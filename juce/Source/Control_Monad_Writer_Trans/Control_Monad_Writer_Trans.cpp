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
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unit/Data_Unit.h"
#include "Effect_Class/Effect_Class.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Writer_Trans/Control_Monad_Writer_Trans.h"


namespace Control_Monad_Writer_Trans {

auto WriterT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto runWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto newtypeWriterT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Monad_Writer_Trans::WriterT());
};
auto monadTransWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return Control_Monad_Trans_Class::MonadTrans()([=](const boxed& dictMonad) -> boxed {
            return [=](const boxed& m) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(m)([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v)(Data_Monoid::mempty()(dictMonoid)));
                });
            };
        });
    };
    return _;
};
auto mapWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v);
        };
    };
    return _;
};
auto functorWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return Control_Monad_Writer_Trans::mapWriterT()(Data_Functor::map()(dictFunctor)([=](const boxed& v) -> boxed {
                return Data_Tuple::Tuple()(f(v["value0"]))(v["value1"]);
            }));
        });
    };
    return _;
};
auto execWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictFunctor)(Data_Tuple::snd())(v);
        };
    };
    return _;
};
auto applyWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& dictApply) -> boxed {
            return Control_Apply::Apply()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::functorWriterT()(dictApply["Functor0"](undefined));
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    boxed k = [=](const boxed& v3) -> boxed {
                        return [=](const boxed& v4) -> boxed {
                            return Data_Tuple::Tuple()(v3["value0"](v4["value0"]))(Data_Semigroup::append()(dictSemigroup)(v3["value1"])(v4["value1"]));
                        };
                    };
                    return Control_Apply::apply()(dictApply)(Data_Functor::map()(dictApply["Functor0"](undefined))(k)(v))(v1);
                };
            });
        };
    };
    return _;
};
auto bindWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& dictBind) -> boxed {
            return Control_Bind::Bind()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::applyWriterT()(dictSemigroup)(dictBind["Apply0"](undefined));
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& k) -> boxed {
                    return Control_Monad_Writer_Trans::WriterT()(Control_Bind::bind()(dictBind)(v)([=](const boxed& v1) -> boxed {
                        boxed v2 = k(v1["value0"]);
                        return Data_Functor::map()(dictBind["Apply0"](undefined)["Functor0"](undefined))([=](const boxed& v3) -> boxed {
                            return Data_Tuple::Tuple()(v3["value0"])(Data_Semigroup::append()(dictSemigroup)(v1["value1"])(v3["value1"]));
                        })(v2);
                    }));
                };
            });
        };
    };
    return _;
};
auto applicativeWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::applyWriterT()(dictMonoid["Semigroup0"](undefined))(dictApplicative["Apply0"](undefined));
            })([=](const boxed& a) -> boxed {
                return Control_Monad_Writer_Trans::WriterT()(Control_Applicative::pure()(dictApplicative)(Data_Tuple::Tuple()(a)(Data_Monoid::mempty()(dictMonoid))));
            });
        };
    };
    return _;
};
auto monadWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_Monad::Monad()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::applicativeWriterT()(dictMonoid)(dictMonad["Applicative0"](undefined));
            })([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::bindWriterT()(dictMonoid["Semigroup0"](undefined))(dictMonad["Bind1"](undefined));
            });
        };
    };
    return _;
};
auto monadAskWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadAsk) -> boxed {
            return Control_Monad_Reader_Class::MonadAsk()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadWriterT()(dictMonoid)(dictMonadAsk["Monad0"](undefined));
            })(Control_Monad_Trans_Class::lift()(Control_Monad_Writer_Trans::monadTransWriterT()(dictMonoid))(dictMonadAsk["Monad0"](undefined))(Control_Monad_Reader_Class::ask()(dictMonadAsk)));
        };
    };
    return _;
};
auto monadReaderWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadReader) -> boxed {
            return Control_Monad_Reader_Class::MonadReader()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadAskWriterT()(dictMonoid)(dictMonadReader["MonadAsk0"](undefined));
            })([=](const boxed& f) -> boxed {
                return Control_Monad_Writer_Trans::mapWriterT()(Control_Monad_Reader_Class::local()(dictMonadReader)(f));
            });
        };
    };
    return _;
};
auto monadContWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadCont) -> boxed {
            return Control_Monad_Cont_Class::MonadCont()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadWriterT()(dictMonoid)(dictMonadCont["Monad0"](undefined));
            })([=](const boxed& f) -> boxed {
                return Control_Monad_Writer_Trans::WriterT()(Control_Monad_Cont_Class::callCC()(dictMonadCont)([=](const boxed& c) -> boxed {
                    boxed v = f([=](const boxed& a) -> boxed {
                        return Control_Monad_Writer_Trans::WriterT()(c(Data_Tuple::Tuple()(a)(Data_Monoid::mempty()(dictMonoid))));
                    });
                    return v;
                }));
            });
        };
    };
    return _;
};
auto monadEffectWriter() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadEffect) -> boxed {
            return Effect_Class::MonadEffect()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadWriterT()(dictMonoid)(dictMonadEffect["Monad0"](undefined));
            })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Writer_Trans::monadTransWriterT()(dictMonoid))(dictMonadEffect["Monad0"](undefined)))(Effect_Class::liftEffect()(dictMonadEffect)));
        };
    };
    return _;
};
auto monadRecWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadRec) -> boxed {
            return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadWriterT()(dictMonoid)(dictMonadRec["Monad0"](undefined));
            })([=](const boxed& f) -> boxed {
                return [=](const boxed& a) -> boxed {
                    boxed f_Prime_ = [=](const boxed& v) -> boxed {
                        return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))([=]() -> boxed {
                            boxed v1 = f(v["value0"]);
                            return v1;
                        }())([=](const boxed& v1) -> boxed {
                            return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))([=]() -> boxed {
                                if (unbox<dict_t>(v1["value0"]).contains("Loop")) {
                                    return Control_Monad_Rec_Class::Loop()(Data_Tuple::Tuple()(v1["value0"]["value0"])(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(v["value1"])(v1["value1"])));
                                };
                                if (unbox<dict_t>(v1["value0"]).contains("Done")) {
                                    return Control_Monad_Rec_Class::Done()(Data_Tuple::Tuple()(v1["value0"]["value0"])(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(v["value1"])(v1["value1"])));
                                };
                                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Writer.Trans (line 83, column 16 - line 85, column 47): ");
                            }());
                        });
                    };
                    return Control_Monad_Writer_Trans::WriterT()(Control_Monad_Rec_Class::tailRecM()(dictMonadRec)(f_Prime_)(Data_Tuple::Tuple()(a)(Data_Monoid::mempty()(dictMonoid))));
                };
            });
        };
    };
    return _;
};
auto monadStateWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadState) -> boxed {
            return Control_Monad_State_Class::MonadState()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadWriterT()(dictMonoid)(dictMonadState["Monad0"](undefined));
            })([=](const boxed& f) -> boxed {
                return Control_Monad_Trans_Class::lift()(Control_Monad_Writer_Trans::monadTransWriterT()(dictMonoid))(dictMonadState["Monad0"](undefined))(Control_Monad_State_Class::state()(dictMonadState)(f));
            });
        };
    };
    return _;
};
auto monadTellWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_Monad_Writer_Class::MonadTell()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadWriterT()(dictMonoid)(dictMonad);
            })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Writer_Trans::WriterT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(dictMonad["Applicative0"](undefined)))(Data_Tuple::Tuple()(Data_Unit::unit()))));
        };
    };
    return _;
};
auto monadWriterWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_Monad_Writer_Class::MonadWriter()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadTellWriterT()(dictMonoid)(dictMonad);
            })([=](const boxed& v) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v)([=](const boxed& v1) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(Data_Tuple::Tuple()(v1["value0"])(v1["value1"]))(v1["value1"]));
                });
            })([=](const boxed& v) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v)([=](const boxed& v1) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v1["value0"]["value0"])(v1["value0"]["value1"](v1["value1"])));
                });
            });
        };
    };
    return _;
};
auto monadThrowWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadThrow) -> boxed {
            return Control_Monad_Error_Class::MonadThrow()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadWriterT()(dictMonoid)(dictMonadThrow["Monad0"](undefined));
            })([=](const boxed& e) -> boxed {
                return Control_Monad_Trans_Class::lift()(Control_Monad_Writer_Trans::monadTransWriterT()(dictMonoid))(dictMonadThrow["Monad0"](undefined))(Control_Monad_Error_Class::throwError()(dictMonadThrow)(e));
            });
        };
    };
    return _;
};
auto monadErrorWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadError) -> boxed {
            return Control_Monad_Error_Class::MonadError()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadThrowWriterT()(dictMonoid)(dictMonadError["MonadThrow0"](undefined));
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& h) -> boxed {
                    return Control_Monad_Writer_Trans::WriterT()(Control_Monad_Error_Class::catchError()(dictMonadError)(v)([=](const boxed& e) -> boxed {
                        boxed v1 = h(e);
                        return v1;
                    }));
                };
            });
        };
    };
    return _;
};
auto altWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlt) -> boxed {
        return Control_Alt::Alt()([=](const boxed&) -> boxed {
            return Control_Monad_Writer_Trans::functorWriterT()(dictAlt["Functor0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Alt::alt()(dictAlt)(v)(v1);
            };
        });
    };
    return _;
};
auto plusWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictPlus) -> boxed {
        return Control_Plus::Plus()([=](const boxed&) -> boxed {
            return Control_Monad_Writer_Trans::altWriterT()(dictPlus["Alt0"](undefined));
        })(Control_Plus::empty()(dictPlus));
    };
    return _;
};
auto alternativeWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictAlternative) -> boxed {
            return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::applicativeWriterT()(dictMonoid)(dictAlternative["Applicative0"](undefined));
            })([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::plusWriterT()(dictAlternative["Plus1"](undefined));
            });
        };
    };
    return _;
};
auto monadZeroWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadZero) -> boxed {
            return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::alternativeWriterT()(dictMonoid)(dictMonadZero["Alternative1"](undefined));
            })([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadWriterT()(dictMonoid)(dictMonadZero["Monad0"](undefined));
            });
        };
    };
    return _;
};
auto monadPlusWriterT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadPlus) -> boxed {
            return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
                return Control_Monad_Writer_Trans::monadZeroWriterT()(dictMonoid)(dictMonadPlus["MonadZero0"](undefined));
            });
        };
    };
    return _;
};


} // end namespace Control_Monad_Writer_Trans


