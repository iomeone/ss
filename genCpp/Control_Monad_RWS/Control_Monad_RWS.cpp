#include "Control_Applicative/Control_Applicative.h"
#include "Control_Monad_RWS_Trans/Control_Monad_RWS_Trans.h"
#include "Control_Monad_Reader_Class/Control_Monad_Reader_Class.h"
#include "Control_Monad_State_Class/Control_Monad_State_Class.h"
#include "Control_Monad_Trans_Class/Control_Monad_Trans_Class.h"
#include "Control_Monad_Writer_Class/Control_Monad_Writer_Class.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_RWS/Control_Monad_RWS.h"


namespace Control_Monad_RWS {

auto withRWS() -> boxed {
    return Control_Monad_RWS_Trans::withRWST();
};
auto rws() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& r) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Control_Applicative::pure()(Data_Identity::applicativeIdentity())(f(r)(s));
            };
        };
    };
    return _;
};
auto runRWS() -> const boxed& {
    static const boxed _ = [](const boxed& m) -> boxed {
        return [=](const boxed& r) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed v = m(r)(s);
                return v;
            };
        };
    };
    return _;
};
auto mapRWS() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Monad_RWS_Trans::mapRWST()(Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Identity::Identity())));
    };
    return _;
};
auto execRWS() -> const boxed& {
    static const boxed _ = [](const boxed& m) -> boxed {
        return [=](const boxed& r) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Data_Newtype::unwrap()(Data_Identity::newtypeIdentity())(Control_Monad_RWS_Trans::execRWST()(Data_Identity::monadIdentity())(m)(r)(s));
            };
        };
    };
    return _;
};
auto evalRWS() -> const boxed& {
    static const boxed _ = [](const boxed& m) -> boxed {
        return [=](const boxed& r) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Data_Newtype::unwrap()(Data_Identity::newtypeIdentity())(Control_Monad_RWS_Trans::evalRWST()(Data_Identity::monadIdentity())(m)(r)(s));
            };
        };
    };
    return _;
};


} // end namespace Control_Monad_RWS


