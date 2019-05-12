#include "Control_Comonad_Env_Class/Control_Comonad_Env_Class.h"
#include "Control_Comonad_Env_Trans/Control_Comonad_Env_Trans.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Comonad_Env/Control_Comonad_Env.h"


namespace Control_Comonad_Env {

auto withEnv() -> boxed {
    return Control_Comonad_Env_Trans::withEnvT();
};
auto runEnv() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Functor::map()(Data_Tuple::functorTuple())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(v);
    };
    return _;
};
auto mapEnv() -> boxed {
    return Data_Functor::map()(Control_Comonad_Env_Trans::functorEnvT()(Data_Identity::functorIdentity()));
};
auto env() -> const boxed& {
    static const boxed _ = [](const boxed& e) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Control_Comonad_Env_Trans::EnvT()(Data_Tuple::Tuple()(e)(a));
        };
    };
    return _;
};


} // end namespace Control_Comonad_Env


