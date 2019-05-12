#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Biapplicative/Control_Biapplicative.h"
#include "Control_Biapply/Control_Biapply.h"
#include "Data_Bifunctor/Data_Bifunctor.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Bifunctor_Clown/Data_Bifunctor_Clown.h"


namespace Data_Bifunctor_Clown {

auto Clown() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showClown() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Clown ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto ordClown() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto newtypeClown() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_Bifunctor_Clown::Clown());
};
auto functorClown() -> boxed {
    return Data_Functor::Functor()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return v1;
        };
    });
};
auto eqClown() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto bifunctorClown() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Bifunctor::Bifunctor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Data_Functor::map()(dictFunctor)(f)(v1);
                };
            };
        });
    };
    return _;
};
auto biapplyClown() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return Control_Biapply::Biapply()([=](const boxed&) -> boxed {
            return Data_Bifunctor_Clown::bifunctorClown()(dictApply["Functor0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Apply::apply()(dictApply)(v)(v1);
            };
        });
    };
    return _;
};
auto biapplicativeClown() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return Control_Biapplicative::Biapplicative()([=](const boxed&) -> boxed {
            return Data_Bifunctor_Clown::biapplyClown()(dictApplicative["Apply0"](undefined));
        })([=](const boxed& a) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Control_Applicative::pure()(dictApplicative)(a);
            };
        });
    };
    return _;
};


} // end namespace Data_Bifunctor_Clown


