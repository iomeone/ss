#include "Data_Eq/Data_Eq.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_String_Pattern/Data_String_Pattern.h"
#include "Prelude/Prelude.h"

#include "Data_String_Common/Data_String_Common.h"


namespace Data_String_Common {

auto null() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        return Data_Eq::eq()(Data_Eq::eqString())(s)("");
    };
    return _;
};
auto localeCompare() -> boxed {
    return Data_String_Common::_localeCompare()(Data_Ordering::LT())(Data_Ordering::EQ())(Data_Ordering::GT());
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto _localeCompare() -> const boxed& { static const boxed _ = foreign().at("_localeCompare"); return _; };
auto replace() -> const boxed& { static const boxed _ = foreign().at("replace"); return _; };
auto replaceAll() -> const boxed& { static const boxed _ = foreign().at("replaceAll"); return _; };
auto split() -> const boxed& { static const boxed _ = foreign().at("split"); return _; };
auto toLower() -> const boxed& { static const boxed _ = foreign().at("toLower"); return _; };
auto toUpper() -> const boxed& { static const boxed _ = foreign().at("toUpper"); return _; };
auto trim() -> const boxed& { static const boxed _ = foreign().at("trim"); return _; };
auto joinWith() -> const boxed& { static const boxed _ = foreign().at("joinWith"); return _; };

} // end namespace Data_String_Common


