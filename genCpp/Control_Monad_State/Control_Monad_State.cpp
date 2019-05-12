#include "Control_Monad_State_Class/Control_Monad_State_Class.h"
#include "Control_Monad_State_Trans/Control_Monad_State_Trans.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_State/Control_Monad_State.h"


namespace Control_Monad_State {

auto withState() -> boxed {
    return Control_Monad_State_Trans::withStateT();
};
auto runState() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(v);
    };
    return _;
};
auto mapState() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Monad_State_Trans::mapStateT()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))));
    };
    return _;
};
auto execState() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& s) -> boxed {
            boxed v1 = v(s);
            return v1["value1"];
        };
    };
    return _;
};
auto evalState() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& s) -> boxed {
            boxed v1 = v(s);
            return v1["value0"];
        };
    };
    return _;
};


} // end namespace Control_Monad_State


