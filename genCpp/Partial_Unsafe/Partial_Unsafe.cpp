#include "Partial/Partial.h"

#include "Partial_Unsafe/Partial_Unsafe.h"


namespace Partial_Unsafe {

auto unsafePartialBecause() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& x) -> boxed {
            return x(undefined);
        };
    };
    return _;
};
auto unsafeCrashWith() -> const boxed& {
    static const boxed _ = [](const boxed& msg) -> boxed {
        return Partial::crashWith()(undefined)(msg);
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unsafePartial() -> const boxed& { static const boxed _ = foreign().at("unsafePartial"); return _; };

} // end namespace Partial_Unsafe


