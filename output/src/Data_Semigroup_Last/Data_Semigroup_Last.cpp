#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Semigroup_Last/Data_Semigroup_Last.h"


namespace Data_Semigroup_Last {

auto Last() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showLast() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Last ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto semigroupLast() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& x) -> boxed {
            return x;
        };
    });
};
auto ordLast() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto functorLast() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return f(m);
        };
    });
};
auto eqLast() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto eq1Last() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Semigroup_Last::eqLast()(dictEq));
    });
};
auto ord1Last() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Semigroup_Last::eq1Last();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Semigroup_Last::ordLast()(dictOrd));
    });
};
auto boundedLast() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return dictBounded;
    };
    return _;
};
auto applyLast() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Semigroup_Last::functorLast();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return v(v1);
        };
    });
};
auto bindLast() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Semigroup_Last::applyLast();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& f) -> boxed {
            return f(v);
        };
    });
};
auto applicativeLast() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Semigroup_Last::applyLast();
    })(Data_Semigroup_Last::Last());
};
auto monadLast() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Semigroup_Last::applicativeLast();
    })([=](const boxed&) -> boxed {
        return Data_Semigroup_Last::bindLast();
    });
};


} // end namespace Data_Semigroup_Last


