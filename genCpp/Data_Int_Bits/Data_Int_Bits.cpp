
#include "Data_Int_Bits/Data_Int_Bits.h"


namespace Data_Int_Bits {




// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto _and_() -> const boxed& { static const boxed _ = foreign().at("and"); return _; };
auto _or_() -> const boxed& { static const boxed _ = foreign().at("or"); return _; };
auto _xor_() -> const boxed& { static const boxed _ = foreign().at("xor"); return _; };
auto shl() -> const boxed& { static const boxed _ = foreign().at("shl"); return _; };
auto shr() -> const boxed& { static const boxed _ = foreign().at("shr"); return _; };
auto zshr() -> const boxed& { static const boxed _ = foreign().at("zshr"); return _; };
auto complement() -> const boxed& { static const boxed _ = foreign().at("complement"); return _; };

} // end namespace Data_Int_Bits


