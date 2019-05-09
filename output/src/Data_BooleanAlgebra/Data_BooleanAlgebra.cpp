#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"

#include "Data_BooleanAlgebra/Data_BooleanAlgebra.h"


namespace Data_BooleanAlgebra {

auto BooleanAlgebraRecord() -> const boxed& {
    static const boxed _ = [](const boxed& HeytingAlgebraRecord0) -> boxed {
        return dict_t{
            { "HeytingAlgebraRecord0", HeytingAlgebraRecord0 }
        };
    };
    return _;
};
auto BooleanAlgebra() -> const boxed& {
    static const boxed _ = [](const boxed& HeytingAlgebra0) -> boxed {
        return dict_t{
            { "HeytingAlgebra0", HeytingAlgebra0 }
        };
    };
    return _;
};
auto booleanAlgebraUnit() -> boxed {
    return Data_BooleanAlgebra::BooleanAlgebra()([=](const boxed&) -> boxed {
        return Data_HeytingAlgebra::heytingAlgebraUnit();
    });
};
auto booleanAlgebraRecordNil() -> boxed {
    return Data_BooleanAlgebra::BooleanAlgebraRecord()([=](const boxed&) -> boxed {
        return Data_HeytingAlgebra::heytingAlgebraRecordNil();
    });
};
auto booleanAlgebraRecordCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictIsSymbol) -> boxed {
        return [=](const boxed& dictCons) -> boxed {
            return [=](const boxed& dictBooleanAlgebraRecord) -> boxed {
                return [=](const boxed& dictBooleanAlgebra) -> boxed {
                    return Data_BooleanAlgebra::BooleanAlgebraRecord()([=](const boxed&) -> boxed {
                        return Data_HeytingAlgebra::heytingAlgebraRecordCons()(dictIsSymbol)(dictCons)(dictBooleanAlgebraRecord["HeytingAlgebraRecord0"](undefined))(dictBooleanAlgebra["HeytingAlgebra0"](undefined));
                    });
                };
            };
        };
    };
    return _;
};
auto booleanAlgebraRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictBooleanAlgebraRecord) -> boxed {
            return Data_BooleanAlgebra::BooleanAlgebra()([=](const boxed&) -> boxed {
                return Data_HeytingAlgebra::heytingAlgebraRecord()(dictRowToList)(dictBooleanAlgebraRecord["HeytingAlgebraRecord0"](undefined));
            });
        };
    };
    return _;
};
auto booleanAlgebraFn() -> const boxed& {
    static const boxed _ = [](const boxed& dictBooleanAlgebra) -> boxed {
        return Data_BooleanAlgebra::BooleanAlgebra()([=](const boxed&) -> boxed {
            return Data_HeytingAlgebra::heytingAlgebraFunction()(dictBooleanAlgebra["HeytingAlgebra0"](undefined));
        });
    };
    return _;
};
auto booleanAlgebraBoolean() -> boxed {
    return Data_BooleanAlgebra::BooleanAlgebra()([=](const boxed&) -> boxed {
        return Data_HeytingAlgebra::heytingAlgebraBoolean();
    });
};


} // end namespace Data_BooleanAlgebra


