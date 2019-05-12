#include "Data_Array/Data_Array.h"
#include "Data_Ring/Data_Ring.h"
#include "Prelude/Prelude.h"

#include "Data_Array_Partial/Data_Array_Partial.h"


namespace Data_Array_Partial {

auto tail() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::slice()(1)(Data_Array::length()(xs))(xs);
        };
    };
    return _;
};
auto last() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::unsafeIndex()(dictPartial)(xs)(unbox<int>(Data_Array::length()(xs)) - 1);
        };
    };
    return _;
};
auto init() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::slice()(0)(unbox<int>(Data_Array::length()(xs)) - 1)(xs);
        };
    };
    return _;
};
auto head() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::unsafeIndex()(dictPartial)(xs)(0);
        };
    };
    return _;
};


} // end namespace Data_Array_Partial


