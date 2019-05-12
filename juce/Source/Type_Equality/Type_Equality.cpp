
#include "Type_Equality/Type_Equality.h"


namespace Type_Equality {

auto TypeEquals() -> const boxed& {
    static const boxed _ = [](const boxed& from) -> boxed {
        return [=](const boxed& to) -> boxed {
            return dict_t{
                { "from", from },
                { "to", to }
            };
        };
    };
    return _;
};
auto to() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["to"];
    };
    return _;
};
auto refl() -> boxed {
    return Type_Equality::TypeEquals()([=](const boxed& a) -> boxed {
        return a;
    })([=](const boxed& a) -> boxed {
        return a;
    });
};
auto from() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["from"];
    };
    return _;
};


} // end namespace Type_Equality


