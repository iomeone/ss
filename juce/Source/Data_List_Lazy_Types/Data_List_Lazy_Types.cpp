#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Comonad/Control_Comonad.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Lazy/Control_Lazy.h"
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
#include "Data_Lazy/Data_Lazy.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_NonEmpty/Data_NonEmpty.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_TraversableWithIndex/Data_TraversableWithIndex.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Data_Unfoldable1/Data_Unfoldable1.h"
#include "Prelude/Prelude.h"

#include "Data_List_Lazy_Types/Data_List_Lazy_Types.h"


namespace Data_List_Lazy_Types {

auto List() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
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
auto nil() -> boxed {
    return Data_List_Lazy_Types::List()(Data_Lazy::defer()([=](const boxed& v) -> boxed {
        return Data_List_Lazy_Types::Nil();
    }));
};
auto newtypeNonEmptyList() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_List_Lazy_Types::NonEmptyList());
};
auto newtypeList() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_List_Lazy_Types::List());
};
auto step() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Lazy::force())(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList()));
};
auto semigroupList() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& xs) -> boxed {
        return [=](const boxed& ys) -> boxed {
            boxed go = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Nil")) {
                    return Data_List_Lazy_Types::step()(ys);
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    return Data_List_Lazy_Types::Cons()(v["value0"])(Data_Semigroup::append()(Data_List_Lazy_Types::semigroupList())(v["value1"])(ys));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.Types (line 98, column 5 - line 98, column 21): ");
            };
            return Data_Functor::map()(Data_Lazy::functorLazy())(go)(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
        };
    });
};
auto showList() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& xs) -> boxed {
            boxed::recur go;
            boxed::recur::weak go_Weak_(go);
            go = [=](const boxed& v) -> boxed {
                boxed go = go_Weak_;
                if (unbox<dict_t>(v).contains("Nil")) {
                    return "Nil";
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Cons ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v["value0"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(go(Data_List_Lazy_Types::step()(v["value1"])))(")"))));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.Types (line 64, column 5 - line 65, column 5): ");
            };
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("fromStrict (")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(go(Data_List_Lazy_Types::step()(xs)))(")"));
        });
    };
    return _;
};
auto showNonEmptyList() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(NonEmptyList ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Lazy::showLazy()(Data_NonEmpty::showNonEmpty()(dictShow)(Data_List_Lazy_Types::showList()(dictShow))))(v))(")"));
        });
    };
    return _;
};
auto monoidList() -> boxed {
    return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::semigroupList();
    })(Data_List_Lazy_Types::nil());
};
auto lazyList() -> boxed {
    return Control_Lazy::Lazy()([=](const boxed& f) -> boxed {
        return Data_List_Lazy_Types::List()(Data_Lazy::defer()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::step())(f)));
    });
};
auto functorList() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& xs) -> boxed {
            boxed go = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Nil")) {
                    return Data_List_Lazy_Types::Nil();
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    return Data_List_Lazy_Types::Cons()(f(v["value0"]))(Data_Functor::map()(Data_List_Lazy_Types::functorList())(f)(v["value1"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.Types (line 107, column 5 - line 107, column 17): ");
            };
            return Data_Functor::map()(Data_Lazy::functorLazy())(go)(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
        };
    });
};
auto functorNonEmptyList() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(Data_Lazy::functorLazy())(Data_Functor::map()(Data_NonEmpty::functorNonEmpty()(Data_List_Lazy_Types::functorList()))(f))(v);
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
                        if (unbox<dict_t>(v).contains("Nil")) {
                            if (unbox<dict_t>(v1).contains("Nil")) {
                                return true;
                            };
                        };
                        if (unbox<dict_t>(v).contains("Cons")) {
                            if (unbox<dict_t>(v1).contains("Cons")) {
                                if (unbox<bool>(Data_Eq::eq()(dictEq)(v["value0"])(v1["value0"]))) {
                                    return go(Data_List_Lazy_Types::step()(v["value1"]))(Data_List_Lazy_Types::step()(v1["value1"]));
                                };
                            };
                        };
                        return false;
                    };
                };
                return go(Data_List_Lazy_Types::step()(xs))(Data_List_Lazy_Types::step()(ys));
            };
        };
    });
};
auto eqList() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::Eq()(Data_Eq::eq1()(Data_List_Lazy_Types::eq1List())(dictEq));
    };
    return _;
};
auto eqNonEmptyList() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Lazy::eqLazy()(Data_NonEmpty::eqNonEmpty()(Data_List_Lazy_Types::eq1List())(dictEq));
    };
    return _;
};
auto ord1List() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::eq1List();
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
                                    return go(Data_List_Lazy_Types::step()(v["value1"]))(Data_List_Lazy_Types::step()(v1["value1"]));
                                };
                                return v2;
                            };
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.Types (line 84, column 5 - line 84, column 20): ");
                    };
                };
                return go(Data_List_Lazy_Types::step()(xs))(Data_List_Lazy_Types::step()(ys));
            };
        };
    });
};
auto ordList() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord()([=](const boxed&) -> boxed {
            return Data_List_Lazy_Types::eqList()(dictOrd["Eq0"](undefined));
        })(Data_Ord::compare1()(Data_List_Lazy_Types::ord1List())(dictOrd));
    };
    return _;
};
auto ordNonEmptyList() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Lazy::ordLazy()(Data_NonEmpty::ordNonEmpty()(Data_List_Lazy_Types::ord1List())(dictOrd));
    };
    return _;
};
auto cons() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_List_Lazy_Types::List()(Data_Lazy::defer()([=](const boxed& v) -> boxed {
                return Data_List_Lazy_Types::Cons()(x)(xs);
            }));
        };
    };
    return _;
};
auto foldableList() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())([=](const boxed& b) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(b)(f(a));
                };
            })(Data_Monoid::mempty()(dictMonoid));
        };
    })([=](const boxed& op) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& b) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& xs) -> boxed {
                boxed v = Data_List_Lazy_Types::step()(xs);
                if (unbox<dict_t>(v).contains("Nil")) {
                    return b;
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    return go(op(b)(v["value0"]))(v["value1"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.Types (line 122, column 7 - line 124, column 40): ");
            };
        };
        return go;
    })([=](const boxed& op) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed rev = Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())(Data_Function::flip()(Data_List_Lazy_Types::cons()))(Data_List_Lazy_Types::nil());
                return Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())(Data_Function::flip()(op))(z)(rev(xs));
            };
        };
    });
};
auto extendList() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorList();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& l) -> boxed {
            boxed go = [=](const boxed& a) -> boxed {
                return [=](const boxed& v) -> boxed {
                    boxed acc_Prime_ = Data_List_Lazy_Types::cons()(a)(v["acc"]);
                    return dict_t{
                        { "val", Data_List_Lazy_Types::cons()(f(acc_Prime_))(v["val"]) },
                        { "acc", acc_Prime_ }
                    };
                };
            };
            boxed v = Data_List_Lazy_Types::step()(l);
            if (unbox<dict_t>(v).contains("Nil")) {
                return Data_List_Lazy_Types::nil();
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                return Data_List_Lazy_Types::cons()(f(l))(Data_Foldable::foldr()(Data_List_Lazy_Types::foldableList())(go)(dict_t{
                    { "val", Data_List_Lazy_Types::nil() },
                    { "acc", Data_List_Lazy_Types::nil() }
                })(v["value1"])["val"]);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.Types (line 194, column 5 - line 197, column 55): ");
        };
    });
};
auto extendNonEmptyList() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorNonEmptyList();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            boxed go = [=](const boxed& a) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return dict_t{
                        { "val", Data_List_Lazy_Types::cons()(f(Data_Lazy::defer()([=](const boxed& v2) -> boxed {
                            return Data_NonEmpty::NonEmpty()(a)(v1["acc"]);
                        })))(v1["val"]) },
                        { "acc", Data_List_Lazy_Types::cons()(a)(v1["acc"]) }
                    };
                };
            };
            boxed v1 = Data_Lazy::force()(v);
            return Data_List_Lazy_Types::NonEmptyList()(Data_Lazy::defer()([=](const boxed& v2) -> boxed {
                return Data_NonEmpty::NonEmpty()(f(v))(Data_Foldable::foldr()(Data_List_Lazy_Types::foldableList())(go)(dict_t{
                    { "val", Data_List_Lazy_Types::nil() },
                    { "acc", Data_List_Lazy_Types::nil() }
                })(v1["value1"])["val"]);
            }));
        };
    });
};
auto foldableNonEmptyList() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldMap()(Data_NonEmpty::foldableNonEmpty()(Data_List_Lazy_Types::foldableList()))(dictMonoid)(f)(Data_Lazy::force()(v));
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldl()(Data_NonEmpty::foldableNonEmpty()(Data_List_Lazy_Types::foldableList()))(f)(b)(Data_Lazy::force()(v));
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldr()(Data_NonEmpty::foldableNonEmpty()(Data_List_Lazy_Types::foldableList()))(f)(b)(Data_Lazy::force()(v));
            };
        };
    });
};
auto foldableWithIndexList() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::foldableList();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_FoldableWithIndex::foldlWithIndex()(Data_List_Lazy_Types::foldableWithIndexList())([=](const boxed& i) -> boxed {
                return [=](const boxed& acc) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(acc))(f(i));
                };
            })(Data_Monoid::mempty()(dictMonoid));
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& acc) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Tuple::snd())(Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())([=](const boxed& v) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Data_Tuple::Tuple()(unbox<int>(v["value0"]) + 1)(f(v["value0"])(v["value1"])(a));
                };
            })(Data_Tuple::Tuple()(0)(acc)));
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed v = [=]() -> boxed {
                    boxed rev = Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())([=](const boxed& v1) -> boxed {
                        return [=](const boxed& a) -> boxed {
                            return Data_Tuple::Tuple()(unbox<int>(v1["value0"]) + 1)(Data_List_Lazy_Types::cons()(a)(v1["value1"]));
                        };
                    });
                    return rev(Data_Tuple::Tuple()(0)(Data_List_Lazy_Types::nil()))(xs);
                }();
                return Data_Tuple::snd()(Data_Foldable::foldl()(Data_List_Lazy_Types::foldableList())([=](const boxed& v1) -> boxed {
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
        return Data_List_Lazy_Types::foldableNonEmptyList();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_FoldableWithIndex::foldMapWithIndex()(Data_NonEmpty::foldableWithIndexNonEmpty()(Data_List_Lazy_Types::foldableWithIndexList()))(dictMonoid)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(Data_Lazy::force()(v));
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_FoldableWithIndex::foldlWithIndex()(Data_NonEmpty::foldableWithIndexNonEmpty()(Data_List_Lazy_Types::foldableWithIndexList()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(b)(Data_Lazy::force()(v));
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_FoldableWithIndex::foldrWithIndex()(Data_NonEmpty::foldableWithIndexNonEmpty()(Data_List_Lazy_Types::foldableWithIndexList()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(b)(Data_Lazy::force()(v));
            };
        };
    });
};
auto functorWithIndexList() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorList();
    })([=](const boxed& f) -> boxed {
        return Data_FoldableWithIndex::foldrWithIndex()(Data_List_Lazy_Types::foldableWithIndexList())([=](const boxed& i) -> boxed {
            return [=](const boxed& x) -> boxed {
                return [=](const boxed& acc) -> boxed {
                    return Data_List_Lazy_Types::cons()(f(i)(x))(acc);
                };
            };
        })(Data_List_Lazy_Types::nil());
    });
};
auto functorWithIndexNonEmptyList() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorNonEmptyList();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_List_Lazy_Types::NonEmptyList()(Data_Lazy::defer()([=](const boxed& v1) -> boxed {
                return Data_FunctorWithIndex::mapWithIndex()(Data_NonEmpty::functorWithIndex()(Data_List_Lazy_Types::functorWithIndexList()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(Data_Lazy::force()(v));
            }));
        };
    });
};
auto toList() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Control_Lazy::defer()(Data_List_Lazy_Types::lazyList())([=](const boxed& v1) -> boxed {
            boxed v2 = Data_Lazy::force()(v);
            return Data_List_Lazy_Types::cons()(v2["value0"])(v2["value1"]);
        });
    };
    return _;
};
auto semigroupNonEmptyList() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& as_Prime_) -> boxed {
            boxed v1 = Data_Lazy::force()(v);
            return Data_Lazy::defer()([=](const boxed& v2) -> boxed {
                return Data_NonEmpty::NonEmpty()(v1["value0"])(Data_Semigroup::append()(Data_List_Lazy_Types::semigroupList())(v1["value1"])(Data_List_Lazy_Types::toList()(as_Prime_)));
            });
        };
    });
};
auto traversableList() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::foldableList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorList();
    })([=](const boxed& dictApplicative) -> boxed {
        return Data_Traversable::traverse()(Data_List_Lazy_Types::traversableList())(dictApplicative)(Control_Category::identity()(Control_Category::categoryFn()));
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldr()(Data_List_Lazy_Types::foldableList())([=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_List_Lazy_Types::cons())(f(a)))(b);
                };
            })(Control_Applicative::pure()(dictApplicative)(Data_List_Lazy_Types::nil()));
        };
    });
};
auto traversableNonEmptyList() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::foldableNonEmptyList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorNonEmptyList();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))([=](const boxed& xxs) -> boxed {
                return Data_List_Lazy_Types::NonEmptyList()(Data_Lazy::defer()([=](const boxed& v1) -> boxed {
                    return xxs;
                }));
            })(Data_Traversable::sequence()(Data_NonEmpty::traversableNonEmpty()(Data_List_Lazy_Types::traversableList()))(dictApplicative)(Data_Lazy::force()(v)));
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))([=](const boxed& xxs) -> boxed {
                    return Data_List_Lazy_Types::NonEmptyList()(Data_Lazy::defer()([=](const boxed& v1) -> boxed {
                        return xxs;
                    }));
                })(Data_Traversable::traverse()(Data_NonEmpty::traversableNonEmpty()(Data_List_Lazy_Types::traversableList()))(dictApplicative)(f)(Data_Lazy::force()(v)));
            };
        };
    });
};
auto traversableWithIndexList() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::foldableWithIndexList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorWithIndexList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::traversableList();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_FoldableWithIndex::foldrWithIndex()(Data_List_Lazy_Types::foldableWithIndexList())([=](const boxed& i) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return [=](const boxed& b) -> boxed {
                        return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_List_Lazy_Types::cons())(f(i)(a)))(b);
                    };
                };
            })(Control_Applicative::pure()(dictApplicative)(Data_List_Lazy_Types::nil()));
        };
    });
};
auto traversableWithIndexNonEmptyList() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::foldableWithIndexNonEmptyList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorWithIndexNonEmptyList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::traversableNonEmptyList();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))([=](const boxed& xxs) -> boxed {
                    return Data_List_Lazy_Types::NonEmptyList()(Data_Lazy::defer()([=](const boxed& v1) -> boxed {
                        return xxs;
                    }));
                })(Data_TraversableWithIndex::traverseWithIndex()(Data_NonEmpty::traversableWithIndexNonEmpty()(Data_List_Lazy_Types::traversableWithIndexList()))(dictApplicative)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::maybe()(0)(Data_Semiring::add()(Data_Semiring::semiringInt())(1))))(Data_Lazy::force()(v)));
            };
        };
    });
};
auto unfoldable1List() -> boxed {
    return Data_Unfoldable1::Unfoldable1()([=]() -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& f) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& b) -> boxed {
                return Control_Lazy::defer()(Data_List_Lazy_Types::lazyList())([=](const boxed& v) -> boxed {
                    boxed v1 = f(b);
                    if (unbox<dict_t>(v1["value1"]).contains("Just")) {
                        return Data_List_Lazy_Types::cons()(v1["value0"])(go(f)(v1["value1"]["value0"]));
                    };
                    if (unbox<dict_t>(v1["value1"]).contains("Nothing")) {
                        return Data_List_Lazy_Types::cons()(v1["value0"])(Data_List_Lazy_Types::nil());
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.Types (line 146, column 28 - line 148, column 33): ");
                });
            };
        };
        return go;
    }());
};
auto unfoldableList() -> boxed {
    return Data_Unfoldable::Unfoldable()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::unfoldable1List();
    })([=]() -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& f) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& b) -> boxed {
                return Control_Lazy::defer()(Data_List_Lazy_Types::lazyList())([=](const boxed& v) -> boxed {
                    boxed v1 = f(b);
                    if (unbox<dict_t>(v1).contains("Nothing")) {
                        return Data_List_Lazy_Types::nil();
                    };
                    if (unbox<dict_t>(v1).contains("Just")) {
                        return Data_List_Lazy_Types::cons()(v1["value0"]["value0"])(go(f)(v1["value0"]["value1"]));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.Types (line 152, column 28 - line 154, column 39): ");
                });
            };
        };
        return go;
    }());
};
auto unfoldable1NonEmptyList() -> boxed {
    return Data_Unfoldable1::Unfoldable1()([=](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return Data_List_Lazy_Types::NonEmptyList()(Data_Lazy::defer()([=](const boxed& v) -> boxed {
                return Data_Unfoldable1::unfoldr1()(Data_NonEmpty::unfoldable1NonEmpty()(Data_List_Lazy_Types::unfoldableList()))(f)(b);
            }));
        };
    });
};
auto comonadNonEmptyList() -> boxed {
    return Control_Comonad::Comonad()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::extendNonEmptyList();
    })([=](const boxed& v) -> boxed {
        return Data_NonEmpty::head()(Data_Lazy::force()(v));
    });
};
auto monadList() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::applicativeList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::bindList();
    });
};
auto bindList() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::applyList();
    })([=](const boxed& xs) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed go = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Nil")) {
                    return Data_List_Lazy_Types::Nil();
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    return Data_List_Lazy_Types::step()(Data_Semigroup::append()(Data_List_Lazy_Types::semigroupList())(f(v["value0"]))(Control_Bind::bind()(Data_List_Lazy_Types::bindList())(v["value1"])(f)));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.Types (line 175, column 5 - line 175, column 17): ");
            };
            return Data_Functor::map()(Data_Lazy::functorLazy())(go)(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeList())(xs));
        };
    });
};
auto applyList() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorList();
    })(Control_Monad::ap()(Data_List_Lazy_Types::monadList()));
};
auto applicativeList() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::applyList();
    })([=](const boxed& a) -> boxed {
        return Data_List_Lazy_Types::cons()(a)(Data_List_Lazy_Types::nil());
    });
};
auto applyNonEmptyList() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorNonEmptyList();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            boxed v2 = Data_Lazy::force()(v1);
            boxed v3 = Data_Lazy::force()(v);
            return Data_Lazy::defer()([=](const boxed& v4) -> boxed {
                return Data_NonEmpty::NonEmpty()(v3["value0"](v2["value0"]))(Data_Semigroup::append()(Data_List_Lazy_Types::semigroupList())(Control_Apply::apply()(Data_List_Lazy_Types::applyList())(v3["value1"])(Data_List_Lazy_Types::cons()(v2["value0"])(Data_List_Lazy_Types::nil())))(Control_Apply::apply()(Data_List_Lazy_Types::applyList())(Data_List_Lazy_Types::cons()(v3["value0"])(v3["value1"]))(v2["value1"])));
            });
        };
    });
};
auto bindNonEmptyList() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::applyNonEmptyList();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed v1 = Data_Lazy::force()(v);
            boxed v2 = Data_Lazy::force()(Data_Newtype::unwrap()(Data_List_Lazy_Types::newtypeNonEmptyList())(f(v1["value0"])));
            return Data_Lazy::defer()([=](const boxed& v3) -> boxed {
                return Data_NonEmpty::NonEmpty()(v2["value0"])(Data_Semigroup::append()(Data_List_Lazy_Types::semigroupList())(v2["value1"])(Control_Bind::bind()(Data_List_Lazy_Types::bindList())(v1["value1"])(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_Types::toList())(f))));
            });
        };
    });
};
auto altNonEmptyList() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorNonEmptyList();
    })(Data_Semigroup::append()(Data_List_Lazy_Types::semigroupNonEmptyList()));
};
auto altList() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::functorList();
    })(Data_Semigroup::append()(Data_List_Lazy_Types::semigroupList()));
};
auto plusList() -> boxed {
    return Control_Plus::Plus()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::altList();
    })(Data_List_Lazy_Types::nil());
};
auto alternativeList() -> boxed {
    return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::applicativeList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::plusList();
    });
};
auto monadZeroList() -> boxed {
    return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::alternativeList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::monadList();
    });
};
auto monadPlusList() -> boxed {
    return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::monadZeroList();
    });
};
auto applicativeNonEmptyList() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::applyNonEmptyList();
    })([=](const boxed& a) -> boxed {
        return Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_NonEmpty::singleton()(Data_List_Lazy_Types::plusList())(a);
        });
    });
};
auto monadNonEmptyList() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::applicativeNonEmptyList();
    })([=](const boxed&) -> boxed {
        return Data_List_Lazy_Types::bindNonEmptyList();
    });
};


} // end namespace Data_List_Lazy_Types


