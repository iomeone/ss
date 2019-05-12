#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Comonad/Control_Comonad.h"
#include "Control_Extend/Control_Extend.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Plus/Control_Plus.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Monoid_Alternate/Data_Monoid_Alternate.h"


namespace Data_Monoid_Alternate {

auto Alternate() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Alternate ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto semigroupAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlt) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Alt::alt()(dictAlt)(v)(v1);
            };
        });
    };
    return _;
};
auto plusAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictPlus) -> boxed {
        return dictPlus;
    };
    return _;
};
auto ordAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto ord1Alternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd1) -> boxed {
        return dictOrd1;
    };
    return _;
};
auto monoidAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictPlus) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Data_Monoid_Alternate::semigroupAlternate()(dictPlus["Alt0"](undefined));
        })(Control_Plus::empty()(dictPlus));
    };
    return _;
};
auto monadAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return dictMonad;
    };
    return _;
};
auto functorAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return dictFunctor;
    };
    return _;
};
auto extendAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictExtend) -> boxed {
        return dictExtend;
    };
    return _;
};
auto eqAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto eq1Alternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq1) -> boxed {
        return dictEq1;
    };
    return _;
};
auto comonadAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonad) -> boxed {
        return dictComonad;
    };
    return _;
};
auto boundedAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return dictBounded;
    };
    return _;
};
auto bindAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return dictBind;
    };
    return _;
};
auto applyAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return dictApply;
    };
    return _;
};
auto applicativeAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return dictApplicative;
    };
    return _;
};
auto alternativeAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlternative) -> boxed {
        return dictAlternative;
    };
    return _;
};
auto altAlternate() -> const boxed& {
    static const boxed _ = [](const boxed& dictAlt) -> boxed {
        return dictAlt;
    };
    return _;
};


} // end namespace Data_Monoid_Alternate


