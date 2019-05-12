#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Category/Control_Category.h"
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
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_Show/Data_Show.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_TraversableWithIndex/Data_TraversableWithIndex.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Data_Unfoldable1/Data_Unfoldable1.h"
#include "Prelude/Prelude.h"

#include "Data_NonEmpty/Data_NonEmpty.h"


namespace Data_NonEmpty {

auto NonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "NonEmpty", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto unfoldable1NonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return Data_Unfoldable1::Unfoldable1()([=](const boxed& f) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Data_Tuple::uncurry()(Data_NonEmpty::NonEmpty())(Data_Functor::map()(Data_Tuple::functorTuple())(Data_Unfoldable::unfoldr()(dictUnfoldable)(Data_Functor::map()(Data_Maybe::functorMaybe())(f)))(f(b)));
            };
        });
    };
    return _;
};
auto tail() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"];
    };
    return _;
};
auto singleton() -> const boxed& {
    static const boxed _ = [](const boxed& dictPlus) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Data_NonEmpty::NonEmpty()(a)(Control_Plus::empty()(dictPlus));
        };
    };
    return _;
};
auto showNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& dictShow1) -> boxed {
            return Data_Show::Show()([=](const boxed& v) -> boxed {
                return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(NonEmpty ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v["value0"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow1)(v["value1"]))(")"))));
            });
        };
    };
    return _;
};
auto oneOf() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlternative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Alt::alt()(dictAlternative["Plus1"](undefined)["Alt0"](undefined))(Control_Applicative::pure()(dictAlternative["Applicative0"](undefined))(v["value0"]))(v["value1"]);
        };
    };
    return _;
};
auto head() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value0"];
    };
    return _;
};
auto functorNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& m) -> boxed {
                return Data_NonEmpty::NonEmpty()(f(m["value0"]))(Data_Functor::map()(dictFunctor)(f)(m["value1"]));
            };
        });
    };
    return _;
};
auto functorWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctorWithIndex) -> boxed {
        return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
            return Data_NonEmpty::functorNonEmpty()(dictFunctorWithIndex["Functor0"](undefined));
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_NonEmpty::NonEmpty()(f(Data_Maybe::Nothing())(v["value0"]))(Data_FunctorWithIndex::mapWithIndex()(dictFunctorWithIndex)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::Just()))(v["value1"]));
            };
        });
    };
    return _;
};
auto fromNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v["value0"])(v["value1"]);
        };
    };
    return _;
};
auto foldl1() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldl()(dictFoldable)(f)(v["value0"])(v["value1"]);
            };
        };
    };
    return _;
};
auto foldableNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(f(v["value0"]))(Data_Foldable::foldMap()(dictFoldable)(dictMonoid)(f)(v["value1"]));
                };
            };
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& b) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Foldable::foldl()(dictFoldable)(f)(f(b)(v["value0"]))(v["value1"]);
                };
            };
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& b) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return f(v["value0"])(Data_Foldable::foldr()(dictFoldable)(f)(b)(v["value1"]));
                };
            };
        });
    };
    return _;
};
auto foldableWithIndexNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
            return Data_NonEmpty::foldableNonEmpty()(dictFoldableWithIndex["Foldable0"](undefined));
        })([=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(f(Data_Maybe::Nothing())(v["value0"]))(Data_FoldableWithIndex::foldMapWithIndex()(dictFoldableWithIndex)(dictMonoid)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::Just()))(v["value1"]));
                };
            };
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& b) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_FoldableWithIndex::foldlWithIndex()(dictFoldableWithIndex)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::Just()))(f(Data_Maybe::Nothing())(b)(v["value0"]))(v["value1"]);
                };
            };
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& b) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return f(Data_Maybe::Nothing())(v["value0"])(Data_FoldableWithIndex::foldrWithIndex()(dictFoldableWithIndex)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::Just()))(b)(v["value1"]));
                };
            };
        });
    };
    return _;
};
auto traversableNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
            return Data_NonEmpty::foldableNonEmpty()(dictTraversable["Foldable1"](undefined));
        })([=](const boxed&) -> boxed {
            return Data_NonEmpty::functorNonEmpty()(dictTraversable["Functor0"](undefined));
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_NonEmpty::NonEmpty())(v["value0"]))(Data_Traversable::sequence()(dictTraversable)(dictApplicative)(v["value1"]));
            };
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_NonEmpty::NonEmpty())(f(v["value0"])))(Data_Traversable::traverse()(dictTraversable)(dictApplicative)(f)(v["value1"]));
                };
            };
        });
    };
    return _;
};
auto traversableWithIndexNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversableWithIndex) -> boxed {
        return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
            return Data_NonEmpty::foldableWithIndexNonEmpty()(dictTraversableWithIndex["FoldableWithIndex1"](undefined));
        })([=](const boxed&) -> boxed {
            return Data_NonEmpty::functorWithIndex()(dictTraversableWithIndex["FunctorWithIndex0"](undefined));
        })([=](const boxed&) -> boxed {
            return Data_NonEmpty::traversableNonEmpty()(dictTraversableWithIndex["Traversable2"](undefined));
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_NonEmpty::NonEmpty())(f(Data_Maybe::Nothing())(v["value0"])))(Data_TraversableWithIndex::traverseWithIndex()(dictTraversableWithIndex)(dictApplicative)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Maybe::Just()))(v["value1"]));
                };
            };
        });
    };
    return _;
};
auto foldable1NonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Data_Semigroup_Foldable::Foldable1()([=](const boxed&) -> boxed {
            return Data_NonEmpty::foldableNonEmpty()(dictFoldable);
        })([=](const boxed& dictSemigroup) -> boxed {
            return Data_Semigroup_Foldable::foldMap1()(Data_NonEmpty::foldable1NonEmpty()(dictFoldable))(dictSemigroup)(Control_Category::identity()(Control_Category::categoryFn()));
        })([=](const boxed& dictSemigroup) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Foldable::foldl()(dictFoldable)([=](const boxed& s) -> boxed {
                        return [=](const boxed& a1) -> boxed {
                            return Data_Semigroup::append()(dictSemigroup)(s)(f(a1));
                        };
                    })(f(v["value0"]))(v["value1"]);
                };
            };
        });
    };
    return _;
};
auto eqNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq1) -> boxed {
        return [=](const boxed& dictEq) -> boxed {
            return Data_Eq::Eq()([=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    return unbox<bool>(Data_Eq::eq()(dictEq)(x["value0"])(y["value0"])) && unbox<bool>(Data_Eq::eq1()(dictEq1)(dictEq)(x["value1"])(y["value1"]));
                };
            });
        };
    };
    return _;
};
auto ordNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd1) -> boxed {
        return [=](const boxed& dictOrd) -> boxed {
            return Data_Ord::Ord()([=](const boxed&) -> boxed {
                return Data_NonEmpty::eqNonEmpty()(dictOrd1["Eq10"](undefined))(dictOrd["Eq0"](undefined));
            })([=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    boxed v = Data_Ord::compare()(dictOrd)(x["value0"])(y["value0"]);
                    if (unbox<dict_t>(v).contains("LT")) {
                        return Data_Ordering::LT();
                    };
                    if (unbox<dict_t>(v).contains("GT")) {
                        return Data_Ordering::GT();
                    };
                    return Data_Ord::compare1()(dictOrd1)(dictOrd)(x["value1"])(y["value1"]);
                };
            });
        };
    };
    return _;
};
auto eq1NonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq1) -> boxed {
        return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
            return Data_Eq::eq()(Data_NonEmpty::eqNonEmpty()(dictEq1)(dictEq));
        });
    };
    return _;
};
auto ord1NonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd1) -> boxed {
        return Data_Ord::Ord1()([=](const boxed&) -> boxed {
            return Data_NonEmpty::eq1NonEmpty()(dictOrd1["Eq10"](undefined));
        })([=](const boxed& dictOrd) -> boxed {
            return Data_Ord::compare()(Data_NonEmpty::ordNonEmpty()(dictOrd1)(dictOrd));
        });
    };
    return _;
};


} // end namespace Data_NonEmpty


