#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Plus/Control_Plus.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_List_Lazy/Data_List_Lazy.h"
#include "Data_List_Lazy_Types/Data_List_Lazy_Types.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"

#include "Data_List_ZipList/Data_List_ZipList.h"


namespace Data_List_ZipList {

auto ZipList() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto traversableZipList() -> boxed {
    return Data_List_Lazy_Types::traversableList();
};
auto showZipList() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(ZipList ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_List_Lazy_Types::showList()(dictShow))(v))(")"));
        });
    };
    return _;
};
auto semigroupZipList() -> boxed {
    return Data_List_Lazy_Types::semigroupList();
};
auto ordZipList() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_List_Lazy_Types::ordList()(dictOrd);
    };
    return _;
};
auto newtypeZipList() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_List_ZipList::ZipList());
};
auto monoidZipList() -> boxed {
    return Data_List_Lazy_Types::monoidList();
};
auto functorZipList() -> boxed {
    return Data_List_Lazy_Types::functorList();
};
auto foldableZipList() -> boxed {
    return Data_List_Lazy_Types::foldableList();
};
auto eqZipList() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_List_Lazy_Types::eqList()(dictEq);
    };
    return _;
};
auto applyZipList() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_List_ZipList::functorZipList();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_List_Lazy::zipWith()(Data_Function::apply())(v)(v1);
        };
    });
};
auto zipListIsNotBind() -> const boxed& {
    static const boxed _ = [](const boxed& dictFail) -> boxed {
        return Control_Bind::Bind()([=](const boxed&) -> boxed {
            return Data_List_ZipList::applyZipList();
        })(Partial_Unsafe::unsafeCrashWith()("bind: unreachable"));
    };
    return _;
};
auto applicativeZipList() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_List_ZipList::applyZipList();
    })(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_List_ZipList::ZipList())(Data_List_Lazy::repeat()));
};
auto altZipList() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_List_ZipList::functorZipList();
    })(Data_Semigroup::append()(Data_List_ZipList::semigroupZipList()));
};
auto plusZipList() -> boxed {
    return Control_Plus::Plus()([=](const boxed&) -> boxed {
        return Data_List_ZipList::altZipList();
    })(Data_Monoid::mempty()(Data_List_ZipList::monoidZipList()));
};
auto alternativeZipList() -> boxed {
    return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
        return Data_List_ZipList::applicativeZipList();
    })([=](const boxed&) -> boxed {
        return Data_List_ZipList::plusZipList();
    });
};


} // end namespace Data_List_ZipList


