#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad_Gen_Class/Control_Monad_Gen_Class.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Monoid_Additive/Data_Monoid_Additive.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Gen/Control_Monad_Gen.h"


namespace Control_Monad_Gen {

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
auto Nil() -> const boxed& {
    static const boxed _ = dict_t{
        { "Nil", true }
    };
    return _;
};
auto FreqSemigroup() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto AtIndex() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto unfoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return [=](const boxed& dictUnfoldable) -> boxed {
                return [=](const boxed& gen) -> boxed {
                    boxed unfold = [=](const boxed& v) -> boxed {
                        if (unbox<dict_t>(v).contains("Nil")) {
                            return Data_Maybe::Nothing();
                        };
                        if (unbox<dict_t>(v).contains("Cons")) {
                            return Data_Maybe::Just()(Data_Tuple::Tuple()(v["value0"])(v["value1"]));
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Gen (line 101, column 12 - line 103, column 35): ");
                    };
                    boxed loopGen = [=](const boxed& v) -> boxed {
                        if (unbox<int>(v["value1"]) == 0) {
                            return Control_Applicative::pure()(dictMonadGen["Monad0"](undefined)["Applicative0"](undefined))(Control_Monad_Rec_Class::Done()(v["value0"]));
                        };
                        return Control_Bind::bind()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined))(gen)([=](const boxed& v1) -> boxed {
                            return Control_Applicative::pure()(dictMonadGen["Monad0"](undefined)["Applicative0"](undefined))(Control_Monad_Rec_Class::Loop()(Data_Tuple::Tuple()(Control_Monad_Gen::Cons()(v1)(v["value0"]))(unbox<int>(v["value1"]) - 1)));
                        });
                    };
                    return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Unfoldable::unfoldr()(dictUnfoldable)(unfold))(Control_Monad_Gen_Class::sized()(dictMonadGen)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Rec_Class::tailRecM()(dictMonadRec)(loopGen))(Data_Tuple::Tuple()(Control_Monad_Gen::Nil()))));
                };
            };
        };
    };
    return _;
};
auto semigroupFreqSemigroup() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& pos) -> boxed {
                boxed v2 = v(pos);
                if (unbox<dict_t>(v2["value0"]).contains("Just")) {
                    return v1(v2["value0"]["value0"]);
                };
                return v2;
            };
        };
    });
};
auto semigroupAtIndex() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& i) -> boxed {
                boxed _Local_22 = Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(i)(0);
                if (unbox<bool>(_Local_22)) {
                    return v(i);
                };
                return v1(unbox<int>(i) - 1);
            };
        };
    });
};
auto getFreqVal() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Tuple::snd())(v);
    };
    return _;
};
auto getAtIndex() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto freqSemigroup() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& pos) -> boxed {
            boxed _Local_26 = Data_Ord::greaterThanOrEq()(Data_Ord::ordNumber())(pos)(v["value0"]);
            if (unbox<bool>(_Local_26)) {
                return Data_Tuple::Tuple()(Data_Maybe::Just()(unbox<double>(pos) - unbox<double>(v["value0"])))(v["value1"]);
            };
            return Data_Tuple::Tuple()(Data_Maybe::Nothing())(v["value1"]);
        };
    };
    return _;
};
auto frequency() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return [=](const boxed& dictFoldable1) -> boxed {
            return [=](const boxed& xs) -> boxed {
                boxed total = Data_Newtype::alaF()(Data_Functor::functorFn())(Data_Functor::functorFn())(Data_Newtype::newtypeAdditive())(Data_Newtype::newtypeAdditive())(Data_Monoid_Additive::Additive())(Data_Foldable::foldMap()(dictFoldable1["Foldable0"](undefined))(Data_Monoid_Additive::monoidAdditive()(Data_Semiring::semiringNumber())))(Data_Tuple::fst())(xs);
                return Control_Bind::bind()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Gen_Class::chooseFloat()(dictMonadGen)(0.0)(total))(Control_Monad_Gen::getFreqVal()(Data_Semigroup_Foldable::foldMap1()(dictFoldable1)(Control_Monad_Gen::semigroupFreqSemigroup())(Control_Monad_Gen::freqSemigroup())(xs)));
            };
        };
    };
    return _;
};
auto filtered() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return [=](const boxed& gen) -> boxed {
                boxed go = [=](const boxed& v) -> boxed {
                    return Data_Functor::mapFlipped()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(gen)([=](const boxed& a) -> boxed {
                        if (unbox<dict_t>(a).contains("Nothing")) {
                            return Control_Monad_Rec_Class::Loop()(Data_Unit::unit());
                        };
                        if (unbox<dict_t>(a).contains("Just")) {
                            return Control_Monad_Rec_Class::Done()(a["value0"]);
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Gen (line 117, column 24 - line 119, column 23): ");
                    });
                };
                return Control_Monad_Rec_Class::tailRecM()(dictMonadRec)(go)(Data_Unit::unit());
            };
        };
    };
    return _;
};
auto suchThat() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return [=](const boxed& gen) -> boxed {
                return [=](const boxed& pred) -> boxed {
                    return Control_Monad_Gen::filtered()(dictMonadRec)(dictMonadGen)(Data_Functor::mapFlipped()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(gen)([=](const boxed& a) -> boxed {
                        boxed _Local_31 = pred(a);
                        if (unbox<bool>(_Local_31)) {
                            return Data_Maybe::Just()(a);
                        };
                        return Data_Maybe::Nothing();
                    }));
                };
            };
        };
    };
    return _;
};
auto choose() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return [=](const boxed& genA) -> boxed {
            return [=](const boxed& genB) -> boxed {
                return Control_Bind::bind()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Gen_Class::chooseBool()(dictMonadGen))([=](const boxed& v) -> boxed {
                    if (unbox<bool>(v)) {
                        return genA;
                    };
                    return genB;
                });
            };
        };
    };
    return _;
};
auto atIndex() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Gen::AtIndex())(Data_Function::_const_());
};
auto fromIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& i) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return Control_Monad_Gen::getAtIndex()(Data_Semigroup_Foldable::foldMap1()(dictFoldable1)(Control_Monad_Gen::semigroupAtIndex())(Control_Monad_Gen::atIndex())(xs))(i);
            };
        };
    };
    return _;
};
auto elements() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return [=](const boxed& dictFoldable1) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return Control_Bind::bind()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Gen_Class::chooseInt()(dictMonadGen)(0)(unbox<int>(Data_Foldable::length()(dictFoldable1["Foldable0"](undefined))(Data_Semiring::semiringInt())(xs)) - 1))([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonadGen["Monad0"](undefined)["Applicative0"](undefined))(Control_Monad_Gen::fromIndex()(dictFoldable1)(v)(xs));
                });
            };
        };
    };
    return _;
};
auto oneOf() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return [=](const boxed& dictFoldable1) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return Control_Bind::bind()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Gen_Class::chooseInt()(dictMonadGen)(0)(unbox<int>(Data_Foldable::length()(dictFoldable1["Foldable0"](undefined))(Data_Semiring::semiringInt())(xs)) - 1))([=](const boxed& v) -> boxed {
                    return Control_Monad_Gen::fromIndex()(dictFoldable1)(v)(xs);
                });
            };
        };
    };
    return _;
};


} // end namespace Control_Monad_Gen


