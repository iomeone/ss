#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Bifoldable/Data_Bifoldable.h"
#include "Data_Bifunctor/Data_Bifunctor.h"
#include "Data_Bitraversable/Data_Bitraversable.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_FoldableWithIndex/Data_FoldableWithIndex.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Functor_Invariant/Data_Functor_Invariant.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_TraversableWithIndex/Data_TraversableWithIndex.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_Either/Data_Either.h"


namespace Data_Either {

auto Left() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "Left", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto Right() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "Right", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto showEither() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& dictShow1) -> boxed {
            return Data_Show::Show()([=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Left")) {
                    return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Left ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v["value0"]))(")"));
                };
                if (unbox<dict_t>(v).contains("Right")) {
                    return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Right ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow1)(v["value0"]))(")"));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 163, column 1 - line 163, column 61): ");
            });
        };
    };
    return _;
};
auto note_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Maybe::maybe_Prime_()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Either::Left())(f))(Data_Either::Right());
    };
    return _;
};
auto note() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return Data_Maybe::maybe()(Data_Either::Left()(a))(Data_Either::Right());
    };
    return _;
};
auto functorEither() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            if (unbox<dict_t>(m).contains("Left")) {
                return Data_Either::Left()(m["value0"]);
            };
            if (unbox<dict_t>(m).contains("Right")) {
                return Data_Either::Right()(f(m["value0"]));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 38, column 8 - line 38, column 52): ");
        };
    });
};
auto functorWithIndexEither() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Either::functorEither();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Either::functorEither())(f(Data_Unit::unit()));
    });
};
auto invariantEither() -> boxed {
    return Data_Functor_Invariant::Invariant()(Data_Functor_Invariant::imapF()(Data_Either::functorEither()));
};
auto fromRight() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Right")) {
                return v["value0"];
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 261, column 1 - line 261, column 52): ");
        };
    };
    return _;
};
auto fromLeft() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Left")) {
                return v["value0"];
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 256, column 1 - line 256, column 51): ");
        };
    };
    return _;
};
auto foldableEither() -> boxed {
    return Data_Foldable::Foldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Left")) {
                    return Data_Monoid::mempty()(dictMonoid);
                };
                if (unbox<dict_t>(v).contains("Right")) {
                    return f(v["value0"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 187, column 1 - line 187, column 47): ");
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Left")) {
                    return z;
                };
                if (unbox<dict_t>(v1).contains("Right")) {
                    return v(z)(v1["value0"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 187, column 1 - line 187, column 47): ");
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Left")) {
                    return z;
                };
                if (unbox<dict_t>(v1).contains("Right")) {
                    return v(v1["value0"])(z);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 187, column 1 - line 187, column 47): ");
            };
        };
    });
};
auto foldableWithIndexEither() -> boxed {
    return Data_FoldableWithIndex::FoldableWithIndex()([=](const boxed&) -> boxed {
        return Data_Either::foldableEither();
    })([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Left")) {
                    return Data_Monoid::mempty()(dictMonoid);
                };
                if (unbox<dict_t>(v).contains("Right")) {
                    return f(Data_Unit::unit())(v["value0"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 195, column 1 - line 195, column 70): ");
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Left")) {
                    return z;
                };
                if (unbox<dict_t>(v1).contains("Right")) {
                    return v(Data_Unit::unit())(z)(v1["value0"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 195, column 1 - line 195, column 70): ");
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& z) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Left")) {
                    return z;
                };
                if (unbox<dict_t>(v1).contains("Right")) {
                    return v(Data_Unit::unit())(v1["value0"])(z);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 195, column 1 - line 195, column 70): ");
            };
        };
    });
};
auto traversableEither() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Either::foldableEither();
    })([=](const boxed&) -> boxed {
        return Data_Either::functorEither();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Left")) {
                return Control_Applicative::pure()(dictApplicative)(Data_Either::Left()(v["value0"]));
            };
            if (unbox<dict_t>(v).contains("Right")) {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Right())(v["value0"]);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 211, column 1 - line 211, column 53): ");
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Left")) {
                    return Control_Applicative::pure()(dictApplicative)(Data_Either::Left()(v1["value0"]));
                };
                if (unbox<dict_t>(v1).contains("Right")) {
                    return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Right())(v(v1["value0"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 211, column 1 - line 211, column 53): ");
            };
        };
    });
};
auto traversableWithIndexEither() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_Either::foldableWithIndexEither();
    })([=](const boxed&) -> boxed {
        return Data_Either::functorWithIndexEither();
    })([=](const boxed&) -> boxed {
        return Data_Either::traversableEither();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Left")) {
                    return Control_Applicative::pure()(dictApplicative)(Data_Either::Left()(v1["value0"]));
                };
                if (unbox<dict_t>(v1).contains("Right")) {
                    return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Right())(v(Data_Unit::unit())(v1["value0"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 217, column 1 - line 217, column 76): ");
            };
        };
    });
};
auto extendEither() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_Either::functorEither();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v1).contains("Left")) {
                return Data_Either::Left()(v1["value0"]);
            };
            return Data_Either::Right()(v(v1));
        };
    });
};
auto eqEither() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& dictEq1) -> boxed {
            return Data_Eq::Eq()([=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    if (unbox<dict_t>(x).contains("Left")) {
                        if (unbox<dict_t>(y).contains("Left")) {
                            return Data_Eq::eq()(dictEq)(x["value0"])(y["value0"]);
                        };
                    };
                    if (unbox<dict_t>(x).contains("Right")) {
                        if (unbox<dict_t>(y).contains("Right")) {
                            return Data_Eq::eq()(dictEq1)(x["value0"])(y["value0"]);
                        };
                    };
                    return false;
                };
            });
        };
    };
    return _;
};
auto ordEither() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictOrd1) -> boxed {
            return Data_Ord::Ord()([=](const boxed&) -> boxed {
                return Data_Either::eqEither()(dictOrd["Eq0"](undefined))(dictOrd1["Eq0"](undefined));
            })([=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    if (unbox<dict_t>(x).contains("Left")) {
                        if (unbox<dict_t>(y).contains("Left")) {
                            return Data_Ord::compare()(dictOrd)(x["value0"])(y["value0"]);
                        };
                    };
                    if (unbox<dict_t>(x).contains("Left")) {
                        return Data_Ordering::LT();
                    };
                    if (unbox<dict_t>(y).contains("Left")) {
                        return Data_Ordering::GT();
                    };
                    if (unbox<dict_t>(x).contains("Right")) {
                        if (unbox<dict_t>(y).contains("Right")) {
                            return Data_Ord::compare()(dictOrd1)(x["value0"])(y["value0"]);
                        };
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 179, column 8 - line 179, column 64): ");
                };
            });
        };
    };
    return _;
};
auto eq1Either() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::Eq1()([=](const boxed& dictEq1) -> boxed {
            return Data_Eq::eq()(Data_Either::eqEither()(dictEq)(dictEq1));
        });
    };
    return _;
};
auto ord1Either() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord1()([=](const boxed&) -> boxed {
            return Data_Either::eq1Either()(dictOrd["Eq0"](undefined));
        })([=](const boxed& dictOrd1) -> boxed {
            return Data_Ord::compare()(Data_Either::ordEither()(dictOrd)(dictOrd1));
        });
    };
    return _;
};
auto either() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<dict_t>(v2).contains("Left")) {
                    return v(v2["value0"]);
                };
                if (unbox<dict_t>(v2).contains("Right")) {
                    return v1(v2["value0"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 238, column 1 - line 238, column 64): ");
            };
        };
    };
    return _;
};
auto hush() -> boxed {
    return Data_Either::either()(Data_Function::_const_()(Data_Maybe::Nothing()))(Data_Maybe::Just());
};
auto isLeft() -> boxed {
    return Data_Either::either()(Data_Function::_const_()(true))(Data_Function::_const_()(false));
};
auto isRight() -> boxed {
    return Data_Either::either()(Data_Function::_const_()(false))(Data_Function::_const_()(true));
};
auto choose() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlt) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Control_Alt::alt()(dictAlt)(Data_Functor::map()(dictAlt["Functor0"](undefined))(Data_Either::Left())(a))(Data_Functor::map()(dictAlt["Functor0"](undefined))(Data_Either::Right())(b));
            };
        };
    };
    return _;
};
auto boundedEither() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return [=](const boxed& dictBounded1) -> boxed {
            return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
                return Data_Either::ordEither()(dictBounded["Ord0"](undefined))(dictBounded1["Ord0"](undefined));
            })(Data_Either::Left()(Data_Bounded::bottom()(dictBounded)))(Data_Either::Right()(Data_Bounded::top()(dictBounded1)));
        };
    };
    return _;
};
auto bifunctorEither() -> boxed {
    return Data_Bifunctor::Bifunctor()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<dict_t>(v2).contains("Left")) {
                    return Data_Either::Left()(v(v2["value0"]));
                };
                if (unbox<dict_t>(v2).contains("Right")) {
                    return Data_Either::Right()(v1(v2["value0"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 46, column 1 - line 46, column 45): ");
            };
        };
    });
};
auto bifoldableEither() -> boxed {
    return Data_Bifoldable::Bifoldable()([=](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return [=](const boxed& v2) -> boxed {
                    if (unbox<dict_t>(v2).contains("Left")) {
                        return v(v2["value0"]);
                    };
                    if (unbox<dict_t>(v2).contains("Right")) {
                        return v1(v2["value0"]);
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 203, column 1 - line 203, column 47): ");
                };
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& z) -> boxed {
                return [=](const boxed& v2) -> boxed {
                    if (unbox<dict_t>(v2).contains("Left")) {
                        return v(z)(v2["value0"]);
                    };
                    if (unbox<dict_t>(v2).contains("Right")) {
                        return v1(z)(v2["value0"]);
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 203, column 1 - line 203, column 47): ");
                };
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& z) -> boxed {
                return [=](const boxed& v2) -> boxed {
                    if (unbox<dict_t>(v2).contains("Left")) {
                        return v(v2["value0"])(z);
                    };
                    if (unbox<dict_t>(v2).contains("Right")) {
                        return v1(v2["value0"])(z);
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 203, column 1 - line 203, column 47): ");
                };
            };
        };
    });
};
auto bitraversableEither() -> boxed {
    return Data_Bitraversable::Bitraversable()([=](const boxed&) -> boxed {
        return Data_Either::bifoldableEither();
    })([=](const boxed&) -> boxed {
        return Data_Either::bifunctorEither();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Left")) {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Left())(v["value0"]);
            };
            if (unbox<dict_t>(v).contains("Right")) {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Right())(v["value0"]);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 221, column 1 - line 221, column 53): ");
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return [=](const boxed& v2) -> boxed {
                    if (unbox<dict_t>(v2).contains("Left")) {
                        return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Left())(v(v2["value0"]));
                    };
                    if (unbox<dict_t>(v2).contains("Right")) {
                        return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Right())(v1(v2["value0"]));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 221, column 1 - line 221, column 53): ");
                };
            };
        };
    });
};
auto applyEither() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Either::functorEither();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Left")) {
                return Data_Either::Left()(v["value0"]);
            };
            if (unbox<dict_t>(v).contains("Right")) {
                return Data_Functor::map()(Data_Either::functorEither())(v["value0"])(v1);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either (line 82, column 1 - line 82, column 41): ");
        };
    });
};
auto bindEither() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Either::applyEither();
    })(Data_Either::either()([=](const boxed& e) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Either::Left()(e);
        };
    })([=](const boxed& a) -> boxed {
        return [=](const boxed& f) -> boxed {
            return f(a);
        };
    }));
};
auto semigroupEither() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                return Control_Apply::apply()(Data_Either::applyEither())(Data_Functor::map()(Data_Either::functorEither())(Data_Semigroup::append()(dictSemigroup))(x))(y);
            };
        });
    };
    return _;
};
auto applicativeEither() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Either::applyEither();
    })(Data_Either::Right());
};
auto monadEither() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Either::applicativeEither();
    })([=](const boxed&) -> boxed {
        return Data_Either::bindEither();
    });
};
auto altEither() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_Either::functorEither();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Left")) {
                return v1;
            };
            return v;
        };
    });
};


} // end namespace Data_Either


