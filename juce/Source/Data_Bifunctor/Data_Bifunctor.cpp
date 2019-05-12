#include "Control_Category/Control_Category.h"

#include "Data_Bifunctor/Data_Bifunctor.h"


namespace Data_Bifunctor {

auto Bifunctor() -> const boxed& {
    static const boxed _ = [](const boxed& bimap) -> boxed {
        return dict_t{
            { "bimap", bimap }
        };
    };
    return _;
};
auto bimap() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["bimap"];
    };
    return _;
};
auto lmap() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Bifunctor::bimap()(dictBifunctor)(f)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto rmap() -> const boxed& {
    static const boxed _ = [](const boxed& dictBifunctor) -> boxed {
        return Data_Bifunctor::bimap()(dictBifunctor)(Control_Category::identity()(Control_Category::categoryFn()));
    };
    return _;
};


} // end namespace Data_Bifunctor


