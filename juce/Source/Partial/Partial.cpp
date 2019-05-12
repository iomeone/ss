
#include "Partial/Partial.h"


namespace Partial {

auto crash() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return Partial::crashWith()(dictPartial)("Partial.crash: partial function");
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto crashWith() -> const boxed& { static const boxed _ = foreign().at("crashWith"); return _; };

} // end namespace Partial


