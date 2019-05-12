#include "Data_Boolean/Data_Boolean.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup_Traversable/Data_Semigroup_Traversable.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"

#include "Data_Unfoldable1/Data_Unfoldable1.h"


namespace Data_Unfoldable1 {

auto Unfoldable1() -> const boxed& {
    static const boxed _ = [](const boxed& unfoldr1) -> boxed {
        return dict_t{
            { "unfoldr1", unfoldr1 }
        };
    };
    return _;
};
auto unfoldr1() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["unfoldr1"];
    };
    return _;
};
auto unfoldable1Array() -> boxed {
    return Data_Unfoldable1::Unfoldable1()(Data_Unfoldable1::unfoldr1ArrayImpl()(Data_Maybe::isNothing())([=](const boxed& dictPartial) -> boxed {
        return Data_Maybe::fromJust()(dictPartial);
    }(undefined))(Data_Tuple::fst())(Data_Tuple::snd()));
};
auto replicate1() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable1) -> boxed {
        return [=](const boxed& n) -> boxed {
            return [=](const boxed& v) -> boxed {
                boxed step = [=](const boxed& i) -> boxed {
                    if (unbox<bool>(Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(i)(0))) {
                        return Data_Tuple::Tuple()(v)(Data_Maybe::Nothing());
                    };
                    return Data_Tuple::Tuple()(v)(Data_Maybe::Just()(unbox<int>(i) - 1));
                };
                return Data_Unfoldable1::unfoldr1()(dictUnfoldable1)(step)(unbox<int>(n) - 1);
            };
        };
    };
    return _;
};
auto replicate1A() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return [=](const boxed& dictUnfoldable1) -> boxed {
            return [=](const boxed& dictTraversable1) -> boxed {
                return [=](const boxed& n) -> boxed {
                    return [=](const boxed& m) -> boxed {
                        return Data_Semigroup_Traversable::sequence1()(dictTraversable1)(dictApply)(Data_Unfoldable1::replicate1()(dictUnfoldable1)(n)(m));
                    };
                };
            };
        };
    };
    return _;
};
auto singleton() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable1) -> boxed {
        return Data_Unfoldable1::replicate1()(dictUnfoldable1)(1);
    };
    return _;
};
auto range() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable1) -> boxed {
        return [=](const boxed& start) -> boxed {
            return [=](const boxed& end) -> boxed {
                boxed go = [=](const boxed& delta) -> boxed {
                    return [=](const boxed& i) -> boxed {
                        boxed i_Prime_ = unbox<int>(i) + unbox<int>(delta);
                        return Data_Tuple::Tuple()(i)([=]() -> boxed {
                            boxed _Local_6 = unbox<int>(i) == unbox<int>(end);
                            if (unbox<bool>(_Local_6)) {
                                return Data_Maybe::Nothing();
                            };
                            return Data_Maybe::Just()(i_Prime_);
                        }());
                    };
                };
                boxed delta = [=]() -> boxed {
                    boxed _Local_7 = Data_Ord::greaterThanOrEq()(Data_Ord::ordInt())(end)(start);
                    if (unbox<bool>(_Local_7)) {
                        return 1;
                    };
                    return -1;
                }();
                return Data_Unfoldable1::unfoldr1()(dictUnfoldable1)(go(delta))(start);
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unfoldr1ArrayImpl() -> const boxed& { static const boxed _ = foreign().at("unfoldr1ArrayImpl"); return _; };

} // end namespace Data_Unfoldable1


