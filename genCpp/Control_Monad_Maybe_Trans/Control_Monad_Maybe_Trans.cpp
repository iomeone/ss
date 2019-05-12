#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
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
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Effect_Class/Effect_Class.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Maybe_Trans/Control_Monad_Maybe_Trans.h"


namespace Control_Monad_Maybe_Trans {

auto MaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto runMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto newtypeMaybeT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Monad_Maybe_Trans::MaybeT());
};
auto monadTransMaybeT() -> boxed {
    return Control_Monad_Trans_Class::MonadTrans()([=](const boxed& dictMonad) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Maybe_Trans::MaybeT())(Control_Monad::liftM1()(dictMonad)(Data_Maybe::Just()));
    });
};
auto mapMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v);
        };
    };
    return _;
};
auto functorMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictFunctor)(Data_Functor::map()(Data_Maybe::functorMaybe())(f))(v);
            };
        });
    };
    return _;
};
auto monadMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad::Monad()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::applicativeMaybeT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::bindMaybeT()(dictMonad);
        });
    };
    return _;
};
auto bindMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Bind::Bind()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::applyMaybeT()(dictMonad);
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v)([=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1).contains("Nothing")) {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Maybe::Nothing());
                    };
                    if (unbox<dict_t>(v1).contains("Just")) {
                        boxed v2 = f(v1["value0"]);
                        return v2;
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Maybe.Trans (line 54, column 11 - line 56, column 42): ");
                });
            };
        });
    };
    return _;
};
auto applyMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Apply::Apply()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::functorMaybeT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined));
        })(Control_Monad::ap()(Control_Monad_Maybe_Trans::monadMaybeT()(dictMonad)));
    };
    return _;
};
auto applicativeMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::applyMaybeT()(dictMonad);
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Maybe_Trans::MaybeT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(dictMonad["Applicative0"](undefined)))(Data_Maybe::Just())));
    };
    return _;
};
auto monadAskMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadAsk) -> boxed {
        return Control_Monad_Reader_Class::MonadAsk()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadMaybeT()(dictMonadAsk["Monad0"](undefined));
        })(Control_Monad_Trans_Class::lift()(Control_Monad_Maybe_Trans::monadTransMaybeT())(dictMonadAsk["Monad0"](undefined))(Control_Monad_Reader_Class::ask()(dictMonadAsk)));
    };
    return _;
};
auto monadReaderMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadReader) -> boxed {
        return Control_Monad_Reader_Class::MonadReader()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadAskMaybeT()(dictMonadReader["MonadAsk0"](undefined));
        })([=](const boxed& f) -> boxed {
            return Control_Monad_Maybe_Trans::mapMaybeT()(Control_Monad_Reader_Class::local()(dictMonadReader)(f));
        });
    };
    return _;
};
auto monadContMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadCont) -> boxed {
        return Control_Monad_Cont_Class::MonadCont()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadMaybeT()(dictMonadCont["Monad0"](undefined));
        })([=](const boxed& f) -> boxed {
            return Control_Monad_Maybe_Trans::MaybeT()(Control_Monad_Cont_Class::callCC()(dictMonadCont)([=](const boxed& c) -> boxed {
                boxed v = f([=](const boxed& a) -> boxed {
                    return Control_Monad_Maybe_Trans::MaybeT()(c(Data_Maybe::Just()(a)));
                });
                return v;
            }));
        });
    };
    return _;
};
auto monadEffectMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Effect_Class::MonadEffect()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadMaybeT()(dictMonadEffect["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Maybe_Trans::monadTransMaybeT())(dictMonadEffect["Monad0"](undefined)))(Effect_Class::liftEffect()(dictMonadEffect)));
    };
    return _;
};
auto monadRecMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadMaybeT()(dictMonadRec["Monad0"](undefined));
        })([=](const boxed& f) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Maybe_Trans::MaybeT())(Control_Monad_Rec_Class::tailRecM()(dictMonadRec)([=](const boxed& a) -> boxed {
                return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))([=]() -> boxed {
                    boxed v = f(a);
                    return v;
                }())([=](const boxed& m_Prime_) -> boxed {
                    return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))([=]() -> boxed {
                        if (unbox<dict_t>(m_Prime_).contains("Nothing")) {
                            return Control_Monad_Rec_Class::Done()(Data_Maybe::Nothing());
                        };
                        if (unbox<dict_t>(m_Prime_).contains("Just")) {
                            if (unbox<dict_t>(m_Prime_["value0"]).contains("Loop")) {
                                return Control_Monad_Rec_Class::Loop()(m_Prime_["value0"]["value0"]);
                            };
                        };
                        if (unbox<dict_t>(m_Prime_).contains("Just")) {
                            if (unbox<dict_t>(m_Prime_["value0"]).contains("Done")) {
                                return Control_Monad_Rec_Class::Done()(Data_Maybe::Just()(m_Prime_["value0"]["value0"]));
                            };
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Maybe.Trans (line 84, column 16 - line 87, column 43): ");
                    }());
                });
            }));
        });
    };
    return _;
};
auto monadStateMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadState) -> boxed {
        return Control_Monad_State_Class::MonadState()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadMaybeT()(dictMonadState["Monad0"](undefined));
        })([=](const boxed& f) -> boxed {
            return Control_Monad_Trans_Class::lift()(Control_Monad_Maybe_Trans::monadTransMaybeT())(dictMonadState["Monad0"](undefined))(Control_Monad_State_Class::state()(dictMonadState)(f));
        });
    };
    return _;
};
auto monadTellMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadTell) -> boxed {
        return Control_Monad_Writer_Class::MonadTell()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadMaybeT()(dictMonadTell["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Maybe_Trans::monadTransMaybeT())(dictMonadTell["Monad0"](undefined)))(Control_Monad_Writer_Class::tell()(dictMonadTell)));
    };
    return _;
};
auto monadWriterMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadWriter) -> boxed {
        return Control_Monad_Writer_Class::MonadWriter()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadTellMaybeT()(dictMonadWriter["MonadTell0"](undefined));
        })(Control_Monad_Maybe_Trans::mapMaybeT()([=](const boxed& m) -> boxed {
            return Control_Bind::bind()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Writer_Class::listen()(dictMonadWriter)(m))([=](const boxed& v) -> boxed {
                return Control_Applicative::pure()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Applicative0"](undefined))(Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& r) -> boxed {
                    return Data_Tuple::Tuple()(r)(v["value1"]);
                })(v["value0"]));
            });
        }))(Control_Monad_Maybe_Trans::mapMaybeT()([=](const boxed& m) -> boxed {
            return Control_Monad_Writer_Class::pass()(dictMonadWriter)(Control_Bind::bind()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(m)([=](const boxed& v) -> boxed {
                return Control_Applicative::pure()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Applicative0"](undefined))([=]() -> boxed {
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Data_Tuple::Tuple()(Data_Maybe::Nothing())(Control_Category::identity()(Control_Category::categoryFn()));
                    };
                    if (unbox<dict_t>(v).contains("Just")) {
                        return Data_Tuple::Tuple()(Data_Maybe::Just()(v["value0"]["value0"]))(v["value0"]["value1"]);
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Maybe.Trans (line 121, column 10 - line 123, column 42): ");
                }());
            }));
        }));
    };
    return _;
};
auto monadThrowMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadThrow) -> boxed {
        return Control_Monad_Error_Class::MonadThrow()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadMaybeT()(dictMonadThrow["Monad0"](undefined));
        })([=](const boxed& e) -> boxed {
            return Control_Monad_Trans_Class::lift()(Control_Monad_Maybe_Trans::monadTransMaybeT())(dictMonadThrow["Monad0"](undefined))(Control_Monad_Error_Class::throwError()(dictMonadThrow)(e));
        });
    };
    return _;
};
auto monadErrorMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadError) -> boxed {
        return Control_Monad_Error_Class::MonadError()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadThrowMaybeT()(dictMonadError["MonadThrow0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& h) -> boxed {
                return Control_Monad_Maybe_Trans::MaybeT()(Control_Monad_Error_Class::catchError()(dictMonadError)(v)([=](const boxed& a) -> boxed {
                    boxed v1 = h(a);
                    return v1;
                }));
            };
        });
    };
    return _;
};
auto altMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Alt::Alt()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::functorMaybeT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v)([=](const boxed& v2) -> boxed {
                    if (unbox<dict_t>(v2).contains("Nothing")) {
                        return v1;
                    };
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(v2);
                });
            };
        });
    };
    return _;
};
auto plusMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Plus::Plus()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::altMaybeT()(dictMonad);
        })(Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Maybe::Nothing()));
    };
    return _;
};
auto alternativeMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::applicativeMaybeT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::plusMaybeT()(dictMonad);
        });
    };
    return _;
};
auto monadZeroMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::alternativeMaybeT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadMaybeT()(dictMonad);
        });
    };
    return _;
};
auto monadPlusMaybeT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
            return Control_Monad_Maybe_Trans::monadZeroMaybeT()(dictMonad);
        });
    };
    return _;
};


} // end namespace Control_Monad_Maybe_Trans


