#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Comonad/Control_Comonad.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad/Control_Monad.h"
#include "Data_BooleanAlgebra/Data_BooleanAlgebra.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_CommutativeRing/Data_CommutativeRing.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_FoldableWithIndex/Data_FoldableWithIndex.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Functor_Invariant/Data_Functor_Invariant.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
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

#include "Data_Identity/Data_Identity.h"


namespace Data_Identity {

auto Identity() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Identity ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto semiringIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemiring) -> boxed {
        return dictSemiring;
    };
    return _;
};
auto semigroupIdenity() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return dictSemigroup;
    };
    return _;
};
auto ringIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictRing) -> boxed {
        return dictRing;
    };
    return _;
};
auto ordIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto newtypeIdentity() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_Identity::Identity());
};
auto monoidIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return dictMonoid;
    };
    return _;
};
auto lazyIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictLazy) -> boxed {
        return dictLazy;
    };
    return _;
};
auto heytingAlgebraIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return dictHeytingAlgebra;
    };
    return _;
};
auto functorIdentity() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return f(m);
        };
    });
};
auto functorWithIndexIdentity() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Identity::functorIdentity();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(Data_Unit::unit())(v);
        };
    });
};
auto invariantIdentity() -> boxed {
    return Data_Functor_Invariant::Invariant()(Data_Functor_Invariant::imapF()(Data_Identity::functorIdentity()));
};
auto foldableIdentity() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(z)(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(v)(z);
            };
        };
    });
};
auto foldableWithIndexIdentity() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Identity::foldableIdentity();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(Data_Unit::unit())(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(Data_Unit::unit())(z)(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(Data_Unit::unit())(v)(z);
            };
        };
    });
};
auto traversableIdentity() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Identity::foldableIdentity();
    })([=](const boxed&) -> boxed {
        return Data_Identity::functorIdentity();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Identity::Identity())(v);
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Identity::Identity())(f(v));
            };
        };
    });
};
auto traversableWithIndexIdentity() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_Identity::foldableWithIndexIdentity();
    })([=](const boxed&) -> boxed {
        return Data_Identity::functorWithIndexIdentity();
    })([=](const boxed&) -> boxed {
        return Data_Identity::traversableIdentity();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Identity::Identity())(f(Data_Unit::unit())(v));
            };
        };
    });
};
auto foldable1Identity() -> boxed {
    return Data_Semigroup_Foldable::Foldable1()([=](const boxed&) -> boxed {
        return Data_Identity::foldableIdentity();
    })([=](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& v) -> boxed {
            return v;
        };
    })([=](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(v);
            };
        };
    });
};
auto traversable1Identity() -> boxed {
    return Data_Semigroup_Traversable::Traversable1()([=](const boxed&) -> boxed {
        return Data_Identity::foldable1Identity();
    })([=](const boxed&) -> boxed {
        return Data_Identity::traversableIdentity();
    })([=](const boxed& dictApply) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApply["Functor0"](undefined))(Data_Identity::Identity())(v);
        };
    })([=](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApply["Functor0"](undefined))(Data_Identity::Identity())(f(v));
            };
        };
    });
};
auto extendIdentity() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_Identity::functorIdentity();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return f(m);
        };
    });
};
auto euclideanRingIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictEuclideanRing) -> boxed {
        return dictEuclideanRing;
    };
    return _;
};
auto eqIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto eq1Identity() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Identity::eqIdentity()(dictEq));
    });
};
auto ord1Identity() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Identity::eq1Identity();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Identity::ordIdentity()(dictOrd));
    });
};
auto comonadIdentity() -> boxed {
    return Control_Comonad::Comonad()([=](const boxed&) -> boxed {
        return Data_Identity::extendIdentity();
    })([=](const boxed& v) -> boxed {
        return v;
    });
};
auto commutativeRingIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictCommutativeRing) -> boxed {
        return dictCommutativeRing;
    };
    return _;
};
auto boundedIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return dictBounded;
    };
    return _;
};
auto booleanAlgebraIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictBooleanAlgebra) -> boxed {
        return dictBooleanAlgebra;
    };
    return _;
};
auto applyIdentity() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Identity::functorIdentity();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return v(v1);
        };
    });
};
auto bindIdentity() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Identity::applyIdentity();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& f) -> boxed {
            return f(v);
        };
    });
};
auto applicativeIdentity() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Identity::applyIdentity();
    })(Data_Identity::Identity());
};
auto monadIdentity() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Identity::applicativeIdentity();
    })([=](const boxed&) -> boxed {
        return Data_Identity::bindIdentity();
    });
};
auto altIdentity() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_Identity::functorIdentity();
    })([=](const boxed& x) -> boxed {
        return [=](const boxed& v) -> boxed {
            return x;
        };
    });
};


} // end namespace Data_Identity


