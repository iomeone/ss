
#include "Global/Global.h"


namespace Global {




// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto nan() -> const boxed& { static const boxed _ = foreign().at("nan"); return _; };
auto isNaN() -> const boxed& { static const boxed _ = foreign().at("isNaN"); return _; };
auto infinity() -> const boxed& { static const boxed _ = foreign().at("infinity"); return _; };
auto isFinite() -> const boxed& { static const boxed _ = foreign().at("isFinite"); return _; };
auto readInt() -> const boxed& { static const boxed _ = foreign().at("readInt"); return _; };
auto readFloat() -> const boxed& { static const boxed _ = foreign().at("readFloat"); return _; };

} // end namespace Global


