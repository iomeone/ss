#include "Control_Applicative/Control_Applicative.h"
#include "Control_Monad_Gen/Control_Monad_Gen.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Enum/Data_Enum.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_NonEmpty/Data_NonEmpty.h"
#include "Data_Unfoldable1/Data_Unfoldable1.h"
#include "Prelude/Prelude.h"

#include "Data_Enum_Gen/Data_Enum_Gen.h"


namespace Data_Enum_Gen {

auto genBoundedEnum() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return [=](const boxed& dictBoundedEnum) -> boxed {
            boxed v = Data_Enum::succ()(dictBoundedEnum["Enum1"](undefined))(Data_Bounded::bottom()(dictBoundedEnum["Bounded0"](undefined)));
            if (unbox<dict_t>(v).contains("Just")) {
                boxed possibilities = Data_Enum::enumFromTo()(dictBoundedEnum["Enum1"](undefined))(Data_Unfoldable1::unfoldable1Array())(v["value0"])(Data_Bounded::top()(dictBoundedEnum["Bounded0"](undefined)));
                return Control_Monad_Gen::elements()(dictMonadGen)(Data_NonEmpty::foldable1NonEmpty()(Data_Foldable::foldableArray()))(Data_NonEmpty::NonEmpty()(Data_Bounded::bottom()(dictBoundedEnum["Bounded0"](undefined)))(possibilities));
            };
            if (unbox<dict_t>(v).contains("Nothing")) {
                return Control_Applicative::pure()(dictMonadGen["Monad0"](undefined)["Applicative0"](undefined))(Data_Bounded::bottom()(dictBoundedEnum["Bounded0"](undefined)));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Enum.Gen (line 13, column 3 - line 18, column 12): ");
        };
    };
    return _;
};


} // end namespace Data_Enum_Gen


