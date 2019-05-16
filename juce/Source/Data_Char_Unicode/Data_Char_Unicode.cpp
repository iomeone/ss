#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Char/Data_Char.h"
#include "Data_Char_Unicode_Internal/Data_Char_Unicode_Internal.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Prelude/Prelude.h"

#include "Data_Char_Unicode/Data_Char_Unicode.h"


namespace Data_Char_Unicode {

auto UppercaseLetter() -> const boxed& {
    static const boxed _ = dict_t{
        { "UppercaseLetter", true }
    };
    return _;
};
auto LowercaseLetter() -> const boxed& {
    static const boxed _ = dict_t{
        { "LowercaseLetter", true }
    };
    return _;
};
auto TitlecaseLetter() -> const boxed& {
    static const boxed _ = dict_t{
        { "TitlecaseLetter", true }
    };
    return _;
};
auto ModifierLetter() -> const boxed& {
    static const boxed _ = dict_t{
        { "ModifierLetter", true }
    };
    return _;
};
auto OtherLetter() -> const boxed& {
    static const boxed _ = dict_t{
        { "OtherLetter", true }
    };
    return _;
};
auto NonSpacingMark() -> const boxed& {
    static const boxed _ = dict_t{
        { "NonSpacingMark", true }
    };
    return _;
};
auto SpacingCombiningMark() -> const boxed& {
    static const boxed _ = dict_t{
        { "SpacingCombiningMark", true }
    };
    return _;
};
auto EnclosingMark() -> const boxed& {
    static const boxed _ = dict_t{
        { "EnclosingMark", true }
    };
    return _;
};
auto DecimalNumber() -> const boxed& {
    static const boxed _ = dict_t{
        { "DecimalNumber", true }
    };
    return _;
};
auto LetterNumber() -> const boxed& {
    static const boxed _ = dict_t{
        { "LetterNumber", true }
    };
    return _;
};
auto OtherNumber() -> const boxed& {
    static const boxed _ = dict_t{
        { "OtherNumber", true }
    };
    return _;
};
auto ConnectorPunctuation() -> const boxed& {
    static const boxed _ = dict_t{
        { "ConnectorPunctuation", true }
    };
    return _;
};
auto DashPunctuation() -> const boxed& {
    static const boxed _ = dict_t{
        { "DashPunctuation", true }
    };
    return _;
};
auto OpenPunctuation() -> const boxed& {
    static const boxed _ = dict_t{
        { "OpenPunctuation", true }
    };
    return _;
};
auto ClosePunctuation() -> const boxed& {
    static const boxed _ = dict_t{
        { "ClosePunctuation", true }
    };
    return _;
};
auto InitialQuote() -> const boxed& {
    static const boxed _ = dict_t{
        { "InitialQuote", true }
    };
    return _;
};
auto FinalQuote() -> const boxed& {
    static const boxed _ = dict_t{
        { "FinalQuote", true }
    };
    return _;
};
auto OtherPunctuation() -> const boxed& {
    static const boxed _ = dict_t{
        { "OtherPunctuation", true }
    };
    return _;
};
auto MathSymbol() -> const boxed& {
    static const boxed _ = dict_t{
        { "MathSymbol", true }
    };
    return _;
};
auto CurrencySymbol() -> const boxed& {
    static const boxed _ = dict_t{
        { "CurrencySymbol", true }
    };
    return _;
};
auto ModifierSymbol() -> const boxed& {
    static const boxed _ = dict_t{
        { "ModifierSymbol", true }
    };
    return _;
};
auto OtherSymbol() -> const boxed& {
    static const boxed _ = dict_t{
        { "OtherSymbol", true }
    };
    return _;
};
auto Space() -> const boxed& {
    static const boxed _ = dict_t{
        { "Space", true }
    };
    return _;
};
auto LineSeparator() -> const boxed& {
    static const boxed _ = dict_t{
        { "LineSeparator", true }
    };
    return _;
};
auto ParagraphSeparator() -> const boxed& {
    static const boxed _ = dict_t{
        { "ParagraphSeparator", true }
    };
    return _;
};
auto Control() -> const boxed& {
    static const boxed _ = dict_t{
        { "Control", true }
    };
    return _;
};
auto Format() -> const boxed& {
    static const boxed _ = dict_t{
        { "Format", true }
    };
    return _;
};
auto Surrogate() -> const boxed& {
    static const boxed _ = dict_t{
        { "Surrogate", true }
    };
    return _;
};
auto PrivateUse() -> const boxed& {
    static const boxed _ = dict_t{
        { "PrivateUse", true }
    };
    return _;
};
auto NotAssigned() -> const boxed& {
    static const boxed _ = dict_t{
        { "NotAssigned", true }
    };
    return _;
};
auto unicodeCatToGeneralCat() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("NUMCAT_LU")) {
            return Data_Char_Unicode::UppercaseLetter();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_LL")) {
            return Data_Char_Unicode::LowercaseLetter();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_LT")) {
            return Data_Char_Unicode::TitlecaseLetter();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_LM")) {
            return Data_Char_Unicode::ModifierLetter();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_LO")) {
            return Data_Char_Unicode::OtherLetter();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_MN")) {
            return Data_Char_Unicode::NonSpacingMark();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_MC")) {
            return Data_Char_Unicode::SpacingCombiningMark();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ME")) {
            return Data_Char_Unicode::EnclosingMark();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ND")) {
            return Data_Char_Unicode::DecimalNumber();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_NL")) {
            return Data_Char_Unicode::LetterNumber();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_NO")) {
            return Data_Char_Unicode::OtherNumber();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PC")) {
            return Data_Char_Unicode::ConnectorPunctuation();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PD")) {
            return Data_Char_Unicode::DashPunctuation();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PS")) {
            return Data_Char_Unicode::OpenPunctuation();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PE")) {
            return Data_Char_Unicode::ClosePunctuation();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PI")) {
            return Data_Char_Unicode::InitialQuote();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PF")) {
            return Data_Char_Unicode::FinalQuote();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PO")) {
            return Data_Char_Unicode::OtherPunctuation();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_SM")) {
            return Data_Char_Unicode::MathSymbol();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_SC")) {
            return Data_Char_Unicode::CurrencySymbol();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_SK")) {
            return Data_Char_Unicode::ModifierSymbol();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_SO")) {
            return Data_Char_Unicode::OtherSymbol();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ZS")) {
            return Data_Char_Unicode::Space();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ZL")) {
            return Data_Char_Unicode::LineSeparator();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ZP")) {
            return Data_Char_Unicode::ParagraphSeparator();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CC")) {
            return Data_Char_Unicode::Control();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CF")) {
            return Data_Char_Unicode::Format();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CS")) {
            return Data_Char_Unicode::Surrogate();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CO")) {
            return Data_Char_Unicode::PrivateUse();
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CN")) {
            return Data_Char_Unicode::NotAssigned();
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode (line 192, column 1 - line 192, column 61): ");
    };
    return _;
};
auto toUpper() -> boxed {
    return Data_Char_Unicode::withCharCode()(Data_Char_Unicode_Internal::uTowupper());
};
auto toTitle() -> boxed {
    return Data_Char_Unicode::withCharCode()(Data_Char_Unicode_Internal::uTowtitle());
};
auto toLower() -> boxed {
    return Data_Char_Unicode::withCharCode()(Data_Char_Unicode_Internal::uTowlower());
};
auto showGeneralCategory() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("UppercaseLetter")) {
            return "UppercaseLetter";
        };
        if (unbox<dict_t>(v).contains("LowercaseLetter")) {
            return "LowercaseLetter";
        };
        if (unbox<dict_t>(v).contains("TitlecaseLetter")) {
            return "TitlecaseLetter";
        };
        if (unbox<dict_t>(v).contains("ModifierLetter")) {
            return "ModifierLetter";
        };
        if (unbox<dict_t>(v).contains("OtherLetter")) {
            return "OtherLetter";
        };
        if (unbox<dict_t>(v).contains("NonSpacingMark")) {
            return "NonSpacingMark";
        };
        if (unbox<dict_t>(v).contains("SpacingCombiningMark")) {
            return "SpacingCombiningMark";
        };
        if (unbox<dict_t>(v).contains("EnclosingMark")) {
            return "EnclosingMark";
        };
        if (unbox<dict_t>(v).contains("DecimalNumber")) {
            return "DecimalNumber";
        };
        if (unbox<dict_t>(v).contains("LetterNumber")) {
            return "LetterNumber";
        };
        if (unbox<dict_t>(v).contains("OtherNumber")) {
            return "OtherNumber";
        };
        if (unbox<dict_t>(v).contains("ConnectorPunctuation")) {
            return "ConnectorPunctuation";
        };
        if (unbox<dict_t>(v).contains("DashPunctuation")) {
            return "DashPunctuation";
        };
        if (unbox<dict_t>(v).contains("OpenPunctuation")) {
            return "OpenPunctuation";
        };
        if (unbox<dict_t>(v).contains("ClosePunctuation")) {
            return "ClosePunctuation";
        };
        if (unbox<dict_t>(v).contains("InitialQuote")) {
            return "InitialQuote";
        };
        if (unbox<dict_t>(v).contains("FinalQuote")) {
            return "FinalQuote";
        };
        if (unbox<dict_t>(v).contains("OtherPunctuation")) {
            return "OtherPunctuation";
        };
        if (unbox<dict_t>(v).contains("MathSymbol")) {
            return "MathSymbol";
        };
        if (unbox<dict_t>(v).contains("CurrencySymbol")) {
            return "CurrencySymbol";
        };
        if (unbox<dict_t>(v).contains("ModifierSymbol")) {
            return "ModifierSymbol";
        };
        if (unbox<dict_t>(v).contains("OtherSymbol")) {
            return "OtherSymbol";
        };
        if (unbox<dict_t>(v).contains("Space")) {
            return "Space";
        };
        if (unbox<dict_t>(v).contains("LineSeparator")) {
            return "LineSeparator";
        };
        if (unbox<dict_t>(v).contains("ParagraphSeparator")) {
            return "ParagraphSeparator";
        };
        if (unbox<dict_t>(v).contains("Control")) {
            return "Control";
        };
        if (unbox<dict_t>(v).contains("Format")) {
            return "Format";
        };
        if (unbox<dict_t>(v).contains("Surrogate")) {
            return "Surrogate";
        };
        if (unbox<dict_t>(v).contains("PrivateUse")) {
            return "PrivateUse";
        };
        if (unbox<dict_t>(v).contains("NotAssigned")) {
            return "NotAssigned";
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode (line 224, column 1 - line 224, column 53): ");
    });
};
auto isUpper() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Char_Unicode_Internal::uIswupper())(Data_Char::toCharCode());
};
auto isSpace() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed uc = Data_Char::toCharCode()(c);
        boxed _Local_7 = Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(uc)(823);
        if (unbox<bool>(_Local_7)) {
            return unbox<bool>(unbox<int>(uc) == 32)|| unbox<bool>(unbox<bool>(unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(uc)(9)) && unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(uc)(13)))|| unbox<bool>(unbox<int>(uc) == 160));
        };
        return Data_Char_Unicode_Internal::uIswspace()(Data_Char::toCharCode()(c));
    };
    return _;
};
auto isPrint() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Char_Unicode_Internal::uIswprint())(Data_Char::toCharCode());
};
auto isOctDigit() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed diff = unbox<int>(Data_Char::toCharCode()(c)) - unbox<int>(Data_Char::toCharCode()("0"));
        return unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(diff)(7)) && unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(diff)(0));
    };
    return _;
};
auto isLower() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Char_Unicode_Internal::uIswlower())(Data_Char::toCharCode());
};
auto isLatin1() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
		return Data_Ord::lessThanOrEq()(Data_Ord::ordChar())(c) (juce::String(CharPointer_UTF8("\xE6\xAF\x8F"))); ;// (u8"\U00006bcf");
    };
    return _;
};
auto isDigit() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed diff = unbox<int>(Data_Char::toCharCode()(c)) - unbox<int>(Data_Char::toCharCode()("0"));
        return unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(diff)(9)) && unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(diff)(0));
    };
    return _;
};
auto isHexDigit() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        return unbox<bool>(Data_Char_Unicode::isDigit()(c))|| unbox<bool>(unbox<bool>([=]() -> boxed {
    boxed diff = unbox<int>(Data_Char::toCharCode()(c)) - unbox<int>(Data_Char::toCharCode()("A"));
    return unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(diff)(5)) && unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(diff)(0));
}())|| unbox<bool>([=]() -> boxed {
    boxed diff = unbox<int>(Data_Char::toCharCode()(c)) - unbox<int>(Data_Char::toCharCode()("a"));
    return unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(diff)(5)) && unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(diff)(0));
}()));
    };
    return _;
};
auto isControl() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Char_Unicode_Internal::uIswcntrl())(Data_Char::toCharCode());
};
auto isAsciiUpper() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        return unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordChar())(c)("A")) && unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordChar())(c)("Z"));
    };
    return _;
};
auto isAsciiLower() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        return unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordChar())(c)("a")) && unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordChar())(c)("z"));
    };
    return _;
};
auto isAscii() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
		return Data_Ord::lessThan()(Data_Ord::ordChar())(c) (juce::String(CharPointer_UTF8("\xE8\x81\x99"))); // (u8"\U00008059");
    };
    return _;
};
auto isAlphaNum() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Char_Unicode_Internal::uIswalnum())(Data_Char::toCharCode());
};
auto isAlpha() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Char_Unicode_Internal::uIswalpha())(Data_Char::toCharCode());
};
auto generalCategory() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Data_Maybe::functorMaybe())(Data_Char_Unicode::unicodeCatToGeneralCat()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Char_Unicode_Internal::uGencat())(Data_Char::toCharCode()));
};
auto isLetter() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed v = Data_Char_Unicode::generalCategory()(c);
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("UppercaseLetter")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("LowercaseLetter")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("TitlecaseLetter")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("ModifierLetter")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("OtherLetter")) {
                return true;
            };
        };
        return false;
    };
    return _;
};
auto isMark() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed v = Data_Char_Unicode::generalCategory()(c);
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("NonSpacingMark")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("SpacingCombiningMark")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("EnclosingMark")) {
                return true;
            };
        };
        return false;
    };
    return _;
};
auto isNumber() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed v = Data_Char_Unicode::generalCategory()(c);
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("DecimalNumber")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("LetterNumber")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("OtherNumber")) {
                return true;
            };
        };
        return false;
    };
    return _;
};
auto isPunctuation() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed v = Data_Char_Unicode::generalCategory()(c);
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("ConnectorPunctuation")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("DashPunctuation")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("OpenPunctuation")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("ClosePunctuation")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("InitialQuote")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("FinalQuote")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("OtherPunctuation")) {
                return true;
            };
        };
        return false;
    };
    return _;
};
auto isSeparator() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed v = Data_Char_Unicode::generalCategory()(c);
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("Space")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("LineSeparator")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("ParagraphSeparator")) {
                return true;
            };
        };
        return false;
    };
    return _;
};
auto isSymbol() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed v = Data_Char_Unicode::generalCategory()(c);
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("MathSymbol")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("CurrencySymbol")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("ModifierSymbol")) {
                return true;
            };
        };
        if (unbox<dict_t>(v).contains("Just")) {
            if (unbox<dict_t>(v["value0"]).contains("OtherSymbol")) {
                return true;
            };
        };
        return false;
    };
    return _;
};
auto generalCatToUnicodeCat() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("UppercaseLetter")) {
            return Data_Char_Unicode_Internal::NUMCAT_LU();
        };
        if (unbox<dict_t>(v).contains("LowercaseLetter")) {
            return Data_Char_Unicode_Internal::NUMCAT_LL();
        };
        if (unbox<dict_t>(v).contains("TitlecaseLetter")) {
            return Data_Char_Unicode_Internal::NUMCAT_LT();
        };
        if (unbox<dict_t>(v).contains("ModifierLetter")) {
            return Data_Char_Unicode_Internal::NUMCAT_LM();
        };
        if (unbox<dict_t>(v).contains("OtherLetter")) {
            return Data_Char_Unicode_Internal::NUMCAT_LO();
        };
        if (unbox<dict_t>(v).contains("NonSpacingMark")) {
            return Data_Char_Unicode_Internal::NUMCAT_MN();
        };
        if (unbox<dict_t>(v).contains("SpacingCombiningMark")) {
            return Data_Char_Unicode_Internal::NUMCAT_MC();
        };
        if (unbox<dict_t>(v).contains("EnclosingMark")) {
            return Data_Char_Unicode_Internal::NUMCAT_ME();
        };
        if (unbox<dict_t>(v).contains("DecimalNumber")) {
            return Data_Char_Unicode_Internal::NUMCAT_ND();
        };
        if (unbox<dict_t>(v).contains("LetterNumber")) {
            return Data_Char_Unicode_Internal::NUMCAT_NL();
        };
        if (unbox<dict_t>(v).contains("OtherNumber")) {
            return Data_Char_Unicode_Internal::NUMCAT_NO();
        };
        if (unbox<dict_t>(v).contains("ConnectorPunctuation")) {
            return Data_Char_Unicode_Internal::NUMCAT_PC();
        };
        if (unbox<dict_t>(v).contains("DashPunctuation")) {
            return Data_Char_Unicode_Internal::NUMCAT_PD();
        };
        if (unbox<dict_t>(v).contains("OpenPunctuation")) {
            return Data_Char_Unicode_Internal::NUMCAT_PS();
        };
        if (unbox<dict_t>(v).contains("ClosePunctuation")) {
            return Data_Char_Unicode_Internal::NUMCAT_PE();
        };
        if (unbox<dict_t>(v).contains("InitialQuote")) {
            return Data_Char_Unicode_Internal::NUMCAT_PI();
        };
        if (unbox<dict_t>(v).contains("FinalQuote")) {
            return Data_Char_Unicode_Internal::NUMCAT_PF();
        };
        if (unbox<dict_t>(v).contains("OtherPunctuation")) {
            return Data_Char_Unicode_Internal::NUMCAT_PO();
        };
        if (unbox<dict_t>(v).contains("MathSymbol")) {
            return Data_Char_Unicode_Internal::NUMCAT_SM();
        };
        if (unbox<dict_t>(v).contains("CurrencySymbol")) {
            return Data_Char_Unicode_Internal::NUMCAT_SC();
        };
        if (unbox<dict_t>(v).contains("ModifierSymbol")) {
            return Data_Char_Unicode_Internal::NUMCAT_SK();
        };
        if (unbox<dict_t>(v).contains("OtherSymbol")) {
            return Data_Char_Unicode_Internal::NUMCAT_SO();
        };
        if (unbox<dict_t>(v).contains("Space")) {
            return Data_Char_Unicode_Internal::NUMCAT_ZS();
        };
        if (unbox<dict_t>(v).contains("LineSeparator")) {
            return Data_Char_Unicode_Internal::NUMCAT_ZL();
        };
        if (unbox<dict_t>(v).contains("ParagraphSeparator")) {
            return Data_Char_Unicode_Internal::NUMCAT_ZP();
        };
        if (unbox<dict_t>(v).contains("Control")) {
            return Data_Char_Unicode_Internal::NUMCAT_CC();
        };
        if (unbox<dict_t>(v).contains("Format")) {
            return Data_Char_Unicode_Internal::NUMCAT_CF();
        };
        if (unbox<dict_t>(v).contains("Surrogate")) {
            return Data_Char_Unicode_Internal::NUMCAT_CS();
        };
        if (unbox<dict_t>(v).contains("PrivateUse")) {
            return Data_Char_Unicode_Internal::NUMCAT_CO();
        };
        if (unbox<dict_t>(v).contains("NotAssigned")) {
            return Data_Char_Unicode_Internal::NUMCAT_CN();
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode (line 160, column 1 - line 160, column 61): ");
    };
    return _;
};
auto generalCatToInt() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("UppercaseLetter")) {
            return 1;
        };
        if (unbox<dict_t>(v).contains("LowercaseLetter")) {
            return 2;
        };
        if (unbox<dict_t>(v).contains("TitlecaseLetter")) {
            return 3;
        };
        if (unbox<dict_t>(v).contains("ModifierLetter")) {
            return 4;
        };
        if (unbox<dict_t>(v).contains("OtherLetter")) {
            return 5;
        };
        if (unbox<dict_t>(v).contains("NonSpacingMark")) {
            return 6;
        };
        if (unbox<dict_t>(v).contains("SpacingCombiningMark")) {
            return 7;
        };
        if (unbox<dict_t>(v).contains("EnclosingMark")) {
            return 8;
        };
        if (unbox<dict_t>(v).contains("DecimalNumber")) {
            return 9;
        };
        if (unbox<dict_t>(v).contains("LetterNumber")) {
            return 10;
        };
        if (unbox<dict_t>(v).contains("OtherNumber")) {
            return 11;
        };
        if (unbox<dict_t>(v).contains("ConnectorPunctuation")) {
            return 12;
        };
        if (unbox<dict_t>(v).contains("DashPunctuation")) {
            return 13;
        };
        if (unbox<dict_t>(v).contains("OpenPunctuation")) {
            return 14;
        };
        if (unbox<dict_t>(v).contains("ClosePunctuation")) {
            return 15;
        };
        if (unbox<dict_t>(v).contains("InitialQuote")) {
            return 16;
        };
        if (unbox<dict_t>(v).contains("FinalQuote")) {
            return 17;
        };
        if (unbox<dict_t>(v).contains("OtherPunctuation")) {
            return 18;
        };
        if (unbox<dict_t>(v).contains("MathSymbol")) {
            return 19;
        };
        if (unbox<dict_t>(v).contains("CurrencySymbol")) {
            return 20;
        };
        if (unbox<dict_t>(v).contains("ModifierSymbol")) {
            return 21;
        };
        if (unbox<dict_t>(v).contains("OtherSymbol")) {
            return 22;
        };
        if (unbox<dict_t>(v).contains("Space")) {
            return 23;
        };
        if (unbox<dict_t>(v).contains("LineSeparator")) {
            return 24;
        };
        if (unbox<dict_t>(v).contains("ParagraphSeparator")) {
            return 25;
        };
        if (unbox<dict_t>(v).contains("Control")) {
            return 26;
        };
        if (unbox<dict_t>(v).contains("Format")) {
            return 27;
        };
        if (unbox<dict_t>(v).contains("Surrogate")) {
            return 28;
        };
        if (unbox<dict_t>(v).contains("PrivateUse")) {
            return 29;
        };
        if (unbox<dict_t>(v).contains("NotAssigned")) {
            return 30;
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode (line 128, column 1 - line 128, column 42): ");
    };
    return _;
};
auto eqGeneralCategory() -> boxed {
    return Data_Eq::Eq()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("UppercaseLetter")) {
                if (unbox<dict_t>(v1).contains("UppercaseLetter")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("LowercaseLetter")) {
                if (unbox<dict_t>(v1).contains("LowercaseLetter")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("TitlecaseLetter")) {
                if (unbox<dict_t>(v1).contains("TitlecaseLetter")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("ModifierLetter")) {
                if (unbox<dict_t>(v1).contains("ModifierLetter")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("OtherLetter")) {
                if (unbox<dict_t>(v1).contains("OtherLetter")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("NonSpacingMark")) {
                if (unbox<dict_t>(v1).contains("NonSpacingMark")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("SpacingCombiningMark")) {
                if (unbox<dict_t>(v1).contains("SpacingCombiningMark")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("EnclosingMark")) {
                if (unbox<dict_t>(v1).contains("EnclosingMark")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("DecimalNumber")) {
                if (unbox<dict_t>(v1).contains("DecimalNumber")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("LetterNumber")) {
                if (unbox<dict_t>(v1).contains("LetterNumber")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("OtherNumber")) {
                if (unbox<dict_t>(v1).contains("OtherNumber")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("ConnectorPunctuation")) {
                if (unbox<dict_t>(v1).contains("ConnectorPunctuation")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("DashPunctuation")) {
                if (unbox<dict_t>(v1).contains("DashPunctuation")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("OpenPunctuation")) {
                if (unbox<dict_t>(v1).contains("OpenPunctuation")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("ClosePunctuation")) {
                if (unbox<dict_t>(v1).contains("ClosePunctuation")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("InitialQuote")) {
                if (unbox<dict_t>(v1).contains("InitialQuote")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("FinalQuote")) {
                if (unbox<dict_t>(v1).contains("FinalQuote")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("OtherPunctuation")) {
                if (unbox<dict_t>(v1).contains("OtherPunctuation")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("MathSymbol")) {
                if (unbox<dict_t>(v1).contains("MathSymbol")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("CurrencySymbol")) {
                if (unbox<dict_t>(v1).contains("CurrencySymbol")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("ModifierSymbol")) {
                if (unbox<dict_t>(v1).contains("ModifierSymbol")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("OtherSymbol")) {
                if (unbox<dict_t>(v1).contains("OtherSymbol")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("Space")) {
                if (unbox<dict_t>(v1).contains("Space")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("LineSeparator")) {
                if (unbox<dict_t>(v1).contains("LineSeparator")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("ParagraphSeparator")) {
                if (unbox<dict_t>(v1).contains("ParagraphSeparator")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("Control")) {
                if (unbox<dict_t>(v1).contains("Control")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("Format")) {
                if (unbox<dict_t>(v1).contains("Format")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("Surrogate")) {
                if (unbox<dict_t>(v1).contains("Surrogate")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("PrivateUse")) {
                if (unbox<dict_t>(v1).contains("PrivateUse")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("NotAssigned")) {
                if (unbox<dict_t>(v1).contains("NotAssigned")) {
                    return true;
                };
            };
            return false;
        };
    });
};
auto ordGeneralCategory() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Char_Unicode::eqGeneralCategory();
    })([=](const boxed& catA) -> boxed {
        return [=](const boxed& catB) -> boxed {
            return Data_Ord::compare()(Data_Ord::ordInt())(Data_Char_Unicode::generalCatToInt()(catA))(Data_Char_Unicode::generalCatToInt()(catB));
        };
    });
};
auto digitToInt() -> const boxed& {
    static const boxed _ = [](const boxed& c) -> boxed {
        boxed hexUpper = unbox<int>(Data_Char::toCharCode()(c)) - unbox<int>(Data_Char::toCharCode()("A"));
        boxed hexLower = unbox<int>(Data_Char::toCharCode()(c)) - unbox<int>(Data_Char::toCharCode()("a"));
        boxed dec = unbox<int>(Data_Char::toCharCode()(c)) - unbox<int>(Data_Char::toCharCode()("0"));
        boxed result = [=]() -> boxed {
            if (unbox<bool>(unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(dec)(9)) && unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(dec)(0)))) {
                return Data_Maybe::Just()(dec);
            };
            if (unbox<bool>(unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(hexLower)(5)) && unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(hexLower)(0)))) {
                return Data_Maybe::Just()(unbox<int>(hexLower) + 10);
            };
            if (unbox<bool>(unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(hexUpper)(5)) && unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(hexUpper)(0)))) {
                return Data_Maybe::Just()(unbox<int>(hexUpper) + 10);
            };
            return Data_Maybe::Nothing();
        }();
        return result;
    };
    return _;
};
auto boundedGeneralCategory() -> boxed {
    return Data_Bounded::Bounded()([=](const boxed&) -> boxed {
        return Data_Char_Unicode::ordGeneralCategory();
    })(Data_Char_Unicode::UppercaseLetter())(Data_Char_Unicode::NotAssigned());
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto withCharCode() -> const boxed& { static const boxed _ = foreign().at("withCharCode"); return _; };

} // end namespace Data_Char_Unicode


