
#include "Unsafe_Coerce/Unsafe_Coerce.h"


namespace Unsafe_Coerce {




// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unsafeCoerce() -> const boxed& { static const boxed _ = foreign().at("unsafeCoerce"); return _; };

} // end namespace Unsafe_Coerce


