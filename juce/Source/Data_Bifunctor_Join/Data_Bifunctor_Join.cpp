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

#include "Data_Bifunctor_Join/Data_Bifunctor_Join.h"


namespace Data_Bifunctor_Join {

auto Join() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showJoin() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Join ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto ordJoin() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto newtypeJoin() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_Bifunctor_Join::Join());
};
auto eqJoin() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto bifunctorJoin() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Bifunctor::bimap()(dictBifunctor)(f)(f)(v);
            };
        });
    };
    return _;
};
auto biapplyJoin() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapply) -> boxed {
        return Control_Apply::Apply()([=](const boxed&) -> boxed {
            return Data_Bifunctor_Join::bifunctorJoin()(dictBiapply["Bifunctor0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Biapply::biapply()(dictBiapply)(v)(v1);
            };
        });
    };
    return _;
};
auto biapplicativeJoin() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapplicative) -> boxed {
        return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
            return Data_Bifunctor_Join::biapplyJoin()(dictBiapplicative["Biapply0"](undefined));
        })([=](const boxed& a) -> boxed {
            return Control_Biapplicative::bipure()(dictBiapplicative)(a)(a);
        });
    };
    return _;
};


} // end namespace Data_Bifunctor_Join


