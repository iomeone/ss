#include "Control_Monad_Reader_Class/Control_Monad_Reader_Class.h"
#include "Control_Monad_Reader_Trans/Control_Monad_Reader_Trans.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Reader/Control_Monad_Reader.h"


namespace Control_Monad_Reader {

auto withReader() -> boxed {
    return Control_Monad_Reader_Trans::withReaderT();
};
auto runReader() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(v);
    };
    return _;
};
auto mapReader() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Monad_Reader_Trans::mapReaderT()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))));
    };
    return _;
};


} // end namespace Control_Monad_Reader


