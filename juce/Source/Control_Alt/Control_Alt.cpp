#include "Data_Functor/Data_Functor.h"
#include "Data_Semigroup/Data_Semigroup.h"

#include "Control_Alt/Control_Alt.h"


namespace Control_Alt {

auto Alt() -> const boxed& {
    static const boxed _ = [](const boxed& Functor0) -> boxed {
        return [=](const boxed& alt) -> boxed {
            return dict_t{
                { "Functor0", Functor0 },
                { "alt", alt }
            };
        };
    };
    return _;
};
auto altArray() -> boxed {
    return Control_Alt::Alt()([=](const boxed&) -> boxed {
        return Data_Functor::functorArray();
    })(Data_Semigroup::append()(Data_Semigroup::semigroupArray()));
};
auto alt() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["alt"];
    };
    return _;
};


} // end namespace Control_Alt


