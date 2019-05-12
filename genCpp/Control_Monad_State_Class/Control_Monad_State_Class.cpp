#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_State_Class/Control_Monad_State_Class.h"


namespace Control_Monad_State_Class {

auto MonadState() -> const boxed& {
    static const boxed _ = [](const boxed& Monad0) -> boxed {
        return [=](const boxed& state) -> boxed {
            return dict_t{
                { "Monad0", Monad0 },
                { "state", state }
            };
        };
    };
    return _;
};
auto state() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["state"];
    };
    return _;
};
auto put() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadState) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Control_Monad_State_Class::state()(dictMonadState)([=](const boxed& v) -> boxed {
                return Data_Tuple::Tuple()(Data_Unit::unit())(s);
            });
        };
    };
    return _;
};
auto modify_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadState) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Monad_State_Class::state()(dictMonadState)([=](const boxed& s) -> boxed {
                return Data_Tuple::Tuple()(Data_Unit::unit())(f(s));
            });
        };
    };
    return _;
};
auto modify() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadState) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Monad_State_Class::state()(dictMonadState)([=](const boxed& s) -> boxed {
                boxed s_Prime_ = f(s);
                return Data_Tuple::Tuple()(s_Prime_)(s_Prime_);
            });
        };
    };
    return _;
};
auto gets() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadState) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Monad_State_Class::state()(dictMonadState)([=](const boxed& s) -> boxed {
                return Data_Tuple::Tuple()(f(s))(s);
            });
        };
    };
    return _;
};
auto get() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadState) -> boxed {
        return Control_Monad_State_Class::state()(dictMonadState)([=](const boxed& s) -> boxed {
            return Data_Tuple::Tuple()(s)(s);
        });
    };
    return _;
};


} // end namespace Control_Monad_State_Class


