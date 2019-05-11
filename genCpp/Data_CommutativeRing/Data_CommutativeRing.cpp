#include "Data_Ring/Data_Ring.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"

#include "Data_CommutativeRing/Data_CommutativeRing.h"


namespace Data_CommutativeRing {

auto CommutativeRing() -> const boxed& {
    static const boxed _ = [](const boxed& Ring0) -> boxed {
        return dict_t{
            { "Ring0", Ring0 }
        };
    };
    return _;
};
auto CommutativeRingRecord() -> const boxed& {
    static const boxed _ = [](const boxed& RingRecord0) -> boxed {
        return dict_t{
            { "RingRecord0", RingRecord0 }
        };
    };
    return _;
};
auto commutativeRingUnit() -> boxed {
    return Data_CommutativeRing::CommutativeRing()([=](const boxed&) -> boxed {
        return Data_Ring::ringUnit();
    });
};
auto commutativeRingRecordNil() -> boxed {
    return Data_CommutativeRing::CommutativeRingRecord()([=](const boxed&) -> boxed {
        return Data_Ring::ringRecordNil();
    });
};
auto commutativeRingRecordCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictIsSymbol) -> boxed {
        return [=](const boxed& dictCons) -> boxed {
            return [=](const boxed& dictCommutativeRingRecord) -> boxed {
                return [=](const boxed& dictCommutativeRing) -> boxed {
                    return Data_CommutativeRing::CommutativeRingRecord()([=](const boxed&) -> boxed {
                        return Data_Ring::ringRecordCons()(dictIsSymbol)(dictCons)(dictCommutativeRingRecord["RingRecord0"](undefined))(dictCommutativeRing["Ring0"](undefined));
                    });
                };
            };
        };
    };
    return _;
};
auto commutativeRingRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictCommutativeRingRecord) -> boxed {
            return Data_CommutativeRing::CommutativeRing()([=](const boxed&) -> boxed {
                return Data_Ring::ringRecord()(dictRowToList)(dictCommutativeRingRecord["RingRecord0"](undefined));
            });
        };
    };
    return _;
};
auto commutativeRingNumber() -> boxed {
    return Data_CommutativeRing::CommutativeRing()([=](const boxed&) -> boxed {
        return Data_Ring::ringNumber();
    });
};
auto commutativeRingInt() -> boxed {
    return Data_CommutativeRing::CommutativeRing()([=](const boxed&) -> boxed {
        return Data_Ring::ringInt();
    });
};
auto commutativeRingFn() -> const boxed& {
    static const boxed _ = [](const boxed& dictCommutativeRing) -> boxed {
        return Data_CommutativeRing::CommutativeRing()([=](const boxed&) -> boxed {
            return Data_Ring::ringFn()(dictCommutativeRing["Ring0"](undefined));
        });
    };
    return _;
};


} // end namespace Data_CommutativeRing


