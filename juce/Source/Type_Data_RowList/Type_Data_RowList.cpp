
#include "Type_Data_RowList/Type_Data_RowList.h"


namespace Type_Data_RowList {

auto RLProxy() -> const boxed& {
    static const boxed _ = dict_t{
        { "RLProxy", true }
    };
    return _;
};


} // end namespace Type_Data_RowList


