#include "Control_Category/Control_Category.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"

#include "Control_Apply/Control_Apply.h"


namespace Control_Apply {

auto Apply() -> const boxed& {
    static const boxed _ = [](const boxed& Functor0) -> boxed {
        return [=](const boxed& apply) -> boxed {
            return dict_t{
                { "Functor0", Functor0 },
                { "apply", apply }
            };
        };
    };
    return _;
};
auto applyFn() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Functor::functorFn();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& g) -> boxed {
            return [=](const boxed& x) -> boxed {
                return f(x)(g(x));
            };
        };
    });
};
auto applyArray() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Functor::functorArray();
    })(Control_Apply::arrayApply());
};
auto apply() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["apply"];
    };
    return _;
};
auto applyFirst() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Control_Apply::apply()(dictApply)(Data_Functor::map()(dictApply["Functor0"](undefined))(Data_Function::_const_())(a))(b);
            };
        };
    };
    return _;
};
auto applySecond() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& b) -> boxed {
                return Control_Apply::apply()(dictApply)(Data_Functor::map()(dictApply["Functor0"](undefined))(Data_Function::_const_()(Control_Category::identity()(Control_Category::categoryFn())))(a))(b);
            };
        };
    };
    return _;
};
auto lift2() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return Control_Apply::apply()(dictApply)(Data_Functor::map()(dictApply["Functor0"](undefined))(f)(a))(b);
                };
            };
        };
    };
    return _;
};
auto lift3() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return Control_Apply::apply()(dictApply)(Control_Apply::apply()(dictApply)(Data_Functor::map()(dictApply["Functor0"](undefined))(f)(a))(b))(c);
                    };
                };
            };
        };
    };
    return _;
};
auto lift4() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return [=](const boxed& d) -> boxed {
                            return Control_Apply::apply()(dictApply)(Control_Apply::apply()(dictApply)(Control_Apply::apply()(dictApply)(Data_Functor::map()(dictApply["Functor0"](undefined))(f)(a))(b))(c))(d);
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto lift5() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return [=](const boxed& d) -> boxed {
                            return [=](const boxed& e) -> boxed {
                                return Control_Apply::apply()(dictApply)(Control_Apply::apply()(dictApply)(Control_Apply::apply()(dictApply)(Control_Apply::apply()(dictApply)(Data_Functor::map()(dictApply["Functor0"](undefined))(f)(a))(b))(c))(d))(e);
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto arrayApply() -> const boxed& { static const boxed _ = foreign().at("arrayApply"); return _; };

} // end namespace Control_Apply


