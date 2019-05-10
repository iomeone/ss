
#include "Record_Unsafe/Record_Unsafe.h"


namespace Record_Unsafe {




// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unsafeHas() -> const boxed& { static const boxed _ = foreign().at("unsafeHas"); return _; };
auto unsafeGet() -> const boxed& { static const boxed _ = foreign().at("unsafeGet"); return _; };
auto unsafeSet() -> const boxed& { static const boxed _ = foreign().at("unsafeSet"); return _; };
auto unsafeDelete() -> const boxed& { static const boxed _ = foreign().at("unsafeDelete"); return _; };

} // end namespace Record_Unsafe


