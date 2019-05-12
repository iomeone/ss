#include "Control_Extend/Control_Extend.h"
#include "Data_Functor/Data_Functor.h"

#include "Control_Comonad/Control_Comonad.h"


namespace Control_Comonad {

auto Comonad() -> const boxed& {
    static const boxed _ = [](const boxed& Extend0) -> boxed {
        return [=](const boxed& extract) -> boxed {
            return dict_t{
                { "Extend0", Extend0 },
                { "extract", extract }
            };
        };
    };
    return _;
};
auto extract() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["extract"];
    };
    return _;
};


} // end namespace Control_Comonad


