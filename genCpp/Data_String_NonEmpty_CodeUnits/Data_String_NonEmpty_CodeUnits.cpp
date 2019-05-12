#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Array_NonEmpty/Data_Array_NonEmpty.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_String_CodeUnits/Data_String_CodeUnits.h"
#include "Data_String_NonEmpty_Internal/Data_String_NonEmpty_Internal.h"
#include "Data_String_Pattern/Data_String_Pattern.h"
#include "Data_String_Unsafe/Data_String_Unsafe.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"
#include "Unsafe_Coerce/Unsafe_Coerce.h"

#include "Data_String_NonEmpty_CodeUnits/Data_String_NonEmpty_CodeUnits.h"


namespace Data_String_NonEmpty_CodeUnits {

auto toNonEmptyString() -> boxed {
    return Unsafe_Coerce::unsafeCoerce();
};
auto snoc() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_NonEmpty_CodeUnits::toNonEmptyString()(Data_Semigroup::append()(Data_Semigroup::semigroupString())(s)(Data_String_CodeUnits::singleton()(c)));
        };
    };
    return _;
};
auto singleton() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodeUnits::toNonEmptyString())(Data_String_CodeUnits::singleton());
};
auto liftS() -> boxed {
    return Unsafe_Coerce::unsafeCoerce();
};
auto takeWhile() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_Internal::fromString())(Data_String_NonEmpty_CodeUnits::liftS()(Data_String_CodeUnits::takeWhile()(f)));
    };
    return _;
};
auto lastIndexOf_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& pat) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodeUnits::liftS())(Data_String_CodeUnits::lastIndexOf_Prime_()(pat));
    };
    return _;
};
auto lastIndexOf() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodeUnits::liftS())(Data_String_CodeUnits::lastIndexOf());
};
auto indexOf_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& pat) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodeUnits::liftS())(Data_String_CodeUnits::indexOf_Prime_()(pat));
    };
    return _;
};
auto indexOf() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodeUnits::liftS())(Data_String_CodeUnits::indexOf());
};
auto fromNonEmptyString() -> boxed {
    return Unsafe_Coerce::unsafeCoerce();
};
auto length() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_CodeUnits::length())(Data_String_NonEmpty_CodeUnits::fromNonEmptyString());
};
auto splitAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& nes) -> boxed {
            boxed v = Data_String_CodeUnits::splitAt()(i)(Data_String_NonEmpty_CodeUnits::fromNonEmptyString()(nes));
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
            boxed s = Data_String_NonEmpty_CodeUnits::fromNonEmptyString()(nes);
            boxed _Local_8 = Data_Ord::lessThan()(Data_Ord::ordInt())(i)(1);
            if (unbox<bool>(_Local_8)) {
                return Data_Maybe::Nothing();
            };
            return Data_Maybe::Just()(Data_String_NonEmpty_CodeUnits::toNonEmptyString()(Data_String_CodeUnits::take()(i)(s)));
        };
    };
    return _;
};
auto takeRight() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& nes) -> boxed {
            boxed s = Data_String_NonEmpty_CodeUnits::fromNonEmptyString()(nes);
            boxed _Local_9 = Data_Ord::lessThan()(Data_Ord::ordInt())(i)(1);
            if (unbox<bool>(_Local_9)) {
                return Data_Maybe::Nothing();
            };
            return Data_Maybe::Just()(Data_String_NonEmpty_CodeUnits::toNonEmptyString()(Data_String_CodeUnits::takeRight()(i)(s)));
        };
    };
    return _;
};
auto toChar() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_CodeUnits::toChar())(Data_String_NonEmpty_CodeUnits::fromNonEmptyString());
};
auto toCharArray() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_CodeUnits::toCharArray())(Data_String_NonEmpty_CodeUnits::fromNonEmptyString());
};
auto toNonEmptyCharArray() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())([=](const boxed& dictPartial) -> boxed {
        return Data_Maybe::fromJust()(dictPartial);
    }(undefined))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::fromArray())(Data_String_NonEmpty_CodeUnits::toCharArray()));
};
auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& nes) -> boxed {
        boxed s = Data_String_NonEmpty_CodeUnits::fromNonEmptyString()(nes);
        return dict_t{
            { "head", Data_String_Unsafe::charAt()(0)(s) },
            { "tail", Data_String_NonEmpty_Internal::fromString()(Data_String_CodeUnits::drop()(1)(s)) }
        };
    };
    return _;
};
auto fromFoldable1() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Semigroup_Foldable::fold1()(dictFoldable1)(Data_String_NonEmpty_Internal::semigroupNonEmptyString()))(Unsafe_Coerce::unsafeCoerce());
    };
    return _;
};
auto fromCharArray() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<int>(array_length(v)) == 0) {
            return Data_Maybe::Nothing();
        };
        return Data_Maybe::Just()(Data_String_NonEmpty_CodeUnits::toNonEmptyString()(Data_String_CodeUnits::fromCharArray()(v)));
    };
    return _;
};
auto fromNonEmptyCharArray() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())([=](const boxed& dictPartial) -> boxed {
        return Data_Maybe::fromJust()(dictPartial);
    }(undefined))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodeUnits::fromCharArray())(Data_Array_NonEmpty::toArray()));
};
auto dropWhile() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_Internal::fromString())(Data_String_NonEmpty_CodeUnits::liftS()(Data_String_CodeUnits::dropWhile()(f)));
    };
    return _;
};
auto dropRight() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& nes) -> boxed {
            boxed s = Data_String_NonEmpty_CodeUnits::fromNonEmptyString()(nes);
            boxed _Local_11 = Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(i)(Data_String_CodeUnits::length()(s));
            if (unbox<bool>(_Local_11)) {
                return Data_Maybe::Nothing();
            };
            return Data_Maybe::Just()(Data_String_NonEmpty_CodeUnits::toNonEmptyString()(Data_String_CodeUnits::dropRight()(i)(s)));
        };
    };
    return _;
};
auto drop() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& nes) -> boxed {
            boxed s = Data_String_NonEmpty_CodeUnits::fromNonEmptyString()(nes);
            boxed _Local_12 = Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(i)(Data_String_CodeUnits::length()(s));
            if (unbox<bool>(_Local_12)) {
                return Data_Maybe::Nothing();
            };
            return Data_Maybe::Just()(Data_String_NonEmpty_CodeUnits::toNonEmptyString()(Data_String_CodeUnits::drop()(i)(s)));
        };
    };
    return _;
};
auto countPrefix() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodeUnits::liftS())(Data_String_CodeUnits::countPrefix());
};
auto cons() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_String_NonEmpty_CodeUnits::toNonEmptyString()(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_String_CodeUnits::singleton()(c))(s));
        };
    };
    return _;
};
auto charAt() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_CodeUnits::liftS())(Data_String_CodeUnits::charAt());
};


} // end namespace Data_String_NonEmpty_CodeUnits


