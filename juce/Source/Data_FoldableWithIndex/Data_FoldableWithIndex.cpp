#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Maybe_First/Data_Maybe_First.h"
#include "Data_Maybe_Last/Data_Maybe_Last.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Monoid_Additive/Data_Monoid_Additive.h"
#include "Data_Monoid_Conj/Data_Monoid_Conj.h"
#include "Data_Monoid_Disj/Data_Monoid_Disj.h"
#include "Data_Monoid_Dual/Data_Monoid_Dual.h"
#include "Data_Monoid_Endo/Data_Monoid_Endo.h"
#include "Data_Monoid_Multiplicative/Data_Monoid_Multiplicative.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_FoldableWithIndex/Data_FoldableWithIndex.h"


namespace Data_FoldableWithIndex {

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
auto FoldableWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& Foldable0) -> boxed {
        return [=](const boxed& foldMapWithIndex) -> boxed {
            return [=](const boxed& foldlWithIndex) -> boxed {
                return [=](const boxed& foldrWithIndex) -> boxed {
                    return dict_t{
                        { "Foldable0", Foldable0 },
                        { "foldMapWithIndex", foldMapWithIndex },
                        { "foldlWithIndex", foldlWithIndex },
                        { "foldrWithIndex", foldrWithIndex }
                    };
                };
            };
        };
    };
    return _;
};
auto foldrWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["foldrWithIndex"];
    };
    return _;
};
auto traverseWithIndex_() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& dictFoldableWithIndex) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_FoldableWithIndex::foldrWithIndex()(dictFoldableWithIndex)([=](const boxed& i) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Apply::applySecond()(dictApplicative["Apply0"](undefined)))(f(i));
                })(Control_Applicative::pure()(dictApplicative)(Data_Unit::unit()));
            };
        };
    };
    return _;
};
auto forWithIndex_() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& dictFoldableWithIndex) -> boxed {
            return Data_Function::flip()(Data_FoldableWithIndex::traverseWithIndex_()(dictApplicative)(dictFoldableWithIndex));
        };
    };
    return _;
};
auto foldrDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_FoldableWithIndex::foldrWithIndex()(dictFoldableWithIndex)(Data_Function::_const_()(f));
        };
    };
    return _;
};
auto foldlWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["foldlWithIndex"];
    };
    return _;
};
auto foldlDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_FoldableWithIndex::foldlWithIndex()(dictFoldableWithIndex)(Data_Function::_const_()(f));
        };
    };
    return _;
};
auto foldableWithIndexMultiplicative() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableMultiplicative();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldMap()(Data_Foldable::foldableMultiplicative())(dictMonoid)(f(Data_Unit::unit()));
        };
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldl()(Data_Foldable::foldableMultiplicative())(f(Data_Unit::unit()));
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_Foldable::foldableMultiplicative())(f(Data_Unit::unit()));
    });
};
auto foldableWithIndexMaybe() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableMaybe();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldMap()(Data_Foldable::foldableMaybe())(dictMonoid)(f(Data_Unit::unit()));
        };
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldl()(Data_Foldable::foldableMaybe())(f(Data_Unit::unit()));
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_Foldable::foldableMaybe())(f(Data_Unit::unit()));
    });
};
auto foldableWithIndexLast() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableLast();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldMap()(Data_Foldable::foldableLast())(dictMonoid)(f(Data_Unit::unit()));
        };
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldl()(Data_Foldable::foldableLast())(f(Data_Unit::unit()));
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_Foldable::foldableLast())(f(Data_Unit::unit()));
    });
};
auto foldableWithIndexFirst() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableFirst();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldMap()(Data_Foldable::foldableFirst())(dictMonoid)(f(Data_Unit::unit()));
        };
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldl()(Data_Foldable::foldableFirst())(f(Data_Unit::unit()));
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_Foldable::foldableFirst())(f(Data_Unit::unit()));
    });
};
auto foldableWithIndexDual() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableDual();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldMap()(Data_Foldable::foldableDual())(dictMonoid)(f(Data_Unit::unit()));
        };
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldl()(Data_Foldable::foldableDual())(f(Data_Unit::unit()));
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_Foldable::foldableDual())(f(Data_Unit::unit()));
    });
};
auto foldableWithIndexDisj() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableDisj();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldMap()(Data_Foldable::foldableDisj())(dictMonoid)(f(Data_Unit::unit()));
        };
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldl()(Data_Foldable::foldableDisj())(f(Data_Unit::unit()));
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_Foldable::foldableDisj())(f(Data_Unit::unit()));
    });
};
auto foldableWithIndexConj() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableConj();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldMap()(Data_Foldable::foldableConj())(dictMonoid)(f(Data_Unit::unit()));
        };
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldl()(Data_Foldable::foldableConj())(f(Data_Unit::unit()));
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_Foldable::foldableConj())(f(Data_Unit::unit()));
    });
};
auto foldableWithIndexAdditive() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableAdditive();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Foldable::foldMap()(Data_Foldable::foldableAdditive())(dictMonoid)(f(Data_Unit::unit()));
        };
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldl()(Data_Foldable::foldableAdditive())(f(Data_Unit::unit()));
    })([=](const boxed& f) -> boxed {
        return Data_Foldable::foldr()(Data_Foldable::foldableAdditive())(f(Data_Unit::unit()));
    });
};
auto foldWithIndexM() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& a0) -> boxed {
                    return Data_FoldableWithIndex::foldlWithIndex()(dictFoldableWithIndex)([=](const boxed& i) -> boxed {
                        return [=](const boxed& ma) -> boxed {
                            return [=](const boxed& b) -> boxed {
                                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(ma)(Data_Function::flip()(f(i))(b));
                            };
                        };
                    })(Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(a0));
                };
            };
        };
    };
    return _;
};
auto foldMapWithIndexDefaultR() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_FoldableWithIndex::foldrWithIndex()(dictFoldableWithIndex)([=](const boxed& i) -> boxed {
                    return [=](const boxed& x) -> boxed {
                        return [=](const boxed& acc) -> boxed {
                            return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(f(i)(x))(acc);
                        };
                    };
                })(Data_Monoid::mempty()(dictMonoid));
            };
        };
    };
    return _;
};
auto foldableWithIndexArray() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableArray();
    })([=](const boxed& dictMonoid) -> boxed {
        return Data_FoldableWithIndex::foldMapWithIndexDefaultR()(Data_FoldableWithIndex::foldableWithIndexArray())(dictMonoid);
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Foldable::foldl()(Data_Foldable::foldableArray())([=](const boxed& y) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return f(v["value0"])(y)(v["value1"]);
                };
            })(z))(Data_FunctorWithIndex::mapWithIndex()(Data_FunctorWithIndex::functorWithIndexArray())(Data_FoldableWithIndex::Tuple()));
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Foldable::foldr()(Data_Foldable::foldableArray())([=](const boxed& v) -> boxed {
                return [=](const boxed& y) -> boxed {
                    return f(v["value0"])(v["value1"])(y);
                };
            })(z))(Data_FunctorWithIndex::mapWithIndex()(Data_FunctorWithIndex::functorWithIndexArray())(Data_FoldableWithIndex::Tuple()));
        };
    });
};
auto foldMapWithIndexDefaultL() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_FoldableWithIndex::foldlWithIndex()(dictFoldableWithIndex)([=](const boxed& i) -> boxed {
                    return [=](const boxed& acc) -> boxed {
                        return [=](const boxed& x) -> boxed {
                            return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(acc)(f(i)(x));
                        };
                    };
                })(Data_Monoid::mempty()(dictMonoid));
            };
        };
    };
    return _;
};
auto foldMapWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["foldMapWithIndex"];
    };
    return _;
};
auto foldlWithIndexDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& c) -> boxed {
            return [=](const boxed& u) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Newtype::unwrap()(Data_Newtype::newtypeEndo())(Data_Newtype::unwrap()(Data_Newtype::newtypeDual())(Data_FoldableWithIndex::foldMapWithIndex()(dictFoldableWithIndex)(Data_Monoid_Dual::monoidDual()(Data_Monoid_Endo::monoidEndo()(Control_Category::categoryFn())))([=](const boxed& i) -> boxed {
                        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Dual::Dual())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Endo::Endo())(Data_Function::flip()(c(i))));
                    })(xs)))(u);
                };
            };
        };
    };
    return _;
};
auto foldrWithIndexDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& c) -> boxed {
            return [=](const boxed& u) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Newtype::unwrap()(Data_Newtype::newtypeEndo())(Data_FoldableWithIndex::foldMapWithIndex()(dictFoldableWithIndex)(Data_Monoid_Endo::monoidEndo()(Control_Category::categoryFn()))([=](const boxed& i) -> boxed {
                        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Endo::Endo())(c(i));
                    })(xs))(u);
                };
            };
        };
    };
    return _;
};
auto surroundMapWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& dictSemigroup) -> boxed {
            return [=](const boxed& d) -> boxed {
                return [=](const boxed& t) -> boxed {
                    return [=](const boxed& f) -> boxed {
                        boxed joined = [=](const boxed& i) -> boxed {
                            return [=](const boxed& a) -> boxed {
                                return [=](const boxed& m) -> boxed {
                                    return Data_Semigroup::append()(dictSemigroup)(d)(Data_Semigroup::append()(dictSemigroup)(t(i)(a))(m));
                                };
                            };
                        };
                        return Data_Newtype::unwrap()(Data_Newtype::newtypeEndo())(Data_FoldableWithIndex::foldMapWithIndex()(dictFoldableWithIndex)(Data_Monoid_Endo::monoidEndo()(Control_Category::categoryFn()))(joined)(f))(d);
                    };
                };
            };
        };
    };
    return _;
};
auto foldMapDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_FoldableWithIndex::foldMapWithIndex()(dictFoldableWithIndex)(dictMonoid)(Data_Function::_const_()(f));
            };
        };
    };
    return _;
};
auto findWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& p) -> boxed {
            boxed go = [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return [=](const boxed& v2) -> boxed {
                        if (unbox<dict_t>(v1).contains("Nothing")) {
                            if (unbox<bool>(p(v)(v2))) {
                                return Data_Maybe::Just()(dict_t{
                                    { "index", v },
                                    { "value", v2 }
                                });
                            };
                        };
                        return v1;
                    };
                };
            };
            return Data_FoldableWithIndex::foldlWithIndex()(dictFoldableWithIndex)(go)(Data_Maybe::Nothing());
        };
    };
    return _;
};
auto anyWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& dictHeytingAlgebra) -> boxed {
            return [=](const boxed& t) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Newtype::newtypeDisj()))(Data_FoldableWithIndex::foldMapWithIndex()(dictFoldableWithIndex)(Data_Monoid_Disj::monoidDisj()(dictHeytingAlgebra))([=](const boxed& i) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Disj::Disj())(t(i));
                }));
            };
        };
    };
    return _;
};
auto allWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldableWithIndex) -> boxed {
        return [=](const boxed& dictHeytingAlgebra) -> boxed {
            return [=](const boxed& t) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Newtype::newtypeConj()))(Data_FoldableWithIndex::foldMapWithIndex()(dictFoldableWithIndex)(Data_Monoid_Conj::monoidConj()(dictHeytingAlgebra))([=](const boxed& i) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Conj::Conj())(t(i));
                }));
            };
        };
    };
    return _;
};


} // end namespace Data_FoldableWithIndex


