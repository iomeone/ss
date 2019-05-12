#include "Control_Comonad/Control_Comonad.h"
#include "Control_Comonad_Env_Trans/Control_Comonad_Env_Trans.h"
#include "Data_Tuple/Data_Tuple.h"

#include "Control_Comonad_Env_Class/Control_Comonad_Env_Class.h"


namespace Control_Comonad_Env_Class {

auto ComonadAsk() -> const boxed& {
    static const boxed _ = [](const boxed& Comonad0) -> boxed {
        return [=](const boxed& ask) -> boxed {
            return dict_t{
                { "Comonad0", Comonad0 },
                { "ask", ask }
            };
        };
    };
    return _;
};
auto ComonadEnv() -> const boxed& {
    static const boxed _ = [](const boxed& ComonadAsk0) -> boxed {
        return [=](const boxed& local) -> boxed {
            return dict_t{
                { "ComonadAsk0", ComonadAsk0 },
                { "local", local }
            };
        };
    };
    return _;
};
auto local() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["local"];
    };
    return _;
};
auto comonadAskTuple() -> boxed {
    return Control_Comonad_Env_Class::ComonadAsk()([=](const boxed&) -> boxed {
        return Data_Tuple::comonadTuple();
    })(Data_Tuple::fst());
};
auto comonadEnvTuple() -> boxed {
    return Control_Comonad_Env_Class::ComonadEnv()([=](const boxed&) -> boxed {
        return Control_Comonad_Env_Class::comonadAskTuple();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(f(v["value0"]))(v["value1"]);
        };
    });
};
auto comonadAskEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonad) -> boxed {
        return Control_Comonad_Env_Class::ComonadAsk()([=](const boxed&) -> boxed {
            return Control_Comonad_Env_Trans::comonadEnvT()(dictComonad);
        })([=](const boxed& v) -> boxed {
            return Data_Tuple::fst()(v);
        });
    };
    return _;
};
auto comonadEnvEnvT() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonad) -> boxed {
        return Control_Comonad_Env_Class::ComonadEnv()([=](const boxed&) -> boxed {
            return Control_Comonad_Env_Class::comonadAskEnvT()(dictComonad);
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Tuple::Tuple()(f(v["value0"]))(v["value1"]);
            };
        });
    };
    return _;
};
auto ask() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["ask"];
    };
    return _;
};
auto asks() -> const boxed& {
    static const boxed _ = [](const boxed& dictComonadEnv) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& x) -> boxed {
                return f(Control_Comonad_Env_Class::ask()(dictComonadEnv["ComonadAsk0"](undefined))(x));
            };
        };
    };
    return _;
};


} // end namespace Control_Comonad_Env_Class


