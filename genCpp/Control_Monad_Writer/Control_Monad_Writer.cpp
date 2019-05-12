#include "Control_Applicative/Control_Applicative.h"
#include "Control_Monad_Writer_Class/Control_Monad_Writer_Class.h"
#include "Control_Monad_Writer_Trans/Control_Monad_Writer_Trans.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Writer/Control_Monad_Writer.h"


namespace Control_Monad_Writer {

auto writer() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Writer_Trans::WriterT())(Control_Applicative::pure()(Data_Identity::applicativeIdentity()));
};
auto runWriter() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(Control_Monad_Writer_Trans::runWriterT());
};
auto mapWriter() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Monad_Writer_Trans::mapWriterT()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))));
    };
    return _;
};
auto execWriter() -> const boxed& {
    static const boxed _ = [](const boxed& m) -> boxed {
        return Data_Tuple::snd()(Control_Monad_Writer::runWriter()(m));
    };
    return _;
};


} // end namespace Control_Monad_Writer


