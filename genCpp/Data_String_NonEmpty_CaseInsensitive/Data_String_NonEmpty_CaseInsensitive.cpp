#include "Data_Eq/Data_Eq.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Data_String_NonEmpty/Data_String_NonEmpty.h"
#include "Data_String_NonEmpty_Internal/Data_String_NonEmpty_Internal.h"
#include "Prelude/Prelude.h"

#include "Data_String_NonEmpty_CaseInsensitive/Data_String_NonEmpty_CaseInsensitive.h"


namespace Data_String_NonEmpty_CaseInsensitive {

auto CaseInsensitiveNonEmptyString() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showCaseInsensitiveNonEmptyString() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(CaseInsensitiveNonEmptyString ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_String_NonEmpty_Internal::showNonEmptyString())(v))(")"));
    });
};
auto newtypeCaseInsensitiveNonEmptyString() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_String_NonEmpty_CaseInsensitive::CaseInsensitiveNonEmptyString());
};
auto eqCaseInsensitiveNonEmptyString() -> boxed {
    return Data_Eq::Eq()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Eq::eq()(Data_String_NonEmpty_Internal::eqNonEmptyString())(Data_String_NonEmpty_Internal::toLower()(v))(Data_String_NonEmpty_Internal::toLower()(v1));
        };
    });
};
auto ordCaseInsensitiveNonEmptyString() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_String_NonEmpty_CaseInsensitive::eqCaseInsensitiveNonEmptyString();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Ord::compare()(Data_String_NonEmpty_Internal::ordNonEmptyString())(Data_String_NonEmpty_Internal::toLower()(v))(Data_String_NonEmpty_Internal::toLower()(v1));
        };
    });
};


} // end namespace Data_String_NonEmpty_CaseInsensitive


