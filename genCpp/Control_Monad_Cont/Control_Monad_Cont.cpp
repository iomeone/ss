#include "Control_Monad_Cont_Class/Control_Monad_Cont_Class.h"
#include "Control_Monad_Cont_Trans/Control_Monad_Cont_Trans.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Cont/Control_Monad_Cont.h"


namespace Control_Monad_Cont {

auto withCont() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Monad_Cont_Trans::withContT()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity())))));
    };
    return _;
};
auto runCont() -> const boxed& {
    static const boxed _ = [](const boxed& cc) -> boxed {
        return [=](const boxed& k) -> boxed {
            return Data_Newtype::unwrap()(Data_Identity::newtypeIdentity())(Control_Monad_Cont_Trans::runContT()(cc)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(k)));
        };
    };
    return _;
};
auto mapCont() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Monad_Cont_Trans::mapContT()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))));
    };
    return _;
};
auto cont() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& c) -> boxed {
            return f(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(c));
        };
    };
    return _;
};


} // end namespace Control_Monad_Cont


