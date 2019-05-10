#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Unit/Data_Unit.h"

#include "Data_Functor/Data_Functor.h"


namespace Data_Functor {

auto Functor() -> const boxed& {
    static const boxed _ = [](const boxed& map) -> boxed {
        return dict_t{
            { "map", map }
        };
    };
    return _;
};
auto map() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["map"];
    };
    return _;
};
auto mapFlipped() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& fa) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_Functor::map()(dictFunctor)(f)(fa);
            };
        };
    };
    return _;
};
auto _void_() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::map()(dictFunctor)(Data_Function::_const_()(Data_Unit::unit()));
    };
    return _;
};
auto voidLeft() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& x) -> boxed {
                return Data_Functor::map()(dictFunctor)(Data_Function::_const_()(x))(f);
            };
        };
    };
    return _;
};
auto voidRight() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& x) -> boxed {
            return Data_Functor::map()(dictFunctor)(Data_Function::_const_()(x));
        };
    };
    return _;
};
auto functorFn() -> boxed {
    return Data_Functor::Functor()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn()));
};
auto functorArray() -> boxed {
    return Data_Functor::Functor()(Data_Functor::arrayMap());
};
auto flap() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& ff) -> boxed {
            return [=](const boxed& x) -> boxed {
                return Data_Functor::map()(dictFunctor)([=](const boxed& f) -> boxed {
                    return f(x);
                })(ff);
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto arrayMap() -> const boxed& { static const boxed _ = foreign().at("arrayMap"); return _; };

} // end namespace Data_Functor


