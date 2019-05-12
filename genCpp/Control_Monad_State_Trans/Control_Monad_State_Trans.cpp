#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Lazy/Control_Lazy.h"
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
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unit/Data_Unit.h"
#include "Effect_Class/Effect_Class.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_State_Trans/Control_Monad_State_Trans.h"


namespace Control_Monad_State_Trans {

auto StateT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto withStateT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(v)(f);
        };
    };
    return _;
};
auto runStateT() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto newtypeStateT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Monad_State_Trans::StateT());
};
auto monadTransStateT() -> boxed {
    return Control_Monad_Trans_Class::MonadTrans()([=](const boxed& dictMonad) -> boxed {
        return [=](const boxed& m) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(m)([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v)(s));
                });
            };
        };
    });
};
auto mapStateT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(v);
        };
    };
    return _;
};
auto lazyStateT() -> boxed {
    return Control_Lazy::Lazy()([=](const boxed& f) -> boxed {
        return [=](const boxed& s) -> boxed {
            boxed v = f(Data_Unit::unit());
            return v(s);
        };
    });
};
auto functorStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& s) -> boxed {
                    return Data_Functor::map()(dictFunctor)([=](const boxed& v1) -> boxed {
                        return Data_Tuple::Tuple()(f(v1["value0"]))(v1["value1"]);
                    })(v(s));
                };
            };
        });
    };
    return _;
};
auto execStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Data_Functor::map()(dictFunctor)(Data_Tuple::snd())(v(s));
            };
        };
    };
    return _;
};
auto evalStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Data_Functor::map()(dictFunctor)(Data_Tuple::fst())(v(s));
            };
        };
    };
    return _;
};
auto monadStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad::Monad()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::applicativeStateT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::bindStateT()(dictMonad);
        });
    };
    return _;
};
auto bindStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Bind::Bind()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::applyStateT()(dictMonad);
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& s) -> boxed {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v(s))([=](const boxed& v1) -> boxed {
                        boxed v3 = f(v1["value0"]);
                        return v3(v1["value1"]);
                    });
                };
            };
        });
    };
    return _;
};
auto applyStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Apply::Apply()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::functorStateT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined));
        })(Control_Monad::ap()(Control_Monad_State_Trans::monadStateT()(dictMonad)));
    };
    return _;
};
auto applicativeStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::applyStateT()(dictMonad);
        })([=](const boxed& a) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(a)(s));
            };
        });
    };
    return _;
};
auto monadAskStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadAsk) -> boxed {
        return Control_Monad_Reader_Class::MonadAsk()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadStateT()(dictMonadAsk["Monad0"](undefined));
        })(Control_Monad_Trans_Class::lift()(Control_Monad_State_Trans::monadTransStateT())(dictMonadAsk["Monad0"](undefined))(Control_Monad_Reader_Class::ask()(dictMonadAsk)));
    };
    return _;
};
auto monadReaderStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadReader) -> boxed {
        return Control_Monad_Reader_Class::MonadReader()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadAskStateT()(dictMonadReader["MonadAsk0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_State_Trans::mapStateT())(Control_Monad_Reader_Class::local()(dictMonadReader)));
    };
    return _;
};
auto monadContStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadCont) -> boxed {
        return Control_Monad_Cont_Class::MonadCont()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadStateT()(dictMonadCont["Monad0"](undefined));
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Control_Monad_Cont_Class::callCC()(dictMonadCont)([=](const boxed& c) -> boxed {
                    boxed v = f([=](const boxed& a) -> boxed {
                        return [=](const boxed& s_Prime_) -> boxed {
                            return c(Data_Tuple::Tuple()(a)(s_Prime_));
                        };
                    });
                    return v(s);
                });
            };
        });
    };
    return _;
};
auto monadEffectState() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Effect_Class::MonadEffect()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadStateT()(dictMonadEffect["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_State_Trans::monadTransStateT())(dictMonadEffect["Monad0"](undefined)))(Effect_Class::liftEffect()(dictMonadEffect)));
    };
    return _;
};
auto monadRecStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadStateT()(dictMonadRec["Monad0"](undefined));
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                boxed f_Prime_ = [=](const boxed& v) -> boxed {
                    return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))([=]() -> boxed {
                        boxed v1 = f(v["value0"]);
                        return v1;
                    }()(v["value1"]))([=](const boxed& v1) -> boxed {
                        return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))([=]() -> boxed {
                            if (unbox<dict_t>(v1["value0"]).contains("Loop")) {
                                return Control_Monad_Rec_Class::Loop()(Data_Tuple::Tuple()(v1["value0"]["value0"])(v1["value1"]));
                            };
                            if (unbox<dict_t>(v1["value0"]).contains("Done")) {
                                return Control_Monad_Rec_Class::Done()(Data_Tuple::Tuple()(v1["value0"]["value0"])(v1["value1"]));
                            };
                            THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.State.Trans (line 87, column 16 - line 89, column 40): ");
                        }());
                    });
                };
                return [=](const boxed& s) -> boxed {
                    return Control_Monad_Rec_Class::tailRecM()(dictMonadRec)(f_Prime_)(Data_Tuple::Tuple()(a)(s));
                };
            };
        });
    };
    return _;
};
auto monadStateStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_State_Class::MonadState()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadStateT()(dictMonad);
        })([=](const boxed& f) -> boxed {
            return Control_Monad_State_Trans::StateT()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(dictMonad["Applicative0"](undefined)))(f));
        });
    };
    return _;
};
auto monadTellStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadTell) -> boxed {
        return Control_Monad_Writer_Class::MonadTell()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadStateT()(dictMonadTell["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_State_Trans::monadTransStateT())(dictMonadTell["Monad0"](undefined)))(Control_Monad_Writer_Class::tell()(dictMonadTell)));
    };
    return _;
};
auto monadWriterStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadWriter) -> boxed {
        return Control_Monad_Writer_Class::MonadWriter()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadTellStateT()(dictMonadWriter["MonadTell0"](undefined));
        })([=](const boxed& m) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Control_Bind::bind()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Writer_Class::listen()(dictMonadWriter)(m(s)))([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Applicative0"](undefined))(Data_Tuple::Tuple()(Data_Tuple::Tuple()(v["value0"]["value0"])(v["value1"]))(v["value0"]["value1"]));
                });
            };
        })([=](const boxed& m) -> boxed {
            return [=](const boxed& s) -> boxed {
                return Control_Monad_Writer_Class::pass()(dictMonadWriter)(Control_Bind::bind()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(m(s))([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Applicative0"](undefined))(Data_Tuple::Tuple()(Data_Tuple::Tuple()(v["value0"]["value0"])(v["value1"]))(v["value0"]["value1"]));
                }));
            };
        });
    };
    return _;
};
auto monadThrowStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadThrow) -> boxed {
        return Control_Monad_Error_Class::MonadThrow()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadStateT()(dictMonadThrow["Monad0"](undefined));
        })([=](const boxed& e) -> boxed {
            return Control_Monad_Trans_Class::lift()(Control_Monad_State_Trans::monadTransStateT())(dictMonadThrow["Monad0"](undefined))(Control_Monad_Error_Class::throwError()(dictMonadThrow)(e));
        });
    };
    return _;
};
auto monadErrorStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadError) -> boxed {
        return Control_Monad_Error_Class::MonadError()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadThrowStateT()(dictMonadError["MonadThrow0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& h) -> boxed {
                return [=](const boxed& s) -> boxed {
                    return Control_Monad_Error_Class::catchError()(dictMonadError)(v(s))([=](const boxed& e) -> boxed {
                        boxed v1 = h(e);
                        return v1(s);
                    });
                };
            };
        });
    };
    return _;
};
auto altStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictAlt) -> boxed {
            return Control_Alt::Alt()([=](const boxed&) -> boxed {
                return Control_Monad_State_Trans::functorStateT()(dictAlt["Functor0"](undefined));
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return [=](const boxed& s) -> boxed {
                        return Control_Alt::alt()(dictAlt)(v(s))(v1(s));
                    };
                };
            });
        };
    };
    return _;
};
auto plusStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictPlus) -> boxed {
            return Control_Plus::Plus()([=](const boxed&) -> boxed {
                return Control_Monad_State_Trans::altStateT()(dictMonad)(dictPlus["Alt0"](undefined));
            })([=](const boxed& v) -> boxed {
                return Control_Plus::empty()(dictPlus);
            });
        };
    };
    return _;
};
auto alternativeStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictAlternative) -> boxed {
            return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
                return Control_Monad_State_Trans::applicativeStateT()(dictMonad);
            })([=](const boxed&) -> boxed {
                return Control_Monad_State_Trans::plusStateT()(dictMonad)(dictAlternative["Plus1"](undefined));
            });
        };
    };
    return _;
};
auto monadZeroStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadZero) -> boxed {
        return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::alternativeStateT()(dictMonadZero["Monad0"](undefined))(dictMonadZero["Alternative1"](undefined));
        })([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadStateT()(dictMonadZero["Monad0"](undefined));
        });
    };
    return _;
};
auto monadPlusStateT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadPlus) -> boxed {
        return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
            return Control_Monad_State_Trans::monadZeroStateT()(dictMonadPlus["MonadZero0"](undefined));
        });
    };
    return _;
};


} // end namespace Control_Monad_State_Trans


