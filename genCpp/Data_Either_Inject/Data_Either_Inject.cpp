#include "Control_Category/Control_Category.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Either/Data_Either.h"
#include "Data_Function/Data_Function.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Prelude/Prelude.h"

#include "Data_Either_Inject/Data_Either_Inject.h"


namespace Data_Either_Inject {

auto Inject() -> const boxed& {
    static const boxed _ = [](const boxed& inj) -> boxed {
        return [=](const boxed& prj) -> boxed {
            return dict_t{
                { "inj", inj },
                { "prj", prj }
            };
        };
    };
    return _;
};
auto prj() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["prj"];
    };
    return _;
};
auto injectReflexive() -> boxed {
    return Data_Either_Inject::Inject()(Control_Category::identity()(Control_Category::categoryFn()))(Data_Maybe::Just());
};
auto injectLeft() -> boxed {
    return Data_Either_Inject::Inject()(Data_Either::Left())(Data_Either::either()(Data_Maybe::Just())(Data_Function::_const_()(Data_Maybe::Nothing())));
};
auto inj() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["inj"];
    };
    return _;
};
auto injectRight() -> const boxed& {
    static const boxed _ = [](const boxed& dictInject) -> boxed {
        return Data_Either_Inject::Inject()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Either::Right())(Data_Either_Inject::inj()(dictInject)))(Data_Either::either()(Data_Function::_const_()(Data_Maybe::Nothing()))(Data_Either_Inject::prj()(dictInject)));
    };
    return _;
};


} // end namespace Data_Either_Inject


