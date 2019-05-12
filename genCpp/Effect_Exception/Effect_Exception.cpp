#include "Control_Applicative/Control_Applicative.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Either/Data_Either.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Show/Data_Show.h"
#include "Effect/Effect.h"
#include "Prelude/Prelude.h"

#include "Effect_Exception/Effect_Exception.h"


namespace Effect_Exception {

auto _try_() -> const boxed& {
    static const boxed _ = [](const boxed& action) -> boxed {
        return Effect_Exception::catchException()(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(Effect::applicativeEffect()))(Data_Either::Left()))(Data_Functor::map()(Effect::functorEffect())(Data_Either::Right())(action));
    };
    return _;
};
auto _throw_() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Exception::throwException())(Effect_Exception::error());
};
auto stack() -> boxed {
    return Effect_Exception::stackImpl()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto showError() -> boxed {
    return Data_Show::Show()(Effect_Exception::showErrorImpl());
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto showErrorImpl() -> const boxed& { static const boxed _ = foreign().at("showErrorImpl"); return _; };
auto error() -> const boxed& { static const boxed _ = foreign().at("error"); return _; };
auto message() -> const boxed& { static const boxed _ = foreign().at("message"); return _; };
auto name() -> const boxed& { static const boxed _ = foreign().at("name"); return _; };
auto stackImpl() -> const boxed& { static const boxed _ = foreign().at("stackImpl"); return _; };
auto throwException() -> const boxed& { static const boxed _ = foreign().at("throwException"); return _; };
auto catchException() -> const boxed& { static const boxed _ = foreign().at("catchException"); return _; };

} // end namespace Effect_Exception


