#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Bifunctor/Data_Bifunctor.h"
#include "Data_Either/Data_Either.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Unit/Data_Unit.h"
#include "Effect/Effect.h"
#include "Effect_Ref/Effect_Ref.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"


namespace Control_Monad_Rec_Class {

auto Loop() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "Loop", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto Done() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "Done", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto MonadRec() -> const boxed& {
    static const boxed _ = [](const boxed& Monad0) -> boxed {
        return [=](const boxed& tailRecM) -> boxed {
            return dict_t{
                { "Monad0", Monad0 },
                { "tailRecM", tailRecM }
            };
        };
    };
    return _;
};
auto tailRecM() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["tailRecM"];
    };
    return _;
};
auto tailRecM2() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return Control_Monad_Rec_Class::tailRecM()(dictMonadRec)([=](const boxed& o) -> boxed {
                        return f(o["a"])(o["b"]);
                    })(dict_t{
                        { "a", a },
                        { "b", b }
                    });
                };
            };
        };
    };
    return _;
};
auto tailRecM3() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return Control_Monad_Rec_Class::tailRecM()(dictMonadRec)([=](const boxed& o) -> boxed {
                            return f(o["a"])(o["b"])(o["c"]);
                        })(dict_t{
                            { "a", a },
                            { "b", b },
                            { "c", c }
                        });
                    };
                };
            };
        };
    };
    return _;
};
auto tailRec() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& v) -> boxed {
            boxed go = go_Weak_;
            if (unbox<dict_t>(v).contains("Loop")) {
                return go(f(v["value0"]));
            };
            if (unbox<dict_t>(v).contains("Done")) {
                return v["value0"];
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Rec.Class (line 91, column 3 - line 91, column 25): ");
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(go)(f);
    };
    return _;
};
auto monadRecMaybe() -> boxed {
    return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
        return Data_Maybe::monadMaybe();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& a0) -> boxed {
            boxed g = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Nothing")) {
                    return Control_Monad_Rec_Class::Done()(Data_Maybe::Nothing());
                };
                if (unbox<dict_t>(v).contains("Just")) {
                    if (unbox<dict_t>(v["value0"]).contains("Loop")) {
                        return Control_Monad_Rec_Class::Loop()(f(v["value0"]["value0"]));
                    };
                };
                if (unbox<dict_t>(v).contains("Just")) {
                    if (unbox<dict_t>(v["value0"]).contains("Done")) {
                        return Control_Monad_Rec_Class::Done()(Data_Maybe::Just()(v["value0"]["value0"]));
                    };
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Rec.Class (line 127, column 7 - line 127, column 31): ");
            };
            return Control_Monad_Rec_Class::tailRec()(g)(f(a0));
        };
    });
};
auto monadRecIdentity() -> boxed {
    return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
        return Data_Identity::monadIdentity();
    })([=](const boxed& f) -> boxed {
        boxed runIdentity = [=](const boxed& v) -> boxed {
            return v;
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(Control_Monad_Rec_Class::tailRec()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(runIdentity)(f)));
    });
};
auto monadRecFunction() -> boxed {
    return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
        return Control_Monad::monadFn();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& a0) -> boxed {
            return [=](const boxed& e) -> boxed {
                return Control_Monad_Rec_Class::tailRec()([=](const boxed& a) -> boxed {
                    return f(a)(e);
                })(a0);
            };
        };
    });
};
auto monadRecEither() -> boxed {
    return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
        return Data_Either::monadEither();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& a0) -> boxed {
            boxed g = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Left")) {
                    return Control_Monad_Rec_Class::Done()(Data_Either::Left()(v["value0"]));
                };
                if (unbox<dict_t>(v).contains("Right")) {
                    if (unbox<dict_t>(v["value0"]).contains("Loop")) {
                        return Control_Monad_Rec_Class::Loop()(f(v["value0"]["value0"]));
                    };
                };
                if (unbox<dict_t>(v).contains("Right")) {
                    if (unbox<dict_t>(v["value0"]).contains("Done")) {
                        return Control_Monad_Rec_Class::Done()(Data_Either::Right()(v["value0"]["value0"]));
                    };
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Rec.Class (line 119, column 7 - line 119, column 33): ");
            };
            return Control_Monad_Rec_Class::tailRec()(g)(f(a0));
        };
    });
};
auto monadRecEffect() -> boxed {
    return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
        return Effect::monadEffect();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& a) -> boxed {
            boxed fromDone = [=](const boxed& dictPartial) -> boxed {
                return [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Done")) {
                        return v["value0"];
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Rec.Class (line 111, column 30 - line 111, column 44): ");
                };
            }(undefined);
            return [=]() -> boxed {
                boxed v = Control_Bind::bindFlipped()(Effect::bindEffect())(Effect_Ref::_new_())(f(a))();
                Effect::untilE()([=]() -> boxed {
                    boxed v1 = Effect_Ref::read()(v)();
                    if (unbox<dict_t>(v1).contains("Loop")) {
                        boxed v2 = f(v1["value0"])();
                        boxed v3 = Effect_Ref::write()(v2)(v)();
                        return false;
                    };
                    if (unbox<dict_t>(v1).contains("Done")) {
                        return true;
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Rec.Class (line 102, column 22 - line 107, column 28): ");
                })();
                return Data_Functor::map()(Effect::functorEffect())(fromDone)(Effect_Ref::read()(v))();
            };
        };
    });
};
auto functorStep() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            if (unbox<dict_t>(m).contains("Loop")) {
                return Control_Monad_Rec_Class::Loop()(m["value0"]);
            };
            if (unbox<dict_t>(m).contains("Done")) {
                return Control_Monad_Rec_Class::Done()(f(m["value0"]));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Rec.Class (line 25, column 8 - line 25, column 48): ");
        };
    });
};
auto forever() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& ma) -> boxed {
            return Control_Monad_Rec_Class::tailRecM()(dictMonadRec)([=](const boxed& u) -> boxed {
                return Data_Functor::voidRight()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Control_Monad_Rec_Class::Loop()(u))(ma);
            })(Data_Unit::unit());
        };
    };
    return _;
};
auto bifunctorStep() -> boxed {
    return Data_Bifunctor::Bifunctor()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<dict_t>(v2).contains("Loop")) {
                    return Control_Monad_Rec_Class::Loop()(v(v2["value0"]));
                };
                if (unbox<dict_t>(v2).contains("Done")) {
                    return Control_Monad_Rec_Class::Done()(v1(v2["value0"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Rec.Class (line 27, column 1 - line 27, column 41): ");
            };
        };
    });
};


} // end namespace Control_Monad_Rec_Class


