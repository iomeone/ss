#include "Control_Monad_ST/Control_Monad_ST.h"
#include "Data_Array_ST/Data_Array_ST.h"
#include "Data_Unit/Data_Unit.h"

#include "Data_Array_ST_Partial/Data_Array_ST_Partial.h"


namespace Data_Array_ST_Partial {

auto poke() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return Data_Array_ST_Partial::pokeImpl();
    };
    return _;
};
auto _peek_() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return Data_Array_ST_Partial::peekImpl();
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto peekImpl() -> const boxed& { static const boxed _ = foreign().at("peekImpl"); return _; };
auto pokeImpl() -> const boxed& { static const boxed _ = foreign().at("pokeImpl"); return _; };

} // end namespace Data_Array_ST_Partial


