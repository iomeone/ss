#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Control_Plus/Control_Plus.h"
#include "Data_Functor/Data_Functor.h"

#include "Control_MonadPlus/Control_MonadPlus.h"


namespace Control_MonadPlus {

auto MonadPlus() -> const boxed& {
    static const boxed _ = [](const boxed& MonadZero0) -> boxed {
        return dict_t{
            { "MonadZero0", MonadZero0 }
        };
    };
    return _;
};
auto monadPlusArray() -> boxed {
    return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
        return Control_MonadZero::monadZeroArray();
    });
};


} // end namespace Control_MonadPlus


