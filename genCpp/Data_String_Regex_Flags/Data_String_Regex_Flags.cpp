#include "Control_MonadPlus/Control_MonadPlus.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Data_String/Data_String.h"
#include "Data_String_Common/Data_String_Common.h"
#include "Prelude/Prelude.h"

#include "Data_String_Regex_Flags/Data_String_Regex_Flags.h"


namespace Data_String_Regex_Flags {

auto RegexFlags() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "RegexFlags", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto unicode() -> boxed {
    return Data_String_Regex_Flags::RegexFlags()(dict_t{
        { "global", false },
        { "ignoreCase", false },
        { "multiline", false },
        { "sticky", false },
        { "unicode", true }
    });
};
auto sticky() -> boxed {
    return Data_String_Regex_Flags::RegexFlags()(dict_t{
        { "global", false },
        { "ignoreCase", false },
        { "multiline", false },
        { "sticky", true },
        { "unicode", false }
    });
};
auto showRegexFlags() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        boxed usedFlags = Data_Semigroup::append()(Data_Semigroup::semigroupArray())(array_t{  })(Data_Semigroup::append()(Data_Semigroup::semigroupArray())(Data_Functor::voidLeft()(Data_Functor::functorArray())(Control_MonadZero::guard()(Control_MonadZero::monadZeroArray())(v["value0"]["global"]))("global"))(Data_Semigroup::append()(Data_Semigroup::semigroupArray())(Data_Functor::voidLeft()(Data_Functor::functorArray())(Control_MonadZero::guard()(Control_MonadZero::monadZeroArray())(v["value0"]["ignoreCase"]))("ignoreCase"))(Data_Semigroup::append()(Data_Semigroup::semigroupArray())(Data_Functor::voidLeft()(Data_Functor::functorArray())(Control_MonadZero::guard()(Control_MonadZero::monadZeroArray())(v["value0"]["multiline"]))("multiline"))(Data_Semigroup::append()(Data_Semigroup::semigroupArray())(Data_Functor::voidLeft()(Data_Functor::functorArray())(Control_MonadZero::guard()(Control_MonadZero::monadZeroArray())(v["value0"]["sticky"]))("sticky"))(Data_Functor::voidLeft()(Data_Functor::functorArray())(Control_MonadZero::guard()(Control_MonadZero::monadZeroArray())(v["value0"]["unicode"]))("unicode"))))));
        boxed _Local_6 = Data_Eq::eq()(Data_Eq::eqArray()(Data_Eq::eqString()))(usedFlags)(array_t{  });
        if (unbox<bool>(_Local_6)) {
            return "noFlags";
        };
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_String_Common::joinWith()(" <> ")(usedFlags))(")"));
    });
};
auto semigroupRegexFlags() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_String_Regex_Flags::RegexFlags()(dict_t{
                { "global", unbox<bool>(v["value0"]["global"])|| unbox<bool>(v1["value0"]["global"]) },
                { "ignoreCase", unbox<bool>(v["value0"]["ignoreCase"])|| unbox<bool>(v1["value0"]["ignoreCase"]) },
                { "multiline", unbox<bool>(v["value0"]["multiline"])|| unbox<bool>(v1["value0"]["multiline"]) },
                { "sticky", unbox<bool>(v["value0"]["sticky"])|| unbox<bool>(v1["value0"]["sticky"]) },
                { "unicode", unbox<bool>(v["value0"]["unicode"])|| unbox<bool>(v1["value0"]["unicode"]) }
            });
        };
    });
};
auto noFlags() -> boxed {
    return Data_String_Regex_Flags::RegexFlags()(dict_t{
        { "global", false },
        { "ignoreCase", false },
        { "multiline", false },
        { "sticky", false },
        { "unicode", false }
    });
};
auto multiline() -> boxed {
    return Data_String_Regex_Flags::RegexFlags()(dict_t{
        { "global", false },
        { "ignoreCase", false },
        { "multiline", true },
        { "sticky", false },
        { "unicode", false }
    });
};
auto monoidRegexFlags() -> boxed {
    return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
        return Data_String_Regex_Flags::semigroupRegexFlags();
    })(Data_String_Regex_Flags::noFlags());
};
auto ignoreCase() -> boxed {
    return Data_String_Regex_Flags::RegexFlags()(dict_t{
        { "global", false },
        { "ignoreCase", true },
        { "multiline", false },
        { "sticky", false },
        { "unicode", false }
    });
};
auto global() -> boxed {
    return Data_String_Regex_Flags::RegexFlags()(dict_t{
        { "global", true },
        { "ignoreCase", false },
        { "multiline", false },
        { "sticky", false },
        { "unicode", false }
    });
};
auto eqRegexFlags() -> boxed {
    return Data_Eq::Eq()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return unbox<bool>(Data_Eq::eq()(Data_Eq::eqBoolean())(v["value0"]["global"])(v1["value0"]["global"])) && unbox<bool>(unbox<bool>(Data_Eq::eq()(Data_Eq::eqBoolean())(v["value0"]["ignoreCase"])(v1["value0"]["ignoreCase"])) && unbox<bool>(unbox<bool>(Data_Eq::eq()(Data_Eq::eqBoolean())(v["value0"]["multiline"])(v1["value0"]["multiline"])) && unbox<bool>(unbox<bool>(Data_Eq::eq()(Data_Eq::eqBoolean())(v["value0"]["sticky"])(v1["value0"]["sticky"])) && unbox<bool>(Data_Eq::eq()(Data_Eq::eqBoolean())(v["value0"]["unicode"])(v1["value0"]["unicode"])))));
        };
    });
};


} // end namespace Data_String_Regex_Flags


