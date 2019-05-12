#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Control_Monad_ST/Control_Monad_ST.h"
#include "Control_Monad_ST_Internal/Control_Monad_ST_Internal.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Array_NonEmpty_Internal/Data_Array_NonEmpty_Internal.h"
#include "Data_Array_ST/Data_Array_ST.h"
#include "Data_Array_ST_Iterator/Data_Array_ST_Iterator.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"
#include "Unsafe_Coerce/Unsafe_Coerce.h"

#include "Data_Array/Data_Array.h"


namespace Data_Array {

auto zipWithA() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return [=](const boxed& ys) -> boxed {
                    return Data_Traversable::sequence()(Data_Traversable::traversableArray())(dictApplicative)(Data_Array::zipWith()(f)(xs)(ys));
                };
            };
        };
    };
    return _;
};
auto zip() -> boxed {
    return Data_Array::zipWith()(Data_Tuple::Tuple());
};
auto updateAtIndices() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& us) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return Control_Monad_ST_Internal::run()(Data_Array_ST::withArray()([=](const boxed& res) -> boxed {
                    return Data_Foldable::traverse_()(Control_Monad_ST_Internal::applicativeST())(dictFoldable)([=](const boxed& v) -> boxed {
                        return Data_Array_ST::poke()(v["value0"])(v["value1"])(res);
                    })(us);
                })(xs));
            };
        };
    };
    return _;
};
auto updateAt() -> boxed {
    return Data_Array::_updateAt()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto unsafeIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return Data_Array::unsafeIndexImpl();
    };
    return _;
};
auto uncons() -> boxed {
    return Data_Array::uncons_Prime_()(Data_Function::_const_()(Data_Maybe::Nothing()))([=](const boxed& x) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Maybe::Just()(dict_t{
                { "head", x },
                { "tail", xs }
            });
        };
    });
};
auto toUnfoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return [=](const boxed& xs) -> boxed {
            boxed len = Data_Array::length()(xs);
            boxed f = [=](const boxed& i) -> boxed {
                if (unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(i)(len))) {
                    return Data_Maybe::Just()(Data_Tuple::Tuple()([=](const boxed& dictPartial) -> boxed {
                        return Data_Array::unsafeIndex()(dictPartial)(xs)(i);
                    }(undefined))(unbox<int>(i) + 1));
                };
                return Data_Maybe::Nothing();
            };
            return Data_Unfoldable::unfoldr()(dictUnfoldable)(f)(0);
        };
    };
    return _;
};
auto takeEnd() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::drop()(unbox<int>(Data_Array::length()(xs)) - unbox<int>(n))(xs);
        };
    };
    return _;
};
auto tail() -> boxed {
    return Data_Array::uncons_Prime_()(Data_Function::_const_()(Data_Maybe::Nothing()))([=](const boxed& v) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Maybe::Just()(xs);
        };
    });
};
auto sortBy() -> const boxed& {
    static const boxed _ = [](const boxed& comp) -> boxed {
        return [=](const boxed& xs) -> boxed {
            boxed comp_Prime_ = [=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    boxed v = comp(x)(y);
                    if (unbox<dict_t>(v).contains("GT")) {
                        return 1;
                    };
                    if (unbox<dict_t>(v).contains("EQ")) {
                        return 0;
                    };
                    if (unbox<dict_t>(v).contains("LT")) {
                        return -1;
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Array (line 702, column 15 - line 707, column 1): ");
                };
            };
            return Data_Array::sortImpl()(comp_Prime_)(xs);
        };
    };
    return _;
};
auto sortWith() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Array::sortBy()(Data_Ord::comparing()(dictOrd)(f));
        };
    };
    return _;
};
auto sort() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::sortBy()(Data_Ord::compare()(dictOrd))(xs);
        };
    };
    return _;
};
auto singleton() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return array_t{ a };
    };
    return _;
};
auto null() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return unbox<int>(Data_Array::length()(xs)) == 0;
    };
    return _;
};
auto nubByEq() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            boxed v = Data_Array::uncons()(xs);
            if (unbox<dict_t>(v).contains("Just")) {
                return Data_Array::cons()(v["value0"]["head"])(Data_Array::nubByEq()(eq)(Data_Array::filter()([=](const boxed& y) -> boxed {
                    return !unbox<bool>(eq(v["value0"]["head"])(y));
                })(v["value0"]["tail"])));
            };
            if (unbox<dict_t>(v).contains("Nothing")) {
                return array_t{  };
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Array (line 930, column 3 - line 932, column 18): ");
        };
    };
    return _;
};
auto nubEq() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Array::nubByEq()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto modifyAtIndices() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& is) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Control_Monad_ST_Internal::run()(Data_Array_ST::withArray()([=](const boxed& res) -> boxed {
                        return Data_Foldable::traverse_()(Control_Monad_ST_Internal::applicativeST())(dictFoldable)([=](const boxed& i) -> boxed {
                            return Data_Array_ST::modify()(i)(f)(res);
                        })(is);
                    })(xs));
                };
            };
        };
    };
    return _;
};
auto mapWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::zipWith()(f)(Data_Array::range()(0)(unbox<int>(Data_Array::length()(xs)) - 1))(xs);
        };
    };
    return _;
};
auto some() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlternative) -> boxed {
        return [=](const boxed& dictLazy) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Apply::apply()(dictAlternative["Applicative0"](undefined)["Apply0"](undefined))(Data_Functor::map()(dictAlternative["Plus1"](undefined)["Alt0"](undefined)["Functor0"](undefined))(Data_Array::cons())(v))(Control_Lazy::defer()(dictLazy)([=](const boxed& v1) -> boxed {
                    return Data_Array::many()(dictAlternative)(dictLazy)(v);
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
                return Control_Alt::alt()(dictAlternative["Plus1"](undefined)["Alt0"](undefined))(Data_Array::some()(dictAlternative)(dictLazy)(v))(Control_Applicative::pure()(dictAlternative["Applicative0"](undefined))(array_t{  }));
            };
        };
    };
    return _;
};
auto insertAt() -> boxed {
    return Data_Array::_insertAt()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto init() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        if (unbox<bool>(Data_Array::null()(xs))) {
            return Data_Maybe::Nothing();
        };
        return Data_Maybe::Just()(Data_Array::slice()(Data_Semiring::zero()(Data_Semiring::semiringInt()))(unbox<int>(Data_Array::length()(xs)) - unbox<int>(Data_Semiring::one()(Data_Semiring::semiringInt())))(xs));
    };
    return _;
};
auto index() -> boxed {
    return Data_Array::indexImpl()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto last() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return Data_Array::index()(xs)(unbox<int>(Data_Array::length()(xs)) - 1);
    };
    return _;
};
auto unsnoc() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return Control_Apply::apply()(Data_Maybe::applyMaybe())(Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return dict_t{
                    { "init", v },
                    { "last", v1 }
                };
            };
        })(Data_Array::init()(xs)))(Data_Array::last()(xs));
    };
    return _;
};
auto modifyAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed go = [=](const boxed& x) -> boxed {
                    return Data_Array::updateAt()(i)(f(x))(xs);
                };
                return Data_Maybe::maybe()(Data_Maybe::Nothing())(go)(Data_Array::index()(xs)(i));
            };
        };
    };
    return _;
};
auto span() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& arr) -> boxed {
            boxed::recur go;
            boxed::recur::weak go_Weak_(go);
            go = [=](const boxed& i) -> boxed {
                boxed go = go_Weak_;
                boxed v = Data_Array::index()(arr)(i);
                if (unbox<dict_t>(v).contains("Just")) {
                    boxed _Local_14 = p(v["value0"]);
                    if (unbox<bool>(_Local_14)) {
                        return go(unbox<int>(i) + 1);
                    };
                    return Data_Maybe::Just()(i);
                };
                if (unbox<dict_t>(v).contains("Nothing")) {
                    return Data_Maybe::Nothing();
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Array (line 834, column 5 - line 836, column 25): ");
            };
            boxed breakIndex = go(0);
            if (unbox<dict_t>(breakIndex).contains("Just")) {
                if (unbox<int>(breakIndex["value0"]) == 0) {
                    return dict_t{
                        { "init", array_t{  } },
                        { "rest", arr }
                    };
                };
            };
            if (unbox<dict_t>(breakIndex).contains("Just")) {
                return dict_t{
                    { "init", Data_Array::slice()(0)(breakIndex["value0"])(arr) },
                    { "rest", Data_Array::slice()(breakIndex["value0"])(Data_Array::length()(arr))(arr) }
                };
            };
            if (unbox<dict_t>(breakIndex).contains("Nothing")) {
                return dict_t{
                    { "init", arr },
                    { "rest", array_t{  } }
                };
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Array (line 821, column 3 - line 827, column 30): ");
        };
    };
    return _;
};
auto takeWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::span()(p)(xs)["init"];
        };
    };
    return _;
};
auto unzip() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return Control_Monad_ST_Internal::run()(Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::empty())([=](const boxed& v) -> boxed {
            return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::empty())([=](const boxed& v1) -> boxed {
                return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST_Iterator::iterator()([=](const boxed& v2) -> boxed {
                    return Data_Array::index()(xs)(v2);
                }))([=](const boxed& v2) -> boxed {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Monad_ST_Internal::bindST())(Data_Array_ST_Iterator::iterate()(v2)([=](const boxed& v3) -> boxed {
                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Monad_ST_Internal::bindST())(Data_Functor::_void_()(Control_Monad_ST_Internal::functorST())(Data_Array_ST::push()(v3["value0"])(v)))([=](const boxed&) -> boxed {
                            return Data_Functor::_void_()(Control_Monad_ST_Internal::functorST())(Data_Array_ST::push()(v3["value1"])(v1));
                        });
                    }))([=](const boxed&) -> boxed {
                        return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::unsafeFreeze()(v))([=](const boxed& v3) -> boxed {
                            return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::unsafeFreeze()(v1))([=](const boxed& v4) -> boxed {
                                return Control_Applicative::pure()(Control_Monad_ST_Internal::applicativeST())(Data_Tuple::Tuple()(v3)(v4));
                            });
                        });
                    });
                });
            });
        }));
    };
    return _;
};
auto head() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return Data_Array::index()(xs)(0);
    };
    return _;
};
auto nubBy() -> const boxed& {
    static const boxed _ = [](const boxed& comp) -> boxed {
        return [=](const boxed& xs) -> boxed {
            boxed indexedAndSorted = Data_Array::sortBy()([=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    return comp(Data_Tuple::snd()(x))(Data_Tuple::snd()(y));
                };
            })(Data_Array::mapWithIndex()(Data_Tuple::Tuple())(xs));
            boxed v = Data_Array::head()(indexedAndSorted);
            if (unbox<dict_t>(v).contains("Nothing")) {
                return array_t{  };
            };
            if (unbox<dict_t>(v).contains("Just")) {
                return Data_Functor::map()(Data_Functor::functorArray())(Data_Tuple::snd())(Data_Array::sortWith()(Data_Ord::ordInt())(Data_Tuple::fst())(Control_Monad_ST_Internal::run()(Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::unsafeThaw()(Data_Array::singleton()(v["value0"])))([=](const boxed& v1) -> boxed {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Monad_ST_Internal::bindST())(Control_Monad_ST_Internal::foreach()(indexedAndSorted)([=](const boxed& v2) -> boxed {
                        return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Functor::map()(Control_Monad_ST_Internal::functorST())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Tuple::snd())([=](const boxed& dictPartial) -> boxed {
                            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::fromJust()(dictPartial))(Data_Array::last());
                        }(undefined)))(Data_Array_ST::unsafeFreeze()(v1)))([=](const boxed& v3) -> boxed {
                            return Control_Applicative::when()(Control_Monad_ST_Internal::applicativeST())(Data_Eq::notEq()(Data_Ordering::eqOrdering())(comp(v3)(v2["value1"]))(Data_Ordering::EQ()))(Data_Functor::_void_()(Control_Monad_ST_Internal::functorST())(Data_Array_ST::push()(v2)(v1)));
                        });
                    }))([=](const boxed&) -> boxed {
                        return Data_Array_ST::unsafeFreeze()(v1);
                    });
                }))));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Array (line 903, column 17 - line 911, column 29): ");
        };
    };
    return _;
};
auto nub() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Array::nubBy()(Data_Ord::compare()(dictOrd));
    };
    return _;
};
auto groupBy() -> const boxed& {
    static const boxed _ = [](const boxed& op) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Control_Monad_ST_Internal::run()(Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::empty())([=](const boxed& v) -> boxed {
                return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST_Iterator::iterator()([=](const boxed& v1) -> boxed {
                    return Data_Array::index()(xs)(v1);
                }))([=](const boxed& v1) -> boxed {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Monad_ST_Internal::bindST())(Data_Array_ST_Iterator::iterate()(v1)([=](const boxed& x) -> boxed {
                        return Data_Functor::_void_()(Control_Monad_ST_Internal::functorST())(Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::empty())([=](const boxed& v2) -> boxed {
                            return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::push()(x)(v2))([=](const boxed& v3) -> boxed {
                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Monad_ST_Internal::bindST())(Data_Array_ST_Iterator::pushWhile()(op(x))(v1)(v2))([=](const boxed&) -> boxed {
                                    return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::unsafeFreeze()(v2))([=](const boxed& v4) -> boxed {
                                        return Data_Array_ST::push()(v4)(v);
                                    });
                                });
                            });
                        }));
                    }))([=](const boxed&) -> boxed {
                        return Data_Array_ST::unsafeFreeze()(v);
                    });
                });
            }));
        };
    };
    return _;
};
auto group() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::groupBy()(Data_Eq::eq()(dictEq))(xs);
        };
    };
    return _;
};
auto group_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array::group()(dictOrd["Eq0"](undefined)))(Data_Array::sort()(dictOrd));
    };
    return _;
};
auto fromFoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Data_Array::fromFoldableImpl()(Data_Foldable::foldr()(dictFoldable));
    };
    return _;
};
auto foldRecM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& array) -> boxed {
                    boxed go = [=](const boxed& res) -> boxed {
                        return [=](const boxed& i) -> boxed {
                            if (unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(i)(Data_Array::length()(array)))) {
                                return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))(Control_Monad_Rec_Class::Done()(res));
                            };
                            return Control_Bind::bind()(dictMonadRec["Monad0"](undefined)["Bind1"](undefined))(f(res)([=](const boxed& dictPartial) -> boxed {
                                return Data_Array::unsafeIndex()(dictPartial)(array)(i);
                            }(undefined)))([=](const boxed& v) -> boxed {
                                return Control_Applicative::pure()(dictMonadRec["Monad0"](undefined)["Applicative0"](undefined))(Control_Monad_Rec_Class::Loop()(dict_t{
                                    { "a", v },
                                    { "b", unbox<int>(i) + 1 }
                                }));
                            });
                        };
                    };
                    return Control_Monad_Rec_Class::tailRecM2()(dictMonadRec)(go)(a)(0);
                };
            };
        };
    };
    return _;
};
auto foldM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return Data_Array::uncons_Prime_()([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(a);
                })([=](const boxed& b) -> boxed {
                    return [=](const boxed& bs) -> boxed {
                        return Control_Bind::bind()(dictMonad["Bind1"](undefined))(f(a)(b))([=](const boxed& a_Prime_) -> boxed {
                            return Data_Array::foldM()(dictMonad)(f)(a_Prime_)(bs);
                        });
                    };
                });
            };
        };
    };
    return _;
};
auto findLastIndex() -> boxed {
    return Data_Array::findLastIndexImpl()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto insertBy() -> const boxed& {
    static const boxed _ = [](const boxed& cmp) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& ys) -> boxed {
                boxed i = Data_Maybe::maybe()(0)([=](const boxed& v) -> boxed {
                    return unbox<int>(v) + 1;
                })(Data_Array::findLastIndex()([=](const boxed& y) -> boxed {
                    return Data_Eq::eq()(Data_Ordering::eqOrdering())(cmp(x)(y))(Data_Ordering::GT());
                })(ys));
                return [=](const boxed& dictPartial) -> boxed {
                    return Data_Maybe::fromJust()(dictPartial)(Data_Array::insertAt()(i)(x)(ys));
                }(undefined);
            };
        };
    };
    return _;
};
auto insert() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Array::insertBy()(Data_Ord::compare()(dictOrd));
    };
    return _;
};
auto findIndex() -> boxed {
    return Data_Array::findIndexImpl()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto intersectBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                return Data_Array::filter()([=](const boxed& x) -> boxed {
                    return Data_Maybe::isJust()(Data_Array::findIndex()(eq(x))(ys));
                })(xs);
            };
        };
    };
    return _;
};
auto intersect() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Array::intersectBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto elemLastIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array::findLastIndex()([=](const boxed& v) -> boxed {
                return Data_Eq::eq()(dictEq)(v)(x);
            });
        };
    };
    return _;
};
auto elemIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array::findIndex()([=](const boxed& v) -> boxed {
                return Data_Eq::eq()(dictEq)(v)(x);
            });
        };
    };
    return _;
};
auto dropWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::span()(p)(xs)["rest"];
        };
    };
    return _;
};
auto dropEnd() -> const boxed& {
    static const boxed _ = [](const boxed& n) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::take()(unbox<int>(Data_Array::length()(xs)) - unbox<int>(n))(xs);
        };
    };
    return _;
};
auto deleteAt() -> boxed {
    return Data_Array::_deleteAt()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto deleteBy() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<int>(array_length(v2)) == 0) {
                    return array_t{  };
                };
                return Data_Maybe::maybe()(v2)([=](const boxed& i) -> boxed {
                    return Data_Maybe::fromJust()(undefined)(Data_Array::deleteAt()(i)(v2));
                })(Data_Array::findIndex()(v(v1))(v2));
            };
        };
    };
    return _;
};
auto unionBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                return Data_Semigroup::append()(Data_Semigroup::semigroupArray())(xs)(Data_Foldable::foldl()(Data_Foldable::foldableArray())(Data_Function::flip()(Data_Array::deleteBy()(eq)))(Data_Array::nubByEq()(eq)(ys))(xs));
            };
        };
    };
    return _;
};
auto _union_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Array::unionBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto _delete_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Array::deleteBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto difference() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Foldable::foldr()(Data_Foldable::foldableArray())(Data_Array::_delete_()(dictEq));
    };
    return _;
};
auto concatMap() -> boxed {
    return Data_Function::flip()(Control_Bind::bind()(Control_Bind::bindArray()));
};
auto mapMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array::concatMap()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::maybe()(array_t{  })(Data_Array::singleton()))(f));
    };
    return _;
};
auto filterA() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(Data_Traversable::traverse()(Data_Traversable::traversableArray())(dictApplicative)([=](const boxed& x) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Tuple::Tuple()(x))(p(x));
            }))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Array::mapMaybe()([=](const boxed& v) -> boxed {
                if (unbox<bool>(v["value1"])) {
                    return Data_Maybe::Just()(v["value0"]);
                };
                return Data_Maybe::Nothing();
            })));
        };
    };
    return _;
};
auto catMaybes() -> boxed {
    return Data_Array::mapMaybe()(Control_Category::identity()(Control_Category::categoryFn()));
};
auto alterAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed go = [=](const boxed& x) -> boxed {
                    boxed v = f(x);
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Data_Array::deleteAt()(i)(xs);
                    };
                    if (unbox<dict_t>(v).contains("Just")) {
                        return Data_Array::updateAt()(i)(v["value0"])(xs);
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Array (line 544, column 10 - line 546, column 32): ");
                };
                return Data_Maybe::maybe()(Data_Maybe::Nothing())(go)(Data_Array::index()(xs)(i));
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto fromFoldableImpl() -> const boxed& { static const boxed _ = foreign().at("fromFoldableImpl"); return _; };
auto range() -> const boxed& { static const boxed _ = foreign().at("range"); return _; };
auto replicate() -> const boxed& { static const boxed _ = foreign().at("replicate"); return _; };
auto length() -> const boxed& { static const boxed _ = foreign().at("length"); return _; };
auto cons() -> const boxed& { static const boxed _ = foreign().at("cons"); return _; };
auto snoc() -> const boxed& { static const boxed _ = foreign().at("snoc"); return _; };
auto uncons_Prime_() -> const boxed& { static const boxed _ = foreign().at("uncons'"); return _; };
auto indexImpl() -> const boxed& { static const boxed _ = foreign().at("indexImpl"); return _; };
auto findIndexImpl() -> const boxed& { static const boxed _ = foreign().at("findIndexImpl"); return _; };
auto findLastIndexImpl() -> const boxed& { static const boxed _ = foreign().at("findLastIndexImpl"); return _; };
auto _insertAt() -> const boxed& { static const boxed _ = foreign().at("_insertAt"); return _; };
auto _deleteAt() -> const boxed& { static const boxed _ = foreign().at("_deleteAt"); return _; };
auto _updateAt() -> const boxed& { static const boxed _ = foreign().at("_updateAt"); return _; };
auto reverse() -> const boxed& { static const boxed _ = foreign().at("reverse"); return _; };
auto concat() -> const boxed& { static const boxed _ = foreign().at("concat"); return _; };
auto filter() -> const boxed& { static const boxed _ = foreign().at("filter"); return _; };
auto partition() -> const boxed& { static const boxed _ = foreign().at("partition"); return _; };
auto sortImpl() -> const boxed& { static const boxed _ = foreign().at("sortImpl"); return _; };
auto slice() -> const boxed& { static const boxed _ = foreign().at("slice"); return _; };
auto take() -> const boxed& { static const boxed _ = foreign().at("take"); return _; };
auto drop() -> const boxed& { static const boxed _ = foreign().at("drop"); return _; };
auto zipWith() -> const boxed& { static const boxed _ = foreign().at("zipWith"); return _; };
auto unsafeIndexImpl() -> const boxed& { static const boxed _ = foreign().at("unsafeIndexImpl"); return _; };

} // end namespace Data_Array


