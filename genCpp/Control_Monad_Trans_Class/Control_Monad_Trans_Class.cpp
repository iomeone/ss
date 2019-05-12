#include "Prelude/Prelude.h"

#include "Control_Monad_Trans_Class/Control_Monad_Trans_Class.h"


namespace Control_Monad_Trans_Class {

auto MonadTrans() -> const boxed& {
    static const boxed _ = [](const boxed& lift) -> boxed {
        return dict_t{
            { "lift", lift }
        };
    };
    return _;
};
auto lift() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["lift"];
    };
    return _;
};


} // end namespace Control_Monad_Trans_Class


