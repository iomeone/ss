#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Lazy/Data_Lazy.h"
#include "Data_List_Lazy/Data_List_Lazy.h"
#include "Data_List_Lazy_Types/Data_List_Lazy_Types.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_NonEmpty/Data_NonEmpty.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Prelude/Prelude.h"

#include "Data_List_Lazy_NonEmpty/Data_List_Lazy_NonEmpty.h"


namespace Data_List_Lazy_NonEmpty {

auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        boxed v1 = Data_Lazy::force()(v);
        return dict_t{
            { "head", v1["value0"] },
            { "tail", v1["value1"] }
        };
    };
    return _;
};
auto toList() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        boxed v1 = Data_Lazy::force()(v);
        return Data_List_Lazy_Types::cons()(v1["value0"])(v1["value1"]);
    };
    return _;
};
auto toUnfoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Unfoldable::unfoldr()(dictUnfoldable)([=](const boxed& xs) -> boxed {
            return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& rec) -> boxed {
                return Data_Tuple::Tuple()(rec["head"])(rec["tail"]);
            })(Data_List_Lazy::uncons()(xs));
        }))(Data_List_Lazy_NonEmpty::toList());
    };
    return _;
};
auto tail() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        boxed v1 = Data_Lazy::force()(v);
        return v1["value1"];
    };
    return _;
};
auto singleton() -> boxed {
    return Control_Applicative::pure()(Data_List_Lazy_Types::applicativeNonEmptyList());
};
auto repeat() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return Data_List_Lazy_Types::NonEmptyList()(Data_Lazy::defer()([=](const boxed& v) -> boxed {
            return Data_NonEmpty::NonEmpty()(x)(Data_List_Lazy::repeat()(x));
        }));
    };
    return _;
};
auto length() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        boxed v1 = Data_Lazy::force()(v);
        return 1 + unbox<int>(Data_List_Lazy::length()(v1["value1"]));
    };
    return _;
};
auto last() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        boxed v1 = Data_Lazy::force()(v);
        return Data_Maybe::fromMaybe()(v1["value0"])(Data_List_Lazy::last()(v1["value1"]));
    };
    return _;
};
auto iterate() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_List_Lazy_Types::NonEmptyList()(Data_Lazy::defer()([=](const boxed& v) -> boxed {
                return Data_NonEmpty::NonEmpty()(x)(Data_List_Lazy::iterate()(f)(f(x)));
            }));
        };
    };
    return _;
};
auto init() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        boxed v1 = Data_Lazy::force()(v);
        return Data_Maybe::maybe()(Data_List_Lazy_Types::nil())([=](const boxed& v2) -> boxed {
            return Data_List_Lazy_Types::cons()(v1["value0"])(v2);
        })(Data_List_Lazy::init()(v1["value1"]));
    };
    return _;
};
auto head() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        boxed v1 = Data_Lazy::force()(v);
        return v1["value0"];
    };
    return _;
};
auto fromList() -> const boxed& {
    static const boxed _ = [](const boxed& l) -> boxed {
        boxed v = Data_List_Lazy_Types::step()(l);
        if (unbox<dict_t>(v).contains("Nil")) {
            return Data_Maybe::Nothing();
        };
        if (unbox<dict_t>(v).contains("Cons")) {
            return Data_Maybe::Just()(Data_Lazy::defer()([=](const boxed& v1) -> boxed {
                return Data_NonEmpty::NonEmpty()(v["value0"])(v["value1"]);
            }));
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Lazy.NonEmpty (line 41, column 3 - line 43, column 61): ");
    };
    return _;
};
auto fromFoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Lazy_NonEmpty::fromList())(Data_List_Lazy::fromFoldable()(dictFoldable));
    };
    return _;
};
auto concatMap() -> boxed {
    return Data_Function::flip()(Control_Bind::bind()(Data_List_Lazy_Types::bindNonEmptyList()));
};
auto appendFoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& nel) -> boxed {
            return [=](const boxed& ys) -> boxed {
                return Data_Lazy::defer()([=](const boxed& v) -> boxed {
                    return Data_NonEmpty::NonEmpty()(Data_List_Lazy_NonEmpty::head()(nel))(Data_Semigroup::append()(Data_List_Lazy_Types::semigroupList())(Data_List_Lazy_NonEmpty::tail()(nel))(Data_List_Lazy::fromFoldable()(dictFoldable)(ys)));
                });
            };
        };
    };
    return _;
};


} // end namespace Data_List_Lazy_NonEmpty


