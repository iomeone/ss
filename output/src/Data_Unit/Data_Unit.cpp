#include "Data_Show/Data_Show.h"

#include "Data_Unit/Data_Unit.h"


namespace Data_Unit {

auto showUnit() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return "unit";
    });
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unit() -> const boxed& { static const boxed _ = foreign().at("unit"); return _; };

} // end namespace Data_Unit


