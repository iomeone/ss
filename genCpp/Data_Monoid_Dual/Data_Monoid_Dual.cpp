#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Monoid_Dual/Data_Monoid_Dual.h"


namespace Data_Monoid_Dual {

auto Dual() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showDual() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Dual ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto semigroupDual() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_Semigroup::append()(dictSemigroup)(v1)(v);
            };
        });
    };
    return _;
};
auto ordDual() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto monoidDual() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Data_Monoid_Dual::semigroupDual()(dictMonoid["Semigroup0"](undefined));
        })(Data_Monoid::mempty()(dictMonoid));
    };
    return _;
};
auto functorDual() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return f(m);
        };
    });
};
auto eqDual() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto eq1Dual() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Monoid_Dual::eqDual()(dictEq));
    });
};
auto ord1Dual() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Monoid_Dual::eq1Dual();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Monoid_Dual::ordDual()(dictOrd));
    });
};
auto boundedDual() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return dictBounded;
    };
    return _;
};
auto applyDual() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Monoid_Dual::functorDual();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return v(v1);
        };
    });
};
auto bindDual() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Monoid_Dual::applyDual();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& f) -> boxed {
            return f(v);
        };
    });
};
auto applicativeDual() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Monoid_Dual::applyDual();
    })(Data_Monoid_Dual::Dual());
};
auto monadDual() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Monoid_Dual::applicativeDual();
    })([=](const boxed&) -> boxed {
        return Data_Monoid_Dual::bindDual();
    });
};


} // end namespace Data_Monoid_Dual


