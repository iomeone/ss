#include "Control_Category/Control_Category.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_CommutativeRing/Data_CommutativeRing.h"
#include "Data_DivisionRing/Data_DivisionRing.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Int_Bits/Data_Int_Bits.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Global/Global.h"
#include "Math/Math.h"
#include "Prelude/Prelude.h"

#include "Data_Int/Data_Int.h"


namespace Data_Int {

auto Radix() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto Even() -> const boxed& {
    static const boxed _ = dict_t{
        { "Even", true }
    };
    return _;
};
auto Odd() -> const boxed& {
    static const boxed _ = dict_t{
        { "Odd", true }
    };
    return _;
};
auto showParity() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Even")) {
            return "Even";
        };
        if (unbox<dict_t>(v).contains("Odd")) {
            return "Odd";
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Int (line 112, column 1 - line 112, column 35): ");
    });
};
auto radix() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        if (unbox<bool>(unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(n)(2)) && unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(n)(36)))) {
            return Data_Maybe::Just()(n);
        };
        return Data_Maybe::Nothing();
    };
    return _;
};
auto odd() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return unbox<int>(Data_Int_Bits::_and_()(x)(1)) != 0;
    };
    return _;
};
auto octal() -> const boxed& {
    static const boxed _ = 8;
    return _;
};
auto hexadecimal() -> const boxed& {
    static const boxed _ = 16;
    return _;
};
auto fromStringAs() -> boxed {
    return Data_Int::fromStringAsImpl()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto fromString() -> boxed {
    return Data_Int::fromStringAs()(10);
};
auto fromNumber() -> boxed {
    return Data_Int::fromNumberImpl()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto unsafeClamp() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        if (unbox<bool>(Data_Eq::eq()(Data_Eq::eqNumber())(x)(Global::infinity()))) {
            return 0;
        };
        if (unbox<bool>(Data_Eq::eq()(Data_Eq::eqNumber())(x)(-unbox<double>(Global::infinity())))) {
            return 0;
        };
        if (unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordNumber())(x)(Data_Int::toNumber()(Data_Bounded::top()(Data_Bounded::boundedInt()))))) {
            return Data_Bounded::top()(Data_Bounded::boundedInt());
        };
        if (unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordNumber())(x)(Data_Int::toNumber()(Data_Bounded::bottom()(Data_Bounded::boundedInt()))))) {
            return Data_Bounded::bottom()(Data_Bounded::boundedInt());
        };
        return Data_Maybe::fromMaybe()(0)(Data_Int::fromNumber()(x));
    };
    return _;
};
auto round() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Int::unsafeClamp())(Math::round());
};
auto floor() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Int::unsafeClamp())(Math::floor());
};
auto even() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return unbox<int>(Data_Int_Bits::_and_()(x)(1)) == 0;
    };
    return _;
};
auto parity() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        boxed _Local_8 = Data_Int::even()(n);
        if (unbox<bool>(_Local_8)) {
            return Data_Int::Even();
        };
        return Data_Int::Odd();
    };
    return _;
};
auto eqParity() -> boxed {
    return Data_Eq::Eq()([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            if (unbox<dict_t>(x).contains("Even")) {
                if (unbox<dict_t>(y).contains("Even")) {
                    return true;
                };
            };
            if (unbox<dict_t>(x).contains("Odd")) {
                if (unbox<dict_t>(y).contains("Odd")) {
                    return true;
                };
            };
            return false;
        };
    });
};
auto ordParity() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Int::eqParity();
    })([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            if (unbox<dict_t>(x).contains("Even")) {
                if (unbox<dict_t>(y).contains("Even")) {
                    return Data_Ordering::EQ();
                };
            };
            if (unbox<dict_t>(x).contains("Even")) {
                return Data_Ordering::LT();
            };
            if (unbox<dict_t>(y).contains("Even")) {
                return Data_Ordering::GT();
            };
            if (unbox<dict_t>(x).contains("Odd")) {
                if (unbox<dict_t>(y).contains("Odd")) {
                    return Data_Ordering::EQ();
                };
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Int (line 110, column 8 - line 110, column 40): ");
        };
    });
};
auto semiringParity() -> boxed {
    return Data_Semiring::Semiring()([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            boxed _Local_13 = Data_Eq::eq()(Data_Int::eqParity())(x)(y);
            if (unbox<bool>(_Local_13)) {
                return Data_Int::Even();
            };
            return Data_Int::Odd();
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Odd")) {
                if (unbox<dict_t>(v1).contains("Odd")) {
                    return Data_Int::Odd();
                };
            };
            return Data_Int::Even();
        };
    })(Data_Int::Odd())(Data_Int::Even());
};
auto ringParity() -> boxed {
    return Data_Ring::Ring()([=](const boxed&) -> boxed {
        return Data_Int::semiringParity();
    })(Data_Semiring::add()(Data_Int::semiringParity()));
};
auto divisionRingParity() -> boxed {
    return Data_DivisionRing::DivisionRing()([=](const boxed&) -> boxed {
        return Data_Int::ringParity();
    })(Control_Category::identity()(Control_Category::categoryFn()));
};
auto decimal() -> const boxed& {
    static const boxed _ = 10;
    return _;
};
auto commutativeRingParity() -> boxed {
    return Data_CommutativeRing::CommutativeRing()([=](const boxed&) -> boxed {
        return Data_Int::ringParity();
    });
};
auto euclideanRingParity() -> boxed {
    return Data_EuclideanRing::EuclideanRing()([=](const boxed&) -> boxed {
        return Data_Int::commutativeRingParity();
    })([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Even")) {
            return 0;
        };
        if (unbox<dict_t>(v).contains("Odd")) {
            return 1;
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Int (line 132, column 1 - line 132, column 53): ");
    })([=](const boxed& x) -> boxed {
        return [=](const boxed& v) -> boxed {
            return x;
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Int::Even();
        };
    });
};
auto ceil() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Int::unsafeClamp())(Math::ceil());
};
auto boundedParity() -> boxed {
    return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
        return Data_Int::ordParity();
    })(Data_Int::Even())(Data_Int::Odd());
};
auto binary() -> const boxed& {
    static const boxed _ = 2;
    return _;
};
auto base36() -> const boxed& {
    static const boxed _ = 36;
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto fromNumberImpl() -> const boxed& { static const boxed _ = foreign().at("fromNumberImpl"); return _; };
auto toNumber() -> const boxed& { static const boxed _ = foreign().at("toNumber"); return _; };
auto quot() -> const boxed& { static const boxed _ = foreign().at("quot"); return _; };
auto rem() -> const boxed& { static const boxed _ = foreign().at("rem"); return _; };
auto pow() -> const boxed& { static const boxed _ = foreign().at("pow"); return _; };
auto fromStringAsImpl() -> const boxed& { static const boxed _ = foreign().at("fromStringAsImpl"); return _; };
auto toStringAs() -> const boxed& { static const boxed _ = foreign().at("toStringAs"); return _; };

} // end namespace Data_Int


