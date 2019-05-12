#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Bifunctor/Data_Bifunctor.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_List_Types/Data_List_Types.h"
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
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_List/Data_List.h"


namespace Data_List {

auto Pattern() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto updateAt() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<int>(v) == 0) {
                    if (unbox<dict_t>(v2).contains("Cons")) {
                        return Data_Maybe::Just()(Data_List_Types::Cons()(v1)(v2["value1"]));
                    };
                };
                if (unbox<dict_t>(v2).contains("Cons")) {
                    return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v3) -> boxed {
                        return Data_List_Types::Cons()(v2["value0"])(v3);
                    })(Data_List::updateAt()(unbox<int>(v) - 1)(v1)(v2["value1"]));
                };
                return Data_Maybe::Nothing();
            };
        };
    };
    return _;
};
auto unzip() -> boxed {
    return Data_Foldable::foldr()(Data_List_Types::foldableList())([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Tuple::Tuple()(Data_List_Types::Cons()(v["value0"])(v1["value0"]))(Data_List_Types::Cons()(v["value1"])(v1["value1"]));
        };
    })(Data_Tuple::Tuple()(Data_List_Types::Nil())(Data_List_Types::Nil()));
};
auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Nil")) {
            return Data_Maybe::Nothing();
        };
        if (unbox<dict_t>(v).contains("Cons")) {
            return Data_Maybe::Just()(dict_t{
                { "head", v["value0"] },
                { "tail", v["value1"] }
            });
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 259, column 1 - line 259, column 66): ");
    };
    return _;
};
auto toUnfoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return Data_Unfoldable::unfoldr()(dictUnfoldable)([=](const boxed& xs) -> boxed {
            return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& rec) -> boxed {
                return Data_Tuple::Tuple()(rec["head"])(rec["tail"]);
            })(Data_List::uncons()(xs));
        });
    };
    return _;
};
auto tail() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Nil")) {
            return Data_Maybe::Nothing();
        };
        if (unbox<dict_t>(v).contains("Cons")) {
            return Data_Maybe::Just()(v["value1"]);
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 245, column 1 - line 245, column 43): ");
    };
    return _;
};
auto stripPrefix() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed go = [=](const boxed& prefix) -> boxed {
                    return [=](const boxed& input) -> boxed {
                        if (unbox<dict_t>(prefix).contains("Cons")) {
                            if (unbox<dict_t>(input).contains("Cons")) {
                                if (unbox<bool>(Data_Eq::eq()(dictEq)(prefix["value0"])(input["value0"]))) {
                                    return Data_Maybe::Just()(Control_Monad_Rec_Class::Loop()(dict_t{
                                        { "a", prefix["value1"] },
                                        { "b", input["value1"] }
                                    }));
                                };
                            };
                        };
                        if (unbox<dict_t>(prefix).contains("Nil")) {
                            return Data_Maybe::Just()(Control_Monad_Rec_Class::Done()(input));
                        };
                        return Data_Maybe::Nothing();
                    };
                };
                return Control_Monad_Rec_Class::tailRecM2()(Control_Monad_Rec_Class::monadRecMaybe())(go)(v)(s);
            };
        };
    };
    return _;
};
auto span() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v1).contains("Cons")) {
                if (unbox<bool>(v(v1["value0"]))) {
                    boxed v2 = Data_List::span()(v)(v1["value1"]);
                    return dict_t{
                        { "init", Data_List_Types::Cons()(v1["value0"])(v2["init"]) },
                        { "rest", v2["rest"] }
                    };
                };
            };
            return dict_t{
                { "init", Data_List_Types::Nil() },
                { "rest", v1 }
            };
        };
    };
    return _;
};
auto snoc() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Foldable::foldr()(Data_List_Types::foldableList())(Data_List_Types::Cons())(Data_List_Types::Cons()(x)(Data_List_Types::Nil()))(xs);
        };
    };
    return _;
};
auto singleton() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return Data_List_Types::Cons()(a)(Data_List_Types::Nil());
    };
    return _;
};
auto sortBy() -> const boxed& {
    static const boxed _ = [](const boxed& cmp) -> boxed {
        boxed::recur merge;
        boxed::recur mergePairs;
        boxed::recur mergeAll;
        boxed::recur sequences;
        boxed::recur descending;
        boxed::recur ascending;
        boxed::recur::weak merge_Weak_(merge);
        boxed::recur::weak mergePairs_Weak_(mergePairs);
        boxed::recur::weak mergeAll_Weak_(mergeAll);
        boxed::recur::weak sequences_Weak_(sequences);
        boxed::recur::weak descending_Weak_(descending);
        boxed::recur::weak ascending_Weak_(ascending);
        #pragma message("Mutually recursive lets will cause retain cycles (memory leaks)") //;
        merge = [=](const boxed& v) -> boxed {
            boxed merge = merge_Weak_;
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v).contains("Cons")) {
                    if (unbox<dict_t>(v1).contains("Cons")) {
                        if (unbox<bool>(Data_Eq::eq()(Data_Ordering::eqOrdering())(cmp(v["value0"])(v1["value0"]))(Data_Ordering::GT()))) {
                            return Data_List_Types::Cons()(v1["value0"])(merge(v)(v1["value1"]));
                        };
                        return Data_List_Types::Cons()(v["value0"])(merge(v["value1"])(v1));
                    };
                };
                if (unbox<dict_t>(v).contains("Nil")) {
                    return v1;
                };
                if (unbox<dict_t>(v1).contains("Nil")) {
                    return v;
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 473, column 3 - line 473, column 38): ");
            };
        };
        mergePairs = [=](const boxed& v) -> boxed {
            boxed mergePairs = mergePairs_Weak_;
            if (unbox<dict_t>(v).contains("Cons")) {
                if (unbox<dict_t>(v["value1"]).contains("Cons")) {
                    return Data_List_Types::Cons()(merge(v["value0"])(v["value1"]["value0"]))(mergePairs(v["value1"]["value1"]));
                };
            };
            return v;
        };
        mergeAll = [=](const boxed& v) -> boxed {
            boxed mergeAll = mergeAll_Weak_;
            if (unbox<dict_t>(v).contains("Cons")) {
                if (unbox<dict_t>(v["value1"]).contains("Nil")) {
                    return v["value0"];
                };
            };
            return mergeAll(mergePairs(v));
        };
        sequences = [=](const boxed& v) -> boxed {
            boxed sequences = sequences_Weak_;
            if (unbox<dict_t>(v).contains("Cons")) {
                if (unbox<dict_t>(v["value1"]).contains("Cons")) {
                    if (unbox<bool>(Data_Eq::eq()(Data_Ordering::eqOrdering())(cmp(v["value0"])(v["value1"]["value0"]))(Data_Ordering::GT()))) {
                        return descending(v["value1"]["value0"])(Data_List::singleton()(v["value0"]))(v["value1"]["value1"]);
                    };
                    return ascending(v["value1"]["value0"])([=](const boxed& v1) -> boxed {
                        return Data_List_Types::Cons()(v["value0"])(v1);
                    })(v["value1"]["value1"]);
                };
            };
            return Data_List::singleton()(v);
        };
        descending = [=](const boxed& a) -> boxed {
            boxed descending = descending_Weak_;
            return [=](const boxed& as) -> boxed {
                return [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Cons")) {
                        if (unbox<bool>(Data_Eq::eq()(Data_Ordering::eqOrdering())(cmp(a)(v["value0"]))(Data_Ordering::GT()))) {
                            return descending(v["value0"])(Data_List_Types::Cons()(a)(as))(v["value1"]);
                        };
                    };
                    return Data_List_Types::Cons()(Data_List_Types::Cons()(a)(as))(sequences(v));
                };
            };
        };
        ascending = [=](const boxed& a) -> boxed {
            boxed ascending = ascending_Weak_;
            return [=](const boxed& as) -> boxed {
                return [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Cons")) {
                        if (unbox<bool>(Data_Eq::notEq()(Data_Ordering::eqOrdering())(cmp(a)(v["value0"]))(Data_Ordering::GT()))) {
                            return ascending(v["value0"])([=](const boxed& ys) -> boxed {
                                return as(Data_List_Types::Cons()(a)(ys));
                            })(v["value1"]);
                        };
                    };
                    return Data_List_Types::Cons()(as(Data_List::singleton()(a)))(sequences(v));
                };
            };
        };
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(mergeAll)(sequences);
    };
    return _;
};
auto sort() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_List::sortBy()(Data_Ord::compare()(dictOrd))(xs);
        };
    };
    return _;
};
auto tails() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Nil")) {
            return Data_List::singleton()(Data_List_Types::Nil());
        };
        if (unbox<dict_t>(v).contains("Cons")) {
            return Data_List_Types::Cons()(v)(Data_List::tails()(v["value1"]));
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 626, column 1 - line 626, column 43): ");
    };
    return _;
};
auto showPattern() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Pattern ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_List_Types::showList()(dictShow))(v))(")"));
        });
    };
    return _;
};
auto reverse() -> boxed {
    boxed::recur go;
    boxed::recur::weak go_Weak_(go);
    go = [=](const boxed& acc) -> boxed {
        boxed go = go_Weak_;
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Nil")) {
                return acc;
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                return go(Data_List_Types::Cons()(v["value0"])(acc))(v["value1"]);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 368, column 3 - line 368, column 19): ");
        };
    };
    return go(Data_List_Types::Nil());
};
auto take() -> boxed {
    boxed::recur go;
    boxed::recur::weak go_Weak_(go);
    go = [=](const boxed& acc) -> boxed {
        boxed go = go_Weak_;
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(v)(1))) {
                    return Data_List::reverse()(acc);
                };
                if (unbox<dict_t>(v1).contains("Nil")) {
                    return Data_List::reverse()(acc);
                };
                if (unbox<dict_t>(v1).contains("Cons")) {
                    return go(Data_List_Types::Cons()(v1["value0"])(acc))(unbox<int>(v) - 1)(v1["value1"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 520, column 3 - line 520, column 35): ");
            };
        };
    };
    return go(Data_List_Types::Nil());
};
auto takeWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& acc) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Cons")) {
                    if (unbox<bool>(p(v["value0"]))) {
                        return go(Data_List_Types::Cons()(v["value0"])(acc))(v["value1"]);
                    };
                };
                return Data_List::reverse()(acc);
            };
        };
        return go(Data_List_Types::Nil());
    };
    return _;
};
auto unsnoc() -> const boxed& {
    static const boxed _ = [](const boxed& lst) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& v) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& acc) -> boxed {
                if (unbox<dict_t>(v).contains("Nil")) {
                    return Data_Maybe::Nothing();
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    if (unbox<dict_t>(v["value1"]).contains("Nil")) {
                        return Data_Maybe::Just()(dict_t{
                            { "revInit", acc },
                            { "last", v["value0"] }
                        });
                    };
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    return go(v["value1"])(Data_List_Types::Cons()(v["value0"])(acc));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 270, column 3 - line 270, column 23): ");
            };
        };
        return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& h) -> boxed {
            return dict_t{
                { "init", Data_List::reverse()(h["revInit"]) },
                { "last", h["last"] }
            };
        })(go(lst)(Data_List_Types::Nil()));
    };
    return _;
};
auto zipWith() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                boxed::recur go;
                boxed::recur::weak go_Weak_(go);
                go = [=](const boxed& v) -> boxed {
                    boxed go = go_Weak_;
                    return [=](const boxed& v1) -> boxed {
                        return [=](const boxed& acc) -> boxed {
                            if (unbox<dict_t>(v).contains("Nil")) {
                                return acc;
                            };
                            if (unbox<dict_t>(v1).contains("Nil")) {
                                return acc;
                            };
                            if (unbox<dict_t>(v).contains("Cons")) {
                                if (unbox<dict_t>(v1).contains("Cons")) {
                                    return go(v["value1"])(v1["value1"])(Data_List_Types::Cons()(f(v["value0"])(v1["value0"]))(acc));
                                };
                            };
                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 718, column 3 - line 718, column 21): ");
                        };
                    };
                };
                return Data_List::reverse()(go(xs)(ys)(Data_List_Types::Nil()));
            };
        };
    };
    return _;
};
auto zip() -> boxed {
    return Data_List::zipWith()(Data_Tuple::Tuple());
};
auto zipWithA() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return [=](const boxed& ys) -> boxed {
                    return Data_Traversable::sequence()(Data_List_Types::traversableList())(dictApplicative)(Data_List::zipWith()(f)(xs)(ys));
                };
            };
        };
    };
    return _;
};
auto range() -> const boxed& {
    static const boxed _ = [](const boxed& start) -> boxed {
        return [=](const boxed& end) -> boxed {
            if (unbox<bool>(unbox<int>(start) == unbox<int>(end))) {
                return Data_List::singleton()(start);
            };
            if (unbox<bool>(Data_Boolean::otherwise())) {
                boxed::recur go;
                boxed::recur::weak go_Weak_(go);
                go = [=](const boxed& s) -> boxed {
                    boxed go = go_Weak_;
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& step) -> boxed {
                            return [=](const boxed& rest) -> boxed {
                                if (unbox<bool>(unbox<int>(s) == unbox<int>(e))) {
                                    return Data_List_Types::Cons()(s)(rest);
                                };
                                return go(unbox<int>(s) + unbox<int>(step))(e)(step)(Data_List_Types::Cons()(s)(rest));
                            };
                        };
                    };
                };
                return go(end)(start)([=]() -> boxed {
                    boxed _Local_104 = Data_Ord::greaterThan()(Data_Ord::ordInt())(start)(end);
                    if (unbox<bool>(_Local_104)) {
                        return 1;
                    };
                    return -1;
                }())(Data_List_Types::Nil());
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 144, column 1 - line 144, column 32): ");
        };
    };
    return _;
};
auto partition() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& xs) -> boxed {
            boxed select = [=](const boxed& x) -> boxed {
                return [=](const boxed& v) -> boxed {
                    boxed _Local_107 = p(x);
                    if (unbox<bool>(_Local_107)) {
                        return dict_t{
                            { "no", v["no"] },
                            { "yes", Data_List_Types::Cons()(x)(v["yes"]) }
                        };
                    };
                    return dict_t{
                        { "no", Data_List_Types::Cons()(x)(v["no"]) },
                        { "yes", v["yes"] }
                    };
                };
            };
            return Data_Foldable::foldr()(Data_List_Types::foldableList())(select)(dict_t{
                { "no", Data_List_Types::Nil() },
                { "yes", Data_List_Types::Nil() }
            })(xs);
        };
    };
    return _;
};
auto null() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Nil")) {
            return true;
        };
        return false;
    };
    return _;
};
auto newtypePattern() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_List::Pattern());
};
auto mapWithIndex() -> boxed {
    return Data_FunctorWithIndex::mapWithIndex()(Data_List_Types::functorWithIndexList());
};
auto mapMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& acc) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Nil")) {
                    return Data_List::reverse()(acc);
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    boxed v1 = f(v["value0"]);
                    if (unbox<dict_t>(v1).contains("Nothing")) {
                        return go(acc)(v["value1"]);
                    };
                    if (unbox<dict_t>(v1).contains("Just")) {
                        return go(Data_List_Types::Cons()(v1["value0"])(acc))(v["value1"]);
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 419, column 5 - line 421, column 32): ");
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 417, column 3 - line 417, column 27): ");
            };
        };
        return go(Data_List_Types::Nil());
    };
    return _;
};
auto manyRec() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictAlternative) -> boxed {
            return [=](const boxed& p) -> boxed {
                boxed go = [=](const boxed& acc) -> boxed {
                    return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))(Control_Alt::alt()(dictAlternative["Plus1"](undefined)["Alt0"](undefined))(Data_Functor::map()(dictAlternative["Plus1"](undefined)["Alt0"](undefined)["Functor0"](undefined))(Control_Monad_Rec_Class::Loop())(p))(Control_Applicative::pure()(dictAlternative["Applicative0"](undefined))(Control_Monad_Rec_Class::Done()(Data_Unit::unit()))))([=](const boxed& v) -> boxed {
                        return Control_Applicative::pure()(dictAlternative["Applicative0"](undefined))(Data_Bifunctor::bimap()(Control_Monad_Rec_Class::bifunctorStep())([=](const boxed& v1) -> boxed {
                            return Data_List_Types::Cons()(v1)(acc);
                        })([=](const boxed& v1) -> boxed {
                            return Data_List::reverse()(acc);
                        })(v));
                    });
                };
                return Control_Monad_Rec_Class::tailRecM()(dictMonadRec)(go)(Data_List_Types::Nil());
            };
        };
    };
    return _;
};
auto someRec() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictAlternative) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Apply::apply()(dictAlternative["Applicative0"](undefined)["Apply0"](undefined))(Data_Functor::map()(dictAlternative["Plus1"](undefined)["Alt0"](undefined)["Functor0"](undefined))(Data_List_Types::Cons())(v))(Data_List::manyRec()(dictMonadRec)(dictAlternative)(v));
            };
        };
    };
    return _;
};
auto some() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlternative) -> boxed {
        return [=](const boxed& dictLazy) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Apply::apply()(dictAlternative["Applicative0"](undefined)["Apply0"](undefined))(Data_Functor::map()(dictAlternative["Plus1"](undefined)["Alt0"](undefined)["Functor0"](undefined))(Data_List_Types::Cons())(v))(Control_Lazy::defer()(dictLazy)([=](const boxed& v1) -> boxed {
                    return Data_List::many()(dictAlternative)(dictLazy)(v);
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
                return Control_Alt::alt()(dictAlternative["Plus1"](undefined)["Alt0"](undefined))(Data_List::some()(dictAlternative)(dictLazy)(v))(Control_Applicative::pure()(dictAlternative["Applicative0"](undefined))(Data_List_Types::Nil()));
            };
        };
    };
    return _;
};
auto length() -> boxed {
    return Data_Foldable::foldl()(Data_List_Types::foldableList())([=](const boxed& acc) -> boxed {
        return [=](const boxed& v) -> boxed {
            return unbox<int>(acc) + 1;
        };
    })(0);
};
auto last() -> const boxed& {
    static const boxed _ = [](const boxed& _TCO_Copy_v_) -> boxed {
        boxed _TCO_v_;
        _TCO_v_ = _TCO_Copy_v_;
        bool _TCO_Done_ = false;
        boxed _TCO_Result_;
        const auto _TCO_Loop_ = [&](const boxed v) -> boxed {
            if (unbox<dict_t>(v).contains("Cons")) {
                if (unbox<dict_t>(v["value1"]).contains("Nil")) {
                    _TCO_Done_ = true;
                    return Data_Maybe::Just()(v["value0"]);
                };
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                _TCO_v_ = v["value1"];
                return undefined;
            };
            _TCO_Done_ = true;
            return Data_Maybe::Nothing();
        };
        while (!(_TCO_Done_)) {
            _TCO_Result_ = _TCO_Loop_(_TCO_v_);
        };
        return _TCO_Result_;
    };
    return _;
};
auto insertBy() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Nil")) {
                    return Data_List::singleton()(x);
                };
                if (unbox<dict_t>(v1).contains("Cons")) {
                    boxed v2 = v(x)(v1["value0"]);
                    if (unbox<dict_t>(v2).contains("GT")) {
                        return Data_List_Types::Cons()(v1["value0"])(Data_List::insertBy()(v)(x)(v1["value1"]));
                    };
                    return Data_List_Types::Cons()(x)(v1);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 216, column 1 - line 216, column 68): ");
            };
        };
    };
    return _;
};
auto insertAt() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<int>(v) == 0) {
                    return Data_Maybe::Just()(Data_List_Types::Cons()(v1)(v2));
                };
                if (unbox<dict_t>(v2).contains("Cons")) {
                    return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v3) -> boxed {
                        return Data_List_Types::Cons()(v2["value0"])(v3);
                    })(Data_List::insertAt()(unbox<int>(v) - 1)(v1)(v2["value1"]));
                };
                return Data_Maybe::Nothing();
            };
        };
    };
    return _;
};
auto insert() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_List::insertBy()(Data_Ord::compare()(dictOrd));
    };
    return _;
};
auto init() -> const boxed& {
    static const boxed _ = [](const boxed& lst) -> boxed {
        return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v) -> boxed {
            return v["init"];
        })(Data_List::unsnoc()(lst));
    };
    return _;
};
auto index() -> const boxed& {
    static const boxed _ = [](const boxed& _TCO_Copy_v_) -> boxed {
        return [=](const boxed& _TCO_Copy_v1_) -> boxed {
            boxed _TCO_v_;
            _TCO_v_ = _TCO_Copy_v_;
            boxed _TCO_v1_;
            _TCO_v1_ = _TCO_Copy_v1_;
            bool _TCO_Done_ = false;
            boxed _TCO_Result_;
            const auto _TCO_Loop_ = [&](const boxed v, const boxed v1) -> boxed {
                if (unbox<dict_t>(v).contains("Nil")) {
                    _TCO_Done_ = true;
                    return Data_Maybe::Nothing();
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    if (unbox<int>(v1) == 0) {
                        _TCO_Done_ = true;
                        return Data_Maybe::Just()(v["value0"]);
                    };
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    _TCO_v_ = v["value1"];
                    _TCO_v1_ = unbox<int>(v1) - 1;
                    return undefined;
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 281, column 1 - line 281, column 44): ");
            };
            while (!(_TCO_Done_)) {
                _TCO_Result_ = _TCO_Loop_(_TCO_v_, _TCO_v1_);
            };
            return _TCO_Result_;
        };
    };
    return _;
};
auto head() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Nil")) {
            return Data_Maybe::Nothing();
        };
        if (unbox<dict_t>(v).contains("Cons")) {
            return Data_Maybe::Just()(v["value0"]);
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 230, column 1 - line 230, column 22): ");
    };
    return _;
};
auto transpose() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Nil")) {
            return Data_List_Types::Nil();
        };
        if (unbox<dict_t>(v).contains("Cons")) {
            if (unbox<dict_t>(v["value0"]).contains("Nil")) {
                return Data_List::transpose()(v["value1"]);
            };
        };
        if (unbox<dict_t>(v).contains("Cons")) {
            if (unbox<dict_t>(v["value0"]).contains("Cons")) {
                return Data_List_Types::Cons()(Data_List_Types::Cons()(v["value0"]["value0"])(Data_List::mapMaybe()(Data_List::head())(v["value1"])))(Data_List::transpose()(Data_List_Types::Cons()(v["value0"]["value1"])(Data_List::mapMaybe()(Data_List::tail())(v["value1"]))));
            };
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 752, column 1 - line 752, column 54): ");
    };
    return _;
};
auto groupBy() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v1).contains("Nil")) {
                return Data_List_Types::Nil();
            };
            if (unbox<dict_t>(v1).contains("Cons")) {
                boxed v2 = Data_List::span()(v(v1["value0"]))(v1["value1"]);
                return Data_List_Types::Cons()(Data_NonEmpty::NonEmpty()(v1["value0"])(v2["init"]))(Data_List::groupBy()(v)(v2["rest"]));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 605, column 1 - line 605, column 80): ");
        };
    };
    return _;
};
auto group() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List::groupBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto group_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List::group()(dictOrd["Eq0"](undefined)))(Data_List::sort()(dictOrd));
    };
    return _;
};
auto fromFoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Data_Foldable::foldr()(dictFoldable)(Data_List_Types::Cons())(Data_List_Types::Nil());
    };
    return _;
};
auto foldM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1).contains("Nil")) {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(a);
                    };
                    if (unbox<dict_t>(v1).contains("Cons")) {
                        return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v(a)(v1["value0"]))([=](const boxed& a_Prime_) -> boxed {
                            return Data_List::foldM()(dictMonad)(v)(a_Prime_)(v1["value1"]);
                        });
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 763, column 1 - line 763, column 72): ");
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
        go = [=](const boxed& v) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Cons")) {
                    if (unbox<bool>(fn(v1["value0"]))) {
                        return Data_Maybe::Just()(v);
                    };
                    return go(unbox<int>(v) + 1)(v1["value1"]);
                };
                if (unbox<dict_t>(v1).contains("Nil")) {
                    return Data_Maybe::Nothing();
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 301, column 3 - line 301, column 35): ");
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
                return unbox<int>(unbox<int>(Data_List::length()(xs)) - 1) - unbox<int>(v);
            })(Data_List::findIndex()(fn)(Data_List::reverse()(xs)));
        };
    };
    return _;
};
auto filterM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Nil")) {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_List_Types::Nil());
                };
                if (unbox<dict_t>(v1).contains("Cons")) {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(v(v1["value0"]))([=](const boxed& v2) -> boxed {
                        return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Data_List::filterM()(dictMonad)(v)(v1["value1"]))([=](const boxed& v3) -> boxed {
                            return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))([=]() -> boxed {
                                if (unbox<bool>(v2)) {
                                    return Data_List_Types::Cons()(v1["value0"])(v3);
                                };
                                return v3;
                            }());
                        });
                    });
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 403, column 1 - line 403, column 75): ");
            };
        };
    };
    return _;
};
auto filter() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& acc) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Nil")) {
                    return Data_List::reverse()(acc);
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    if (unbox<bool>(p(v["value0"]))) {
                        return go(Data_List_Types::Cons()(v["value0"])(acc))(v["value1"]);
                    };
                    return go(acc)(v["value1"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 390, column 3 - line 390, column 27): ");
            };
        };
        return go(Data_List_Types::Nil());
    };
    return _;
};
auto intersectBy() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<dict_t>(v1).contains("Nil")) {
                    return Data_List_Types::Nil();
                };
                if (unbox<dict_t>(v2).contains("Nil")) {
                    return Data_List_Types::Nil();
                };
                return Data_List::filter()([=](const boxed& x) -> boxed {
                    return Data_Foldable::any()(Data_List_Types::foldableList())(Data_HeytingAlgebra::heytingAlgebraBoolean())(v(x))(v2);
                })(v1);
            };
        };
    };
    return _;
};
auto intersect() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List::intersectBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto nubBy() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v1).contains("Nil")) {
                return Data_List_Types::Nil();
            };
            if (unbox<dict_t>(v1).contains("Cons")) {
                return Data_List_Types::Cons()(v1["value0"])(Data_List::nubBy()(v)(Data_List::filter()([=](const boxed& y) -> boxed {
                    return !unbox<bool>(v(v1["value0"])(y));
                })(v1["value1"])));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 644, column 1 - line 644, column 59): ");
        };
    };
    return _;
};
auto nub() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List::nubBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto eqPattern() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::Eq()([=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                return Data_Eq::eq()(Data_List_Types::eqList()(dictEq))(x)(y);
            };
        });
    };
    return _;
};
auto ordPattern() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord()([=](const boxed&) -> boxed {
            return Data_List::eqPattern()(dictOrd["Eq0"](undefined));
        })([=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                return Data_Ord::compare()(Data_List_Types::ordList()(dictOrd))(x)(y);
            };
        });
    };
    return _;
};
auto elemLastIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_List::findLastIndex()([=](const boxed& v) -> boxed {
                return Data_Eq::eq()(dictEq)(v)(x);
            });
        };
    };
    return _;
};
auto elemIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_List::findIndex()([=](const boxed& v) -> boxed {
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
                    return go(v["value1"]);
                };
            };
            return v;
        };
        return go;
    };
    return _;
};
auto dropEnd() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_List::take()(unbox<int>(Data_List::length()(xs)) - unbox<int>(n))(xs);
        };
    };
    return _;
};
auto drop() -> const boxed& {
    static const boxed _ = [](const boxed& _TCO_Copy_v_) -> boxed {
        return [=](const boxed& _TCO_Copy_v1_) -> boxed {
            boxed _TCO_v_;
            _TCO_v_ = _TCO_Copy_v_;
            boxed _TCO_v1_;
            _TCO_v1_ = _TCO_Copy_v1_;
            bool _TCO_Done_ = false;
            boxed _TCO_Result_;
            const auto _TCO_Loop_ = [&](const boxed v, const boxed v1) -> boxed {
                if (unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(v)(1))) {
                    _TCO_Done_ = true;
                    return v1;
                };
                if (unbox<dict_t>(v1).contains("Nil")) {
                    _TCO_Done_ = true;
                    return Data_List_Types::Nil();
                };
                if (unbox<dict_t>(v1).contains("Cons")) {
                    _TCO_v_ = unbox<int>(v) - 1;
                    _TCO_v1_ = v1["value1"];
                    return undefined;
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 543, column 1 - line 543, column 42): ");
            };
            while (!(_TCO_Done_)) {
                _TCO_Result_ = _TCO_Loop_(_TCO_v_, _TCO_v1_);
            };
            return _TCO_Result_;
        };
    };
    return _;
};
auto slice() -> const boxed& {
    static const boxed _ = [](const boxed& start) -> boxed {
        return [=](const boxed& end) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return Data_List::take()(unbox<int>(end) - unbox<int>(start))(Data_List::drop()(start)(xs));
            };
        };
    };
    return _;
};
auto takeEnd() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_List::drop()(unbox<int>(Data_List::length()(xs)) - unbox<int>(n))(xs);
        };
    };
    return _;
};
auto deleteBy() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<dict_t>(v2).contains("Nil")) {
                    return Data_List_Types::Nil();
                };
                if (unbox<dict_t>(v2).contains("Cons")) {
                    if (unbox<bool>(v(v1)(v2["value0"]))) {
                        return v2["value1"];
                    };
                };
                if (unbox<dict_t>(v2).contains("Cons")) {
                    return Data_List_Types::Cons()(v2["value0"])(Data_List::deleteBy()(v)(v1)(v2["value1"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 671, column 1 - line 671, column 67): ");
            };
        };
    };
    return _;
};
auto unionBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                return Data_Semigroup::append()(Data_List_Types::semigroupList())(xs)(Data_Foldable::foldl()(Data_List_Types::foldableList())(Data_Function::flip()(Data_List::deleteBy()(eq)))(Data_List::nubBy()(eq)(ys))(xs));
            };
        };
    };
    return _;
};
auto _union_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List::unionBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto deleteAt() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<int>(v) == 0) {
                if (unbox<dict_t>(v1).contains("Cons")) {
                    return Data_Maybe::Just()(v1["value1"]);
                };
            };
            if (unbox<dict_t>(v1).contains("Cons")) {
                return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v2) -> boxed {
                    return Data_List_Types::Cons()(v1["value0"])(v2);
                })(Data_List::deleteAt()(unbox<int>(v) - 1)(v1["value1"]));
            };
            return Data_Maybe::Nothing();
        };
    };
    return _;
};
auto _delete_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List::deleteBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto difference() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Foldable::foldl()(Data_List_Types::foldableList())(Data_Function::flip()(Data_List::_delete_()(dictEq)));
    };
    return _;
};
auto concatMap() -> boxed {
    return Data_Function::flip()(Control_Bind::bind()(Data_List_Types::bindList()));
};
auto concat() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Control_Bind::bind()(Data_List_Types::bindList())(v)(Control_Category::identity()(Control_Category::categoryFn()));
    };
    return _;
};
auto catMaybes() -> boxed {
    return Data_List::mapMaybe()(Control_Category::identity()(Control_Category::categoryFn()));
};
auto alterAt() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<int>(v) == 0) {
                    if (unbox<dict_t>(v2).contains("Cons")) {
                        return Data_Maybe::Just()([=]() -> boxed {
                            boxed v3 = v1(v2["value0"]);
                            if (unbox<dict_t>(v3).contains("Nothing")) {
                                return v2["value1"];
                            };
                            if (unbox<dict_t>(v3).contains("Just")) {
                                return Data_List_Types::Cons()(v3["value0"])(v2["value1"]);
                            };
                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List (line 352, column 3 - line 354, column 23): ");
                        }());
                    };
                };
                if (unbox<dict_t>(v2).contains("Cons")) {
                    return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v3) -> boxed {
                        return Data_List_Types::Cons()(v2["value0"])(v3);
                    })(Data_List::alterAt()(unbox<int>(v) - 1)(v1)(v2["value1"]));
                };
                return Data_Maybe::Nothing();
            };
        };
    };
    return _;
};
auto modifyAt() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_List::alterAt()(n)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::Just())(f));
        };
    };
    return _;
};


} // end namespace Data_List


