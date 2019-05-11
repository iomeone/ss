#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Prelude/Prelude.h"

#include "Effect/Effect.h"


namespace Effect {

auto monadEffect() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Effect::applicativeEffect();
    })([=](const boxed&) -> boxed {
        return Effect::bindEffect();
    });
};
auto bindEffect() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Effect::applyEffect();
    })(Effect::bindE());
};
auto applyEffect() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Effect::functorEffect();
    })(Control_Monad::ap()(Effect::monadEffect()));
};
auto applicativeEffect() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Effect::applyEffect();
    })(Effect::pureE());
};
auto functorEffect() -> boxed {
    return Data_Functor::Functor()(Control_Applicative::liftA1()(Effect::applicativeEffect()));
};
auto semigroupEffect() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup::Semigroup()(Control_Apply::lift2()(Effect::applyEffect())(Data_Semigroup::append()(dictSemigroup)));
    };
    return _;
};
auto monoidEffect() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Effect::semigroupEffect()(dictMonoid["Semigroup0"](undefined));
        })(Effect::pureE()(Data_Monoid::mempty()(dictMonoid)));
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto pureE() -> const boxed& { static const boxed _ = foreign().at("pureE"); return _; };
auto bindE() -> const boxed& { static const boxed _ = foreign().at("bindE"); return _; };
auto untilE() -> const boxed& { static const boxed _ = foreign().at("untilE"); return _; };
auto whileE() -> const boxed& { static const boxed _ = foreign().at("whileE"); return _; };
auto forE() -> const boxed& { static const boxed _ = foreign().at("forE"); return _; };
auto foreachE() -> const boxed& { static const boxed _ = foreign().at("foreachE"); return _; };

} // end namespace Effect


