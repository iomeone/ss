#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Comonad/Control_Comonad.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_MonadPlus/Control_MonadPlus.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Control_Plus/Control_Plus.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_FoldableWithIndex/Data_FoldableWithIndex.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_NonEmpty/Data_NonEmpty.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_Semigroup_Traversable/Data_Semigroup_Traversable.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_TraversableWithIndex/Data_TraversableWithIndex.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Data_Unfoldable1/Data_Unfoldable1.h"
#include "Prelude/Prelude.h"

#include "Data_List_Types/Data_List_Types.h"


namespace Data_List_Types {

auto Nil() -> const boxed& {
    static const boxed _ = dict_t{
        { "Nil", true }
    };
    return _;
};
auto Cons() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "Cons", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto NonEmptyList() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto toList() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_List_Types::Cons()(v["value0"])(v["value1"]);
    };
    return _;
};
auto newtypeNonEmptyList() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_List_Types::NonEmptyList());
};
auto nelCons() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_NonEmpty::NonEmpty()(a)(Data_List_Types::Cons()(v["value0"])(v["value1"]));
        };
    };
    return _;
};
auto foldableList() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldl()(Data_List_Types::foldableList())([=](const boxed& acc) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(acc))(f);
            })(Data_Monoid::mempty()(dictMonoid));
        };
    })([=](const boxed& f) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& b) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Nil")) {
                    return b;
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    return go(f(b)(v["value0"]))(v["value1"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Types (line 81, column 12 - line 83, column 30): ");
            };
        };
        return go;
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            boxed rev = Data_Foldable::foldl()(Data_List_Types::foldableList())(Data_Function::flip()(Data_List_Types::Cons()))(Data_List_Types::Nil());
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Foldable::foldl()(Data_List_Types::foldableList())(Data_Function::flip()(f))(b))(rev);
        };
    });
};
auto foldableNonEmptyList() -> boxed {
    return Data_NonEmpty::foldableNonEmpty()(Data_List_Types::foldableList());
};
auto foldableWithIndexList() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Types::foldableList();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_FoldableWithIndex::foldlWithIndex()(Data_List_Types::foldableWithIndexList())([=](const boxed& i) -> boxed {
                return [=](const boxed& acc) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(acc))(f(i));
                };
            })(Data_Monoid::mempty()(dictMonoid));
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& acc) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Tuple::snd())(Data_Foldable::foldl()(Data_List_Types::foldableList())([=](const boxed& v) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Data_Tuple::Tuple()(unbox<int>(v["value0"]) + 1)(f(v["value0"])(v["value1"])(a));
                };
            })(Data_Tuple::Tuple()(0)(acc)));
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed v = [=]() -> boxed {
                    boxed rev = Data_Foldable::foldl()(Data_List_Types::foldableList())([=](const boxed& v1) -> boxed {
                        return [=](const boxed& a) -> boxed {
                            return Data_Tuple::Tuple()(unbox<int>(v1["value0"]) + 1)(Data_List_Types::Cons()(a)(v1["value1"]));
                        };
                    });
                    return rev(Data_Tuple::Tuple()(0)(Data_List_Types::Nil()))(xs);
                }();
                return Data_Tuple::snd()(Data_Foldable::foldl()(Data_List_Types::foldableList())([=](const boxed& v1) -> boxed {
                    return [=](const boxed& a) -> boxed {
                        return Data_Tuple::Tuple()(unbox<int>(v1["value0"]) - 1)(f(unbox<int>(v1["value0"]) - 1)(a)(v1["value1"]));
                    };
                })(Data_Tuple::Tuple()(v["value0"])(b))(v["value1"]));
            };
        };
    });
};
auto foldableWithIndexNonEmptyList() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Types::foldableNonEmptyList();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_FoldableWithIndex::foldMapWithIndex()(Data_NonEmpty::foldableWithIndexNonEmpty()(Data_List_Types::foldableWithIndexList()))(dictMonoid)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_FoldableWithIndex::foldlWithIndex()(Data_NonEmpty::foldableWithIndexNonEmpty()(Data_List_Types::foldableWithIndexList()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(b)(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_FoldableWithIndex::foldrWithIndex()(Data_NonEmpty::foldableWithIndexNonEmpty()(Data_List_Types::foldableWithIndexList()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(b)(v);
            };
        };
    });
};
auto functorList() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_List_Types::foldableList())([=](const boxed& x) -> boxed {
            return [=](const boxed& acc) -> boxed {
                return Data_List_Types::Cons()(f(x))(acc);
            };
        })(Data_List_Types::Nil());
    });
};
auto functorNonEmptyList() -> boxed {
    return Data_NonEmpty::functorNonEmpty()(Data_List_Types::functorList());
};
auto functorWithIndexList() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Types::functorList();
    })([=](const boxed& f) -> boxed {
        return Data_FoldableWithIndex::foldrWithIndex()(Data_List_Types::foldableWithIndexList())([=](const boxed& i) -> boxed {
            return [=](const boxed& x) -> boxed {
                return [=](const boxed& acc) -> boxed {
                    return Data_List_Types::Cons()(f(i)(x))(acc);
                };
            };
        })(Data_List_Types::Nil());
    });
};
auto functorWithIndexNonEmptyList() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Types::functorNonEmptyList();
    })([=](const boxed& fn) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_List_Types::NonEmptyList()(Data_FunctorWithIndex::mapWithIndex()(Data_NonEmpty::functorWithIndex()(Data_List_Types::functorWithIndexList()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(fn)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(v));
        };
    });
};
auto semigroupList() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& xs) -> boxed {
        return [=](const boxed& ys) -> boxed {
            return Data_Foldable::foldr()(Data_List_Types::foldableList())(Data_List_Types::Cons())(ys)(xs);
        };
    });
};
auto monoidList() -> boxed {
    return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
        return Data_List_Types::semigroupList();
    })(Data_List_Types::Nil());
};
auto semigroupNonEmptyList() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& as_Prime_) -> boxed {
            return Data_NonEmpty::NonEmpty()(v["value0"])(Data_Semigroup::append()(Data_List_Types::semigroupList())(v["value1"])(Data_List_Types::toList()(as_Prime_)));
        };
    });
};
auto showList() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Nil")) {
                return "Nil";
            };
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Foldable::intercalate()(Data_List_Types::foldableList())(Data_Monoid::monoidString())(" : ")(Data_Functor::map()(Data_List_Types::functorList())(Data_Show::show()(dictShow))(v)))(" : Nil)"));
        });
    };
    return _;
};
auto showNonEmptyList() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(NonEmptyList ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_NonEmpty::showNonEmpty()(dictShow)(Data_List_Types::showList()(dictShow)))(v))(")"));
        });
    };
    return _;
};
auto traversableList() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_List_Types::foldableList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::functorList();
    })([=](const boxed& dictApplicative) -> boxed {
        return Data_Traversable::traverse()(Data_List_Types::traversableList())(dictApplicative)(Control_Category::identity()(Control_Category::categoryFn()));
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Foldable::foldl()(Data_List_Types::foldableList())(Data_Function::flip()(Data_List_Types::Cons()))(Data_List_Types::Nil())))(Data_Foldable::foldl()(Data_List_Types::foldableList())([=](const boxed& acc) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Apply::lift2()(dictApplicative["Apply0"](undefined))(Data_Function::flip()(Data_List_Types::Cons()))(acc))(f);
            })(Control_Applicative::pure()(dictApplicative)(Data_List_Types::Nil())));
        };
    });
};
auto traversableNonEmptyList() -> boxed {
    return Data_NonEmpty::traversableNonEmpty()(Data_List_Types::traversableList());
};
auto traversableWithIndexList() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Types::foldableWithIndexList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::functorWithIndexList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::traversableList();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed rev = Data_Foldable::foldl()(Data_List_Types::foldableList())(Data_Function::flip()(Data_List_Types::Cons()))(Data_List_Types::Nil());
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(rev))(Data_FoldableWithIndex::foldlWithIndex()(Data_List_Types::foldableWithIndexList())([=](const boxed& i) -> boxed {
                return [=](const boxed& acc) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Apply::lift2()(dictApplicative["Apply0"](undefined))(Data_Function::flip()(Data_List_Types::Cons()))(acc))(f(i));
                };
            })(Control_Applicative::pure()(dictApplicative)(Data_List_Types::Nil())));
        };
    });
};
auto traversableWithIndexNonEmptyList() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Types::foldableWithIndexNonEmptyList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::functorWithIndexNonEmptyList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::traversableNonEmptyList();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_List_Types::NonEmptyList())(Data_TraversableWithIndex::traverseWithIndex()(Data_NonEmpty::traversableWithIndexNonEmpty()(Data_List_Types::traversableWithIndexList()))(dictApplicative)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(v));
            };
        };
    });
};
auto unfoldable1List() -> boxed {
    return Data_Unfoldable1::Unfoldable1()([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            boxed::recur go;
            boxed::recur::weak go_Weak_(go);
            go = [=](const boxed& source) -> boxed {
                boxed go = go_Weak_;
                return [=](const boxed& memo) -> boxed {
                    boxed v = f(source);
                    if (unbox<dict_t>(v["value1"]).contains("Just")) {
                        return go(v["value1"]["value0"])(Data_List_Types::Cons()(v["value0"])(memo));
                    };
                    if (unbox<dict_t>(v["value1"]).contains("Nothing")) {
                        return Data_Foldable::foldl()(Data_List_Types::foldableList())(Data_Function::flip()(Data_List_Types::Cons()))(Data_List_Types::Nil())(Data_List_Types::Cons()(v["value0"])(memo));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Types (line 105, column 22 - line 107, column 61): ");
                };
            };
            return go(b)(Data_List_Types::Nil());
        };
    });
};
auto unfoldableList() -> boxed {
    return Data_Unfoldable::Unfoldable()([=](const boxed&) -> boxed {
        return Data_List_Types::unfoldable1List();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            boxed::recur go;
            boxed::recur::weak go_Weak_(go);
            go = [=](const boxed& source) -> boxed {
                boxed go = go_Weak_;
                return [=](const boxed& memo) -> boxed {
                    boxed v = f(source);
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Data_Foldable::foldl()(Data_List_Types::foldableList())(Data_Function::flip()(Data_List_Types::Cons()))(Data_List_Types::Nil())(memo);
                    };
                    if (unbox<dict_t>(v).contains("Just")) {
                        return go(v["value0"]["value1"])(Data_List_Types::Cons()(v["value0"]["value0"])(memo));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Types (line 112, column 22 - line 114, column 52): ");
                };
            };
            return go(b)(Data_List_Types::Nil());
        };
    });
};
auto unfoldable1NonEmptyList() -> boxed {
    return Data_NonEmpty::unfoldable1NonEmpty()(Data_List_Types::unfoldableList());
};
auto foldable1NonEmptyList() -> boxed {
    return Data_NonEmpty::foldable1NonEmpty()(Data_List_Types::foldableList());
};
auto extendNonEmptyList() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_List_Types::functorNonEmptyList();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            boxed go = [=](const boxed& a) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return dict_t{
                        { "val", Data_List_Types::Cons()(f(Data_NonEmpty::NonEmpty()(a)(v1["acc"])))(v1["val"]) },
                        { "acc", Data_List_Types::Cons()(a)(v1["acc"]) }
                    };
                };
            };
            return Data_NonEmpty::NonEmpty()(f(v))(Data_Foldable::foldr()(Data_List_Types::foldableList())(go)(dict_t{
                { "val", Data_List_Types::Nil() },
                { "acc", Data_List_Types::Nil() }
            })(v["value1"])["val"]);
        };
    });
};
auto extendList() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_List_Types::functorList();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Nil")) {
                return Data_List_Types::Nil();
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                boxed go = [=](const boxed& a_Prime_) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        boxed acc_Prime_ = Data_List_Types::Cons()(a_Prime_)(v1["acc"]);
                        return dict_t{
                            { "val", Data_List_Types::Cons()(f(acc_Prime_))(v1["val"]) },
                            { "acc", acc_Prime_ }
                        };
                    };
                };
                return Data_List_Types::Cons()(f(v))(Data_Foldable::foldr()(Data_List_Types::foldableList())(go)(dict_t{
                    { "val", Data_List_Types::Nil() },
                    { "acc", Data_List_Types::Nil() }
                })(v["value1"])["val"]);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Types (line 152, column 1 - line 152, column 35): ");
        };
    });
};
auto eq1List() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                boxed::recur go;
                boxed::recur::weak go_Weak_(go);
                go = [=](const boxed& v) -> boxed {
                    boxed go = go_Weak_;
                    return [=](const boxed& v1) -> boxed {
                        return [=](const boxed& v2) -> boxed {
                            if (!(unbox<bool>(v2))) {
                                return false;
                            };
                            if (unbox<dict_t>(v).contains("Nil")) {
                                if (unbox<dict_t>(v1).contains("Nil")) {
                                    return v2;
                                };
                            };
                            if (unbox<dict_t>(v).contains("Cons")) {
                                if (unbox<dict_t>(v1).contains("Cons")) {
                                    return go(v["value1"])(v1["value1"])(unbox<bool>(v2) && unbox<bool>(Data_Eq::eq()(dictEq)(v1["value0"])(v["value0"])));
                                };
                            };
                            return false;
                        };
                    };
                };
                return go(xs)(ys)(true);
            };
        };
    });
};
auto eqList() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::Eq()(Data_Eq::eq1()(Data_List_Types::eq1List())(dictEq));
    };
    return _;
};
auto eqNonEmptyList() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_NonEmpty::eqNonEmpty()(Data_List_Types::eq1List())(dictEq);
    };
    return _;
};
auto ord1List() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_List_Types::eq1List();
    })([=](const boxed& dictOrd) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                boxed::recur go;
                boxed::recur::weak go_Weak_(go);
                go = [=](const boxed& v) -> boxed {
                    boxed go = go_Weak_;
                    return [=](const boxed& v1) -> boxed {
                        if (unbox<dict_t>(v).contains("Nil")) {
                            if (unbox<dict_t>(v1).contains("Nil")) {
                                return Data_Ordering::EQ();
                            };
                        };
                        if (unbox<dict_t>(v).contains("Nil")) {
                            return Data_Ordering::LT();
                        };
                        if (unbox<dict_t>(v1).contains("Nil")) {
                            return Data_Ordering::GT();
                        };
                        if (unbox<dict_t>(v).contains("Cons")) {
                            if (unbox<dict_t>(v1).contains("Cons")) {
                                boxed v2 = Data_Ord::compare()(dictOrd)(v["value0"])(v1["value0"]);
                                if (unbox<dict_t>(v2).contains("EQ")) {
                                    return go(v["value1"])(v1["value1"]);
                                };
                                return v2;
                            };
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Types (line 55, column 5 - line 55, column 20): ");
                    };
                };
                return go(xs)(ys);
            };
        };
    });
};
auto ordList() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord()([=](const boxed&) -> boxed {
            return Data_List_Types::eqList()(dictOrd["Eq0"](undefined));
        })(Data_Ord::compare1()(Data_List_Types::ord1List())(dictOrd));
    };
    return _;
};
auto ordNonEmptyList() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_NonEmpty::ordNonEmpty()(Data_List_Types::ord1List())(dictOrd);
    };
    return _;
};
auto comonadNonEmptyList() -> boxed {
    return Control_Comonad::Comonad()([=](const boxed&) -> boxed {
        return Data_List_Types::extendNonEmptyList();
    })([=](const boxed& v) -> boxed {
        return v["value0"];
    });
};
auto applyList() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_List_Types::functorList();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Nil")) {
                return Data_List_Types::Nil();
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                return Data_Semigroup::append()(Data_List_Types::semigroupList())(Data_Functor::map()(Data_List_Types::functorList())(v["value0"])(v1))(Control_Apply::apply()(Data_List_Types::applyList())(v["value1"])(v1));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Types (line 127, column 1 - line 127, column 33): ");
        };
    });
};
auto applyNonEmptyList() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_List_Types::functorNonEmptyList();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_NonEmpty::NonEmpty()(v["value0"](v1["value0"]))(Data_Semigroup::append()(Data_List_Types::semigroupList())(Control_Apply::apply()(Data_List_Types::applyList())(v["value1"])(Data_List_Types::Cons()(v1["value0"])(Data_List_Types::Nil())))(Control_Apply::apply()(Data_List_Types::applyList())(Data_List_Types::Cons()(v["value0"])(v["value1"]))(v1["value1"])));
        };
    });
};
auto bindList() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_List_Types::applyList();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Nil")) {
                return Data_List_Types::Nil();
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                return Data_Semigroup::append()(Data_List_Types::semigroupList())(v1(v["value0"]))(Control_Bind::bind()(Data_List_Types::bindList())(v["value1"])(v1));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Types (line 134, column 1 - line 134, column 31): ");
        };
    });
};
auto bindNonEmptyList() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_List_Types::applyNonEmptyList();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed v1 = f(v["value0"]);
            return Data_NonEmpty::NonEmpty()(v1["value0"])(Data_Semigroup::append()(Data_List_Types::semigroupList())(v1["value1"])(Control_Bind::bind()(Data_List_Types::bindList())(v["value1"])(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Types::toList())(f))));
        };
    });
};
auto applicativeList() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_List_Types::applyList();
    })([=](const boxed& a) -> boxed {
        return Data_List_Types::Cons()(a)(Data_List_Types::Nil());
    });
};
auto monadList() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_List_Types::applicativeList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::bindList();
    });
};
auto altNonEmptyList() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_List_Types::functorNonEmptyList();
    })(Data_Semigroup::append()(Data_List_Types::semigroupNonEmptyList()));
};
auto altList() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_List_Types::functorList();
    })(Data_Semigroup::append()(Data_List_Types::semigroupList()));
};
auto plusList() -> boxed {
    return Control_Plus::Plus()([=](const boxed&) -> boxed {
        return Data_List_Types::altList();
    })(Data_List_Types::Nil());
};
auto alternativeList() -> boxed {
    return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
        return Data_List_Types::applicativeList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::plusList();
    });
};
auto monadZeroList() -> boxed {
    return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
        return Data_List_Types::alternativeList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::monadList();
    });
};
auto monadPlusList() -> boxed {
    return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
        return Data_List_Types::monadZeroList();
    });
};
auto applicativeNonEmptyList() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_List_Types::applyNonEmptyList();
    })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Types::NonEmptyList())(Data_NonEmpty::singleton()(Data_List_Types::plusList())));
};
auto monadNonEmptyList() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_List_Types::applicativeNonEmptyList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::bindNonEmptyList();
    });
};
auto traversable1NonEmptyList() -> boxed {
    return Data_Semigroup_Traversable::Traversable1()([=](const boxed&) -> boxed {
        return Data_List_Types::foldable1NonEmptyList();
    })([=](const boxed&) -> boxed {
        return Data_List_Types::traversableNonEmptyList();
    })([=](const boxed& dictApply) -> boxed {
        return Data_Semigroup_Traversable::traverse1()(Data_List_Types::traversable1NonEmptyList())(dictApply)(Control_Category::identity()(Control_Category::categoryFn()));
    })([=](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::mapFlipped()(dictApply["Functor0"](undefined))(Data_Foldable::foldl()(Data_List_Types::foldableList())([=](const boxed& acc) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Apply::lift2()(dictApply)(Data_Function::flip()(Data_List_Types::nelCons()))(acc))(f);
                })(Data_Functor::map()(dictApply["Functor0"](undefined))(Control_Applicative::pure()(Data_List_Types::applicativeNonEmptyList()))(f(v["value0"])))(v["value1"]))([=](const boxed& v1) -> boxed {
                    return Data_Foldable::foldl()(Data_List_Types::foldableList())(Data_Function::flip()(Data_List_Types::nelCons()))(Control_Applicative::pure()(Data_List_Types::applicativeNonEmptyList())(v1["value0"]))(v1["value1"]);
                });
            };
        };
    });
};


} // end namespace Data_List_Types


