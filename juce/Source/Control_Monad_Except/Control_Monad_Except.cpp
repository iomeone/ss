#include "Control_Monad_Error_Class/Control_Monad_Error_Class.h"
#include "Control_Monad_Except_Trans/Control_Monad_Except_Trans.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Either/Data_Either.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Except/Control_Monad_Except.h"


namespace Control_Monad_Except {

auto withExcept() -> boxed {
    return Control_Monad_Except_Trans::withExceptT()(Data_Identity::functorIdentity());
};
auto runExcept() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(Control_Monad_Except_Trans::runExceptT());
};
auto mapExcept() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Monad_Except_Trans::mapExceptT()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))));
    };
    return _;
};


} // end namespace Control_Monad_Except


