#include "Control_Category/Control_Category.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Prelude/Prelude.h"

#include "Data_Distributive/Data_Distributive.h"


namespace Data_Distributive {

auto Distributive() -> const boxed& {
    static const boxed _ = [](const boxed& Functor0) -> boxed {
        return [=](const boxed& collect) -> boxed {
            return [=](const boxed& distribute) -> boxed {
                return dict_t{
                    { "Functor0", Functor0 },
                    { "collect", collect },
                    { "distribute", distribute }
                };
            };
        };
    };
    return _;
};
auto distributiveIdentity() -> boxed {
    return Data_Distributive::Distributive()([=](const boxed&) -> boxed {
        return Data_Identity::functorIdentity();
    })([=](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(Data_Functor::map()(dictFunctor)(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(f)));
        };
    })([=](const boxed& dictFunctor) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Identity::Identity())(Data_Functor::map()(dictFunctor)(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity())));
    });
};
auto distribute() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["distribute"];
    };
    return _;
};
auto distributiveFunction() -> boxed {
    return Data_Distributive::Distributive()([=](const boxed&) -> boxed {
        return Data_Functor::functorFn();
    })([=](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Distributive::distribute()(Data_Distributive::distributiveFunction())(dictFunctor))(Data_Functor::map()(dictFunctor)(f));
        };
    })([=](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& e) -> boxed {
                return Data_Functor::map()(dictFunctor)([=](const boxed& v) -> boxed {
                    return v(e);
                })(a);
            };
        };
    });
};
auto cotraverse() -> const boxed& {
    static const boxed _ = [](const boxed& dictDistributive) -> boxed {
        return [=](const boxed& dictFunctor) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictDistributive["Functor0"](undefined))(f))(Data_Distributive::distribute()(dictDistributive)(dictFunctor));
            };
        };
    };
    return _;
};
auto collectDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictDistributive) -> boxed {
        return [=](const boxed& dictFunctor) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Distributive::distribute()(dictDistributive)(dictFunctor))(Data_Functor::map()(dictFunctor)(f));
            };
        };
    };
    return _;
};
auto collect() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["collect"];
    };
    return _;
};
auto distributeDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictDistributive) -> boxed {
        return [=](const boxed& dictFunctor) -> boxed {
            return Data_Distributive::collect()(dictDistributive)(dictFunctor)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};


} // end namespace Data_Distributive


