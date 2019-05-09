#include "Control_Category/Control_Category.h"
#include "Control_Monad/Control_Monad.h"
#include "Effect/Effect.h"

#include "Effect_Class/Effect_Class.h"


namespace Effect_Class {

auto MonadEffect() -> const boxed& {
    static const boxed _ = [](const boxed& Monad0) -> boxed {
        return [=](const boxed& liftEffect) -> boxed {
            return dict_t{
                { "Monad0", Monad0 },
                { "liftEffect", liftEffect }
            };
        };
    };
    return _;
};
auto monadEffectEffect() -> boxed {
    return Effect_Class::MonadEffect()([=](const boxed&) -> boxed {
        return Effect::monadEffect();
    })(Control_Category::identity()(Control_Category::categoryFn()));
};
auto liftEffect() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["liftEffect"];
    };
    return _;
};


} // end namespace Effect_Class


