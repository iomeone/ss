#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_FoldableWithIndex/Data_FoldableWithIndex.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_Semigroup_Traversable/Data_Semigroup_Traversable.h"
#include "Data_Show/Data_Show.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_TraversableWithIndex/Data_TraversableWithIndex.h"
#include "Data_Unfoldable1/Data_Unfoldable1.h"
#include "Prelude/Prelude.h"

#include "Data_Array_NonEmpty_Internal/Data_Array_NonEmpty_Internal.h"


namespace Data_Array_NonEmpty_Internal {

auto NonEmptyArray() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto unfoldable1NonEmptyArray() -> boxed {
    return Data_Unfoldable1::unfoldable1Array();
};
auto traversableWithIndexNonEmptyArray() -> boxed {
    return Data_TraversableWithIndex::traversableWithIndexArray();
};
auto traversableNonEmptyArray() -> boxed {
    return Data_Traversable::traversableArray();
};
auto showNonEmptyArray() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(NonEmptyArray ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showArray()(dictShow))(v))(")"));
        });
    };
    return _;
};
auto semigroupNonEmptyArray() -> boxed {
    return Data_Semigroup::semigroupArray();
};
auto ordNonEmptyArray() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::ordArray()(dictOrd);
    };
    return _;
};
auto ord1NonEmptyArray() -> boxed {
    return Data_Ord::ord1Array();
};
auto monadNonEmptyArray() -> boxed {
    return Control_Monad::monadArray();
};
auto functorWithIndexNonEmptyArray() -> boxed {
    return Data_FunctorWithIndex::functorWithIndexArray();
};
auto functorNonEmptyArray() -> boxed {
    return Data_Functor::functorArray();
};
auto foldableWithIndexNonEmptyArray() -> boxed {
    return Data_FoldableWithIndex::foldableWithIndexArray();
};
auto foldableNonEmptyArray() -> boxed {
    return Data_Foldable::foldableArray();
};
auto foldable1NonEmptyArray() -> boxed {
    return Data_Semigroup_Foldable::Foldable1()([=](const boxed&) -> boxed {
        return Data_Array_NonEmpty_Internal::foldableNonEmptyArray();
    })([=](const boxed& dictSemigroup) -> boxed {
        return Data_Array_NonEmpty_Internal::fold1Impl()(Data_Semigroup::append()(dictSemigroup));
    })([=](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup_Foldable::foldMap1Default()(Data_Array_NonEmpty_Internal::foldable1NonEmptyArray())(Data_Array_NonEmpty_Internal::functorNonEmptyArray())(dictSemigroup);
    });
};
auto traversable1NonEmptyArray() -> boxed {
    return Data_Semigroup_Traversable::Traversable1()([=](const boxed&) -> boxed {
        return Data_Array_NonEmpty_Internal::foldable1NonEmptyArray();
    })([=](const boxed&) -> boxed {
        return Data_Array_NonEmpty_Internal::traversableNonEmptyArray();
    })([=](const boxed& dictApply) -> boxed {
        return Data_Semigroup_Traversable::sequence1Default()(Data_Array_NonEmpty_Internal::traversable1NonEmptyArray())(dictApply);
    })([=](const boxed& dictApply) -> boxed {
        return Data_Array_NonEmpty_Internal::traverse1Impl()(Control_Apply::apply()(dictApply))(Data_Functor::map()(dictApply["Functor0"](undefined)));
    });
};
auto eqNonEmptyArray() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::eqArray()(dictEq);
    };
    return _;
};
auto eq1NonEmptyArray() -> boxed {
    return Data_Eq::eq1Array();
};
auto bindNonEmptyArray() -> boxed {
    return Control_Bind::bindArray();
};
auto applyNonEmptyArray() -> boxed {
    return Control_Apply::applyArray();
};
auto applicativeNonEmptyArray() -> boxed {
    return Control_Applicative::applicativeArray();
};
auto altNonEmptyArray() -> boxed {
    return Control_Alt::altArray();
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto fold1Impl() -> const boxed& { static const boxed _ = foreign().at("fold1Impl"); return _; };
auto traverse1Impl() -> const boxed& { static const boxed _ = foreign().at("traverse1Impl"); return _; };

} // end namespace Data_Array_NonEmpty_Internal


