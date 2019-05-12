#include "Control_Alt/Control_Alt.h"
#include "Data_Functor/Data_Functor.h"

#include "Control_Plus/Control_Plus.h"


namespace Control_Plus {

auto Plus() -> const boxed& {
    static const boxed _ = [](const boxed& Alt0) -> boxed {
        return [=](const boxed& empty) -> boxed {
            return dict_t{
                { "Alt0", Alt0 },
                { "empty", empty }
            };
        };
    };
    return _;
};
auto plusArray() -> boxed {
    return Control_Plus::Plus()([=](const boxed&) -> boxed {
        return Control_Alt::altArray();
    })(array_t{  });
};
auto empty() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["empty"];
    };
    return _;
};


} // end namespace Control_Plus


