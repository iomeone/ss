#include "Control_Comonad_Store_Class/Control_Comonad_Store_Class.h"
#include "Control_Comonad_Store_Trans/Control_Comonad_Store_Trans.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Comonad_Store/Control_Comonad_Store.h"


namespace Control_Comonad_Store {

auto store() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Control_Comonad_Store_Trans::StoreT()(Data_Tuple::Tuple()(f)(x));
        };
    };
    return _;
};
auto runStore() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Tuple::swap()(Data_Functor::map()(Data_Tuple::functorTuple())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(Data_Tuple::swap()(v)));
    };
    return _;
};


} // end namespace Control_Comonad_Store


