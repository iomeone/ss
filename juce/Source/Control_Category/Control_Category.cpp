#include "Control_Semigroupoid/Control_Semigroupoid.h"

#include "Control_Category/Control_Category.h"


namespace Control_Category {

auto Category() -> const boxed& {
    static const boxed _ = [](const boxed& Semigroupoid0) -> boxed {
        return [=](const boxed& identity) -> boxed {
            return dict_t{
                { "Semigroupoid0", Semigroupoid0 },
                { "identity", identity }
            };
        };
    };
    return _;
};
auto identity() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["identity"];
    };
    return _;
};
auto categoryFn() -> boxed {
    return Control_Category::Category()([=](const boxed&) -> boxed {
        return Control_Semigroupoid::semigroupoidFn();
    })([=](const boxed& x) -> boxed {
        return x;
    });
};


} // end namespace Control_Category


