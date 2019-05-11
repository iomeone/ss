#include "Control_Category/Control_Category.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"

#include "Data_Function/Data_Function.h"


namespace Data_Function {

auto on() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& g) -> boxed {
            return [=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    return f(g(x))(g(y));
                };
            };
        };
    };
    return _;
};
auto flip() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& a) -> boxed {
                return f(a)(b);
            };
        };
    };
    return _;
};
auto _const_() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& v) -> boxed {
            return a;
        };
    };
    return _;
};
auto applyN() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        boxed::recur go;
        boxed::recur::weak go_Weak_(go);
        go = [=](const boxed& n) -> boxed {
            boxed go = go_Weak_;
            return [=](const boxed& acc) -> boxed {
                if (unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(n)(0))) {
                    return acc;
                };
                return go(unbox<int>(n) - 1)(f(acc));
            };
        };
        return go;
    };
    return _;
};
auto applyFlipped() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return [=](const boxed& f) -> boxed {
            return f(x);
        };
    };
    return _;
};
auto apply() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return f(x);
        };
    };
    return _;
};


} // end namespace Data_Function


