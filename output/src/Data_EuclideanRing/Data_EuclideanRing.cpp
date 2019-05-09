#include "Data_BooleanAlgebra/Data_BooleanAlgebra.h"
#include "Data_CommutativeRing/Data_CommutativeRing.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semiring/Data_Semiring.h"

#include "Data_EuclideanRing/Data_EuclideanRing.h"


namespace Data_EuclideanRing {

auto EuclideanRing() -> const boxed& {
    static const boxed _ = [](const boxed& CommutativeRing0) -> boxed {
        return [=](const boxed& degree) -> boxed {
            return [=](const boxed& div) -> boxed {
                return [=](const boxed& mod) -> boxed {
                    return dict_t{
                        { "CommutativeRing0", CommutativeRing0 },
                        { "degree", degree },
                        { "div", div },
                        { "mod", mod }
                    };
                };
            };
        };
    };
    return _;
};
auto mod() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["mod"];
    };
    return _;
};
auto gcd() -> const boxed& {
    static const boxed _ = [](const boxed& _TCO_Copy_dictEq_) -> boxed {
        return [=](const boxed& _TCO_Copy_dictEuclideanRing_) -> boxed {
            return [=](const boxed& _TCO_Copy_a_) -> boxed {
                return [=](const boxed& _TCO_Copy_b_) -> boxed {
                    boxed _TCO_dictEq_;
                    _TCO_dictEq_ = _TCO_Copy_dictEq_;
                    boxed _TCO_dictEuclideanRing_;
                    _TCO_dictEuclideanRing_ = _TCO_Copy_dictEuclideanRing_;
                    boxed _TCO_a_;
                    _TCO_a_ = _TCO_Copy_a_;
                    boxed _TCO_b_;
                    _TCO_b_ = _TCO_Copy_b_;
                    bool _TCO_Done_ = false;
                    boxed _TCO_Result_;
                    const auto _TCO_Loop_ = [&](const boxed dictEq, const boxed dictEuclideanRing, const boxed a, const boxed b) -> boxed {
                        boxed _Local_5 = Data_Eq::eq()(dictEq)(b)(Data_Semiring::zero()(dictEuclideanRing["CommutativeRing0"](undefined)["Ring0"](undefined)["Semiring0"](undefined)));
                        if (unbox<bool>(_Local_5)) {
                            _TCO_Done_ = true;
                            return a;
                        };
                        _TCO_dictEq_ = dictEq;
                        _TCO_dictEuclideanRing_ = dictEuclideanRing;
                        _TCO_a_ = b;
                        _TCO_b_ = Data_EuclideanRing::mod()(dictEuclideanRing)(a)(b);
                        return undefined;
                    };
                    while (!(_TCO_Done_)) {
                        _TCO_Result_ = _TCO_Loop_(_TCO_dictEq_, _TCO_dictEuclideanRing_, _TCO_a_, _TCO_b_);
                    };
                    return _TCO_Result_;
                };
            };
        };
    };
    return _;
};
auto euclideanRingNumber() -> boxed {
    return Data_EuclideanRing::EuclideanRing()([=](const boxed&) -> boxed {
        return Data_CommutativeRing::commutativeRingNumber();
    })([=](const boxed& v) -> boxed {
        return 1;
    })(Data_EuclideanRing::numDiv())([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return 0.0;
        };
    });
};
auto euclideanRingInt() -> boxed {
    return Data_EuclideanRing::EuclideanRing()([=](const boxed&) -> boxed {
        return Data_CommutativeRing::commutativeRingInt();
    })(Data_EuclideanRing::intDegree())(Data_EuclideanRing::intDiv())(Data_EuclideanRing::intMod());
};
auto div() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["div"];
    };
    return _;
};
auto lcm() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& dictEuclideanRing) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    boxed _Local_6 = unbox<bool>(Data_Eq::eq()(dictEq)(a)(Data_Semiring::zero()(dictEuclideanRing["CommutativeRing0"](undefined)["Ring0"](undefined)["Semiring0"](undefined))))|| unbox<bool>(Data_Eq::eq()(dictEq)(b)(Data_Semiring::zero()(dictEuclideanRing["CommutativeRing0"](undefined)["Ring0"](undefined)["Semiring0"](undefined))));
                    if (unbox<bool>(_Local_6)) {
                        return Data_Semiring::zero()(dictEuclideanRing["CommutativeRing0"](undefined)["Ring0"](undefined)["Semiring0"](undefined));
                    };
                    return Data_EuclideanRing::div()(dictEuclideanRing)(Data_Semiring::mul()(dictEuclideanRing["CommutativeRing0"](undefined)["Ring0"](undefined)["Semiring0"](undefined))(a)(b))(Data_EuclideanRing::gcd()(dictEq)(dictEuclideanRing)(a)(b));
                };
            };
        };
    };
    return _;
};
auto degree() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["degree"];
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto intDegree() -> const boxed& { static const boxed _ = foreign().at("intDegree"); return _; };
auto intDiv() -> const boxed& { static const boxed _ = foreign().at("intDiv"); return _; };
auto intMod() -> const boxed& { static const boxed _ = foreign().at("intMod"); return _; };
auto numDiv() -> const boxed& { static const boxed _ = foreign().at("numDiv"); return _; };

} // end namespace Data_EuclideanRing


