#include "Data_Eq/Data_Eq.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Data_String/Data_String.h"
#include "Data_String_Common/Data_String_Common.h"
#include "Prelude/Prelude.h"

#include "Data_String_CaseInsensitive/Data_String_CaseInsensitive.h"


namespace Data_String_CaseInsensitive {

auto CaseInsensitiveString() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showCaseInsensitiveString() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(CaseInsensitiveString ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showString())(v))(")"));
    });
};
auto newtypeCaseInsensitiveString() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_String_CaseInsensitive::CaseInsensitiveString());
};
auto eqCaseInsensitiveString() -> boxed {
    return Data_Eq::Eq()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Eq::eq()(Data_Eq::eqString())(Data_String_Common::toLower()(v))(Data_String_Common::toLower()(v1));
        };
    });
};
auto ordCaseInsensitiveString() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_String_CaseInsensitive::eqCaseInsensitiveString();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Ord::compare()(Data_Ord::ordString())(Data_String_Common::toLower()(v))(Data_String_Common::toLower()(v1));
        };
    });
};


} // end namespace Data_String_CaseInsensitive


