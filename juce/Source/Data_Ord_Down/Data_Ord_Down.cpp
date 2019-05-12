#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Ord_Down/Data_Ord_Down.h"


namespace Data_Ord_Down {

auto Down() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showDown() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Down ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto newtypeDown() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_Ord_Down::Down());
};
auto eqDown() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto ordDown() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord()([=](const boxed&) -> boxed {
            return Data_Ord_Down::eqDown()(dictOrd["Eq0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_Ordering::invert()(Data_Ord::compare()(dictOrd)(v)(v1));
            };
        });
    };
    return _;
};
auto boundedDown() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
            return Data_Ord_Down::ordDown()(dictBounded["Ord0"](undefined));
        })(Data_Bounded::top()(dictBounded))(Data_Bounded::bottom()(dictBounded));
    };
    return _;
};


} // end namespace Data_Ord_Down


