#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Array/Data_Array.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Enum/Data_Enum.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Int/Data_Int.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Data_String_CodeUnits/Data_String_CodeUnits.h"
#include "Data_String_Common/Data_String_Common.h"
#include "Data_String_Pattern/Data_String_Pattern.h"
#include "Data_String_Unsafe/Data_String_Unsafe.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Prelude/Prelude.h"

#include "Data_String_CodePoints/Data_String_CodePoints.h"


namespace Data_String_CodePoints {

auto CodePoint() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto unsurrogate() -> const boxed& {
    static const boxed _ = [](const boxed& lead) -> boxed {
        return [=](const boxed& trail) -> boxed {
            return unbox<int>(unbox<int>(unbox<int>(unbox<int>(lead) - 55296) * 1024) + unbox<int>(unbox<int>(trail) - 56320)) + 65536;
        };
    };
    return _;
};
auto showCodePoint() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(CodePoint 0x")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_String_Common::toUpper()(Data_Int::toStringAs()(Data_Int::hexadecimal())(v)))(")"));
    });
};
auto isTrail() -> const boxed& {
    static const boxed _ = [](const boxed& cu) -> boxed {
        return unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(56320)(cu)) && unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(cu)(57343));
    };
    return _;
};
auto isLead() -> const boxed& {
    static const boxed _ = [](const boxed& cu) -> boxed {
        return unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(55296)(cu)) && unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(cu)(56319));
    };
    return _;
};
auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        boxed v = Data_String_CodeUnits::length()(s);
        if (unbox<int>(v) == 0) {
            return Data_Maybe::Nothing();
        };
        if (unbox<int>(v) == 1) {
            return Data_Maybe::Just()(dict_t{
                { "head", Data_Enum::fromEnum()(Data_Enum::boundedEnumChar())(Data_String_Unsafe::charAt()(0)(s)) },
                { "tail", "" }
            });
        };
        boxed cu1 = Data_Enum::fromEnum()(Data_Enum::boundedEnumChar())(Data_String_Unsafe::charAt()(1)(s));
        boxed cu0 = Data_Enum::fromEnum()(Data_Enum::boundedEnumChar())(Data_String_Unsafe::charAt()(0)(s));
        boxed _Local_7 = unbox<bool>(Data_String_CodePoints::isLead()(cu0)) && unbox<bool>(Data_String_CodePoints::isTrail()(cu1));
        if (unbox<bool>(_Local_7)) {
            return Data_Maybe::Just()(dict_t{
                { "head", Data_String_CodePoints::unsurrogate()(cu0)(cu1) },
                { "tail", Data_String_CodeUnits::drop()(2)(s) }
            });
        };
        return Data_Maybe::Just()(dict_t{
            { "head", cu0 },
            { "tail", Data_String_CodeUnits::drop()(1)(s) }
        });
    };
    return _;
};
auto unconsButWithTuple() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["head"])(v["tail"]);
        })(Data_String_CodePoints::uncons()(s));
    };
    return _;
};
auto toCodePointArrayFallback() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        return Data_Unfoldable::unfoldr()(Data_Unfoldable::unfoldableArray())(Data_String_CodePoints::unconsButWithTuple())(s);
    };
    return _;
};
auto unsafeCodePointAt0Fallback() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        boxed cu0 = Data_Enum::fromEnum()(Data_Enum::boundedEnumChar())(Data_String_Unsafe::charAt()(0)(s));
        boxed _Local_11 = unbox<bool>(Data_String_CodePoints::isLead()(cu0)) && unbox<bool>(Data_Ord::greaterThan()(Data_Ord::ordInt())(Data_String_CodeUnits::length()(s))(1));
        if (unbox<bool>(_Local_11)) {
            boxed cu1 = Data_Enum::fromEnum()(Data_Enum::boundedEnumChar())(Data_String_Unsafe::charAt()(1)(s));
            boxed _Local_12 = Data_String_CodePoints::isTrail()(cu1);
            if (unbox<bool>(_Local_12)) {
                return Data_String_CodePoints::unsurrogate()(cu0)(cu1);
            };
            return cu0;
        };
        return cu0;
    };
    return _;
};
auto unsafeCodePointAt0() -> boxed {
    return Data_String_CodePoints::_unsafeCodePointAt0()(Data_String_CodePoints::unsafeCodePointAt0Fallback());
};
auto toCodePointArray() -> boxed {
    return Data_String_CodePoints::_toCodePointArray()(Data_String_CodePoints::toCodePointArrayFallback())(Data_String_CodePoints::unsafeCodePointAt0());
};
auto length() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array::length())(Data_String_CodePoints::toCodePointArray());
};
auto lastIndexOf() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& i) -> boxed {
                return Data_String_CodePoints::length()(Data_String_CodeUnits::take()(i)(s));
            })(Data_String_CodeUnits::lastIndexOf()(p)(s));
        };
    };
    return _;
};
auto indexOf() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& i) -> boxed {
                return Data_String_CodePoints::length()(Data_String_CodeUnits::take()(i)(s));
            })(Data_String_CodeUnits::indexOf()(p)(s));
        };
    };
    return _;
};
auto fromCharCode() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_CodeUnits::singleton())(Data_Enum::toEnumWithDefaults()(Data_Enum::boundedEnumChar())(Data_Bounded::bottom()(Data_Bounded::boundedChar()))(Data_Bounded::top()(Data_Bounded::boundedChar())));
};
auto singletonFallback() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(v)(65535))) {
            return Data_String_CodePoints::fromCharCode()(v);
        };
        boxed lead = unbox<int>(Data_EuclideanRing::div()(Data_EuclideanRing::euclideanRingInt())(unbox<int>(v) - 65536)(1024)) + 55296;
        boxed trail = unbox<int>(Data_EuclideanRing::mod()(Data_EuclideanRing::euclideanRingInt())(unbox<int>(v) - 65536)(1024)) + 56320;
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_String_CodePoints::fromCharCode()(lead))(Data_String_CodePoints::fromCharCode()(trail));
    };
    return _;
};
auto fromCodePointArray() -> boxed {
    return Data_String_CodePoints::_fromCodePointArray()(Data_String_CodePoints::singletonFallback());
};
auto singleton() -> boxed {
    return Data_String_CodePoints::_singleton()(Data_String_CodePoints::singletonFallback());
};
auto takeFallback() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(n)(1))) {
                return "";
            };
            boxed v1 = Data_String_CodePoints::uncons()(v);
            if (unbox<dict_t>(v1).contains("Just")) {
                return Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_String_CodePoints::singleton()(v1["value0"]["head"]))(Data_String_CodePoints::takeFallback()(unbox<int>(n) - 1)(v1["value0"]["tail"]));
            };
            return v;
        };
    };
    return _;
};
auto take() -> boxed {
    return Data_String_CodePoints::_take()(Data_String_CodePoints::takeFallback());
};
auto lastIndexOf_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& i) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed i_Prime_ = Data_String_CodeUnits::length()(Data_String_CodePoints::take()(i)(s));
                return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& k) -> boxed {
                    return Data_String_CodePoints::length()(Data_String_CodeUnits::take()(k)(s));
                })(Data_String_CodeUnits::lastIndexOf_Prime_()(p)(i_Prime_)(s));
            };
        };
    };
    return _;
};
auto splitAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& s) -> boxed {
            boxed before = Data_String_CodePoints::take()(i)(s);
            return dict_t{
                { "before", before },
                { "after", Data_String_CodeUnits::drop()(Data_String_CodeUnits::length()(before))(s) }
            };
        };
    };
    return _;
};
auto eqCodePoint() -> boxed {
    return Data_Eq::Eq()([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            return unbox<int>(x) == unbox<int>(y);
        };
    });
};
auto ordCodePoint() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_String_CodePoints::eqCodePoint();
    })([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            return Data_Ord::compare()(Data_Ord::ordInt())(x)(y);
        };
    });
};
auto drop() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_CodeUnits::drop()(Data_String_CodeUnits::length()(Data_String_CodePoints::take()(n)(s)))(s);
        };
    };
    return _;
};
auto indexOf_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& i) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed s_Prime_ = Data_String_CodePoints::drop()(i)(s);
                return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& k) -> boxed {
                    return unbox<int>(i) + unbox<int>(Data_String_CodePoints::length()(Data_String_CodeUnits::take()(k)(s_Prime_)));
                })(Data_String_CodeUnits::indexOf()(p)(s_Prime_));
            };
        };
    };
    return _;
};
auto countTail() -> const boxed& {
    static const boxed _ = [](const boxed& _TCO_Copy_p_) -> boxed {
        return [=](const boxed& _TCO_Copy_s_) -> boxed {
            return [=](const boxed& _TCO_Copy_accum_) -> boxed {
                boxed _TCO_p_;
                _TCO_p_ = _TCO_Copy_p_;
                boxed _TCO_s_;
                _TCO_s_ = _TCO_Copy_s_;
                boxed _TCO_accum_;
                _TCO_accum_ = _TCO_Copy_accum_;
                bool _TCO_Done_ = false;
                boxed _TCO_Result_;
                const auto _TCO_Loop_ = [&](const boxed p, const boxed s, const boxed accum) -> boxed {
                    boxed v = Data_String_CodePoints::uncons()(s);
                    if (unbox<dict_t>(v).contains("Just")) {
                        boxed _Local_25 = p(v["value0"]["head"]);
                        if (unbox<bool>(_Local_25)) {
                            _TCO_p_ = p;
                            _TCO_s_ = v["value0"]["tail"];
                            _TCO_accum_ = unbox<int>(accum) + 1;
                            return undefined;
                        };
                        _TCO_Done_ = true;
                        return accum;
                    };
                    _TCO_Done_ = true;
                    return accum;
                };
                while (!(_TCO_Done_)) {
                    _TCO_Result_ = _TCO_Loop_(_TCO_p_, _TCO_s_, _TCO_accum_);
                };
                return _TCO_Result_;
            };
        };
    };
    return _;
};
auto countFallback() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_CodePoints::countTail()(p)(s)(0);
        };
    };
    return _;
};
auto countPrefix() -> boxed {
    return Data_String_CodePoints::_countPrefix()(Data_String_CodePoints::countFallback())(Data_String_CodePoints::unsafeCodePointAt0());
};
auto dropWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_CodePoints::drop()(Data_String_CodePoints::countPrefix()(p)(s))(s);
        };
    };
    return _;
};
auto takeWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_CodePoints::take()(Data_String_CodePoints::countPrefix()(p)(s))(s);
        };
    };
    return _;
};
auto codePointFromChar() -> boxed {
    return Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(Data_Enum::fromEnum()(Data_Enum::boundedEnumChar()))(Data_String_CodePoints::CodePoint());
};
auto codePointAtFallback() -> const boxed& {
    static const boxed _ = [](const boxed& _TCO_Copy_n_) -> boxed {
        return [=](const boxed& _TCO_Copy_s_) -> boxed {
            boxed _TCO_n_;
            _TCO_n_ = _TCO_Copy_n_;
            boxed _TCO_s_;
            _TCO_s_ = _TCO_Copy_s_;
            bool _TCO_Done_ = false;
            boxed _TCO_Result_;
            const auto _TCO_Loop_ = [&](const boxed n, const boxed s) -> boxed {
                boxed v = Data_String_CodePoints::uncons()(s);
                if (unbox<dict_t>(v).contains("Just")) {
                    boxed _Local_30 = unbox<int>(n) == 0;
                    if (unbox<bool>(_Local_30)) {
                        _TCO_Done_ = true;
                        return Data_Maybe::Just()(v["value0"]["head"]);
                    };
                    _TCO_n_ = unbox<int>(n) - 1;
                    _TCO_s_ = v["value0"]["tail"];
                    return undefined;
                };
                _TCO_Done_ = true;
                return Data_Maybe::Nothing();
            };
            while (!(_TCO_Done_)) {
                _TCO_Result_ = _TCO_Loop_(_TCO_n_, _TCO_s_);
            };
            return _TCO_Result_;
        };
    };
    return _;
};
auto codePointAt() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(v)(0))) {
                return Data_Maybe::Nothing();
            };
            if (unbox<int>(v) == 0) {
                if (unbox<juce::String>(v1) == "") {
                    return Data_Maybe::Nothing();
                };
            };
            if (unbox<int>(v) == 0) {
                return Data_Maybe::Just()(Data_String_CodePoints::unsafeCodePointAt0()(v1));
            };
            return Data_String_CodePoints::_codePointAt()(Data_String_CodePoints::codePointAtFallback())(Data_Maybe::Just())(Data_Maybe::Nothing())(Data_String_CodePoints::unsafeCodePointAt0())(v)(v1);
        };
    };
    return _;
};
auto boundedCodePoint() -> boxed {
    return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
        return Data_String_CodePoints::ordCodePoint();
    })(0)(1114111);
};
auto boundedEnumCodePoint() -> boxed {
    return Data_Enum::BoundedEnum()([=](const boxed&) -> boxed {
        return Data_String_CodePoints::boundedCodePoint();
    })([=](const boxed&) -> boxed {
        return Data_String_CodePoints::enumCodePoint();
    })(1114111 + 1)([=](const boxed& v) -> boxed {
        return v;
    })([=](const boxed& n) -> boxed {
        if (unbox<bool>(unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(n)(0)) && unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(n)(1114111)))) {
            return Data_Maybe::Just()(n);
        };
        return Data_Maybe::Nothing();
    });
};
auto enumCodePoint() -> boxed {
    return Data_Enum::Enum()([=](const boxed&) -> boxed {
        return Data_String_CodePoints::ordCodePoint();
    })(Data_Enum::defaultPred()(Data_Enum::toEnum()(Data_String_CodePoints::boundedEnumCodePoint()))(Data_Enum::fromEnum()(Data_String_CodePoints::boundedEnumCodePoint())))(Data_Enum::defaultSucc()(Data_Enum::toEnum()(Data_String_CodePoints::boundedEnumCodePoint()))(Data_Enum::fromEnum()(Data_String_CodePoints::boundedEnumCodePoint())));
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto _singleton() -> const boxed& { static const boxed _ = foreign().at("_singleton"); return _; };
auto _fromCodePointArray() -> const boxed& { static const boxed _ = foreign().at("_fromCodePointArray"); return _; };
auto _toCodePointArray() -> const boxed& { static const boxed _ = foreign().at("_toCodePointArray"); return _; };
auto _codePointAt() -> const boxed& { static const boxed _ = foreign().at("_codePointAt"); return _; };
auto _countPrefix() -> const boxed& { static const boxed _ = foreign().at("_countPrefix"); return _; };
auto _take() -> const boxed& { static const boxed _ = foreign().at("_take"); return _; };
auto _unsafeCodePointAt0() -> const boxed& { static const boxed _ = foreign().at("_unsafeCodePointAt0"); return _; };

} // end namespace Data_String_CodePoints


