#include "Data_Enum/Data_Enum.h"
#include "Data_Maybe/Data_Maybe.h"

#include "Data_Char/Data_Char.h"


namespace Data_Char {

auto toCharCode() -> boxed {
    return Data_Enum::fromEnum()(Data_Enum::boundedEnumChar());
};
auto fromCharCode() -> boxed {
    return Data_Enum::toEnum()(Data_Enum::boundedEnumChar());
};


} // end namespace Data_Char


