#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Category/Control_Category.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Bifunctor_Clown/Data_Bifunctor_Clown.h"
#include "Data_Bifunctor_Flip/Data_Bifunctor_Flip.h"
#include "Data_Bifunctor_Joker/Data_Bifunctor_Joker.h"
#include "Data_Bifunctor_Product/Data_Bifunctor_Product.h"
#include "Data_Bifunctor_Wrap/Data_Bifunctor_Wrap.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Monoid_Conj/Data_Monoid_Conj.h"
#include "Data_Monoid_Disj/Data_Monoid_Disj.h"
#include "Data_Monoid_Dual/Data_Monoid_Dual.h"
#include "Data_Monoid_Endo/Data_Monoid_Endo.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_Bifoldable/Data_Bifoldable.h"


namespace Data_Bifoldable {

auto Bifoldable() -> const boxed& {
    static const boxed _ = [](const boxed& bifoldMap) -> boxed {
        return [=](const boxed& bifoldl) -> boxed {
            return [=](const boxed& bifoldr) -> boxed {
                return dict_t{
                    { "bifoldMap", bifoldMap },
                    { "bifoldl", bifoldl },
                    { "bifoldr", bifoldr }
                };
            };
        };
    };
    return _;
};
auto bifoldr() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["bifoldr"];
    };
    return _;
};
auto bitraverse_() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& g) -> boxed {
                    return Data_Bifoldable::bifoldr()(dictBifoldable)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Apply::applySecond()(dictApplicative["Apply0"](undefined)))(f))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Apply::applySecond()(dictApplicative["Apply0"](undefined)))(g))(Control_Applicative::pure()(dictApplicative)(Data_Unit::unit()));
                };
            };
        };
    };
    return _;
};
auto bifor_() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& t) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return [=](const boxed& g) -> boxed {
                        return Data_Bifoldable::bitraverse_()(dictBifoldable)(dictApplicative)(f)(g)(t);
                    };
                };
            };
        };
    };
    return _;
};
auto bisequence_() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return Data_Bifoldable::bitraverse_()(dictBifoldable)(dictApplicative)(Control_Category::identity()(Control_Category::categoryFn()))(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto bifoldl() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["bifoldl"];
    };
    return _;
};
auto bifoldableJoker() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Data_Bifoldable::Bifoldable()([=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        return Data_Foldable::foldMap()(dictFoldable)(dictMonoid)(r)(v1);
                    };
                };
            };
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& u) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        return Data_Foldable::foldl()(dictFoldable)(r)(u)(v1);
                    };
                };
            };
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& u) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        return Data_Foldable::foldr()(dictFoldable)(r)(u)(v1);
                    };
                };
            };
        });
    };
    return _;
};
auto bifoldableClown() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Data_Bifoldable::Bifoldable()([=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& l) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        return Data_Foldable::foldMap()(dictFoldable)(dictMonoid)(l)(v1);
                    };
                };
            };
        })([=](const boxed& l) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& u) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        return Data_Foldable::foldl()(dictFoldable)(l)(u)(v1);
                    };
                };
            };
        })([=](const boxed& l) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& u) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        return Data_Foldable::foldr()(dictFoldable)(l)(u)(v1);
                    };
                };
            };
        });
    };
    return _;
};
auto bifoldMapDefaultR() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& g) -> boxed {
                    return Data_Bifoldable::bifoldr()(dictBifoldable)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined)))(f))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined)))(g))(Data_Monoid::mempty()(dictMonoid));
                };
            };
        };
    };
    return _;
};
auto bifoldMapDefaultL() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& g) -> boxed {
                    return Data_Bifoldable::bifoldl()(dictBifoldable)([=](const boxed& m) -> boxed {
                        return [=](const boxed& a) -> boxed {
                            return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(m)(f(a));
                        };
                    })([=](const boxed& m) -> boxed {
                        return [=](const boxed& b) -> boxed {
                            return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(m)(g(b));
                        };
                    })(Data_Monoid::mempty()(dictMonoid));
                };
            };
        };
    };
    return _;
};
auto bifoldMap() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["bifoldMap"];
    };
    return _;
};
auto bifoldableFlip() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return Data_Bifoldable::Bifoldable()([=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& l) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return Data_Bifoldable::bifoldMap()(dictBifoldable)(dictMonoid)(l)(r)(v);
                    };
                };
            };
        })([=](const boxed& r) -> boxed {
            return [=](const boxed& l) -> boxed {
                return [=](const boxed& u) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return Data_Bifoldable::bifoldl()(dictBifoldable)(l)(r)(u)(v);
                    };
                };
            };
        })([=](const boxed& r) -> boxed {
            return [=](const boxed& l) -> boxed {
                return [=](const boxed& u) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return Data_Bifoldable::bifoldr()(dictBifoldable)(l)(r)(u)(v);
                    };
                };
            };
        });
    };
    return _;
};
auto bifoldableWrap() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return Data_Bifoldable::Bifoldable()([=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& l) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return Data_Bifoldable::bifoldMap()(dictBifoldable)(dictMonoid)(l)(r)(v);
                    };
                };
            };
        })([=](const boxed& l) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& u) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return Data_Bifoldable::bifoldl()(dictBifoldable)(l)(r)(u)(v);
                    };
                };
            };
        })([=](const boxed& l) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& u) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return Data_Bifoldable::bifoldr()(dictBifoldable)(l)(r)(u)(v);
                    };
                };
            };
        });
    };
    return _;
};
auto bifoldlDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& z) -> boxed {
                    return [=](const boxed& p) -> boxed {
                        return Data_Newtype::unwrap()(Data_Newtype::newtypeEndo())(Data_Newtype::unwrap()(Data_Newtype::newtypeDual())(Data_Bifoldable::bifoldMap()(dictBifoldable)(Data_Monoid_Dual::monoidDual()(Data_Monoid_Endo::monoidEndo()(Control_Category::categoryFn())))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Dual::Dual())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Endo::Endo())(Data_Function::flip()(f))))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Dual::Dual())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Endo::Endo())(Data_Function::flip()(g))))(p)))(z);
                    };
                };
            };
        };
    };
    return _;
};
auto bifoldrDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& z) -> boxed {
                    return [=](const boxed& p) -> boxed {
                        return Data_Newtype::unwrap()(Data_Newtype::newtypeEndo())(Data_Bifoldable::bifoldMap()(dictBifoldable)(Data_Monoid_Endo::monoidEndo()(Control_Category::categoryFn()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Endo::Endo())(f))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Endo::Endo())(g))(p))(z);
                    };
                };
            };
        };
    };
    return _;
};
auto bifoldableProduct() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& dictBifoldable1) -> boxed {
            return Data_Bifoldable::Bifoldable()([=](const boxed& dictMonoid) -> boxed {
                return [=](const boxed& l) -> boxed {
                    return [=](const boxed& r) -> boxed {
                        return [=](const boxed& v) -> boxed {
                            return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(Data_Bifoldable::bifoldMap()(dictBifoldable)(dictMonoid)(l)(r)(v["value0"]))(Data_Bifoldable::bifoldMap()(dictBifoldable1)(dictMonoid)(l)(r)(v["value1"]));
                        };
                    };
                };
            })([=](const boxed& l) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return [=](const boxed& u) -> boxed {
                        return [=](const boxed& m) -> boxed {
                            return Data_Bifoldable::bifoldlDefault()(Data_Bifoldable::bifoldableProduct()(dictBifoldable)(dictBifoldable1))(l)(r)(u)(m);
                        };
                    };
                };
            })([=](const boxed& l) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return [=](const boxed& u) -> boxed {
                        return [=](const boxed& m) -> boxed {
                            return Data_Bifoldable::bifoldrDefault()(Data_Bifoldable::bifoldableProduct()(dictBifoldable)(dictBifoldable1))(l)(r)(u)(m);
                        };
                    };
                };
            });
        };
    };
    return _;
};
auto bifold() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Data_Bifoldable::bifoldMap()(dictBifoldable)(dictMonoid)(Control_Category::identity()(Control_Category::categoryFn()))(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto biany() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& dictBooleanAlgebra) -> boxed {
            return [=](const boxed& p) -> boxed {
                return [=](const boxed& q) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Newtype::newtypeDisj()))(Data_Bifoldable::bifoldMap()(dictBifoldable)(Data_Monoid_Disj::monoidDisj()(dictBooleanAlgebra["HeytingAlgebra0"](undefined)))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Disj::Disj())(p))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Disj::Disj())(q)));
                };
            };
        };
    };
    return _;
};
auto biall() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifoldable) -> boxed {
        return [=](const boxed& dictBooleanAlgebra) -> boxed {
            return [=](const boxed& p) -> boxed {
                return [=](const boxed& q) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Newtype::newtypeConj()))(Data_Bifoldable::bifoldMap()(dictBifoldable)(Data_Monoid_Conj::monoidConj()(dictBooleanAlgebra["HeytingAlgebra0"](undefined)))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Conj::Conj())(p))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Conj::Conj())(q)));
                };
            };
        };
    };
    return _;
};


} // end namespace Data_Bifoldable


