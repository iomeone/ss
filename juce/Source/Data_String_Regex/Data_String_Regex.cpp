#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Array_NonEmpty/Data_Array_NonEmpty.h"
#include "Data_Either/Data_Either.h"
#include "Data_Function/Data_Function.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Data_String/Data_String.h"
#include "Data_String_CodeUnits/Data_String_CodeUnits.h"
#include "Data_String_Pattern/Data_String_Pattern.h"
#include "Data_String_Regex_Flags/Data_String_Regex_Flags.h"
#include "Prelude/Prelude.h"

#include "Data_String_Regex/Data_String_Regex.h"


namespace Data_String_Regex {

auto showRegex() -> boxed {
    return Data_Show::Show()(Data_String_Regex::showRegex_Prime_());
};
auto search() -> boxed {
    return Data_String_Regex::_search()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto renderFlags() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())([=]() -> boxed {
            if (unbox<bool>(v["value0"]["global"])) {
                return "g";
            };
            return "";
        }())(Data_Semigroup::append()(Data_Semigroup::semigroupString())([=]() -> boxed {
            if (unbox<bool>(v["value0"]["ignoreCase"])) {
                return "i";
            };
            return "";
        }())(Data_Semigroup::append()(Data_Semigroup::semigroupString())([=]() -> boxed {
            if (unbox<bool>(v["value0"]["multiline"])) {
                return "m";
            };
            return "";
        }())(Data_Semigroup::append()(Data_Semigroup::semigroupString())([=]() -> boxed {
            if (unbox<bool>(v["value0"]["sticky"])) {
                return "y";
            };
            return "";
        }())([=]() -> boxed {
            if (unbox<bool>(v["value0"]["unicode"])) {
                return "u";
            };
            return "";
        }()))));
    };
    return _;
};
auto regex() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_String_Regex::regex_Prime_()(Data_Either::Left())(Data_Either::Right())(s)(Data_String_Regex::renderFlags()(f));
        };
    };
    return _;
};
auto parseFlags() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        return Data_String_Regex_Flags::RegexFlags()(dict_t{
            { "global", Data_String_CodeUnits::contains()("g")(s) },
            { "ignoreCase", Data_String_CodeUnits::contains()("i")(s) },
            { "multiline", Data_String_CodeUnits::contains()("m")(s) },
            { "sticky", Data_String_CodeUnits::contains()("y")(s) },
            { "unicode", Data_String_CodeUnits::contains()("u")(s) }
        });
    };
    return _;
};
auto match() -> boxed {
    return Data_String_Regex::_match()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto flags() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_String_Regex_Flags::RegexFlags())(Data_String_Regex::flags_Prime_());
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto showRegex_Prime_() -> const boxed& { static const boxed _ = foreign().at("showRegex'"); return _; };
auto regex_Prime_() -> const boxed& { static const boxed _ = foreign().at("regex'"); return _; };
auto source() -> const boxed& { static const boxed _ = foreign().at("source"); return _; };
auto flags_Prime_() -> const boxed& { static const boxed _ = foreign().at("flags'"); return _; };
auto test() -> const boxed& { static const boxed _ = foreign().at("test"); return _; };
auto _match() -> const boxed& { static const boxed _ = foreign().at("_match"); return _; };
auto replace() -> const boxed& { static const boxed _ = foreign().at("replace"); return _; };
auto replace_Prime_() -> const boxed& { static const boxed _ = foreign().at("replace'"); return _; };
auto _search() -> const boxed& { static const boxed _ = foreign().at("_search"); return _; };
auto split() -> const boxed& { static const boxed _ = foreign().at("split"); return _; };

} // end namespace Data_String_Regex


