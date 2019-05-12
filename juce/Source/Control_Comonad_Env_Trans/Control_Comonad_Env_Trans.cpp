#include "Control_Comonad/Control_Comonad.h"
#include "Control_Comonad_Trans_Class/Control_Comonad_Trans_Class.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Comonad_Env_Trans/Control_Comonad_Env_Trans.h"


namespace Control_Comonad_Env_Trans {

auto EnvT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto withEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Comonad_Env_Trans::EnvT()(Data_Tuple::Tuple()(f(v["value0"]))(v["value1"]));
        };
    };
    return _;
};
auto runEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto newtypeEnvT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Comonad_Env_Trans::EnvT());
};
auto mapEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Comonad_Env_Trans::EnvT()(Data_Tuple::Tuple()(v["value0"])(f(v["value1"])));
        };
    };
    return _;
};
auto functorEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Comonad_Env_Trans::EnvT()(Data_Tuple::Tuple()(v["value0"])(Data_Functor::map()(dictFunctor)(f)(v["value1"])));
            };
        });
    };
    return _;
};
auto foldableEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& fn) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Foldable::foldMap()(dictFoldable)(dictMonoid)(fn)(v["value1"]);
                };
            };
        })([=](const boxed& fn) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Foldable::foldl()(dictFoldable)(fn)(a)(v["value1"]);
                };
            };
        })([=](const boxed& fn) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Foldable::foldr()(dictFoldable)(fn)(a)(v["value1"]);
                };
            };
        });
    };
    return _;
};
auto traversableEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
            return Control_Comonad_Env_Trans::foldableEnvT()(dictTraversable["Foldable1"](undefined));
        })([=](const boxed&) -> boxed {
            return Control_Comonad_Env_Trans::functorEnvT()(dictTraversable["Functor0"](undefined));
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Functor::map()(Data_Functor::functorFn())(Control_Comonad_Env_Trans::EnvT())(Data_Tuple::Tuple()(v["value0"])))(Data_Traversable::sequence()(dictTraversable)(dictApplicative)(v["value1"]));
            };
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Functor::map()(Data_Functor::functorFn())(Control_Comonad_Env_Trans::EnvT())(Data_Tuple::Tuple()(v["value0"])))(Data_Traversable::traverse()(dictTraversable)(dictApplicative)(f)(v["value1"]));
                };
            };
        });
    };
    return _;
};
auto extendEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& dictExtend) -> boxed {
        return Control_Extend::Extend()([=](const boxed&) -> boxed {
            return Control_Comonad_Env_Trans::functorEnvT()(dictExtend["Functor0"](undefined));
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Comonad_Env_Trans::EnvT()(Data_Tuple::Tuple()(v["value0"])(Data_Functor::map()(dictExtend["Functor0"](undefined))(f)(Control_Extend::extend()(dictExtend)(Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(Data_Tuple::Tuple()(v["value0"]))(Control_Comonad_Env_Trans::EnvT()))(v["value1"]))));
            };
        });
    };
    return _;
};
auto comonadTransEnvT() -> boxed {
    return Control_Comonad_Trans_Class::ComonadTrans()([=](const boxed& dictComonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            return v["value1"];
        };
    });
};
auto comonadEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonad) -> boxed {
        return Control_Comonad::Comonad()([=](const boxed&) -> boxed {
            return Control_Comonad_Env_Trans::extendEnvT()(dictComonad["Extend0"](undefined));
        })([=](const boxed& v) -> boxed {
            return Control_Comonad::extract()(dictComonad)(v["value1"]);
        });
    };
    return _;
};


} // end namespace Control_Comonad_Env_Trans


