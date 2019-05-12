#include "Prelude/Prelude.h"

#include "Control_Monad_Gen_Class/Control_Monad_Gen_Class.h"


namespace Control_Monad_Gen_Class {

auto MonadGen() -> const boxed& {
    static const boxed _ = [](const boxed& Monad0) -> boxed {
        return [=](const boxed& chooseBool) -> boxed {
            return [=](const boxed& chooseFloat) -> boxed {
                return [=](const boxed& chooseInt) -> boxed {
                    return [=](const boxed& resize) -> boxed {
                        return [=](const boxed& sized) -> boxed {
                            return dict_t{
                                { "Monad0", Monad0 },
                                { "chooseBool", chooseBool },
                                { "chooseFloat", chooseFloat },
                                { "chooseInt", chooseInt },
                                { "resize", resize },
                                { "sized", sized }
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto sized() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["sized"];
    };
    return _;
};
auto resize() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["resize"];
    };
    return _;
};
auto chooseInt() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["chooseInt"];
    };
    return _;
};
auto chooseFloat() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["chooseFloat"];
    };
    return _;
};
auto chooseBool() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["chooseBool"];
    };
    return _;
};


} // end namespace Control_Monad_Gen_Class


