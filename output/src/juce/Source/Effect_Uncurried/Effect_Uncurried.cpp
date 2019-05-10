#include "Effect/Effect.h"

#include "Effect_Uncurried/Effect_Uncurried.h"


namespace Effect_Uncurried {




// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto mkEffectFn1() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn1"); return _; };
auto mkEffectFn2() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn2"); return _; };
auto mkEffectFn3() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn3"); return _; };
auto mkEffectFn4() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn4"); return _; };
auto mkEffectFn5() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn5"); return _; };
auto mkEffectFn6() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn6"); return _; };
auto mkEffectFn7() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn7"); return _; };
auto mkEffectFn8() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn8"); return _; };
auto mkEffectFn9() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn9"); return _; };
auto mkEffectFn10() -> const boxed& { static const boxed _ = foreign().at("mkEffectFn10"); return _; };
auto runEffectFn1() -> const boxed& { static const boxed _ = foreign().at("runEffectFn1"); return _; };
auto runEffectFn2() -> const boxed& { static const boxed _ = foreign().at("runEffectFn2"); return _; };
auto runEffectFn3() -> const boxed& { static const boxed _ = foreign().at("runEffectFn3"); return _; };
auto runEffectFn4() -> const boxed& { static const boxed _ = foreign().at("runEffectFn4"); return _; };
auto runEffectFn5() -> const boxed& { static const boxed _ = foreign().at("runEffectFn5"); return _; };
auto runEffectFn6() -> const boxed& { static const boxed _ = foreign().at("runEffectFn6"); return _; };
auto runEffectFn7() -> const boxed& { static const boxed _ = foreign().at("runEffectFn7"); return _; };
auto runEffectFn8() -> const boxed& { static const boxed _ = foreign().at("runEffectFn8"); return _; };
auto runEffectFn9() -> const boxed& { static const boxed _ = foreign().at("runEffectFn9"); return _; };
auto runEffectFn10() -> const boxed& { static const boxed _ = foreign().at("runEffectFn10"); return _; };

} // end namespace Effect_Uncurried


