#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Unit/Data_Unit.h"

#include "Control_Monad/Control_Monad.h"


namespace Control_Monad {

auto Monad() -> const boxed& {
    static const boxed _ = [](const boxed& Applicative0) -> boxed {
        return [=](const boxed& Bind1) -> boxed {
            return dict_t{
                { "Applicative0", Applicative0 },
                { "Bind1", Bind1 }
            };
        };
    };
    return _;
};
auto whenM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& mb) -> boxed {
            return [=](const boxed& m) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(mb)([=](const boxed& v) -> boxed {
                    return Control_Applicative::when()(dictMonad["Applicative0"](undefined))(v)(m);
                });
            };
        };
    };
    return _;
};
auto unlessM() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& mb) -> boxed {
            return [=](const boxed& m) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(mb)([=](const boxed& v) -> boxed {
                    return Control_Applicative::unless()(dictMonad["Applicative0"](undefined))(v)(m);
                });
            };
        };
    };
    return _;
};
auto monadFn() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Control_Applicative::applicativeFn();
    })([=](const boxed&) -> boxed {
        return Control_Bind::bindFn();
    });
};
auto monadArray() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Control_Applicative::applicativeArray();
    })([=](const boxed&) -> boxed {
        return Control_Bind::bindArray();
    });
};
auto liftM1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(a)([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(f(v));
                });
            };
        };
    };
    return _;
};
auto ap() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(f)([=](const boxed& v) -> boxed {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(a)([=](const boxed& v1) -> boxed {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(v(v1));
                    });
                });
            };
        };
    };
    return _;
};


} // end namespace Control_Monad


