#include "Control_Bind/Control_Bind.h"
#include "Control_Monad_Gen/Control_Monad_Gen.h"
#include "Control_Monad_Gen_Class/Control_Monad_Gen_Class.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Data_Char_Gen/Data_Char_Gen.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_String_CodeUnits/Data_String_CodeUnits.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Prelude/Prelude.h"

#include "Data_String_Gen/Data_String_Gen.h"


namespace Data_String_Gen {

auto genString() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return [=](const boxed& genChar) -> boxed {
                return Control_Monad_Gen_Class::sized()(dictMonadGen)([=](const boxed& size) -> boxed {
                    return Control_Bind::bind()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Gen_Class::chooseInt()(dictMonadGen)(1)(Data_Ord::max()(Data_Ord::ordInt())(1)(size)))([=](const boxed& v) -> boxed {
                        return Control_Monad_Gen_Class::resize()(dictMonadGen)(Data_Function::_const_()(v))(Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_String_CodeUnits::fromCharArray())(Control_Monad_Gen::unfoldable()(dictMonadRec)(dictMonadGen)(Data_Unfoldable::unfoldableArray())(genChar)));
                    });
                });
            };
        };
    };
    return _;
};
auto genUnicodeString() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return Data_String_Gen::genString()(dictMonadRec)(dictMonadGen)(Data_Char_Gen::genUnicodeChar()(dictMonadGen));
        };
    };
    return _;
};
auto genDigitString() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return Data_String_Gen::genString()(dictMonadRec)(dictMonadGen)(Data_Char_Gen::genDigitChar()(dictMonadGen));
        };
    };
    return _;
};
auto genAsciiString_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return Data_String_Gen::genString()(dictMonadRec)(dictMonadGen)(Data_Char_Gen::genAsciiChar_Prime_()(dictMonadGen));
        };
    };
    return _;
};
auto genAsciiString() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return Data_String_Gen::genString()(dictMonadRec)(dictMonadGen)(Data_Char_Gen::genAsciiChar()(dictMonadGen));
        };
    };
    return _;
};
auto genAlphaUppercaseString() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return Data_String_Gen::genString()(dictMonadRec)(dictMonadGen)(Data_Char_Gen::genAlphaUppercase()(dictMonadGen));
        };
    };
    return _;
};
auto genAlphaString() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return Data_String_Gen::genString()(dictMonadRec)(dictMonadGen)(Data_Char_Gen::genAlpha()(dictMonadGen));
        };
    };
    return _;
};
auto genAlphaLowercaseString() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return Data_String_Gen::genString()(dictMonadRec)(dictMonadGen)(Data_Char_Gen::genAlphaLowercase()(dictMonadGen));
        };
    };
    return _;
};


} // end namespace Data_String_Gen


