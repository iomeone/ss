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

#include "Data_Bifunctor_Wrap/Data_Bifunctor_Wrap.h"


namespace Data_Bifunctor_Wrap {

auto Wrap() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showWrap() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()([=](const boxed& v) -> boxed {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Wrap ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v))(")"));
        });
    };
    return _;
};
auto ordWrap() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return dictOrd;
    };
    return _;
};
auto newtypeWrap() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_Bifunctor_Wrap::Wrap());
};
auto functorWrap() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifunctor) -> boxed {
        return Data_Functor::Functor()([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Bifunctor::rmap()(dictBifunctor)(f)(v);
            };
        });
    };
    return _;
};
auto eqWrap() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return dictEq;
    };
    return _;
};
auto bifunctorWrap() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifunctor) -> boxed {
        return Data_Bifunctor::Bifunctor()([=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Data_Bifunctor::bimap()(dictBifunctor)(f)(g)(v);
                };
            };
        });
    };
    return _;
};
auto biapplyWrap() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapply) -> boxed {
        return Control_Biapply::Biapply()([=](const boxed&) -> boxed {
            return Data_Bifunctor_Wrap::bifunctorWrap()(dictBiapply["Bifunctor0"](undefined));
        })([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Biapply::biapply()(dictBiapply)(v)(v1);
            };
        });
    };
    return _;
};
auto biapplicativeWrap() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapplicative) -> boxed {
        return Control_Biapplicative::Biapplicative()([=](const boxed&) -> boxed {
            return Data_Bifunctor_Wrap::biapplyWrap()(dictBiapplicative["Biapply0"](undefined));
        })([=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Control_Biapplicative::bipure()(dictBiapplicative)(a)(b);
            };
        });
    };
    return _;
};


} // end namespace Data_Bifunctor_Wrap


