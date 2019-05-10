#include "Data_Eq/Data_Eq.h"
#include "Data_Ord_Unsafe/Data_Ord_Unsafe.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"
#include "Data_Void/Data_Void.h"
#include "Record_Unsafe/Record_Unsafe.h"
#include "Type_Data_RowList/Type_Data_RowList.h"

#include "Data_Ord/Data_Ord.h"


namespace Data_Ord {

auto OrdRecord() -> const boxed& {
    static const boxed _ = [](const boxed& EqRecord0) -> boxed {
        return [=](const boxed& compareRecord) -> boxed {
            return dict_t{
                { "EqRecord0", EqRecord0 },
                { "compareRecord", compareRecord }
            };
        };
    };
    return _;
};
auto Ord1() -> const boxed& {
    static const boxed _ = [](const boxed& Eq10) -> boxed {
        return [=](const boxed& compare1) -> boxed {
            return dict_t{
                { "Eq10", Eq10 },
                { "compare1", compare1 }
            };
        };
    };
    return _;
};
auto Ord() -> const boxed& {
    static const boxed _ = [](const boxed& Eq0) -> boxed {
        return [=](const boxed& compare) -> boxed {
            return dict_t{
                { "Eq0", Eq0 },
                { "compare", compare }
            };
        };
    };
    return _;
};
auto ordVoid() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Eq::eqVoid();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Ordering::EQ();
        };
    });
};
auto ordUnit() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Eq::eqUnit();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Ordering::EQ();
        };
    });
};
auto ordString() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Eq::eqString();
    })(Data_Ord_Unsafe::unsafeCompare());
};
auto ordRecordNil() -> boxed {
    return Data_Ord::OrdRecord()([=](const boxed&) -> boxed {
        return Data_Eq::eqRowNil();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                return Data_Ordering::EQ();
            };
        };
    });
};
auto ordOrdering() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Ordering::eqOrdering();
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("LT")) {
                if (unbox<dict_t>(v1).contains("LT")) {
                    return Data_Ordering::EQ();
                };
            };
            if (unbox<dict_t>(v).contains("EQ")) {
                if (unbox<dict_t>(v1).contains("EQ")) {
                    return Data_Ordering::EQ();
                };
            };
            if (unbox<dict_t>(v).contains("GT")) {
                if (unbox<dict_t>(v1).contains("GT")) {
                    return Data_Ordering::EQ();
                };
            };
            if (unbox<dict_t>(v).contains("LT")) {
                return Data_Ordering::LT();
            };
            if (unbox<dict_t>(v).contains("EQ")) {
                if (unbox<dict_t>(v1).contains("LT")) {
                    return Data_Ordering::GT();
                };
            };
            if (unbox<dict_t>(v).contains("EQ")) {
                if (unbox<dict_t>(v1).contains("GT")) {
                    return Data_Ordering::LT();
                };
            };
            if (unbox<dict_t>(v).contains("GT")) {
                return Data_Ordering::GT();
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Ord (line 73, column 1 - line 73, column 37): ");
        };
    });
};
auto ordNumber() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Eq::eqNumber();
    })(Data_Ord_Unsafe::unsafeCompare());
};
auto ordInt() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Eq::eqInt();
    })(Data_Ord_Unsafe::unsafeCompare());
};
auto ordChar() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Eq::eqChar();
    })(Data_Ord_Unsafe::unsafeCompare());
};
auto ordBoolean() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Data_Eq::eqBoolean();
    })(Data_Ord_Unsafe::unsafeCompare());
};
auto compareRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["compareRecord"];
    };
    return _;
};
auto ordRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictOrdRecord) -> boxed {
            return Data_Ord::Ord()([=](const boxed&) -> boxed {
                return Data_Eq::eqRec()(dictRowToList)(dictOrdRecord["EqRecord0"](undefined));
            })(Data_Ord::compareRecord()(dictOrdRecord)(Type_Data_RowList::RLProxy()));
        };
    };
    return _;
};
auto compare1() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["compare1"];
    };
    return _;
};
auto compare() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["compare"];
    };
    return _;
};
auto comparing() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    return Data_Ord::compare()(dictOrd)(f(x))(f(y));
                };
            };
        };
    };
    return _;
};
auto greaterThan() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& a1) -> boxed {
            return [=](const boxed& a2) -> boxed {
                boxed v = Data_Ord::compare()(dictOrd)(a1)(a2);
                if (unbox<dict_t>(v).contains("GT")) {
                    return true;
                };
                return false;
            };
        };
    };
    return _;
};
auto greaterThanOrEq() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& a1) -> boxed {
            return [=](const boxed& a2) -> boxed {
                boxed v = Data_Ord::compare()(dictOrd)(a1)(a2);
                if (unbox<dict_t>(v).contains("LT")) {
                    return false;
                };
                return true;
            };
        };
    };
    return _;
};
auto signum() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictRing) -> boxed {
            return [=](const boxed& x) -> boxed {
                boxed _Local_9 = Data_Ord::greaterThanOrEq()(dictOrd)(x)(Data_Semiring::zero()(dictRing["Semiring0"](undefined)));
                if (unbox<bool>(_Local_9)) {
                    return Data_Semiring::one()(dictRing["Semiring0"](undefined));
                };
                return Data_Ring::negate()(dictRing)(Data_Semiring::one()(dictRing["Semiring0"](undefined)));
            };
        };
    };
    return _;
};
auto lessThan() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& a1) -> boxed {
            return [=](const boxed& a2) -> boxed {
                boxed v = Data_Ord::compare()(dictOrd)(a1)(a2);
                if (unbox<dict_t>(v).contains("LT")) {
                    return true;
                };
                return false;
            };
        };
    };
    return _;
};
auto lessThanOrEq() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& a1) -> boxed {
            return [=](const boxed& a2) -> boxed {
                boxed v = Data_Ord::compare()(dictOrd)(a1)(a2);
                if (unbox<dict_t>(v).contains("GT")) {
                    return false;
                };
                return true;
            };
        };
    };
    return _;
};
auto max() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                boxed v = Data_Ord::compare()(dictOrd)(x)(y);
                if (unbox<dict_t>(v).contains("LT")) {
                    return y;
                };
                if (unbox<dict_t>(v).contains("EQ")) {
                    return x;
                };
                if (unbox<dict_t>(v).contains("GT")) {
                    return x;
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Ord (line 128, column 3 - line 131, column 12): ");
            };
        };
    };
    return _;
};
auto min() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                boxed v = Data_Ord::compare()(dictOrd)(x)(y);
                if (unbox<dict_t>(v).contains("LT")) {
                    return x;
                };
                if (unbox<dict_t>(v).contains("EQ")) {
                    return x;
                };
                if (unbox<dict_t>(v).contains("GT")) {
                    return y;
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Ord (line 119, column 3 - line 122, column 12): ");
            };
        };
    };
    return _;
};
auto ordArray() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Ord::Ord()([=](const boxed&) -> boxed {
            return Data_Eq::eqArray()(dictOrd["Eq0"](undefined));
        })([=]() -> boxed {
            boxed toDelta = [=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    boxed v = Data_Ord::compare()(dictOrd)(x)(y);
                    if (unbox<dict_t>(v).contains("EQ")) {
                        return 0;
                    };
                    if (unbox<dict_t>(v).contains("LT")) {
                        return 1;
                    };
                    if (unbox<dict_t>(v).contains("GT")) {
                        return -1;
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Ord (line 66, column 7 - line 71, column 1): ");
                };
            };
            return [=](const boxed& xs) -> boxed {
                return [=](const boxed& ys) -> boxed {
                    return Data_Ord::compare()(Data_Ord::ordInt())(0)(Data_Ord::ordArrayImpl()(toDelta)(xs)(ys));
                };
            };
        }());
    };
    return _;
};
auto ord1Array() -> boxed {
    return Data_Ord::Ord1()([=](const boxed&) -> boxed {
        return Data_Eq::eq1Array();
    })([=](const boxed& dictOrd) -> boxed {
        return Data_Ord::compare()(Data_Ord::ordArray()(dictOrd));
    });
};
auto ordRecordCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrdRecord) -> boxed {
        return [=](const boxed& dictCons) -> boxed {
            return [=](const boxed& dictIsSymbol) -> boxed {
                return [=](const boxed& dictOrd) -> boxed {
                    return Data_Ord::OrdRecord()([=](const boxed&) -> boxed {
                        return Data_Eq::eqRowCons()(dictOrdRecord["EqRecord0"](undefined))(dictCons)(dictIsSymbol)(dictOrd["Eq0"](undefined));
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& ra) -> boxed {
                            return [=](const boxed& rb) -> boxed {
                                boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                                boxed left = Data_Ord::compare()(dictOrd)(Record_Unsafe::unsafeGet()(key)(ra))(Record_Unsafe::unsafeGet()(key)(rb));
                                boxed _Local_15 = Data_Eq::notEq()(Data_Ordering::eqOrdering())(left)(Data_Ordering::EQ());
                                if (unbox<bool>(_Local_15)) {
                                    return left;
                                };
                                return Data_Ord::compareRecord()(dictOrdRecord)(Type_Data_RowList::RLProxy())(ra)(rb);
                            };
                        };
                    });
                };
            };
        };
    };
    return _;
};
auto clamp() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& low) -> boxed {
            return [=](const boxed& hi) -> boxed {
                return [=](const boxed& x) -> boxed {
                    return Data_Ord::min()(dictOrd)(hi)(Data_Ord::max()(dictOrd)(low)(x));
                };
            };
        };
    };
    return _;
};
auto between() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& low) -> boxed {
            return [=](const boxed& hi) -> boxed {
                return [=](const boxed& x) -> boxed {
                    if (unbox<bool>(Data_Ord::lessThan()(dictOrd)(x)(low))) {
                        return false;
                    };
                    if (unbox<bool>(Data_Ord::greaterThan()(dictOrd)(x)(hi))) {
                        return false;
                    };
                    return true;
                };
            };
        };
    };
    return _;
};
auto abs() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictRing) -> boxed {
            return [=](const boxed& x) -> boxed {
                boxed _Local_19 = Data_Ord::greaterThanOrEq()(dictOrd)(x)(Data_Semiring::zero()(dictRing["Semiring0"](undefined)));
                if (unbox<bool>(_Local_19)) {
                    return x;
                };
                return Data_Ring::negate()(dictRing)(x);
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto ordArrayImpl() -> const boxed& { static const boxed _ = foreign().at("ordArrayImpl"); return _; };

} // end namespace Data_Ord


