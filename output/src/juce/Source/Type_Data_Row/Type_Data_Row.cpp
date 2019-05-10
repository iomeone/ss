
#include "Type_Data_Row/Type_Data_Row.h"


namespace Type_Data_Row {

auto RProxy() -> const boxed& {
    static const boxed _ = dict_t{
        { "RProxy", true }
    };
    return _;
};


} // end namespace Type_Data_Row


