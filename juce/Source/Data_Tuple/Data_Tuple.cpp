#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Biapplicative/Control_Biapplicative.h"
#include "Control_Biapply/Control_Biapply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Comonad/Control_Comonad.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Bifoldable/Data_Bifoldable.h"
#include "Data_Bifunctor/Data_Bifunctor.h"
#include "Data_Bitraversable/Data_Bitraversable.h"
#include "Data_BooleanAlgebra/Data_BooleanAlgebra.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_CommutativeRing/Data_CommutativeRing.h"
#include "Data_Distributive/Data_Distributive.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_FoldableWithIndex/Data_FoldableWithIndex.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Functor_Invariant/Data_Functor_Invariant.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Maybe_First/Data_Maybe_First.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
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
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"
#include "Type_Equality/Type_Equality.h"

#include "Data_Tuple/Data_Tuple.h"


namespace Data_Tuple {

auto Tuple() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "Tuple", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto uncurry() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v["value0"])(v["value1"]);
        };
    };
    return _;
};
auto swap() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Tuple::Tuple()(v["value1"])(v["value0"]);
    };
    return _;
};
auto snd() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"];
    };
    return _;
};
auto showTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& dictShow1) -> boxed {
            return Data_Show::Show()([=](const boxed& v) -> boxed {
                return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Tuple ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v["value0"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow1)(v["value1"]))(")"))));
            });
        };
    };
    return _;
};
auto semiringTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemiring) -> boxed {
        return [=](const boxed& dictSemiring1) -> boxed {
            return Data_Semiring::Semiring()([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Data_Tuple::Tuple()(Data_Semiring::add()(dictSemiring)(v["value0"])(v1["value0"]))(Data_Semiring::add()(dictSemiring1)(v["value1"])(v1["value1"]));
                };
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Data_Tuple::Tuple()(Data_Semiring::mul()(dictSemiring)(v["value0"])(v1["value0"]))(Data_Semiring::mul()(dictSemiring1)(v["value1"])(v1["value1"]));
                };
            })(Data_Tuple::Tuple()(Data_Semiring::one()(dictSemiring))(Data_Semiring::one()(dictSemiring1)))(Data_Tuple::Tuple()(Data_Semiring::zero()(dictSemiring))(Data_Semiring::zero()(dictSemiring1)));
        };
    };
    return _;
};
auto semigroupoidTuple() -> boxed {
    return Control_Semigroupoid::Semigroupoid()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Tuple::Tuple()(v1["value0"])(v["value1"]);
        };
    });
};
auto semigroupTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& dictSemigroup1) -> boxed {
            return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Data_Tuple::Tuple()(Data_Semigroup::append()(dictSemigroup)(v["value0"])(v1["value0"]))(Data_Semigroup::append()(dictSemigroup1)(v["value1"])(v1["value1"]));
                };
            });
        };
    };
    return _;
};
auto ringTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictRing) -> boxed {
        return [=](const boxed& dictRing1) -> boxed {
            return Data_Ring::Ring()([=](const boxed&) -> boxed {
                return Data_Tuple::semiringTuple()(dictRing["Semiring0"](undefined))(dictRing1["Semiring0"](undefined));
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Data_Tuple::Tuple()(Data_Ring::sub()(dictRing)(v["value0"])(v1["value0"]))(Data_Ring::sub()(dictRing1)(v["value1"])(v1["value1"]));
                };
            });
        };
    };
    return _;
};
auto monoidTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& dictMonoid1) -> boxed {
            return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
                return Data_Tuple::semigroupTuple()(dictMonoid["Semigroup0"](undefined))(dictMonoid1["Semigroup0"](undefined));
            })(Data_Tuple::Tuple()(Data_Monoid::mempty()(dictMonoid))(Data_Monoid::mempty()(dictMonoid1)));
        };
    };
    return _;
};
auto lookup() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictEq) -> boxed {
            return [=](const boxed& a) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Maybe_First::newtypeFirst()))(Data_Foldable::foldMap()(dictFoldable)(Data_Maybe_First::monoidFirst())([=](const boxed& v) -> boxed {
                    boxed _Local_49 = Data_Eq::eq()(dictEq)(a)(v["value0"]);
                    if (unbox<bool>(_Local_49)) {
                        return Data_Maybe::Just()(v["value1"]);
                    };
                    return Data_Maybe::Nothing();
                }));
            };
        };
    };
    return _;
};
auto heytingAlgebraTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return [=](const boxed& dictHeytingAlgebra1) -> boxed {
            return Data_HeytingAlgebra::HeytingAlgebra()([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Data_Tuple::Tuple()(Data_HeytingAlgebra::conj()(dictHeytingAlgebra)(v["value0"])(v1["value0"]))(Data_HeytingAlgebra::conj()(dictHeytingAlgebra1)(v["value1"])(v1["value1"]));
                };
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Data_Tuple::Tuple()(Data_HeytingAlgebra::disj()(dictHeytingAlgebra)(v["value0"])(v1["value0"]))(Data_HeytingAlgebra::disj()(dictHeytingAlgebra1)(v["value1"])(v1["value1"]));
                };
            })(Data_Tuple::Tuple()(Data_HeytingAlgebra::ff()(dictHeytingAlgebra))(Data_HeytingAlgebra::ff()(dictHeytingAlgebra1)))([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Data_Tuple::Tuple()(Data_HeytingAlgebra::implies()(dictHeytingAlgebra)(v["value0"])(v1["value0"]))(Data_HeytingAlgebra::implies()(dictHeytingAlgebra1)(v["value1"])(v1["value1"]));
                };
            })([=](const boxed& v) -> boxed {
                return Data_Tuple::Tuple()(Data_HeytingAlgebra::_not_()(dictHeytingAlgebra)(v["value0"]))(Data_HeytingAlgebra::_not_()(dictHeytingAlgebra1)(v["value1"]));
            })(Data_Tuple::Tuple()(Data_HeytingAlgebra::tt()(dictHeytingAlgebra))(Data_HeytingAlgebra::tt()(dictHeytingAlgebra1)));
        };
    };
    return _;
};
auto functorTuple() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return Data_Tuple::Tuple()(m["value0"])(f(m["value1"]));
        };
    });
};
auto functorWithIndexTuple() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Tuple::functorTuple();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Tuple::functorTuple())(f(Data_Unit::unit()));
    });
};
auto invariantTuple() -> boxed {
    return Data_Functor_Invariant::Invariant()(Data_Functor_Invariant::imapF()(Data_Tuple::functorTuple()));
};
auto fst() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value0"];
    };
    return _;
};
auto lazyTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictLazy) -> boxed {
        return [=](const boxed& dictLazy1) -> boxed {
            return Control_Lazy::Lazy()([=](const boxed& f) -> boxed {
                return Data_Tuple::Tuple()(Control_Lazy::defer()(dictLazy)([=](const boxed& v) -> boxed {
                    return Data_Tuple::fst()(f(Data_Unit::unit()));
                }))(Control_Lazy::defer()(dictLazy1)([=](const boxed& v) -> boxed {
                    return Data_Tuple::snd()(f(Data_Unit::unit()));
                }));
            });
        };
    };
    return _;
};
auto foldableTuple() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(v["value1"]);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(z)(v["value1"]);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(v["value1"])(z);
            };
        };
    });
};
auto foldableWithIndexTuple() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Tuple::foldableTuple();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(Data_Unit::unit())(v["value1"]);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(Data_Unit::unit())(z)(v["value1"]);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(Data_Unit::unit())(v["value1"])(z);
            };
        };
    });
};
auto traversableTuple() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Tuple::foldableTuple();
    })([=](const boxed&) -> boxed {
        return Data_Tuple::functorTuple();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Tuple::Tuple()(v["value0"]))(v["value1"]);
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Tuple::Tuple()(v["value0"]))(f(v["value1"]));
            };
        };
    });
};
auto traversableWithIndexTuple() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_Tuple::foldableWithIndexTuple();
    })([=](const boxed&) -> boxed {
        return Data_Tuple::functorWithIndexTuple();
    })([=](const boxed&) -> boxed {
        return Data_Tuple::traversableTuple();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Tuple::Tuple()(v["value0"]))(f(Data_Unit::unit())(v["value1"]));
            };
        };
    });
};
auto foldable1Tuple() -> boxed {
    return Data_Semigroup_Foldable::Foldable1()([=](const boxed&) -> boxed {
        return Data_Tuple::foldableTuple();
    })([=](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& v) -> boxed {
            return v["value1"];
        };
    })([=](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(v["value1"]);
            };
        };
    });
};
auto traversable1Tuple() -> boxed {
    return Data_Semigroup_Traversable::Traversable1()([=](const boxed&) -> boxed {
        return Data_Tuple::foldable1Tuple();
    })([=](const boxed&) -> boxed {
        return Data_Tuple::traversableTuple();
    })([=](const boxed& dictApply) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApply["Functor0"](undefined))(Data_Tuple::Tuple()(v["value0"]))(v["value1"]);
        };
    })([=](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApply["Functor0"](undefined))(Data_Tuple::Tuple()(v["value0"]))(f(v["value1"]));
            };
        };
    });
};
auto extendTuple() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_Tuple::functorTuple();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(f(v));
        };
    });
};
auto eqTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& dictEq1) -> boxed {
            return Data_Eq::Eq()([=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    return unbox<bool>(Data_Eq::eq()(dictEq)(x["value0"])(y["value0"])) && unbox<bool>(Data_Eq::eq()(dictEq1)(x["value1"])(y["value1"]));
                };
            });
        };
    };
    return _;
};
auto ordTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictOrd1) -> boxed {
            return Data_Ord::Ord()([=](const boxed&) -> boxed {
                return Data_Tuple::eqTuple()(dictOrd["Eq0"](undefined))(dictOrd1["Eq0"](undefined));
            })([=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    boxed v = Data_Ord::compare()(dictOrd)(x["value0"])(y["value0"]);
                    if (unbox<dict_t>(v).contains("LT")) {
                        return Data_Ordering::LT();
                    };
                    if (unbox<dict_t>(v).contains("GT")) {
                        return Data_Ordering::GT();
                    };
                    return Data_Ord::compare()(dictOrd1)(x["value1"])(y["value1"]);
                };
            });
        };
    };
    return _;
};
auto eq1Tuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::Eq1()([=](const boxed& dictEq1) -> boxed {
            return Data_Eq::eq()(Data_Tuple::eqTuple()(dictEq)(dictEq1));
        });
    };
    return _;
};
auto ord1Tuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord1()([=](const boxed&) -> boxed {
            return Data_Tuple::eq1Tuple()(dictOrd["Eq0"](undefined));
        })([=](const boxed& dictOrd1) -> boxed {
            return Data_Ord::compare()(Data_Tuple::ordTuple()(dictOrd)(dictOrd1));
        });
    };
    return _;
};
auto distributiveTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictTypeEquals) -> boxed {
        return Data_Distributive::Distributive()([=](const boxed&) -> boxed {
            return Data_Tuple::functorTuple();
        })([=](const boxed& dictFunctor) -> boxed {
            return Data_Distributive::collectDefault()(Data_Tuple::distributiveTuple()(dictTypeEquals))(dictFunctor);
        })([=](const boxed& dictFunctor) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Tuple::Tuple()(Type_Equality::from()(dictTypeEquals)(Data_Unit::unit())))(Data_Functor::map()(dictFunctor)(Data_Tuple::snd()));
        });
    };
    return _;
};
auto curry() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return f(Data_Tuple::Tuple()(a)(b));
            };
        };
    };
    return _;
};
auto comonadTuple() -> boxed {
    return Control_Comonad::Comonad()([=](const boxed&) -> boxed {
        return Data_Tuple::extendTuple();
    })(Data_Tuple::snd());
};
auto commutativeRingTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictCommutativeRing) -> boxed {
        return [=](const boxed& dictCommutativeRing1) -> boxed {
            return Data_CommutativeRing::CommutativeRing()([=](const boxed&) -> boxed {
                return Data_Tuple::ringTuple()(dictCommutativeRing["Ring0"](undefined))(dictCommutativeRing1["Ring0"](undefined));
            });
        };
    };
    return _;
};
auto boundedTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return [=](const boxed& dictBounded1) -> boxed {
            return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
                return Data_Tuple::ordTuple()(dictBounded["Ord0"](undefined))(dictBounded1["Ord0"](undefined));
            })(Data_Tuple::Tuple()(Data_Bounded::bottom()(dictBounded))(Data_Bounded::bottom()(dictBounded1)))(Data_Tuple::Tuple()(Data_Bounded::top()(dictBounded))(Data_Bounded::top()(dictBounded1)));
        };
    };
    return _;
};
auto booleanAlgebraTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictBooleanAlgebra) -> boxed {
        return [=](const boxed& dictBooleanAlgebra1) -> boxed {
            return Data_BooleanAlgebra::BooleanAlgebra()([=](const boxed&) -> boxed {
                return Data_Tuple::heytingAlgebraTuple()(dictBooleanAlgebra["HeytingAlgebra0"](undefined))(dictBooleanAlgebra1["HeytingAlgebra0"](undefined));
            });
        };
    };
    return _;
};
auto bifunctorTuple() -> boxed {
    return Data_Bifunctor::Bifunctor()([=](const boxed& f) -> boxed {
        return [=](const boxed& g) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Tuple::Tuple()(f(v["value0"]))(g(v["value1"]));
            };
        };
    });
};
auto bifoldableTuple() -> boxed {
    return Data_Bifoldable::Bifoldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(f(v["value0"]))(g(v["value1"]));
                };
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& g) -> boxed {
            return [=](const boxed& z) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return g(f(z)(v["value0"]))(v["value1"]);
                };
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& g) -> boxed {
            return [=](const boxed& z) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return f(v["value0"])(g(v["value1"])(z));
                };
            };
        };
    });
};
auto bitraversableTuple() -> boxed {
    return Data_Bitraversable::Bitraversable()([=](const boxed&) -> boxed {
        return Data_Tuple::bifoldableTuple();
    })([=](const boxed&) -> boxed {
        return Data_Tuple::bifunctorTuple();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Tuple::Tuple())(v["value0"]))(v["value1"]);
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Tuple::Tuple())(f(v["value0"])))(g(v["value1"]));
                };
            };
        };
    });
};
auto biapplyTuple() -> boxed {
    return Control_Biapply::Biapply()([=](const boxed&) -> boxed {
        return Data_Tuple::bifunctorTuple();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Tuple::Tuple()(v["value0"](v1["value0"]))(v["value1"](v1["value1"]));
        };
    });
};
auto biapplicativeTuple() -> boxed {
    return Control_Biapplicative::Biapplicative()([=](const boxed&) -> boxed {
        return Data_Tuple::biapplyTuple();
    })(Data_Tuple::Tuple());
};
auto applyTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Control_Apply::Apply()([=](const boxed&) -> boxed {
            return Data_Tuple::functorTuple();
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_Tuple::Tuple()(Data_Semigroup::append()(dictSemigroup)(v["value0"])(v1["value0"]))(v["value1"](v1["value1"]));
            };
        });
    };
    return _;
};
auto bindTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Control_Bind::Bind()([=](const boxed&) -> boxed {
            return Data_Tuple::applyTuple()(dictSemigroup);
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& f) -> boxed {
                boxed v1 = f(v["value1"]);
                return Data_Tuple::Tuple()(Data_Semigroup::append()(dictSemigroup)(v["value0"])(v1["value0"]))(v1["value1"]);
            };
        });
    };
    return _;
};
auto applicativeTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
            return Data_Tuple::applyTuple()(dictMonoid["Semigroup0"](undefined));
        })(Data_Tuple::Tuple()(Data_Monoid::mempty()(dictMonoid)));
    };
    return _;
};
auto monadTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return Control_Monad::Monad()([=](const boxed&) -> boxed {
            return Data_Tuple::applicativeTuple()(dictMonoid);
        })([=](const boxed&) -> boxed {
            return Data_Tuple::bindTuple()(dictMonoid["Semigroup0"](undefined));
        });
    };
    return _;
};


} // end namespace Data_Tuple


