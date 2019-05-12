#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Monad_Cont_Class/Control_Monad_Cont_Class.h"
#include "Control_Monad_Reader_Class/Control_Monad_Reader_Class.h"
#include "Control_Monad_State_Class/Control_Monad_State_Class.h"
#include "Control_Monad_Trans_Class/Control_Monad_Trans_Class.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Effect_Class/Effect_Class.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Cont_Trans/Control_Monad_Cont_Trans.h"


namespace Control_Monad_Cont_Trans {

auto ContT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto withContT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& k) -> boxed {
                return v(f(k));
            };
        };
    };
    return _;
};
auto runContT() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& k) -> boxed {
            return v(k);
        };
    };
    return _;
};
auto newtypeContT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Monad_Cont_Trans::ContT());
};
auto monadTransContT() -> boxed {
    return Control_Monad_Trans_Class::MonadTrans()([=](const boxed& dictMonad) -> boxed {
        return [=](const boxed& m) -> boxed {
            return [=](const boxed& k) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(m)(k);
            };
        };
    });
};
auto mapContT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& k) -> boxed {
                return f(v(k));
            };
        };
    };
    return _;
};
auto functorContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& k) -> boxed {
                    return v([=](const boxed& a) -> boxed {
                        return k(f(a));
                    });
                };
            };
        });
    };
    return _;
};
auto applyContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return Control_Apply::Apply()([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::functorContT()(dictApply["Functor0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return [=](const boxed& k) -> boxed {
                    return v([=](const boxed& g) -> boxed {
                        return v1([=](const boxed& a) -> boxed {
                            return k(g(a));
                        });
                    });
                };
            };
        });
    };
    return _;
};
auto bindContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return Control_Bind::Bind()([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::applyContT()(dictBind["Apply0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& k) -> boxed {
                return [=](const boxed& k_Prime_) -> boxed {
                    return v([=](const boxed& a) -> boxed {
                        boxed v1 = k(a);
                        return v1(k_Prime_);
                    });
                };
            };
        });
    };
    return _;
};
auto applicativeContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::applyContT()(dictApplicative["Apply0"](undefined));
        })([=](const boxed& a) -> boxed {
            return [=](const boxed& k) -> boxed {
                return k(a);
            };
        });
    };
    return _;
};
auto monadContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad::Monad()([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::applicativeContT()(dictMonad["Applicative0"](undefined));
        })([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::bindContT()(dictMonad["Bind1"](undefined));
        });
    };
    return _;
};
auto monadAskContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadAsk) -> boxed {
        return Control_Monad_Reader_Class::MonadAsk()([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::monadContT()(dictMonadAsk["Monad0"](undefined));
        })(Control_Monad_Trans_Class::lift()(Control_Monad_Cont_Trans::monadTransContT())(dictMonadAsk["Monad0"](undefined))(Control_Monad_Reader_Class::ask()(dictMonadAsk)));
    };
    return _;
};
auto monadReaderContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadReader) -> boxed {
        return Control_Monad_Reader_Class::MonadReader()([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::monadAskContT()(dictMonadReader["MonadAsk0"](undefined));
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& k) -> boxed {
                    return Control_Bind::bind()(dictMonadReader["MonadAsk0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Reader_Class::ask()(dictMonadReader["MonadAsk0"](undefined)))([=](const boxed& v1) -> boxed {
                        return Control_Monad_Reader_Class::local()(dictMonadReader)(f)(v(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Reader_Class::local()(dictMonadReader)(Data_Function::_const_()(v1)))(k)));
                    });
                };
            };
        });
    };
    return _;
};
auto monadContContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Cont_Class::MonadCont()([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::monadContT()(dictMonad);
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& k) -> boxed {
                boxed v = f([=](const boxed& a) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        return k(a);
                    };
                });
                return v(k);
            };
        });
    };
    return _;
};
auto monadEffectContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Effect_Class::MonadEffect()([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::monadContT()(dictMonadEffect["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Cont_Trans::monadTransContT())(dictMonadEffect["Monad0"](undefined)))(Effect_Class::liftEffect()(dictMonadEffect)));
    };
    return _;
};
auto monadStateContT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadState) -> boxed {
        return Control_Monad_State_Class::MonadState()([=](const boxed&) -> boxed {
            return Control_Monad_Cont_Trans::monadContT()(dictMonadState["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Cont_Trans::monadTransContT())(dictMonadState["Monad0"](undefined)))(Control_Monad_State_Class::state()(dictMonadState)));
    };
    return _;
};


} // end namespace Control_Monad_Cont_Trans


