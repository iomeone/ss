#include "Data_CommutativeRing/Data_CommutativeRing.h"
#include "Data_DivisionRing/Data_DivisionRing.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semiring/Data_Semiring.h"

#include "Data_Field/Data_Field.h"


namespace Data_Field {

auto Field() -> const boxed& {
    static const boxed _ = [](const boxed& DivisionRing1) -> boxed {
        return [=](const boxed& EuclideanRing0) -> boxed {
            return dict_t{
                { "DivisionRing1", DivisionRing1 },
                { "EuclideanRing0", EuclideanRing0 }
            };
        };
    };
    return _;
};
auto field() -> const boxed& {
    static const boxed _ = [](const boxed& dictEuclideanRing) -> boxed {
        return [=](const boxed& dictDivisionRing) -> boxed {
            return Data_Field::Field()([=](const boxed&) -> boxed {
                return dictDivisionRing;
            })([=](const boxed&) -> boxed {
                return dictEuclideanRing;
            });
        };
    };
    return _;
};


} // end namespace Data_Field


