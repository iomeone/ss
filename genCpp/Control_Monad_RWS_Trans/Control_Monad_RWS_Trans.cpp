#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Monad_Error_Class/Control_Monad_Error_Class.h"
#include "Control_Monad_Reader_Class/Control_Monad_Reader_Class.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Control_Monad_State_Class/Control_Monad_State_Class.h"
#include "Control_Monad_Trans_Class/Control_Monad_Trans_Class.h"
#include "Control_Monad_Writer_Class/Control_Monad_Writer_Class.h"
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

#include "Control_Monad_RWS_Trans/Control_Monad_RWS_Trans.h"


namespace Control_Monad_RWS_Trans {

auto RWSResult() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return [=](const boxed& value2) -> boxed {
                return dict_t{
                    { "RWSResult", true },
                    { "value0", value0 },
                    { "value1", value1 },
                    { "value2", value2 }
                };
            };
        };
    };
    return _;
};
auto RWST() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto withRWST() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& s) -> boxed {
                    return Data_Tuple::uncurry()(m)(f(r)(s));
                };
            };
        };
    };
    return _;
};
auto runRWST() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto newtypeRWST() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Monad_RWS_Trans::RWST());
};
auto monadTransRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return Control_Monad_Trans_Class::MonadTrans()([=](const boxed& dictMonad) -> boxed {
            return [=](const boxed& m) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return [=](const boxed& s) -> boxed {
                        return Control_Bind::bind()(dictMonad["Bind1"](undefined))(m)([=](const boxed& a) -> boxed {
                            return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Control_Monad_RWS_Trans::RWSResult()(s)(a)(Data_Monoid::mempty()(dictMonoid)));
                        });
                    };
                };
            };
        });
    };
    return _;
};
auto mapRWST() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& s) -> boxed {
                    return f(v(r)(s));
                };
            };
        };
    };
    return _;
};
auto lazyRWST() -> boxed {
    return Control_Lazy::Lazy()([=](const boxed& f) -> boxed {
        return [=](const boxed& r) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed v = f(Data_Unit::unit());
                return v(r)(s);
            };
        };
    });
};
auto functorRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return [=](const boxed& s) -> boxed {
                        return Data_Functor::map()(dictFunctor)([=](const boxed& v1) -> boxed {
                            return Control_Monad_RWS_Trans::RWSResult()(v1["value0"])(f(v1["value1"]))(v1["value2"]);
                        })(v(r)(s));
                    };
                };
            };
        });
    };
    return _;
};
auto execRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& s) -> boxed {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v(r)(s))([=](const boxed& v1) -> boxed {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v1["value0"])(v1["value2"]));
                    });
                };
            };
        };
    };
    return _;
};
auto evalRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& s) -> boxed {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v(r)(s))([=](const boxed& v1) -> boxed {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v1["value1"])(v1["value2"]));
                    });
                };
            };
        };
    };
    return _;
};
auto applyRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Apply::Apply()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::functorRWST()(dictBind["Apply0"](undefined)["Functor0"](undefined));
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return [=](const boxed& r) -> boxed {
                        return [=](const boxed& s) -> boxed {
                            return Control_Bind::bind()(dictBind)(v(r)(s))([=](const boxed& v2) -> boxed {
                                return Data_Functor::mapFlipped()(dictBind["Apply0"](undefined)["Functor0"](undefined))(v1(r)(v2["value0"]))([=](const boxed& v3) -> boxed {
                                    return Control_Monad_RWS_Trans::RWSResult()(v3["value0"])(v2["value1"](v3["value1"]))(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(v2["value2"])(v3["value2"]));
                                });
                            });
                        };
                    };
                };
            });
        };
    };
    return _;
};
auto bindRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Bind::Bind()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::applyRWST()(dictBind)(dictMonoid);
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return [=](const boxed& r) -> boxed {
                        return [=](const boxed& s) -> boxed {
                            return Control_Bind::bind()(dictBind)(v(r)(s))([=](const boxed& v1) -> boxed {
                                boxed v2 = f(v1["value1"]);
                                return Data_Functor::mapFlipped()(dictBind["Apply0"](undefined)["Functor0"](undefined))(v2(r)(v1["value0"]))([=](const boxed& v3) -> boxed {
                                    return Control_Monad_RWS_Trans::RWSResult()(v3["value0"])(v3["value1"])(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(v1["value2"])(v3["value2"]));
                                });
                            });
                        };
                    };
                };
            });
        };
    };
    return _;
};
auto applicativeRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::applyRWST()(dictMonad["Bind1"](undefined))(dictMonoid);
            })([=](const boxed& a) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return [=](const boxed& s) -> boxed {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Control_Monad_RWS_Trans::RWSResult()(s)(a)(Data_Monoid::mempty()(dictMonoid)));
                    };
                };
            });
        };
    };
    return _;
};
auto monadRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Monad::Monad()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::applicativeRWST()(dictMonad)(dictMonoid);
            })([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::bindRWST()(dictMonad["Bind1"](undefined))(dictMonoid);
            });
        };
    };
    return _;
};
auto monadAskRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Monad_Reader_Class::MonadAsk()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::monadRWST()(dictMonad)(dictMonoid);
            })([=](const boxed& r) -> boxed {
                return [=](const boxed& s) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Control_Monad_RWS_Trans::RWSResult()(s)(r)(Data_Monoid::mempty()(dictMonoid)));
                };
            });
        };
    };
    return _;
};
auto monadReaderRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Monad_Reader_Class::MonadReader()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::monadAskRWST()(dictMonad)(dictMonoid);
            })([=](const boxed& f) -> boxed {
                return [=](const boxed& m) -> boxed {
                    return [=](const boxed& r) -> boxed {
                        return [=](const boxed& s) -> boxed {
                            return m(f(r))(s);
                        };
                    };
                };
            });
        };
    };
    return _;
};
auto monadEffectRWS() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonadEffect) -> boxed {
            return Effect_Class::MonadEffect()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::monadRWST()(dictMonadEffect["Monad0"](undefined))(dictMonoid);
            })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_RWS_Trans::monadTransRWST()(dictMonoid))(dictMonadEffect["Monad0"](undefined)))(Effect_Class::liftEffect()(dictMonadEffect)));
        };
    };
    return _;
};
auto monadRecRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::monadRWST()(dictMonadRec["Monad0"](undefined))(dictMonoid);
            })([=](const boxed& k) -> boxed {
                return [=](const boxed& a) -> boxed {
                    boxed k_Prime_ = [=](const boxed& r) -> boxed {
                        return [=](const boxed& v) -> boxed {
                            boxed v1 = k(v["value1"]);
                            return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))(v1(r)(v["value0"]))([=](const boxed& v2) -> boxed {
                                return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))([=]() -> boxed {
                                    if (unbox<dict_t>(v2["value1"]).contains("Loop")) {
                                        return Control_Monad_Rec_Class::Loop()(Control_Monad_RWS_Trans::RWSResult()(v2["value0"])(v2["value1"]["value0"])(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(v["value2"])(v2["value2"])));
                                    };
                                    if (unbox<dict_t>(v2["value1"]).contains("Done")) {
                                        return Control_Monad_Rec_Class::Done()(Control_Monad_RWS_Trans::RWSResult()(v2["value0"])(v2["value1"]["value0"])(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(v["value2"])(v2["value2"])));
                                    };
                                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.RWS.Trans (line 127, column 16 - line 129, column 68): ");
                                }());
                            });
                        };
                    };
                    return [=](const boxed& r) -> boxed {
                        return [=](const boxed& s) -> boxed {
                            return Control_Monad_Rec_Class::tailRecM()(dictMonadRec)(k_Prime_(r))(Control_Monad_RWS_Trans::RWSResult()(s)(a)(Data_Monoid::mempty()(dictMonoid)));
                        };
                    };
                };
            });
        };
    };
    return _;
};
auto monadStateRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Monad_State_Class::MonadState()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::monadRWST()(dictMonad)(dictMonoid);
            })([=](const boxed& f) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return [=](const boxed& s) -> boxed {
                        boxed v1 = f(s);
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Control_Monad_RWS_Trans::RWSResult()(v1["value1"])(v1["value0"])(Data_Monoid::mempty()(dictMonoid)));
                    };
                };
            });
        };
    };
    return _;
};
auto monadTellRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Monad_Writer_Class::MonadTell()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::monadRWST()(dictMonad)(dictMonoid);
            })([=](const boxed& w) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return [=](const boxed& s) -> boxed {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Control_Monad_RWS_Trans::RWSResult()(s)(Data_Unit::unit())(w));
                    };
                };
            });
        };
    };
    return _;
};
auto monadWriterRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Monad_Writer_Class::MonadWriter()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::monadTellRWST()(dictMonad)(dictMonoid);
            })([=](const boxed& m) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return [=](const boxed& s) -> boxed {
                        return Control_Bind::bind()(dictMonad["Bind1"](undefined))(m(r)(s))([=](const boxed& v) -> boxed {
                            return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Control_Monad_RWS_Trans::RWSResult()(v["value0"])(Data_Tuple::Tuple()(v["value1"])(v["value2"]))(v["value2"]));
                        });
                    };
                };
            })([=](const boxed& m) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return [=](const boxed& s) -> boxed {
                        return Control_Bind::bind()(dictMonad["Bind1"](undefined))(m(r)(s))([=](const boxed& v) -> boxed {
                            return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Control_Monad_RWS_Trans::RWSResult()(v["value0"])(v["value1"]["value0"])(v["value1"]["value1"](v["value2"])));
                        });
                    };
                };
            });
        };
    };
    return _;
};
auto monadThrowRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadThrow) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Monad_Error_Class::MonadThrow()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::monadRWST()(dictMonadThrow["Monad0"](undefined))(dictMonoid);
            })([=](const boxed& e) -> boxed {
                return Control_Monad_Trans_Class::lift()(Control_Monad_RWS_Trans::monadTransRWST()(dictMonoid))(dictMonadThrow["Monad0"](undefined))(Control_Monad_Error_Class::throwError()(dictMonadThrow)(e));
            });
        };
    };
    return _;
};
auto monadErrorRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadError) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Control_Monad_Error_Class::MonadError()([=](const boxed&) -> boxed {
                return Control_Monad_RWS_Trans::monadThrowRWST()(dictMonadError["MonadThrow0"](undefined))(dictMonoid);
            })([=](const boxed& m) -> boxed {
                return [=](const boxed& h) -> boxed {
                    return Control_Monad_RWS_Trans::RWST()([=](const boxed& r) -> boxed {
                        return [=](const boxed& s) -> boxed {
                            return Control_Monad_Error_Class::catchError()(dictMonadError)(m(r)(s))([=](const boxed& e) -> boxed {
                                boxed v = h(e);
                                return v(r)(s);
                            });
                        };
                    });
                };
            });
        };
    };
    return _;
};
auto altRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlt) -> boxed {
        return Control_Alt::Alt()([=](const boxed&) -> boxed {
            return Control_Monad_RWS_Trans::functorRWST()(dictAlt["Functor0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Monad_RWS_Trans::RWST()([=](const boxed& r) -> boxed {
                    return [=](const boxed& s) -> boxed {
                        return Control_Alt::alt()(dictAlt)(v(r)(s))(v1(r)(s));
                    };
                });
            };
        });
    };
    return _;
};
auto plusRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictPlus) -> boxed {
        return Control_Plus::Plus()([=](const boxed&) -> boxed {
            return Control_Monad_RWS_Trans::altRWST()(dictPlus["Alt0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Plus::empty()(dictPlus);
            };
        });
    };
    return _;
};
auto alternativeRWST() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictAlternative) -> boxed {
            return [=](const boxed& dictMonad) -> boxed {
                return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
                    return Control_Monad_RWS_Trans::applicativeRWST()(dictMonad)(dictMonoid);
                })([=](const boxed&) -> boxed {
                    return Control_Monad_RWS_Trans::plusRWST()(dictAlternative["Plus1"](undefined));
                });
            };
        };
    };
    return _;
};


} // end namespace Control_Monad_RWS_Trans


