#include "Data_Boolean/Data_Boolean.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"
#include "Record_Unsafe/Record_Unsafe.h"
#include "Type_Data_RowList/Type_Data_RowList.h"

#include "Data_Monoid/Data_Monoid.h"


namespace Data_Monoid {

auto Monoid() -> const boxed& {
    static const boxed _ = [](const boxed& Semigroup0) -> boxed {
        return [=](const boxed& mempty) -> boxed {
            return dict_t{
                { "Semigroup0", Semigroup0 },
                { "mempty", mempty }
            };
        };
    };
    return _;
};
auto MonoidRecord() -> const boxed& {
    static const boxed _ = [](const boxed& SemigroupRecord0) -> boxed {
        return [=](const boxed& memptyRecord) -> boxed {
            return dict_t{
                { "SemigroupRecord0", SemigroupRecord0 },
                { "memptyRecord", memptyRecord }
            };
        };
    };
    return _;
};
auto monoidUnit() -> boxed {
    return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
        return Data_Semigroup::semigroupUnit();
    })(Data_Unit::unit());
};
auto monoidString() -> boxed {
    return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
        return Data_Semigroup::semigroupString();
    })("");
};
auto monoidRecordNil() -> boxed {
    return Data_Monoid::MonoidRecord()([=](const boxed&) -> boxed {
        return Data_Semigroup::semigroupRecordNil();
    })([=](const boxed& v) -> boxed {
        return dict_t{

        };
    });
};
auto monoidOrdering() -> boxed {
    return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
        return Data_Ordering::semigroupOrdering();
    })(Data_Ordering::EQ());
};
auto monoidArray() -> boxed {
    return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
        return Data_Semigroup::semigroupArray();
    })(array_t{  });
};
auto memptyRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["memptyRecord"];
    };
    return _;
};
auto monoidRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictMonoidRecord) -> boxed {
            return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
                return Data_Semigroup::semigroupRecord()(dictRowToList)(dictMonoidRecord["SemigroupRecord0"](undefined));
            })(Data_Monoid::memptyRecord()(dictMonoidRecord)(Type_Data_RowList::RLProxy()));
        };
    };
    return _;
};
auto mempty() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["mempty"];
    };
    return _;
};
auto monoidFn() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
            return Data_Semigroup::semigroupFn()(dictMonoid["Semigroup0"](undefined));
        })([=](const boxed& v) -> boxed {
            return Data_Monoid::mempty()(dictMonoid);
        });
    };
    return _;
};
auto monoidRecordCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictIsSymbol) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return [=](const boxed& dictCons) -> boxed {
                return [=](const boxed& dictMonoidRecord) -> boxed {
                    return Data_Monoid::MonoidRecord()([=](const boxed&) -> boxed {
                        return Data_Semigroup::semigroupRecordCons()(dictIsSymbol)(dictCons)(dictMonoidRecord["SemigroupRecord0"](undefined))(dictMonoid["Semigroup0"](undefined));
                    })([=](const boxed& v) -> boxed {
                        boxed tail = Data_Monoid::memptyRecord()(dictMonoidRecord)(Type_Data_RowList::RLProxy());
                        boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                        boxed insert = Record_Unsafe::unsafeSet()(key);
                        return insert(Data_Monoid::mempty()(dictMonoid))(tail);
                    });
                };
            };
        };
    };
    return _;
};
auto power() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& x) -> boxed {
            boxed::recur go;
            boxed::recur::weak go_Weak_(go);
            go = [=](const boxed& p) -> boxed {
                boxed go = go_Weak_;
                if (unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(p)(0))) {
                    return Data_Monoid::mempty()(dictMonoid);
                };
                if (unbox<bool>(unbox<int>(p) == 1)) {
                    return x;
                };
                if (unbox<bool>(unbox<int>(Data_EuclideanRing::mod()(Data_EuclideanRing::euclideanRingInt())(p)(2)) == 0)) {
                    boxed x_Prime_ = go(Data_EuclideanRing::div()(Data_EuclideanRing::euclideanRingInt())(p)(2));
                    return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(x_Prime_)(x_Prime_);
                };
                if (unbox<bool>(Data_Boolean::otherwise())) {
                    boxed x_Prime_ = go(Data_EuclideanRing::div()(Data_EuclideanRing::euclideanRingInt())(p)(2));
                    return Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(x_Prime_)(Data_Semigroup::append()(dictMonoid["Semigroup0"](undefined))(x_Prime_)(x));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Monoid (line 65, column 3 - line 65, column 17): ");
            };
            return go;
        };
    };
    return _;
};
auto guard() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonoid) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<bool>(v)) {
                    return v1;
                };
                if (!(unbox<bool>(v))) {
                    return Data_Monoid::mempty()(dictMonoid);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Monoid (line 73, column 1 - line 73, column 49): ");
            };
        };
    };
    return _;
};


} // end namespace Data_Monoid


