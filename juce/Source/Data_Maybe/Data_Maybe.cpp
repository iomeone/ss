#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Control_Plus/Control_Plus.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Functor_Invariant/Data_Functor_Invariant.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_Maybe/Data_Maybe.h"


namespace Data_Maybe {

auto Nothing() -> const boxed& {
    static const boxed _ = dict_t{
        { "Nothing", true }
    };
    return _;
};
auto Just() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "Just", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto showMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Just")) {
                return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Just ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v["value0"]))(")"));
            };
            if (unbox<dict_t>(v).contains("Nothing")) {
                return "Nothing";
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Maybe (line 205, column 1 - line 205, column 47): ");
        });
    };
    return _;
};
auto semigroupMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v).contains("Nothing")) {
                    return v1;
                };
                if (unbox<dict_t>(v1).contains("Nothing")) {
                    return v;
                };
                if (unbox<dict_t>(v).contains("Just")) {
                    if (unbox<dict_t>(v1).contains("Just")) {
                        return Data_Maybe::Just()(Data_Semigroup::append()(dictSemigroup)(v["value0"])(v1["value0"]));
                    };
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Maybe (line 174, column 1 - line 174, column 62): ");
            };
        });
    };
    return _;
};
auto optional() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlternative) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Control_Alt::alt()(dictAlternative["Plus1"](undefined)["Alt0"](undefined))(Data_Functor::map()(dictAlternative["Plus1"](undefined)["Alt0"](undefined)["Functor0"](undefined))(Data_Maybe::Just())(a))(Control_Applicative::pure()(dictAlternative["Applicative0"](undefined))(Data_Maybe::Nothing()));
        };
    };
    return _;
};
auto monoidMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Data_Maybe::semigroupMaybe()(dictSemigroup);
        })(Data_Maybe::Nothing());
    };
    return _;
};
auto maybe_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<dict_t>(v2).contains("Nothing")) {
                    return v(Data_Unit::unit());
                };
                if (unbox<dict_t>(v2).contains("Just")) {
                    return v1(v2["value0"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Maybe (line 230, column 1 - line 230, column 62): ");
            };
        };
    };
    return _;
};
auto maybe() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                if (unbox<dict_t>(v2).contains("Nothing")) {
                    return v;
                };
                if (unbox<dict_t>(v2).contains("Just")) {
                    return v1(v2["value0"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Maybe (line 217, column 1 - line 217, column 51): ");
            };
        };
    };
    return _;
};
auto isNothing() -> boxed {
    return Data_Maybe::maybe()(true)(Data_Function::_const_()(false));
};
auto isJust() -> boxed {
    return Data_Maybe::maybe()(false)(Data_Function::_const_()(true));
};
auto functorMaybe() -> boxed {
    return Data_Functor::Functor()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v1).contains("Just")) {
                return Data_Maybe::Just()(v(v1["value0"]));
            };
            return Data_Maybe::Nothing();
        };
    });
};
auto invariantMaybe() -> boxed {
    return Data_Functor_Invariant::Invariant()(Data_Functor_Invariant::imapF()(Data_Maybe::functorMaybe()));
};
auto fromMaybe_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return Data_Maybe::maybe_Prime_()(a)(Control_Category::identity()(Control_Category::categoryFn()));
    };
    return _;
};
auto fromMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return Data_Maybe::maybe()(a)(Control_Category::identity()(Control_Category::categoryFn()));
    };
    return _;
};
auto fromJust() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Just")) {
                return v["value0"];
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Maybe (line 268, column 1 - line 268, column 46): ");
        };
    };
    return _;
};
auto extendMaybe() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_Maybe::functorMaybe();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v1).contains("Nothing")) {
                return Data_Maybe::Nothing();
            };
            return Data_Maybe::Just()(v(v1));
        };
    });
};
auto eqMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::Eq()([=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(x).contains("Nothing")) {
                    if (unbox<dict_t>(y).contains("Nothing")) {
                        return true;
                    };
                };
                if (unbox<dict_t>(x).contains("Just")) {
                    if (unbox<dict_t>(y).contains("Just")) {
                        return Data_Eq::eq()(dictEq)(x["value0"])(y["value0"]);
                    };
                };
                return false;
            };
        });
    };
    return _;
};
auto ordMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord()([=](const boxed&) -> boxed {
            return Data_Maybe::eqMaybe()(dictOrd["Eq0"](undefined));
        })([=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(x).contains("Nothing")) {
                    if (unbox<dict_t>(y).contains("Nothing")) {
                        return Data_Ordering::EQ();
                    };
                };
                if (unbox<dict_t>(x).contains("Nothing")) {
                    return Data_Ordering::LT();
                };
                if (unbox<dict_t>(y).contains("Nothing")) {
                    return Data_Ordering::GT();
                };
                if (unbox<dict_t>(x).contains("Just")) {
                    if (unbox<dict_t>(y).contains("Just")) {
                        return Data_Ord::compare()(dictOrd)(x["value0"])(y["value0"]);
                    };
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Maybe (line 194, column 8 - line 194, column 51): ");
            };
        });
    };
    return _;
};
auto eq1Maybe() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Maybe::eqMaybe()(dictEq));
    });
};
auto ord1Maybe() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Maybe::eq1Maybe();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Maybe::ordMaybe()(dictOrd));
    });
};
auto boundedMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
            return Data_Maybe::ordMaybe()(dictBounded["Ord0"](undefined));
        })(Data_Maybe::Nothing())(Data_Maybe::Just()(Data_Bounded::top()(dictBounded)));
    };
    return _;
};
auto applyMaybe() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Maybe::functorMaybe();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Just")) {
                return Data_Functor::map()(Data_Maybe::functorMaybe())(v["value0"])(v1);
            };
            if (unbox<dict_t>(v).contains("Nothing")) {
                return Data_Maybe::Nothing();
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Maybe (line 67, column 1 - line 67, column 35): ");
        };
    });
};
auto bindMaybe() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Maybe::applyMaybe();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Just")) {
                return v1(v["value0"]);
            };
            if (unbox<dict_t>(v).contains("Nothing")) {
                return Data_Maybe::Nothing();
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Maybe (line 125, column 1 - line 125, column 33): ");
        };
    });
};
auto applicativeMaybe() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Maybe::applyMaybe();
    })(Data_Maybe::Just());
};
auto monadMaybe() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Maybe::applicativeMaybe();
    })([=](const boxed&) -> boxed {
        return Data_Maybe::bindMaybe();
    });
};
auto altMaybe() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_Maybe::functorMaybe();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Nothing")) {
                return v1;
            };
            return v;
        };
    });
};
auto plusMaybe() -> boxed {
    return Control_Plus::Plus()([=](const boxed&) -> boxed {
        return Data_Maybe::altMaybe();
    })(Data_Maybe::Nothing());
};
auto alternativeMaybe() -> boxed {
    return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
        return Data_Maybe::applicativeMaybe();
    })([=](const boxed&) -> boxed {
        return Data_Maybe::plusMaybe();
    });
};
auto monadZeroMaybe() -> boxed {
    return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
        return Data_Maybe::alternativeMaybe();
    })([=](const boxed&) -> boxed {
        return Data_Maybe::monadMaybe();
    });
};


} // end namespace Data_Maybe


