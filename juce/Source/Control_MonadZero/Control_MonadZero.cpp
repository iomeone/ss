#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Plus/Control_Plus.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Unit/Data_Unit.h"

#include "Control_MonadZero/Control_MonadZero.h"


namespace Control_MonadZero {

auto MonadZero() -> const boxed& {
    static const boxed _ = [](const boxed& Alternative1) -> boxed {
        return [=](const boxed& Monad0) -> boxed {
            return dict_t{
                { "Alternative1", Alternative1 },
                { "Monad0", Monad0 }
            };
        };
    };
    return _;
};
auto monadZeroArray() -> boxed {
    return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
        return Control_Alternative::alternativeArray();
    })([=](const boxed&) -> boxed {
        return Control_Monad::monadArray();
    });
};
auto guard() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadZero) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<bool>(v)) {
                return Control_Applicative::pure()(dictMonadZero["Alternative1"](undefined)["Applicative0"](undefined))(Data_Unit::unit());
            };
            if (!(unbox<bool>(v))) {
                return Control_Plus::empty()(dictMonadZero["Alternative1"](undefined)["Plus1"](undefined));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Control.MonadZero (line 54, column 1 - line 54, column 52): ");
        };
    };
    return _;
};


} // end namespace Control_MonadZero


