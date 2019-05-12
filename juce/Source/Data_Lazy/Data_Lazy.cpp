#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Comonad/Control_Comonad.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_BooleanAlgebra/Data_BooleanAlgebra.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_CommutativeRing/Data_CommutativeRing.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_FoldableWithIndex/Data_FoldableWithIndex.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Functor_Invariant/Data_Functor_Invariant.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Ord/Data_Ord.h"
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

#include "Data_Lazy/Data_Lazy.h"


namespace Data_Lazy {

auto showLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& x) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(defer \\_ -> ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(Data_Lazy::force()(x)))(")"));
        });
    };
    return _;
};
auto semiringLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemiring) -> boxed {
        return Data_Semiring::Semiring()([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                    return Data_Semiring::add()(dictSemiring)(Data_Lazy::force()(a))(Data_Lazy::force()(b));
                });
            };
        })([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                    return Data_Semiring::mul()(dictSemiring)(Data_Lazy::force()(a))(Data_Lazy::force()(b));
                });
            };
        })(Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_Semiring::one()(dictSemiring);
        }))(Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_Semiring::zero()(dictSemiring);
        }));
    };
    return _;
};
auto semigroupLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                    return Data_Semigroup::append()(dictSemigroup)(Data_Lazy::force()(a))(Data_Lazy::force()(b));
                });
            };
        });
    };
    return _;
};
auto ringLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictRing) -> boxed {
        return Data_Ring::Ring()([=](const boxed&) -> boxed {
            return Data_Lazy::semiringLazy()(dictRing["Semiring0"](undefined));
        })([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                    return Data_Ring::sub()(dictRing)(Data_Lazy::force()(a))(Data_Lazy::force()(b));
                });
            };
        });
    };
    return _;
};
auto monoidLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Data_Lazy::semigroupLazy()(dictMonoid["Semigroup0"](undefined));
        })(Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_Monoid::mempty()(dictMonoid);
        }));
    };
    return _;
};
auto lazyLazy() -> boxed {
    return Control_Lazy::Lazy()([=](const boxed& f) -> boxed {
        return Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_Lazy::force()(f(Data_Unit::unit()));
        });
    });
};
auto functorLazy() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& l) -> boxed {
            return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                return f(Data_Lazy::force()(l));
            });
        };
    });
};
auto functorWithIndexLazy() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Lazy::functorLazy();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Lazy::functorLazy())(f(Data_Unit::unit()));
    });
};
auto invariantLazy() -> boxed {
    return Data_Functor_Invariant::Invariant()(Data_Functor_Invariant::imapF()(Data_Lazy::functorLazy()));
};
auto foldableLazy() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& l) -> boxed {
                return f(Data_Lazy::force()(l));
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& l) -> boxed {
                return f(z)(Data_Lazy::force()(l));
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& l) -> boxed {
                return f(Data_Lazy::force()(l))(z);
            };
        };
    });
};
auto foldableWithIndexLazy() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Lazy::foldableLazy();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldMap()(Data_Lazy::foldableLazy())(dictMonoid)(f(Data_Unit::unit()));
        };
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldl()(Data_Lazy::foldableLazy())(f(Data_Unit::unit()));
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_Lazy::foldableLazy())(f(Data_Unit::unit()));
    });
};
auto traversableLazy() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Lazy::foldableLazy();
    })([=](const boxed&) -> boxed {
        return Data_Lazy::functorLazy();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& l) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Lazy::defer())(Data_Function::_const_()))(Data_Lazy::force()(l));
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& l) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Lazy::defer())(Data_Function::_const_()))(f(Data_Lazy::force()(l)));
            };
        };
    });
};
auto traversableWithIndexLazy() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_Lazy::foldableWithIndexLazy();
    })([=](const boxed&) -> boxed {
        return Data_Lazy::functorWithIndexLazy();
    })([=](const boxed&) -> boxed {
        return Data_Lazy::traversableLazy();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Traversable::traverse()(Data_Lazy::traversableLazy())(dictApplicative)(f(Data_Unit::unit()));
        };
    });
};
auto foldable1Lazy() -> boxed {
    return Data_Semigroup_Foldable::Foldable1()([=](const boxed&) -> boxed {
        return Data_Lazy::foldableLazy();
    })([=](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup_Foldable::fold1Default()(Data_Lazy::foldable1Lazy())(dictSemigroup);
    })([=](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& l) -> boxed {
                return f(Data_Lazy::force()(l));
            };
        };
    });
};
auto traversable1Lazy() -> boxed {
    return Data_Semigroup_Traversable::Traversable1()([=](const boxed&) -> boxed {
        return Data_Lazy::foldable1Lazy();
    })([=](const boxed&) -> boxed {
        return Data_Lazy::traversableLazy();
    })([=](const boxed& dictApply) -> boxed {
        return [=](const boxed& l) -> boxed {
            return Data_Functor::map()(dictApply["Functor0"](undefined))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Lazy::defer())(Data_Function::_const_()))(Data_Lazy::force()(l));
        };
    })([=](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& l) -> boxed {
                return Data_Functor::map()(dictApply["Functor0"](undefined))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Lazy::defer())(Data_Function::_const_()))(f(Data_Lazy::force()(l)));
            };
        };
    });
};
auto extendLazy() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_Lazy::functorLazy();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                return f(x);
            });
        };
    });
};
auto eqLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::Eq()([=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                return Data_Eq::eq()(dictEq)(Data_Lazy::force()(x))(Data_Lazy::force()(y));
            };
        });
    };
    return _;
};
auto ordLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord()([=](const boxed&) -> boxed {
            return Data_Lazy::eqLazy()(dictOrd["Eq0"](undefined));
        })([=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                return Data_Ord::compare()(dictOrd)(Data_Lazy::force()(x))(Data_Lazy::force()(y));
            };
        });
    };
    return _;
};
auto eq1Lazy() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Lazy::eqLazy()(dictEq));
    });
};
auto ord1Lazy() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Lazy::eq1Lazy();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Lazy::ordLazy()(dictOrd));
    });
};
auto comonadLazy() -> boxed {
    return Control_Comonad::Comonad()([=](const boxed&) -> boxed {
        return Data_Lazy::extendLazy();
    })(Data_Lazy::force());
};
auto commutativeRingLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictCommutativeRing) -> boxed {
        return Data_CommutativeRing::CommutativeRing()([=](const boxed&) -> boxed {
            return Data_Lazy::ringLazy()(dictCommutativeRing["Ring0"](undefined));
        });
    };
    return _;
};
auto euclideanRingLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictEuclideanRing) -> boxed {
        return Data_EuclideanRing::EuclideanRing()([=](const boxed&) -> boxed {
            return Data_Lazy::commutativeRingLazy()(dictEuclideanRing["CommutativeRing0"](undefined));
        })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_EuclideanRing::degree()(dictEuclideanRing))(Data_Lazy::force()))([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                    return Data_EuclideanRing::div()(dictEuclideanRing)(Data_Lazy::force()(a))(Data_Lazy::force()(b));
                });
            };
        })([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                    return Data_EuclideanRing::mod()(dictEuclideanRing)(Data_Lazy::force()(a))(Data_Lazy::force()(b));
                });
            };
        });
    };
    return _;
};
auto boundedLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
            return Data_Lazy::ordLazy()(dictBounded["Ord0"](undefined));
        })(Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_Bounded::bottom()(dictBounded);
        }))(Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_Bounded::top()(dictBounded);
        }));
    };
    return _;
};
auto applyLazy() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Lazy::functorLazy();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                return Data_Lazy::force()(f)(Data_Lazy::force()(x));
            });
        };
    });
};
auto bindLazy() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Lazy::applyLazy();
    })([=](const boxed& l) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                return Data_Lazy::force()(f(Data_Lazy::force()(l)));
            });
        };
    });
};
auto heytingAlgebraLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return Data_HeytingAlgebra::HeytingAlgebra()([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Control_Apply::apply()(Data_Lazy::applyLazy())(Data_Functor::map()(Data_Lazy::functorLazy())(Data_HeytingAlgebra::conj()(dictHeytingAlgebra))(a))(b);
            };
        })([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Control_Apply::apply()(Data_Lazy::applyLazy())(Data_Functor::map()(Data_Lazy::functorLazy())(Data_HeytingAlgebra::disj()(dictHeytingAlgebra))(a))(b);
            };
        })(Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_HeytingAlgebra::ff()(dictHeytingAlgebra);
        }))([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Control_Apply::apply()(Data_Lazy::applyLazy())(Data_Functor::map()(Data_Lazy::functorLazy())(Data_HeytingAlgebra::implies()(dictHeytingAlgebra))(a))(b);
            };
        })([=](const boxed& a) -> boxed {
            return Data_Functor::map()(Data_Lazy::functorLazy())(Data_HeytingAlgebra::_not_()(dictHeytingAlgebra))(a);
        })(Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_HeytingAlgebra::tt()(dictHeytingAlgebra);
        }));
    };
    return _;
};
auto booleanAlgebraLazy() -> const boxed& {
    static const boxed _ = [](const boxed& dictBooleanAlgebra) -> boxed {
        return Data_BooleanAlgebra::BooleanAlgebra()([=](const boxed&) -> boxed {
            return Data_Lazy::heytingAlgebraLazy()(dictBooleanAlgebra["HeytingAlgebra0"](undefined));
        });
    };
    return _;
};
auto applicativeLazy() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Lazy::applyLazy();
    })([=](const boxed& a) -> boxed {
        return Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return a;
        });
    });
};
auto monadLazy() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Lazy::applicativeLazy();
    })([=](const boxed&) -> boxed {
        return Data_Lazy::bindLazy();
    });
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto defer() -> const boxed& { static const boxed _ = foreign().at("defer"); return _; };
auto force() -> const boxed& { static const boxed _ = foreign().at("force"); return _; };

} // end namespace Data_Lazy


