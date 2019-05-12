#include "Control_Biapplicative/Control_Biapplicative.h"
#include "Control_Biapply/Control_Biapply.h"
#include "Data_Bifunctor/Data_Bifunctor.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Bifunctor_Product/Data_Bifunctor_Product.h"


namespace Data_Bifunctor_Product {

auto Product() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "Product", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto showProduct() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& dictShow1) -> boxed {
            return Data_Show::Show()([=](const boxed& v) -> boxed {
                return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Product ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(v["value0"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow1)(v["value1"]))(")"))));
            });
        };
    };
    return _;
};
auto eqProduct() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& dictEq1) -> boxed {
            return Data_Eq::Eq()([=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    return unbox<bool>(Data_Eq::eq()(dictEq)(x["value0"])(y["value0"])) && unbox<bool>(Data_Eq::eq()(dictEq1)(x["value1"])(y["value1"]));
                };
            });
        };
    };
    return _;
};
auto ordProduct() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictOrd1) -> boxed {
            return Data_Ord::Ord()([=](const boxed&) -> boxed {
                return Data_Bifunctor_Product::eqProduct()(dictOrd["Eq0"](undefined))(dictOrd1["Eq0"](undefined));
            })([=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    boxed v = Data_Ord::compare()(dictOrd)(x["value0"])(y["value0"]);
                    if (unbox<dict_t>(v).contains("LT")) {
                        return Data_Ordering::LT();
                    };
                    if (unbox<dict_t>(v).contains("GT")) {
                        return Data_Ordering::GT();
                    };
                    return Data_Ord::compare()(dictOrd1)(x["value1"])(y["value1"]);
                };
            });
        };
    };
    return _;
};
auto bifunctorProduct() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifunctor) -> boxed {
        return [=](const boxed& dictBifunctor1) -> boxed {
            return Data_Bifunctor::Bifunctor()([=](const boxed& f) -> boxed {
                return [=](const boxed& g) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return Data_Bifunctor_Product::Product()(Data_Bifunctor::bimap()(dictBifunctor)(f)(g)(v["value0"]))(Data_Bifunctor::bimap()(dictBifunctor1)(f)(g)(v["value1"]));
                    };
                };
            });
        };
    };
    return _;
};
auto biapplyProduct() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapply) -> boxed {
        return [=](const boxed& dictBiapply1) -> boxed {
            return Control_Biapply::Biapply()([=](const boxed&) -> boxed {
                return Data_Bifunctor_Product::bifunctorProduct()(dictBiapply["Bifunctor0"](undefined))(dictBiapply1["Bifunctor0"](undefined));
            })([=](const boxed& v) -> boxed {
                return [=](const boxed& v1) -> boxed {
                    return Data_Bifunctor_Product::Product()(Control_Biapply::biapply()(dictBiapply)(v["value0"])(v1["value0"]))(Control_Biapply::biapply()(dictBiapply1)(v["value1"])(v1["value1"]));
                };
            });
        };
    };
    return _;
};
auto biapplicativeProduct() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapplicative) -> boxed {
        return [=](const boxed& dictBiapplicative1) -> boxed {
            return Control_Biapplicative::Biapplicative()([=](const boxed&) -> boxed {
                return Data_Bifunctor_Product::biapplyProduct()(dictBiapplicative["Biapply0"](undefined))(dictBiapplicative1["Biapply0"](undefined));
            })([=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return Data_Bifunctor_Product::Product()(Control_Biapplicative::bipure()(dictBiapplicative)(a)(b))(Control_Biapplicative::bipure()(dictBiapplicative1)(a)(b));
                };
            });
        };
    };
    return _;
};


} // end namespace Data_Bifunctor_Product


