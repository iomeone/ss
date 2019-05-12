#include "Control_Comonad/Control_Comonad.h"

#include "Control_Comonad_Trans_Class/Control_Comonad_Trans_Class.h"


namespace Control_Comonad_Trans_Class {

auto ComonadTrans() -> const boxed& {
    static const boxed _ = [](const boxed& lower) -> boxed {
        return dict_t{
            { "lower", lower }
        };
    };
    return _;
};
auto lower() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["lower"];
    };
    return _;
};


} // end namespace Control_Comonad_Trans_Class


