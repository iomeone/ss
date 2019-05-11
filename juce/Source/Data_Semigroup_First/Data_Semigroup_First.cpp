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

#include "Data_Semigroup_First/Data_Semigroup_First.h"


namespace Data_Semigroup_First {

auto First() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(First ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto semigroupFirst() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& x) -> boxed {
        return [=](const boxed& v) -> boxed {
            return x;
        };
    });
};
auto ordFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto functorFirst() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& m) -> boxed {
            return f(m);
        };
    });
};
auto eqFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto eq1First() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Semigroup_First::eqFirst()(dictEq));
    });
};
auto ord1First() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Semigroup_First::eq1First();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Semigroup_First::ordFirst()(dictOrd));
    });
};
auto boundedFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictBounded) -> boxed {
        return dictBounded;
    };
    return _;
};
auto applyFirst() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Semigroup_First::functorFirst();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return v(v1);
        };
    });
};
auto bindFirst() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Data_Semigroup_First::applyFirst();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& f) -> boxed {
            return f(v);
        };
    });
};
auto applicativeFirst() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Semigroup_First::applyFirst();
    })(Data_Semigroup_First::First());
};
auto monadFirst() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Data_Semigroup_First::applicativeFirst();
    })([=](const boxed&) -> boxed {
        return Data_Semigroup_First::bindFirst();
    });
};


} // end namespace Data_Semigroup_First


