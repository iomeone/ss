
#include "Data_Boolean/Data_Boolean.h"


namespace Data_Boolean {

auto otherwise() -> const boxed& {
    static const boxed _ = true;
    return _;
};


} // end namespace Data_Boolean


