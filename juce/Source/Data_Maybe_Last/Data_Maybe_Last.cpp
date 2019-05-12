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

#include "Data_Maybe_Last/Data_Maybe_Last.h"


namespace Data_Maybe_Last {

auto Last() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showLast() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Last ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Maybe::showMaybe()(dictShow))(v))(")"));
        });
    };
    return _;
};
auto semigroupLast() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v1).contains("Just")) {
                return v1;
            };
            if (unbox<dict_t>(v1).contains("Nothing")) {
                return v;
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Maybe.Last (line 52, column 1 - line 52, column 45): ");
        };
    });
};
auto ordLast() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Maybe::ordMaybe()(dictOrd);
    };
    return _;
};
auto ord1Last() -> boxed {
    return Data_Maybe::ord1Maybe();
};
auto newtypeLast() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_Maybe_Last::Last());
};
auto monoidLast() -> boxed {
    return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
        return Data_Maybe_Last::semigroupLast();
    })(Data_Maybe::Nothing());
};
auto monadLast() -> boxed {
    return Data_Maybe::monadMaybe();
};
auto invariantLast() -> boxed {
    return Data_Maybe::invariantMaybe();
};
auto functorLast() -> boxed {
    return Data_Maybe::functorMaybe();
};
auto extendLast() -> boxed {
    return Data_Maybe::extendMaybe();
};
auto eqLast() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Maybe::eqMaybe()(dictEq);
    };
    return _;
};
auto eq1Last() -> boxed {
    return Data_Maybe::eq1Maybe();
};
auto boundedLast() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return Data_Maybe::boundedMaybe()(dictBounded);
    };
    return _;
};
auto bindLast() -> boxed {
    return Data_Maybe::bindMaybe();
};
auto applyLast() -> boxed {
    return Data_Maybe::applyMaybe();
};
auto applicativeLast() -> boxed {
    return Data_Maybe::applicativeMaybe();
};
auto altLast() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_Maybe_Last::functorLast();
    })(Data_Semigroup::append()(Data_Maybe_Last::semigroupLast()));
};
auto plusLast() -> boxed {
    return Control_Plus::Plus()([=](const boxed&) -> boxed {
        return Data_Maybe_Last::altLast();
    })(Data_Monoid::mempty()(Data_Maybe_Last::monoidLast()));
};
auto alternativeLast() -> boxed {
    return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
        return Data_Maybe_Last::applicativeLast();
    })([=](const boxed&) -> boxed {
        return Data_Maybe_Last::plusLast();
    });
};
auto monadZeroLast() -> boxed {
    return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
        return Data_Maybe_Last::alternativeLast();
    })([=](const boxed&) -> boxed {
        return Data_Maybe_Last::monadLast();
    });
};


} // end namespace Data_Maybe_Last


