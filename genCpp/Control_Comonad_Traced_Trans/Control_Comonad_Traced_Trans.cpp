#include "Control_Comonad/Control_Comonad.h"
#include "Control_Comonad_Trans_Class/Control_Comonad_Trans_Class.h"
#include "Control_Extend/Control_Extend.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Prelude/Prelude.h"

#include "Control_Comonad_Traced_Trans/Control_Comonad_Traced_Trans.h"


namespace Control_Comonad_Traced_Trans {

auto TracedT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto runTracedT() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto newtypeTracedT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Comonad_Traced_Trans::TracedT());
};
auto functorTracedT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictFunctor)([=](const boxed& g) -> boxed {
                    return [=](const boxed& t) -> boxed {
                        return f(g(t));
                    };
                })(v);
            };
        });
    };
    return _;
};
auto extendTracedT() -> const boxed& {
    static const boxed _ = [](const boxed& dictExtend) -> boxed {
        return [=](const boxed& dictSemigroup) -> boxed {
            return Control_Extend::Extend()([=](const boxed&) -> boxed {
                return Control_Comonad_Traced_Trans::functorTracedT()(dictExtend["Functor0"](undefined));
            })([=](const boxed& f) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Control_Extend::extend()(dictExtend)([=](const boxed& w_Prime_) -> boxed {
                        return [=](const boxed& t) -> boxed {
                            return f(Data_Functor::map()(dictExtend["Functor0"](undefined))([=](const boxed& h) -> boxed {
                                return [=](const boxed& t_Prime_) -> boxed {
                                    return h(Data_Semigroup::append()(dictSemigroup)(t)(t_Prime_));
                                };
                            })(w_Prime_));
                        };
                    })(v);
                };
            });
        };
    };
    return _;
};
auto comonadTransTracedT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return Control_Comonad_Trans_Class::ComonadTrans()([=](const boxed& dictComonad) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictComonad["Extend0"](undefined)["Functor0"](undefined))([=](const boxed& f) -> boxed {
                    return f(Data_Monoid::mempty()(dictMonoid));
                })(v);
            };
        });
    };
    return _;
};
auto comonadTracedT() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Comonad::Comonad()([=](const boxed&) -> boxed {
                return Control_Comonad_Traced_Trans::extendTracedT()(dictComonad["Extend0"](undefined))(dictMonoid["Semigroup0"](undefined));
            })([=](const boxed& v) -> boxed {
                return Control_Comonad::extract()(dictComonad)(v)(Data_Monoid::mempty()(dictMonoid));
            });
        };
    };
    return _;
};


} // end namespace Control_Comonad_Traced_Trans


