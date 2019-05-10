#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Unit/Data_Unit.h"

#include "Data_Bounded/Data_Bounded.h"


namespace Data_Bounded {

auto Bounded() -> const boxed& {
    static const boxed _ = [](const boxed& Ord0) -> boxed {
        return [=](const boxed& bottom) -> boxed {
            return [=](const boxed& top) -> boxed {
                return dict_t{
                    { "Ord0", Ord0 },
                    { "bottom", bottom },
                    { "top", top }
                };
            };
        };
    };
    return _;
};
auto top() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["top"];
    };
    return _;
};
auto boundedUnit() -> boxed {
    return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
        return Data_Ord::ordUnit();
    })(Data_Unit::unit())(Data_Unit::unit());
};
auto boundedOrdering() -> boxed {
    return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
        return Data_Ord::ordOrdering();
    })(Data_Ordering::LT())(Data_Ordering::GT());
};
auto boundedNumber() -> boxed {
    return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
        return Data_Ord::ordNumber();
    })(Data_Bounded::bottomNumber())(Data_Bounded::topNumber());
};
auto boundedInt() -> boxed {
    return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
        return Data_Ord::ordInt();
    })(Data_Bounded::bottomInt())(Data_Bounded::topInt());
};
auto boundedChar() -> boxed {
    return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
        return Data_Ord::ordChar();
    })(Data_Bounded::bottomChar())(Data_Bounded::topChar());
};
auto boundedBoolean() -> boxed {
    return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
        return Data_Ord::ordBoolean();
    })(false)(true);
};
auto bottom() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["bottom"];
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto topInt() -> const boxed& { static const boxed _ = foreign().at("topInt"); return _; };
auto bottomInt() -> const boxed& { static const boxed _ = foreign().at("bottomInt"); return _; };
auto topChar() -> const boxed& { static const boxed _ = foreign().at("topChar"); return _; };
auto bottomChar() -> const boxed& { static const boxed _ = foreign().at("bottomChar"); return _; };
auto topNumber() -> const boxed& { static const boxed _ = foreign().at("topNumber"); return _; };
auto bottomNumber() -> const boxed& { static const boxed _ = foreign().at("bottomNumber"); return _; };

} // end namespace Data_Bounded


