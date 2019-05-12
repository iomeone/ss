#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Control_Plus/Control_Plus.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Functor_Invariant/Data_Functor_Invariant.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Maybe_First/Data_Maybe_First.h"


namespace Data_Maybe_First {

auto First() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("First (")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Maybe::showMaybe()(dictShow))(v))(")"));
        });
    };
    return _;
};
auto semigroupFirst() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Just")) {
                return v;
            };
            return v1;
        };
    });
};
auto ordFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Maybe::ordMaybe()(dictOrd);
    };
    return _;
};
auto ord1First() -> boxed {
    return Data_Maybe::ord1Maybe();
};
auto newtypeFirst() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_Maybe_First::First());
};
auto monoidFirst() -> boxed {
    return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
        return Data_Maybe_First::semigroupFirst();
    })(Data_Maybe::Nothing());
};
auto monadFirst() -> boxed {
    return Data_Maybe::monadMaybe();
};
auto invariantFirst() -> boxed {
    return Data_Maybe::invariantMaybe();
};
auto functorFirst() -> boxed {
    return Data_Maybe::functorMaybe();
};
auto extendFirst() -> boxed {
    return Data_Maybe::extendMaybe();
};
auto eqFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Maybe::eqMaybe()(dictEq);
    };
    return _;
};
auto eq1First() -> boxed {
    return Data_Maybe::eq1Maybe();
};
auto boundedFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return Data_Maybe::boundedMaybe()(dictBounded);
    };
    return _;
};
auto bindFirst() -> boxed {
    return Data_Maybe::bindMaybe();
};
auto applyFirst() -> boxed {
    return Data_Maybe::applyMaybe();
};
auto applicativeFirst() -> boxed {
    return Data_Maybe::applicativeMaybe();
};
auto altFirst() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_Maybe_First::functorFirst();
    })(Data_Semigroup::append()(Data_Maybe_First::semigroupFirst()));
};
auto plusFirst() -> boxed {
    return Control_Plus::Plus()([=](const boxed&) -> boxed {
        return Data_Maybe_First::altFirst();
    })(Data_Monoid::mempty()(Data_Maybe_First::monoidFirst()));
};
auto alternativeFirst() -> boxed {
    return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
        return Data_Maybe_First::applicativeFirst();
    })([=](const boxed&) -> boxed {
        return Data_Maybe_First::plusFirst();
    });
};
auto monadZeroFirst() -> boxed {
    return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
        return Data_Maybe_First::alternativeFirst();
    })([=](const boxed&) -> boxed {
        return Data_Maybe_First::monadFirst();
    });
};


} // end namespace Data_Maybe_First


