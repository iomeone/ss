
#include "Data_String_Unsafe/Data_String_Unsafe.h"


namespace Data_String_Unsafe {




// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto charAt() -> const boxed& { static const boxed _ = foreign().at("charAt"); return _; };
auto _char_() -> const boxed& { static const boxed _ = foreign().at("char"); return _; };

} // end namespace Data_String_Unsafe


