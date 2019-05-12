#include "Control_Alternative/Control_Alternative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Array/Data_Array.h"
#include "Data_Array_NonEmpty_Internal/Data_Array_NonEmpty_Internal.h"
#include "Data_Bifunctor/Data_Bifunctor.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_NonEmpty/Data_NonEmpty.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Data_Unfoldable1/Data_Unfoldable1.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"
#include "Unsafe_Coerce/Unsafe_Coerce.h"

#include "Data_Array_NonEmpty/Data_Array_NonEmpty.h"


namespace Data_Array_NonEmpty {

auto unsafeFromArrayF() -> boxed {
    return Unsafe_Coerce::unsafeCoerce();
};
auto unsafeFromArray() -> boxed {
    return Unsafe_Coerce::unsafeCoerce();
};
auto toArray() -> boxed {
    return Unsafe_Coerce::unsafeCoerce();
};
auto unionBy_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unsafeFromArray())(Data_Array::unionBy()(eq)(Data_Array_NonEmpty::toArray()(xs)));
        };
    };
    return _;
};
auto union_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Array_NonEmpty::unionBy_Prime_()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto unionBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unionBy_Prime_()(eq)(xs))(Data_Array_NonEmpty::toArray());
        };
    };
    return _;
};
auto _union_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Array_NonEmpty::unionBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto unzip() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Bifunctor::bimap()(Data_Tuple::bifunctorTuple())(Data_Array_NonEmpty::unsafeFromArray())(Data_Array_NonEmpty::unsafeFromArray()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array::unzip())(Data_Array_NonEmpty::toArray()));
};
auto updateAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unsafeFromArrayF())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array::updateAt()(i)(x))(Data_Array_NonEmpty::toArray()));
        };
    };
    return _;
};
auto zip() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return [=](const boxed& ys) -> boxed {
            return Data_Array_NonEmpty::unsafeFromArray()(Data_Array::zip()(Data_Array_NonEmpty::toArray()(xs))(Data_Array_NonEmpty::toArray()(ys)));
        };
    };
    return _;
};
auto zipWith() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return [=](const boxed& ys) -> boxed {
                return Data_Array_NonEmpty::unsafeFromArray()(Data_Array::zipWith()(f)(Data_Array_NonEmpty::toArray()(xs))(Data_Array_NonEmpty::toArray()(ys)));
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
                    return Data_Array_NonEmpty::unsafeFromArrayF()(Data_Array::zipWithA()(dictApplicative)(f)(Data_Array_NonEmpty::toArray()(xs))(Data_Array_NonEmpty::toArray()(ys)));
                };
            };
        };
    };
    return _;
};
auto some() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlternative) -> boxed {
        return [=](const boxed& dictLazy) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unsafeFromArrayF())(Data_Array::some()(dictAlternative)(dictLazy));
        };
    };
    return _;
};
auto snoc_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array_NonEmpty::unsafeFromArray()(Data_Array::snoc()(xs)(x));
        };
    };
    return _;
};
auto snoc() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array_NonEmpty::unsafeFromArray()(Data_Array::snoc()(Data_Array_NonEmpty::toArray()(xs))(x));
        };
    };
    return _;
};
auto singleton() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unsafeFromArray())(Data_Array::singleton());
};
auto replicate() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array_NonEmpty::unsafeFromArray()(Data_Array::replicate()(Data_Ord::max()(Data_Ord::ordInt())(1)(i))(x));
        };
    };
    return _;
};
auto range() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            return Data_Array_NonEmpty::unsafeFromArray()(Data_Array::range()(x)(y));
        };
    };
    return _;
};
auto modifyAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unsafeFromArrayF())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array::modifyAt()(i)(f))(Data_Array_NonEmpty::toArray()));
        };
    };
    return _;
};
auto intersectBy_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::intersectBy()(eq)(Data_Array_NonEmpty::toArray()(xs));
        };
    };
    return _;
};
auto intersectBy() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::intersectBy_Prime_()(eq)(xs))(Data_Array_NonEmpty::toArray());
        };
    };
    return _;
};
auto intersect_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Array_NonEmpty::intersectBy_Prime_()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto intersect() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Array_NonEmpty::intersectBy()(Data_Eq::eq()(dictEq));
    };
    return _;
};
auto insertAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unsafeFromArrayF())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array::insertAt()(i)(x))(Data_Array_NonEmpty::toArray()));
        };
    };
    return _;
};
auto fromFoldable1() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unsafeFromArray())(Data_Array::fromFoldable()(dictFoldable1["Foldable0"](undefined)));
    };
    return _;
};
auto fromArray() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        if (unbox<bool>(Data_Ord::greaterThan()(Data_Ord::ordInt())(Data_Array::length()(xs))(0))) {
            return Data_Maybe::Just()(Data_Array_NonEmpty::unsafeFromArray()(xs));
        };
        return Data_Maybe::Nothing();
    };
    return _;
};
auto fromFoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::fromArray())(Data_Array::fromFoldable()(dictFoldable));
    };
    return _;
};
auto difference_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array::difference()(dictEq)(Data_Array_NonEmpty::toArray()(xs));
        };
    };
    return _;
};
auto cons_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array_NonEmpty::unsafeFromArray()(Data_Array::cons()(x)(xs));
        };
    };
    return _;
};
auto fromNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Array_NonEmpty::cons_Prime_()(v["value0"])(v["value1"]);
    };
    return _;
};
auto concatMap() -> boxed {
    return Data_Function::flip()(Control_Bind::bind()(Data_Array_NonEmpty_Internal::bindNonEmptyArray()));
};
auto concat() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unsafeFromArray())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array::concat())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::toArray())(Data_Functor::map()(Data_Array_NonEmpty_Internal::functorNonEmptyArray())(Data_Array_NonEmpty::toArray()))));
};
auto appendArray() -> const boxed& {
    static const boxed _ = [](const boxed& xs) -> boxed {
        return [=](const boxed& ys) -> boxed {
            return Data_Array_NonEmpty::unsafeFromArray()(Data_Semigroup::append()(Data_Semigroup::semigroupArray())(Data_Array_NonEmpty::toArray()(xs))(ys));
        };
    };
    return _;
};
auto alterAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array::alterAt()(i)(f))(Data_Array_NonEmpty::toArray());
        };
    };
    return _;
};
auto adaptMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Maybe::fromJust()(undefined))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Array_NonEmpty::toArray()));
    };
    return _;
};
auto head() -> boxed {
    return Data_Array_NonEmpty::adaptMaybe()(Data_Array::head());
};
auto init() -> boxed {
    return Data_Array_NonEmpty::adaptMaybe()(Data_Array::init());
};
auto last() -> boxed {
    return Data_Array_NonEmpty::adaptMaybe()(Data_Array::last());
};
auto tail() -> boxed {
    return Data_Array_NonEmpty::adaptMaybe()(Data_Array::tail());
};
auto uncons() -> boxed {
    return Data_Array_NonEmpty::adaptMaybe()(Data_Array::uncons());
};
auto toNonEmpty() -> boxed {
    return Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::uncons())([=](const boxed& v) -> boxed {
        return Data_NonEmpty::NonEmpty()(v["head"])(v["tail"]);
    });
};
auto unsnoc() -> boxed {
    return Data_Array_NonEmpty::adaptMaybe()(Data_Array::unsnoc());
};
auto adaptAny() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Array_NonEmpty::toArray());
    };
    return _;
};
auto catMaybes() -> boxed {
    return Data_Array_NonEmpty::adaptAny()(Data_Array::catMaybes());
};
auto _delete_() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array_NonEmpty::adaptAny()(Data_Array::_delete_()(dictEq)(x));
        };
    };
    return _;
};
auto deleteAt() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::deleteAt()(i));
    };
    return _;
};
auto deleteBy() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array_NonEmpty::adaptAny()(Data_Array::deleteBy()(f)(x));
        };
    };
    return _;
};
auto difference() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Data_Array_NonEmpty::adaptAny()(Data_Array_NonEmpty::difference_Prime_()(dictEq)(xs));
        };
    };
    return _;
};
auto drop() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::drop()(i));
    };
    return _;
};
auto dropEnd() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::dropEnd()(i));
    };
    return _;
};
auto dropWhile() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::dropWhile()(f));
    };
    return _;
};
auto elemIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array_NonEmpty::adaptAny()(Data_Array::elemIndex()(dictEq)(x));
        };
    };
    return _;
};
auto elemLastIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array_NonEmpty::adaptAny()(Data_Array::elemLastIndex()(dictEq)(x));
        };
    };
    return _;
};
auto filter() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::filter()(f));
    };
    return _;
};
auto filterA() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Array_NonEmpty::adaptAny()(Data_Array::filterA()(dictApplicative)(f));
        };
    };
    return _;
};
auto findIndex() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::findIndex()(x));
    };
    return _;
};
auto findLastIndex() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::findLastIndex()(x));
    };
    return _;
};
auto foldM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& acc) -> boxed {
                return Data_Array_NonEmpty::adaptAny()(Data_Array::foldM()(dictMonad)(f)(acc));
            };
        };
    };
    return _;
};
auto foldRecM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& acc) -> boxed {
                return Data_Array_NonEmpty::adaptAny()(Data_Array::foldRecM()(dictMonadRec)(f)(acc));
            };
        };
    };
    return _;
};
auto index() -> boxed {
    return Data_Array_NonEmpty::adaptAny()(Data_Array::index());
};
auto length() -> boxed {
    return Data_Array_NonEmpty::adaptAny()(Data_Array::length());
};
auto mapMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::mapMaybe()(f));
    };
    return _;
};
auto partition() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::partition()(f));
    };
    return _;
};
auto slice() -> const boxed& {
    static const boxed _ = [](const boxed& start) -> boxed {
        return [=](const boxed& end) -> boxed {
            return Data_Array_NonEmpty::adaptAny()(Data_Array::slice()(start)(end));
        };
    };
    return _;
};
auto span() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::span()(f));
    };
    return _;
};
auto take() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::take()(i));
    };
    return _;
};
auto takeEnd() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::takeEnd()(i));
    };
    return _;
};
auto takeWhile() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::takeWhile()(f));
    };
    return _;
};
auto toUnfoldable() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::toUnfoldable()(dictUnfoldable));
    };
    return _;
};
auto unsafeAdapt() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Array_NonEmpty::unsafeFromArray())(Data_Array_NonEmpty::adaptAny()(f));
    };
    return _;
};
auto cons() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::cons()(x));
    };
    return _;
};
auto insert() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::insert()(dictOrd)(x));
        };
    };
    return _;
};
auto insertBy() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::insertBy()(f)(x));
        };
    };
    return _;
};
auto modifyAtIndices() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& is) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::modifyAtIndices()(dictFoldable)(is)(f));
            };
        };
    };
    return _;
};
auto nub() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::nub()(dictOrd));
    };
    return _;
};
auto nubBy() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::nubBy()(f));
    };
    return _;
};
auto nubByEq() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::nubByEq()(f));
    };
    return _;
};
auto nubEq() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::nubEq()(dictEq));
    };
    return _;
};
auto reverse() -> boxed {
    return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::reverse());
};
auto sort() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::sort()(dictOrd));
    };
    return _;
};
auto sortBy() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::sortBy()(f));
    };
    return _;
};
auto sortWith() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::sortWith()(dictOrd)(f));
        };
    };
    return _;
};
auto updateAtIndices() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& pairs) -> boxed {
            return Data_Array_NonEmpty::unsafeAdapt()(Data_Array::updateAtIndices()(dictFoldable)(pairs));
        };
    };
    return _;
};
auto unsafeIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return Data_Array_NonEmpty::adaptAny()(Data_Array::unsafeIndex()(dictPartial));
    };
    return _;
};
auto toUnfoldable1() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable1) -> boxed {
        return [=](const boxed& xs) -> boxed {
            boxed len = Data_Array_NonEmpty::length()(xs);
            boxed f = [=](const boxed& i) -> boxed {
                return Data_Tuple::Tuple()([=](const boxed& dictPartial) -> boxed {
                    return Data_Array_NonEmpty::unsafeIndex()(dictPartial);
                }(undefined)(xs)(i))([=]() -> boxed {
                    boxed _Local_12 = Data_Ord::lessThan()(Data_Ord::ordInt())(i)(unbox<int>(len) - 1);
                    if (unbox<bool>(_Local_12)) {
                        return Data_Maybe::Just()(unbox<int>(i) + 1);
                    };
                    return Data_Maybe::Nothing();
                }());
            };
            return Data_Unfoldable1::unfoldr1()(dictUnfoldable1)(f)(0);
        };
    };
    return _;
};


} // end namespace Data_Array_NonEmpty


