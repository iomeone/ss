#include "Data_Show/Data_Show.h"
#include "Data_Unit/Data_Unit.h"
#include "Effect/Effect.h"

#include "Effect_Console/Effect_Console.h"


namespace Effect_Console {

auto warnShow() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Effect_Console::warn()(Data_Show::show()(dictShow)(a));
        };
    };
    return _;
};
auto logShow() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Effect_Console::log()(Data_Show::show()(dictShow)(a));
        };
    };
    return _;
};
auto infoShow() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Effect_Console::info()(Data_Show::show()(dictShow)(a));
        };
    };
    return _;
};
auto errorShow() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Effect_Console::error()(Data_Show::show()(dictShow)(a));
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto log() -> const boxed& { static const boxed _ = foreign().at("log"); return _; };
auto warn() -> const boxed& { static const boxed _ = foreign().at("warn"); return _; };
auto error() -> const boxed& { static const boxed _ = foreign().at("error"); return _; };
auto info() -> const boxed& { static const boxed _ = foreign().at("info"); return _; };
auto time() -> const boxed& { static const boxed _ = foreign().at("time"); return _; };
auto timeEnd() -> const boxed& { static const boxed _ = foreign().at("timeEnd"); return _; };

} // end namespace Effect_Console


