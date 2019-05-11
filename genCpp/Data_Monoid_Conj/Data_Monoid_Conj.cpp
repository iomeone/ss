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

#include "Data_Monoid_Conj/Data_Monoid_Conj.h"


namespace Data_Monoid_Conj {

auto Conj() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showConj() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Conj ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto semiringConj() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return Data_Semiring::Semiring()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_HeytingAlgebra::conj()(dictHeytingAlgebra)(v)(v1);
            };
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_HeytingAlgebra::disj()(dictHeytingAlgebra)(v)(v1);
            };
        })(Data_HeytingAlgebra::ff()(dictHeytingAlgebra))(Data_HeytingAlgebra::tt()(dictHeytingAlgebra));
    };
    return _;
};
auto semigroupConj() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_HeytingAlgebra::conj()(dictHeytingAlgebra)(v)(v1);
            };
        });
    };
    return _;
};
auto ordConj() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto monoidConj() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Data_Monoid_Conj::semigroupConj()(dictHeytingAlgebra);
        })(Data_HeytingAlgebra::tt()(dictHeytingAlgebra));
    };
    return _;
};
auto functorConj() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return f(m);
        };
    });
};
auto eqConj() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto eq1Conj() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Monoid_Conj::eqConj()(dictEq));
    });
};
auto ord1Conj() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Monoid_Conj::eq1Conj();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Monoid_Conj::ordConj()(dictOrd));
    });
};
auto boundedConj() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return dictBounded;
    };
    return _;
};
auto applyConj() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Monoid_Conj::functorConj();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return v(v1);
        };
    });
};
auto bindConj() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Monoid_Conj::applyConj();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& f) -> boxed {
            return f(v);
        };
    });
};
auto applicativeConj() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Monoid_Conj::applyConj();
    })(Data_Monoid_Conj::Conj());
};
auto monadConj() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Monoid_Conj::applicativeConj();
    })([=](const boxed&) -> boxed {
        return Data_Monoid_Conj::bindConj();
    });
};


} // end namespace Data_Monoid_Conj


