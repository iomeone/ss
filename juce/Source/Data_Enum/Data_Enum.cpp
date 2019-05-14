#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_MonadPlus/Control_MonadPlus.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Either/Data_Either.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Data_Unfoldable1/Data_Unfoldable1.h"
#include "Data_Unit/Data_Unit.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"

#include "Data_Enum/Data_Enum.h"


namespace Data_Enum {

auto Cardinality() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto Enum() -> const boxed& {
    static const boxed _ = [](const boxed& Ord0) -> boxed {
        return [=](const boxed& pred) -> boxed {
            return [=](const boxed& succ) -> boxed {
                return dict_t{
                    { "Ord0", Ord0 },
                    { "pred", pred },
                    { "succ", succ }
                };
            };
        };
    };
    return _;
};
auto BoundedEnum() -> const boxed& {
    static const boxed _ = [](const boxed& Bounded0) -> boxed {
        return [=](const boxed& Enum1) -> boxed {
            return [=](const boxed& cardinality) -> boxed {
                return [=](const boxed& fromEnum) -> boxed {
                    return [=](const boxed& toEnum) -> boxed {
                        return dict_t{
                            { "Bounded0", Bounded0 },
                            { "Enum1", Enum1 },
                            { "cardinality", cardinality },
                            { "fromEnum", fromEnum },
                            { "toEnum", toEnum }
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto toEnum() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["toEnum"];
    };
    return _;
};
auto succ() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["succ"];
    };
    return _;
};
auto upFromIncluding() -> const boxed& {
    static const boxed _ = [](const boxed& dictEnum) -> boxed {
        return [=](const boxed& dictUnfoldable1) -> boxed {
            return Data_Unfoldable1::unfoldr1()(dictUnfoldable1)(Control_Apply::apply()(Control_Apply::applyFn())(Data_Tuple::Tuple())(Data_Enum::succ()(dictEnum)));
        };
    };
    return _;
};
auto showCardinality() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Cardinality ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v))(")"));
    });
};
auto pred() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["pred"];
    };
    return _;
};
auto ordCardinality() -> boxed {
    return Data_Ord::ordInt();
};
auto newtypeCardinality() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_Enum::Cardinality());
};
auto fromEnum() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["fromEnum"];
    };
    return _;
};
auto toEnumWithDefaults() -> const boxed& {
    static const boxed _ = [](const boxed& dictBoundedEnum) -> boxed {
        return [=](const boxed& low) -> boxed {
            return [=](const boxed& high) -> boxed {
                return [=](const boxed& x) -> boxed {
                    boxed v = Data_Enum::toEnum()(dictBoundedEnum)(x);
                    if (unbox<dict_t>(v).contains("Just")) {
                        return v["value0"];
                    };
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        boxed _Local_9 = Data_Ord::lessThan()(Data_Ord::ordInt())(x)(Data_Enum::fromEnum()(dictBoundedEnum)(Data_Bounded::bottom()(dictBoundedEnum["Bounded0"](undefined))));
                        if (unbox<bool>(_Local_9)) {
                            return low;
                        };
                        return high;
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 158, column 33 - line 160, column 62): ");
                };
            };
        };
    };
    return _;
};
auto eqCardinality() -> boxed {
    return Data_Eq::eqInt();
};
auto enumUnit() -> boxed {
    return Data_Enum::Enum()([=](const boxed&) -> boxed {
        return Data_Ord::ordUnit();
    })(Data_Function::_const_()(Data_Maybe::Nothing()))(Data_Function::_const_()(Data_Maybe::Nothing()));
};
auto enumTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictEnum) -> boxed {
        return [=](const boxed& dictBoundedEnum) -> boxed {
            return Data_Enum::Enum()([=](const boxed&) -> boxed {
                return Data_Tuple::ordTuple()(dictEnum["Ord0"](undefined))(dictBoundedEnum["Enum1"](undefined)["Ord0"](undefined));
            })([=](const boxed& v) -> boxed {
                return Data_Maybe::maybe()(Data_Functor::map()(Data_Maybe::functorMaybe())(Data_Function::flip()(Data_Tuple::Tuple())(Data_Bounded::top()(dictBoundedEnum["Bounded0"](undefined))))(Data_Enum::pred()(dictEnum)(v["value0"])))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::Just())(Data_Tuple::Tuple()(v["value0"])))(Data_Enum::pred()(dictBoundedEnum["Enum1"](undefined))(v["value1"]));
            })([=](const boxed& v) -> boxed {
                return Data_Maybe::maybe()(Data_Functor::map()(Data_Maybe::functorMaybe())(Data_Function::flip()(Data_Tuple::Tuple())(Data_Bounded::bottom()(dictBoundedEnum["Bounded0"](undefined))))(Data_Enum::succ()(dictEnum)(v["value0"])))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::Just())(Data_Tuple::Tuple()(v["value0"])))(Data_Enum::succ()(dictBoundedEnum["Enum1"](undefined))(v["value1"]));
            });
        };
    };
    return _;
};
auto enumOrdering() -> boxed {
    return Data_Enum::Enum()([=](const boxed&) -> boxed {
        return Data_Ord::ordOrdering();
    })([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("LT")) {
            return Data_Maybe::Nothing();
        };
        if (unbox<dict_t>(v).contains("EQ")) {
            return Data_Maybe::Just()(Data_Ordering::LT());
        };
        if (unbox<dict_t>(v).contains("GT")) {
            return Data_Maybe::Just()(Data_Ordering::EQ());
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 72, column 1 - line 72, column 39): ");
    })([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("LT")) {
            return Data_Maybe::Just()(Data_Ordering::EQ());
        };
        if (unbox<dict_t>(v).contains("EQ")) {
            return Data_Maybe::Just()(Data_Ordering::GT());
        };
        if (unbox<dict_t>(v).contains("GT")) {
            return Data_Maybe::Nothing();
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 72, column 1 - line 72, column 39): ");
    });
};
auto enumMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictBoundedEnum) -> boxed {
        return Data_Enum::Enum()([=](const boxed&) -> boxed {
            return Data_Maybe::ordMaybe()(dictBoundedEnum["Enum1"](undefined)["Ord0"](undefined));
        })([=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Nothing")) {
                return Data_Maybe::Nothing();
            };
            if (unbox<dict_t>(v).contains("Just")) {
                return Data_Maybe::Just()(Data_Enum::pred()(dictBoundedEnum["Enum1"](undefined))(v["value0"]));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 80, column 1 - line 80, column 54): ");
        })([=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Nothing")) {
                return Data_Maybe::Just()(Data_Maybe::Just()(Data_Bounded::bottom()(dictBoundedEnum["Bounded0"](undefined))));
            };
            if (unbox<dict_t>(v).contains("Just")) {
                return Data_Functor::map()(Data_Maybe::functorMaybe())(Data_Maybe::Just())(Data_Enum::succ()(dictBoundedEnum["Enum1"](undefined))(v["value0"]));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 80, column 1 - line 80, column 54): ");
        });
    };
    return _;
};
auto enumInt() -> boxed {
    return Data_Enum::Enum()([=](const boxed&) -> boxed {
        return Data_Ord::ordInt();
    })([=](const boxed& n) -> boxed {
        boxed _Local_22 = Data_Ord::greaterThan()(Data_Ord::ordInt())(n)(Data_Bounded::bottom()(Data_Bounded::boundedInt()));
        if (unbox<bool>(_Local_22)) {
            return Data_Maybe::Just()(unbox<int>(n) - 1);
        };
        return Data_Maybe::Nothing();
    })([=](const boxed& n) -> boxed {
        boxed _Local_23 = Data_Ord::lessThan()(Data_Ord::ordInt())(n)(Data_Bounded::top()(Data_Bounded::boundedInt()));
        if (unbox<bool>(_Local_23)) {
            return Data_Maybe::Just()(unbox<int>(n) + 1);
        };
        return Data_Maybe::Nothing();
    });
};
auto enumFromTo() -> const boxed& {
    static const boxed _ = [](const boxed& dictEnum) -> boxed {
        return [=](const boxed& dictUnfoldable1) -> boxed {
            boxed go = [=](const boxed& step) -> boxed {
                return [=](const boxed& op) -> boxed {
                    return [=](const boxed& to) -> boxed {
                        return [=](const boxed& a) -> boxed {
                            return Data_Tuple::Tuple()(a)(Control_Bind::bind()(Data_Maybe::bindMaybe())(step(a))([=](const boxed& a_Prime_) -> boxed {
                                return Data_Functor::voidLeft()(Data_Maybe::functorMaybe())(Control_MonadZero::guard()(Data_Maybe::monadZeroMaybe())(op(a_Prime_)(to)))(a_Prime_);
                            }));
                        };
                    };
                };
            };
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    if (unbox<bool>(Data_Eq::eq()(dictEnum["Ord0"](undefined)["Eq0"](undefined))(v)(v1))) {
                        return Data_Unfoldable1::singleton()(dictUnfoldable1)(v);
                    };
                    if (unbox<bool>(Data_Ord::lessThan()(dictEnum["Ord0"](undefined))(v)(v1))) {
                        return Data_Unfoldable1::unfoldr1()(dictUnfoldable1)(go(Data_Enum::succ()(dictEnum))(Data_Ord::lessThanOrEq()(dictEnum["Ord0"](undefined)))(v1))(v);
                    };
                    return Data_Unfoldable1::unfoldr1()(dictUnfoldable1)(go(Data_Enum::pred()(dictEnum))(Data_Ord::greaterThanOrEq()(dictEnum["Ord0"](undefined)))(v1))(v);
                };
            };
        };
    };
    return _;
};
auto enumFromThenTo() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return [=](const boxed& dictFunctor) -> boxed {
            return [=](const boxed& dictBoundedEnum) -> boxed {
                boxed go = [=](const boxed& step) -> boxed {
                    return [=](const boxed& to) -> boxed {
                        return [=](const boxed& e) -> boxed {
                            if (unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(e)(to))) {
                                return Data_Maybe::Just()(Data_Tuple::Tuple()(e)(unbox<int>(e) + unbox<int>(step)));
                            };
                            return Data_Maybe::Nothing();
                        };
                    };
                };
                return [=](const boxed& dictPartial) -> boxed {
                    return [=](const boxed& a) -> boxed {
                        return [=](const boxed& b) -> boxed {
                            return [=](const boxed& c) -> boxed {
                                boxed c_Prime_ = Data_Enum::fromEnum()(dictBoundedEnum)(c);
                                boxed b_Prime_ = Data_Enum::fromEnum()(dictBoundedEnum)(b);
                                boxed a_Prime_ = Data_Enum::fromEnum()(dictBoundedEnum)(a);
                                return Data_Functor::map()(dictFunctor)(Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(Data_Enum::toEnum()(dictBoundedEnum))(Data_Maybe::fromJust()(dictPartial)))(Data_Unfoldable::unfoldr()(dictUnfoldable)(go(unbox<int>(b_Prime_) - unbox<int>(a_Prime_))(c_Prime_))(a_Prime_));
                            };
                        };
                    };
                }(undefined);
            };
        };
    };
    return _;
};
auto enumEither() -> const boxed& {
    static const boxed _ = [](const boxed& dictBoundedEnum) -> boxed {
        return [=](const boxed& dictBoundedEnum1) -> boxed {
            return Data_Enum::Enum()([=](const boxed&) -> boxed {
                return Data_Either::ordEither()(dictBoundedEnum["Enum1"](undefined)["Ord0"](undefined))(dictBoundedEnum1["Enum1"](undefined)["Ord0"](undefined));
            })([=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Left")) {
                    return Data_Maybe::maybe()(Data_Maybe::Nothing())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::Just())(Data_Either::Left()))(Data_Enum::pred()(dictBoundedEnum["Enum1"](undefined))(v["value0"]));
                };
                if (unbox<dict_t>(v).contains("Right")) {
                    return Data_Maybe::maybe()(Data_Maybe::Just()(Data_Either::Left()(Data_Bounded::top()(dictBoundedEnum["Bounded0"](undefined)))))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::Just())(Data_Either::Right()))(Data_Enum::pred()(dictBoundedEnum1["Enum1"](undefined))(v["value0"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 86, column 1 - line 86, column 75): ");
            })([=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Left")) {
                    return Data_Maybe::maybe()(Data_Maybe::Just()(Data_Either::Right()(Data_Bounded::bottom()(dictBoundedEnum1["Bounded0"](undefined)))))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::Just())(Data_Either::Left()))(Data_Enum::succ()(dictBoundedEnum["Enum1"](undefined))(v["value0"]));
                };
                if (unbox<dict_t>(v).contains("Right")) {
                    return Data_Maybe::maybe()(Data_Maybe::Nothing())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::Just())(Data_Either::Right()))(Data_Enum::succ()(dictBoundedEnum1["Enum1"](undefined))(v["value0"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 86, column 1 - line 86, column 75): ");
            });
        };
    };
    return _;
};
auto enumBoolean() -> boxed {
    return Data_Enum::Enum()([=](const boxed&) -> boxed {
        return Data_Ord::ordBoolean();
    })([=](const boxed& v) -> boxed {
        if (unbox<bool>(v)) {
            return Data_Maybe::Just()(false);
        };
        return Data_Maybe::Nothing();
    })([=](const boxed& v) -> boxed {
        if (!(unbox<bool>(v))) {
            return Data_Maybe::Just()(true);
        };
        return Data_Maybe::Nothing();
    });
};
auto downFromIncluding() -> const boxed& {
    static const boxed _ = [](const boxed& dictEnum) -> boxed {
        return [=](const boxed& dictUnfoldable1) -> boxed {
            return Data_Unfoldable1::unfoldr1()(dictUnfoldable1)(Control_Apply::apply()(Control_Apply::applyFn())(Data_Tuple::Tuple())(Data_Enum::pred()(dictEnum)));
        };
    };
    return _;
};
auto diag() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return Data_Tuple::Tuple()(a)(a);
    };
    return _;
};
auto downFrom() -> const boxed& {
    static const boxed _ = [](const boxed& dictEnum) -> boxed {
        return [=](const boxed& dictUnfoldable) -> boxed {
            return Data_Unfoldable::unfoldr()(dictUnfoldable)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Maybe::functorMaybe())(Data_Enum::diag()))(Data_Enum::pred()(dictEnum)));
        };
    };
    return _;
};
auto upFrom() -> const boxed& {
    static const boxed _ = [](const boxed& dictEnum) -> boxed {
        return [=](const boxed& dictUnfoldable) -> boxed {
            return Data_Unfoldable::unfoldr()(dictUnfoldable)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Maybe::functorMaybe())(Data_Enum::diag()))(Data_Enum::succ()(dictEnum)));
        };
    };
    return _;
};
auto defaultToEnum() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return [=](const boxed& dictEnum) -> boxed {
            return [=](const boxed& i_Prime_) -> boxed {
                boxed::recur go;
                boxed::recur::weak go_Weak_(go);
                go = [=](const boxed& i) -> boxed {
                    boxed go = go_Weak_;
                    return [=](const boxed& x) -> boxed {
                        boxed _Local_37 = unbox<int>(i) == 0;
                        if (unbox<bool>(_Local_37)) {
                            return Data_Maybe::Just()(x);
                        };
                        boxed v = Data_Enum::succ()(dictEnum)(x);
                        if (unbox<dict_t>(v).contains("Just")) {
                            return go(unbox<int>(i) - 1)(v["value0"]);
                        };
                        if (unbox<dict_t>(v).contains("Nothing")) {
                            return Data_Maybe::Nothing();
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 293, column 12 - line 295, column 33): ");
                    };
                };
                boxed _Local_40 = Data_Ord::lessThan()(Data_Ord::ordInt())(i_Prime_)(0);
                if (unbox<bool>(_Local_40)) {
                    return Data_Maybe::Nothing();
                };
                return go(i_Prime_)(Data_Bounded::bottom()(dictBounded));
            };
        };
    };
    return _;
};
auto defaultSucc() -> const boxed& {
    static const boxed _ = [](const boxed& toEnum_Prime_) -> boxed {
        return [=](const boxed& fromEnum_Prime_) -> boxed {
            return [=](const boxed& a) -> boxed {
                return toEnum_Prime_(unbox<int>(fromEnum_Prime_(a)) + 1);
            };
        };
    };
    return _;
};
auto defaultPred() -> const boxed& {
    static const boxed _ = [](const boxed& toEnum_Prime_) -> boxed {
        return [=](const boxed& fromEnum_Prime_) -> boxed {
            return [=](const boxed& a) -> boxed {
                return toEnum_Prime_(unbox<int>(fromEnum_Prime_(a)) - 1);
            };
        };
    };
    return _;
};
auto defaultFromEnum() -> const boxed& {
    static const boxed _ = [](const boxed& dictEnum) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& i) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& x) -> boxed {
                boxed v = Data_Enum::pred()(dictEnum)(x);
                if (unbox<dict_t>(v).contains("Just")) {
                    return go(unbox<int>(i) + 1)(v["value0"]);
                };
                if (unbox<dict_t>(v).contains("Nothing")) {
                    return i;
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 306, column 5 - line 308, column 19): ");
            };
        };
        return go(0);
    };
    return _;
};
auto defaultCardinality() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return [=](const boxed& dictEnum) -> boxed {
            boxed::recur go;
            boxed::recur::weak go_Weak_(go);
            go = [=](const boxed& i) -> boxed {
                boxed go = go_Weak_;
                return [=](const boxed& x) -> boxed {
                    boxed v = Data_Enum::succ()(dictEnum)(x);
                    if (unbox<dict_t>(v).contains("Just")) {
                        return go(unbox<int>(i) + 1)(v["value0"]);
                    };
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return i;
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 273, column 5 - line 275, column 19): ");
                };
            };
            return Data_Enum::Cardinality()(go(1)(Data_Bounded::bottom()(dictBounded)));
        };
    };
    return _;
};
auto charToEnum() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<bool>(unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(v)(Data_Bounded::bottom()(Data_Bounded::boundedInt()))) && unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(v)(Data_Bounded::top()(Data_Bounded::boundedInt()))))) {
            return Data_Maybe::Just()(Data_Enum::fromCharCode()(v));
        };
        return Data_Maybe::Nothing();
    };
    return _;
};
auto enumChar() -> boxed {
    return Data_Enum::Enum()([=](const boxed&) -> boxed {
        return Data_Ord::ordChar();
    })(Data_Enum::defaultPred()(Data_Enum::charToEnum())(Data_Enum::toCharCode()))(Data_Enum::defaultSucc()(Data_Enum::charToEnum())(Data_Enum::toCharCode()));
};
auto cardinality() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["cardinality"];
    };
    return _;
};
auto boundedEnumUnit() -> boxed {
    return Data_Enum::BoundedEnum()([=](const boxed&) -> boxed {
        return Data_Bounded::boundedUnit();
    })([=](const boxed&) -> boxed {
        return Data_Enum::enumUnit();
    })(1)(Data_Function::_const_()(0))([=](const boxed& v) -> boxed {
        if (unbox<int>(v) == 0) {
            return Data_Maybe::Just()(Data_Unit::unit());
        };
        return Data_Maybe::Nothing();
    });
};
auto boundedEnumOrdering() -> boxed {
    return Data_Enum::BoundedEnum()([=](const boxed&) -> boxed {
        return Data_Bounded::boundedOrdering();
    })([=](const boxed&) -> boxed {
        return Data_Enum::enumOrdering();
    })(3)([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("LT")) {
            return 0;
        };
        if (unbox<dict_t>(v).contains("EQ")) {
            return 1;
        };
        if (unbox<dict_t>(v).contains("GT")) {
            return 2;
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 137, column 1 - line 137, column 53): ");
    })([=](const boxed& v) -> boxed {
        if (unbox<int>(v) == 0) {
            return Data_Maybe::Just()(Data_Ordering::LT());
        };
        if (unbox<int>(v) == 1) {
            return Data_Maybe::Just()(Data_Ordering::EQ());
        };
        if (unbox<int>(v) == 2) {
            return Data_Maybe::Just()(Data_Ordering::GT());
        };
        return Data_Maybe::Nothing();
    });
};
auto boundedEnumChar() -> boxed {
    return Data_Enum::BoundedEnum()([=](const boxed&) -> boxed {
        return Data_Bounded::boundedChar();
    })([=](const boxed&) -> boxed {
        return Data_Enum::enumChar();
    })(unbox<int>(Data_Enum::toCharCode()(Data_Bounded::top()(Data_Bounded::boundedChar() ) ) ) - unbox<int>(Data_Enum::toCharCode()(Data_Bounded::bottom()(Data_Bounded::boundedChar()))))(Data_Enum::toCharCode())(Data_Enum::charToEnum());
};
auto boundedEnumBoolean() -> boxed {
    return Data_Enum::BoundedEnum()([=](const boxed&) -> boxed {
        return Data_Bounded::boundedBoolean();
    })([=](const boxed&) -> boxed {
        return Data_Enum::enumBoolean();
    })(2)([=](const boxed& v) -> boxed {
        if (!(unbox<bool>(v))) {
            return 0;
        };
        if (unbox<bool>(v)) {
            return 1;
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum (line 118, column 1 - line 118, column 51): ");
    })([=](const boxed& v) -> boxed {
        if (unbox<int>(v) == 0) {
            return Data_Maybe::Just()(false);
        };
        if (unbox<int>(v) == 1) {
            return Data_Maybe::Just()(true);
        };
        return Data_Maybe::Nothing();
    });
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto toCharCode() -> const boxed& { static const boxed _ = foreign().at("toCharCode"); return _; };
auto fromCharCode() -> const boxed& { static const boxed _ = foreign().at("fromCharCode"); return _; };

} // end namespace Data_Enum


