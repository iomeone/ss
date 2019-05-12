#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Maybe_First/Data_Maybe_First.h"
#include "Data_Maybe_Last/Data_Maybe_Last.h"
#include "Data_Monoid_Additive/Data_Monoid_Additive.h"
#include "Data_Monoid_Conj/Data_Monoid_Conj.h"
#include "Data_Monoid_Disj/Data_Monoid_Disj.h"
#include "Data_Monoid_Dual/Data_Monoid_Dual.h"
#include "Data_Monoid_Multiplicative/Data_Monoid_Multiplicative.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"


namespace Data_FunctorWithIndex {

auto FunctorWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& Functor0) -> boxed {
        return [=](const boxed& mapWithIndex) -> boxed {
            return dict_t{
                { "Functor0", Functor0 },
                { "mapWithIndex", mapWithIndex }
            };
        };
    };
    return _;
};
auto mapWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["mapWithIndex"];
    };
    return _;
};
auto mapDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctorWithIndex) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_FunctorWithIndex::mapWithIndex()(dictFunctorWithIndex)(Data_Function::_const_()(f));
        };
    };
    return _;
};
auto functorWithIndexMultiplicative() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Monoid_Multiplicative::functorMultiplicative();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Monoid_Multiplicative::functorMultiplicative())(f(Data_Unit::unit()));
    });
};
auto functorWithIndexMaybe() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Maybe::functorMaybe();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Maybe::functorMaybe())(f(Data_Unit::unit()));
    });
};
auto functorWithIndexLast() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Maybe_Last::functorLast();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Maybe_Last::functorLast())(f(Data_Unit::unit()));
    });
};
auto functorWithIndexFirst() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Maybe_First::functorFirst();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Maybe_First::functorFirst())(f(Data_Unit::unit()));
    });
};
auto functorWithIndexDual() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Monoid_Dual::functorDual();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Monoid_Dual::functorDual())(f(Data_Unit::unit()));
    });
};
auto functorWithIndexDisj() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Monoid_Disj::functorDisj();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Monoid_Disj::functorDisj())(f(Data_Unit::unit()));
    });
};
auto functorWithIndexConj() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Monoid_Conj::functorConj();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Monoid_Conj::functorConj())(f(Data_Unit::unit()));
    });
};
auto functorWithIndexArray() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Functor::functorArray();
    })(Data_FunctorWithIndex::mapWithIndexArray());
};
auto functorWithIndexAdditive() -> boxed {
    return Data_FunctorWithIndex::FunctorWithIndex()([=](const boxed&) -> boxed {
        return Data_Monoid_Additive::functorAdditive();
    })([=](const boxed& f) -> boxed {
        return Data_Functor::map()(Data_Monoid_Additive::functorAdditive())(f(Data_Unit::unit()));
    });
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto mapWithIndexArray() -> const boxed& { static const boxed _ = foreign().at("mapWithIndexArray"); return _; };

} // end namespace Data_FunctorWithIndex


