#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Control_Monad_Trans_Class/Control_Monad_Trans_Class.h"
#include "Control_MonadPlus/Control_MonadPlus.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Control_Plus/Control_Plus.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Lazy/Data_Lazy.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Data_Unfoldable1/Data_Unfoldable1.h"
#include "Data_Unit/Data_Unit.h"
#include "Effect_Class/Effect_Class.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_List_Trans/Control_Monad_List_Trans.h"


namespace Control_Monad_List_Trans {

auto Yield() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "Yield", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto Skip() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "Skip", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto Done() -> const boxed& {
    static const boxed _ = dict_t{
        { "Done", true }
    };
    return _;
};
auto ListT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto wrapLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Monad_List_Trans::ListT()(Control_Applicative::pure()(dictApplicative)(Control_Monad_List_Trans::Skip()(v)));
        };
    };
    return _;
};
auto wrapEffect() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Monad_List_Trans::ListT()(Data_Functor::map()(dictFunctor)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_List_Trans::Skip())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Lazy::defer())(Data_Function::_const_())))(v));
        };
    };
    return _;
};
auto unfold() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& z) -> boxed {
                boxed g = [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Just")) {
                        return Control_Monad_List_Trans::Yield()(v["value0"]["value1"])(Data_Lazy::defer()([=](const boxed& v1) -> boxed {
                            return Control_Monad_List_Trans::unfold()(dictMonad)(f)(v["value0"]["value0"]);
                        }));
                    };
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Control_Monad_List_Trans::Done();
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 130, column 3 - line 130, column 60): ");
                };
                return Control_Monad_List_Trans::ListT()(Data_Functor::map()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(g)(f(z)));
            };
        };
    };
    return _;
};
auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            boxed g = [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Yield")) {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Maybe::Just()(Data_Tuple::Tuple()(v1["value0"])(Data_Lazy::force()(v1["value1"]))));
                };
                if (unbox<dict_t>(v1).contains("Skip")) {
                    return Control_Monad_List_Trans::uncons()(dictMonad)(Data_Lazy::force()(v1["value0"]));
                };
                if (unbox<dict_t>(v1).contains("Done")) {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Maybe::Nothing());
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 195, column 3 - line 195, column 50): ");
            };
            return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v)(g);
        };
    };
    return _;
};
auto tail() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& l) -> boxed {
            return Data_Functor::map()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Functor::map()(Data_Maybe::functorMaybe())(Data_Tuple::snd()))(Control_Monad_List_Trans::uncons()(dictMonad)(l));
        };
    };
    return _;
};
auto stepMap() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Monad_List_Trans::ListT()(Data_Functor::map()(dictFunctor)(f)(v));
            };
        };
    };
    return _;
};
auto takeWhile() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed g = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Yield")) {
                    boxed _Local_17 = f(v["value0"]);
                    if (unbox<bool>(_Local_17)) {
                        return Control_Monad_List_Trans::Yield()(v["value0"])(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::takeWhile()(dictApplicative)(f))(v["value1"]));
                    };
                    return Control_Monad_List_Trans::Done();
                };
                if (unbox<dict_t>(v).contains("Skip")) {
                    return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::takeWhile()(dictApplicative)(f))(v["value0"]));
                };
                if (unbox<dict_t>(v).contains("Done")) {
                    return Control_Monad_List_Trans::Done();
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 154, column 3 - line 154, column 68): ");
            };
            return Control_Monad_List_Trans::stepMap()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(g);
        };
    };
    return _;
};
auto scanl() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& b) -> boxed {
                return [=](const boxed& l) -> boxed {
                    boxed g = [=](const boxed& v) -> boxed {
                        boxed h = [=](const boxed& v1) -> boxed {
                            if (unbox<dict_t>(v1).contains("Yield")) {
                                boxed b_Prime__Prime_ = f(v["value0"])(v1["value0"]);
                                return Data_Maybe::Just()(Data_Tuple::Tuple()(Data_Tuple::Tuple()(b_Prime__Prime_)(Data_Lazy::force()(v1["value1"])))(v["value0"]));
                            };
                            if (unbox<dict_t>(v1).contains("Skip")) {
                                return Data_Maybe::Just()(Data_Tuple::Tuple()(Data_Tuple::Tuple()(v["value0"])(Data_Lazy::force()(v1["value0"])))(v["value0"]));
                            };
                            if (unbox<dict_t>(v1).contains("Done")) {
                                return Data_Maybe::Nothing();
                            };
                            THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 248, column 5 - line 248, column 78): ");
                        };
                        return Data_Functor::map()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(h)(v["value1"]);
                    };
                    return Control_Monad_List_Trans::unfold()(dictMonad)(g)(Data_Tuple::Tuple()(b)(l));
                };
            };
        };
    };
    return _;
};
auto prepend_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& h) -> boxed {
            return [=](const boxed& t) -> boxed {
                return Control_Monad_List_Trans::ListT()(Control_Applicative::pure()(dictApplicative)(Control_Monad_List_Trans::Yield()(h)(t)));
            };
        };
    };
    return _;
};
auto prepend() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& h) -> boxed {
            return [=](const boxed& t) -> boxed {
                return Control_Monad_List_Trans::prepend_Prime_()(dictApplicative)(h)(Data_Lazy::defer()(Data_Function::_const_()(t)));
            };
        };
    };
    return _;
};
auto nil() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return Control_Monad_List_Trans::ListT()(Control_Applicative::pure()(dictApplicative)(Control_Monad_List_Trans::Done()));
    };
    return _;
};
auto singleton() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Control_Monad_List_Trans::prepend()(dictApplicative)(a)(Control_Monad_List_Trans::nil()(dictApplicative));
        };
    };
    return _;
};
auto take() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& fa) -> boxed {
                if (unbox<int>(v) == 0) {
                    return Control_Monad_List_Trans::nil()(dictApplicative);
                };
                boxed f = [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1).contains("Yield")) {
                        return Control_Monad_List_Trans::Yield()(v1["value0"])(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::take()(dictApplicative)(unbox<int>(v) - 1))(v1["value1"]));
                    };
                    if (unbox<dict_t>(v1).contains("Skip")) {
                        return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::take()(dictApplicative)(v))(v1["value0"]));
                    };
                    if (unbox<dict_t>(v1).contains("Done")) {
                        return Control_Monad_List_Trans::Done();
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 147, column 3 - line 147, column 47): ");
                };
                return Control_Monad_List_Trans::stepMap()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(f)(fa);
            };
        };
    };
    return _;
};
auto zipWith_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed g = [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1).contains("Nothing")) {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Control_Monad_List_Trans::nil()(dictMonad["Applicative0"](undefined)));
                    };
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Control_Monad_List_Trans::nil()(dictMonad["Applicative0"](undefined)));
                    };
                    if (unbox<dict_t>(v).contains("Just")) {
                        if (unbox<dict_t>(v1).contains("Just")) {
                            return Data_Functor::map()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Function::flip()(Control_Monad_List_Trans::prepend_Prime_()(dictMonad["Applicative0"](undefined)))(Data_Lazy::defer()([=](const boxed& v2) -> boxed {
                                return Control_Monad_List_Trans::zipWith_Prime_()(dictMonad)(f)(v["value0"]["value1"])(v1["value0"]["value1"]);
                            })))(f(v["value0"]["value0"])(v1["value0"]["value0"]));
                        };
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 260, column 3 - line 260, column 25): ");
                };
            };
            boxed loop = [=](const boxed& fa) -> boxed {
                return [=](const boxed& fb) -> boxed {
                    return Control_Monad_List_Trans::wrapEffect()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Control_Bind::bind()(dictMonad["Bind1"](undefined))(Control_Monad_List_Trans::uncons()(dictMonad)(fa))([=](const boxed& v) -> boxed {
                        return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Control_Monad_List_Trans::uncons()(dictMonad)(fb))([=](const boxed& v1) -> boxed {
                            return g(v)(v1);
                        });
                    }));
                };
            };
            return loop;
        };
    };
    return _;
};
auto zipWith() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed g = [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(f(a)(b));
                };
            };
            return Control_Monad_List_Trans::zipWith_Prime_()(dictMonad)(g);
        };
    };
    return _;
};
auto newtypeListT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Control_Monad_List_Trans::ListT());
};
auto mapMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed g = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Yield")) {
                    return Data_Maybe::fromMaybe()(Control_Monad_List_Trans::Skip())(Data_Functor::map()(Data_Maybe::functorMaybe())(Control_Monad_List_Trans::Yield())(f(v["value0"])))(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::mapMaybe()(dictFunctor)(f))(v["value1"]));
                };
                if (unbox<dict_t>(v).contains("Skip")) {
                    return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::mapMaybe()(dictFunctor)(f))(v["value0"]));
                };
                if (unbox<dict_t>(v).contains("Done")) {
                    return Control_Monad_List_Trans::Done();
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 183, column 3 - line 183, column 72): ");
            };
            return Control_Monad_List_Trans::stepMap()(dictFunctor)(g);
        };
    };
    return _;
};
auto iterate() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                boxed g = [=](const boxed& x) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Maybe::Just()(Data_Tuple::Tuple()(f(x))(x)));
                };
                return Control_Monad_List_Trans::unfold()(dictMonad)(g)(a);
            };
        };
    };
    return _;
};
auto repeat() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_List_Trans::iterate()(dictMonad)(Control_Category::identity()(Control_Category::categoryFn()));
    };
    return _;
};
auto head() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& l) -> boxed {
            return Data_Functor::map()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Functor::map()(Data_Maybe::functorMaybe())(Data_Tuple::fst()))(Control_Monad_List_Trans::uncons()(dictMonad)(l));
        };
    };
    return _;
};
auto functorListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            boxed g = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Yield")) {
                    return Control_Monad_List_Trans::Yield()(f(v["value0"]))(Data_Functor::map()(Data_Lazy::functorLazy())(Data_Functor::map()(Control_Monad_List_Trans::functorListT()(dictFunctor))(f))(v["value1"]));
                };
                if (unbox<dict_t>(v).contains("Skip")) {
                    return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())(Data_Functor::map()(Control_Monad_List_Trans::functorListT()(dictFunctor))(f))(v["value0"]));
                };
                if (unbox<dict_t>(v).contains("Done")) {
                    return Control_Monad_List_Trans::Done();
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 280, column 5 - line 280, column 48): ");
            };
            return Control_Monad_List_Trans::stepMap()(dictFunctor)(g);
        });
    };
    return _;
};
auto fromEffect() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& fa) -> boxed {
            return Control_Monad_List_Trans::ListT()(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Function::flip()(Control_Monad_List_Trans::Yield())(Data_Lazy::defer()([=](const boxed& v) -> boxed {
                return Control_Monad_List_Trans::nil()(dictApplicative);
            })))(fa));
        };
    };
    return _;
};
auto monadTransListT() -> boxed {
    return Control_Monad_Trans_Class::MonadTrans()([=](const boxed& dictMonad) -> boxed {
        return Control_Monad_List_Trans::fromEffect()(dictMonad["Applicative0"](undefined));
    });
};
auto foldlRec_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed loop = [=](const boxed& b) -> boxed {
                return [=](const boxed& l) -> boxed {
                    boxed g = [=](const boxed& v) -> boxed {
                        if (unbox<dict_t>(v).contains("Nothing")) {
                            return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))(Control_Monad_Rec_Class::Done()(b));
                        };
                        if (unbox<dict_t>(v).contains("Just")) {
                            return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))(f(b)(v["value0"]["value0"]))([=](const boxed& b_Prime_) -> boxed {
                                return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))(Control_Monad_Rec_Class::Loop()(dict_t{
                                    { "a", b_Prime_ },
                                    { "b", v["value0"]["value1"] }
                                }));
                            });
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 221, column 5 - line 221, column 45): ");
                    };
                    return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_List_Trans::uncons()(dictMonadRec["Monad0"](undefined))(l))(g);
                };
            };
            return Control_Monad_Rec_Class::tailRecM2()(dictMonadRec)(loop);
        };
    };
    return _;
};
auto runListTRec() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return Control_Monad_List_Trans::foldlRec_Prime_()(dictMonadRec)([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))(Data_Unit::unit());
            };
        })(Data_Unit::unit());
    };
    return _;
};
auto foldlRec() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed loop = [=](const boxed& b) -> boxed {
                return [=](const boxed& l) -> boxed {
                    boxed g = [=](const boxed& v) -> boxed {
                        if (unbox<dict_t>(v).contains("Nothing")) {
                            return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))(Control_Monad_Rec_Class::Done()(b));
                        };
                        if (unbox<dict_t>(v).contains("Just")) {
                            return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))(Control_Monad_Rec_Class::Loop()(dict_t{
                                { "a", f(b)(v["value0"]["value0"]) },
                                { "b", v["value0"]["value1"] }
                            }));
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 239, column 7 - line 239, column 47): ");
                    };
                    return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_List_Trans::uncons()(dictMonadRec["Monad0"](undefined))(l))(g);
                };
            };
            return Control_Monad_Rec_Class::tailRecM2()(dictMonadRec)(loop);
        };
    };
    return _;
};
auto foldl_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed::recur loop;
            boxed::recur::weak loop_Weak_(loop);
            loop = [=](const boxed& b) -> boxed {
                boxed loop = loop_Weak_;
                return [=](const boxed& l) -> boxed {
                    boxed g = [=](const boxed& v) -> boxed {
                        if (unbox<dict_t>(v).contains("Nothing")) {
                            return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(b);
                        };
                        if (unbox<dict_t>(v).contains("Just")) {
                            return Control_Bind::bind()(dictMonad["Bind1"](undefined))(f(b)(v["value0"]["value0"]))(Data_Function::flip()(loop)(v["value0"]["value1"]));
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 212, column 5 - line 212, column 35): ");
                    };
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Control_Monad_List_Trans::uncons()(dictMonad)(l))(g);
                };
            };
            return loop;
        };
    };
    return _;
};
auto runListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_List_Trans::foldl_Prime_()(dictMonad)([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Unit::unit());
            };
        })(Data_Unit::unit());
    };
    return _;
};
auto foldl() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed::recur loop;
            boxed::recur::weak loop_Weak_(loop);
            loop = [=](const boxed& b) -> boxed {
                boxed loop = loop_Weak_;
                return [=](const boxed& l) -> boxed {
                    boxed g = [=](const boxed& v) -> boxed {
                        if (unbox<dict_t>(v).contains("Nothing")) {
                            return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(b);
                        };
                        if (unbox<dict_t>(v).contains("Just")) {
                            return loop(f(b)(v["value0"]["value0"]))(v["value0"]["value1"]);
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 229, column 5 - line 229, column 35): ");
                    };
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Control_Monad_List_Trans::uncons()(dictMonad)(l))(g);
                };
            };
            return loop;
        };
    };
    return _;
};
auto filter() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed g = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Yield")) {
                    boxed s_Prime_ = Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::filter()(dictFunctor)(f))(v["value1"]);
                    boxed _Local_70 = f(v["value0"]);
                    if (unbox<bool>(_Local_70)) {
                        return Control_Monad_List_Trans::Yield()(v["value0"])(s_Prime_);
                    };
                    return Control_Monad_List_Trans::Skip()(s_Prime_);
                };
                if (unbox<dict_t>(v).contains("Skip")) {
                    boxed s_Prime_ = Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::filter()(dictFunctor)(f))(v["value0"]);
                    return Control_Monad_List_Trans::Skip()(s_Prime_);
                };
                if (unbox<dict_t>(v).contains("Done")) {
                    return Control_Monad_List_Trans::Done();
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 176, column 3 - line 176, column 80): ");
            };
            return Control_Monad_List_Trans::stepMap()(dictFunctor)(g);
        };
    };
    return _;
};
auto dropWhile() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed g = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Yield")) {
                    boxed _Local_75 = f(v["value0"]);
                    if (unbox<bool>(_Local_75)) {
                        return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::dropWhile()(dictApplicative)(f))(v["value1"]));
                    };
                    return Control_Monad_List_Trans::Yield()(v["value0"])(v["value1"]);
                };
                if (unbox<dict_t>(v).contains("Skip")) {
                    return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::dropWhile()(dictApplicative)(f))(v["value0"]));
                };
                if (unbox<dict_t>(v).contains("Done")) {
                    return Control_Monad_List_Trans::Done();
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 169, column 3 - line 169, column 70): ");
            };
            return Control_Monad_List_Trans::stepMap()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(g);
        };
    };
    return _;
};
auto drop() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& fa) -> boxed {
                if (unbox<int>(v) == 0) {
                    return fa;
                };
                boxed f = [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1).contains("Yield")) {
                        return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::drop()(dictApplicative)(unbox<int>(v) - 1))(v1["value1"]));
                    };
                    if (unbox<dict_t>(v1).contains("Skip")) {
                        return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())(Control_Monad_List_Trans::drop()(dictApplicative)(v))(v1["value0"]));
                    };
                    if (unbox<dict_t>(v1).contains("Done")) {
                        return Control_Monad_List_Trans::Done();
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 162, column 3 - line 162, column 44): ");
                };
                return Control_Monad_List_Trans::stepMap()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(f)(fa);
            };
        };
    };
    return _;
};
auto cons() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& lh) -> boxed {
            return [=](const boxed& t) -> boxed {
                return Control_Monad_List_Trans::ListT()(Control_Applicative::pure()(dictApplicative)(Control_Monad_List_Trans::Yield()(Data_Lazy::force()(lh))(t)));
            };
        };
    };
    return _;
};
auto unfoldable1ListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Data_Unfoldable1::Unfoldable1()([=](const boxed& f) -> boxed {
            return [=](const boxed& b) -> boxed {
                boxed::recur go;
                boxed::recur::weak go_Weak_(go);
                go = [=](const boxed& v) -> boxed {
                    boxed go = go_Weak_;
                    if (unbox<dict_t>(v["value1"]).contains("Nothing")) {
                        return Control_Monad_List_Trans::singleton()(dictMonad["Applicative0"](undefined))(v["value0"]);
                    };
                    if (unbox<dict_t>(v["value1"]).contains("Just")) {
                        return Control_Monad_List_Trans::cons()(dictMonad["Applicative0"](undefined))(Control_Applicative::pure()(Data_Lazy::applicativeLazy())(v["value0"]))(Data_Lazy::defer()([=](const boxed& v1) -> boxed {
                            return go(f(v["value1"]["value0"]));
                        }));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 294, column 12 - line 296, column 67): ");
                };
                return go(f(b));
            };
        });
    };
    return _;
};
auto unfoldableListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Data_Unfoldable::Unfoldable()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::unfoldable1ListT()(dictMonad);
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& b) -> boxed {
                boxed::recur go;
                boxed::recur::weak go_Weak_(go);
                go = [=](const boxed& v) -> boxed {
                    boxed go = go_Weak_;
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Control_Monad_List_Trans::nil()(dictMonad["Applicative0"](undefined));
                    };
                    if (unbox<dict_t>(v).contains("Just")) {
                        return Control_Monad_List_Trans::cons()(dictMonad["Applicative0"](undefined))(Control_Applicative::pure()(Data_Lazy::applicativeLazy())(v["value0"]["value0"]))(Data_Lazy::defer()([=](const boxed& v1) -> boxed {
                            return go(f(v["value0"]["value1"]));
                        }));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 287, column 12 - line 289, column 67): ");
                };
                return go(f(b));
            };
        });
    };
    return _;
};
auto semigroupListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return Data_Semigroup::Semigroup()(Control_Monad_List_Trans::concat()(dictApplicative));
    };
    return _;
};
auto concat() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                boxed f = [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Yield")) {
                        return Control_Monad_List_Trans::Yield()(v["value0"])(Data_Functor::map()(Data_Lazy::functorLazy())([=](const boxed& v1) -> boxed {
                            return Data_Semigroup::append()(Control_Monad_List_Trans::semigroupListT()(dictApplicative))(v1)(y);
                        })(v["value1"]));
                    };
                    if (unbox<dict_t>(v).contains("Skip")) {
                        return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())([=](const boxed& v1) -> boxed {
                            return Data_Semigroup::append()(Control_Monad_List_Trans::semigroupListT()(dictApplicative))(v1)(y);
                        })(v["value0"]));
                    };
                    if (unbox<dict_t>(v).contains("Done")) {
                        return Control_Monad_List_Trans::Skip()(Data_Lazy::defer()(Data_Function::_const_()(y)));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 106, column 3 - line 106, column 43): ");
                };
                return Control_Monad_List_Trans::stepMap()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(f)(x);
            };
        };
    };
    return _;
};
auto monoidListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::semigroupListT()(dictApplicative);
        })(Control_Monad_List_Trans::nil()(dictApplicative));
    };
    return _;
};
auto catMaybes() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Control_Monad_List_Trans::mapMaybe()(dictFunctor)(Control_Category::identity()(Control_Category::categoryFn()));
    };
    return _;
};
auto monadListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad::Monad()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::applicativeListT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::bindListT()(dictMonad);
        });
    };
    return _;
};
auto bindListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Bind::Bind()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::applyListT()(dictMonad);
        })([=](const boxed& fa) -> boxed {
            return [=](const boxed& f) -> boxed {
                boxed g = [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Yield")) {
                        boxed h = [=](const boxed& s_Prime_) -> boxed {
                            return Data_Semigroup::append()(Control_Monad_List_Trans::semigroupListT()(dictMonad["Applicative0"](undefined)))(f(v["value0"]))(Control_Bind::bind()(Control_Monad_List_Trans::bindListT()(dictMonad))(s_Prime_)(f));
                        };
                        return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())(h)(v["value1"]));
                    };
                    if (unbox<dict_t>(v).contains("Skip")) {
                        return Control_Monad_List_Trans::Skip()(Data_Functor::map()(Data_Lazy::functorLazy())([=](const boxed& v1) -> boxed {
                            return Control_Bind::bind()(Control_Monad_List_Trans::bindListT()(dictMonad))(v1)(f);
                        })(v["value0"]));
                    };
                    if (unbox<dict_t>(v).contains("Done")) {
                        return Control_Monad_List_Trans::Done();
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.List.Trans (line 306, column 5 - line 308, column 31): ");
                };
                return Control_Monad_List_Trans::stepMap()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(g)(fa);
            };
        });
    };
    return _;
};
auto applyListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Apply::Apply()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::functorListT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined));
        })(Control_Monad::ap()(Control_Monad_List_Trans::monadListT()(dictMonad)));
    };
    return _;
};
auto applicativeListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::applyListT()(dictMonad);
        })(Control_Monad_List_Trans::singleton()(dictMonad["Applicative0"](undefined)));
    };
    return _;
};
auto monadEffectListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Effect_Class::MonadEffect()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::monadListT()(dictMonadEffect["Monad0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_List_Trans::monadTransListT())(dictMonadEffect["Monad0"](undefined)))(Effect_Class::liftEffect()(dictMonadEffect)));
    };
    return _;
};
auto altListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return Control_Alt::Alt()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::functorListT()(dictApplicative["Apply0"](undefined)["Functor0"](undefined));
        })(Control_Monad_List_Trans::concat()(dictApplicative));
    };
    return _;
};
auto plusListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Plus::Plus()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::altListT()(dictMonad["Applicative0"](undefined));
        })(Control_Monad_List_Trans::nil()(dictMonad["Applicative0"](undefined)));
    };
    return _;
};
auto alternativeListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::applicativeListT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::plusListT()(dictMonad);
        });
    };
    return _;
};
auto monadZeroListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::alternativeListT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::monadListT()(dictMonad);
        });
    };
    return _;
};
auto monadPlusListT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
            return Control_Monad_List_Trans::monadZeroListT()(dictMonad);
        });
    };
    return _;
};


} // end namespace Control_Monad_List_Trans


