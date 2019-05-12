
#include "Math/Math.h"


namespace Math {




// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto abs() -> const boxed& { static const boxed _ = foreign().at("abs"); return _; };
auto acos() -> const boxed& { static const boxed _ = foreign().at("acos"); return _; };
auto asin() -> const boxed& { static const boxed _ = foreign().at("asin"); return _; };
auto atan() -> const boxed& { static const boxed _ = foreign().at("atan"); return _; };
auto atan2() -> const boxed& { static const boxed _ = foreign().at("atan2"); return _; };
auto ceil() -> const boxed& { static const boxed _ = foreign().at("ceil"); return _; };
auto cos() -> const boxed& { static const boxed _ = foreign().at("cos"); return _; };
auto exp() -> const boxed& { static const boxed _ = foreign().at("exp"); return _; };
auto floor() -> const boxed& { static const boxed _ = foreign().at("floor"); return _; };
auto log() -> const boxed& { static const boxed _ = foreign().at("log"); return _; };
auto max() -> const boxed& { static const boxed _ = foreign().at("max"); return _; };
auto min() -> const boxed& { static const boxed _ = foreign().at("min"); return _; };
auto pow() -> const boxed& { static const boxed _ = foreign().at("pow"); return _; };
auto round() -> const boxed& { static const boxed _ = foreign().at("round"); return _; };
auto sin() -> const boxed& { static const boxed _ = foreign().at("sin"); return _; };
auto sqrt() -> const boxed& { static const boxed _ = foreign().at("sqrt"); return _; };
auto tan() -> const boxed& { static const boxed _ = foreign().at("tan"); return _; };
auto trunc() -> const boxed& { static const boxed _ = foreign().at("trunc"); return _; };
auto remainder() -> const boxed& { static const boxed _ = foreign().at("remainder"); return _; };
auto e() -> const boxed& { static const boxed _ = foreign().at("e"); return _; };
auto ln2() -> const boxed& { static const boxed _ = foreign().at("ln2"); return _; };
auto ln10() -> const boxed& { static const boxed _ = foreign().at("ln10"); return _; };
auto log2e() -> const boxed& { static const boxed _ = foreign().at("log2e"); return _; };
auto log10e() -> const boxed& { static const boxed _ = foreign().at("log10e"); return _; };
auto pi() -> const boxed& { static const boxed _ = foreign().at("pi"); return _; };
auto tau() -> const boxed& { static const boxed _ = foreign().at("tau"); return _; };
auto sqrt1_2() -> const boxed& { static const boxed _ = foreign().at("sqrt1_2"); return _; };
auto sqrt2() -> const boxed& { static const boxed _ = foreign().at("sqrt2"); return _; };

} // end namespace Math


