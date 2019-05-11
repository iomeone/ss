#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Category/Control_Category.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Unit/Data_Unit.h"

#include "Control_Bind/Control_Bind.h"


namespace Control_Bind {

auto Bind() -> const boxed& {
    static const boxed _ = [](const boxed& Apply0) -> boxed {
        return [=](const boxed& bind) -> boxed {
            return dict_t{
                { "Apply0", Apply0 },
                { "bind", bind }
            };
        };
    };
    return _;
};
auto Discard() -> const boxed& {
    static const boxed _ = [](const boxed& discard) -> boxed {
        return dict_t{
            { "discard", discard }
        };
    };
    return _;
};
auto discard() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["discard"];
    };
    return _;
};
auto bindFn() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Control_Apply::applyFn();
    })([=](const boxed& m) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& x) -> boxed {
                return f(m(x))(x);
            };
        };
    });
};
auto bindArray() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Control_Apply::applyArray();
    })(Control_Bind::arrayBind());
};
auto bind() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["bind"];
    };
    return _;
};
auto bindFlipped() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return Data_Function::flip()(Control_Bind::bind()(dictBind));
    };
    return _;
};
auto composeKleisliFlipped() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Control_Bind::bindFlipped()(dictBind)(f)(g(a));
                };
            };
        };
    };
    return _;
};
auto composeKleisli() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Control_Bind::bind()(dictBind)(f(a))(g);
                };
            };
        };
    };
    return _;
};
auto discardUnit() -> boxed {
    return Control_Bind::Discard()([=](const boxed& dictBind) -> boxed {
        return Control_Bind::bind()(dictBind);
    });
};
auto ifM() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return [=](const boxed& cond) -> boxed {
            return [=](const boxed& t) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Control_Bind::bind()(dictBind)(cond)([=](const boxed& cond_Prime_) -> boxed {
                        if (unbox<bool>(cond_Prime_)) {
                            return t;
                        };
                        return f;
                    });
                };
            };
        };
    };
    return _;
};
auto join() -> const boxed& {
    static const boxed _ = [](const boxed& dictBind) -> boxed {
        return [=](const boxed& m) -> boxed {
            return Control_Bind::bind()(dictBind)(m)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto arrayBind() -> const boxed& { static const boxed _ = foreign().at("arrayBind"); return _; };

} // end namespace Control_Bind


