#include "Control_Category/Control_Category.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Functor/Data_Functor.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Reader_Class/Control_Monad_Reader_Class.h"


namespace Control_Monad_Reader_Class {

auto MonadAsk() -> const boxed& {
    static const boxed _ = [](const boxed& Monad0) -> boxed {
        return [=](const boxed& ask) -> boxed {
            return dict_t{
                { "Monad0", Monad0 },
                { "ask", ask }
            };
        };
    };
    return _;
};
auto MonadReader() -> const boxed& {
    static const boxed _ = [](const boxed& MonadAsk0) -> boxed {
        return [=](const boxed& local) -> boxed {
            return dict_t{
                { "MonadAsk0", MonadAsk0 },
                { "local", local }
            };
        };
    };
    return _;
};
auto monadAskFun() -> boxed {
    return Control_Monad_Reader_Class::MonadAsk()([=](const boxed&) -> boxed {
        return Control_Monad::monadFn();
    })(Control_Category::identity()(Control_Category::categoryFn()));
};
auto monadReaderFun() -> boxed {
    return Control_Monad_Reader_Class::MonadReader()([=](const boxed&) -> boxed {
        return Control_Monad_Reader_Class::monadAskFun();
    })(Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn()));
};
auto local() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["local"];
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
    static const boxed _ = [](const boxed& dictMonadAsk) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Functor::map()(dictMonadAsk["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(f)(Control_Monad_Reader_Class::ask()(dictMonadAsk));
        };
    };
    return _;
};


} // end namespace Control_Monad_Reader_Class


