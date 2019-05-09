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
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Monoid_Additive/Data_Monoid_Additive.h"


namespace Data_Monoid_Additive {

auto Additive() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showAdditive() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Additive ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto semigroupAdditive() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemiring) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_Semiring::add()(dictSemiring)(v)(v1);
            };
        });
    };
    return _;
};
auto ordAdditive() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto monoidAdditive() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemiring) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Data_Monoid_Additive::semigroupAdditive()(dictSemiring);
        })(Data_Semiring::zero()(dictSemiring));
    };
    return _;
};
auto functorAdditive() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return f(m);
        };
    });
};
auto eqAdditive() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto eq1Additive() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Monoid_Additive::eqAdditive()(dictEq));
    });
};
auto ord1Additive() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Monoid_Additive::eq1Additive();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Monoid_Additive::ordAdditive()(dictOrd));
    });
};
auto boundedAdditive() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return dictBounded;
    };
    return _;
};
auto applyAdditive() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Monoid_Additive::functorAdditive();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return v(v1);
        };
    });
};
auto bindAdditive() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Monoid_Additive::applyAdditive();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& f) -> boxed {
            return f(v);
        };
    });
};
auto applicativeAdditive() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Monoid_Additive::applyAdditive();
    })(Data_Monoid_Additive::Additive());
};
auto monadAdditive() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Monoid_Additive::applicativeAdditive();
    })([=](const boxed&) -> boxed {
        return Data_Monoid_Additive::bindAdditive();
    });
};


} // end namespace Data_Monoid_Additive


