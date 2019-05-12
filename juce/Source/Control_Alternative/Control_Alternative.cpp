#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Plus/Control_Plus.h"
#include "Data_Functor/Data_Functor.h"

#include "Control_Alternative/Control_Alternative.h"


namespace Control_Alternative {

auto Alternative() -> const boxed& {
    static const boxed _ = [](const boxed& Applicative0) -> boxed {
        return [=](const boxed& Plus1) -> boxed {
            return dict_t{
                { "Applicative0", Applicative0 },
                { "Plus1", Plus1 }
            };
        };
    };
    return _;
};
auto alternativeArray() -> boxed {
    return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
        return Control_Applicative::applicativeArray();
    })([=](const boxed&) -> boxed {
        return Control_Plus::plusArray();
    });
};


} // end namespace Control_Alternative


