#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"
#include "Record_Unsafe/Record_Unsafe.h"
#include "Type_Data_Row/Type_Data_Row.h"
#include "Type_Data_RowList/Type_Data_RowList.h"

#include "Data_Semiring/Data_Semiring.h"


namespace Data_Semiring {

auto Semiring() -> const boxed& {
    static const boxed _ = [](const boxed& add) -> boxed {
        return [=](const boxed& mul) -> boxed {
            return [=](const boxed& one) -> boxed {
                return [=](const boxed& zero) -> boxed {
                    return dict_t{
                        { "add", add },
                        { "mul", mul },
                        { "one", one },
                        { "zero", zero }
                    };
                };
            };
        };
    };
    return _;
};
auto SemiringRecord() -> const boxed& {
    static const boxed _ = [](const boxed& addRecord) -> boxed {
        return [=](const boxed& mulRecord) -> boxed {
            return [=](const boxed& oneRecord) -> boxed {
                return [=](const boxed& zeroRecord) -> boxed {
                    return dict_t{
                        { "addRecord", addRecord },
                        { "mulRecord", mulRecord },
                        { "oneRecord", oneRecord },
                        { "zeroRecord", zeroRecord }
                    };
                };
            };
        };
    };
    return _;
};
auto zeroRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["zeroRecord"];
    };
    return _;
};
auto zero() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["zero"];
    };
    return _;
};
auto semiringUnit() -> boxed {
    return Data_Semiring::Semiring()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Unit::unit();
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Unit::unit();
        };
    })(Data_Unit::unit())(Data_Unit::unit());
};
auto semiringRecordNil() -> boxed {
    return Data_Semiring::SemiringRecord()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                return dict_t{

                };
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                return dict_t{

                };
            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return dict_t{

            };
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return dict_t{

            };
        };
    });
};
auto semiringNumber() -> boxed {
    return Data_Semiring::Semiring()(Data_Semiring::numAdd())(Data_Semiring::numMul())(1.0)(0.0);
};
auto semiringInt() -> boxed {
    return Data_Semiring::Semiring()(Data_Semiring::intAdd())(Data_Semiring::intMul())(1)(0);
};
auto oneRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["oneRecord"];
    };
    return _;
};
auto one() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["one"];
    };
    return _;
};
auto mulRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["mulRecord"];
    };
    return _;
};
auto mul() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["mul"];
    };
    return _;
};
auto addRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["addRecord"];
    };
    return _;
};
auto semiringRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictSemiringRecord) -> boxed {
            return Data_Semiring::Semiring()(Data_Semiring::addRecord()(dictSemiringRecord)(Type_Data_RowList::RLProxy()))(Data_Semiring::mulRecord()(dictSemiringRecord)(Type_Data_RowList::RLProxy()))(Data_Semiring::oneRecord()(dictSemiringRecord)(Type_Data_RowList::RLProxy())(Type_Data_Row::RProxy()))(Data_Semiring::zeroRecord()(dictSemiringRecord)(Type_Data_RowList::RLProxy())(Type_Data_Row::RProxy()));
        };
    };
    return _;
};
auto add() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["add"];
    };
    return _;
};
auto semiringFn() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemiring) -> boxed {
        return Data_Semiring::Semiring()([=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& x) -> boxed {
                    return Data_Semiring::add()(dictSemiring)(f(x))(g(x));
                };
            };
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& x) -> boxed {
                    return Data_Semiring::mul()(dictSemiring)(f(x))(g(x));
                };
            };
        })([=](const boxed& v) -> boxed {
            return Data_Semiring::one()(dictSemiring);
        })([=](const boxed& v) -> boxed {
            return Data_Semiring::zero()(dictSemiring);
        });
    };
    return _;
};
auto semiringRecordCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictIsSymbol) -> boxed {
        return [=](const boxed& dictCons) -> boxed {
            return [=](const boxed& dictSemiringRecord) -> boxed {
                return [=](const boxed& dictSemiring) -> boxed {
                    return Data_Semiring::SemiringRecord()([=](const boxed& v) -> boxed {
                        return [=](const boxed& ra) -> boxed {
                            return [=](const boxed& rb) -> boxed {
                                boxed tail = Data_Semiring::addRecord()(dictSemiringRecord)(Type_Data_RowList::RLProxy())(ra)(rb);
                                boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                                boxed insert = Record_Unsafe::unsafeSet()(key);
                                boxed get = Record_Unsafe::unsafeGet()(key);
                                return insert(Data_Semiring::add()(dictSemiring)(get(ra))(get(rb)))(tail);
                            };
                        };
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& ra) -> boxed {
                            return [=](const boxed& rb) -> boxed {
                                boxed tail = Data_Semiring::mulRecord()(dictSemiringRecord)(Type_Data_RowList::RLProxy())(ra)(rb);
                                boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                                boxed insert = Record_Unsafe::unsafeSet()(key);
                                boxed get = Record_Unsafe::unsafeGet()(key);
                                return insert(Data_Semiring::mul()(dictSemiring)(get(ra))(get(rb)))(tail);
                            };
                        };
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& v1) -> boxed {
                            boxed tail = Data_Semiring::oneRecord()(dictSemiringRecord)(Type_Data_RowList::RLProxy())(Type_Data_Row::RProxy());
                            boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                            boxed insert = Record_Unsafe::unsafeSet()(key);
                            return insert(Data_Semiring::one()(dictSemiring))(tail);
                        };
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& v1) -> boxed {
                            boxed tail = Data_Semiring::zeroRecord()(dictSemiringRecord)(Type_Data_RowList::RLProxy())(Type_Data_Row::RProxy());
                            boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                            boxed insert = Record_Unsafe::unsafeSet()(key);
                            return insert(Data_Semiring::zero()(dictSemiring))(tail);
                        };
                    });
                };
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto intAdd() -> const boxed& { static const boxed _ = foreign().at("intAdd"); return _; };
auto intMul() -> const boxed& { static const boxed _ = foreign().at("intMul"); return _; };
auto numAdd() -> const boxed& { static const boxed _ = foreign().at("numAdd"); return _; };
auto numMul() -> const boxed& { static const boxed _ = foreign().at("numMul"); return _; };

} // end namespace Data_Semiring


