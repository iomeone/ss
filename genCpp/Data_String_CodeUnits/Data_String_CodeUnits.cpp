#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Function/Data_Function.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_String_Pattern/Data_String_Pattern.h"
#include "Data_String_Unsafe/Data_String_Unsafe.h"
#include "Prelude/Prelude.h"

#include "Data_String_CodeUnits/Data_String_CodeUnits.h"


namespace Data_String_CodeUnits {

auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<string>(v) == "") {
            return Data_Maybe::Nothing();
        };
        return Data_Maybe::Just()(dict_t{
            { "head", Data_String_Unsafe::charAt()(Data_Semiring::zero()(Data_Semiring::semiringInt()))(v) },
            { "tail", Data_String_CodeUnits::drop()(Data_Semiring::one()(Data_Semiring::semiringInt()))(v) }
        });
    };
    return _;
};
auto toChar() -> boxed {
    return Data_String_CodeUnits::_toChar()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto takeWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_CodeUnits::take()(Data_String_CodeUnits::countPrefix()(p)(s))(s);
        };
    };
    return _;
};
auto takeRight() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_CodeUnits::drop()(unbox<int>(Data_String_CodeUnits::length()(s)) - unbox<int>(i))(s);
        };
    };
    return _;
};
auto slice() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& e) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed l = Data_String_CodeUnits::length()(s);
                boxed norm = [=](const boxed& x) -> boxed {
                    if (unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(x)(0))) {
                        return unbox<int>(l) + unbox<int>(x);
                    };
                    return x;
                };
                boxed e_Prime_ = norm(e);
                boxed b_Prime_ = norm(b);
                boxed _Local_7 = unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(b_Prime_)(0))|| unbox<bool>(unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(b_Prime_)(l))|| unbox<bool>(unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(e_Prime_)(0))|| unbox<bool>(unbox<bool>(Data_Ord::greaterThan()(Data_Ord::ordInt())(e_Prime_)(l))|| unbox<bool>(Data_Ord::greaterThan()(Data_Ord::ordInt())(b_Prime_)(e_Prime_)))));
                if (unbox<bool>(_Local_7)) {
                    return Data_Maybe::Nothing();
                };
                return Data_Maybe::Just()(Data_String_CodeUnits::_slice()(b)(e)(s));
            };
        };
    };
    return _;
};
auto lastIndexOf_Prime_() -> boxed {
    return Data_String_CodeUnits::_lastIndexOf_Prime_()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto lastIndexOf() -> boxed {
    return Data_String_CodeUnits::_lastIndexOf()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto stripSuffix() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& str) -> boxed {
            boxed v1 = Data_String_CodeUnits::lastIndexOf()(v)(str);
            if (unbox<dict_t>(v1).contains("Just")) {
                if (unbox<bool>(unbox<int>(v1["value0"]) == unbox<int>(unbox<int>(Data_String_CodeUnits::length()(str)) - unbox<int>(Data_String_CodeUnits::length()(v))))) {
                    return Data_Maybe::Just()(Data_String_CodeUnits::take()(v1["value0"])(str));
                };
            };
            return Data_Maybe::Nothing();
        };
    };
    return _;
};
auto indexOf_Prime_() -> boxed {
    return Data_String_CodeUnits::_indexOf_Prime_()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto indexOf() -> boxed {
    return Data_String_CodeUnits::_indexOf()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto stripPrefix() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& str) -> boxed {
            boxed v1 = Data_String_CodeUnits::indexOf()(v)(str);
            if (unbox<dict_t>(v1).contains("Just")) {
                if (unbox<int>(v1["value0"]) == 0) {
                    return Data_Maybe::Just()(Data_String_CodeUnits::drop()(Data_String_CodeUnits::length()(v))(str));
                };
            };
            return Data_Maybe::Nothing();
        };
    };
    return _;
};
auto dropWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_CodeUnits::drop()(Data_String_CodeUnits::countPrefix()(p)(s))(s);
        };
    };
    return _;
};
auto dropRight() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_CodeUnits::take()(unbox<int>(Data_String_CodeUnits::length()(s)) - unbox<int>(i))(s);
        };
    };
    return _;
};
auto contains() -> const boxed& {
    static const boxed _ = [](const boxed& pat) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::isJust())(Data_String_CodeUnits::indexOf()(pat));
    };
    return _;
};
auto charAt() -> boxed {
    return Data_String_CodeUnits::_charAt()(Data_Maybe::Just())(Data_Maybe::Nothing());
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto singleton() -> const boxed& { static const boxed _ = foreign().at("singleton"); return _; };
auto fromCharArray() -> const boxed& { static const boxed _ = foreign().at("fromCharArray"); return _; };
auto toCharArray() -> const boxed& { static const boxed _ = foreign().at("toCharArray"); return _; };
auto _charAt() -> const boxed& { static const boxed _ = foreign().at("_charAt"); return _; };
auto _toChar() -> const boxed& { static const boxed _ = foreign().at("_toChar"); return _; };
auto length() -> const boxed& { static const boxed _ = foreign().at("length"); return _; };
auto countPrefix() -> const boxed& { static const boxed _ = foreign().at("countPrefix"); return _; };
auto _indexOf() -> const boxed& { static const boxed _ = foreign().at("_indexOf"); return _; };
auto _indexOf_Prime_() -> const boxed& { static const boxed _ = foreign().at("_indexOf'"); return _; };
auto _lastIndexOf() -> const boxed& { static const boxed _ = foreign().at("_lastIndexOf"); return _; };
auto _lastIndexOf_Prime_() -> const boxed& { static const boxed _ = foreign().at("_lastIndexOf'"); return _; };
auto take() -> const boxed& { static const boxed _ = foreign().at("take"); return _; };
auto drop() -> const boxed& { static const boxed _ = foreign().at("drop"); return _; };
auto _slice() -> const boxed& { static const boxed _ = foreign().at("_slice"); return _; };
auto splitAt() -> const boxed& { static const boxed _ = foreign().at("splitAt"); return _; };

} // end namespace Data_String_CodeUnits


