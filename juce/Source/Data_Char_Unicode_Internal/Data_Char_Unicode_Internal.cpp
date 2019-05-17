#include "Data_Array/Data_Array.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Int/Data_Int.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"

#include "Data_Char_Unicode_Internal/Data_Char_Unicode_Internal.h"


namespace Data_Char_Unicode_Internal {

auto NUMCAT_LU() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_LU", true }
    };
    return _;
};
auto NUMCAT_LL() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_LL", true }
    };
    return _;
};
auto NUMCAT_LT() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_LT", true }
    };
    return _;
};
auto NUMCAT_LM() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_LM", true }
    };
    return _;
};
auto NUMCAT_LO() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_LO", true }
    };
    return _;
};
auto NUMCAT_MN() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_MN", true }
    };
    return _;
};
auto NUMCAT_MC() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_MC", true }
    };
    return _;
};
auto NUMCAT_ME() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_ME", true }
    };
    return _;
};
auto NUMCAT_ND() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_ND", true }
    };
    return _;
};
auto NUMCAT_NL() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_NL", true }
    };
    return _;
};
auto NUMCAT_NO() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_NO", true }
    };
    return _;
};
auto NUMCAT_PC() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_PC", true }
    };
    return _;
};
auto NUMCAT_PD() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_PD", true }
    };
    return _;
};
auto NUMCAT_PS() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_PS", true }
    };
    return _;
};
auto NUMCAT_PE() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_PE", true }
    };
    return _;
};
auto NUMCAT_PI() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_PI", true }
    };
    return _;
};
auto NUMCAT_PF() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_PF", true }
    };
    return _;
};
auto NUMCAT_PO() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_PO", true }
    };
    return _;
};
auto NUMCAT_SM() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_SM", true }
    };
    return _;
};
auto NUMCAT_SC() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_SC", true }
    };
    return _;
};
auto NUMCAT_SK() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_SK", true }
    };
    return _;
};
auto NUMCAT_SO() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_SO", true }
    };
    return _;
};
auto NUMCAT_ZS() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_ZS", true }
    };
    return _;
};
auto NUMCAT_ZL() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_ZL", true }
    };
    return _;
};
auto NUMCAT_ZP() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_ZP", true }
    };
    return _;
};
auto NUMCAT_CC() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_CC", true }
    };
    return _;
};
auto NUMCAT_CF() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_CF", true }
    };
    return _;
};
auto NUMCAT_CS() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_CS", true }
    };
    return _;
};
auto NUMCAT_CO() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_CO", true }
    };
    return _;
};
auto NUMCAT_CN() -> const boxed& {
    static const boxed _ = dict_t{
        { "NUMCAT_CN", true }
    };
    return _;
};
auto ConversionRule() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto CharBlock() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showUnicodeCategory() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("NUMCAT_LU")) {
            return "NUMCAT_LU";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_LL")) {
            return "NUMCAT_LL";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_LT")) {
            return "NUMCAT_LT";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_LM")) {
            return "NUMCAT_LM";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_LO")) {
            return "NUMCAT_LO";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_MN")) {
            return "NUMCAT_MN";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_MC")) {
            return "NUMCAT_MC";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ME")) {
            return "NUMCAT_ME";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ND")) {
            return "NUMCAT_ND";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_NL")) {
            return "NUMCAT_NL";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_NO")) {
            return "NUMCAT_NO";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PC")) {
            return "NUMCAT_PC";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PD")) {
            return "NUMCAT_PD";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PS")) {
            return "NUMCAT_PS";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PE")) {
            return "NUMCAT_PE";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PI")) {
            return "NUMCAT_PI";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PF")) {
            return "NUMCAT_PF";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_PO")) {
            return "NUMCAT_PO";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_SM")) {
            return "NUMCAT_SM";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_SC")) {
            return "NUMCAT_SC";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_SK")) {
            return "NUMCAT_SK";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_SO")) {
            return "NUMCAT_SO";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ZS")) {
            return "NUMCAT_ZS";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ZL")) {
            return "NUMCAT_ZL";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_ZP")) {
            return "NUMCAT_ZP";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CC")) {
            return "NUMCAT_CC";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CF")) {
            return "NUMCAT_CF";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CS")) {
            return "NUMCAT_CS";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CO")) {
            return "NUMCAT_CO";
        };
        if (unbox<dict_t>(v).contains("NUMCAT_CN")) {
            return "NUMCAT_CN";
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode.Internal (line 49, column 1 - line 49, column 53): ");
    });
};
auto showConversionRule() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("ConversionRule { category: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v["category"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(", unicodeCat: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Char_Unicode_Internal::showUnicodeCategory())(v["unicodeCat"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(", possible: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v["possible"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(", updist: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v["updist"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(", lowdist: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v["lowdist"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(", titledist: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v["titledist"]))(" }"))))))))))));
    });
};
auto showCharBlock() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("CharBlock { start: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v["start"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(", length: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v["length"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(", convRule: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Char_Unicode_Internal::showConversionRule())(v["convRule"]))(" }"))))));
    });
};
auto numSpaceBlocks() -> const boxed& {
    static const boxed _ = 8;
    return _;
};
auto numRules() -> const boxed& {
    static const boxed _ = 167;
    return _;
};
auto numLat1Blocks() -> const boxed& {
    static const boxed _ = 63;
    return _;
};
auto numConvBlocks() -> const boxed& {
    static const boxed _ = 1230;
    return _;
};
auto numBlocks() -> const boxed& {
    static const boxed _ = 2783;
    return _;
};
auto maxUniChar() -> const boxed& {
    static const boxed _ = 1114109;
    return _;
};
auto gencatZS() -> const boxed& {
    static const boxed _ = 2;
    return _;
};
auto rule1() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatZS() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_ZS() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto spacechars() -> const boxed& {
    static const boxed _ = array_t{ dict_t{
        { "start", 32 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 160 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 5760 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 6158 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 8192 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 8239 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 8287 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 12288 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    } };
    return _;
};
auto gencatZP() -> const boxed& {
    static const boxed _ = 67108864;
    return _;
};
auto rule140() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatZP() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_ZP() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatZL() -> const boxed& {
    static const boxed _ = 33554432;
    return _;
};
auto rule139() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatZL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_ZL() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatSO() -> const boxed& {
    static const boxed _ = 8192;
    return _;
};
auto rule13() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatSO() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_SO() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto rule148() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatSO() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_SO() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 26 },
        { "titledist", 0 }
    };
    return _;
};
auto rule149() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatSO() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_SO() },
        { "possible", 1 },
        { "updist", -26 },
        { "lowdist", 0 },
        { "titledist", -26 }
    };
    return _;
};
auto gencatSM() -> const boxed& {
    static const boxed _ = 64;
    return _;
};
auto rule6() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatSM() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_SM() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatSK() -> const boxed& {
    static const boxed _ = 1024;
    return _;
};
auto rule10() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatSK() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_SK() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatSC() -> const boxed& {
    static const boxed _ = 8;
    return _;
};
auto rule3() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatSC() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_SC() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatPS() -> const boxed& {
    static const boxed _ = 16;
    return _;
};
auto rule4() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatPS() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_PS() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatPO() -> const boxed& {
    static const boxed _ = 4;
    return _;
};
auto rule2() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatPO() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_PO() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatPI() -> const boxed& {
    static const boxed _ = 16384;
    return _;
};
auto rule15() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatPI() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_PI() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatPF() -> const boxed& {
    static const boxed _ = 131072;
    return _;
};
auto rule19() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatPF() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_PF() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatPE() -> const boxed& {
    static const boxed _ = 32;
    return _;
};
auto rule5() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatPE() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_PE() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatPD() -> const boxed& {
    static const boxed _ = 128;
    return _;
};
auto rule7() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatPD() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_PD() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatPC() -> const boxed& {
    static const boxed _ = 2048;
    return _;
};
auto rule11() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatPC() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_PC() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatNO() -> const boxed& {
    static const boxed _ = 65536;
    return _;
};
auto rule17() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatNO() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_NO() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatNL() -> const boxed& {
    static const boxed _ = 16777216;
    return _;
};
auto rule116() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatNL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_NL() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto rule146() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatNL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_NL() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 16 },
        { "titledist", 0 }
    };
    return _;
};
auto rule147() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatNL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_NL() },
        { "possible", 1 },
        { "updist", -16 },
        { "lowdist", 0 },
        { "titledist", -16 }
    };
    return _;
};
auto gencatND() -> const boxed& {
    static const boxed _ = 256;
    return _;
};
auto rule8() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatND() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_ND() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatMN() -> const boxed& {
    static const boxed _ = 2097152;
    return _;
};
auto rule84() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatMN() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_MN() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto rule85() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatMN() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_MN() },
        { "possible", 1 },
        { "updist", 84 },
        { "lowdist", 0 },
        { "titledist", 84 }
    };
    return _;
};
auto gencatME() -> const boxed& {
    static const boxed _ = 4194304;
    return _;
};
auto rule109() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatME() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_ME() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatMC() -> const boxed& {
    static const boxed _ = 8388608;
    return _;
};
auto rule114() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatMC() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_MC() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatLU() -> const boxed& {
    static const boxed _ = 512;
    return _;
};
auto nullrule() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_CN() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto rule105() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -60 },
        { "titledist", 0 }
    };
    return _;
};
auto rule107() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -7 },
        { "titledist", 0 }
    };
    return _;
};
auto rule108() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 80 },
        { "titledist", 0 }
    };
    return _;
};
auto rule110() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 15 },
        { "titledist", 0 }
    };
    return _;
};
auto rule112() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 48 },
        { "titledist", 0 }
    };
    return _;
};
auto rule115() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 7264 },
        { "titledist", 0 }
    };
    return _;
};
auto rule120() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -7615 },
        { "titledist", 0 }
    };
    return _;
};
auto rule122() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -8 },
        { "titledist", 0 }
    };
    return _;
};
auto rule131() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -74 },
        { "titledist", 0 }
    };
    return _;
};
auto rule134() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -86 },
        { "titledist", 0 }
    };
    return _;
};
auto rule135() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -100 },
        { "titledist", 0 }
    };
    return _;
};
auto rule136() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -112 },
        { "titledist", 0 }
    };
    return _;
};
auto rule137() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -128 },
        { "titledist", 0 }
    };
    return _;
};
auto rule138() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -126 },
        { "titledist", 0 }
    };
    return _;
};
auto rule141() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -7517 },
        { "titledist", 0 }
    };
    return _;
};
auto rule142() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -8383 },
        { "titledist", 0 }
    };
    return _;
};
auto rule143() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -8262 },
        { "titledist", 0 }
    };
    return _;
};
auto rule144() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 28 },
        { "titledist", 0 }
    };
    return _;
};
auto rule150() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -10743 },
        { "titledist", 0 }
    };
    return _;
};
auto rule151() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -3814 },
        { "titledist", 0 }
    };
    return _;
};
auto rule152() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -10727 },
        { "titledist", 0 }
    };
    return _;
};
auto rule155() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -10780 },
        { "titledist", 0 }
    };
    return _;
};
auto rule156() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -10749 },
        { "titledist", 0 }
    };
    return _;
};
auto rule157() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -10783 },
        { "titledist", 0 }
    };
    return _;
};
auto rule158() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -10782 },
        { "titledist", 0 }
    };
    return _;
};
auto rule159() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -10815 },
        { "titledist", 0 }
    };
    return _;
};
auto rule161() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -35332 },
        { "titledist", 0 }
    };
    return _;
};
auto rule162() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -42280 },
        { "titledist", 0 }
    };
    return _;
};
auto rule165() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 40 },
        { "titledist", 0 }
    };
    return _;
};
auto rule21() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 1 },
        { "titledist", 0 }
    };
    return _;
};
auto rule23() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -199 },
        { "titledist", 0 }
    };
    return _;
};
auto rule25() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -121 },
        { "titledist", 0 }
    };
    return _;
};
auto rule28() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 210 },
        { "titledist", 0 }
    };
    return _;
};
auto rule29() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 206 },
        { "titledist", 0 }
    };
    return _;
};
auto rule30() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 205 },
        { "titledist", 0 }
    };
    return _;
};
auto rule31() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 79 },
        { "titledist", 0 }
    };
    return _;
};
auto rule32() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 202 },
        { "titledist", 0 }
    };
    return _;
};
auto rule33() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 203 },
        { "titledist", 0 }
    };
    return _;
};
auto rule34() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 207 },
        { "titledist", 0 }
    };
    return _;
};
auto rule36() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 211 },
        { "titledist", 0 }
    };
    return _;
};
auto rule37() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 209 },
        { "titledist", 0 }
    };
    return _;
};
auto rule39() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 213 },
        { "titledist", 0 }
    };
    return _;
};
auto rule41() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 214 },
        { "titledist", 0 }
    };
    return _;
};
auto rule42() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 218 },
        { "titledist", 0 }
    };
    return _;
};
auto rule43() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 217 },
        { "titledist", 0 }
    };
    return _;
};
auto rule44() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 219 },
        { "titledist", 0 }
    };
    return _;
};
auto rule47() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 2 },
        { "titledist", 1 }
    };
    return _;
};
auto rule51() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -97 },
        { "titledist", 0 }
    };
    return _;
};
auto rule52() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -56 },
        { "titledist", 0 }
    };
    return _;
};
auto rule53() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -130 },
        { "titledist", 0 }
    };
    return _;
};
auto rule54() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 10795 },
        { "titledist", 0 }
    };
    return _;
};
auto rule55() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -163 },
        { "titledist", 0 }
    };
    return _;
};
auto rule56() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 10792 },
        { "titledist", 0 }
    };
    return _;
};
auto rule58() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -195 },
        { "titledist", 0 }
    };
    return _;
};
auto rule59() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 69 },
        { "titledist", 0 }
    };
    return _;
};
auto rule60() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 71 },
        { "titledist", 0 }
    };
    return _;
};
auto rule86() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 38 },
        { "titledist", 0 }
    };
    return _;
};
auto rule87() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 37 },
        { "titledist", 0 }
    };
    return _;
};
auto rule88() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 64 },
        { "titledist", 0 }
    };
    return _;
};
auto rule89() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 63 },
        { "titledist", 0 }
    };
    return _;
};
auto rule9() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 32 },
        { "titledist", 0 }
    };
    return _;
};
auto rule95() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", 8 },
        { "titledist", 0 }
    };
    return _;
};
auto rule98() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLU() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LU() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatLT() -> const boxed& {
    static const boxed _ = 524288;
    return _;
};
auto rule129() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLT() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LT() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -8 },
        { "titledist", 0 }
    };
    return _;
};
auto rule132() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLT() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LT() },
        { "possible", 1 },
        { "updist", 0 },
        { "lowdist", -9 },
        { "titledist", 0 }
    };
    return _;
};
auto rule48() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLT() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LT() },
        { "possible", 1 },
        { "updist", -1 },
        { "lowdist", 1 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatLO() -> const boxed& {
    static const boxed _ = 262144;
    return _;
};
auto rule45() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLO() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LO() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatLM() -> const boxed& {
    static const boxed _ = 1048576;
    return _;
};
auto rule83() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLM() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LM() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatLL() -> const boxed& {
    static const boxed _ = 4096;
    return _;
};
auto rule100() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -54 },
        { "lowdist", 0 },
        { "titledist", -54 }
    };
    return _;
};
auto rule101() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -8 },
        { "lowdist", 0 },
        { "titledist", -8 }
    };
    return _;
};
auto rule102() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -86 },
        { "lowdist", 0 },
        { "titledist", -86 }
    };
    return _;
};
auto rule103() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -80 },
        { "lowdist", 0 },
        { "titledist", -80 }
    };
    return _;
};
auto rule104() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 7 },
        { "lowdist", 0 },
        { "titledist", 7 }
    };
    return _;
};
auto rule106() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -96 },
        { "lowdist", 0 },
        { "titledist", -96 }
    };
    return _;
};
auto rule111() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -15 },
        { "lowdist", 0 },
        { "titledist", -15 }
    };
    return _;
};
auto rule113() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -48 },
        { "lowdist", 0 },
        { "titledist", -48 }
    };
    return _;
};
auto rule117() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 35332 },
        { "lowdist", 0 },
        { "titledist", 35332 }
    };
    return _;
};
auto rule118() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 3814 },
        { "lowdist", 0 },
        { "titledist", 3814 }
    };
    return _;
};
auto rule119() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -59 },
        { "lowdist", 0 },
        { "titledist", -59 }
    };
    return _;
};
auto rule12() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -32 },
        { "lowdist", 0 },
        { "titledist", -32 }
    };
    return _;
};
auto rule121() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 8 },
        { "lowdist", 0 },
        { "titledist", 8 }
    };
    return _;
};
auto rule123() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 74 },
        { "lowdist", 0 },
        { "titledist", 74 }
    };
    return _;
};
auto rule124() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 86 },
        { "lowdist", 0 },
        { "titledist", 86 }
    };
    return _;
};
auto rule125() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 100 },
        { "lowdist", 0 },
        { "titledist", 100 }
    };
    return _;
};
auto rule126() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 128 },
        { "lowdist", 0 },
        { "titledist", 128 }
    };
    return _;
};
auto rule127() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 112 },
        { "lowdist", 0 },
        { "titledist", 112 }
    };
    return _;
};
auto rule128() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 126 },
        { "lowdist", 0 },
        { "titledist", 126 }
    };
    return _;
};
auto rule130() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 9 },
        { "lowdist", 0 },
        { "titledist", 9 }
    };
    return _;
};
auto rule133() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -7205 },
        { "lowdist", 0 },
        { "titledist", -7205 }
    };
    return _;
};
auto rule14() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto rule145() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -28 },
        { "lowdist", 0 },
        { "titledist", -28 }
    };
    return _;
};
auto rule153() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -10795 },
        { "lowdist", 0 },
        { "titledist", -10795 }
    };
    return _;
};
auto rule154() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -10792 },
        { "lowdist", 0 },
        { "titledist", -10792 }
    };
    return _;
};
auto rule160() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -7264 },
        { "lowdist", 0 },
        { "titledist", -7264 }
    };
    return _;
};
auto rule166() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -40 },
        { "lowdist", 0 },
        { "titledist", -40 }
    };
    return _;
};
auto rule18() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 743 },
        { "lowdist", 0 },
        { "titledist", 743 }
    };
    return _;
};
auto rule20() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 121 },
        { "lowdist", 0 },
        { "titledist", 121 }
    };
    return _;
};
auto rule22() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -1 },
        { "lowdist", 0 },
        { "titledist", -1 }
    };
    return _;
};
auto rule24() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -232 },
        { "lowdist", 0 },
        { "titledist", -232 }
    };
    return _;
};
auto rule26() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -300 },
        { "lowdist", 0 },
        { "titledist", -300 }
    };
    return _;
};
auto rule27() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 195 },
        { "lowdist", 0 },
        { "titledist", 195 }
    };
    return _;
};
auto rule35() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 97 },
        { "lowdist", 0 },
        { "titledist", 97 }
    };
    return _;
};
auto rule38() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 163 },
        { "lowdist", 0 },
        { "titledist", 163 }
    };
    return _;
};
auto rule40() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 130 },
        { "lowdist", 0 },
        { "titledist", 130 }
    };
    return _;
};
auto rule46() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 56 },
        { "lowdist", 0 },
        { "titledist", 56 }
    };
    return _;
};
auto rule49() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -2 },
        { "lowdist", 0 },
        { "titledist", -1 }
    };
    return _;
};
auto rule50() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -79 },
        { "lowdist", 0 },
        { "titledist", -79 }
    };
    return _;
};
auto rule57() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 10815 },
        { "lowdist", 0 },
        { "titledist", 10815 }
    };
    return _;
};
auto rule61() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 10783 },
        { "lowdist", 0 },
        { "titledist", 10783 }
    };
    return _;
};
auto rule62() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 10780 },
        { "lowdist", 0 },
        { "titledist", 10780 }
    };
    return _;
};
auto rule63() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 10782 },
        { "lowdist", 0 },
        { "titledist", 10782 }
    };
    return _;
};
auto rule64() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -210 },
        { "lowdist", 0 },
        { "titledist", -210 }
    };
    return _;
};
auto rule65() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -206 },
        { "lowdist", 0 },
        { "titledist", -206 }
    };
    return _;
};
auto rule66() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -205 },
        { "lowdist", 0 },
        { "titledist", -205 }
    };
    return _;
};
auto rule67() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -202 },
        { "lowdist", 0 },
        { "titledist", -202 }
    };
    return _;
};
auto rule68() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -203 },
        { "lowdist", 0 },
        { "titledist", -203 }
    };
    return _;
};
auto rule69() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -207 },
        { "lowdist", 0 },
        { "titledist", -207 }
    };
    return _;
};
auto rule70() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 42280 },
        { "lowdist", 0 },
        { "titledist", 42280 }
    };
    return _;
};
auto rule71() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -209 },
        { "lowdist", 0 },
        { "titledist", -209 }
    };
    return _;
};
auto rule72() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -211 },
        { "lowdist", 0 },
        { "titledist", -211 }
    };
    return _;
};
auto rule73() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 10743 },
        { "lowdist", 0 },
        { "titledist", 10743 }
    };
    return _;
};
auto rule74() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 10749 },
        { "lowdist", 0 },
        { "titledist", 10749 }
    };
    return _;
};
auto rule75() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -213 },
        { "lowdist", 0 },
        { "titledist", -213 }
    };
    return _;
};
auto rule76() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -214 },
        { "lowdist", 0 },
        { "titledist", -214 }
    };
    return _;
};
auto rule77() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", 10727 },
        { "lowdist", 0 },
        { "titledist", 10727 }
    };
    return _;
};
auto rule78() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -218 },
        { "lowdist", 0 },
        { "titledist", -218 }
    };
    return _;
};
auto rule79() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -69 },
        { "lowdist", 0 },
        { "titledist", -69 }
    };
    return _;
};
auto rule80() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -217 },
        { "lowdist", 0 },
        { "titledist", -217 }
    };
    return _;
};
auto rule81() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -71 },
        { "lowdist", 0 },
        { "titledist", -71 }
    };
    return _;
};
auto rule82() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -219 },
        { "lowdist", 0 },
        { "titledist", -219 }
    };
    return _;
};
auto rule90() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -38 },
        { "lowdist", 0 },
        { "titledist", -38 }
    };
    return _;
};
auto rule91() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -37 },
        { "lowdist", 0 },
        { "titledist", -37 }
    };
    return _;
};
auto rule92() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -31 },
        { "lowdist", 0 },
        { "titledist", -31 }
    };
    return _;
};
auto rule93() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -64 },
        { "lowdist", 0 },
        { "titledist", -64 }
    };
    return _;
};
auto rule94() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -63 },
        { "lowdist", 0 },
        { "titledist", -63 }
    };
    return _;
};
auto rule96() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -62 },
        { "lowdist", 0 },
        { "titledist", -62 }
    };
    return _;
};
auto rule97() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -57 },
        { "lowdist", 0 },
        { "titledist", -57 }
    };
    return _;
};
auto rule99() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatLL() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_LL() },
        { "possible", 1 },
        { "updist", -47 },
        { "lowdist", 0 },
        { "titledist", -47 }
    };
    return _;
};
auto gencatCS() -> const boxed& {
    static const boxed _ = 134217728;
    return _;
};
auto rule163() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatCS() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_CS() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatCO() -> const boxed& {
    static const boxed _ = 268435456;
    return _;
};
auto rule164() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatCO() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_CO() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatCF() -> const boxed& {
    static const boxed _ = 32768;
    return _;
};
auto rule16() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatCF() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_CF() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto gencatCC() -> const boxed& {
    static const boxed _ = 1;
    return _;
};
auto rule0() -> const boxed& {
    static const boxed _ = dict_t{
        { "category", Data_Char_Unicode_Internal::gencatCC() },
        { "unicodeCat", Data_Char_Unicode_Internal::NUMCAT_CC() },
        { "possible", 0 },
        { "updist", 0 },
        { "lowdist", 0 },
        { "titledist", 0 }
    };
    return _;
};
auto convchars() -> const boxed& {
    static const boxed _ = array_t{ dict_t{
        { "start", 65 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 97 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 181 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule18() }
    }, dict_t{
        { "start", 192 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 216 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 224 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 248 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 255 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule20() }
    }, dict_t{
        { "start", 256 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 257 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 258 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 259 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 260 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 261 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 262 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 263 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 264 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 265 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 266 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 267 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 268 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 269 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 270 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 271 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 272 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 273 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 274 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 275 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 276 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 277 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 278 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 279 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 280 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 281 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 282 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 283 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 284 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 285 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 286 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 287 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 288 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 289 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 290 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 291 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 292 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 293 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 294 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 295 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 296 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 297 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 298 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 299 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 300 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 301 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 302 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 303 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 304 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule23() }
    }, dict_t{
        { "start", 305 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule24() }
    }, dict_t{
        { "start", 306 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 307 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 308 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 309 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 310 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 311 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 313 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 314 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 315 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 316 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 317 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 318 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 319 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 320 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 321 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 322 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 323 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 324 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 325 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 326 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 327 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 328 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 330 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 331 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 332 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 333 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 334 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 335 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 336 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 337 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 338 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 339 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 340 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 341 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 342 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 343 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 344 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 345 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 346 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 347 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 348 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 349 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 350 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 351 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 352 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 353 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 354 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 355 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 356 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 357 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 358 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 359 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 360 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 361 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 362 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 363 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 364 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 365 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 366 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 367 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 368 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 369 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 370 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 371 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 372 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 373 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 374 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 375 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 376 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule25() }
    }, dict_t{
        { "start", 377 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 378 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 379 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 380 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 381 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 382 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 383 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule26() }
    }, dict_t{
        { "start", 384 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule27() }
    }, dict_t{
        { "start", 385 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule28() }
    }, dict_t{
        { "start", 386 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 387 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 388 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 389 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 390 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule29() }
    }, dict_t{
        { "start", 391 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 392 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 393 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule30() }
    }, dict_t{
        { "start", 395 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 396 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 398 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule31() }
    }, dict_t{
        { "start", 399 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule32() }
    }, dict_t{
        { "start", 400 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule33() }
    }, dict_t{
        { "start", 401 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 402 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 403 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule30() }
    }, dict_t{
        { "start", 404 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule34() }
    }, dict_t{
        { "start", 405 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule35() }
    }, dict_t{
        { "start", 406 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule36() }
    }, dict_t{
        { "start", 407 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule37() }
    }, dict_t{
        { "start", 408 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 409 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 410 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule38() }
    }, dict_t{
        { "start", 412 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule36() }
    }, dict_t{
        { "start", 413 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule39() }
    }, dict_t{
        { "start", 414 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule40() }
    }, dict_t{
        { "start", 415 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule41() }
    }, dict_t{
        { "start", 416 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 417 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 418 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 419 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 420 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 421 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 422 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule42() }
    }, dict_t{
        { "start", 423 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 424 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 425 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule42() }
    }, dict_t{
        { "start", 428 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 429 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 430 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule42() }
    }, dict_t{
        { "start", 431 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 432 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 433 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule43() }
    }, dict_t{
        { "start", 435 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 436 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 437 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 438 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 439 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule44() }
    }, dict_t{
        { "start", 440 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 441 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 444 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 445 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 447 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule46() }
    }, dict_t{
        { "start", 452 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule47() }
    }, dict_t{
        { "start", 453 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule48() }
    }, dict_t{
        { "start", 454 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule49() }
    }, dict_t{
        { "start", 455 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule47() }
    }, dict_t{
        { "start", 456 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule48() }
    }, dict_t{
        { "start", 457 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule49() }
    }, dict_t{
        { "start", 458 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule47() }
    }, dict_t{
        { "start", 459 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule48() }
    }, dict_t{
        { "start", 460 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule49() }
    }, dict_t{
        { "start", 461 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 462 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 463 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 464 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 465 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 466 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 467 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 468 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 469 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 470 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 471 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 472 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 473 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 474 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 475 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 476 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 477 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule50() }
    }, dict_t{
        { "start", 478 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 479 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 480 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 481 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 482 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 483 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 484 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 485 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 486 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 487 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 488 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 489 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 490 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 491 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 492 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 493 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 494 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 495 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 497 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule47() }
    }, dict_t{
        { "start", 498 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule48() }
    }, dict_t{
        { "start", 499 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule49() }
    }, dict_t{
        { "start", 500 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 501 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 502 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule51() }
    }, dict_t{
        { "start", 503 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule52() }
    }, dict_t{
        { "start", 504 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 505 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 506 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 507 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 508 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 509 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 510 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 511 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 512 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 513 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 514 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 515 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 516 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 517 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 518 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 519 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 520 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 521 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 522 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 523 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 524 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 525 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 526 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 527 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 528 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 529 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 530 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 531 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 532 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 533 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 534 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 535 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 536 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 537 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 538 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 539 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 540 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 541 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 542 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 543 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 544 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule53() }
    }, dict_t{
        { "start", 546 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 547 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 548 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 549 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 550 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 551 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 552 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 553 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 554 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 555 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 556 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 557 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 558 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 559 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 560 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 561 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 562 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 563 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 570 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule54() }
    }, dict_t{
        { "start", 571 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 572 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 573 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule55() }
    }, dict_t{
        { "start", 574 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule56() }
    }, dict_t{
        { "start", 575 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule57() }
    }, dict_t{
        { "start", 577 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 578 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 579 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule58() }
    }, dict_t{
        { "start", 580 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule59() }
    }, dict_t{
        { "start", 581 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule60() }
    }, dict_t{
        { "start", 582 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 583 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 584 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 585 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 586 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 587 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 588 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 589 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 590 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 591 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 592 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule61() }
    }, dict_t{
        { "start", 593 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule62() }
    }, dict_t{
        { "start", 594 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule63() }
    }, dict_t{
        { "start", 595 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule64() }
    }, dict_t{
        { "start", 596 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule65() }
    }, dict_t{
        { "start", 598 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule66() }
    }, dict_t{
        { "start", 601 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule67() }
    }, dict_t{
        { "start", 603 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule68() }
    }, dict_t{
        { "start", 608 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule66() }
    }, dict_t{
        { "start", 611 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule69() }
    }, dict_t{
        { "start", 613 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule70() }
    }, dict_t{
        { "start", 616 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule71() }
    }, dict_t{
        { "start", 617 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule72() }
    }, dict_t{
        { "start", 619 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule73() }
    }, dict_t{
        { "start", 623 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule72() }
    }, dict_t{
        { "start", 625 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule74() }
    }, dict_t{
        { "start", 626 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule75() }
    }, dict_t{
        { "start", 629 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule76() }
    }, dict_t{
        { "start", 637 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule77() }
    }, dict_t{
        { "start", 640 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule78() }
    }, dict_t{
        { "start", 643 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule78() }
    }, dict_t{
        { "start", 648 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule78() }
    }, dict_t{
        { "start", 649 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule79() }
    }, dict_t{
        { "start", 650 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule80() }
    }, dict_t{
        { "start", 652 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule81() }
    }, dict_t{
        { "start", 658 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule82() }
    }, dict_t{
        { "start", 837 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule85() }
    }, dict_t{
        { "start", 880 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 881 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 882 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 883 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 886 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 887 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 891 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule40() }
    }, dict_t{
        { "start", 902 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule86() }
    }, dict_t{
        { "start", 904 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule87() }
    }, dict_t{
        { "start", 908 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule88() }
    }, dict_t{
        { "start", 910 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule89() }
    }, dict_t{
        { "start", 913 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 931 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 940 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule90() }
    }, dict_t{
        { "start", 941 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule91() }
    }, dict_t{
        { "start", 945 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 962 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule92() }
    }, dict_t{
        { "start", 963 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 972 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule93() }
    }, dict_t{
        { "start", 973 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule94() }
    }, dict_t{
        { "start", 975 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule95() }
    }, dict_t{
        { "start", 976 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule96() }
    }, dict_t{
        { "start", 977 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule97() }
    }, dict_t{
        { "start", 981 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule99() }
    }, dict_t{
        { "start", 982 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule100() }
    }, dict_t{
        { "start", 983 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule101() }
    }, dict_t{
        { "start", 984 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 985 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 986 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 987 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 988 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 989 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 990 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 991 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 992 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 993 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 994 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 995 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 996 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 997 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 998 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 999 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1000 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1001 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1002 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1003 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1004 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1005 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1006 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1007 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1008 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule102() }
    }, dict_t{
        { "start", 1009 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule103() }
    }, dict_t{
        { "start", 1010 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule104() }
    }, dict_t{
        { "start", 1012 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule105() }
    }, dict_t{
        { "start", 1013 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule106() }
    }, dict_t{
        { "start", 1015 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1016 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1017 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule107() }
    }, dict_t{
        { "start", 1018 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1019 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1021 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule53() }
    }, dict_t{
        { "start", 1024 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule108() }
    }, dict_t{
        { "start", 1040 },
        { "length", 32 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 1072 },
        { "length", 32 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 1104 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule103() }
    }, dict_t{
        { "start", 1120 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1121 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1122 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1123 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1124 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1125 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1126 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1127 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1128 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1129 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1130 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1131 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1132 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1133 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1134 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1135 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1136 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1137 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1138 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1139 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1140 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1141 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1142 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1143 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1144 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1145 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1146 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1147 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1148 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1149 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1150 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1151 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1152 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1153 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1162 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1163 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1164 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1165 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1166 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1167 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1168 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1169 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1170 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1171 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1172 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1173 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1174 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1175 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1176 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1177 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1178 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1179 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1180 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1181 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1182 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1183 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1184 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1185 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1186 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1187 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1188 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1189 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1190 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1191 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1192 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1193 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1194 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1195 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1196 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1197 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1198 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1199 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1200 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1201 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1202 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1203 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1204 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1205 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1206 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1207 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1208 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1209 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1210 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1211 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1212 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1213 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1214 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1215 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1216 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule110() }
    }, dict_t{
        { "start", 1217 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1218 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1219 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1220 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1221 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1222 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1223 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1224 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1225 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1226 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1227 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1228 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1229 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1230 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1231 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule111() }
    }, dict_t{
        { "start", 1232 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1233 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1234 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1235 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1236 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1237 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1238 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1239 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1240 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1241 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1242 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1243 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1244 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1245 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1246 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1247 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1248 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1249 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1250 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1251 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1252 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1253 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1254 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1255 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1256 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1257 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1258 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1259 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1260 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1261 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1262 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1263 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1264 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1265 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1266 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1267 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1268 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1269 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1270 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1271 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1272 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1273 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1274 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1275 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1276 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1277 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1278 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1279 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1280 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1281 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1282 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1283 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1284 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1285 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1286 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1287 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1288 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1289 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1290 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1291 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1292 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1293 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1294 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1295 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1296 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1297 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1298 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1299 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1300 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1301 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1302 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1303 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1304 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1305 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1306 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1307 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1308 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1309 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1310 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1311 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1312 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1313 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1314 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1315 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1316 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1317 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1318 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1319 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1329 },
        { "length", 38 },
        { "convRule", Data_Char_Unicode_Internal::rule112() }
    }, dict_t{
        { "start", 1377 },
        { "length", 38 },
        { "convRule", Data_Char_Unicode_Internal::rule113() }
    }, dict_t{
        { "start", 4256 },
        { "length", 38 },
        { "convRule", Data_Char_Unicode_Internal::rule115() }
    }, dict_t{
        { "start", 7545 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule117() }
    }, dict_t{
        { "start", 7549 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule118() }
    }, dict_t{
        { "start", 7680 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7681 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7682 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7683 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7684 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7685 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7686 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7687 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7688 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7689 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7690 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7691 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7692 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7693 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7694 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7695 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7696 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7697 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7698 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7699 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7700 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7701 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7702 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7703 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7704 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7705 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7706 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7707 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7708 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7709 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7710 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7711 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7712 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7713 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7714 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7715 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7716 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7717 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7718 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7719 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7720 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7721 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7722 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7723 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7724 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7725 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7726 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7727 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7728 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7729 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7730 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7731 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7732 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7733 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7734 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7735 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7736 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7737 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7738 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7739 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7740 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7741 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7742 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7743 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7744 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7745 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7746 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7747 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7748 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7749 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7750 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7751 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7752 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7753 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7754 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7755 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7756 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7757 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7758 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7759 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7760 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7761 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7762 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7763 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7764 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7765 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7766 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7767 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7768 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7769 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7770 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7771 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7772 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7773 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7774 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7775 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7776 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7777 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7778 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7779 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7780 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7781 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7782 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7783 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7784 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7785 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7786 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7787 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7788 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7789 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7790 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7791 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7792 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7793 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7794 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7795 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7796 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7797 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7798 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7799 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7800 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7801 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7802 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7803 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7804 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7805 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7806 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7807 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7808 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7809 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7810 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7811 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7812 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7813 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7814 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7815 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7816 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7817 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7818 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7819 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7820 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7821 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7822 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7823 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7824 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7825 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7826 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7827 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7828 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7829 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7835 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule119() }
    }, dict_t{
        { "start", 7838 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule120() }
    }, dict_t{
        { "start", 7840 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7841 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7842 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7843 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7844 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7845 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7846 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7847 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7848 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7849 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7850 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7851 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7852 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7853 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7854 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7855 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7856 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7857 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7858 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7859 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7860 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7861 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7862 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7863 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7864 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7865 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7866 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7867 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7868 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7869 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7870 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7871 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7872 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7873 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7874 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7875 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7876 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7877 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7878 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7879 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7880 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7881 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7882 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7883 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7884 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7885 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7886 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7887 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7888 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7889 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7890 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7891 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7892 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7893 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7894 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7895 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7896 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7897 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7898 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7899 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7900 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7901 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7902 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7903 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7904 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7905 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7906 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7907 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7908 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7909 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7910 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7911 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7912 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7913 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7914 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7915 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7916 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7917 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7918 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7919 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7920 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7921 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7922 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7923 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7924 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7925 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7926 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7927 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7928 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7929 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7930 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7931 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7932 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7933 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7934 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7935 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7936 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 7944 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 7952 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 7960 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 7968 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 7976 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 7984 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 7992 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8000 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8008 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8017 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8019 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8021 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8023 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8025 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8027 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8029 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8031 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8032 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8040 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8048 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule123() }
    }, dict_t{
        { "start", 8050 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule124() }
    }, dict_t{
        { "start", 8054 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule125() }
    }, dict_t{
        { "start", 8056 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule126() }
    }, dict_t{
        { "start", 8058 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule127() }
    }, dict_t{
        { "start", 8060 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule128() }
    }, dict_t{
        { "start", 8064 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8072 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule129() }
    }, dict_t{
        { "start", 8080 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8088 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule129() }
    }, dict_t{
        { "start", 8096 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8104 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule129() }
    }, dict_t{
        { "start", 8112 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8115 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule130() }
    }, dict_t{
        { "start", 8120 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8122 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule131() }
    }, dict_t{
        { "start", 8124 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule132() }
    }, dict_t{
        { "start", 8126 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule133() }
    }, dict_t{
        { "start", 8131 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule130() }
    }, dict_t{
        { "start", 8136 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule134() }
    }, dict_t{
        { "start", 8140 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule132() }
    }, dict_t{
        { "start", 8144 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8152 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8154 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule135() }
    }, dict_t{
        { "start", 8160 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8165 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule104() }
    }, dict_t{
        { "start", 8168 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8170 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule136() }
    }, dict_t{
        { "start", 8172 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule107() }
    }, dict_t{
        { "start", 8179 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule130() }
    }, dict_t{
        { "start", 8184 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule137() }
    }, dict_t{
        { "start", 8186 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule138() }
    }, dict_t{
        { "start", 8188 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule132() }
    }, dict_t{
        { "start", 8486 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule141() }
    }, dict_t{
        { "start", 8490 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule142() }
    }, dict_t{
        { "start", 8491 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule143() }
    }, dict_t{
        { "start", 8498 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule144() }
    }, dict_t{
        { "start", 8526 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule145() }
    }, dict_t{
        { "start", 8544 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule146() }
    }, dict_t{
        { "start", 8560 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule147() }
    }, dict_t{
        { "start", 8579 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 8580 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 9398 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule148() }
    }, dict_t{
        { "start", 9424 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule149() }
    }, dict_t{
        { "start", 11264 },
        { "length", 47 },
        { "convRule", Data_Char_Unicode_Internal::rule112() }
    }, dict_t{
        { "start", 11312 },
        { "length", 47 },
        { "convRule", Data_Char_Unicode_Internal::rule113() }
    }, dict_t{
        { "start", 11360 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11361 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11362 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule150() }
    }, dict_t{
        { "start", 11363 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule151() }
    }, dict_t{
        { "start", 11364 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule152() }
    }, dict_t{
        { "start", 11365 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule153() }
    }, dict_t{
        { "start", 11366 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule154() }
    }, dict_t{
        { "start", 11367 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11368 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11369 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11370 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11371 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11372 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11373 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule155() }
    }, dict_t{
        { "start", 11374 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule156() }
    }, dict_t{
        { "start", 11375 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule157() }
    }, dict_t{
        { "start", 11376 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule158() }
    }, dict_t{
        { "start", 11378 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11379 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11381 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11382 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11390 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule159() }
    }, dict_t{
        { "start", 11392 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11393 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11394 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11395 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11396 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11397 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11398 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11399 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11400 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11401 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11402 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11403 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11404 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11405 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11406 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11407 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11408 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11409 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11410 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11411 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11412 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11413 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11414 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11415 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11416 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11417 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11418 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11419 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11420 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11421 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11422 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11423 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11424 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11425 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11426 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11427 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11428 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11429 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11430 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11431 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11432 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11433 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11434 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11435 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11436 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11437 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11438 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11439 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11440 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11441 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11442 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11443 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11444 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11445 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11446 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11447 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11448 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11449 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11450 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11451 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11452 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11453 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11454 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11455 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11456 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11457 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11458 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11459 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11460 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11461 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11462 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11463 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11464 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11465 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11466 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11467 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11468 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11469 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11470 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11471 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11472 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11473 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11474 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11475 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11476 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11477 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11478 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11479 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11480 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11481 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11482 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11483 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11484 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11485 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11486 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11487 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11488 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11489 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11490 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11491 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11499 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11500 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11501 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11502 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11520 },
        { "length", 38 },
        { "convRule", Data_Char_Unicode_Internal::rule160() }
    }, dict_t{
        { "start", 42560 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42561 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42562 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42563 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42564 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42565 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42566 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42567 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42568 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42569 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42570 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42571 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42572 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42573 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42574 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42575 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42576 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42577 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42578 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42579 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42580 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42581 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42582 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42583 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42584 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42585 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42586 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42587 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42588 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42589 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42590 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42591 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42592 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42593 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42594 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42595 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42596 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42597 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42598 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42599 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42600 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42601 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42602 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42603 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42604 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42605 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42624 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42625 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42626 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42627 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42628 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42629 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42630 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42631 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42632 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42633 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42634 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42635 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42636 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42637 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42638 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42639 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42640 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42641 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42642 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42643 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42644 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42645 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42646 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42647 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42786 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42787 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42788 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42789 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42790 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42791 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42792 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42793 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42794 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42795 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42796 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42797 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42798 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42799 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42802 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42803 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42804 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42805 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42806 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42807 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42808 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42809 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42810 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42811 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42812 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42813 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42814 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42815 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42816 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42817 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42818 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42819 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42820 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42821 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42822 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42823 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42824 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42825 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42826 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42827 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42828 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42829 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42830 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42831 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42832 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42833 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42834 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42835 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42836 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42837 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42838 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42839 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42840 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42841 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42842 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42843 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42844 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42845 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42846 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42847 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42848 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42849 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42850 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42851 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42852 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42853 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42854 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42855 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42856 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42857 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42858 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42859 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42860 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42861 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42862 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42863 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42873 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42874 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42875 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42876 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42877 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule161() }
    }, dict_t{
        { "start", 42878 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42879 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42880 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42881 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42882 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42883 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42884 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42885 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42886 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42887 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42891 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42892 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42893 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule162() }
    }, dict_t{
        { "start", 42896 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42897 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42912 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42913 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42914 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42915 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42916 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42917 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42918 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42919 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42920 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42921 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 65313 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 65345 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 66560 },
        { "length", 40 },
        { "convRule", Data_Char_Unicode_Internal::rule165() }
    }, dict_t{
        { "start", 66600 },
        { "length", 40 },
        { "convRule", Data_Char_Unicode_Internal::rule166() }
    } };
    return _;
};
auto bsearch() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& array) -> boxed {
            return [=](const boxed& size) -> boxed {
                return [=](const boxed& compare) -> boxed {
                    boxed::recur go;
                    boxed::recur::weak go_Weak_(go);
                    go = [=](const boxed& i) -> boxed {
                        boxed go = go_Weak_;
                        return [=](const boxed& k) -> boxed {
                            if (unbox<bool>(Data_Ord::greaterThan()(Data_Ord::ordInt())(i)(k))) {
                                return Data_Maybe::Nothing();
                            };
                            if (unbox<bool>(Data_Boolean::otherwise())) {
                                boxed j = Data_Int::floor()(unbox<double>(Data_Int::toNumber()(unbox<int>(i) + unbox<int>(k))) / 2.0);

								//boxed b_testInt = Data_Int::floor()(2.5);
								//int testInt = unbox<int>(b_testInt);

                                boxed b = [=](const boxed& dictPartial) -> boxed {
                                    return Data_Array::unsafeIndex()(dictPartial)(array)(j);
                                }(undefined);

								//int ii = unbox<int>(i);
								//int jj = unbox<int>(j);
								//int kk = unbox<int>(k);
								//std::cout << " i is " << ii << " jj is " << jj << " kk is " << kk << std::endl;

                                boxed v = compare(a)(b);
                                if (unbox<dict_t>(v).contains("EQ")) {
                                    return Data_Maybe::Just()(b);
                                };
                                if (unbox<dict_t>(v).contains("GT")) {
                                    return go(unbox<int>(j) + 1)(k);
                                };
                                return go(i)(unbox<int>(j) - 1);
                            };
                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode.Internal (line 4783, column 5 - line 4789, column 49): ");
                        };
                    };
                    return go(0)(size);
                };
            };
        };
    };
    return _;
};
auto blkCmp() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<bool>(unbox<bool>(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(v["start"])(v1["start"])) && unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(v["start"])(unbox<int>(v1["start"]) + unbox<int>(v1["length"]))))) {
                return Data_Ordering::EQ();
            };
            if (unbox<bool>(Data_Ord::greaterThan()(Data_Ord::ordInt())(v["start"])(v1["start"]))) {
                return Data_Ordering::GT();
            };
            return Data_Ordering::LT();
        };
    };
    return _;
};
auto getRule() -> const boxed& {
    static const boxed _ = [](const boxed& blocks) -> boxed {
        return [=](const boxed& unichar) -> boxed {
            return [=](const boxed& size) -> boxed {
                boxed key = dict_t{
                    { "start", unichar },
                    { "length", 1 },
                    { "convRule", Data_Char_Unicode_Internal::nullrule() }
                };
                boxed maybeCharBlock = Data_Char_Unicode_Internal::bsearch()(key)(blocks)(size)(Data_Char_Unicode_Internal::blkCmp());
                if (unbox<dict_t>(maybeCharBlock).contains("Nothing")) {
                    return Data_Maybe::Nothing();
                };
                if (unbox<dict_t>(maybeCharBlock).contains("Just")) {
                    return Data_Maybe::Just()(maybeCharBlock["value0"]["convRule"]);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode.Internal (line 4773, column 8 - line 4775, column 62): ");
            };
        };
    };
    return _;
};
auto caseConv() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& _char_) -> boxed {
            boxed maybeConversionRule = Data_Char_Unicode_Internal::getRule()(Data_Char_Unicode_Internal::convchars())(_char_)(Data_Char_Unicode_Internal::numConvBlocks());
            if (unbox<dict_t>(maybeConversionRule).contains("Nothing")) {
                return _char_;
            };
            if (unbox<dict_t>(maybeConversionRule).contains("Just")) {
                return unbox<int>(_char_) + unbox<int>(f(maybeConversionRule["value0"]));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode.Internal (line 4850, column 8 - line 4852, column 55): ");
        };
    };
    return _;
};
auto uTowlower() -> boxed {
    return Data_Char_Unicode_Internal::caseConv()([=](const boxed& v) -> boxed {
        return v["lowdist"];
    });
};
auto uTowtitle() -> boxed {
    return Data_Char_Unicode_Internal::caseConv()([=](const boxed& v) -> boxed {
        return v["titledist"];
    });
};
auto uTowupper() -> boxed {
    return Data_Char_Unicode_Internal::caseConv()([=](const boxed& v) -> boxed {
        return v["updist"];
    });
};
auto checkAttrS() -> const boxed& {
    static const boxed _ = [](const boxed& categories) -> boxed {
        return [=](const boxed& _char_) -> boxed {
            boxed maybeConversionRule = Data_Char_Unicode_Internal::getRule()(Data_Char_Unicode_Internal::spacechars())(_char_)(Data_Char_Unicode_Internal::numSpaceBlocks());
            if (unbox<dict_t>(maybeConversionRule).contains("Nothing")) {
                return false;
            };
            if (unbox<dict_t>(maybeConversionRule).contains("Just")) {
                return Data_Maybe::isJust()(Data_Array::elemIndex()(Data_Eq::eqInt())(maybeConversionRule["value0"]["category"])(categories));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode.Internal (line 4807, column 8 - line 4809, column 92): ");
        };
    };
    return _;
};
auto uIswspace() -> boxed {
    return Data_Char_Unicode_Internal::checkAttrS()(array_t{ Data_Char_Unicode_Internal::gencatZS() });
};
auto allchars() -> const boxed& {
    static const boxed _ = array_t{ dict_t{
        { "start", 0 },
        { "length", 32 },
        { "convRule", Data_Char_Unicode_Internal::rule0() }
    }, dict_t{
        { "start", 32 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 33 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 36 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 37 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 40 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 41 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 42 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 44 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 45 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 46 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 48 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 58 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 60 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 63 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 91 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 92 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 93 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 94 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 95 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule11() }
    }, dict_t{
        { "start", 96 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 97 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 123 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 124 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 125 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 126 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 127 },
        { "length", 33 },
        { "convRule", Data_Char_Unicode_Internal::rule0() }
    }, dict_t{
        { "start", 160 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 161 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 162 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 166 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 168 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 169 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 170 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 171 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 172 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 173 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 174 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 175 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 176 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 177 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 178 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 180 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 181 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule18() }
    }, dict_t{
        { "start", 182 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 183 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 184 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 185 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 186 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 187 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 188 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 191 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 192 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 215 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 216 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 223 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 224 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 247 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 248 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 255 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule20() }
    }, dict_t{
        { "start", 256 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 257 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 258 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 259 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 260 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 261 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 262 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 263 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 264 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 265 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 266 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 267 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 268 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 269 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 270 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 271 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 272 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 273 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 274 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 275 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 276 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 277 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 278 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 279 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 280 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 281 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 282 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 283 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 284 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 285 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 286 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 287 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 288 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 289 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 290 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 291 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 292 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 293 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 294 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 295 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 296 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 297 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 298 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 299 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 300 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 301 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 302 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 303 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 304 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule23() }
    }, dict_t{
        { "start", 305 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule24() }
    }, dict_t{
        { "start", 306 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 307 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 308 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 309 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 310 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 311 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 312 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 313 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 314 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 315 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 316 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 317 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 318 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 319 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 320 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 321 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 322 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 323 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 324 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 325 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 326 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 327 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 328 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 329 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 330 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 331 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 332 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 333 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 334 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 335 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 336 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 337 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 338 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 339 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 340 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 341 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 342 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 343 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 344 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 345 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 346 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 347 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 348 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 349 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 350 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 351 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 352 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 353 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 354 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 355 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 356 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 357 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 358 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 359 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 360 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 361 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 362 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 363 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 364 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 365 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 366 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 367 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 368 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 369 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 370 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 371 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 372 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 373 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 374 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 375 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 376 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule25() }
    }, dict_t{
        { "start", 377 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 378 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 379 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 380 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 381 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 382 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 383 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule26() }
    }, dict_t{
        { "start", 384 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule27() }
    }, dict_t{
        { "start", 385 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule28() }
    }, dict_t{
        { "start", 386 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 387 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 388 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 389 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 390 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule29() }
    }, dict_t{
        { "start", 391 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 392 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 393 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule30() }
    }, dict_t{
        { "start", 395 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 396 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 397 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 398 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule31() }
    }, dict_t{
        { "start", 399 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule32() }
    }, dict_t{
        { "start", 400 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule33() }
    }, dict_t{
        { "start", 401 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 402 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 403 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule30() }
    }, dict_t{
        { "start", 404 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule34() }
    }, dict_t{
        { "start", 405 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule35() }
    }, dict_t{
        { "start", 406 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule36() }
    }, dict_t{
        { "start", 407 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule37() }
    }, dict_t{
        { "start", 408 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 409 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 410 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule38() }
    }, dict_t{
        { "start", 411 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 412 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule36() }
    }, dict_t{
        { "start", 413 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule39() }
    }, dict_t{
        { "start", 414 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule40() }
    }, dict_t{
        { "start", 415 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule41() }
    }, dict_t{
        { "start", 416 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 417 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 418 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 419 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 420 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 421 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 422 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule42() }
    }, dict_t{
        { "start", 423 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 424 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 425 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule42() }
    }, dict_t{
        { "start", 426 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 428 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 429 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 430 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule42() }
    }, dict_t{
        { "start", 431 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 432 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 433 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule43() }
    }, dict_t{
        { "start", 435 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 436 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 437 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 438 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 439 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule44() }
    }, dict_t{
        { "start", 440 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 441 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 442 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 443 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 444 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 445 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 446 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 447 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule46() }
    }, dict_t{
        { "start", 448 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 452 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule47() }
    }, dict_t{
        { "start", 453 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule48() }
    }, dict_t{
        { "start", 454 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule49() }
    }, dict_t{
        { "start", 455 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule47() }
    }, dict_t{
        { "start", 456 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule48() }
    }, dict_t{
        { "start", 457 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule49() }
    }, dict_t{
        { "start", 458 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule47() }
    }, dict_t{
        { "start", 459 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule48() }
    }, dict_t{
        { "start", 460 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule49() }
    }, dict_t{
        { "start", 461 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 462 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 463 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 464 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 465 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 466 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 467 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 468 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 469 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 470 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 471 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 472 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 473 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 474 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 475 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 476 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 477 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule50() }
    }, dict_t{
        { "start", 478 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 479 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 480 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 481 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 482 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 483 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 484 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 485 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 486 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 487 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 488 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 489 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 490 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 491 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 492 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 493 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 494 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 495 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 496 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 497 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule47() }
    }, dict_t{
        { "start", 498 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule48() }
    }, dict_t{
        { "start", 499 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule49() }
    }, dict_t{
        { "start", 500 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 501 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 502 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule51() }
    }, dict_t{
        { "start", 503 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule52() }
    }, dict_t{
        { "start", 504 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 505 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 506 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 507 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 508 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 509 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 510 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 511 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 512 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 513 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 514 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 515 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 516 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 517 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 518 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 519 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 520 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 521 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 522 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 523 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 524 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 525 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 526 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 527 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 528 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 529 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 530 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 531 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 532 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 533 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 534 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 535 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 536 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 537 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 538 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 539 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 540 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 541 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 542 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 543 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 544 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule53() }
    }, dict_t{
        { "start", 545 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 546 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 547 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 548 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 549 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 550 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 551 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 552 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 553 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 554 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 555 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 556 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 557 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 558 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 559 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 560 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 561 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 562 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 563 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 564 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 570 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule54() }
    }, dict_t{
        { "start", 571 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 572 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 573 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule55() }
    }, dict_t{
        { "start", 574 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule56() }
    }, dict_t{
        { "start", 575 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule57() }
    }, dict_t{
        { "start", 577 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 578 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 579 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule58() }
    }, dict_t{
        { "start", 580 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule59() }
    }, dict_t{
        { "start", 581 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule60() }
    }, dict_t{
        { "start", 582 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 583 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 584 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 585 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 586 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 587 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 588 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 589 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 590 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 591 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 592 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule61() }
    }, dict_t{
        { "start", 593 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule62() }
    }, dict_t{
        { "start", 594 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule63() }
    }, dict_t{
        { "start", 595 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule64() }
    }, dict_t{
        { "start", 596 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule65() }
    }, dict_t{
        { "start", 597 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 598 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule66() }
    }, dict_t{
        { "start", 600 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 601 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule67() }
    }, dict_t{
        { "start", 602 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 603 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule68() }
    }, dict_t{
        { "start", 604 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 608 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule66() }
    }, dict_t{
        { "start", 609 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 611 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule69() }
    }, dict_t{
        { "start", 612 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 613 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule70() }
    }, dict_t{
        { "start", 614 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 616 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule71() }
    }, dict_t{
        { "start", 617 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule72() }
    }, dict_t{
        { "start", 618 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 619 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule73() }
    }, dict_t{
        { "start", 620 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 623 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule72() }
    }, dict_t{
        { "start", 624 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 625 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule74() }
    }, dict_t{
        { "start", 626 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule75() }
    }, dict_t{
        { "start", 627 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 629 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule76() }
    }, dict_t{
        { "start", 630 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 637 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule77() }
    }, dict_t{
        { "start", 638 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 640 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule78() }
    }, dict_t{
        { "start", 641 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 643 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule78() }
    }, dict_t{
        { "start", 644 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 648 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule78() }
    }, dict_t{
        { "start", 649 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule79() }
    }, dict_t{
        { "start", 650 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule80() }
    }, dict_t{
        { "start", 652 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule81() }
    }, dict_t{
        { "start", 653 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 658 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule82() }
    }, dict_t{
        { "start", 659 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 660 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 661 },
        { "length", 27 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 688 },
        { "length", 18 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 706 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 710 },
        { "length", 12 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 722 },
        { "length", 14 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 736 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 741 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 748 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 749 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 750 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 751 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 768 },
        { "length", 69 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 837 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule85() }
    }, dict_t{
        { "start", 838 },
        { "length", 42 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 880 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 881 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 882 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 883 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 884 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 885 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 886 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 887 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 890 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 891 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule40() }
    }, dict_t{
        { "start", 894 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 900 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 902 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule86() }
    }, dict_t{
        { "start", 903 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 904 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule87() }
    }, dict_t{
        { "start", 908 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule88() }
    }, dict_t{
        { "start", 910 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule89() }
    }, dict_t{
        { "start", 912 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 913 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 931 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 940 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule90() }
    }, dict_t{
        { "start", 941 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule91() }
    }, dict_t{
        { "start", 944 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 945 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 962 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule92() }
    }, dict_t{
        { "start", 963 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 972 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule93() }
    }, dict_t{
        { "start", 973 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule94() }
    }, dict_t{
        { "start", 975 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule95() }
    }, dict_t{
        { "start", 976 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule96() }
    }, dict_t{
        { "start", 977 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule97() }
    }, dict_t{
        { "start", 978 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 981 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule99() }
    }, dict_t{
        { "start", 982 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule100() }
    }, dict_t{
        { "start", 983 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule101() }
    }, dict_t{
        { "start", 984 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 985 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 986 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 987 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 988 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 989 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 990 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 991 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 992 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 993 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 994 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 995 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 996 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 997 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 998 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 999 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1000 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1001 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1002 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1003 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1004 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1005 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1006 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1007 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1008 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule102() }
    }, dict_t{
        { "start", 1009 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule103() }
    }, dict_t{
        { "start", 1010 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule104() }
    }, dict_t{
        { "start", 1011 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 1012 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule105() }
    }, dict_t{
        { "start", 1013 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule106() }
    }, dict_t{
        { "start", 1014 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 1015 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1016 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1017 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule107() }
    }, dict_t{
        { "start", 1018 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1019 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1020 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 1021 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule53() }
    }, dict_t{
        { "start", 1024 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule108() }
    }, dict_t{
        { "start", 1040 },
        { "length", 32 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 1072 },
        { "length", 32 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 1104 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule103() }
    }, dict_t{
        { "start", 1120 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1121 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1122 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1123 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1124 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1125 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1126 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1127 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1128 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1129 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1130 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1131 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1132 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1133 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1134 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1135 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1136 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1137 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1138 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1139 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1140 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1141 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1142 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1143 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1144 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1145 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1146 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1147 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1148 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1149 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1150 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1151 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1152 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1153 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1154 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 1155 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1160 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule109() }
    }, dict_t{
        { "start", 1162 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1163 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1164 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1165 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1166 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1167 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1168 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1169 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1170 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1171 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1172 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1173 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1174 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1175 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1176 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1177 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1178 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1179 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1180 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1181 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1182 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1183 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1184 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1185 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1186 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1187 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1188 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1189 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1190 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1191 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1192 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1193 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1194 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1195 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1196 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1197 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1198 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1199 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1200 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1201 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1202 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1203 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1204 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1205 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1206 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1207 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1208 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1209 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1210 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1211 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1212 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1213 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1214 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1215 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1216 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule110() }
    }, dict_t{
        { "start", 1217 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1218 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1219 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1220 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1221 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1222 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1223 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1224 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1225 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1226 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1227 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1228 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1229 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1230 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1231 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule111() }
    }, dict_t{
        { "start", 1232 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1233 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1234 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1235 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1236 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1237 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1238 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1239 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1240 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1241 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1242 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1243 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1244 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1245 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1246 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1247 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1248 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1249 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1250 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1251 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1252 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1253 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1254 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1255 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1256 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1257 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1258 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1259 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1260 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1261 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1262 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1263 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1264 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1265 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1266 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1267 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1268 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1269 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1270 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1271 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1272 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1273 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1274 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1275 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1276 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1277 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1278 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1279 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1280 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1281 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1282 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1283 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1284 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1285 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1286 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1287 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1288 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1289 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1290 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1291 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1292 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1293 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1294 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1295 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1296 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1297 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1298 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1299 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1300 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1301 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1302 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1303 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1304 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1305 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1306 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1307 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1308 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1309 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1310 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1311 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1312 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1313 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1314 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1315 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1316 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1317 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1318 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 1319 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 1329 },
        { "length", 38 },
        { "convRule", Data_Char_Unicode_Internal::rule112() }
    }, dict_t{
        { "start", 1369 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 1370 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1377 },
        { "length", 38 },
        { "convRule", Data_Char_Unicode_Internal::rule113() }
    }, dict_t{
        { "start", 1415 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 1417 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1418 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 1425 },
        { "length", 45 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1470 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 1471 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1472 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1473 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1475 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1476 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1478 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1479 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1488 },
        { "length", 27 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1520 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1523 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1536 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 1542 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 1545 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1547 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 1548 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1550 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 1552 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1563 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1566 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1568 },
        { "length", 32 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1600 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 1601 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1611 },
        { "length", 21 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1632 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 1642 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1646 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1648 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1649 },
        { "length", 99 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1748 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1749 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1750 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1757 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 1758 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 1759 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1765 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 1767 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1769 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 1770 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1774 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1776 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 1786 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1789 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 1791 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1792 },
        { "length", 14 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 1807 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 1808 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1809 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1810 },
        { "length", 30 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1840 },
        { "length", 27 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1869 },
        { "length", 89 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1958 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 1969 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 1984 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 1994 },
        { "length", 33 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2027 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2036 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 2038 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 2039 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 2042 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 2048 },
        { "length", 22 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2070 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2074 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 2075 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2084 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 2085 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2088 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 2089 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2096 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 2112 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2137 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2142 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 2304 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2307 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2308 },
        { "length", 54 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2362 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2363 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2364 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2365 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2366 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2369 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2377 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2381 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2382 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2384 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2385 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2392 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2402 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2404 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 2406 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 2416 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 2417 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 2418 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2425 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2433 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2434 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2437 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2447 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2451 },
        { "length", 22 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2474 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2482 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2486 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2492 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2493 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2494 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2497 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2503 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2507 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2509 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2510 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2519 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2524 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2527 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2530 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2534 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 2544 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2546 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 2548 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 2554 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 2555 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 2561 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2563 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2565 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2575 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2579 },
        { "length", 22 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2602 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2610 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2613 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2616 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2620 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2622 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2625 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2631 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2635 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2641 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2649 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2654 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2662 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 2672 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2674 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2677 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2689 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2691 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2693 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2703 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2707 },
        { "length", 22 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2730 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2738 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2741 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2748 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2749 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2750 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2753 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2759 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2761 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2763 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2765 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2768 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2784 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2786 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2790 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 2801 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 2817 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2818 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2821 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2831 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2835 },
        { "length", 22 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2858 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2866 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2869 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2876 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2877 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2878 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2879 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2880 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2881 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2887 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2891 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2893 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2902 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2903 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 2908 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2911 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2914 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2918 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 2928 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 2929 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2930 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 2946 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 2947 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2949 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2958 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2962 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2969 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2972 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2974 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2979 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2984 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 2990 },
        { "length", 12 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3006 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3008 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3009 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3014 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3018 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3021 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3024 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3031 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3046 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 3056 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 3059 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3065 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 3066 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3073 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3077 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3086 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3090 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3114 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3125 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3133 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3134 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3137 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3142 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3146 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3157 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3160 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3168 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3170 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3174 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 3192 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 3199 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3202 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3205 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3214 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3218 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3242 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3253 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3260 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3261 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3262 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3263 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3264 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3270 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3271 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3274 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3276 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3285 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3294 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3296 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3298 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3302 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 3313 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3330 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3333 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3342 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3346 },
        { "length", 41 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3389 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3390 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3393 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3398 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3402 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3405 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3406 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3415 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3424 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3426 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3430 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 3440 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 3449 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3450 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3458 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3461 },
        { "length", 18 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3482 },
        { "length", 24 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3507 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3517 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3520 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3530 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3535 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3538 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3542 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3544 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3570 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3572 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 3585 },
        { "length", 48 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3633 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3634 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3636 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3647 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 3648 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3654 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 3655 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3663 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 3664 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 3674 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 3713 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3716 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3719 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3722 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3725 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3732 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3737 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3745 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3749 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3751 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3754 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3757 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3761 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3762 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3764 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3771 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3773 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3776 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3782 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 3784 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3792 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 3804 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3840 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3841 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3844 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 3859 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3864 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3866 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3872 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 3882 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 3892 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3893 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3894 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3895 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3896 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 3897 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3898 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 3899 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 3900 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 3901 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 3902 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3904 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3913 },
        { "length", 36 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3953 },
        { "length", 14 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3967 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 3968 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3973 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 3974 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3976 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 3981 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 3993 },
        { "length", 36 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4030 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 4038 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4039 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 4046 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 4048 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 4053 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 4057 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 4096 },
        { "length", 43 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4139 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4141 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4145 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4146 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4152 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4153 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4155 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4157 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4159 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4160 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 4170 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 4176 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4182 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4184 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4186 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4190 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4193 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4194 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4197 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4199 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4206 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4209 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4213 },
        { "length", 13 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4226 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4227 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4229 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4231 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4237 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4238 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4239 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4240 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 4250 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 4253 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4254 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 4256 },
        { "length", 38 },
        { "convRule", Data_Char_Unicode_Internal::rule115() }
    }, dict_t{
        { "start", 4304 },
        { "length", 43 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4347 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 4348 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 4352 },
        { "length", 329 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4682 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4688 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4696 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4698 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4704 },
        { "length", 41 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4746 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4752 },
        { "length", 33 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4786 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4792 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4800 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4802 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4808 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4824 },
        { "length", 57 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4882 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4888 },
        { "length", 67 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 4957 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 4960 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 4961 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 4969 },
        { "length", 20 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 4992 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5008 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 5024 },
        { "length", 85 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5120 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 5121 },
        { "length", 620 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5741 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 5743 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5760 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 5761 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5787 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 5788 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 5792 },
        { "length", 75 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5867 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 5870 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 5888 },
        { "length", 13 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5902 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5906 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 5920 },
        { "length", 18 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5938 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 5941 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 5952 },
        { "length", 18 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5970 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 5984 },
        { "length", 13 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 5998 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6002 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6016 },
        { "length", 52 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6068 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 6070 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6071 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6078 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6086 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6087 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6089 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6100 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 6103 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 6104 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 6107 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 6108 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6109 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6112 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 6128 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 6144 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 6150 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 6151 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 6155 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6158 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 6160 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 6176 },
        { "length", 35 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6211 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 6212 },
        { "length", 52 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6272 },
        { "length", 41 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6313 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6314 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6320 },
        { "length", 70 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6400 },
        { "length", 29 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6432 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6435 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6439 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6441 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6448 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6450 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6451 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6457 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6464 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 6468 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 6470 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 6480 },
        { "length", 30 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6512 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6528 },
        { "length", 44 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6576 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6593 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6600 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6608 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 6618 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 6622 },
        { "length", 34 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 6656 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6679 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6681 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6686 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 6688 },
        { "length", 53 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6741 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6742 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6743 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6744 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6752 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6753 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6754 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6755 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6757 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6765 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6771 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6783 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6784 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 6800 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 6816 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 6823 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 6824 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 6912 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6916 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6917 },
        { "length", 47 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6964 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6965 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6966 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6971 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6972 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6973 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6978 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 6979 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 6981 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 6992 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 7002 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 7009 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 7019 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7028 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 7040 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7042 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7043 },
        { "length", 30 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 7073 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7074 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7078 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7080 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7082 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7086 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 7088 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 7104 },
        { "length", 38 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 7142 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7143 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7144 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7146 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7149 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7150 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7151 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7154 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7164 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 7168 },
        { "length", 36 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 7204 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7212 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7220 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7222 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7227 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 7232 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 7245 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 7248 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 7258 },
        { "length", 30 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 7288 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 7294 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 7376 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7379 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 7380 },
        { "length", 13 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7393 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7394 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7401 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 7405 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7406 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 7410 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 7424 },
        { "length", 44 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 7468 },
        { "length", 54 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 7522 },
        { "length", 22 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 7544 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 7545 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule117() }
    }, dict_t{
        { "start", 7546 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 7549 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule118() }
    }, dict_t{
        { "start", 7550 },
        { "length", 29 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 7579 },
        { "length", 37 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 7616 },
        { "length", 39 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7676 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 7680 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7681 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7682 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7683 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7684 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7685 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7686 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7687 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7688 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7689 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7690 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7691 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7692 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7693 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7694 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7695 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7696 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7697 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7698 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7699 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7700 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7701 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7702 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7703 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7704 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7705 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7706 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7707 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7708 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7709 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7710 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7711 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7712 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7713 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7714 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7715 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7716 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7717 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7718 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7719 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7720 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7721 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7722 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7723 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7724 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7725 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7726 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7727 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7728 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7729 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7730 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7731 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7732 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7733 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7734 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7735 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7736 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7737 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7738 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7739 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7740 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7741 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7742 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7743 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7744 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7745 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7746 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7747 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7748 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7749 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7750 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7751 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7752 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7753 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7754 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7755 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7756 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7757 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7758 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7759 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7760 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7761 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7762 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7763 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7764 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7765 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7766 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7767 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7768 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7769 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7770 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7771 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7772 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7773 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7774 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7775 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7776 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7777 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7778 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7779 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7780 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7781 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7782 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7783 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7784 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7785 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7786 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7787 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7788 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7789 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7790 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7791 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7792 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7793 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7794 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7795 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7796 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7797 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7798 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7799 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7800 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7801 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7802 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7803 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7804 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7805 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7806 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7807 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7808 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7809 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7810 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7811 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7812 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7813 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7814 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7815 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7816 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7817 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7818 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7819 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7820 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7821 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7822 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7823 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7824 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7825 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7826 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7827 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7828 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7829 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7830 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 7835 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule119() }
    }, dict_t{
        { "start", 7836 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 7838 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule120() }
    }, dict_t{
        { "start", 7839 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 7840 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7841 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7842 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7843 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7844 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7845 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7846 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7847 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7848 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7849 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7850 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7851 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7852 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7853 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7854 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7855 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7856 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7857 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7858 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7859 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7860 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7861 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7862 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7863 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7864 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7865 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7866 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7867 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7868 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7869 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7870 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7871 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7872 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7873 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7874 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7875 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7876 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7877 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7878 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7879 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7880 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7881 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7882 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7883 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7884 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7885 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7886 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7887 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7888 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7889 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7890 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7891 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7892 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7893 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7894 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7895 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7896 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7897 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7898 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7899 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7900 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7901 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7902 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7903 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7904 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7905 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7906 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7907 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7908 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7909 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7910 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7911 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7912 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7913 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7914 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7915 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7916 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7917 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7918 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7919 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7920 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7921 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7922 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7923 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7924 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7925 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7926 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7927 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7928 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7929 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7930 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7931 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7932 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7933 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7934 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 7935 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 7936 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 7944 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 7952 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 7960 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 7968 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 7976 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 7984 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 7992 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8000 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8008 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8016 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8017 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8018 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8019 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8020 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8021 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8022 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8023 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8025 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8027 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8029 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8031 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8032 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8040 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8048 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule123() }
    }, dict_t{
        { "start", 8050 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule124() }
    }, dict_t{
        { "start", 8054 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule125() }
    }, dict_t{
        { "start", 8056 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule126() }
    }, dict_t{
        { "start", 8058 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule127() }
    }, dict_t{
        { "start", 8060 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule128() }
    }, dict_t{
        { "start", 8064 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8072 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule129() }
    }, dict_t{
        { "start", 8080 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8088 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule129() }
    }, dict_t{
        { "start", 8096 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8104 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule129() }
    }, dict_t{
        { "start", 8112 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8114 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8115 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule130() }
    }, dict_t{
        { "start", 8116 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8118 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8120 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8122 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule131() }
    }, dict_t{
        { "start", 8124 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule132() }
    }, dict_t{
        { "start", 8125 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 8126 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule133() }
    }, dict_t{
        { "start", 8127 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 8130 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8131 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule130() }
    }, dict_t{
        { "start", 8132 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8134 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8136 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule134() }
    }, dict_t{
        { "start", 8140 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule132() }
    }, dict_t{
        { "start", 8141 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 8144 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8146 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8150 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8152 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8154 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule135() }
    }, dict_t{
        { "start", 8157 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 8160 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule121() }
    }, dict_t{
        { "start", 8162 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8165 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule104() }
    }, dict_t{
        { "start", 8166 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8168 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule122() }
    }, dict_t{
        { "start", 8170 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule136() }
    }, dict_t{
        { "start", 8172 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule107() }
    }, dict_t{
        { "start", 8173 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 8178 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8179 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule130() }
    }, dict_t{
        { "start", 8180 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8182 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8184 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule137() }
    }, dict_t{
        { "start", 8186 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule138() }
    }, dict_t{
        { "start", 8188 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule132() }
    }, dict_t{
        { "start", 8189 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 8192 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 8203 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 8208 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 8214 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 8216 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 8217 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 8218 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 8219 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 8221 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 8222 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 8223 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 8224 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 8232 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule139() }
    }, dict_t{
        { "start", 8233 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule140() }
    }, dict_t{
        { "start", 8234 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 8239 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 8240 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 8249 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 8250 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 8251 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 8255 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule11() }
    }, dict_t{
        { "start", 8257 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 8260 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8261 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 8262 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 8263 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 8274 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8275 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 8276 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule11() }
    }, dict_t{
        { "start", 8277 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 8287 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 8288 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 8298 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 8304 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 8305 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 8308 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 8314 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8317 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 8318 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 8319 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 8320 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 8330 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8333 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 8334 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 8336 },
        { "length", 13 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 8352 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 8400 },
        { "length", 13 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 8413 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule109() }
    }, dict_t{
        { "start", 8417 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 8418 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule109() }
    }, dict_t{
        { "start", 8421 },
        { "length", 12 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 8448 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8450 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8451 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8455 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8456 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8458 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8459 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8462 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8464 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8467 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8468 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8469 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8470 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8472 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8473 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8478 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8484 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8485 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8486 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule141() }
    }, dict_t{
        { "start", 8487 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8488 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8489 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8490 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule142() }
    }, dict_t{
        { "start", 8491 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule143() }
    }, dict_t{
        { "start", 8492 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8494 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8495 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8496 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8498 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule144() }
    }, dict_t{
        { "start", 8499 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8500 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8501 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 8505 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8506 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8508 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8510 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8512 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8517 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 8518 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 8522 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8523 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8524 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8526 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule145() }
    }, dict_t{
        { "start", 8527 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8528 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 8544 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule146() }
    }, dict_t{
        { "start", 8560 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule147() }
    }, dict_t{
        { "start", 8576 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 8579 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 8580 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 8581 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 8585 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 8592 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8597 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8602 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8604 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8608 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8609 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8611 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8612 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8614 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8615 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8622 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8623 },
        { "length", 31 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8654 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8656 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8658 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8659 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8660 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8661 },
        { "length", 31 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8692 },
        { "length", 268 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8960 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8968 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8972 },
        { "length", 20 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 8992 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 8994 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9001 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 9002 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 9003 },
        { "length", 81 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9084 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 9085 },
        { "length", 30 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9115 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 9140 },
        { "length", 40 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9180 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 9186 },
        { "length", 18 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9216 },
        { "length", 39 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9280 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9312 },
        { "length", 60 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 9372 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9398 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule148() }
    }, dict_t{
        { "start", 9424 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule149() }
    }, dict_t{
        { "start", 9450 },
        { "length", 22 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 9472 },
        { "length", 183 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9655 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 9656 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9665 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 9666 },
        { "length", 54 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9720 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 9728 },
        { "length", 111 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9839 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 9840 },
        { "length", 144 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 9985 },
        { "length", 103 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 10088 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10089 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10090 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10091 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10092 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10093 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10094 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10095 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10096 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10097 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10098 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10099 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10100 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10101 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10102 },
        { "length", 30 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 10132 },
        { "length", 44 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 10176 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 10181 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10182 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10183 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 10188 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 10190 },
        { "length", 24 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 10214 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10215 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10216 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10217 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10218 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10219 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10220 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10221 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10222 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10223 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10224 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 10240 },
        { "length", 256 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 10496 },
        { "length", 131 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 10627 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10628 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10629 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10630 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10631 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10632 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10633 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10634 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10635 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10636 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10637 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10638 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10639 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10640 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10641 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10642 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10643 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10644 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10645 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10646 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10647 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10648 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10649 },
        { "length", 63 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 10712 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10713 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10714 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10715 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10716 },
        { "length", 32 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 10748 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 10749 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 10750 },
        { "length", 258 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 11008 },
        { "length", 48 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 11056 },
        { "length", 21 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 11077 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 11079 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 11088 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 11264 },
        { "length", 47 },
        { "convRule", Data_Char_Unicode_Internal::rule112() }
    }, dict_t{
        { "start", 11312 },
        { "length", 47 },
        { "convRule", Data_Char_Unicode_Internal::rule113() }
    }, dict_t{
        { "start", 11360 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11361 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11362 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule150() }
    }, dict_t{
        { "start", 11363 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule151() }
    }, dict_t{
        { "start", 11364 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule152() }
    }, dict_t{
        { "start", 11365 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule153() }
    }, dict_t{
        { "start", 11366 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule154() }
    }, dict_t{
        { "start", 11367 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11368 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11369 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11370 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11371 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11372 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11373 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule155() }
    }, dict_t{
        { "start", 11374 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule156() }
    }, dict_t{
        { "start", 11375 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule157() }
    }, dict_t{
        { "start", 11376 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule158() }
    }, dict_t{
        { "start", 11377 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 11378 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11379 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11380 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 11381 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11382 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11383 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 11389 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 11390 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule159() }
    }, dict_t{
        { "start", 11392 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11393 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11394 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11395 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11396 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11397 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11398 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11399 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11400 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11401 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11402 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11403 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11404 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11405 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11406 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11407 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11408 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11409 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11410 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11411 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11412 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11413 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11414 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11415 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11416 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11417 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11418 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11419 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11420 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11421 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11422 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11423 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11424 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11425 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11426 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11427 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11428 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11429 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11430 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11431 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11432 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11433 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11434 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11435 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11436 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11437 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11438 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11439 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11440 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11441 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11442 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11443 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11444 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11445 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11446 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11447 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11448 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11449 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11450 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11451 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11452 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11453 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11454 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11455 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11456 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11457 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11458 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11459 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11460 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11461 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11462 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11463 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11464 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11465 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11466 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11467 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11468 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11469 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11470 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11471 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11472 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11473 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11474 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11475 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11476 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11477 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11478 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11479 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11480 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11481 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11482 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11483 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11484 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11485 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11486 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11487 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11488 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11489 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11490 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11491 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11492 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 11493 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 11499 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11500 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11501 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 11502 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 11503 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 11513 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11517 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 11518 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11520 },
        { "length", 38 },
        { "convRule", Data_Char_Unicode_Internal::rule160() }
    }, dict_t{
        { "start", 11568 },
        { "length", 54 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11631 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 11632 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11647 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 11648 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11680 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11688 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11696 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11704 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11712 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11720 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11728 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11736 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 11744 },
        { "length", 32 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 11776 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11778 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 11779 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 11780 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 11781 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 11782 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11785 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 11786 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 11787 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11788 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 11789 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 11790 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11799 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 11800 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11802 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 11803 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11804 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 11805 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 11806 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11808 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule15() }
    }, dict_t{
        { "start", 11809 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule19() }
    }, dict_t{
        { "start", 11810 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 11811 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 11812 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 11813 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 11814 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 11815 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 11816 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 11817 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 11818 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11823 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 11824 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 11904 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 11931 },
        { "length", 89 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12032 },
        { "length", 214 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12272 },
        { "length", 12 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12288 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule1() }
    }, dict_t{
        { "start", 12289 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 12292 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12293 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 12294 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12295 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 12296 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12297 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12298 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12299 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12300 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12301 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12302 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12303 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12304 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12305 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12306 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12308 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12309 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12310 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12311 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12312 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12313 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12314 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12315 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12316 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 12317 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 12318 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 12320 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12321 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 12330 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 12336 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 12337 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 12342 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12344 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 12347 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 12348 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12349 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 12350 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12353 },
        { "length", 86 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12441 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 12443 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 12445 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 12447 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12448 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 12449 },
        { "length", 90 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12539 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 12540 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 12543 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12549 },
        { "length", 41 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12593 },
        { "length", 94 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12688 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12690 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 12694 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12704 },
        { "length", 27 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12736 },
        { "length", 36 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12784 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 12800 },
        { "length", 31 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12832 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 12842 },
        { "length", 39 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12881 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 12896 },
        { "length", 32 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12928 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 12938 },
        { "length", 39 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 12977 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 12992 },
        { "length", 63 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 13056 },
        { "length", 256 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 13312 },
        { "length", 6582 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 19904 },
        { "length", 64 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 19968 },
        { "length", 20940 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 40960 },
        { "length", 21 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 40981 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 40982 },
        { "length", 1143 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 42128 },
        { "length", 55 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 42192 },
        { "length", 40 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 42232 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 42238 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 42240 },
        { "length", 268 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 42508 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 42509 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 42512 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 42528 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 42538 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 42560 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42561 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42562 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42563 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42564 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42565 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42566 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42567 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42568 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42569 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42570 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42571 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42572 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42573 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42574 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42575 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42576 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42577 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42578 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42579 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42580 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42581 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42582 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42583 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42584 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42585 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42586 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42587 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42588 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42589 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42590 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42591 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42592 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42593 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42594 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42595 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42596 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42597 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42598 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42599 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42600 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42601 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42602 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42603 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42604 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42605 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42606 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 42607 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 42608 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule109() }
    }, dict_t{
        { "start", 42611 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 42620 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 42622 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 42623 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 42624 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42625 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42626 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42627 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42628 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42629 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42630 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42631 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42632 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42633 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42634 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42635 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42636 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42637 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42638 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42639 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42640 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42641 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42642 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42643 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42644 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42645 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42646 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42647 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42656 },
        { "length", 70 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 42726 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 42736 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 42738 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 42752 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 42775 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 42784 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 42786 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42787 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42788 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42789 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42790 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42791 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42792 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42793 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42794 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42795 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42796 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42797 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42798 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42799 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42800 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 42802 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42803 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42804 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42805 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42806 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42807 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42808 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42809 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42810 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42811 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42812 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42813 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42814 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42815 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42816 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42817 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42818 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42819 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42820 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42821 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42822 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42823 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42824 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42825 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42826 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42827 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42828 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42829 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42830 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42831 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42832 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42833 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42834 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42835 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42836 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42837 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42838 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42839 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42840 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42841 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42842 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42843 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42844 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42845 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42846 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42847 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42848 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42849 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42850 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42851 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42852 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42853 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42854 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42855 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42856 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42857 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42858 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42859 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42860 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42861 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42862 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42863 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42864 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 42865 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 42873 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42874 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42875 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42876 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42877 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule161() }
    }, dict_t{
        { "start", 42878 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42879 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42880 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42881 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42882 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42883 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42884 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42885 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42886 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42887 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42888 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 42889 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 42891 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42892 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42893 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule162() }
    }, dict_t{
        { "start", 42894 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 42896 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42897 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42912 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42913 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42914 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42915 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42916 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42917 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42918 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42919 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 42920 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule21() }
    }, dict_t{
        { "start", 42921 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule22() }
    }, dict_t{
        { "start", 43002 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 43003 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43010 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43011 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43014 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43015 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43019 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43020 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43043 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43045 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43047 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43048 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 43056 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 43062 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 43064 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 43065 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 43072 },
        { "length", 52 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43124 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43136 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43138 },
        { "length", 50 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43188 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43204 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43214 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43216 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 43232 },
        { "length", 18 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43250 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43256 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43259 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43264 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 43274 },
        { "length", 28 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43302 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43310 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43312 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43335 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43346 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43359 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43360 },
        { "length", 29 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43392 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43395 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43396 },
        { "length", 47 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43443 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43444 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43446 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43450 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43452 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43453 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43457 },
        { "length", 13 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43471 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 43472 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 43486 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43520 },
        { "length", 41 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43561 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43567 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43569 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43571 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43573 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43584 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43587 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43588 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43596 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43597 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43600 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 43612 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43616 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43632 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 43633 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43639 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 43642 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43643 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 43648 },
        { "length", 48 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43696 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43697 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43698 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43701 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43703 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43705 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43710 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43712 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43713 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 43714 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43739 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43741 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 43742 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 43777 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43785 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43793 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43808 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43816 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 43968 },
        { "length", 35 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 44003 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 44005 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 44006 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 44008 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 44009 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 44011 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 44012 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 44013 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 44016 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 44032 },
        { "length", 11172 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 55216 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 55243 },
        { "length", 49 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 55296 },
        { "length", 896 },
        { "convRule", Data_Char_Unicode_Internal::rule163() }
    }, dict_t{
        { "start", 56192 },
        { "length", 128 },
        { "convRule", Data_Char_Unicode_Internal::rule163() }
    }, dict_t{
        { "start", 56320 },
        { "length", 1024 },
        { "convRule", Data_Char_Unicode_Internal::rule163() }
    }, dict_t{
        { "start", 57344 },
        { "length", 6400 },
        { "convRule", Data_Char_Unicode_Internal::rule164() }
    }, dict_t{
        { "start", 63744 },
        { "length", 302 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64048 },
        { "length", 62 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64112 },
        { "length", 106 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64256 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 64275 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 64285 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64286 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 64287 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64297 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 64298 },
        { "length", 13 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64312 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64318 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64320 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64323 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64326 },
        { "length", 108 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64434 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 64467 },
        { "length", 363 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64830 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 64831 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 64848 },
        { "length", 64 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 64914 },
        { "length", 54 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65008 },
        { "length", 12 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65020 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 65021 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 65024 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 65040 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65047 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65048 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65049 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65056 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 65072 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65073 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 65075 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule11() }
    }, dict_t{
        { "start", 65077 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65078 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65079 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65080 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65081 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65082 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65083 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65084 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65085 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65086 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65087 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65088 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65089 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65090 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65091 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65092 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65093 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65095 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65096 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65097 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65101 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule11() }
    }, dict_t{
        { "start", 65104 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65108 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65112 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 65113 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65114 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65115 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65116 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65117 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65118 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65119 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65122 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 65123 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 65124 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 65128 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65129 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 65130 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65136 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65142 },
        { "length", 135 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65279 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 65281 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65284 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 65285 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65288 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65289 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65290 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65291 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 65292 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65293 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule7() }
    }, dict_t{
        { "start", 65294 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65296 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 65306 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65308 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 65311 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65313 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule9() }
    }, dict_t{
        { "start", 65339 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65340 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65341 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65342 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 65343 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule11() }
    }, dict_t{
        { "start", 65344 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 65345 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule12() }
    }, dict_t{
        { "start", 65371 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65372 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 65373 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65374 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 65375 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65376 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65377 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65378 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule4() }
    }, dict_t{
        { "start", 65379 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule5() }
    }, dict_t{
        { "start", 65380 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65382 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65392 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 65393 },
        { "length", 45 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65438 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule83() }
    }, dict_t{
        { "start", 65440 },
        { "length", 31 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65474 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65482 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65490 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65498 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65504 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 65506 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 65507 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule10() }
    }, dict_t{
        { "start", 65508 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 65509 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule3() }
    }, dict_t{
        { "start", 65512 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 65513 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 65517 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 65529 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 65532 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 65536 },
        { "length", 12 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65549 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65576 },
        { "length", 19 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65596 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65599 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65616 },
        { "length", 14 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65664 },
        { "length", 123 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 65792 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 65794 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 65799 },
        { "length", 45 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 65847 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 65856 },
        { "length", 53 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 65909 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 65913 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 65930 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 65936 },
        { "length", 12 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 66000 },
        { "length", 45 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 66045 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 66176 },
        { "length", 29 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 66208 },
        { "length", 49 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 66304 },
        { "length", 31 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 66336 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 66352 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 66369 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 66370 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 66378 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 66432 },
        { "length", 30 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 66463 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 66464 },
        { "length", 36 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 66504 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 66512 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 66513 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 66560 },
        { "length", 40 },
        { "convRule", Data_Char_Unicode_Internal::rule165() }
    }, dict_t{
        { "start", 66600 },
        { "length", 40 },
        { "convRule", Data_Char_Unicode_Internal::rule166() }
    }, dict_t{
        { "start", 66640 },
        { "length", 78 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 66720 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 67584 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 67592 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 67594 },
        { "length", 44 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 67639 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 67644 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 67647 },
        { "length", 23 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 67671 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 67672 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 67840 },
        { "length", 22 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 67862 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 67871 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 67872 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 67903 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 68096 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 68097 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 68101 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 68108 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 68112 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 68117 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 68121 },
        { "length", 27 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 68152 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 68159 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 68160 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 68176 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 68192 },
        { "length", 29 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 68221 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 68223 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 68352 },
        { "length", 54 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 68409 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 68416 },
        { "length", 22 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 68440 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 68448 },
        { "length", 19 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 68472 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 68608 },
        { "length", 73 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 69216 },
        { "length", 31 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 69632 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 69633 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 69634 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 69635 },
        { "length", 53 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 69688 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 69703 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 69714 },
        { "length", 20 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 69734 },
        { "length", 10 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 69760 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 69762 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 69763 },
        { "length", 45 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 69808 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 69811 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 69815 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 69817 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 69819 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 69821 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 69822 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 73728 },
        { "length", 879 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 74752 },
        { "length", 99 },
        { "convRule", Data_Char_Unicode_Internal::rule116() }
    }, dict_t{
        { "start", 74864 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule2() }
    }, dict_t{
        { "start", 77824 },
        { "length", 1071 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 92160 },
        { "length", 569 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 110592 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 118784 },
        { "length", 246 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119040 },
        { "length", 39 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119081 },
        { "length", 60 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119141 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 119143 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 119146 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119149 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule114() }
    }, dict_t{
        { "start", 119155 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 119163 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 119171 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119173 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 119180 },
        { "length", 30 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119210 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 119214 },
        { "length", 48 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119296 },
        { "length", 66 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119362 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 119365 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119552 },
        { "length", 87 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 119648 },
        { "length", 18 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 119808 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 119834 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 119860 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 119886 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 119894 },
        { "length", 18 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 119912 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 119938 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 119964 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 119966 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 119970 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 119973 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 119977 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 119982 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 119990 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 119995 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 119997 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120005 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120016 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120042 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120068 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120071 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120077 },
        { "length", 8 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120086 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120094 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120120 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120123 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120128 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120134 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120138 },
        { "length", 7 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120146 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120172 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120198 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120224 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120250 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120276 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120302 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120328 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120354 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120380 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120406 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120432 },
        { "length", 26 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120458 },
        { "length", 28 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120488 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120513 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120514 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120539 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120540 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120546 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120571 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120572 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120597 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120598 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120604 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120629 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120630 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120655 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120656 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120662 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120687 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120688 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120713 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120714 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120720 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120745 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120746 },
        { "length", 25 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120771 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule6() }
    }, dict_t{
        { "start", 120772 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120778 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule98() }
    }, dict_t{
        { "start", 120779 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule14() }
    }, dict_t{
        { "start", 120782 },
        { "length", 50 },
        { "convRule", Data_Char_Unicode_Internal::rule8() }
    }, dict_t{
        { "start", 126976 },
        { "length", 44 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127024 },
        { "length", 100 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127136 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127153 },
        { "length", 14 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127169 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127185 },
        { "length", 15 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127232 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule17() }
    }, dict_t{
        { "start", 127248 },
        { "length", 31 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127280 },
        { "length", 58 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127344 },
        { "length", 43 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127462 },
        { "length", 29 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127504 },
        { "length", 43 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127552 },
        { "length", 9 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127568 },
        { "length", 2 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127744 },
        { "length", 33 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127792 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127799 },
        { "length", 70 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127872 },
        { "length", 20 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127904 },
        { "length", 37 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127942 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 127968 },
        { "length", 17 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128000 },
        { "length", 63 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128064 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128066 },
        { "length", 182 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128249 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128256 },
        { "length", 62 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128336 },
        { "length", 24 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128507 },
        { "length", 5 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128513 },
        { "length", 16 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128530 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128534 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128536 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128538 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128540 },
        { "length", 3 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128544 },
        { "length", 6 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128552 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128557 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128560 },
        { "length", 4 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128565 },
        { "length", 12 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128581 },
        { "length", 11 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128640 },
        { "length", 70 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 128768 },
        { "length", 116 },
        { "convRule", Data_Char_Unicode_Internal::rule13() }
    }, dict_t{
        { "start", 131072 },
        { "length", 42711 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 173824 },
        { "length", 4149 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 177984 },
        { "length", 222 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 194560 },
        { "length", 542 },
        { "convRule", Data_Char_Unicode_Internal::rule45() }
    }, dict_t{
        { "start", 917505 },
        { "length", 1 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 917536 },
        { "length", 96 },
        { "convRule", Data_Char_Unicode_Internal::rule16() }
    }, dict_t{
        { "start", 917760 },
        { "length", 240 },
        { "convRule", Data_Char_Unicode_Internal::rule84() }
    }, dict_t{
        { "start", 983040 },
        { "length", 65534 },
        { "convRule", Data_Char_Unicode_Internal::rule164() }
    }, dict_t{
        { "start", 1048576 },
        { "length", 65534 },
        { "convRule", Data_Char_Unicode_Internal::rule164() }
    } };
    return _;
};
auto checkAttr() -> const boxed& {
    static const boxed _ = [](const boxed& categories) -> boxed {
        return [=](const boxed& _char_) -> boxed {
            boxed numOfBlocks = [=]() -> boxed {
                boxed _Local_22 = Data_Ord::lessThan()(Data_Ord::ordInt())(_char_)(256);
                if (unbox<bool>(_Local_22)) {
                    return Data_Char_Unicode_Internal::numLat1Blocks();
                };
                return Data_Char_Unicode_Internal::numBlocks();
            }();
            boxed maybeConversionRule = Data_Char_Unicode_Internal::getRule()(Data_Char_Unicode_Internal::allchars())(_char_)(numOfBlocks);
            if (unbox<dict_t>(maybeConversionRule).contains("Nothing")) {
                return false;
            };
            if (unbox<dict_t>(maybeConversionRule).contains("Just")) {
                return Data_Maybe::isJust()(Data_Array::elemIndex()(Data_Eq::eqInt())(maybeConversionRule["value0"]["category"])(categories));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Char.Unicode.Internal (line 4800, column 8 - line 4802, column 92): ");
        };
    };
    return _;
};
auto uIswalnum() -> boxed {
    return Data_Char_Unicode_Internal::checkAttr()(array_t{ Data_Char_Unicode_Internal::gencatLT(), Data_Char_Unicode_Internal::gencatLU(), Data_Char_Unicode_Internal::gencatLL(), Data_Char_Unicode_Internal::gencatLM(), Data_Char_Unicode_Internal::gencatLO(), Data_Char_Unicode_Internal::gencatMC(), Data_Char_Unicode_Internal::gencatME(), Data_Char_Unicode_Internal::gencatMN(), Data_Char_Unicode_Internal::gencatNO(), Data_Char_Unicode_Internal::gencatND(), Data_Char_Unicode_Internal::gencatNL() });
};
auto uIswalpha() -> boxed {
    return Data_Char_Unicode_Internal::checkAttr()(array_t{ Data_Char_Unicode_Internal::gencatLL(), Data_Char_Unicode_Internal::gencatLU(), Data_Char_Unicode_Internal::gencatLT(), Data_Char_Unicode_Internal::gencatLM(), Data_Char_Unicode_Internal::gencatLO() });
};
auto uIswcntrl() -> boxed {
    return Data_Char_Unicode_Internal::checkAttr()(array_t{ Data_Char_Unicode_Internal::gencatCC() });
};
auto uIswdigit() -> boxed {
    return Data_Char_Unicode_Internal::checkAttr()(array_t{ Data_Char_Unicode_Internal::gencatND() });
};
auto uIswlower() -> boxed {
    return Data_Char_Unicode_Internal::checkAttr()(array_t{ Data_Char_Unicode_Internal::gencatLL() });
};
auto uIswprint() -> boxed {
    return Data_Char_Unicode_Internal::checkAttr()(array_t{ Data_Char_Unicode_Internal::gencatMC(), Data_Char_Unicode_Internal::gencatNO(), Data_Char_Unicode_Internal::gencatSK(), Data_Char_Unicode_Internal::gencatME(), Data_Char_Unicode_Internal::gencatND(), Data_Char_Unicode_Internal::gencatPO(), Data_Char_Unicode_Internal::gencatLT(), Data_Char_Unicode_Internal::gencatPC(), Data_Char_Unicode_Internal::gencatSM(), Data_Char_Unicode_Internal::gencatZS(), Data_Char_Unicode_Internal::gencatLU(), Data_Char_Unicode_Internal::gencatPD(), Data_Char_Unicode_Internal::gencatSO(), Data_Char_Unicode_Internal::gencatPE(), Data_Char_Unicode_Internal::gencatPF(), Data_Char_Unicode_Internal::gencatPS(), Data_Char_Unicode_Internal::gencatSC(), Data_Char_Unicode_Internal::gencatLL(), Data_Char_Unicode_Internal::gencatLM(), Data_Char_Unicode_Internal::gencatPI(), Data_Char_Unicode_Internal::gencatNL(), Data_Char_Unicode_Internal::gencatMN(), Data_Char_Unicode_Internal::gencatLO() });
};
auto uIswupper() -> boxed {
    return Data_Char_Unicode_Internal::checkAttr()(array_t{ Data_Char_Unicode_Internal::gencatLU(), Data_Char_Unicode_Internal::gencatLT() });
};
auto uGencat() -> const boxed& {
    static const boxed _ = [](const boxed& _char_) -> boxed {
        boxed conversionRule = Data_Char_Unicode_Internal::getRule()(Data_Char_Unicode_Internal::allchars())(_char_)(Data_Char_Unicode_Internal::numBlocks());
        return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v) -> boxed {
            return v["unicodeCat"];
        })(conversionRule);
    };
    return _;
};


} // end namespace Data_Char_Unicode_Internal


