#include "Control_Monad_Gen/Control_Monad_Gen.h"
#include "Control_Monad_Gen_Class/Control_Monad_Gen_Class.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Enum/Data_Enum.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_NonEmpty/Data_NonEmpty.h"
#include "Prelude/Prelude.h"

#include "Data_Char_Gen/Data_Char_Gen.h"


namespace Data_Char_Gen {

auto genUnicodeChar() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Enum::toEnumWithDefaults()(Data_Enum::boundedEnumChar())(Data_Bounded::bottom()(Data_Bounded::boundedChar()))(Data_Bounded::top()(Data_Bounded::boundedChar())))(Control_Monad_Gen_Class::chooseInt()(dictMonadGen)(0)(65536));
    };
    return _;
};
auto genDigitChar() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Enum::toEnumWithDefaults()(Data_Enum::boundedEnumChar())(Data_Bounded::bottom()(Data_Bounded::boundedChar()))(Data_Bounded::top()(Data_Bounded::boundedChar())))(Control_Monad_Gen_Class::chooseInt()(dictMonadGen)(48)(57));
    };
    return _;
};
auto genAsciiChar_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Enum::toEnumWithDefaults()(Data_Enum::boundedEnumChar())(Data_Bounded::bottom()(Data_Bounded::boundedChar()))(Data_Bounded::top()(Data_Bounded::boundedChar())))(Control_Monad_Gen_Class::chooseInt()(dictMonadGen)(0)(127));
    };
    return _;
};
auto genAsciiChar() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Enum::toEnumWithDefaults()(Data_Enum::boundedEnumChar())(Data_Bounded::bottom()(Data_Bounded::boundedChar()))(Data_Bounded::top()(Data_Bounded::boundedChar())))(Control_Monad_Gen_Class::chooseInt()(dictMonadGen)(32)(127));
    };
    return _;
};
auto genAlphaUppercase() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Enum::toEnumWithDefaults()(Data_Enum::boundedEnumChar())(Data_Bounded::bottom()(Data_Bounded::boundedChar()))(Data_Bounded::top()(Data_Bounded::boundedChar())))(Control_Monad_Gen_Class::chooseInt()(dictMonadGen)(65)(90));
    };
    return _;
};
auto genAlphaLowercase() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Enum::toEnumWithDefaults()(Data_Enum::boundedEnumChar())(Data_Bounded::bottom()(Data_Bounded::boundedChar()))(Data_Bounded::top()(Data_Bounded::boundedChar())))(Control_Monad_Gen_Class::chooseInt()(dictMonadGen)(97)(122));
    };
    return _;
};
auto genAlpha() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return Control_Monad_Gen::oneOf()(dictMonadGen)(Data_NonEmpty::foldable1NonEmpty()(Data_Foldable::foldableArray()))(Data_NonEmpty::NonEmpty()(Data_Char_Gen::genAlphaLowercase()(dictMonadGen))(array_t{ Data_Char_Gen::genAlphaUppercase()(dictMonadGen) }));
    };
    return _;
};


} // end namespace Data_Char_Gen


