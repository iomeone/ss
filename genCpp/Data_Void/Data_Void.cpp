#include "Data_Show/Data_Show.h"

#include "Data_Void/Data_Void.h"


namespace Data_Void {

auto Void() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto absurd() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        boxed::recur spin;
        boxed::recur::weak spin_Weak_(spin);
        spin = [=](const boxed& v) -> boxed {
            boxed spin = spin_Weak_;
            return spin(v);
        };
        return spin(a);
    };
    return _;
};
auto showVoid() -> boxed {
    return Data_Show::Show()(Data_Void::absurd());
};


} // end namespace Data_Void


