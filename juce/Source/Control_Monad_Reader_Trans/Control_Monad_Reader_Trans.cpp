#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Monad_Cont_Class/Control_Monad_Cont_Class.h"
#include "Control_Monad_Error_Class/Control_Monad_Error_Class.h"
#include "Control_Monad_Reader_Class/Control_Monad_Reader_Class.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Control_Monad_State_Class/Control_Monad_State_Class.h"
#include "Control_Monad_Trans_Class/Control_Monad_Trans_Class.h"
#include "Control_Monad_Writer_Class/Control_Monad_Writer_Class.h"
#include "Control_MonadPlus/Control_MonadPlus.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Control_Plus/Control_Plus.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Distributive/Data_Distributive.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Effect_Class/Effect_Class.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Reader_Trans/Control_Monad_Reader_Trans.h"


namespace Control_Monad_Reader_Trans {

auto ReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto withReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(v)(f);
        };
    };
    return _;
};
auto runReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto newtypeReaderT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Monad_Reader_Trans::ReaderT());
};
auto monadTransReaderT() -> boxed {
    return Control_Monad_Trans_Class::MonadTrans()([=](const boxed& dictMonad) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Reader_Trans::ReaderT())(Data_Function::_const_());
    });
};
auto mapReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(v);
        };
    };
    return _;
};
auto functorReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Reader_Trans::mapReaderT())(Data_Functor::map()(dictFunctor)));
    };
    return _;
};
auto distributiveReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictDistributive) -> boxed {
        return Data_Distributive::Distributive()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::functorReaderT()(dictDistributive["Functor0"](undefined));
        })([=](const boxed& dictFunctor) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Distributive::distribute()(Control_Monad_Reader_Trans::distributiveReaderT()(dictDistributive))(dictFunctor))(Data_Functor::map()(dictFunctor)(f));
            };
        })([=](const boxed& dictFunctor) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& e) -> boxed {
                    return Data_Distributive::collect()(dictDistributive)(dictFunctor)([=](const boxed& r) -> boxed {
                        return r(e);
                    })(a);
                };
            };
        });
    };
    return _;
};
auto applyReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return Control_Apply::Apply()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::functorReaderT()(dictApply["Functor0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return Control_Apply::apply()(dictApply)(v(r))(v1(r));
                };
            };
        });
    };
    return _;
};
auto bindReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return Control_Bind::Bind()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::applyReaderT()(dictBind["Apply0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& k) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return Control_Bind::bind()(dictBind)(v(r))([=](const boxed& a) -> boxed {
                        boxed v1 = k(a);
                        return v1(r);
                    });
                };
            };
        });
    };
    return _;
};
auto semigroupReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return [=](const boxed& dictSemigroup) -> boxed {
            return Data_Semigroup::Semigroup()(Control_Apply::lift2()(Control_Monad_Reader_Trans::applyReaderT()(dictApply))(Data_Semigroup::append()(dictSemigroup)));
        };
    };
    return _;
};
auto applicativeReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::applyReaderT()(dictApplicative["Apply0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Reader_Trans::ReaderT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Function::_const_())(Control_Applicative::pure()(dictApplicative))));
    };
    return _;
};
auto monadReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad::Monad()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::applicativeReaderT()(dictMonad["Applicative0"](undefined));
        })([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::bindReaderT()(dictMonad["Bind1"](undefined));
        });
    };
    return _;
};
auto monadAskReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Reader_Class::MonadAsk()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadReaderT()(dictMonad);
        })(Control_Applicative::pure()(dictMonad["Applicative0"](undefined)));
    };
    return _;
};
auto monadReaderReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Reader_Class::MonadReader()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadAskReaderT()(dictMonad);
        })(Control_Monad_Reader_Trans::withReaderT());
    };
    return _;
};
auto monadContReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadCont) -> boxed {
        return Control_Monad_Cont_Class::MonadCont()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadReaderT()(dictMonadCont["Monad0"](undefined));
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& r) -> boxed {
                return Control_Monad_Cont_Class::callCC()(dictMonadCont)([=](const boxed& c) -> boxed {
                    boxed v = f(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Reader_Trans::ReaderT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Function::_const_())(c)));
                    return v(r);
                });
            };
        });
    };
    return _;
};
auto monadEffectReader() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Effect_Class::MonadEffect()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadReaderT()(dictMonadEffect["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Reader_Trans::monadTransReaderT())(dictMonadEffect["Monad0"](undefined)))(Effect_Class::liftEffect()(dictMonadEffect)));
    };
    return _;
};
auto monadRecReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadReaderT()(dictMonadRec["Monad0"](undefined));
        })([=](const boxed& k) -> boxed {
            return [=](const boxed& a) -> boxed {
                boxed k_Prime_ = [=](const boxed& r) -> boxed {
                    return [=](const boxed& a_Prime_) -> boxed {
                        boxed v = k(a_Prime_);
                        return Control_Bind::bindFlipped()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))(Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined)))(v(r));
                    };
                };
                return [=](const boxed& r) -> boxed {
                    return Control_Monad_Rec_Class::tailRecM()(dictMonadRec)(k_Prime_(r))(a);
                };
            };
        });
    };
    return _;
};
auto monadStateReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadState) -> boxed {
        return Control_Monad_State_Class::MonadState()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadReaderT()(dictMonadState["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Reader_Trans::monadTransReaderT())(dictMonadState["Monad0"](undefined)))(Control_Monad_State_Class::state()(dictMonadState)));
    };
    return _;
};
auto monadTellReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadTell) -> boxed {
        return Control_Monad_Writer_Class::MonadTell()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadReaderT()(dictMonadTell["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Reader_Trans::monadTransReaderT())(dictMonadTell["Monad0"](undefined)))(Control_Monad_Writer_Class::tell()(dictMonadTell)));
    };
    return _;
};
auto monadWriterReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadWriter) -> boxed {
        return Control_Monad_Writer_Class::MonadWriter()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadTellReaderT()(dictMonadWriter["MonadTell0"](undefined));
        })(Control_Monad_Reader_Trans::mapReaderT()(Control_Monad_Writer_Class::listen()(dictMonadWriter)))(Control_Monad_Reader_Trans::mapReaderT()(Control_Monad_Writer_Class::pass()(dictMonadWriter)));
    };
    return _;
};
auto monadThrowReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadThrow) -> boxed {
        return Control_Monad_Error_Class::MonadThrow()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadReaderT()(dictMonadThrow["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Reader_Trans::monadTransReaderT())(dictMonadThrow["Monad0"](undefined)))(Control_Monad_Error_Class::throwError()(dictMonadThrow)));
    };
    return _;
};
auto monadErrorReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadError) -> boxed {
        return Control_Monad_Error_Class::MonadError()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadThrowReaderT()(dictMonadError["MonadThrow0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& h) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return Control_Monad_Error_Class::catchError()(dictMonadError)(v(r))([=](const boxed& e) -> boxed {
                        boxed v1 = h(e);
                        return v1(r);
                    });
                };
            };
        });
    };
    return _;
};
auto monoidReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
                return Control_Monad_Reader_Trans::semigroupReaderT()(dictApplicative["Apply0"](undefined))(dictMonoid["Semigroup0"](undefined));
            })(Control_Applicative::pure()(Control_Monad_Reader_Trans::applicativeReaderT()(dictApplicative))(Data_Monoid::mempty()(dictMonoid)));
        };
    };
    return _;
};
auto altReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlt) -> boxed {
        return Control_Alt::Alt()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::functorReaderT()(dictAlt["Functor0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return Control_Alt::alt()(dictAlt)(v(r))(v1(r));
                };
            };
        });
    };
    return _;
};
auto plusReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictPlus) -> boxed {
        return Control_Plus::Plus()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::altReaderT()(dictPlus["Alt0"](undefined));
        })(Data_Function::_const_()(Control_Plus::empty()(dictPlus)));
    };
    return _;
};
auto alternativeReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlternative) -> boxed {
        return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::applicativeReaderT()(dictAlternative["Applicative0"](undefined));
        })([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::plusReaderT()(dictAlternative["Plus1"](undefined));
        });
    };
    return _;
};
auto monadZeroReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadZero) -> boxed {
        return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::alternativeReaderT()(dictMonadZero["Alternative1"](undefined));
        })([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadReaderT()(dictMonadZero["Monad0"](undefined));
        });
    };
    return _;
};
auto monadPlusReaderT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadPlus) -> boxed {
        return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
            return Control_Monad_Reader_Trans::monadZeroReaderT()(dictMonadPlus["MonadZero0"](undefined));
        });
    };
    return _;
};


} // end namespace Control_Monad_Reader_Trans


