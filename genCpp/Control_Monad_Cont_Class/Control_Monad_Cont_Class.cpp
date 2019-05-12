#include "Prelude/Prelude.h"

#include "Control_Monad_Cont_Class/Control_Monad_Cont_Class.h"


namespace Control_Monad_Cont_Class {

auto MonadCont() -> const boxed& {
    static const boxed _ = [](const boxed& Monad0) -> boxed {
        return [=](const boxed& callCC) -> boxed {
            return dict_t{
                { "Monad0", Monad0 },
                { "callCC", callCC }
            };
        };
    };
    return _;
};
auto callCC() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["callCC"];
    };
    return _;
};


} // end namespace Control_Monad_Cont_Class


