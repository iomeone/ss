#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Array_NonEmpty/Data_Array_NonEmpty.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_String_CodePoints/Data_String_CodePoints.h"
#include "Data_String_NonEmpty_Internal/Data_String_NonEmpty_Internal.h"
#include "Data_String_Pattern/Data_String_Pattern.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"
#include "Unsafe_Coerce/Unsafe_Coerce.h"

#include "Data_String_NonEmpty_CodePoints/Data_String_NonEmpty_CodePoints.h"


namespace Data_String_NonEmpty_CodePoints {

auto toNonEmptyString() -> boxed {
    return Unsafe_Coerce::unsafeCoerce();
};
auto snoc() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_NonEmpty_CodePoints::toNonEmptyString()(Data_Semigroup::append()(Data_Semigroup::semigroupString())(s)(Data_String_CodePoints::singleton()(c)));
        };
    };
    return _;
};
auto singleton() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodePoints::toNonEmptyString())(Data_String_CodePoints::singleton());
};
auto liftS() -> boxed {
    return Unsafe_Coerce::unsafeCoerce();
};
auto takeWhile() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_Internal::fromString())(Data_String_NonEmpty_CodePoints::liftS()(Data_String_CodePoints::takeWhile()(f)));
    };
    return _;
};
auto lastIndexOf_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& pat) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodePoints::liftS())(Data_String_CodePoints::lastIndexOf_Prime_()(pat));
    };
    return _;
};
auto lastIndexOf() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodePoints::liftS())(Data_String_CodePoints::lastIndexOf());
};
auto indexOf_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& pat) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodePoints::liftS())(Data_String_CodePoints::indexOf_Prime_()(pat));
    };
    return _;
};
auto indexOf() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodePoints::liftS())(Data_String_CodePoints::indexOf());
};
auto fromNonEmptyString() -> boxed {
    return Unsafe_Coerce::unsafeCoerce();
};
auto length() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_CodePoints::length())(Data_String_NonEmpty_CodePoints::fromNonEmptyString());
};
auto splitAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& nes) -> boxed {
            boxed v = Data_String_CodePoints::splitAt()(i)(Data_String_NonEmpty_CodePoints::fromNonEmptyString()(nes));
            return dict_t{
                { "before", Data_String_NonEmpty_Internal::fromString()(v["before"]) },
                { "after", Data_String_NonEmpty_Internal::fromString()(v["after"]) }
            };
        };
    };
    return _;
};
auto take() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& nes) -> boxed {
            boxed s = Data_String_NonEmpty_CodePoints::fromNonEmptyString()(nes);
            boxed _Local_8 = Data_Ord::lessThan()(Data_Ord::ordInt())(i)(1);
            if (unbox<bool>(_Local_8)) {
                return Data_Maybe::Nothing();
            };
            return Data_Maybe::Just()(Data_String_NonEmpty_CodePoints::toNonEmptyString()(Data_String_CodePoints::take()(i)(s)));
        };
    };
    return _;
};
auto toCodePointArray() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_CodePoints::toCodePointArray())(Data_String_NonEmpty_CodePoints::fromNonEmptyString());
};
auto toNonEmptyCodePointArray() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())([=](const boxed& dictPartial) -> boxed {
        return Data_Maybe::fromJust()(dictPartial);
    }(undefined))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::fromArray())(Data_String_NonEmpty_CodePoints::toCodePointArray()));
};
auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& nes) -> boxed {
        boxed s = Data_String_NonEmpty_CodePoints::fromNonEmptyString()(nes);
        return dict_t{
            { "head", [=](const boxed& dictPartial) -> boxed {
                return Data_Maybe::fromJust()(dictPartial);
            }(undefined)(Data_String_CodePoints::codePointAt()(0)(s)) },
            { "tail", Data_String_NonEmpty_Internal::fromString()(Data_String_CodePoints::drop()(1)(s)) }
        };
    };
    return _;
};
auto fromFoldable1() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return Data_Semigroup_Foldable::foldMap1()(dictFoldable1)(Data_String_NonEmpty_Internal::semigroupNonEmptyString())(Data_String_NonEmpty_CodePoints::singleton());
    };
    return _;
};
auto fromCodePointArray() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<int>(array_length(v)) == 0) {
            return Data_Maybe::Nothing();
        };
        return Data_Maybe::Just()(Data_String_NonEmpty_CodePoints::toNonEmptyString()(Data_String_CodePoints::fromCodePointArray()(v)));
    };
    return _;
};
auto fromNonEmptyCodePointArray() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())([=](const boxed& dictPartial) -> boxed {
        return Data_Maybe::fromJust()(dictPartial);
    }(undefined))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodePoints::fromCodePointArray())(Data_Array_NonEmpty::toArray()));
};
auto dropWhile() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_Internal::fromString())(Data_String_NonEmpty_CodePoints::liftS()(Data_String_CodePoints::dropWhile()(f)));
    };
    return _;
};
auto drop() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& nes) -> boxed {
            boxed s = Data_String_NonEmpty_CodePoints::fromNonEmptyString()(nes);
            boxed _Local_10 = Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(i)(Data_String_CodePoints::length()(s));
            if (unbox<bool>(_Local_10)) {
                return Data_Maybe::Nothing();
            };
            return Data_Maybe::Just()(Data_String_NonEmpty_CodePoints::toNonEmptyString()(Data_String_CodePoints::drop()(i)(s)));
        };
    };
    return _;
};
auto countPrefix() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodePoints::liftS())(Data_String_CodePoints::countPrefix());
};
auto cons() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_NonEmpty_CodePoints::toNonEmptyString()(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_String_CodePoints::singleton()(c))(s));
        };
    };
    return _;
};
auto codePointAt() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodePoints::liftS())(Data_String_CodePoints::codePointAt());
};


} // end namespace Data_String_NonEmpty_CodePoints


