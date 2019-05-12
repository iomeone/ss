#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"
#include "Data_Void/Data_Void.h"
#include "Record_Unsafe/Record_Unsafe.h"
#include "Type_Data_RowList/Type_Data_RowList.h"

#include "Data_Eq/Data_Eq.h"


namespace Data_Eq {

auto Eq() -> const boxed& {
    static const boxed _ = [](const boxed& eq) -> boxed {
        return dict_t{
            { "eq", eq }
        };
    };
    return _;
};
auto Eq1() -> const boxed& {
    static const boxed _ = [](const boxed& eq1) -> boxed {
        return dict_t{
            { "eq1", eq1 }
        };
    };
    return _;
};
auto EqRecord() -> const boxed& {
    static const boxed _ = [](const boxed& eqRecord) -> boxed {
        return dict_t{
            { "eqRecord", eqRecord }
        };
    };
    return _;
};
auto eqVoid() -> boxed {
    return Data_Eq::Eq()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return true;
        };
    });
};
auto eqUnit() -> boxed {
    return Data_Eq::Eq()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return true;
        };
    });
};
auto eqString() -> boxed {
    return Data_Eq::Eq()(Data_Eq::eqStringImpl());
};
auto eqRowNil() -> boxed {
    return Data_Eq::EqRecord()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                return true;
            };
        };
    });
};
auto eqRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["eqRecord"];
    };
    return _;
};
auto eqRec() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictEqRecord) -> boxed {
            return Data_Eq::Eq()(Data_Eq::eqRecord()(dictEqRecord)(Type_Data_RowList::RLProxy()));
        };
    };
    return _;
};
auto eqNumber() -> boxed {
    return Data_Eq::Eq()(Data_Eq::eqNumberImpl());
};
auto eqInt() -> boxed {
    return Data_Eq::Eq()(Data_Eq::eqIntImpl());
};
auto eqChar() -> boxed {
    return Data_Eq::Eq()(Data_Eq::eqCharImpl());
};
auto eqBoolean() -> boxed {
    return Data_Eq::Eq()(Data_Eq::eqBooleanImpl());
};
auto eq1() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["eq1"];
    };
    return _;
};
auto eq() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["eq"];
    };
    return _;
};
auto eqArray() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return Data_Eq::Eq()(Data_Eq::eqArrayImpl()(Data_Eq::eq()(dictEq)));
    };
    return _;
};
auto eq1Array() -> boxed {
    return Data_Eq::Eq1()([=](const boxed& dictEq) -> boxed {
        return Data_Eq::eq()(Data_Eq::eqArray()(dictEq));
    });
};
auto eqRowCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictEqRecord) -> boxed {
        return [=](const boxed& dictCons) -> boxed {
            return [=](const boxed& dictIsSymbol) -> boxed {
                return [=](const boxed& dictEq) -> boxed {
                    return Data_Eq::EqRecord()([=](const boxed& v) -> boxed {
                        return [=](const boxed& ra) -> boxed {
                            return [=](const boxed& rb) -> boxed {
                                boxed tail = Data_Eq::eqRecord()(dictEqRecord)(Type_Data_RowList::RLProxy())(ra)(rb);
                                boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                                boxed get = Record_Unsafe::unsafeGet()(key);
                                return unbox<bool>(Data_Eq::eq()(dictEq)(get(ra))(get(rb))) && unbox<bool>(tail);
                            };
                        };
                    });
                };
            };
        };
    };
    return _;
};
auto notEq() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                return Data_Eq::eq()(Data_Eq::eqBoolean())(Data_Eq::eq()(dictEq)(x)(y))(false);
            };
        };
    };
    return _;
};
auto notEq1() -> const boxed& {
    static const boxed _ = [](const boxed& dictEq1) -> boxed {
        return [=](const boxed& dictEq) -> boxed {
            return [=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    return Data_Eq::eq()(Data_Eq::eqBoolean())(Data_Eq::eq1()(dictEq1)(dictEq)(x)(y))(false);
                };
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto eqBooleanImpl() -> const boxed& { static const boxed _ = foreign().at("eqBooleanImpl"); return _; };
auto eqIntImpl() -> const boxed& { static const boxed _ = foreign().at("eqIntImpl"); return _; };
auto eqNumberImpl() -> const boxed& { static const boxed _ = foreign().at("eqNumberImpl"); return _; };
auto eqCharImpl() -> const boxed& { static const boxed _ = foreign().at("eqCharImpl"); return _; };
auto eqStringImpl() -> const boxed& { static const boxed _ = foreign().at("eqStringImpl"); return _; };
auto eqArrayImpl() -> const boxed& { static const boxed _ = foreign().at("eqArrayImpl"); return _; };

} // end namespace Data_Eq


