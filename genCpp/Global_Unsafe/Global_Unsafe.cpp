
#include "Global_Unsafe/Global_Unsafe.h"


namespace Global_Unsafe {




// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unsafeStringify() -> const boxed& { static const boxed _ = foreign().at("unsafeStringify"); return _; };
auto unsafeToFixed() -> const boxed& { static const boxed _ = foreign().at("unsafeToFixed"); return _; };
auto unsafeToExponential() -> const boxed& { static const boxed _ = foreign().at("unsafeToExponential"); return _; };
auto unsafeToPrecision() -> const boxed& { static const boxed _ = foreign().at("unsafeToPrecision"); return _; };
auto unsafeDecodeURI() -> const boxed& { static const boxed _ = foreign().at("unsafeDecodeURI"); return _; };
auto unsafeEncodeURI() -> const boxed& { static const boxed _ = foreign().at("unsafeEncodeURI"); return _; };
auto unsafeDecodeURIComponent() -> const boxed& { static const boxed _ = foreign().at("unsafeDecodeURIComponent"); return _; };
auto unsafeEncodeURIComponent() -> const boxed& { static const boxed _ = foreign().at("unsafeEncodeURIComponent"); return _; };

} // end namespace Global_Unsafe


