#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Lazy/Data_Lazy.h"
#include "Data_List_Lazy_Types/Data_List_Lazy_Types.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_NonEmpty/Data_NonEmpty.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Prelude/Prelude.h"

#include "Data_List_Lazy/Data_List_Lazy.h"


namespace Data_List_Lazy {

auto Pattern() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto zipWith() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                boxed go = [=](const boxed& v) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        if (unbox<dict_t>(v).contains("Nil")) {
                            return Data_List_Lazy_Types::Nil();
                        };
                        if (unbox<dict_t>(v1).contains("Nil")) {
                            return Data_List_Lazy_Types::Nil();
                        };
                        if (unbox<dict_t>(v).contains("Cons")) {
                            if (unbox<dict_t>(v1).contains("Cons")) {
                                return Data_List_Lazy_Types::Cons()(f(v["value0"])(v1["value0"]))(Data_List_Lazy::zipWith()(f)(v["value1"])(v1["value1"]));
                            };
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 693, column 3 - line 693, column 35): ");
                    };
                };
                return Control_Apply::apply()(Data_Lazy::applyLazy())(Data_Functor::map()(Data_Lazy::functorLazy())(go)(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs)))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(ys));
            };
        };
    };
    return _;
};
auto zipWithA() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return [=](const boxed& ys) -> boxed {
                    return Data_Traversable::sequence()(Data_List_Lazy_Types::traversableList())(dictApplicative)(Data_List_Lazy::zipWith()(f)(xs)(ys));
                };
            };
        };
    };
    return _;
};
auto zip() -> boxed {
    return Data_List_Lazy::zipWith()(Data_Tuple::Tuple());
};
auto updateAt() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed go = [=](const boxed& v) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        if (unbox<dict_t>(v1).contains("Nil")) {
                            return Data_List_Lazy_Types::Nil();
                        };
                        if (unbox<int>(v) == 0) {
                            if (unbox<dict_t>(v1).contains("Cons")) {
                                return Data_List_Lazy_Types::Cons()(x)(v1["value1"]);
                            };
                        };
                        if (unbox<dict_t>(v1).contains("Cons")) {
                            return Data_List_Lazy_Types::Cons()(v1["value0"])(Data_List_Lazy::updateAt()(unbox<int>(v) - 1)(x)(v1["value1"]));
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 367, column 3 - line 367, column 17): ");
                    };
                };
                return Data_Functor::map()(Data_Lazy::functorLazy())(go(n))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
            };
        };
    };
    return _;
};
auto unzip() -> boxed {
    return Data_Foldable::foldr()(Data_List_Lazy_Types::foldableList())([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Tuple::Tuple()(Data_List_Lazy_Types::cons()(v["value0"])(v1["value0"]))(Data_List_Lazy_Types::cons()(v["value1"])(v1["value1"]));
        };
    })(Data_Tuple::Tuple()(Data_List_Lazy_Types::nil())(Data_List_Lazy_Types::nil()));
};
auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        boxed v = Data_List_Lazy_Types::step()(xs);
        if (unbox<dict_t>(v).contains("Nil")) {
            return Data_Maybe::Nothing();
        };
        if (unbox<dict_t>(v).contains("Cons")) {
            return Data_Maybe::Just()(dict_t{
                { "head", v["value0"] },
                { "tail", v["value1"] }
            });
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 285, column 13 - line 287, column 44): ");
    };
    return _;
};
auto toUnfoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return Data_Unfoldable::unfoldr()(dictUnfoldable)([=](const boxed& xs) -> boxed {
            return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& rec) -> boxed {
                return Data_Tuple::Tuple()(rec["head"])(rec["tail"]);
            })(Data_List_Lazy::uncons()(xs));
        });
    };
    return _;
};
auto takeWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        boxed go = [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Cons")) {
                if (unbox<bool>(p(v["value0"]))) {
                    return Data_List_Lazy_Types::Cons()(v["value0"])(Data_List_Lazy::takeWhile()(p)(v["value1"]));
                };
            };
            return Data_List_Lazy_Types::Nil();
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::List())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Lazy::functorLazy())(go))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())));
    };
    return _;
};
auto take() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        boxed go = [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Nil")) {
                    return Data_List_Lazy_Types::Nil();
                };
                if (unbox<dict_t>(v1).contains("Cons")) {
                    return Data_List_Lazy_Types::Cons()(v1["value0"])(Data_List_Lazy::take()(unbox<int>(v) - 1)(v1["value1"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 517, column 3 - line 517, column 32): ");
            };
        };
        boxed _Local_33 = Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(n)(0);
        if (unbox<bool>(_Local_33)) {
            return Data_Function::_const_()(Data_List_Lazy_Types::nil());
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::List())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Lazy::functorLazy())(go(n)))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())));
    };
    return _;
};
auto tail() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v) -> boxed {
            return v["tail"];
        })(Data_List_Lazy::uncons()(xs));
    };
    return _;
};
auto stripPrefix() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed go = [=](const boxed& prefix) -> boxed {
                    return [=](const boxed& input) -> boxed {
                        boxed v1 = Data_List_Lazy_Types::step()(prefix);
                        if (unbox<dict_t>(v1).contains("Nil")) {
                            return Data_Maybe::Just()(Control_Monad_Rec_Class::Done()(input));
                        };
                        if (unbox<dict_t>(v1).contains("Cons")) {
                            boxed v2 = Data_List_Lazy_Types::step()(input);
                            if (unbox<dict_t>(v2).contains("Cons")) {
                                if (unbox<bool>(Data_Eq::eq()(dictEq)(v1["value0"])(v2["value0"]))) {
                                    return Data_Maybe::Just()(Control_Monad_Rec_Class::Loop()(dict_t{
                                        { "a", v1["value1"] },
                                        { "b", v2["value1"] }
                                    }));
                                };
                            };
                            return Data_Maybe::Nothing();
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 499, column 21 - line 503, column 19): ");
                    };
                };
                return Control_Monad_Rec_Class::tailRecM2()(Control_Monad_Rec_Class::monadRecMaybe())(go)(v)(s);
            };
        };
    };
    return _;
};
auto span() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& xs) -> boxed {
            boxed v = Data_List_Lazy::uncons()(xs);
            if (unbox<dict_t>(v).contains("Just")) {
                if (unbox<bool>(p(v["value0"]["head"]))) {
                    boxed v1 = Data_List_Lazy::span()(p)(v["value0"]["tail"]);
                    return dict_t{
                        { "init", Data_List_Lazy_Types::cons()(v["value0"]["head"])(v1["init"]) },
                        { "rest", v1["rest"] }
                    };
                };
            };
            return dict_t{
                { "init", Data_List_Lazy_Types::nil() },
                { "rest", xs }
            };
        };
    };
    return _;
};
auto snoc() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Foldable::foldr()(Data_List_Lazy_Types::foldableList())(Data_List_Lazy_Types::cons())(Data_List_Lazy_Types::cons()(x)(Data_List_Lazy_Types::nil()))(xs);
        };
    };
    return _;
};
auto singleton() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return Data_List_Lazy_Types::cons()(a)(Data_List_Lazy_Types::nil());
    };
    return _;
};
auto showPattern() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Pattern ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_List_Lazy_Types::showList()(dictShow))(v))(")"));
        });
    };
    return _;
};
auto scanrLazy() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& acc) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed go = [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Nil")) {
                        return Data_List_Lazy_Types::Nil();
                    };
                    if (unbox<dict_t>(v).contains("Cons")) {
                        boxed acc_Prime_ = f(v["value0"])(acc);
                        return Data_List_Lazy_Types::Cons()(acc_Prime_)(Data_List_Lazy::scanrLazy()(f)(acc_Prime_)(v["value1"]));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 764, column 5 - line 764, column 27): ");
                };
                return Data_Functor::map()(Data_Lazy::functorLazy())(go)(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
            };
        };
    };
    return _;
};
auto reverse() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return Control_Lazy::defer()(Data_List_Lazy_Types::lazyList())([=](const boxed& v) -> boxed {
            return Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())(Data_Function::flip()(Data_List_Lazy_Types::cons()))(Data_List_Lazy_Types::nil())(xs);
        });
    };
    return _;
};
auto replicateM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& n) -> boxed {
            return [=](const boxed& m) -> boxed {
                if (unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(n)(Data_Semiring::one()(Data_Semiring::semiringInt())))) {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_List_Lazy_Types::nil());
                };
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(m)([=](const boxed& v) -> boxed {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Data_List_Lazy::replicateM()(dictMonad)(unbox<int>(n) - unbox<int>(Data_Semiring::one()(Data_Semiring::semiringInt())))(m))([=](const boxed& v1) -> boxed {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_List_Lazy_Types::cons()(v)(v1));
                    });
                });
            };
        };
    };
    return _;
};
auto repeat() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return Control_Lazy::fix()(Data_List_Lazy_Types::lazyList())([=](const boxed& xs) -> boxed {
            return Data_List_Lazy_Types::cons()(x)(xs);
        });
    };
    return _;
};
auto replicate() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_List_Lazy::take()(i)(Data_List_Lazy::repeat()(xs));
        };
    };
    return _;
};
auto range() -> const boxed& {
    static const boxed _ = [](const boxed& start) -> boxed {
        return [=](const boxed& end) -> boxed {
            if (unbox<bool>(Data_Ord::greaterThan()(Data_Ord::ordInt())(start)(end))) {
                boxed g = [=](const boxed& x) -> boxed {
                    if (unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(x)(end))) {
                        return Data_Maybe::Just()(Data_Tuple::Tuple()(x)(unbox<int>(x) - 1));
                    };
                    return Data_Maybe::Nothing();
                };
                return Data_Unfoldable::unfoldr()(Data_List_Lazy_Types::unfoldableList())(g)(start);
            };
            if (unbox<bool>(Data_Boolean::otherwise())) {
                boxed f = [=](const boxed& x) -> boxed {
                    if (unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(x)(end))) {
                        return Data_Maybe::Just()(Data_Tuple::Tuple()(x)(unbox<int>(x) + 1));
                    };
                    return Data_Maybe::Nothing();
                };
                return Data_Unfoldable::unfoldr()(Data_List_Lazy_Types::unfoldableList())(f)(start);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 145, column 1 - line 145, column 32): ");
        };
    };
    return _;
};
auto partition() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        boxed go = [=](const boxed& x) -> boxed {
            return [=](const boxed& v) -> boxed {
                boxed _Local_63 = f(x);
                if (unbox<bool>(_Local_63)) {
                    return dict_t{
                        { "yes", Data_List_Lazy_Types::cons()(x)(v["yes"]) },
                        { "no", v["no"] }
                    };
                };
                return dict_t{
                    { "yes", v["yes"] },
                    { "no", Data_List_Lazy_Types::cons()(x)(v["no"]) }
                };
            };
        };
        return Data_Foldable::foldr()(Data_List_Lazy_Types::foldableList())(go)(dict_t{
            { "yes", Data_List_Lazy_Types::nil() },
            { "no", Data_List_Lazy_Types::nil() }
        });
    };
    return _;
};
auto null() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::isNothing())(Data_List_Lazy::uncons());
};
auto newtypePattern() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_List_Lazy::Pattern());
};
auto mapMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& v) -> boxed {
            boxed go = go_Weak_;
            if (unbox<dict_t>(v).contains("Nil")) {
                return Data_List_Lazy_Types::Nil();
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                boxed v1 = f(v["value0"]);
                if (unbox<dict_t>(v1).contains("Nothing")) {
                    return go(Data_List_Lazy_Types::step()(v["value1"]));
                };
                if (unbox<dict_t>(v1).contains("Just")) {
                    return Data_List_Lazy_Types::Cons()(v1["value0"])(Data_List_Lazy::mapMaybe()(f)(v["value1"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 460, column 5 - line 462, column 39): ");
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 458, column 3 - line 458, column 15): ");
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::List())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Lazy::functorLazy())(go))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())));
    };
    return _;
};
auto some() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlternative) -> boxed {
        return [=](const boxed& dictLazy) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Apply::apply()(dictAlternative["Applicative0"](undefined)["Apply0"](undefined))(Data_Functor::map()(dictAlternative["Plus1"](undefined)["Alt0"](undefined)["Functor0"](undefined))(Data_List_Lazy_Types::cons())(v))(Control_Lazy::defer()(dictLazy)([=](const boxed& v1) -> boxed {
                    return Data_List_Lazy::many()(dictAlternative)(dictLazy)(v);
                }));
            };
        };
    };
    return _;
};
auto many() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlternative) -> boxed {
        return [=](const boxed& dictLazy) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Alt::alt()(dictAlternative["Plus1"](undefined)["Alt0"](undefined))(Data_List_Lazy::some()(dictAlternative)(dictLazy)(v))(Control_Applicative::pure()(dictAlternative["Applicative0"](undefined))(Data_List_Lazy_Types::nil()));
            };
        };
    };
    return _;
};
auto length() -> boxed {
    return Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())([=](const boxed& l) -> boxed {
        return [=](const boxed& v) -> boxed {
            return unbox<int>(l) + 1;
        };
    })(0);
};
auto last() -> boxed {
    boxed::recur go;
    boxed::recur::weak go_Weak_(go);
    go = [=](const boxed& v) -> boxed {
        boxed go = go_Weak_;
        if (unbox<dict_t>(v).contains("Cons")) {
            if (unbox<bool>(Data_List_Lazy::null()(v["value1"]))) {
                return Data_Maybe::Just()(v["value0"]);
            };
            return go(Data_List_Lazy_Types::step()(v["value1"]));
        };
        return Data_Maybe::Nothing();
    };
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(go)(Data_List_Lazy_Types::step());
};
auto iterate() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Control_Lazy::fix()(Data_List_Lazy_Types::lazyList())([=](const boxed& xs) -> boxed {
                return Data_List_Lazy_Types::cons()(x)(Data_Functor::map()(Data_List_Lazy_Types::functorList())(f)(xs));
            });
        };
    };
    return _;
};
auto insertAt() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& xs) -> boxed {
                if (unbox<int>(v) == 0) {
                    return Data_List_Lazy_Types::cons()(x)(xs);
                };
                boxed go = [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1).contains("Nil")) {
                        return Data_List_Lazy_Types::Cons()(x)(Data_List_Lazy_Types::nil());
                    };
                    if (unbox<dict_t>(v1).contains("Cons")) {
                        return Data_List_Lazy_Types::Cons()(v1["value0"])(Data_List_Lazy::insertAt()(unbox<int>(v) - 1)(x)(v1["value1"]));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 340, column 3 - line 340, column 22): ");
                };
                return Data_Functor::map()(Data_Lazy::functorLazy())(go)(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
            };
        };
    };
    return _;
};
auto init() -> boxed {
    boxed::recur go;
    boxed::recur::weak go_Weak_(go);
    go = [=](const boxed& v) -> boxed {
        boxed go = go_Weak_;
        if (unbox<dict_t>(v).contains("Cons")) {
            if (unbox<bool>(Data_List_Lazy::null()(v["value1"]))) {
                return Data_Maybe::Just()(Data_List_Lazy_Types::nil());
            };
            return Data_Functor::map()(Data_Maybe::functorMaybe())(Data_List_Lazy_Types::cons()(v["value0"]))(go(Data_List_Lazy_Types::step()(v["value1"])));
        };
        return Data_Maybe::Nothing();
    };
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(go)(Data_List_Lazy_Types::step());
};
auto index() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& v) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v).contains("Nil")) {
                    return Data_Maybe::Nothing();
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    if (unbox<int>(v1) == 0) {
                        return Data_Maybe::Just()(v["value0"]);
                    };
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    return go(Data_List_Lazy_Types::step()(v["value1"]))(unbox<int>(v1) - 1);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 299, column 3 - line 299, column 21): ");
            };
        };
        return go(Data_List_Lazy_Types::step()(xs));
    };
    return _;
};
auto head() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v) -> boxed {
            return v["head"];
        })(Data_List_Lazy::uncons()(xs));
    };
    return _;
};
auto transpose() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        boxed v = Data_List_Lazy::uncons()(xs);
        if (unbox<dict_t>(v).contains("Nothing")) {
            return xs;
        };
        if (unbox<dict_t>(v).contains("Just")) {
            boxed v1 = Data_List_Lazy::uncons()(v["value0"]["head"]);
            if (unbox<dict_t>(v1).contains("Nothing")) {
                return Data_List_Lazy::transpose()(v["value0"]["tail"]);
            };
            if (unbox<dict_t>(v1).contains("Just")) {
                return Data_List_Lazy_Types::cons()(Data_List_Lazy_Types::cons()(v1["value0"]["head"])(Data_List_Lazy::mapMaybe()(Data_List_Lazy::head())(v["value0"]["tail"])))(Data_List_Lazy::transpose()(Data_List_Lazy_Types::cons()(v1["value0"]["tail"])(Data_List_Lazy::mapMaybe()(Data_List_Lazy::tail())(v["value0"]["tail"]))));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 734, column 7 - line 738, column 72): ");
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 730, column 3 - line 738, column 72): ");
    };
    return _;
};
auto groupBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        boxed go = [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Nil")) {
                return Data_List_Lazy_Types::Nil();
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                boxed v1 = Data_List_Lazy::span()(eq(v["value0"]))(v["value1"]);
                return Data_List_Lazy_Types::Cons()(Data_Lazy::defer()([=](const boxed& v2) -> boxed {
                    return Data_NonEmpty::NonEmpty()(v["value0"])(v1["init"]);
                }))(Data_List_Lazy::groupBy()(eq)(v1["rest"]));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 588, column 3 - line 588, column 15): ");
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::List())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Lazy::functorLazy())(go))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())));
    };
    return _;
};
auto group() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_Lazy::groupBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto fromStep() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::List())(Control_Applicative::pure()(Data_Lazy::applicativeLazy()));
};
auto insertBy() -> const boxed& {
    static const boxed _ = [](const boxed& cmp) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed go = [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Nil")) {
                        return Data_List_Lazy_Types::Cons()(x)(Data_List_Lazy_Types::nil());
                    };
                    if (unbox<dict_t>(v).contains("Cons")) {
                        boxed v1 = cmp(x)(v["value0"]);
                        if (unbox<dict_t>(v1).contains("GT")) {
                            return Data_List_Lazy_Types::Cons()(v["value0"])(Data_List_Lazy::insertBy()(cmp)(x)(v["value1"]));
                        };
                        return Data_List_Lazy_Types::Cons()(x)(Data_List_Lazy::fromStep()(v));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 235, column 3 - line 235, column 22): ");
                };
                return Data_Functor::map()(Data_Lazy::functorLazy())(go)(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
            };
        };
    };
    return _;
};
auto insert() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_List_Lazy::insertBy()(Data_Ord::compare()(dictOrd));
    };
    return _;
};
auto fromFoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Data_Foldable::foldr()(dictFoldable)(Data_List_Lazy_Types::cons())(Data_List_Lazy_Types::nil());
    };
    return _;
};
auto foldrLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictLazy) -> boxed {
        return [=](const boxed& op) -> boxed {
            return [=](const boxed& z) -> boxed {
                boxed::recur go;
                boxed::recur::weak go_Weak_(go);
                go = [=](const boxed& xs) -> boxed {
                    boxed go = go_Weak_;
                    boxed v = Data_List_Lazy_Types::step()(xs);
                    if (unbox<dict_t>(v).contains("Cons")) {
                        return Control_Lazy::defer()(dictLazy)([=](const boxed& v1) -> boxed {
                            return op(v["value0"])(go(v["value1"]));
                        });
                    };
                    if (unbox<dict_t>(v).contains("Nil")) {
                        return z;
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 756, column 13 - line 758, column 15): ");
                };
                return go;
            };
        };
    };
    return _;
};
auto foldM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    boxed v = Data_List_Lazy::uncons()(xs);
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(a);
                    };
                    if (unbox<dict_t>(v).contains("Just")) {
                        return Control_Bind::bind()(dictMonad["Bind1"](undefined))(f(a)(v["value0"]["head"]))([=](const boxed& a_Prime_) -> boxed {
                            return Data_List_Lazy::foldM()(dictMonad)(f)(a_Prime_)(v["value0"]["tail"]);
                        });
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 747, column 5 - line 750, column 54): ");
                };
            };
        };
    };
    return _;
};
auto findIndex() -> const boxed& {
    static const boxed _ = [](const boxed& fn) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& n) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& list) -> boxed {
                return Control_Bind::bind()(Data_Maybe::bindMaybe())(Data_List_Lazy::uncons()(list))([=](const boxed& v) -> boxed {
                    boxed _Local_116 = fn(v["head"]);
                    if (unbox<bool>(_Local_116)) {
                        return Control_Applicative::pure()(Data_Maybe::applicativeMaybe())(n);
                    };
                    return go(unbox<int>(n) + 1)(v["tail"]);
                });
            };
        };
        return go(0);
    };
    return _;
};
auto findLastIndex() -> const boxed& {
    static const boxed _ = [](const boxed& fn) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v) -> boxed {
                return unbox<int>(unbox<int>(Data_List_Lazy::length()(xs)) - 1) - unbox<int>(v);
            })(Data_List_Lazy::findIndex()(fn)(Data_List_Lazy::reverse()(xs)));
        };
    };
    return _;
};
auto filterM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& list) -> boxed {
                boxed v = Data_List_Lazy::uncons()(list);
                if (unbox<dict_t>(v).contains("Nothing")) {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_List_Lazy_Types::nil());
                };
                if (unbox<dict_t>(v).contains("Just")) {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(p(v["value0"]["head"]))([=](const boxed& v1) -> boxed {
                        return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Data_List_Lazy::filterM()(dictMonad)(p)(v["value0"]["tail"]))([=](const boxed& v2) -> boxed {
                            return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))([=]() -> boxed {
                                if (unbox<bool>(v1)) {
                                    return Data_List_Lazy_Types::cons()(v["value0"]["head"])(v2);
                                };
                                return v2;
                            }());
                        });
                    });
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 443, column 5 - line 448, column 48): ");
            };
        };
    };
    return _;
};
auto filter() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& v) -> boxed {
            boxed go = go_Weak_;
            if (unbox<dict_t>(v).contains("Nil")) {
                return Data_List_Lazy_Types::Nil();
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                if (unbox<bool>(p(v["value0"]))) {
                    return Data_List_Lazy_Types::Cons()(v["value0"])(Data_List_Lazy::filter()(p)(v["value1"]));
                };
                return go(Data_List_Lazy_Types::step()(v["value1"]));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 428, column 3 - line 428, column 15): ");
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::List())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Lazy::functorLazy())(go))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())));
    };
    return _;
};
auto intersectBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                return Data_List_Lazy::filter()([=](const boxed& x) -> boxed {
                    return Data_Foldable::any()(Data_List_Lazy_Types::foldableList())(Data_HeytingAlgebra::heytingAlgebraBoolean())(eq(x))(ys);
                })(xs);
            };
        };
    };
    return _;
};
auto intersect() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_Lazy::intersectBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto nubBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        boxed go = [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Nil")) {
                return Data_List_Lazy_Types::Nil();
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                return Data_List_Lazy_Types::Cons()(v["value0"])(Data_List_Lazy::nubBy()(eq)(Data_List_Lazy::filter()([=](const boxed& y) -> boxed {
                    return !unbox<bool>(eq(v["value0"])(y));
                })(v["value1"])));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 621, column 3 - line 621, column 15): ");
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::List())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Lazy::functorLazy())(go))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())));
    };
    return _;
};
auto nub() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_Lazy::nubBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto eqPattern() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::Eq()([=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                return Data_Eq::eq()(Data_List_Lazy_Types::eqList()(dictEq))(x)(y);
            };
        });
    };
    return _;
};
auto ordPattern() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord()([=](const boxed&) -> boxed {
            return Data_List_Lazy::eqPattern()(dictOrd["Eq0"](undefined));
        })([=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                return Data_Ord::compare()(Data_List_Lazy_Types::ordList()(dictOrd))(x)(y);
            };
        });
    };
    return _;
};
auto elemLastIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_List_Lazy::findLastIndex()([=](const boxed& v) -> boxed {
                return Data_Eq::eq()(dictEq)(v)(x);
            });
        };
    };
    return _;
};
auto elemIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_List_Lazy::findIndex()([=](const boxed& v) -> boxed {
                return Data_Eq::eq()(dictEq)(v)(x);
            });
        };
    };
    return _;
};
auto dropWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& v) -> boxed {
            boxed go = go_Weak_;
            if (unbox<dict_t>(v).contains("Cons")) {
                if (unbox<bool>(p(v["value0"]))) {
                    return go(Data_List_Lazy_Types::step()(v["value1"]));
                };
            };
            return Data_List_Lazy::fromStep()(v);
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(go)(Data_List_Lazy_Types::step());
    };
    return _;
};
auto drop() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& v) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& v1) -> boxed {
                if (unbox<int>(v) == 0) {
                    return v1;
                };
                if (unbox<dict_t>(v1).contains("Nil")) {
                    return Data_List_Lazy_Types::Nil();
                };
                if (unbox<dict_t>(v1).contains("Cons")) {
                    return go(unbox<int>(v) - 1)(Data_List_Lazy_Types::step()(v1["value1"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 536, column 3 - line 536, column 15): ");
            };
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::List())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Lazy::functorLazy())(go(n)))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())));
    };
    return _;
};
auto slice() -> const boxed& {
    static const boxed _ = [](const boxed& start) -> boxed {
        return [=](const boxed& end) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return Data_List_Lazy::take()(unbox<int>(end) - unbox<int>(start))(Data_List_Lazy::drop()(start)(xs));
            };
        };
    };
    return _;
};
auto deleteBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed go = [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Nil")) {
                        return Data_List_Lazy_Types::Nil();
                    };
                    if (unbox<dict_t>(v).contains("Cons")) {
                        if (unbox<bool>(eq(x)(v["value0"]))) {
                            return Data_List_Lazy_Types::step()(v["value1"]);
                        };
                        return Data_List_Lazy_Types::Cons()(v["value0"])(Data_List_Lazy::deleteBy()(eq)(x)(v["value1"]));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 650, column 3 - line 650, column 15): ");
                };
                return Data_Functor::map()(Data_Lazy::functorLazy())(go)(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
            };
        };
    };
    return _;
};
auto unionBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                return Data_Semigroup::append()(Data_List_Lazy_Types::semigroupList())(xs)(Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())(Data_Function::flip()(Data_List_Lazy::deleteBy()(eq)))(Data_List_Lazy::nubBy()(eq)(ys))(xs));
            };
        };
    };
    return _;
};
auto _union_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_Lazy::unionBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto deleteAt() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& xs) -> boxed {
            boxed go = [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1).contains("Nil")) {
                        return Data_List_Lazy_Types::Nil();
                    };
                    if (unbox<int>(v) == 0) {
                        if (unbox<dict_t>(v1).contains("Cons")) {
                            return Data_List_Lazy_Types::step()(v1["value1"]);
                        };
                    };
                    if (unbox<dict_t>(v1).contains("Cons")) {
                        return Data_List_Lazy_Types::Cons()(v1["value0"])(Data_List_Lazy::deleteAt()(unbox<int>(v) - 1)(v1["value1"]));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 353, column 3 - line 353, column 17): ");
                };
            };
            return Data_Functor::map()(Data_Lazy::functorLazy())(go(n))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
        };
    };
    return _;
};
auto _delete_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_Lazy::deleteBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto difference() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())(Data_Function::flip()(Data_List_Lazy::_delete_()(dictEq)));
    };
    return _;
};
auto cycle() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return Control_Lazy::fix()(Data_List_Lazy_Types::lazyList())([=](const boxed& ys) -> boxed {
            return Data_Semigroup::append()(Data_List_Lazy_Types::semigroupList())(xs)(ys);
        });
    };
    return _;
};
auto concatMap() -> boxed {
    return Data_Function::flip()(Control_Bind::bind()(Data_List_Lazy_Types::bindList()));
};
auto concat() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Control_Bind::bind()(Data_List_Lazy_Types::bindList())(v)(Control_Category::identity()(Control_Category::categoryFn()));
    };
    return _;
};
auto catMaybes() -> boxed {
    return Data_List_Lazy::mapMaybe()(Control_Category::identity()(Control_Category::categoryFn()));
};
auto alterAt() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed go = [=](const boxed& v) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        if (unbox<dict_t>(v1).contains("Nil")) {
                            return Data_List_Lazy_Types::Nil();
                        };
                        if (unbox<int>(v) == 0) {
                            if (unbox<dict_t>(v1).contains("Cons")) {
                                boxed v2 = f(v1["value0"]);
                                if (unbox<dict_t>(v2).contains("Nothing")) {
                                    return Data_List_Lazy_Types::step()(v1["value1"]);
                                };
                                if (unbox<dict_t>(v2).contains("Just")) {
                                    return Data_List_Lazy_Types::Cons()(v2["value0"])(v1["value1"]);
                                };
                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 394, column 22 - line 396, column 26): ");
                            };
                        };
                        if (unbox<dict_t>(v1).contains("Cons")) {
                            return Data_List_Lazy_Types::Cons()(v1["value0"])(Data_List_Lazy::alterAt()(unbox<int>(v) - 1)(f)(v1["value1"]));
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy (line 393, column 3 - line 393, column 17): ");
                    };
                };
                return Data_Functor::map()(Data_Lazy::functorLazy())(go(n))(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
            };
        };
    };
    return _;
};
auto modifyAt() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_List_Lazy::alterAt()(n)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::Just())(f));
        };
    };
    return _;
};


} // end namespace Data_List_Lazy


