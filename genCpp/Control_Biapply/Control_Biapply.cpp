#include "Control_Category/Control_Category.h"
#include "Data_Bifunctor/Data_Bifunctor.h"
#include "Data_Function/Data_Function.h"

#include "Control_Biapply/Control_Biapply.h"


namespace Control_Biapply {

auto Biapply() -> const boxed& {
    static const boxed _ = [](const boxed& Bifunctor0) -> boxed {
        return [=](const boxed& biapply) -> boxed {
            return dict_t{
                { "Bifunctor0", Bifunctor0 },
                { "biapply", biapply }
            };
        };
    };
    return _;
};
auto biapply() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["biapply"];
    };
    return _;
};
auto biapplyFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapply) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Control_Biapply::biapply()(dictBiapply)(Control_Category::identity()(Control_Category::categoryFn())(Data_Bifunctor::bimap()(dictBiapply["Bifunctor0"](undefined))(Data_Function::_const_()(Control_Category::identity()(Control_Category::categoryFn())))(Data_Function::_const_()(Control_Category::identity()(Control_Category::categoryFn()))))(a))(b);
            };
        };
    };
    return _;
};
auto biapplySecond() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapply) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Control_Biapply::biapply()(dictBiapply)(Control_Category::identity()(Control_Category::categoryFn())(Data_Bifunctor::bimap()(dictBiapply["Bifunctor0"](undefined))(Data_Function::_const_())(Data_Function::_const_()))(a))(b);
            };
        };
    };
    return _;
};
auto bilift2() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return [=](const boxed& b) -> boxed {
                        return Control_Biapply::biapply()(dictBiapply)(Control_Category::identity()(Control_Category::categoryFn())(Data_Bifunctor::bimap()(dictBiapply["Bifunctor0"](undefined))(f)(g))(a))(b);
                    };
                };
            };
        };
    };
    return _;
};
auto bilift3() -> const boxed& {
    static const boxed _ = [](const boxed& dictBiapply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return [=](const boxed& b) -> boxed {
                        return [=](const boxed& c) -> boxed {
                            return Control_Biapply::biapply()(dictBiapply)(Control_Biapply::biapply()(dictBiapply)(Control_Category::identity()(Control_Category::categoryFn())(Data_Bifunctor::bimap()(dictBiapply["Bifunctor0"](undefined))(f)(g))(a))(b))(c);
                        };
                    };
                };
            };
        };
    };
    return _;
};


} // end namespace Control_Biapply


