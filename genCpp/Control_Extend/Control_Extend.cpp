#include "Control_Category/Control_Category.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Semigroup/Data_Semigroup.h"

#include "Control_Extend/Control_Extend.h"


namespace Control_Extend {

auto Extend() -> const boxed& {
    static const boxed _ = [](const boxed& Functor0) -> boxed {
        return [=](const boxed& extend) -> boxed {
            return dict_t{
                { "Functor0", Functor0 },
                { "extend", extend }
            };
        };
    };
    return _;
};
auto extendFn() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Control_Extend::Extend()([=](const boxed&) -> boxed {
            return Data_Functor::functorFn();
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& w) -> boxed {
                    return f([=](const boxed& w_Prime_) -> boxed {
                        return g(Data_Semigroup::append()(dictSemigroup)(w)(w_Prime_));
                    });
                };
            };
        });
    };
    return _;
};
auto extendArray() -> boxed {
    return Control_Extend::Extend()([=](const boxed&) -> boxed {
        return Data_Functor::functorArray();
    })(Control_Extend::arrayExtend());
};
auto extend() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["extend"];
    };
    return _;
};
auto extendFlipped() -> const boxed& {
    static const boxed _ = [](const boxed& dictExtend) -> boxed {
        return [=](const boxed& w) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Control_Extend::extend()(dictExtend)(f)(w);
            };
        };
    };
    return _;
};
auto duplicate() -> const boxed& {
    static const boxed _ = [](const boxed& dictExtend) -> boxed {
        return Control_Extend::extend()(dictExtend)(Control_Category::identity()(Control_Category::categoryFn()));
    };
    return _;
};
auto composeCoKleisliFlipped() -> const boxed& {
    static const boxed _ = [](const boxed& dictExtend) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& w) -> boxed {
                    return f(Control_Extend::extend()(dictExtend)(g)(w));
                };
            };
        };
    };
    return _;
};
auto composeCoKleisli() -> const boxed& {
    static const boxed _ = [](const boxed& dictExtend) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& w) -> boxed {
                    return g(Control_Extend::extend()(dictExtend)(f)(w));
                };
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto arrayExtend() -> const boxed& { static const boxed _ = foreign().at("arrayExtend"); return _; };

} // end namespace Control_Extend


