#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_Tuple_Nested/Data_Tuple_Nested.h"


namespace Data_Tuple_Nested {

auto uncurry9() -> const boxed& {
    static const boxed _ = [](const boxed& f_Prime_) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f_Prime_(v["value0"])(v["value1"]["value0"])(v["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]);
        };
    };
    return _;
};
auto uncurry8() -> const boxed& {
    static const boxed _ = [](const boxed& f_Prime_) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f_Prime_(v["value0"])(v["value1"]["value0"])(v["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]);
        };
    };
    return _;
};
auto uncurry7() -> const boxed& {
    static const boxed _ = [](const boxed& f_Prime_) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f_Prime_(v["value0"])(v["value1"]["value0"])(v["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]);
        };
    };
    return _;
};
auto uncurry6() -> const boxed& {
    static const boxed _ = [](const boxed& f_Prime_) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f_Prime_(v["value0"])(v["value1"]["value0"])(v["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]);
        };
    };
    return _;
};
auto uncurry5() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v["value0"])(v["value1"]["value0"])(v["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value0"]);
        };
    };
    return _;
};
auto uncurry4() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v["value0"])(v["value1"]["value0"])(v["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value0"]);
        };
    };
    return _;
};
auto uncurry3() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v["value0"])(v["value1"]["value0"])(v["value1"]["value1"]["value0"]);
        };
    };
    return _;
};
auto uncurry2() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v["value0"])(v["value1"]["value0"]);
        };
    };
    return _;
};
auto uncurry10() -> const boxed& {
    static const boxed _ = [](const boxed& f_Prime_) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f_Prime_(v["value0"])(v["value1"]["value0"])(v["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]);
        };
    };
    return _;
};
auto uncurry1() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& v) -> boxed {
            return f(v["value0"]);
        };
    };
    return _;
};
auto tuple9() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return [=](const boxed& i) -> boxed {
                                        return Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(Data_Tuple::Tuple()(g)(Data_Tuple::Tuple()(h)(Data_Tuple::Tuple()(i)(Data_Unit::unit())))))))));
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto tuple8() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(Data_Tuple::Tuple()(g)(Data_Tuple::Tuple()(h)(Data_Unit::unit()))))))));
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto tuple7() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(Data_Tuple::Tuple()(g)(Data_Unit::unit())))))));
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto tuple6() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(Data_Unit::unit()))))));
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto tuple5() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Unit::unit())))));
                    };
                };
            };
        };
    };
    return _;
};
auto tuple4() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Unit::unit()))));
                };
            };
        };
    };
    return _;
};
auto tuple3() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Unit::unit())));
            };
        };
    };
    return _;
};
auto tuple2() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Unit::unit()));
        };
    };
    return _;
};
auto tuple10() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return [=](const boxed& i) -> boxed {
                                        return [=](const boxed& j) -> boxed {
                                            return Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(Data_Tuple::Tuple()(g)(Data_Tuple::Tuple()(h)(Data_Tuple::Tuple()(i)(Data_Tuple::Tuple()(j)(Data_Unit::unit()))))))))));
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto tuple1() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return Data_Tuple::Tuple()(a)(Data_Unit::unit());
    };
    return _;
};
auto over9() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(Data_Tuple::Tuple()(v["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(o(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]))(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"])))))))));
        };
    };
    return _;
};
auto over8() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(Data_Tuple::Tuple()(v["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(o(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]))(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]))))))));
        };
    };
    return _;
};
auto over7() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(Data_Tuple::Tuple()(v["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(o(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]))(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"])))))));
        };
    };
    return _;
};
auto over6() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(Data_Tuple::Tuple()(v["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(o(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]))(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]))))));
        };
    };
    return _;
};
auto over5() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(Data_Tuple::Tuple()(v["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(o(v["value1"]["value1"]["value1"]["value1"]["value0"]))(v["value1"]["value1"]["value1"]["value1"]["value1"])))));
        };
    };
    return _;
};
auto over4() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(Data_Tuple::Tuple()(v["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(o(v["value1"]["value1"]["value1"]["value0"]))(v["value1"]["value1"]["value1"]["value1"]))));
        };
    };
    return _;
};
auto over3() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(Data_Tuple::Tuple()(v["value1"]["value0"])(Data_Tuple::Tuple()(o(v["value1"]["value1"]["value0"]))(v["value1"]["value1"]["value1"])));
        };
    };
    return _;
};
auto over2() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(Data_Tuple::Tuple()(o(v["value1"]["value0"]))(v["value1"]["value1"]));
        };
    };
    return _;
};
auto over10() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(v["value0"])(Data_Tuple::Tuple()(v["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"])(Data_Tuple::Tuple()(o(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"]))(v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]))))))))));
        };
    };
    return _;
};
auto over1() -> const boxed& {
    static const boxed _ = [](const boxed& o) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Tuple::Tuple()(o(v["value0"]))(v["value1"]);
        };
    };
    return _;
};
auto get9() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"];
    };
    return _;
};
auto get8() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"];
    };
    return _;
};
auto get7() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"];
    };
    return _;
};
auto get6() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"]["value1"]["value1"]["value1"]["value1"]["value0"];
    };
    return _;
};
auto get5() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"]["value1"]["value1"]["value1"]["value0"];
    };
    return _;
};
auto get4() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"]["value1"]["value1"]["value0"];
    };
    return _;
};
auto get3() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"]["value1"]["value0"];
    };
    return _;
};
auto get2() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"]["value0"];
    };
    return _;
};
auto get10() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value1"]["value0"];
    };
    return _;
};
auto get1() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value0"];
    };
    return _;
};
auto curry9() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f_Prime_) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return [=](const boxed& d) -> boxed {
                            return [=](const boxed& e) -> boxed {
                                return [=](const boxed& f) -> boxed {
                                    return [=](const boxed& g) -> boxed {
                                        return [=](const boxed& h) -> boxed {
                                            return [=](const boxed& i) -> boxed {
                                                return f_Prime_(Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(Data_Tuple::Tuple()(g)(Data_Tuple::Tuple()(h)(Data_Tuple::Tuple()(i)(z))))))))));
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto curry8() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f_Prime_) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return [=](const boxed& d) -> boxed {
                            return [=](const boxed& e) -> boxed {
                                return [=](const boxed& f) -> boxed {
                                    return [=](const boxed& g) -> boxed {
                                        return [=](const boxed& h) -> boxed {
                                            return f_Prime_(Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(Data_Tuple::Tuple()(g)(Data_Tuple::Tuple()(h)(z)))))))));
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto curry7() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f_Prime_) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return [=](const boxed& d) -> boxed {
                            return [=](const boxed& e) -> boxed {
                                return [=](const boxed& f) -> boxed {
                                    return [=](const boxed& g) -> boxed {
                                        return f_Prime_(Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(Data_Tuple::Tuple()(g)(z))))))));
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto curry6() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f_Prime_) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return [=](const boxed& d) -> boxed {
                            return [=](const boxed& e) -> boxed {
                                return [=](const boxed& f) -> boxed {
                                    return f_Prime_(Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(z)))))));
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto curry5() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return [=](const boxed& d) -> boxed {
                            return [=](const boxed& e) -> boxed {
                                return f(Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(z))))));
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto curry4() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return [=](const boxed& d) -> boxed {
                            return f(Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(z)))));
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto curry3() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return f(Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(z))));
                    };
                };
            };
        };
    };
    return _;
};
auto curry2() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return f(Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(z)));
                };
            };
        };
    };
    return _;
};
auto curry10() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f_Prime_) -> boxed {
            return [=](const boxed& a) -> boxed {
                return [=](const boxed& b) -> boxed {
                    return [=](const boxed& c) -> boxed {
                        return [=](const boxed& d) -> boxed {
                            return [=](const boxed& e) -> boxed {
                                return [=](const boxed& f) -> boxed {
                                    return [=](const boxed& g) -> boxed {
                                        return [=](const boxed& h) -> boxed {
                                            return [=](const boxed& i) -> boxed {
                                                return [=](const boxed& j) -> boxed {
                                                    return f_Prime_(Data_Tuple::Tuple()(a)(Data_Tuple::Tuple()(b)(Data_Tuple::Tuple()(c)(Data_Tuple::Tuple()(d)(Data_Tuple::Tuple()(e)(Data_Tuple::Tuple()(f)(Data_Tuple::Tuple()(g)(Data_Tuple::Tuple()(h)(Data_Tuple::Tuple()(i)(Data_Tuple::Tuple()(j)(z)))))))))));
                                                };
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto curry1() -> const boxed& {
    static const boxed _ = [](const boxed& z) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return f(Data_Tuple::Tuple()(a)(z));
            };
        };
    };
    return _;
};


} // end namespace Data_Tuple_Nested


