#include "Control_Category/Control_Category.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid_Dual/Data_Monoid_Dual.h"
#include "Data_Monoid_Multiplicative/Data_Monoid_Multiplicative.h"
#include "Data_Semigroup_Foldable/Data_Semigroup_Foldable.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Prelude/Prelude.h"

#include "Data_Semigroup_Traversable/Data_Semigroup_Traversable.h"


namespace Data_Semigroup_Traversable {

auto Traversable1() -> const boxed& {
    static const boxed _ = [](const boxed& Foldable10) -> boxed {
        return [=](const boxed& Traversable1) -> boxed {
            return [=](const boxed& sequence1) -> boxed {
                return [=](const boxed& traverse1) -> boxed {
                    return dict_t{
                        { "Foldable10", Foldable10 },
                        { "Traversable1", Traversable1 },
                        { "sequence1", sequence1 },
                        { "traverse1", traverse1 }
                    };
                };
            };
        };
    };
    return _;
};
auto traverse1() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["traverse1"];
    };
    return _;
};
auto sequence1Default() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable1) -> boxed {
        return [=](const boxed& dictApply) -> boxed {
            return Data_Semigroup_Traversable::traverse1()(dictTraversable1)(dictApply)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto traversableDual() -> boxed {
    return Data_Semigroup_Traversable::Traversable1()([=](const boxed&) -> boxed {
        return Data_Semigroup_Foldable::foldableDual();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableDual();
    })([=](const boxed& dictApply) -> boxed {
        return Data_Semigroup_Traversable::sequence1Default()(Data_Semigroup_Traversable::traversableDual())(dictApply);
    })([=](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApply["Functor0"](undefined))(Data_Monoid_Dual::Dual())(f(v));
            };
        };
    });
};
auto traversableMultiplicative() -> boxed {
    return Data_Semigroup_Traversable::Traversable1()([=](const boxed&) -> boxed {
        return Data_Semigroup_Foldable::foldableMultiplicative();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableMultiplicative();
    })([=](const boxed& dictApply) -> boxed {
        return Data_Semigroup_Traversable::sequence1Default()(Data_Semigroup_Traversable::traversableMultiplicative())(dictApply);
    })([=](const boxed& dictApply) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApply["Functor0"](undefined))(Data_Monoid_Multiplicative::Multiplicative())(f(v));
            };
        };
    });
};
auto sequence1() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["sequence1"];
    };
    return _;
};
auto traverse1Default() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable1) -> boxed {
        return [=](const boxed& dictApply) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& ta) -> boxed {
                    return Data_Semigroup_Traversable::sequence1()(dictTraversable1)(dictApply)(Data_Functor::map()(dictTraversable1["Traversable1"](undefined)["Functor0"](undefined))(f)(ta));
                };
            };
        };
    };
    return _;
};


} // end namespace Data_Semigroup_Traversable


