#include "Data_Either/Data_Either.h"
#include "Data_String_Regex/Data_String_Regex.h"
#include "Data_String_Regex_Flags/Data_String_Regex_Flags.h"
#include "Partial_Unsafe/Partial_Unsafe.h"

#include "Data_String_Regex_Unsafe/Data_String_Regex_Unsafe.h"


namespace Data_String_Regex_Unsafe {

auto unsafeRegex() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& dictPartial) -> boxed {
                return Data_Either::fromRight()(dictPartial);
            }(undefined)(Data_String_Regex::regex()(s)(f));
        };
    };
    return _;
};


} // end namespace Data_String_Regex_Unsafe


