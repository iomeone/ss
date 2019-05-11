#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semiring/Data_Semiring.h"

#include "Data_DivisionRing/Data_DivisionRing.h"


namespace Data_DivisionRing {

auto DivisionRing() -> const boxed& {
    static const boxed _ = [](const boxed& Ring0) -> boxed {
        return [=](const boxed& recip) -> boxed {
            return dict_t{
                { "Ring0", Ring0 },
                { "recip", recip }
            };
        };
    };
    return _;
};
auto recip() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["recip"];
    };
    return _;
};
auto rightDiv() -> const boxed& {
    static const boxed _ = [](const boxed& dictDivisionRing) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Data_Semiring::mul()(dictDivisionRing["Ring0"](undefined)["Semiring0"](undefined))(a)(Data_DivisionRing::recip()(dictDivisionRing)(b));
            };
        };
    };
    return _;
};
auto leftDiv() -> const boxed& {
    static const boxed _ = [](const boxed& dictDivisionRing) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Data_Semiring::mul()(dictDivisionRing["Ring0"](undefined)["Semiring0"](undefined))(Data_DivisionRing::recip()(dictDivisionRing)(b))(a);
            };
        };
    };
    return _;
};
auto divisionringNumber() -> boxed {
    return Data_DivisionRing::DivisionRing()([=](const boxed&) -> boxed {
        return Data_Ring::ringNumber();
    })([=](const boxed& x) -> boxed {
        return 1.0 / unbox<double>(x);
    });
};


} // end namespace Data_DivisionRing


