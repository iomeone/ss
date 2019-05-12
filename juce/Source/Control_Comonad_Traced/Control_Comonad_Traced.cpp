#include "Control_Comonad_Traced_Class/Control_Comonad_Traced_Class.h"
#include "Control_Comonad_Traced_Trans/Control_Comonad_Traced_Trans.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Prelude/Prelude.h"

#include "Control_Comonad_Traced/Control_Comonad_Traced.h"


namespace Control_Comonad_Traced {

auto traced() -> boxed {
    return Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(Control_Comonad_Traced_Trans::TracedT());
};
auto runTraced() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Newtype::unwrap()(Data_Identity::newtypeIdentity())(v);
    };
    return _;
};


} // end namespace Control_Comonad_Traced


