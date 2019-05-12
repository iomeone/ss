#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Either/Data_Either.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Unit/Data_Unit.h"
#include "Effect/Effect.h"
#include "Effect_Exception/Effect_Exception.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Error_Class/Control_Monad_Error_Class.h"


namespace Control_Monad_Error_Class {

auto MonadThrow() -> const boxed& {
    static const boxed _ = [](const boxed& Monad0) -> boxed {
        return [=](const boxed& throwError) -> boxed {
            return dict_t{
                { "Monad0", Monad0 },
                { "throwError", throwError }
            };
        };
    };
    return _;
};
auto MonadError() -> const boxed& {
    static const boxed _ = [](const boxed& MonadThrow0) -> boxed {
        return [=](const boxed& catchError) -> boxed {
            return dict_t{
                { "MonadThrow0", MonadThrow0 },
                { "catchError", catchError }
            };
        };
    };
    return _;
};
auto throwError() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["throwError"];
    };
    return _;
};
auto monadThrowMaybe() -> boxed {
    return Control_Monad_Error_Class::MonadThrow()([=](const boxed&) -> boxed {
        return Data_Maybe::monadMaybe();
    })(Data_Function::_const_()(Data_Maybe::Nothing()));
};
auto monadThrowEither() -> boxed {
    return Control_Monad_Error_Class::MonadThrow()([=](const boxed&) -> boxed {
        return Data_Either::monadEither();
    })(Data_Either::Left());
};
auto monadThrowEffect() -> boxed {
    return Control_Monad_Error_Class::MonadThrow()([=](const boxed&) -> boxed {
        return Effect::monadEffect();
    })(Effect_Exception::throwException());
};
auto monadErrorMaybe() -> boxed {
    return Control_Monad_Error_Class::MonadError()([=](const boxed&) -> boxed {
        return Control_Monad_Error_Class::monadThrowMaybe();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Nothing")) {
                return v1(Data_Unit::unit());
            };
            if (unbox<dict_t>(v).contains("Just")) {
                return Data_Maybe::Just()(v["value0"]);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Error.Class (line 79, column 1 - line 79, column 50): ");
        };
    });
};
auto monadErrorEither() -> boxed {
    return Control_Monad_Error_Class::MonadError()([=](const boxed&) -> boxed {
        return Control_Monad_Error_Class::monadThrowEither();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("Left")) {
                return v1(v["value0"]);
            };
            if (unbox<dict_t>(v).contains("Right")) {
                return Data_Either::Right()(v["value0"]);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Error.Class (line 72, column 1 - line 72, column 53): ");
        };
    });
};
auto monadErrorEffect() -> boxed {
    return Control_Monad_Error_Class::MonadError()([=](const boxed&) -> boxed {
        return Control_Monad_Error_Class::monadThrowEffect();
    })(Data_Function::flip()(Effect_Exception::catchException()));
};
auto catchError() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["catchError"];
    };
    return _;
};
auto catchJust() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadError) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& act) -> boxed {
                return [=](const boxed& handler) -> boxed {
                    boxed handle = [=](const boxed& e) -> boxed {
                        boxed v = p(e);
                        if (unbox<dict_t>(v).contains("Nothing")) {
                            return Control_Monad_Error_Class::throwError()(dictMonadError["MonadThrow0"](undefined))(e);
                        };
                        if (unbox<dict_t>(v).contains("Just")) {
                            return handler(v["value0"]);
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.Error.Class (line 57, column 5 - line 59, column 26): ");
                    };
                    return Control_Monad_Error_Class::catchError()(dictMonadError)(act)(handle);
                };
            };
        };
    };
    return _;
};
auto _try_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadError) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Control_Monad_Error_Class::catchError()(dictMonadError)(Data_Functor::map()(dictMonadError["MonadThrow0"](undefined)["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Right())(a))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(dictMonadError["MonadThrow0"](undefined)["Monad0"](undefined)["Applicative0"](undefined)))(Data_Either::Left()));
        };
    };
    return _;
};
auto withResource() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadError) -> boxed {
        return [=](const boxed& acquire) -> boxed {
            return [=](const boxed& release) -> boxed {
                return [=](const boxed& kleisli) -> boxed {
                    return Control_Bind::bind()(dictMonadError["MonadThrow0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(acquire)([=](const boxed& v) -> boxed {
                        return Control_Bind::bind()(dictMonadError["MonadThrow0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Error_Class::_try_()(dictMonadError)(kleisli(v)))([=](const boxed& v1) -> boxed {
                            return Control_Bind::discard()(Control_Bind::discardUnit())(dictMonadError["MonadThrow0"](undefined)["Monad0"](undefined)["Bind1"](undefined))(release(v))([=](const boxed&) -> boxed {
                                return Data_Either::either()(Control_Monad_Error_Class::throwError()(dictMonadError["MonadThrow0"](undefined)))(Control_Applicative::pure()(dictMonadError["MonadThrow0"](undefined)["Monad0"](undefined)["Applicative0"](undefined)))(v1);
                            });
                        });
                    });
                };
            };
        };
    };
    return _;
};


} // end namespace Control_Monad_Error_Class


