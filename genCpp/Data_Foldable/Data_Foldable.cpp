#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Plus/Control_Plus.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
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
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_Foldable/Data_Foldable.h"


namespace Data_Foldable {

auto Foldable() -> const boxed& {
    static const boxed _ = [](const boxed& foldMap) -> boxed {
        return [=](const boxed& foldl) -> boxed {
            return [=](const boxed& foldr) -> boxed {
                return dict_t{
                    { "foldMap", foldMap },
                    { "foldl", foldl },
                    { "foldr", foldr }
                };
            };
        };
    };
    return _;
};
auto foldr() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["foldr"];
    };
    return _;
};
auto indexr() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& idx) -> boxed {
            boxed go = [=](const boxed& a) -> boxed {
                return [=](const boxed& cursor) -> boxed {
                    if (unbox<dict_t>(cursor["elem"]).contains("Just")) {
                        return cursor;
                    };
                    boxed _Local_7 = unbox<int>(cursor["pos"]) == unbox<int>(idx);
                    if (unbox<bool>(_Local_7)) {
                        return dict_t{
                            { "elem", Data_Maybe::Just()(a) },
                            { "pos", cursor["pos"] }
                        };
                    };
                    return dict_t{
                        { "pos", unbox<int>(cursor["pos"]) + 1 },
                        { "elem", cursor["elem"] }
                    };
                };
            };
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())([=](const boxed& v) -> boxed {
                return v["elem"];
            })(Data_Foldable::foldr()(dictFoldable)(go)(dict_t{
                { "elem", Data_Maybe::Nothing() },
                { "pos", 0 }
            }));
        };
    };
    return _;
};
auto null() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Data_Foldable::foldr()(dictFoldable)([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return false;
            };
        })(true);
    };
    return _;
};
auto oneOf() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictPlus) -> boxed {
            return Data_Foldable::foldr()(dictFoldable)(Control_Alt::alt()(dictPlus["Alt0"](undefined)))(Control_Plus::empty()(dictPlus));
        };
    };
    return _;
};
auto oneOfMap() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictPlus) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_Foldable::foldr()(dictFoldable)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Alt::alt()(dictPlus["Alt0"](undefined)))(f))(Control_Plus::empty()(dictPlus));
            };
        };
    };
    return _;
};
auto traverse_() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& dictFoldable) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_Foldable::foldr()(dictFoldable)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Apply::applySecond()(dictApplicative["Apply0"](undefined)))(f))(Control_Applicative::pure()(dictApplicative)(Data_Unit::unit()));
            };
        };
    };
    return _;
};
auto for_() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& dictFoldable) -> boxed {
            return Data_Function::flip()(Data_Foldable::traverse_()(dictApplicative)(dictFoldable));
        };
    };
    return _;
};
auto sequence_() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& dictFoldable) -> boxed {
            return Data_Foldable::traverse_()(dictApplicative)(dictFoldable)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto foldl() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["foldl"];
    };
    return _;
};
auto indexl() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& idx) -> boxed {
            boxed go = [=](const boxed& cursor) -> boxed {
                return [=](const boxed& a) -> boxed {
                    if (unbox<dict_t>(cursor["elem"]).contains("Just")) {
                        return cursor;
                    };
                    boxed _Local_10 = unbox<int>(cursor["pos"]) == unbox<int>(idx);
                    if (unbox<bool>(_Local_10)) {
                        return dict_t{
                            { "elem", Data_Maybe::Just()(a) },
                            { "pos", cursor["pos"] }
                        };
                    };
                    return dict_t{
                        { "pos", unbox<int>(cursor["pos"]) + 1 },
                        { "elem", cursor["elem"] }
                    };
                };
            };
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())([=](const boxed& v) -> boxed {
                return v["elem"];
            })(Data_Foldable::foldl()(dictFoldable)(go)(dict_t{
                { "elem", Data_Maybe::Nothing() },
                { "pos", 0 }
            }));
        };
    };
    return _;
};
auto intercalate() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& sep) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    boxed go = [=](const boxed& v) -> boxed {
                        return [=](const boxed& x) -> boxed {
                            if (unbox<bool>(v["init"])) {
                                return dict_t{
                                    { "init", false },
                                    { "acc", x }
                                };
                            };
                            return dict_t{
                                { "init", false },
                                { "acc", Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(v["acc"])(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(sep)(x)) }
                            };
                        };
                    };
                    return Data_Foldable::foldl()(dictFoldable)(go)(dict_t{
                        { "init", true },
                        { "acc", Data_Monoid::mempty()(dictMonoid) }
                    })(xs)["acc"];
                };
            };
        };
    };
    return _;
};
auto length() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictSemiring) -> boxed {
            return Data_Foldable::foldl()(dictFoldable)([=](const boxed& c) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Semiring::add()(dictSemiring)(Data_Semiring::one()(dictSemiring))(c);
                };
            })(Data_Semiring::zero()(dictSemiring));
        };
    };
    return _;
};
auto maximumBy() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& cmp) -> boxed {
            boxed max_Prime_ = [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Data_Maybe::Just()(v1);
                    };
                    if (unbox<dict_t>(v).contains("Just")) {
                        return Data_Maybe::Just()([=]() -> boxed {
                            boxed _Local_17 = Data_Eq::eq()(Data_Ordering::eqOrdering())(cmp(v["value0"])(v1))(Data_Ordering::GT());
                            if (unbox<bool>(_Local_17)) {
                                return v["value0"];
                            };
                            return v1;
                        }());
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Foldable (line 389, column 3 - line 389, column 27): ");
                };
            };
            return Data_Foldable::foldl()(dictFoldable)(max_Prime_)(Data_Maybe::Nothing());
        };
    };
    return _;
};
auto maximum() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictFoldable) -> boxed {
            return Data_Foldable::maximumBy()(dictFoldable)(Data_Ord::compare()(dictOrd));
        };
    };
    return _;
};
auto minimumBy() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& cmp) -> boxed {
            boxed min_Prime_ = [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Data_Maybe::Just()(v1);
                    };
                    if (unbox<dict_t>(v).contains("Just")) {
                        return Data_Maybe::Just()([=]() -> boxed {
                            boxed _Local_21 = Data_Eq::eq()(Data_Ordering::eqOrdering())(cmp(v["value0"])(v1))(Data_Ordering::LT());
                            if (unbox<bool>(_Local_21)) {
                                return v["value0"];
                            };
                            return v1;
                        }());
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Foldable (line 402, column 3 - line 402, column 27): ");
                };
            };
            return Data_Foldable::foldl()(dictFoldable)(min_Prime_)(Data_Maybe::Nothing());
        };
    };
    return _;
};
auto minimum() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictFoldable) -> boxed {
            return Data_Foldable::minimumBy()(dictFoldable)(Data_Ord::compare()(dictOrd));
        };
    };
    return _;
};
auto product() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictSemiring) -> boxed {
            return Data_Foldable::foldl()(dictFoldable)(Data_Semiring::mul()(dictSemiring))(Data_Semiring::one()(dictSemiring));
        };
    };
    return _;
};
auto sum() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictSemiring) -> boxed {
            return Data_Foldable::foldl()(dictFoldable)(Data_Semiring::add()(dictSemiring))(Data_Semiring::zero()(dictSemiring));
        };
    };
    return _;
};
auto foldableMultiplicative() -> boxed {
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
auto foldableMaybe() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Nothing")) {
                    return Data_Monoid::mempty()(dictMonoid);
                };
                if (unbox<dict_t>(v).contains("Just")) {
                    return f(v["value0"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Foldable (line 129, column 1 - line 129, column 41): ");
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Nothing")) {
                    return z;
                };
                if (unbox<dict_t>(v1).contains("Just")) {
                    return v(z)(v1["value0"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Foldable (line 129, column 1 - line 129, column 41): ");
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Nothing")) {
                    return z;
                };
                if (unbox<dict_t>(v1).contains("Just")) {
                    return v(v1["value0"])(z);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Foldable (line 129, column 1 - line 129, column 41): ");
            };
        };
    });
};
auto foldableDual() -> boxed {
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
auto foldableDisj() -> boxed {
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
auto foldableConj() -> boxed {
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
auto foldableAdditive() -> boxed {
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
auto foldMapDefaultR() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_Foldable::foldr()(dictFoldable)([=](const boxed& x) -> boxed {
                    return [=](const boxed& acc) -> boxed {
                        return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(f(x))(acc);
                    };
                })(Data_Monoid::mempty()(dictMonoid));
            };
        };
    };
    return _;
};
auto foldableArray() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return Data_Foldable::foldMapDefaultR()(Data_Foldable::foldableArray())(dictMonoid);
    })(Data_Foldable::foldlArray())(Data_Foldable::foldrArray());
};
auto foldMapDefaultL() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_Foldable::foldl()(dictFoldable)([=](const boxed& acc) -> boxed {
                    return [=](const boxed& x) -> boxed {
                        return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(acc)(f(x));
                    };
                })(Data_Monoid::mempty()(dictMonoid));
            };
        };
    };
    return _;
};
auto foldMap() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["foldMap"];
    };
    return _;
};
auto foldableFirst() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldMap()(Data_Foldable::foldableMaybe())(dictMonoid)(f)(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldl()(Data_Foldable::foldableMaybe())(f)(z)(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldr()(Data_Foldable::foldableMaybe())(f)(z)(v);
            };
        };
    });
};
auto foldableLast() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldMap()(Data_Foldable::foldableMaybe())(dictMonoid)(f)(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldl()(Data_Foldable::foldableMaybe())(f)(z)(v);
            };
        };
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Foldable::foldr()(Data_Foldable::foldableMaybe())(f)(z)(v);
            };
        };
    });
};
auto foldlDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& c) -> boxed {
            return [=](const boxed& u) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Newtype::unwrap()(Data_Newtype::newtypeEndo())(Data_Newtype::unwrap()(Data_Newtype::newtypeDual())(Data_Foldable::foldMap()(dictFoldable)(Data_Monoid_Dual::monoidDual()(Data_Monoid_Endo::monoidEndo()(Control_Category::categoryFn())))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Dual::Dual())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Endo::Endo())(Data_Function::flip()(c))))(xs)))(u);
                };
            };
        };
    };
    return _;
};
auto foldrDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& c) -> boxed {
            return [=](const boxed& u) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Newtype::unwrap()(Data_Newtype::newtypeEndo())(Data_Foldable::foldMap()(dictFoldable)(Data_Monoid_Endo::monoidEndo()(Control_Category::categoryFn()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Monoid_Endo::Endo())(c))(xs))(u);
                };
            };
        };
    };
    return _;
};
auto surroundMap() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictSemigroup) -> boxed {
            return [=](const boxed& d) -> boxed {
                return [=](const boxed& t) -> boxed {
                    return [=](const boxed& f) -> boxed {
                        boxed joined = [=](const boxed& a) -> boxed {
                            return [=](const boxed& m) -> boxed {
                                return Data_Semigroup::append()(dictSemigroup)(d)(Data_Semigroup::append()(dictSemigroup)(t(a))(m));
                            };
                        };
                        return Data_Newtype::unwrap()(Data_Newtype::newtypeEndo())(Data_Foldable::foldMap()(dictFoldable)(Data_Monoid_Endo::monoidEndo()(Control_Category::categoryFn()))(joined)(f))(d);
                    };
                };
            };
        };
    };
    return _;
};
auto surround() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictSemigroup) -> boxed {
            return [=](const boxed& d) -> boxed {
                return Data_Foldable::surroundMap()(dictFoldable)(dictSemigroup)(d)(Control_Category::identity()(Control_Category::categoryFn()));
            };
        };
    };
    return _;
};
auto foldM() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& a0) -> boxed {
                    return Data_Foldable::foldl()(dictFoldable)([=](const boxed& ma) -> boxed {
                        return [=](const boxed& b) -> boxed {
                            return Control_Bind::bind()(dictMonad["Bind1"](undefined))(ma)(Data_Function::flip()(f)(b));
                        };
                    })(Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(a0));
                };
            };
        };
    };
    return _;
};
auto fold() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Data_Foldable::foldMap()(dictFoldable)(dictMonoid)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto findMap() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& p) -> boxed {
            boxed go = [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return p(v1);
                    };
                    return v;
                };
            };
            return Data_Foldable::foldl()(dictFoldable)(go)(Data_Maybe::Nothing());
        };
    };
    return _;
};
auto find() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& p) -> boxed {
            boxed go = [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        if (unbox<bool>(p(v1))) {
                            return Data_Maybe::Just()(v1);
                        };
                    };
                    return v;
                };
            };
            return Data_Foldable::foldl()(dictFoldable)(go)(Data_Maybe::Nothing());
        };
    };
    return _;
};
auto any() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictHeytingAlgebra) -> boxed {
            return Data_Newtype::alaF()(Data_Functor::functorFn())(Data_Functor::functorFn())(Data_Newtype::newtypeDisj())(Data_Newtype::newtypeDisj())(Data_Monoid_Disj::Disj())(Data_Foldable::foldMap()(dictFoldable)(Data_Monoid_Disj::monoidDisj()(dictHeytingAlgebra)));
        };
    };
    return _;
};
auto elem() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictEq) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Foldable::any()(dictFoldable)(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_Eq::eq()(dictEq));
        };
    };
    return _;
};
auto notElem() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictEq) -> boxed {
            return [=](const boxed& x) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_HeytingAlgebra::_not_()(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_Foldable::elem()(dictFoldable)(dictEq)(x));
            };
        };
    };
    return _;
};
auto _or_() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictHeytingAlgebra) -> boxed {
            return Data_Foldable::any()(dictFoldable)(dictHeytingAlgebra)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto all() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictHeytingAlgebra) -> boxed {
            return Data_Newtype::alaF()(Data_Functor::functorFn())(Data_Functor::functorFn())(Data_Newtype::newtypeConj())(Data_Newtype::newtypeConj())(Data_Monoid_Conj::Conj())(Data_Foldable::foldMap()(dictFoldable)(Data_Monoid_Conj::monoidConj()(dictHeytingAlgebra)));
        };
    };
    return _;
};
auto _and_() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictHeytingAlgebra) -> boxed {
            return Data_Foldable::all()(dictFoldable)(dictHeytingAlgebra)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto foldrArray() -> const boxed& { static const boxed _ = foreign().at("foldrArray"); return _; };
auto foldlArray() -> const boxed& { static const boxed _ = foreign().at("foldlArray"); return _; };

} // end namespace Data_Foldable


