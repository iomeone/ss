#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad_Gen/Control_Monad_Gen.h"
#include "Control_Monad_Gen_Class/Control_Monad_Gen_Class.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Data_Either/Data_Either.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_NonEmpty/Data_NonEmpty.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_Gen_Common/Control_Monad_Gen_Common.h"


namespace Control_Monad_Gen_Common {

auto genTuple() -> const boxed& {
    static const boxed _ = [](const boxed& dictApply) -> boxed {
        return Control_Apply::lift2()(dictApply)(Data_Tuple::Tuple());
    };
    return _;
};
auto genNonEmpty() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return [=](const boxed& dictMonadGen) -> boxed {
            return [=](const boxed& dictUnfoldable) -> boxed {
                return [=](const boxed& gen) -> boxed {
                    return Control_Apply::apply()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined))(Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_NonEmpty::NonEmpty())(gen))(Control_Monad_Gen_Class::resize()(dictMonadGen)([=](const boxed& v) -> boxed {
                        return unbox<int>(v) - 1;
                    })(Control_Monad_Gen::unfoldable()(dictMonadRec)(dictMonadGen)(dictUnfoldable)(gen)));
                };
            };
        };
    };
    return _;
};
auto genMaybe_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return [=](const boxed& bias) -> boxed {
            return [=](const boxed& gen) -> boxed {
                return Control_Bind::bind()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Gen_Class::chooseFloat()(dictMonadGen)(0.0)(1.0))([=](const boxed& v) -> boxed {
                    boxed _Local_6 = Data_Ord::lessThan()(Data_Ord::ordNumber())(v)(bias);
                    if (unbox<bool>(_Local_6)) {
                        return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Maybe::Just())(gen);
                    };
                    return Control_Applicative::pure()(dictMonadGen["Monad0"](undefined)["Applicative0"](undefined))(Data_Maybe::Nothing());
                });
            };
        };
    };
    return _;
};
auto genMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return Control_Monad_Gen_Common::genMaybe_Prime_()(dictMonadGen)(0.75);
    };
    return _;
};
auto genIdentity() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Data_Functor::map()(dictFunctor)(Data_Identity::Identity());
    };
    return _;
};
auto genEither_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return [=](const boxed& bias) -> boxed {
            return [=](const boxed& genA) -> boxed {
                return [=](const boxed& genB) -> boxed {
                    return Control_Bind::bind()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined))(Control_Monad_Gen_Class::chooseFloat()(dictMonadGen)(0.0)(1.0))([=](const boxed& v) -> boxed {
                        boxed _Local_8 = Data_Ord::lessThan()(Data_Ord::ordNumber())(v)(bias);
                        if (unbox<bool>(_Local_8)) {
                            return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Left())(genA);
                        };
                        return Data_Functor::map()(dictMonadGen["Monad0"](undefined)["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Data_Either::Right())(genB);
                    });
                };
            };
        };
    };
    return _;
};
auto genEither() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadGen) -> boxed {
        return Control_Monad_Gen_Common::genEither_Prime_()(dictMonadGen)(0.5);
    };
    return _;
};


} // end namespace Control_Monad_Gen_Common


