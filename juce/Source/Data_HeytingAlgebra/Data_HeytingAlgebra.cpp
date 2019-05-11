#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"
#include "Record_Unsafe/Record_Unsafe.h"
#include "Type_Data_Row/Type_Data_Row.h"
#include "Type_Data_RowList/Type_Data_RowList.h"

#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"


namespace Data_HeytingAlgebra {

auto HeytingAlgebra() -> const boxed& {
    static const boxed _ = [](const boxed& conj) -> boxed {
        return [=](const boxed& disj) -> boxed {
            return [=](const boxed& ff) -> boxed {
                return [=](const boxed& implies) -> boxed {
                    return [=](const boxed& _not_) -> boxed {
                        return [=](const boxed& tt) -> boxed {
                            return dict_t{
                                { "conj", conj },
                                { "disj", disj },
                                { "ff", ff },
                                { "implies", implies },
                                { "not", _not_ },
                                { "tt", tt }
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto HeytingAlgebraRecord() -> const boxed& {
    static const boxed _ = [](const boxed& conjRecord) -> boxed {
        return [=](const boxed& disjRecord) -> boxed {
            return [=](const boxed& ffRecord) -> boxed {
                return [=](const boxed& impliesRecord) -> boxed {
                    return [=](const boxed& notRecord) -> boxed {
                        return [=](const boxed& ttRecord) -> boxed {
                            return dict_t{
                                { "conjRecord", conjRecord },
                                { "disjRecord", disjRecord },
                                { "ffRecord", ffRecord },
                                { "impliesRecord", impliesRecord },
                                { "notRecord", notRecord },
                                { "ttRecord", ttRecord }
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto ttRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["ttRecord"];
    };
    return _;
};
auto tt() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["tt"];
    };
    return _;
};
auto notRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["notRecord"];
    };
    return _;
};
auto _not_() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["not"];
    };
    return _;
};
auto impliesRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["impliesRecord"];
    };
    return _;
};
auto implies() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["implies"];
    };
    return _;
};
auto heytingAlgebraUnit() -> boxed {
    return Data_HeytingAlgebra::HeytingAlgebra()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Unit::unit();
        };
    })([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Unit::unit();
        };
    })(Data_Unit::unit())([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return Data_Unit::unit();
        };
    })([=](const boxed& v) -> boxed {
        return Data_Unit::unit();
    })(Data_Unit::unit());
};
auto heytingAlgebraRecordNil() -> boxed {
    return Data_HeytingAlgebra::HeytingAlgebraRecord()([=](const boxed& v) -> boxed {
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
auto ffRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["ffRecord"];
    };
    return _;
};
auto ff() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["ff"];
    };
    return _;
};
auto disjRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["disjRecord"];
    };
    return _;
};
auto disj() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["disj"];
    };
    return _;
};
auto heytingAlgebraBoolean() -> boxed {
    return Data_HeytingAlgebra::HeytingAlgebra()(Data_HeytingAlgebra::boolConj())(Data_HeytingAlgebra::boolDisj())(false)([=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return unbox<bool>(!unbox<bool>(a))|| unbox<bool>(b);
        };
    })(Data_HeytingAlgebra::boolNot())(true);
};
auto conjRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["conjRecord"];
    };
    return _;
};
auto heytingAlgebraRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictHeytingAlgebraRecord) -> boxed {
            return Data_HeytingAlgebra::HeytingAlgebra()(Data_HeytingAlgebra::conjRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy()))(Data_HeytingAlgebra::disjRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy()))(Data_HeytingAlgebra::ffRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy())(Type_Data_Row::RProxy()))(Data_HeytingAlgebra::impliesRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy()))(Data_HeytingAlgebra::notRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy()))(Data_HeytingAlgebra::ttRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy())(Type_Data_Row::RProxy()));
        };
    };
    return _;
};
auto conj() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["conj"];
    };
    return _;
};
auto heytingAlgebraFunction() -> const boxed& {
    static const boxed _ = [](const boxed& dictHeytingAlgebra) -> boxed {
        return Data_HeytingAlgebra::HeytingAlgebra()([=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Data_HeytingAlgebra::conj()(dictHeytingAlgebra)(f(a))(g(a));
                };
            };
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Data_HeytingAlgebra::disj()(dictHeytingAlgebra)(f(a))(g(a));
                };
            };
        })([=](const boxed& v) -> boxed {
            return Data_HeytingAlgebra::ff()(dictHeytingAlgebra);
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& g) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Data_HeytingAlgebra::implies()(dictHeytingAlgebra)(f(a))(g(a));
                };
            };
        })([=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return Data_HeytingAlgebra::_not_()(dictHeytingAlgebra)(f(a));
            };
        })([=](const boxed& v) -> boxed {
            return Data_HeytingAlgebra::tt()(dictHeytingAlgebra);
        });
    };
    return _;
};
auto heytingAlgebraRecordCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictIsSymbol) -> boxed {
        return [=](const boxed& dictCons) -> boxed {
            return [=](const boxed& dictHeytingAlgebraRecord) -> boxed {
                return [=](const boxed& dictHeytingAlgebra) -> boxed {
                    return Data_HeytingAlgebra::HeytingAlgebraRecord()([=](const boxed& v) -> boxed {
                        return [=](const boxed& ra) -> boxed {
                            return [=](const boxed& rb) -> boxed {
                                boxed tail = Data_HeytingAlgebra::conjRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy())(ra)(rb);
                                boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                                boxed insert = Record_Unsafe::unsafeSet()(key);
                                boxed get = Record_Unsafe::unsafeGet()(key);
                                return insert(Data_HeytingAlgebra::conj()(dictHeytingAlgebra)(get(ra))(get(rb)))(tail);
                            };
                        };
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& ra) -> boxed {
                            return [=](const boxed& rb) -> boxed {
                                boxed tail = Data_HeytingAlgebra::disjRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy())(ra)(rb);
                                boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                                boxed insert = Record_Unsafe::unsafeSet()(key);
                                boxed get = Record_Unsafe::unsafeGet()(key);
                                return insert(Data_HeytingAlgebra::disj()(dictHeytingAlgebra)(get(ra))(get(rb)))(tail);
                            };
                        };
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& row) -> boxed {
                            boxed tail = Data_HeytingAlgebra::ffRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy())(row);
                            boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                            boxed insert = Record_Unsafe::unsafeSet()(key);
                            return insert(Data_HeytingAlgebra::ff()(dictHeytingAlgebra))(tail);
                        };
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& ra) -> boxed {
                            return [=](const boxed& rb) -> boxed {
                                boxed tail = Data_HeytingAlgebra::impliesRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy())(ra)(rb);
                                boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                                boxed insert = Record_Unsafe::unsafeSet()(key);
                                boxed get = Record_Unsafe::unsafeGet()(key);
                                return insert(Data_HeytingAlgebra::implies()(dictHeytingAlgebra)(get(ra))(get(rb)))(tail);
                            };
                        };
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& row) -> boxed {
                            boxed tail = Data_HeytingAlgebra::notRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy())(row);
                            boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                            boxed insert = Record_Unsafe::unsafeSet()(key);
                            boxed get = Record_Unsafe::unsafeGet()(key);
                            return insert(Data_HeytingAlgebra::_not_()(dictHeytingAlgebra)(get(row)))(tail);
                        };
                    })([=](const boxed& v) -> boxed {
                        return [=](const boxed& row) -> boxed {
                            boxed tail = Data_HeytingAlgebra::ttRecord()(dictHeytingAlgebraRecord)(Type_Data_RowList::RLProxy())(row);
                            boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                            boxed insert = Record_Unsafe::unsafeSet()(key);
                            return insert(Data_HeytingAlgebra::tt()(dictHeytingAlgebra))(tail);
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

auto boolConj() -> const boxed& { static const boxed _ = foreign().at("boolConj"); return _; };
auto boolDisj() -> const boxed& { static const boxed _ = foreign().at("boolDisj"); return _; };
auto boolNot() -> const boxed& { static const boxed _ = foreign().at("boolNot"); return _; };

} // end namespace Data_HeytingAlgebra


