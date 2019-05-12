#include "Control_Bind/Control_Bind.h"
#include "Data_Bounded/Data_Bounded.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Function/Data_Function.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Data_Symbol/Data_Symbol.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Test_Main/Test_Main.h"


namespace Test_Main {

auto plusInfinity() -> boxed {
    return 1.0 / 1.0;
};
auto nan() -> boxed {
    return 0.0 / 1.0;
};
auto minusInfinity() -> boxed {
    return unbox<double>(-1.0) / 0.0;
};
auto _assert_() -> const boxed& {
    static const boxed _ = [](const boxed& msg) -> boxed {
        return [=](const boxed& condition) -> boxed {
            if (unbox<bool>(condition)) {
                return Data_Function::_const_()(Data_Unit::unit());
            };
            return Test_Main::throwErr()(msg);
        };
    };
    return _;
};
auto testIntDegree() -> boxed {
    boxed bot = Data_Bounded::bottom()(Data_Bounded::boundedInt());
    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("degree returns absolute integers")(unbox<int>(Data_EuclideanRing::degree()(Data_EuclideanRing::euclideanRingInt())(-4)) == 4))([=](const boxed&) -> boxed {
        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("degree returns absolute integers")(unbox<int>(Data_EuclideanRing::degree()(Data_EuclideanRing::euclideanRingInt())(4)) == 4))([=](const boxed&) -> boxed {
            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("degree returns absolute integers")(Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(Data_EuclideanRing::degree()(Data_EuclideanRing::euclideanRingInt())(bot))(0)))([=](const boxed&) -> boxed {
                return Test_Main::_assert_()("degree does not return out-of-bounds integers")(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(Data_EuclideanRing::degree()(Data_EuclideanRing::euclideanRingInt())(bot))(Data_Bounded::top()(Data_Bounded::boundedInt())));
            });
        });
    });
};
auto testIntDivMod() -> boxed {
    boxed go = [=](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            boxed r = Data_EuclideanRing::mod()(Data_EuclideanRing::euclideanRingInt())(a)(b);
            boxed q = Data_EuclideanRing::div()(Data_EuclideanRing::euclideanRingInt())(a)(b);
            boxed msg = Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(a))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" / ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(b))(": ")));
            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()(Data_Semigroup::append()(Data_Semigroup::semigroupString())(msg)("Quotient/remainder law"))(unbox<int>(unbox<int>(unbox<int>(q) * unbox<int>(b)) + unbox<int>(r)) == unbox<int>(a)))([=](const boxed&) -> boxed {
                return Test_Main::_assert_()(Data_Semigroup::append()(Data_Semigroup::semigroupString())(msg)(Data_Semigroup::append()(Data_Semigroup::semigroupString())("Remainder should be between 0 and `abs b`, got: ")(Data_Show::show()(Data_Show::showInt())(r))))(unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(0)(r)) && unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(r)(Data_Ord::abs()(Data_Ord::ordInt())(Data_Ring::ringInt())(b))));
            });
        };
    };
    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(go(8)(2))([=](const boxed&) -> boxed {
        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(go(-8)(2))([=](const boxed&) -> boxed {
            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(go(8)(-2))([=](const boxed&) -> boxed {
                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(go(-8)(-2))([=](const boxed&) -> boxed {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(go(2)(3))([=](const boxed&) -> boxed {
                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(go(-2)(3))([=](const boxed&) -> boxed {
                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(go(2)(-3))([=](const boxed&) -> boxed {
                                return go(-2)(-3);
                            });
                        });
                    });
                });
            });
        });
    });
};
auto testOrd() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictShow) -> boxed {
            return [=](const boxed& x) -> boxed {
                return [=](const boxed& y) -> boxed {
                    return [=](const boxed& ord) -> boxed {
                        return Test_Main::_assert_()(Data_Semigroup::append()(Data_Semigroup::semigroupString())("(compare ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(x))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(dictShow)(y))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" ) is not equal to ")(Data_Show::show()(Data_Ordering::showOrdering())(ord)))))))(Data_Eq::eq()(Data_Ordering::eqOrdering())(Data_Ord::compare()(dictOrd)(x)(y))(ord));
                    };
                };
            };
        };
    };
    return _;
};
auto testOrdUtils() -> boxed {
    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("-5 clamped between 0 and 10 should be 0")(unbox<int>(Data_Ord::clamp()(Data_Ord::ordInt())(0)(10)(-5)) == 0))([=](const boxed&) -> boxed {
        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("5 clamped between 0 and 10 should be 5")(unbox<int>(Data_Ord::clamp()(Data_Ord::ordInt())(0)(10)(5)) == 5))([=](const boxed&) -> boxed {
            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("15 clamped between 0 and 10 should be 10")(unbox<int>(Data_Ord::clamp()(Data_Ord::ordInt())(0)(10)(15)) == 10))([=](const boxed&) -> boxed {
                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("-5 should not be between 0 and 10")(Data_Eq::eq()(Data_Eq::eqBoolean())(Data_Ord::between()(Data_Ord::ordInt())(0)(10)(-5))(false)))([=](const boxed&) -> boxed {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("5 should be between 0 and 10")(Data_Eq::eq()(Data_Eq::eqBoolean())(Data_Ord::between()(Data_Ord::ordInt())(0)(10)(5))(true)))([=](const boxed&) -> boxed {
                        return Test_Main::_assert_()("15 should not be between 0 10")(Data_Eq::eq()(Data_Eq::eqBoolean())(Data_Ord::between()(Data_Ord::ordInt())(0)(10)(15))(false));
                    });
                });
            });
        });
    });
};
auto testOrderings() -> boxed {
    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("NaN shouldn't be equal to itself")(Data_Eq::notEq()(Data_Eq::eqNumber())(Test_Main::nan())(Test_Main::nan())))([=](const boxed&) -> boxed {
        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("NaN shouldn't be equal to itself")(Data_Eq::notEq()(Data_Ordering::eqOrdering())(Data_Ord::compare()(Data_Ord::ordNumber())(Test_Main::nan())(Test_Main::nan()))(Data_Ordering::EQ())))([=](const boxed&) -> boxed {
            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(1.0)(2.0)(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(2.0)(1.0)(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(1.0)(-2.0)(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(-2.0)(1.0)(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(Test_Main::minusInfinity())(Test_Main::plusInfinity())(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(Test_Main::minusInfinity())(0.0)(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(Test_Main::plusInfinity())(0.0)(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(Test_Main::plusInfinity())(Test_Main::minusInfinity())(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(1.0)(Test_Main::nan())(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(Test_Main::nan())(1.0)(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(Test_Main::nan())(Test_Main::plusInfinity())(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordNumber())(Data_Show::showNumber())(Test_Main::plusInfinity())(Test_Main::nan())(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("1 > NaN should be false")(Data_Eq::eq()(Data_Eq::eqBoolean())(Data_Ord::greaterThan()(Data_Ord::ordNumber())(1.0)(Test_Main::nan()))(false)))([=](const boxed&) -> boxed {
                                                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("1 < NaN should be false")(Data_Eq::eq()(Data_Eq::eqBoolean())(Data_Ord::lessThan()(Data_Ord::ordNumber())(1.0)(Test_Main::nan()))(false)))([=](const boxed&) -> boxed {
                                                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("NaN > 1 should be false")(Data_Eq::eq()(Data_Eq::eqBoolean())(Data_Ord::greaterThan()(Data_Ord::ordNumber())(Test_Main::nan())(1.0))(false)))([=](const boxed&) -> boxed {
                                                                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("NaN < 1 should be false")(Data_Eq::eq()(Data_Eq::eqBoolean())(Data_Ord::lessThan()(Data_Ord::ordNumber())(Test_Main::nan())(1.0))(false)))([=](const boxed&) -> boxed {
                                                                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("NaN == 1 should be false")(Data_Eq::notEq()(Data_Eq::eqNumber())(Test_Main::nan())(1.0)))([=](const boxed&) -> boxed {
                                                                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordInt())(Data_Show::showInt())(Data_EuclideanRing::div()(Data_EuclideanRing::euclideanRingInt())(1)(0))(0)(Data_Ordering::EQ()))([=](const boxed&) -> boxed {
                                                                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordInt())(Data_Show::showInt())(Data_EuclideanRing::mod()(Data_EuclideanRing::euclideanRingInt())(1)(0))(0)(Data_Ordering::EQ()))([=](const boxed&) -> boxed {
                                                                                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordChar())(Data_Show::showChar())("a")("b")(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                                                                                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordChar())(Data_Show::showChar())("b")("A")(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                                                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordString())(Data_Show::showString())("10")("0")(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                                                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordString())(Data_Show::showString())("10")("2")(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                                                                                                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordBoolean())(Data_Show::showBoolean())(true)(true)(Data_Ordering::EQ()))([=](const boxed&) -> boxed {
                                                                                                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordBoolean())(Data_Show::showBoolean())(false)(false)(Data_Ordering::EQ()))([=](const boxed&) -> boxed {
                                                                                                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordBoolean())(Data_Show::showBoolean())(false)(true)(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                                                                                                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordBoolean())(Data_Show::showBoolean())(true)(false)(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                                                                                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordArray()(Data_Ord::ordInt()))(Data_Show::showArray()(Data_Show::showInt()))(array_t{  })(array_t{  })(Data_Ordering::EQ()))([=](const boxed&) -> boxed {
                                                                                                                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordArray()(Data_Ord::ordInt()))(Data_Show::showArray()(Data_Show::showInt()))(array_t{ 1, 0 })(array_t{ 1 })(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                                                                                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordArray()(Data_Ord::ordInt()))(Data_Show::showArray()(Data_Show::showInt()))(array_t{ 1 })(array_t{ 1, 0 })(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                                                                                                                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordArray()(Data_Ord::ordInt()))(Data_Show::showArray()(Data_Show::showInt()))(array_t{ 1, 1 })(array_t{ 1, 0 })(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                                                                                                        return Test_Main::testOrd()(Data_Ord::ordArray()(Data_Ord::ordInt()))(Data_Show::showArray()(Data_Show::showInt()))(array_t{ 1, -1 })(array_t{ 1, 0 })(Data_Ordering::LT());
                                                                                                                                    });
                                                                                                                                });
                                                                                                                            });
                                                                                                                        });
                                                                                                                    });
                                                                                                                });
                                                                                                            });
                                                                                                        });
                                                                                                    });
                                                                                                });
                                                                                            });
                                                                                        });
                                                                                    });
                                                                                });
                                                                            });
                                                                        });
                                                                    });
                                                                });
                                                            });
                                                        });
                                                    });
                                                });
                                            });
                                        });
                                    });
                                });
                            });
                        });
                    });
                });
            });
        });
    });
};
auto testRecordInstances() -> boxed {
    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record equality")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
        return "a";
    }))(Data_Eq::eqInt())))(dict_t{
        { "a", 1 }
    })(dict_t{
        { "a", 1 }
    })))([=](const boxed&) -> boxed {
        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record inequality")(Data_Eq::notEq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
            return "a";
        }))(Data_Eq::eqInt())))(dict_t{
            { "a", 2 }
        })(dict_t{
            { "a", 1 }
        })))([=](const boxed&) -> boxed {
            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record show")(Data_Eq::eq()(Data_Eq::eqString())(Data_Show::show()(Data_Show::showRecord()(undefined)(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                return "a";
            }))(Data_Show::showRecordFieldsNil())(Data_Show::showInt())))(dict_t{
                { "a", 1 }
            }))("{ a: 1 }")))([=](const boxed&) -> boxed {
                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record +")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                    return "b";
                }))(Data_Eq::eqNumber()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                    return "a";
                }))(Data_Eq::eqInt())))(Data_Semiring::add()(Data_Semiring::semiringRecord()(undefined)(Data_Semiring::semiringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                    return "a";
                }))(undefined)(Data_Semiring::semiringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                    return "b";
                }))(undefined)(Data_Semiring::semiringRecordNil())(Data_Semiring::semiringNumber()))(Data_Semiring::semiringInt())))(dict_t{
                    { "a", 1 },
                    { "b", 2.0 }
                })(dict_t{
                    { "a", 0 },
                    { "b", -2.0 }
                }))(dict_t{
                    { "a", 1 },
                    { "b", 0.0 }
                })))([=](const boxed&) -> boxed {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record *")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                        return "b";
                    }))(Data_Eq::eqNumber()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                        return "a";
                    }))(Data_Eq::eqInt())))(Data_Semiring::mul()(Data_Semiring::semiringRecord()(undefined)(Data_Semiring::semiringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                        return "a";
                    }))(undefined)(Data_Semiring::semiringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                        return "b";
                    }))(undefined)(Data_Semiring::semiringRecordNil())(Data_Semiring::semiringNumber()))(Data_Semiring::semiringInt())))(dict_t{
                        { "a", 1 },
                        { "b", 2.0 }
                    })(dict_t{
                        { "a", 0 },
                        { "b", -2.0 }
                    }))(dict_t{
                        { "a", 0 },
                        { "b", -4.0 }
                    })))([=](const boxed&) -> boxed {
                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record one")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                            return "b";
                        }))(Data_Eq::eqNumber()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                            return "a";
                        }))(Data_Eq::eqInt())))(Data_Semiring::one()(Data_Semiring::semiringRecord()(undefined)(Data_Semiring::semiringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                            return "a";
                        }))(undefined)(Data_Semiring::semiringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                            return "b";
                        }))(undefined)(Data_Semiring::semiringRecordNil())(Data_Semiring::semiringNumber()))(Data_Semiring::semiringInt()))))(dict_t{
                            { "a", 1 },
                            { "b", 1.0 }
                        })))([=](const boxed&) -> boxed {
                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record zero")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                return "b";
                            }))(Data_Eq::eqNumber()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                return "a";
                            }))(Data_Eq::eqInt())))(Data_Semiring::zero()(Data_Semiring::semiringRecord()(undefined)(Data_Semiring::semiringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                return "a";
                            }))(undefined)(Data_Semiring::semiringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                return "b";
                            }))(undefined)(Data_Semiring::semiringRecordNil())(Data_Semiring::semiringNumber()))(Data_Semiring::semiringInt()))))(dict_t{
                                { "a", 0 },
                                { "b", 0.0 }
                            })))([=](const boxed&) -> boxed {
                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record sub")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                    return "b";
                                }))(Data_Eq::eqNumber()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                    return "a";
                                }))(Data_Eq::eqInt())))(Data_Ring::sub()(Data_Ring::ringRecord()(undefined)(Data_Ring::ringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                    return "a";
                                }))(undefined)(Data_Ring::ringRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                    return "b";
                                }))(undefined)(Data_Ring::ringRecordNil())(Data_Ring::ringNumber()))(Data_Ring::ringInt())))(dict_t{
                                    { "a", 2 },
                                    { "b", 2.0 }
                                })(dict_t{
                                    { "a", 1 },
                                    { "b", 1.0 }
                                }))(dict_t{
                                    { "a", 1 },
                                    { "b", 1.0 }
                                })))([=](const boxed&) -> boxed {
                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record append")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                        return "b";
                                    }))(Data_Eq::eqString()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                        return "a";
                                    }))(Data_Eq::eqArray()(Data_Eq::eqInt()))))(Data_Semigroup::append()(Data_Semigroup::semigroupRecord()(undefined)(Data_Semigroup::semigroupRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                        return "a";
                                    }))(undefined)(Data_Semigroup::semigroupRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                        return "b";
                                    }))(undefined)(Data_Semigroup::semigroupRecordNil())(Data_Semigroup::semigroupString()))(Data_Semigroup::semigroupArray())))(dict_t{
                                        { "a", array_t{  } },
                                        { "b", "T" }
                                    })(dict_t{
                                        { "a", array_t{ 1 } },
                                        { "b", "OM" }
                                    }))(dict_t{
                                        { "a", array_t{ 1 } },
                                        { "b", "TOM" }
                                    })))([=](const boxed&) -> boxed {
                                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record mempty")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                            return "b";
                                        }))(Data_Eq::eqString()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                            return "a";
                                        }))(Data_Eq::eqArray()(Data_Eq::eqInt()))))(Data_Monoid::mempty()(Data_Monoid::monoidRecord()(undefined)(Data_Monoid::monoidRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                            return "a";
                                        }))(Data_Monoid::monoidArray())(undefined)(Data_Monoid::monoidRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                            return "b";
                                        }))(Data_Monoid::monoidString())(undefined)(Data_Monoid::monoidRecordNil())))))(dict_t{
                                            { "a", array_t{  } },
                                            { "b", "" }
                                        })))([=](const boxed&) -> boxed {
                                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record ff")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                return "b";
                                            }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                return "a";
                                            }))(Data_Eq::eqBoolean())))(Data_HeytingAlgebra::ff()(Data_HeytingAlgebra::heytingAlgebraRecord()(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                return "a";
                                            }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                return "b";
                                            }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordNil())(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean()))))(dict_t{
                                                { "a", false },
                                                { "b", false }
                                            })))([=](const boxed&) -> boxed {
                                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record tt")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                    return "b";
                                                }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                    return "a";
                                                }))(Data_Eq::eqBoolean())))(Data_HeytingAlgebra::tt()(Data_HeytingAlgebra::heytingAlgebraRecord()(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                    return "a";
                                                }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                    return "b";
                                                }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordNil())(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean()))))(dict_t{
                                                    { "a", true },
                                                    { "b", true }
                                                })))([=](const boxed&) -> boxed {
                                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record not")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                        return "b";
                                                    }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                        return "a";
                                                    }))(Data_Eq::eqBoolean())))(Data_HeytingAlgebra::_not_()(Data_HeytingAlgebra::heytingAlgebraRecord()(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                        return "a";
                                                    }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                        return "b";
                                                    }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordNil())(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean())))(dict_t{
                                                        { "a", true },
                                                        { "b", false }
                                                    }))(dict_t{
                                                        { "a", false },
                                                        { "b", true }
                                                    })))([=](const boxed&) -> boxed {
                                                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record conj")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                            return "d";
                                                        }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                            return "c";
                                                        }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                            return "b";
                                                        }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                            return "a";
                                                        }))(Data_Eq::eqBoolean())))(Data_HeytingAlgebra::conj()(Data_HeytingAlgebra::heytingAlgebraRecord()(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                            return "a";
                                                        }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                            return "b";
                                                        }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                            return "c";
                                                        }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                            return "d";
                                                        }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordNil())(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean())))(dict_t{
                                                            { "a", true },
                                                            { "b", false },
                                                            { "c", true },
                                                            { "d", false }
                                                        })(dict_t{
                                                            { "a", true },
                                                            { "b", true },
                                                            { "c", false },
                                                            { "d", false }
                                                        }))(dict_t{
                                                            { "a", true },
                                                            { "b", false },
                                                            { "c", false },
                                                            { "d", false }
                                                        })))([=](const boxed&) -> boxed {
                                                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record disj")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                return "d";
                                                            }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                return "c";
                                                            }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                return "b";
                                                            }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                return "a";
                                                            }))(Data_Eq::eqBoolean())))(Data_HeytingAlgebra::disj()(Data_HeytingAlgebra::heytingAlgebraRecord()(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                return "a";
                                                            }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                return "b";
                                                            }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                return "c";
                                                            }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                return "d";
                                                            }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordNil())(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean())))(dict_t{
                                                                { "a", true },
                                                                { "b", false },
                                                                { "c", true },
                                                                { "d", false }
                                                            })(dict_t{
                                                                { "a", true },
                                                                { "b", true },
                                                                { "c", false },
                                                                { "d", false }
                                                            }))(dict_t{
                                                                { "a", true },
                                                                { "b", true },
                                                                { "c", true },
                                                                { "d", false }
                                                            })))([=](const boxed&) -> boxed {
                                                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::_assert_()("Record implies")(Data_Eq::eq()(Data_Eq::eqRec()(undefined)(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowCons()(Data_Eq::eqRowNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                    return "d";
                                                                }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                    return "c";
                                                                }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                    return "b";
                                                                }))(Data_Eq::eqBoolean()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                    return "a";
                                                                }))(Data_Eq::eqBoolean())))(Data_HeytingAlgebra::implies()(Data_HeytingAlgebra::heytingAlgebraRecord()(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                    return "a";
                                                                }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                    return "b";
                                                                }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                    return "c";
                                                                }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                    return "d";
                                                                }))(undefined)(Data_HeytingAlgebra::heytingAlgebraRecordNil())(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Data_HeytingAlgebra::heytingAlgebraBoolean())))(dict_t{
                                                                    { "a", true },
                                                                    { "b", false },
                                                                    { "c", true },
                                                                    { "d", false }
                                                                })(dict_t{
                                                                    { "a", true },
                                                                    { "b", true },
                                                                    { "c", false },
                                                                    { "d", false }
                                                                }))(dict_t{
                                                                    { "a", true },
                                                                    { "b", true },
                                                                    { "c", false },
                                                                    { "d", true }
                                                                })))([=](const boxed&) -> boxed {
                                                                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordRecord()(undefined)(Data_Ord::ordRecordCons()(Data_Ord::ordRecordCons()(Data_Ord::ordRecordNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                        return "b";
                                                                    }))(Data_Ord::ordString()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                        return "a";
                                                                    }))(Data_Ord::ordInt())))(Data_Show::showRecord()(undefined)(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                        return "a";
                                                                    }))(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                        return "b";
                                                                    }))(Data_Show::showRecordFieldsNil())(Data_Show::showString()))(Data_Show::showInt())))(dict_t{
                                                                        { "a", 0 },
                                                                        { "b", "hello" }
                                                                    })(dict_t{
                                                                        { "a", 42 },
                                                                        { "b", "hello" }
                                                                    })(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                                                                        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordRecord()(undefined)(Data_Ord::ordRecordCons()(Data_Ord::ordRecordCons()(Data_Ord::ordRecordNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                            return "b";
                                                                        }))(Data_Ord::ordString()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                            return "a";
                                                                        }))(Data_Ord::ordInt())))(Data_Show::showRecord()(undefined)(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                            return "a";
                                                                        }))(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                            return "b";
                                                                        }))(Data_Show::showRecordFieldsNil())(Data_Show::showString()))(Data_Show::showInt())))(dict_t{
                                                                            { "a", 42 },
                                                                            { "b", "hello" }
                                                                        })(dict_t{
                                                                            { "a", 0 },
                                                                            { "b", "hello" }
                                                                        })(Data_Ordering::GT()))([=](const boxed&) -> boxed {
                                                                            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordRecord()(undefined)(Data_Ord::ordRecordCons()(Data_Ord::ordRecordCons()(Data_Ord::ordRecordNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                return "b";
                                                                            }))(Data_Ord::ordString()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                return "a";
                                                                            }))(Data_Ord::ordInt())))(Data_Show::showRecord()(undefined)(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                return "a";
                                                                            }))(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                return "b";
                                                                            }))(Data_Show::showRecordFieldsNil())(Data_Show::showString()))(Data_Show::showInt())))(dict_t{
                                                                                { "a", 42 },
                                                                                { "b", "hello" }
                                                                            })(dict_t{
                                                                                { "a", 42 },
                                                                                { "b", "hello" }
                                                                            })(Data_Ordering::EQ()))([=](const boxed&) -> boxed {
                                                                                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrd()(Data_Ord::ordRecord()(undefined)(Data_Ord::ordRecordCons()(Data_Ord::ordRecordCons()(Data_Ord::ordRecordNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                    return "b";
                                                                                }))(Data_Ord::ordString()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                    return "a";
                                                                                }))(Data_Ord::ordInt())))(Data_Show::showRecord()(undefined)(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                    return "a";
                                                                                }))(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                    return "b";
                                                                                }))(Data_Show::showRecordFieldsNil())(Data_Show::showString()))(Data_Show::showInt())))(dict_t{
                                                                                    { "a", 42 },
                                                                                    { "b", "hell" }
                                                                                })(dict_t{
                                                                                    { "a", 42 },
                                                                                    { "b", "hello" }
                                                                                })(Data_Ordering::LT()))([=](const boxed&) -> boxed {
                                                                                    return Test_Main::testOrd()(Data_Ord::ordRecord()(undefined)(Data_Ord::ordRecordCons()(Data_Ord::ordRecordCons()(Data_Ord::ordRecordNil())(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                        return "b";
                                                                                    }))(Data_Ord::ordString()))(undefined)(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                        return "a";
                                                                                    }))(Data_Ord::ordInt())))(Data_Show::showRecord()(undefined)(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                        return "a";
                                                                                    }))(Data_Show::showRecordFieldsCons()(Data_Symbol::IsSymbol()([=](const boxed&) -> boxed {
                                                                                        return "b";
                                                                                    }))(Data_Show::showRecordFieldsNil())(Data_Show::showString()))(Data_Show::showInt())))(dict_t{
                                                                                        { "a", 42 },
                                                                                        { "b", "hello" }
                                                                                    })(dict_t{
                                                                                        { "a", 42 },
                                                                                        { "b", "hell" }
                                                                                    })(Data_Ordering::GT());
                                                                                });
                                                                            });
                                                                        });
                                                                    });
                                                                });
                                                            });
                                                        });
                                                    });
                                                });
                                            });
                                        });
                                    });
                                });
                            });
                        });
                    });
                });
            });
        });
    });
};
auto main() -> boxed {
    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testNumberShow()(Data_Show::show()(Data_Show::showNumber())))([=](const boxed&) -> boxed {
        return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrderings())([=](const boxed&) -> boxed {
            return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testOrdUtils())([=](const boxed&) -> boxed {
                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testIntDivMod())([=](const boxed&) -> boxed {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Bind::bindFn())(Test_Main::testIntDegree())([=](const boxed&) -> boxed {
                        return Test_Main::testRecordInstances();
                    });
                });
            });
        });
    });
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto testNumberShow() -> const boxed& { static const boxed _ = foreign().at("testNumberShow"); return _; };
auto throwErr() -> const boxed& { static const boxed _ = foreign().at("throwErr"); return _; };

} // end namespace Test_Main


