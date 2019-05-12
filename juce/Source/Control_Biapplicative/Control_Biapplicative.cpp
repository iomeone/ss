#include "Control_Biapply/Control_Biapply.h"

#include "Control_Biapplicative/Control_Biapplicative.h"


namespace Control_Biapplicative {

auto Biapplicative() -> const boxed& {
    static const boxed _ = [](const boxed& Biapply0) -> boxed {
        return [=](const boxed& bipure) -> boxed {
            return dict_t{
                { "Biapply0", Biapply0 },
                { "bipure", bipure }
            };
        };
    };
    return _;
};
auto bipure() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["bipure"];
    };
    return _;
};


} // end namespace Control_Biapplicative


