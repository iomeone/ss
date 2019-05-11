#include "Data_Semiring/Data_Semiring.h"
#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"
#include "Record_Unsafe/Record_Unsafe.h"
#include "Type_Data_RowList/Type_Data_RowList.h"

#include "Data_Ring/Data_Ring.h"


namespace Data_Ring {

auto Ring() -> const boxed& {
    static const boxed _ = [](const boxed& Semiring0) -> boxed {
        return [=](const boxed& sub) -> boxed {
            return dict_t{
                { "Semiring0", Semiring0 },
                { "sub", sub }
            };
        };
    };
    return _;
};
auto RingRecord() -> const boxed& {
    static const boxed _ = [](const boxed& SemiringRecord0) -> boxed {
        return [=](const boxed& subRecord) -> boxed {
            return dict_t{
                { "SemiringRecord0", SemiringRecord0 },
                { "subRecord", subRecord }
            };
        };
    };
    return _;
};
auto subRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["subRecord"];
    };
    return _;
};
auto sub() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["sub"];
    };
    return _;
};
auto ringUnit() -> boxed {
    return Data_Ring::Ring()([=](const boxed&) -> boxed {
        return Data_Semiring::semiringUnit();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Unit::unit();
        };
    });
};
auto ringRecordNil() -> boxed {
    return Data_Ring::RingRecord()([=](const boxed&) -> boxed {
        return Data_Semiring::semiringRecordNil();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                return dict_t{

                };
            };
        };
    });
};
auto ringRecordCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictIsSymbol) -> boxed {
        return [=](const boxed& dictCons) -> boxed {
            return [=](const boxed& dictRingRecord) -> boxed {
                return [=](const boxed& dictRing) -> boxed {
                    return Data_Ring::RingRecord()([=](const boxed&) -> boxed {
                        return Data_Semiring::semiringRecordCons()(dictIsSymbol)(dictCons)(dictRingRecord["SemiringRecord0"](undefined))(dictRing["Semiring0"](undefined));
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& ra) -> boxed {
                            return [=](const boxed& rb) -> boxed {
                                boxed tail = Data_Ring::subRecord()(dictRingRecord)(Type_Data_RowList::RLProxy())(ra)(rb);
                                boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                                boxed insert = Record_Unsafe::unsafeSet()(key);
                                boxed get = Record_Unsafe::unsafeGet()(key);
                                return insert(Data_Ring::sub()(dictRing)(get(ra))(get(rb)))(tail);
                            };
                        };
                    });
                };
            };
        };
    };
    return _;
};
auto ringRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictRingRecord) -> boxed {
            return Data_Ring::Ring()([=](const boxed&) -> boxed {
                return Data_Semiring::semiringRecord()(dictRowToList)(dictRingRecord["SemiringRecord0"](undefined));
            })(Data_Ring::subRecord()(dictRingRecord)(Type_Data_RowList::RLProxy()));
        };
    };
    return _;
};
auto ringNumber() -> boxed {
    return Data_Ring::Ring()([=](const boxed&) -> boxed {
        return Data_Semiring::semiringNumber();
    })(Data_Ring::numSub());
};
auto ringInt() -> boxed {
    return Data_Ring::Ring()([=](const boxed&) -> boxed {
        return Data_Semiring::semiringInt();
    })(Data_Ring::intSub());
};
auto ringFn() -> const boxed& {
    static const boxed _ = [](const boxed& dictRing) -> boxed {
        return Data_Ring::Ring()([=](const boxed&) -> boxed {
            return Data_Semiring::semiringFn()(dictRing["Semiring0"](undefined));
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& x) -> boxed {
                    return Data_Ring::sub()(dictRing)(f(x))(g(x));
                };
            };
        });
    };
    return _;
};
auto negate() -> const boxed& {
    static const boxed _ = [](const boxed& dictRing) -> boxed {
        return [=](const boxed& a) -> boxed {
            return Data_Ring::sub()(dictRing)(Data_Semiring::zero()(dictRing["Semiring0"](undefined)))(a);
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto intSub() -> const boxed& { static const boxed _ = foreign().at("intSub"); return _; };
auto numSub() -> const boxed& { static const boxed _ = foreign().at("numSub"); return _; };

} // end namespace Data_Ring


