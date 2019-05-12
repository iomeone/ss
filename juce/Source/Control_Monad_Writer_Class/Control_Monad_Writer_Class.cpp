#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Data_Function/Data_Function.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Writer_Class/Control_Monad_Writer_Class.h"


namespace Control_Monad_Writer_Class {

auto MonadTell() -> const boxed& {
    static const boxed _ = [](const boxed& Monad0) -> boxed {
        return [=](const boxed& tell) -> boxed {
            return dict_t{
                { "Monad0", Monad0 },
                { "tell", tell }
            };
        };
    };
    return _;
};
auto MonadWriter() -> const boxed& {
    static const boxed _ = [](const boxed& MonadTell0) -> boxed {
        return [=](const boxed& listen) -> boxed {
            return [=](const boxed& pass) -> boxed {
                return dict_t{
                    { "MonadTell0", MonadTell0 },
                    { "listen", listen },
                    { "pass", pass }
                };
            };
        };
    };
    return _;
};
auto tell() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["tell"];
    };
    return _;
};
auto pass() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["pass"];
    };
    return _;
};
auto listen() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["listen"];
    };
    return _;
};
auto listens() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadWriter) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& m) -> boxed {
                return Control_Bind::bind()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Writer_Class::listen()(dictMonadWriter)(m))([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Applicative0"](undefined))(Data_Tuple::Tuple()(v["value0"])(f(v["value1"])));
                });
            };
        };
    };
    return _;
};
auto censor() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadWriter) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& m) -> boxed {
                return Control_Monad_Writer_Class::pass()(dictMonadWriter)(Control_Bind::bind()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(m)([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonadWriter["MonadTell0"](undefined)["Monad0"](undefined)["Applicative0"](undefined))(Data_Tuple::Tuple()(v)(f));
                }));
            };
        };
    };
    return _;
};


} // end namespace Control_Monad_Writer_Class


