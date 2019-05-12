#include "Data_Unit/Data_Unit.h"

#include "Control_Lazy/Control_Lazy.h"


namespace Control_Lazy {

auto Lazy() -> const boxed& {
    static const boxed _ = [](const boxed& defer) -> boxed {
        return dict_t{
            { "defer", defer }
        };
    };
    return _;
};
auto lazyUnit() -> boxed {
    return Control_Lazy::Lazy()([=](const boxed& v) -> boxed {
        return Data_Unit::unit();
    });
};
auto lazyFn() -> boxed {
    return Control_Lazy::Lazy()([=](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return f(Data_Unit::unit())(x);
        };
    });
};
auto defer() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["defer"];
    };
    return _;
};
auto fix() -> const boxed& {
    static const boxed _ = [](const boxed& dictLazy) -> boxed {
        return [=](const boxed& f) -> boxed {
            boxed::recur go;
            boxed::recur::weak go_Weak_(go);
            go = [=]() -> boxed {
                auto& go = go_Weak_;
                return Control_Lazy::defer()(dictLazy)([=](const boxed& v) -> boxed {
                    return f(go);
                });
            }();
            return go;
        };
    };
    return _;
};


} // end namespace Control_Lazy


