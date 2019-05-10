#include "Effect/Effect.h"

#include "Effect_Unsafe/Effect_Unsafe.h"


namespace Effect_Unsafe {




// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unsafePerformEffect() -> const boxed& { static const boxed _ = foreign().at("unsafePerformEffect"); return _; };

} // end namespace Effect_Unsafe


