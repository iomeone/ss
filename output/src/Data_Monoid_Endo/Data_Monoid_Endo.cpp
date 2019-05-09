#include "Control_Category/Control_Category.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Monoid_Endo/Data_Monoid_Endo.h"


namespace Data_Monoid_Endo {

auto Endo() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showEndo() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Endo ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto semigroupEndo() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroupoid) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Semigroupoid::compose()(dictSemigroupoid)(v)(v1);
            };
        });
    };
    return _;
};
auto ordEndo() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto monoidEndo() -> const boxed& {
    static const boxed _ = [](const boxed& dictCategory) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Data_Monoid_Endo::semigroupEndo()(dictCategory["Semigroupoid0"](undefined));
        })(Control_Category::identity()(dictCategory));
    };
    return _;
};
auto eqEndo() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto boundedEndo() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return dictBounded;
    };
    return _;
};


} // end namespace Data_Monoid_Endo


