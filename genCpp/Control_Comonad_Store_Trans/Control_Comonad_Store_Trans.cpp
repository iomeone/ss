#include "Control_Comonad/Control_Comonad.h"
#include "Control_Comonad_Trans_Class/Control_Comonad_Trans_Class.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Comonad_Store_Trans/Control_Comonad_Store_Trans.h"


namespace Control_Comonad_Store_Trans {

auto StoreT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto runStoreT() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto newtypeStoreT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Comonad_Store_Trans::StoreT());
};
auto functorStoreT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Comonad_Store_Trans::StoreT()(Data_Tuple::Tuple()(Data_Functor::map()(dictFunctor)([=](const boxed& h) -> boxed {
                    return Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(h)(f);
                })(v["value0"]))(v["value1"]));
            };
        });
    };
    return _;
};
auto extendStoreT() -> const boxed& {
    static const boxed _ = [](const boxed& dictExtend) -> boxed {
        return Control_Extend::Extend()([=](const boxed&) -> boxed {
            return Control_Comonad_Store_Trans::functorStoreT()(dictExtend["Functor0"](undefined));
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Comonad_Store_Trans::StoreT()(Data_Tuple::Tuple()(Control_Extend::extend()(dictExtend)([=](const boxed& w_Prime_) -> boxed {
                    return [=](const boxed& s_Prime_) -> boxed {
                        return f(Control_Comonad_Store_Trans::StoreT()(Data_Tuple::Tuple()(w_Prime_)(s_Prime_)));
                    };
                })(v["value0"]))(v["value1"]));
            };
        });
    };
    return _;
};
auto comonadTransStoreT() -> boxed {
    return Control_Comonad_Trans_Class::ComonadTrans()([=](const boxed& dictComonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictComonad["Extend0"](undefined)["Functor0"](undefined))([=](const boxed& v1) -> boxed {
                return v1(v["value1"]);
            })(v["value0"]);
        };
    });
};
auto comonadStoreT() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonad) -> boxed {
        return Control_Comonad::Comonad()([=](const boxed&) -> boxed {
            return Control_Comonad_Store_Trans::extendStoreT()(dictComonad["Extend0"](undefined));
        })([=](const boxed& v) -> boxed {
            return Control_Comonad::extract()(dictComonad)(v["value0"])(v["value1"]);
        });
    };
    return _;
};


} // end namespace Control_Comonad_Store_Trans


