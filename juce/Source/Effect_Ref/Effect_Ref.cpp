#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Effect/Effect.h"
#include "Prelude/Prelude.h"

#include "Effect_Ref/Effect_Ref.h"


namespace Effect_Ref {

auto modify() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Effect_Ref::modify_Prime_()([=](const boxed& s) -> boxed {
            boxed s_Prime_ = f(s);
            return dict_t{
                { "state", s_Prime_ },
                { "value", s_Prime_ }
            };
        });
    };
    return _;
};
auto modify_() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& s) -> boxed {
            return Data_Functor::_void_()(Effect::functorEffect())(Effect_Ref::modify()(f)(s));
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto _new_() -> const boxed& { static const boxed _ = foreign().at("new"); return _; };
auto read() -> const boxed& { static const boxed _ = foreign().at("read"); return _; };
auto modify_Prime_() -> const boxed& { static const boxed _ = foreign().at("modify'"); return _; };
auto write() -> const boxed& { static const boxed _ = foreign().at("write"); return _; };

} // end namespace Effect_Ref


