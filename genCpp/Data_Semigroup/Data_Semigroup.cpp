#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"
#include "Data_Void/Data_Void.h"
#include "Record_Unsafe/Record_Unsafe.h"
#include "Type_Data_RowList/Type_Data_RowList.h"

#include "Data_Semigroup/Data_Semigroup.h"


namespace Data_Semigroup {

auto Semigroup() -> const boxed& {
    static const boxed _ = [](const boxed& append) -> boxed {
        return dict_t{
            { "append", append }
        };
    };
    return _;
};
auto SemigroupRecord() -> const boxed& {
    static const boxed _ = [](const boxed& appendRecord) -> boxed {
        return dict_t{
            { "appendRecord", appendRecord }
        };
    };
    return _;
};
auto semigroupVoid() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return Data_Void::absurd();
    });
};
auto semigroupUnit() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Unit::unit();
        };
    });
};
auto semigroupString() -> boxed {
    return Data_Semigroup::Semigroup()(Data_Semigroup::concatString());
};
auto semigroupRecordNil() -> boxed {
    return Data_Semigroup::SemigroupRecord()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return [=](const boxed& v2) -> boxed {
                return dict_t{

                };
            };
        };
    });
};
auto semigroupArray() -> boxed {
    return Data_Semigroup::Semigroup()(Data_Semigroup::concatArray());
};
auto appendRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["appendRecord"];
    };
    return _;
};
auto semigroupRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictSemigroupRecord) -> boxed {
            return Data_Semigroup::Semigroup()(Data_Semigroup::appendRecord()(dictSemigroupRecord)(Type_Data_RowList::RLProxy()));
        };
    };
    return _;
};
auto append() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["append"];
    };
    return _;
};
auto semigroupFn() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& x) -> boxed {
                    return Data_Semigroup::append()(dictSemigroup)(f(x))(g(x));
                };
            };
        });
    };
    return _;
};
auto semigroupRecordCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictIsSymbol) -> boxed {
        return [=](const boxed& dictCons) -> boxed {
            return [=](const boxed& dictSemigroupRecord) -> boxed {
                return [=](const boxed& dictSemigroup) -> boxed {
                    return Data_Semigroup::SemigroupRecord()([=](const boxed& v) -> boxed {
                        return [=](const boxed& ra) -> boxed {
                            return [=](const boxed& rb) -> boxed {
                                boxed tail = Data_Semigroup::appendRecord()(dictSemigroupRecord)(Type_Data_RowList::RLProxy())(ra)(rb);
                                boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                                boxed insert = Record_Unsafe::unsafeSet()(key);
                                boxed get = Record_Unsafe::unsafeGet()(key);
                                return insert(Data_Semigroup::append()(dictSemigroup)(get(ra))(get(rb)))(tail);
                            };
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

auto concatString() -> const boxed& { static const boxed _ = foreign().at("concatString"); return _; };
auto concatArray() -> const boxed& { static const boxed _ = foreign().at("concatArray"); return _; };

} // end namespace Data_Semigroup


