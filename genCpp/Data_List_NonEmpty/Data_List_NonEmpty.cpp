#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_List/Data_List.h"
#include "Data_List_Types/Data_List_Types.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_NonEmpty/Data_NonEmpty.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_Semigroup_Traversable/Data_Semigroup_Traversable.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"

#include "Data_List_NonEmpty/Data_List_NonEmpty.h"


namespace Data_List_NonEmpty {

auto zipWith() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_NonEmpty::NonEmpty()(f(v["value0"])(v1["value0"]))(Data_List::zipWith()(f)(v["value1"])(v1["value1"]));
            };
        };
    };
    return _;
};
auto zipWithA() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return [=](const boxed& ys) -> boxed {
                    return Data_Semigroup_Traversable::sequence1()(Data_List_Types::traversable1NonEmptyList())(dictApplicative["Apply0"](undefined))(Data_List_NonEmpty::zipWith()(f)(xs)(ys));
                };
            };
        };
    };
    return _;
};
auto zip() -> boxed {
    return Data_List_NonEmpty::zipWith()(Data_Tuple::Tuple());
};
auto wrappedOperation2() -> const boxed& {
    static const boxed _ = [](const boxed& name) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    boxed v2 = f(Data_List_Types::Cons()(v["value0"])(v["value1"]))(Data_List_Types::Cons()(v1["value0"])(v1["value1"]));
                    if (unbox<dict_t>(v2).contains("Cons")) {
                        return Data_NonEmpty::NonEmpty()(v2["value0"])(v2["value1"]);
                    };
                    if (unbox<dict_t>(v2).contains("Nil")) {
                        return Partial_Unsafe::unsafeCrashWith()(Data_Semigroup::append()(Data_Semigroup::semigroupString())("Impossible: empty list in NonEmptyList ")(name));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.NonEmpty (line 104, column 3 - line 106, column 81): ");
                };
            };
        };
    };
    return _;
};
auto wrappedOperation() -> const boxed& {
    static const boxed _ = [](const boxed& name) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                boxed v1 = f(Data_List_Types::Cons()(v["value0"])(v["value1"]));
                if (unbox<dict_t>(v1).contains("Cons")) {
                    return Data_NonEmpty::NonEmpty()(v1["value0"])(v1["value1"]);
                };
                if (unbox<dict_t>(v1).contains("Nil")) {
                    return Partial_Unsafe::unsafeCrashWith()(Data_Semigroup::append()(Data_Semigroup::semigroupString())("Impossible: empty list in NonEmptyList ")(name));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.NonEmpty (line 91, column 3 - line 93, column 81): ");
            };
        };
    };
    return _;
};
auto updateAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& v) -> boxed {
                if (unbox<bool>(unbox<int>(i) == 0)) {
                    return Data_Maybe::Just()(Data_NonEmpty::NonEmpty()(a)(v["value1"]));
                };
                return Data_Functor::map()(Data_Maybe::functorMaybe())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Types::NonEmptyList())([=](const boxed& v1) -> boxed {
                    return Data_NonEmpty::NonEmpty()(v["value0"])(v1);
                }))(Data_List::updateAt()(unbox<int>(i) - 1)(a)(v["value1"]));
            };
        };
    };
    return _;
};
auto unzip() -> const boxed& {
    static const boxed _ = [](const boxed& ts) -> boxed {
        return Data_Tuple::Tuple()(Data_Functor::map()(Data_List_Types::functorNonEmptyList())(Data_Tuple::fst())(ts))(Data_Functor::map()(Data_List_Types::functorNonEmptyList())(Data_Tuple::snd())(ts));
    };
    return _;
};
auto unsnoc() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        boxed v1 = Data_List::unsnoc()(v["value1"]);
        if (unbox<dict_t>(v1).contains("Nothing")) {
            return dict_t{
                { "init", Data_List_Types::Nil() },
                { "last", v["value0"] }
            };
        };
        if (unbox<dict_t>(v1).contains("Just")) {
            return dict_t{
                { "init", Data_List_Types::Cons()(v["value0"])(v1["value0"]["init"]) },
                { "last", v1["value0"]["last"] }
            };
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.NonEmpty (line 159, column 35 - line 161, column 50): ");
    };
    return _;
};
auto unionBy() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::wrappedOperation2()("unionBy"))(Data_List::unionBy());
};
auto _union_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_NonEmpty::wrappedOperation2()("union")(Data_List::_union_()(dictEq));
    };
    return _;
};
auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return dict_t{
            { "head", v["value0"] },
            { "tail", v["value1"] }
        };
    };
    return _;
};
auto toList() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_List_Types::Cons()(v["value0"])(v["value1"]);
    };
    return _;
};
auto toUnfoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Unfoldable::unfoldr()(dictUnfoldable)([=](const boxed& xs) -> boxed {
            return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& rec) -> boxed {
                return Data_Tuple::Tuple()(rec["head"])(rec["tail"]);
            })(Data_List::uncons()(xs));
        }))(Data_List_NonEmpty::toList());
    };
    return _;
};
auto tail() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"];
    };
    return _;
};
auto sortBy() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::wrappedOperation()("sortBy"))(Data_List::sortBy());
};
auto sort() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_List_NonEmpty::sortBy()(Data_Ord::compare()(dictOrd))(xs);
        };
    };
    return _;
};
auto snoc() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& y) -> boxed {
            return Data_NonEmpty::NonEmpty()(v["value0"])(Data_List::snoc()(v["value1"])(y));
        };
    };
    return _;
};
auto singleton() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Types::NonEmptyList())(Data_NonEmpty::singleton()(Data_List_Types::plusList()));
};
auto snoc_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& y) -> boxed {
            if (unbox<dict_t>(v).contains("Cons")) {
                return Data_NonEmpty::NonEmpty()(v["value0"])(Data_List::snoc()(v["value1"])(y));
            };
            if (unbox<dict_t>(v).contains("Nil")) {
                return Data_List_NonEmpty::singleton()(y);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.NonEmpty (line 139, column 1 - line 139, column 51): ");
        };
    };
    return _;
};
auto reverse() -> boxed {
    return Data_List_NonEmpty::wrappedOperation()("reverse")(Data_List::reverse());
};
auto nubBy() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::wrappedOperation()("nubBy"))(Data_List::nubBy());
};
auto nub() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_NonEmpty::wrappedOperation()("nub")(Data_List::nub()(dictEq));
    };
    return _;
};
auto modifyAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                if (unbox<bool>(unbox<int>(i) == 0)) {
                    return Data_Maybe::Just()(Data_NonEmpty::NonEmpty()(f(v["value0"]))(v["value1"]));
                };
                return Data_Functor::map()(Data_Maybe::functorMaybe())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Types::NonEmptyList())([=](const boxed& v1) -> boxed {
                    return Data_NonEmpty::NonEmpty()(v["value0"])(v1);
                }))(Data_List::modifyAt()(unbox<int>(i) - 1)(f)(v["value1"]));
            };
        };
    };
    return _;
};
auto mapWithIndex() -> boxed {
    return Data_FunctorWithIndex::mapWithIndex()(Data_List_Types::functorWithIndexNonEmptyList());
};
auto lift() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(Data_List_Types::Cons()(v["value0"])(v["value1"]));
        };
    };
    return _;
};
auto mapMaybe() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::lift())(Data_List::mapMaybe());
};
auto partition() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::lift())(Data_List::partition());
};
auto span() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::lift())(Data_List::span());
};
auto take() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::lift())(Data_List::take());
};
auto takeWhile() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::lift())(Data_List::takeWhile());
};
auto length() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return 1 + unbox<int>(Data_List::length()(v["value1"]));
    };
    return _;
};
auto last() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Maybe::fromMaybe()(v["value0"])(Data_List::last()(v["value1"]));
    };
    return _;
};
auto intersectBy() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::wrappedOperation2()("intersectBy"))(Data_List::intersectBy());
};
auto intersect() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_NonEmpty::wrappedOperation2()("intersect")(Data_List::intersect()(dictEq));
    };
    return _;
};
auto insertAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& v) -> boxed {
                if (unbox<bool>(unbox<int>(i) == 0)) {
                    return Data_Maybe::Just()(Data_NonEmpty::NonEmpty()(a)(Data_List_Types::Cons()(v["value0"])(v["value1"])));
                };
                return Data_Functor::map()(Data_Maybe::functorMaybe())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_Types::NonEmptyList())([=](const boxed& v1) -> boxed {
                    return Data_NonEmpty::NonEmpty()(v["value0"])(v1);
                }))(Data_List::insertAt()(unbox<int>(i) - 1)(a)(v["value1"]));
            };
        };
    };
    return _;
};
auto init() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Maybe::maybe()(Data_List_Types::Nil())([=](const boxed& v1) -> boxed {
            return Data_List_Types::Cons()(v["value0"])(v1);
        })(Data_List::init()(v["value1"]));
    };
    return _;
};
auto index() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& i) -> boxed {
            if (unbox<bool>(unbox<int>(i) == 0)) {
                return Data_Maybe::Just()(v["value0"]);
            };
            return Data_List::index()(v["value1"])(unbox<int>(i) - 1);
        };
    };
    return _;
};
auto head() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value0"];
    };
    return _;
};
auto groupBy() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::wrappedOperation()("groupBy"))(Data_List::groupBy());
};
auto group_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_List_NonEmpty::wrappedOperation()("group'")(Data_List::group_Prime_()(dictOrd));
    };
    return _;
};
auto group() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_NonEmpty::wrappedOperation()("group")(Data_List::group()(dictEq));
    };
    return _;
};
auto fromList() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Nil")) {
            return Data_Maybe::Nothing();
        };
        if (unbox<dict_t>(v).contains("Cons")) {
            return Data_Maybe::Just()(Data_NonEmpty::NonEmpty()(v["value0"])(v["value1"]));
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.NonEmpty (line 120, column 1 - line 120, column 57): ");
    };
    return _;
};
auto fromFoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::fromList())(Data_List::fromFoldable()(dictFoldable));
    };
    return _;
};
auto foldM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(f(a)(v["value0"]))([=](const boxed& a_Prime_) -> boxed {
                        return Data_List::foldM()(dictMonad)(f)(a_Prime_)(v["value1"]);
                    });
                };
            };
        };
    };
    return _;
};
auto findLastIndex() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            boxed v1 = Data_List::findLastIndex()(f)(v["value1"]);
            if (unbox<dict_t>(v1).contains("Just")) {
                return Data_Maybe::Just()(unbox<int>(v1["value0"]) + 1);
            };
            if (unbox<dict_t>(v1).contains("Nothing")) {
                if (unbox<bool>(f(v["value0"]))) {
                    return Data_Maybe::Just()(0);
                };
                return Data_Maybe::Nothing();
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.NonEmpty (line 186, column 3 - line 190, column 29): ");
        };
    };
    return _;
};
auto findIndex() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<bool>(f(v["value0"]))) {
                return Data_Maybe::Just()(0);
            };
            return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v1) -> boxed {
                return unbox<int>(v1) + 1;
            })(Data_List::findIndex()(f)(v["value1"]));
        };
    };
    return _;
};
auto filterM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::lift())(Data_List::filterM()(dictMonad));
    };
    return _;
};
auto filter() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::lift())(Data_List::filter());
};
auto elemLastIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_List_NonEmpty::findLastIndex()([=](const boxed& v) -> boxed {
                return Data_Eq::eq()(dictEq)(v)(x);
            });
        };
    };
    return _;
};
auto elemIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_List_NonEmpty::findIndex()([=](const boxed& v) -> boxed {
                return Data_Eq::eq()(dictEq)(v)(x);
            });
        };
    };
    return _;
};
auto dropWhile() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::lift())(Data_List::dropWhile());
};
auto drop() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_NonEmpty::lift())(Data_List::drop());
};
auto cons_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_NonEmpty::NonEmpty()(x)(xs);
        };
    };
    return _;
};
auto cons() -> const boxed& {
    static const boxed _ = [](const boxed& y) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_NonEmpty::NonEmpty()(y)(Data_List_Types::Cons()(v["value0"])(v["value1"]));
        };
    };
    return _;
};
auto concatMap() -> boxed {
    return Data_Function::flip()(Control_Bind::bind()(Data_List_Types::bindNonEmptyList()));
};
auto concat() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Control_Bind::bind()(Data_List_Types::bindNonEmptyList())(v)(Control_Category::identity()(Control_Category::categoryFn()));
    };
    return _;
};
auto catMaybes() -> boxed {
    return Data_List_NonEmpty::lift()(Data_List::catMaybes());
};
auto appendFoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& ys) -> boxed {
                return Data_NonEmpty::NonEmpty()(v["value0"])(Data_Semigroup::append()(Data_List_Types::semigroupList())(v["value1"])(Data_List::fromFoldable()(dictFoldable)(ys)));
            };
        };
    };
    return _;
};


} // end namespace Data_List_NonEmpty


