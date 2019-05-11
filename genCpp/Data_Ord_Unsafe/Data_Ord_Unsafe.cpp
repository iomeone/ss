#include "Data_Ordering/Data_Ordering.h"

#include "Data_Ord_Unsafe/Data_Ord_Unsafe.h"


namespace Data_Ord_Unsafe {

auto unsafeCompare() -> boxed {
    return Data_Ord_Unsafe::unsafeCompareImpl()(Data_Ordering::LT())(Data_Ordering::EQ())(Data_Ordering::GT());
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unsafeCompareImpl() -> const boxed& { static const boxed _ = foreign().at("unsafeCompareImpl"); return _; };

} // end namespace Data_Ord_Unsafe


