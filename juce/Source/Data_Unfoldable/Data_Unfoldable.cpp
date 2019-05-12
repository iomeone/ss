#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable1/Data_Unfoldable1.h"
#include "Data_Unit/Data_Unit.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"

#include "Data_Unfoldable/Data_Unfoldable.h"


namespace Data_Unfoldable {

auto Unfoldable() -> const boxed& {
    static const boxed _ = [](const boxed& Unfoldable10) -> boxed {
        return [=](const boxed& unfoldr) -> boxed {
            return dict_t{
                { "Unfoldable10", Unfoldable10 },
                { "unfoldr", unfoldr }
            };
        };
    };
    return _;
};
auto unfoldr() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["unfoldr"];
    };
    return _;
};
auto unfoldableArray() -> boxed {
    return Data_Unfoldable::Unfoldable()([=](const boxed&) -> boxed {
        return Data_Unfoldable1::unfoldable1Array();
    })(Data_Unfoldable::unfoldrArrayImpl()(Data_Maybe::isNothing())([=](const boxed& dictPartial) -> boxed {
        return Data_Maybe::fromJust()(dictPartial);
    }(undefined))(Data_Tuple::fst())(Data_Tuple::snd()));
};
auto replicate() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return [=](const boxed& n) -> boxed {
            return [=](const boxed& v) -> boxed {
                boxed step = [=](const boxed& i) -> boxed {
                    boxed _Local_5 = Data_Ord::lessThanOrEq()(Data_Ord::ordInt())(i)(0);
                    if (unbox<bool>(_Local_5)) {
                        return Data_Maybe::Nothing();
                    };
                    return Data_Maybe::Just()(Data_Tuple::Tuple()(v)(unbox<int>(i) - 1));
                };
                return Data_Unfoldable::unfoldr()(dictUnfoldable)(step)(n);
            };
        };
    };
    return _;
};
auto replicateA() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& dictUnfoldable) -> boxed {
            return [=](const boxed& dictTraversable) -> boxed {
                return [=](const boxed& n) -> boxed {
                    return [=](const boxed& m) -> boxed {
                        return Data_Traversable::sequence()(dictTraversable)(dictApplicative)(Data_Unfoldable::replicate()(dictUnfoldable)(n)(m));
                    };
                };
            };
        };
    };
    return _;
};
auto none() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return Data_Unfoldable::unfoldr()(dictUnfoldable)(Data_Function::_const_()(Data_Maybe::Nothing()))(Data_Unit::unit());
    };
    return _;
};
auto fromMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictUnfoldable) -> boxed {
        return Data_Unfoldable::unfoldr()(dictUnfoldable)([=](const boxed& b) -> boxed {
            return Data_Functor::map()(Data_Maybe::functorMaybe())(Data_Function::flip()(Data_Tuple::Tuple())(Data_Maybe::Nothing()))(b);
        });
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unfoldrArrayImpl() -> const boxed& { static const boxed _ = foreign().at("unfoldrArrayImpl"); return _; };

} // end namespace Data_Unfoldable


