#include "Control_Comonad/Control_Comonad.h"
#include "Control_Comonad_Env_Trans/Control_Comonad_Env_Trans.h"
#include "Control_Comonad_Store_Trans/Control_Comonad_Store_Trans.h"
#include "Control_Comonad_Traced_Trans/Control_Comonad_Traced_Trans.h"
#include "Control_Comonad_Trans_Class/Control_Comonad_Trans_Class.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Comonad_Store_Class/Control_Comonad_Store_Class.h"


namespace Control_Comonad_Store_Class {

auto ComonadStore() -> const boxed& {
    static const boxed _ = [](const boxed& Comonad0) -> boxed {
        return [=](const boxed& _peek_) -> boxed {
            return [=](const boxed& pos) -> boxed {
                return dict_t{
                    { "Comonad0", Comonad0 },
                    { "peek", _peek_ },
                    { "pos", pos }
                };
            };
        };
    };
    return _;
};
auto pos() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["pos"];
    };
    return _;
};
auto _peek_() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["peek"];
    };
    return _;
};
auto peeks() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonadStore) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& x) -> boxed {
                return Control_Comonad_Store_Class::_peek_()(dictComonadStore)(f(Control_Comonad_Store_Class::pos()(dictComonadStore)(x)))(x);
            };
        };
    };
    return _;
};
auto seeks() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonadStore) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Comonad_Store_Class::peeks()(dictComonadStore)(f))(Control_Extend::duplicate()(dictComonadStore["Comonad0"](undefined)["Extend0"](undefined)));
        };
    };
    return _;
};
auto seek() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonadStore) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Comonad_Store_Class::_peek_()(dictComonadStore)(s))(Control_Extend::duplicate()(dictComonadStore["Comonad0"](undefined)["Extend0"](undefined)));
        };
    };
    return _;
};
auto experiment() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonadStore) -> boxed {
        return [=](const boxed& dictFunctor) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& x) -> boxed {
                    return Data_Functor::map()(dictFunctor)(Data_Function::flip()(Control_Comonad_Store_Class::_peek_()(dictComonadStore))(x))(f(Control_Comonad_Store_Class::pos()(dictComonadStore)(x)));
                };
            };
        };
    };
    return _;
};
auto comonadStoreTracedT() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonadStore) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Comonad_Store_Class::ComonadStore()([=](const boxed&) -> boxed {
                return Control_Comonad_Traced_Trans::comonadTracedT()(dictComonadStore["Comonad0"](undefined))(dictMonoid);
            })([=](const boxed& s) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Comonad_Store_Class::_peek_()(dictComonadStore)(s))(Control_Comonad_Trans_Class::lower()(Control_Comonad_Traced_Trans::comonadTransTracedT()(dictMonoid))(dictComonadStore["Comonad0"](undefined)));
            })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Comonad_Store_Class::pos()(dictComonadStore))(Control_Comonad_Trans_Class::lower()(Control_Comonad_Traced_Trans::comonadTransTracedT()(dictMonoid))(dictComonadStore["Comonad0"](undefined))));
        };
    };
    return _;
};
auto comonadStoreStoreT() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonad) -> boxed {
        return Control_Comonad_Store_Class::ComonadStore()([=](const boxed&) -> boxed {
            return Control_Comonad_Store_Trans::comonadStoreT()(dictComonad);
        })([=](const boxed& s) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Comonad::extract()(dictComonad)(v["value0"])(s);
            };
        })([=](const boxed& v) -> boxed {
            return v["value1"];
        });
    };
    return _;
};
auto comonadStoreEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonadStore) -> boxed {
        return Control_Comonad_Store_Class::ComonadStore()([=](const boxed&) -> boxed {
            return Control_Comonad_Env_Trans::comonadEnvT()(dictComonadStore["Comonad0"](undefined));
        })([=](const boxed& s) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Comonad_Store_Class::_peek_()(dictComonadStore)(s))(Control_Comonad_Trans_Class::lower()(Control_Comonad_Env_Trans::comonadTransEnvT())(dictComonadStore["Comonad0"](undefined)));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Comonad_Store_Class::pos()(dictComonadStore))(Control_Comonad_Trans_Class::lower()(Control_Comonad_Env_Trans::comonadTransEnvT())(dictComonadStore["Comonad0"](undefined))));
    };
    return _;
};


} // end namespace Control_Comonad_Store_Class


