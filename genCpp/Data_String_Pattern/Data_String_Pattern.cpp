#include "Data_Eq/Data_Eq.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_String_Pattern/Data_String_Pattern.h"


namespace Data_String_Pattern {

auto Replacement() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto Pattern() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showReplacement() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Replacement ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showString())(v))(")"));
    });
};
auto showPattern() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Pattern ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showString())(v))(")"));
    });
};
auto newtypeReplacement() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_String_Pattern::Replacement());
};
auto newtypePattern() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Data_String_Pattern::Pattern());
};
auto eqReplacement() -> boxed {
    return Data_Eq::Eq()([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            return Data_Eq::eq()(Data_Eq::eqString())(x)(y);
        };
    });
};
auto ordReplacement() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_String_Pattern::eqReplacement();
    })([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            return Data_Ord::compare()(Data_Ord::ordString())(x)(y);
        };
    });
};
auto eqPattern() -> boxed {
    return Data_Eq::Eq()([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            return Data_Eq::eq()(Data_Eq::eqString())(x)(y);
        };
    });
};
auto ordPattern() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_String_Pattern::eqPattern();
    })([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            return Data_Ord::compare()(Data_Ord::ordString())(x)(y);
        };
    });
};


} // end namespace Data_String_Pattern


