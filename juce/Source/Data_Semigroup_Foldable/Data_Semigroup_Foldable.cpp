#include "Control_Apply/Control_Apply.h"
#include "Control_Category/Control_Category.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid_Dual/Data_Monoid_Dual.h"
#include "Data_Monoid_Multiplicative/Data_Monoid_Multiplicative.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord_Max/Data_Ord_Max.h"
#include "Data_Ord_Min/Data_Ord_Min.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"


namespace Data_Semigroup_Foldable {

auto JoinWith() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto Act() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto Foldable1() -> const boxed& {
    static const boxed _ = [](const boxed& Foldable0) -> boxed {
        return [=](const boxed& fold1) -> boxed {
            return [=](const boxed& foldMap1) -> boxed {
                return dict_t{
                    { "Foldable0", Foldable0 },
                    { "fold1", fold1 },
                    { "foldMap1", foldMap1 }
                };
            };
        };
    };
    return _;
};
auto semigroupJoinWith() -> const boxed& {
    static const boxed _ = [](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Data_Semigroup_Foldable::JoinWith()([=](const boxed& j) -> boxed {
                    return Data_Semigroup::append()(dictSemigroup)(v(j))(Data_Semigroup::append()(dictSemigroup)(j)(v1(j)));
                });
            };
        });
    };
    return _;
};
auto semigroupAct() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return Control_Apply::applySecond()(dictApply)(v)(v1);
            };
        });
    };
    return _;
};
auto joinee() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto getAct() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto foldMap1() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["foldMap1"];
    };
    return _;
};
auto intercalateMap() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& dictSemigroup) -> boxed {
            return [=](const boxed& j) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return [=](const boxed& foldable) -> boxed {
                        return Data_Semigroup_Foldable::joinee()(Data_Semigroup_Foldable::foldMap1()(dictFoldable1)(Data_Semigroup_Foldable::semigroupJoinWith()(dictSemigroup))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Semigroup_Foldable::JoinWith())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Function::_const_())(f)))(foldable))(j);
                    };
                };
            };
        };
    };
    return _;
};
auto intercalate() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& dictSemigroup) -> boxed {
            return Data_Function::flip()(Data_Semigroup_Foldable::intercalateMap()(dictFoldable1)(dictSemigroup))(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto maximum() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictFoldable1) -> boxed {
            return Data_Newtype::ala()(Data_Functor::functorFn())(Data_Ord_Max::newtypeMax())(Data_Ord_Max::newtypeMax())(Data_Ord_Max::Max())(Data_Semigroup_Foldable::foldMap1()(dictFoldable1)(Data_Ord_Max::semigroupMax()(dictOrd)));
        };
    };
    return _;
};
auto minimum() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& dictFoldable1) -> boxed {
            return Data_Newtype::ala()(Data_Functor::functorFn())(Data_Ord_Min::newtypeMin())(Data_Ord_Min::newtypeMin())(Data_Ord_Min::Min())(Data_Semigroup_Foldable::foldMap1()(dictFoldable1)(Data_Ord_Min::semigroupMin()(dictOrd)));
        };
    };
    return _;
};
auto traverse1_() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& dictApply) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& t) -> boxed {
                    return Data_Functor::voidRight()(dictApply["Functor0"](undefined))(Data_Unit::unit())(Data_Semigroup_Foldable::getAct()(Data_Semigroup_Foldable::foldMap1()(dictFoldable1)(Data_Semigroup_Foldable::semigroupAct()(dictApply))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Semigroup_Foldable::Act())(f))(t)));
                };
            };
        };
    };
    return _;
};
auto for1_() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& dictApply) -> boxed {
            return Data_Function::flip()(Data_Semigroup_Foldable::traverse1_()(dictFoldable1)(dictApply));
        };
    };
    return _;
};
auto sequence1_() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& dictApply) -> boxed {
            return Data_Semigroup_Foldable::traverse1_()(dictFoldable1)(dictApply)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto fold1Default() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& dictSemigroup) -> boxed {
            return Data_Semigroup_Foldable::foldMap1()(dictFoldable1)(dictSemigroup)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto foldableDual() -> boxed {
    return Data_Semigroup_Foldable::Foldable1()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableDual();
    })([=](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup_Foldable::fold1Default()(Data_Semigroup_Foldable::foldableDual())(dictSemigroup);
    })([=](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(v);
            };
        };
    });
};
auto foldableMultiplicative() -> boxed {
    return Data_Semigroup_Foldable::Foldable1()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableMultiplicative();
    })([=](const boxed& dictSemigroup) -> boxed {
        return Data_Semigroup_Foldable::fold1Default()(Data_Semigroup_Foldable::foldableMultiplicative())(dictSemigroup);
    })([=](const boxed& dictSemigroup) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return f(v);
            };
        };
    });
};
auto fold1() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["fold1"];
    };
    return _;
};
auto foldMap1Default() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable1) -> boxed {
        return [=](const boxed& dictFunctor) -> boxed {
            return [=](const boxed& dictSemigroup) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Control_Semigroupoid::composeFlipped()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictFunctor)(f))(Data_Semigroup_Foldable::fold1()(dictFoldable1)(dictSemigroup));
                };
            };
        };
    };
    return _;
};


} // end namespace Data_Semigroup_Foldable


