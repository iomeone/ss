#include "Control_Comonad/Control_Comonad.h"
#include "Control_Comonad_Traced_Trans/Control_Comonad_Traced_Trans.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Comonad_Traced_Class/Control_Comonad_Traced_Class.h"


namespace Control_Comonad_Traced_Class {

auto ComonadTraced() -> const boxed& {
    static const boxed _ = [](const boxed& Comonad0) -> boxed {
        return [=](const boxed& track) -> boxed {
            return dict_t{
                { "Comonad0", Comonad0 },
                { "track", track }
            };
        };
    };
    return _;
};
auto track() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["track"];
    };
    return _;
};
auto tracks() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonadTraced) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& w) -> boxed {
                return Control_Comonad_Traced_Class::track()(dictComonadTraced)(f(Control_Comonad::extract()(dictComonadTraced["Comonad0"](undefined))(w)))(w);
            };
        };
    };
    return _;
};
auto listens() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictFunctor)([=](const boxed& g) -> boxed {
                    return [=](const boxed& t) -> boxed {
                        return Data_Tuple::Tuple()(g(t))(f(t));
                    };
                })(v);
            };
        };
    };
    return _;
};
auto listen() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictFunctor)([=](const boxed& f) -> boxed {
                return [=](const boxed& t) -> boxed {
                    return Data_Tuple::Tuple()(f(t))(t);
                };
            })(v);
        };
    };
    return _;
};
auto comonadTracedTracedT() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Comonad_Traced_Class::ComonadTraced()([=](const boxed&) -> boxed {
                return Control_Comonad_Traced_Trans::comonadTracedT()(dictComonad)(dictMonoid);
            })([=](const boxed& t) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Control_Comonad::extract()(dictComonad)(v)(t);
                };
            });
        };
    };
    return _;
};
auto censor() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictFunctor)([=](const boxed& v1) -> boxed {
                    return Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(f)(v1);
                })(v);
            };
        };
    };
    return _;
};


} // end namespace Control_Comonad_Traced_Class


