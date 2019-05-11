#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Show/Data_Show.h"
#include "Data_Unit/Data_Unit.h"
#include "Effect_Class/Effect_Class.h"
#include "Effect_Console/Effect_Console.h"

#include "Effect_Class_Console/Effect_Class_Console.h"


namespace Effect_Class_Console {

auto warnShow() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return [=](const boxed& dictShow) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::warnShow()(dictShow));
        };
    };
    return _;
};
auto warn() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::warn());
    };
    return _;
};
auto timeEnd() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::timeEnd());
    };
    return _;
};
auto time() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::time());
    };
    return _;
};
auto logShow() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return [=](const boxed& dictShow) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::logShow()(dictShow));
        };
    };
    return _;
};
auto log() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::log());
    };
    return _;
};
auto infoShow() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return [=](const boxed& dictShow) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::infoShow()(dictShow));
        };
    };
    return _;
};
auto info() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::info());
    };
    return _;
};
auto errorShow() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return [=](const boxed& dictShow) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::errorShow()(dictShow));
        };
    };
    return _;
};
auto error() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadEffect) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Class::liftEffect()(dictMonadEffect))(Effect_Console::error());
    };
    return _;
};


} // end namespace Effect_Class_Console


