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
#include "Data_Either/Data_Either.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Effect_Class/Effect_Class.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Except_Trans/Control_Monad_Except_Trans.h"


namespace Control_Monad_Except_Trans {

auto ExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto withExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                boxed mapLeft = [=](const boxed& v1) -> boxed {
                    return [=](const boxed& v2) -> boxed {
                        if (unbox<dict_t>(v2).contains("Right")) {
                            return Data_Either::Right()(v2["value0"]);
                        };
                        if (unbox<dict_t>(v2).contains("Left")) {
                            return Data_Either::Left()(v1(v2["value0"]));
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Except.Trans (line 42, column 3 - line 42, column 32): ");
                    };
                };
                return Control_Monad_Except_Trans::ExceptT()(Data_Functor::map()(dictFunctor)(mapLeft(f))(v));
            };
        };
    };
    return _;
};
auto runExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto newtypeExceptT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Monad_Except_Trans::ExceptT());
};
auto monadTransExceptT() -> boxed {
    return Control_Monad_Trans_Class::MonadTrans()([=](const boxed& dictMonad) -> boxed {
        return [=](const boxed& m) -> boxed {
            return Control_Bind::bind()(dictMonad["Bind1"](undefined))(m)([=](const boxed& v) -> boxed {
                return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Either::Right()(v));
            });
        };
    });
};
auto mapExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v);
        };
    };
    return _;
};
auto functorExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return Control_Monad_Except_Trans::mapExceptT()(Data_Functor::map()(dictFunctor)(Data_Functor::map()(Data_Either::functorEither())(f)));
        });
    };
    return _;
};
auto except() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::ExceptT())(Control_Applicative::pure()(dictApplicative));
    };
    return _;
};
auto monadExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad::Monad()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::applicativeExceptT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::bindExceptT()(dictMonad);
        });
    };
    return _;
};
auto bindExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Bind::Bind()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::applyExceptT()(dictMonad);
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& k) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v)(Data_Either::either()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(dictMonad["Applicative0"](undefined)))(Data_Either::Left()))([=](const boxed& a) -> boxed {
                    boxed v1 = k(a);
                    return v1;
                }));
            };
        });
    };
    return _;
};
auto applyExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Apply::Apply()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::functorExceptT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined));
        })(Control_Monad::ap()(Control_Monad_Except_Trans::monadExceptT()(dictMonad)));
    };
    return _;
};
auto applicativeExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::applyExceptT()(dictMonad);
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::ExceptT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(dictMonad["Applicative0"](undefined)))(Data_Either::Right())));
    };
    return _;
};
auto monadAskExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadAsk) -> boxed {
        return Control_Monad_Reader_Class::MonadAsk()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadExceptT()(dictMonadAsk["Monad0"](undefined));
        })(Control_Monad_Trans_Class::lift()(Control_Monad_Except_Trans::monadTransExceptT())(dictMonadAsk["Monad0"](undefined))(Control_Monad_Reader_Class::ask()(dictMonadAsk)));
    };
    return _;
};
auto monadReaderExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadReader) -> boxed {
        return Control_Monad_Reader_Class::MonadReader()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadAskExceptT()(dictMonadReader["MonadAsk0"](undefined));
        })([=](const boxed& f) -> boxed {
            return Control_Monad_Except_Trans::mapExceptT()(Control_Monad_Reader_Class::local()(dictMonadReader)(f));
        });
    };
    return _;
};
auto monadContExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadCont) -> boxed {
        return Control_Monad_Cont_Class::MonadCont()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadExceptT()(dictMonadCont["Monad0"](undefined));
        })([=](const boxed& f) -> boxed {
            return Control_Monad_Except_Trans::ExceptT()(Control_Monad_Cont_Class::callCC()(dictMonadCont)([=](const boxed& c) -> boxed {
                boxed v = f([=](const boxed& a) -> boxed {
                    return Control_Monad_Except_Trans::ExceptT()(c(Data_Either::Right()(a)));
                });
                return v;
            }));
        });
    };
    return _;
};
auto monadEffectExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Effect_Class::MonadEffect()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadExceptT()(dictMonadEffect["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Except_Trans::monadTransExceptT())(dictMonadEffect["Monad0"](undefined)))(Effect_Class::liftEffect()(dictMonadEffect)));
    };
    return _;
};
auto monadRecExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadExceptT()(dictMonadRec["Monad0"](undefined));
        })([=](const boxed& f) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::ExceptT())(Control_Monad_Rec_Class::tailRecM()(dictMonadRec)([=](const boxed& a) -> boxed {
                return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))([=]() -> boxed {
                    boxed v = f(a);
                    return v;
                }())([=](const boxed& m_Prime_) -> boxed {
                    return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))([=]() -> boxed {
                        if (unbox<dict_t>(m_Prime_).contains("Left")) {
                            return Control_Monad_Rec_Class::Done()(Data_Either::Left()(m_Prime_["value0"]));
                        };
                        if (unbox<dict_t>(m_Prime_).contains("Right")) {
                            if (unbox<dict_t>(m_Prime_["value0"]).contains("Loop")) {
                                return Control_Monad_Rec_Class::Loop()(m_Prime_["value0"]["value0"]);
                            };
                        };
                        if (unbox<dict_t>(m_Prime_).contains("Right")) {
                            if (unbox<dict_t>(m_Prime_["value0"]).contains("Done")) {
                                return Control_Monad_Rec_Class::Done()(Data_Either::Right()(m_Prime_["value0"]["value0"]));
                            };
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Except.Trans (line 74, column 14 - line 77, column 43): ");
                    }());
                });
            }));
        });
    };
    return _;
};
auto monadStateExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadState) -> boxed {
        return Control_Monad_State_Class::MonadState()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadExceptT()(dictMonadState["Monad0"](undefined));
        })([=](const boxed& f) -> boxed {
            return Control_Monad_Trans_Class::lift()(Control_Monad_Except_Trans::monadTransExceptT())(dictMonadState["Monad0"](undefined))(Control_Monad_State_Class::state()(dictMonadState)(f));
        });
    };
    return _;
};
auto monadTellExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadTell) -> boxed {
        return Control_Monad_Writer_Class::MonadTell()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadExceptT()(dictMonadTell["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Except_Trans::monadTransExceptT())(dictMonadTell["Monad0"](undefined)))(Control_Monad_Writer_Class::tell()(dictMonadTell)));
    };
    return _;
};
auto monadWriterExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadWriter) -> boxed {
        return Control_Monad_Writer_Class::MonadWriter()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadTellExceptT()(dictMonadWriter["MonadTell0"](undefined));
        })(Control_Monad_Except_Trans::mapExceptT()([=](const boxed& m) -> boxed {
            return Control_Bind::bind()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Writer_Class::listen()(dictMonadWriter)(m))([=](const boxed& v) -> boxed {
                return Control_Applicative::pure()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Applicative0"](undefined))(Data_Functor::map()(Data_Either::functorEither())([=](const boxed& r) -> boxed {
                    return Data_Tuple::Tuple()(r)(v["value1"]);
                })(v["value0"]));
            });
        }))(Control_Monad_Except_Trans::mapExceptT()([=](const boxed& m) -> boxed {
            return Control_Monad_Writer_Class::pass()(dictMonadWriter)(Control_Bind::bind()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(m)([=](const boxed& v) -> boxed {
                return Control_Applicative::pure()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Applicative0"](undefined))([=]() -> boxed {
                    if (unbox<dict_t>(v).contains("Left")) {
                        return Data_Tuple::Tuple()(Data_Either::Left()(v["value0"]))(Control_Category::identity()(Control_Category::categoryFn()));
                    };
                    if (unbox<dict_t>(v).contains("Right")) {
                        return Data_Tuple::Tuple()(Data_Either::Right()(v["value0"]["value0"]))(v["value0"]["value1"]);
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Except.Trans (line 136, column 10 - line 138, column 44): ");
                }());
            }));
        }));
    };
    return _;
};
auto monadThrowExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Error_Class::MonadThrow()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadExceptT()(dictMonad);
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::ExceptT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(dictMonad["Applicative0"](undefined)))(Data_Either::Left())));
    };
    return _;
};
auto monadErrorExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Error_Class::MonadError()([=](const boxed&) -> boxed {
            return Control_Monad_Except_Trans::monadThrowExceptT()(dictMonad);
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& k) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v)(Data_Either::either()([=](const boxed& a) -> boxed {
                    boxed v1 = k(a);
                    return v1;
                })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(dictMonad["Applicative0"](undefined)))(Data_Either::Right())));
            };
        });
    };
    return _;
};
auto altExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_Alt::Alt()([=](const boxed&) -> boxed {
                return Control_Monad_Except_Trans::functorExceptT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined));
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v)([=](const boxed& v2) -> boxed {
                        if (unbox<dict_t>(v2).contains("Right")) {
                            return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Either::Right()(v2["value0"]));
                        };
                        if (unbox<dict_t>(v2).contains("Left")) {
                            return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v1)([=](const boxed& v3) -> boxed {
                                if (unbox<dict_t>(v3).contains("Right")) {
                                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Either::Right()(v3["value0"]));
                                };
                                if (unbox<dict_t>(v3).contains("Left")) {
                                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Either::Left()(Data_Semigroup::append()(dictSemigroup)(v2["value0"])(v3["value0"])));
                                };
                                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Except.Trans (line 86, column 9 - line 88, column 49): ");
                            });
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Except.Trans (line 82, column 5 - line 88, column 49): ");
                    });
                };
            });
        };
    };
    return _;
};
auto plusExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_Plus::Plus()([=](const boxed&) -> boxed {
                return Control_Monad_Except_Trans::altExceptT()(dictMonoid["Semigroup0"](undefined))(dictMonad);
            })(Control_Monad_Error_Class::throwError()(Control_Monad_Except_Trans::monadThrowExceptT()(dictMonad))(Data_Monoid::mempty()(dictMonoid)));
        };
    };
    return _;
};
auto alternativeExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
                return Control_Monad_Except_Trans::applicativeExceptT()(dictMonad);
            })([=](const boxed&) -> boxed {
                return Control_Monad_Except_Trans::plusExceptT()(dictMonoid)(dictMonad);
            });
        };
    };
    return _;
};
auto monadZeroExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
                return Control_Monad_Except_Trans::alternativeExceptT()(dictMonoid)(dictMonad);
            })([=](const boxed&) -> boxed {
                return Control_Monad_Except_Trans::monadExceptT()(dictMonad);
            });
        };
    };
    return _;
};
auto monadPlusExceptT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
                return Control_Monad_Except_Trans::monadZeroExceptT()(dictMonoid)(dictMonad);
            });
        };
    };
    return _;
};


} // end namespace Control_Monad_Except_Trans


