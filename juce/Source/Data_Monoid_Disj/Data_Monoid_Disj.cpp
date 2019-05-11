#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Monoid_Disj/Data_Monoid_Disj.h"


namespace Data_Monoid_Disj {

auto Disj() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showDisj() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Disj ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto semiringDisj() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return Data_Semiring::Semiring()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_HeytingAlgebra::disj()(dictHeytingAlgebra)(v)(v1);
            };
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_HeytingAlgebra::conj()(dictHeytingAlgebra)(v)(v1);
            };
        })(Data_HeytingAlgebra::tt()(dictHeytingAlgebra))(Data_HeytingAlgebra::ff()(dictHeytingAlgebra));
    };
    return _;
};
auto semigroupDisj() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_HeytingAlgebra::disj()(dictHeytingAlgebra)(v)(v1);
            };
        });
    };
    return _;
};
auto ordDisj() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto monoidDisj() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Data_Monoid_Disj::semigroupDisj()(dictHeytingAlgebra);
        })(Data_HeytingAlgebra::ff()(dictHeytingAlgebra));
    };
    return _;
};
auto functorDisj() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return f(m);
        };
    });
};
auto eqDisj() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto eq1Disj() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Monoid_Disj::eqDisj()(dictEq));
    });
};
auto ord1Disj() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Monoid_Disj::eq1Disj();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Monoid_Disj::ordDisj()(dictOrd));
    });
};
auto boundedDisj() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return dictBounded;
    };
    return _;
};
auto applyDisj() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Monoid_Disj::functorDisj();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return v(v1);
        };
    });
};
auto bindDisj() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Monoid_Disj::applyDisj();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& f) -> boxed {
            return f(v);
        };
    });
};
auto applicativeDisj() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Monoid_Disj::applyDisj();
    })(Data_Monoid_Disj::Disj());
};
auto monadDisj() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Monoid_Disj::applicativeDisj();
    })([=](const boxed&) -> boxed {
        return Data_Monoid_Disj::bindDisj();
    });
};


} // end namespace Data_Monoid_Disj


