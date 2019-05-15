#include "Control_Bind/Control_Bind.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_Show/Data_Show.h"
#include "Data_String/Data_String.h"
#include "Data_String_CodeUnits/Data_String_CodeUnits.h"
#include "Data_String_Common/Data_String_Common.h"
#include "Data_String_Pattern/Data_String_Pattern.h"
#include "Data_Symbol/Data_Symbol.h"
#include "Prelude/Prelude.h"
#include "Unsafe_Coerce/Unsafe_Coerce.h"

#include "Data_String_NonEmpty_Internal/Data_String_NonEmpty_Internal.h"


namespace Data_String_NonEmpty_Internal {

auto NonEmptyString() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto NonEmptyReplacement() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto MakeNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& nes) -> boxed {
        return dict_t{
            { "nes", nes }
        };
    };
    return _;
};
auto toUpper() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_String_Common::toUpper()(v);
    };
    return _;
};
auto toString() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto toLower() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_String_Common::toLower()(v);
    };
    return _;
};
auto showNonEmptyString() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(NonEmptyString.unsafeFromString ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showString())(v))(")"));
    });
};
auto showNonEmptyReplacement() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(NonEmptyReplacement ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_String_NonEmpty_Internal::showNonEmptyString())(v))(")"));
    });
};
auto semigroupNonEmptyString() -> boxed {
    return Data_Semigroup::semigroupString();
};
auto semigroupNonEmptyReplacement() -> boxed {
    return Data_String_NonEmpty_Internal::semigroupNonEmptyString();
};
auto replaceAll() -> const boxed& {
    static const boxed _ = [](const boxed& pat) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_String_Common::replaceAll()(pat)(v)(v1);
            };
        };
    };
    return _;
};
auto replace() -> const boxed& {
    static const boxed _ = [](const boxed& pat) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_String_Common::replace()(pat)(v)(v1);
            };
        };
    };
    return _;
};
auto prependString() -> const boxed& {
    static const boxed _ = [](const boxed& s1) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())(s1)(v);
        };
    };
    return _;
};
auto ordNonEmptyString() -> boxed {
    return Data_Ord::ordString();
};
auto ordNonEmptyReplacement() -> boxed {
    return Data_String_NonEmpty_Internal::ordNonEmptyString();
};
auto nonEmptyNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictIsSymbol) -> boxed {
        return Data_String_NonEmpty_Internal::MakeNonEmpty()([=](const boxed& p) -> boxed {
            return Data_Symbol::reflectSymbol()(dictIsSymbol)(p);
        });
    };
    return _;
};
auto nes() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["nes"];
    };
    return _;
};
auto makeNonEmptyBad() -> const boxed& {
    static const boxed _ = [](const boxed& dictFail) -> boxed {
        return Data_String_NonEmpty_Internal::MakeNonEmpty()([=](const boxed& v) -> boxed {
            return "";
        });
    };
    return _;
};
auto localeCompare() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_String_Common::localeCompare()(v)(v1);
        };
    };
    return _;
};
auto liftS() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v);
        };
    };
    return _;
};
auto joinWith1() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_Internal::NonEmptyString())(Data_Foldable::intercalate()(dictFoldable1["Foldable0"](undefined))(Data_Monoid::monoidString())(v));
        };
    };
    return _;
};
auto joinWith() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& splice) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Foldable::intercalate()(dictFoldable)(Data_Monoid::monoidString())(splice))(Unsafe_Coerce::unsafeCoerce());
        };
    };
    return _;
};
auto join1With() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& splice) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_Internal::NonEmptyString())(Data_String_NonEmpty_Internal::joinWith()(dictFoldable1["Foldable0"](undefined))(splice));
        };
    };
    return _;
};
auto fromString() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<juce::String>(v) == "") {
            return Data_Maybe::Nothing();
        };
        return Data_Maybe::Just()(v);
    };
    return _;
};
auto stripPrefix() -> const boxed& {
    static const boxed _ = [](const boxed& pat) -> boxed {
        return Control_Bind::composeKleisliFlipped()(Data_Maybe::bindMaybe())(Data_String_NonEmpty_Internal::fromString())(Data_String_NonEmpty_Internal::liftS()(Data_String_CodeUnits::stripPrefix()(pat)));
    };
    return _;
};
auto stripSuffix() -> const boxed& {
    static const boxed _ = [](const boxed& pat) -> boxed {
        return Control_Bind::composeKleisliFlipped()(Data_Maybe::bindMaybe())(Data_String_NonEmpty_Internal::fromString())(Data_String_NonEmpty_Internal::liftS()(Data_String_CodeUnits::stripSuffix()(pat)));
    };
    return _;
};
auto trim() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_String_NonEmpty_Internal::fromString()(Data_String_Common::trim()(v));
    };
    return _;
};
auto unsafeFromString() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::fromJust()(dictPartial))(Data_String_NonEmpty_Internal::fromString());
    };
    return _;
};
auto eqNonEmptyString() -> boxed {
    return Data_Eq::eqString();
};
auto eqNonEmptyReplacement() -> boxed {
    return Data_String_NonEmpty_Internal::eqNonEmptyString();
};
auto contains() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_NonEmpty_Internal::liftS())(Data_String_CodeUnits::contains());
};
auto appendString() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& s2) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())(v)(s2);
        };
    };
    return _;
};


} // end namespace Data_String_NonEmpty_Internal


