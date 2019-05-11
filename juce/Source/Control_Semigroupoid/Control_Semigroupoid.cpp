
#include "Control_Semigroupoid/Control_Semigroupoid.h"


namespace Control_Semigroupoid {

auto Semigroupoid() -> const boxed& {
    static const boxed _ = [](const boxed& compose) -> boxed {
        return dict_t{
            { "compose", compose }
        };
    };
    return _;
};
auto semigroupoidFn() -> boxed {
    return Control_Semigroupoid::Semigroupoid()([=](const boxed& f) -> boxed {
        return [=](const boxed& g) -> boxed {
            return [=](const boxed& x) -> boxed {
                return f(g(x));
            };
        };
    });
};
auto compose() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["compose"];
    };
    return _;
};
auto composeFlipped() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroupoid) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return Control_Semigroupoid::compose()(dictSemigroupoid)(g)(f);
            };
        };
    };
    return _;
};


} // end namespace Control_Semigroupoid


