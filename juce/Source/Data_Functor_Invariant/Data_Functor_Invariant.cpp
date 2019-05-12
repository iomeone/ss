#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid_Additive/Data_Monoid_Additive.h"
#include "Data_Monoid_Conj/Data_Monoid_Conj.h"
#include "Data_Monoid_Disj/Data_Monoid_Disj.h"
#include "Data_Monoid_Dual/Data_Monoid_Dual.h"
#include "Data_Monoid_Endo/Data_Monoid_Endo.h"
#include "Data_Monoid_Multiplicative/Data_Monoid_Multiplicative.h"

#include "Data_Functor_Invariant/Data_Functor_Invariant.h"


namespace Data_Functor_Invariant {

auto Invariant() -> const boxed& {
    static const boxed _ = [](const boxed& imap) -> boxed {
        return dict_t{
            { "imap", imap }
        };
    };
    return _;
};
auto invariantMultiplicative() -> boxed {
    return Data_Functor_Invariant::Invariant()([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return f(v1);
            };
        };
    });
};
auto invariantEndo() -> boxed {
    return Data_Functor_Invariant::Invariant()([=](const boxed& ab) -> boxed {
        return [=](const boxed& ba) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(ab)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(v)(ba));
            };
        };
    });
};
auto invariantDual() -> boxed {
    return Data_Functor_Invariant::Invariant()([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return f(v1);
            };
        };
    });
};
auto invariantDisj() -> boxed {
    return Data_Functor_Invariant::Invariant()([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return f(v1);
            };
        };
    });
};
auto invariantConj() -> boxed {
    return Data_Functor_Invariant::Invariant()([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return f(v1);
            };
        };
    });
};
auto invariantAdditive() -> boxed {
    return Data_Functor_Invariant::Invariant()([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return f(v1);
            };
        };
    });
};
auto imapF() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictFunctor)(f);
            };
        };
    };
    return _;
};
auto invariantArray() -> boxed {
    return Data_Functor_Invariant::Invariant()(Data_Functor_Invariant::imapF()(Data_Functor::functorArray()));
};
auto invariantFn() -> boxed {
    return Data_Functor_Invariant::Invariant()(Data_Functor_Invariant::imapF()(Data_Functor::functorFn()));
};
auto imap() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["imap"];
    };
    return _;
};


} // end namespace Data_Functor_Invariant


