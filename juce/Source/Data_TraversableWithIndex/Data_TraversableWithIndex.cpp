#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_FoldableWithIndex/Data_FoldableWithIndex.h"
#include "Data_Function/Data_Function.h"
#include "Data_FunctorWithIndex/Data_FunctorWithIndex.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Maybe_First/Data_Maybe_First.h"
#include "Data_Maybe_Last/Data_Maybe_Last.h"
#include "Data_Monoid_Additive/Data_Monoid_Additive.h"
#include "Data_Monoid_Conj/Data_Monoid_Conj.h"
#include "Data_Monoid_Disj/Data_Monoid_Disj.h"
#include "Data_Monoid_Dual/Data_Monoid_Dual.h"
#include "Data_Monoid_Multiplicative/Data_Monoid_Multiplicative.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Data_Traversable_Accum/Data_Traversable_Accum.h"
#include "Data_Traversable_Accum_Internal/Data_Traversable_Accum_Internal.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"

#include "Data_TraversableWithIndex/Data_TraversableWithIndex.h"


namespace Data_TraversableWithIndex {

auto TraversableWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& FoldableWithIndex1) -> boxed {
        return [=](const boxed& FunctorWithIndex0) -> boxed {
            return [=](const boxed& Traversable2) -> boxed {
                return [=](const boxed& traverseWithIndex) -> boxed {
                    return dict_t{
                        { "FoldableWithIndex1", FoldableWithIndex1 },
                        { "FunctorWithIndex0", FunctorWithIndex0 },
                        { "Traversable2", Traversable2 },
                        { "traverseWithIndex", traverseWithIndex }
                    };
                };
            };
        };
    };
    return _;
};
auto traverseWithIndexDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversableWithIndex) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Traversable::sequence()(dictTraversableWithIndex["Traversable2"](undefined))(dictApplicative))(Data_FunctorWithIndex::mapWithIndex()(dictTraversableWithIndex["FunctorWithIndex0"](undefined))(f));
            };
        };
    };
    return _;
};
auto traverseWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["traverseWithIndex"];
    };
    return _;
};
auto traverseDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversableWithIndex) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_TraversableWithIndex::traverseWithIndex()(dictTraversableWithIndex)(dictApplicative)(Data_Function::_const_()(f));
            };
        };
    };
    return _;
};
auto traversableWithIndexMultiplicative() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_FoldableWithIndex::foldableWithIndexMultiplicative();
    })([=](const boxed&) -> boxed {
        return Data_FunctorWithIndex::functorWithIndexMultiplicative();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableMultiplicative();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Traversable::traverse()(Data_Traversable::traversableMultiplicative())(dictApplicative)(f(Data_Unit::unit()));
        };
    });
};
auto traversableWithIndexMaybe() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_FoldableWithIndex::foldableWithIndexMaybe();
    })([=](const boxed&) -> boxed {
        return Data_FunctorWithIndex::functorWithIndexMaybe();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableMaybe();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Traversable::traverse()(Data_Traversable::traversableMaybe())(dictApplicative)(f(Data_Unit::unit()));
        };
    });
};
auto traversableWithIndexLast() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_FoldableWithIndex::foldableWithIndexLast();
    })([=](const boxed&) -> boxed {
        return Data_FunctorWithIndex::functorWithIndexLast();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableLast();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Traversable::traverse()(Data_Traversable::traversableLast())(dictApplicative)(f(Data_Unit::unit()));
        };
    });
};
auto traversableWithIndexFirst() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_FoldableWithIndex::foldableWithIndexFirst();
    })([=](const boxed&) -> boxed {
        return Data_FunctorWithIndex::functorWithIndexFirst();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableFirst();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Traversable::traverse()(Data_Traversable::traversableFirst())(dictApplicative)(f(Data_Unit::unit()));
        };
    });
};
auto traversableWithIndexDual() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_FoldableWithIndex::foldableWithIndexDual();
    })([=](const boxed&) -> boxed {
        return Data_FunctorWithIndex::functorWithIndexDual();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableDual();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Traversable::traverse()(Data_Traversable::traversableDual())(dictApplicative)(f(Data_Unit::unit()));
        };
    });
};
auto traversableWithIndexDisj() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_FoldableWithIndex::foldableWithIndexDisj();
    })([=](const boxed&) -> boxed {
        return Data_FunctorWithIndex::functorWithIndexDisj();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableDisj();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Traversable::traverse()(Data_Traversable::traversableDisj())(dictApplicative)(f(Data_Unit::unit()));
        };
    });
};
auto traversableWithIndexConj() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_FoldableWithIndex::foldableWithIndexConj();
    })([=](const boxed&) -> boxed {
        return Data_FunctorWithIndex::functorWithIndexConj();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableConj();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Traversable::traverse()(Data_Traversable::traversableConj())(dictApplicative)(f(Data_Unit::unit()));
        };
    });
};
auto traversableWithIndexArray() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_FoldableWithIndex::foldableWithIndexArray();
    })([=](const boxed&) -> boxed {
        return Data_FunctorWithIndex::functorWithIndexArray();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableArray();
    })([=](const boxed& dictApplicative) -> boxed {
        return Data_TraversableWithIndex::traverseWithIndexDefault()(Data_TraversableWithIndex::traversableWithIndexArray())(dictApplicative);
    });
};
auto traversableWithIndexAdditive() -> boxed {
    return Data_TraversableWithIndex::TraversableWithIndex()([=](const boxed&) -> boxed {
        return Data_FoldableWithIndex::foldableWithIndexAdditive();
    })([=](const boxed&) -> boxed {
        return Data_FunctorWithIndex::functorWithIndexAdditive();
    })([=](const boxed&) -> boxed {
        return Data_Traversable::traversableAdditive();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Traversable::traverse()(Data_Traversable::traversableAdditive())(dictApplicative)(f(Data_Unit::unit()));
        };
    });
};
auto mapAccumRWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversableWithIndex) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& s0) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Traversable_Accum_Internal::stateR()(Data_TraversableWithIndex::traverseWithIndex()(dictTraversableWithIndex)(Data_Traversable_Accum_Internal::applicativeStateR())([=](const boxed& i) -> boxed {
                        return [=](const boxed& a) -> boxed {
                            return [=](const boxed& s) -> boxed {
                                return f(i)(s)(a);
                            };
                        };
                    })(xs))(s0);
                };
            };
        };
    };
    return _;
};
auto scanrWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversableWithIndex) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& b0) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_TraversableWithIndex::mapAccumRWithIndex()(dictTraversableWithIndex)([=](const boxed& i) -> boxed {
                        return [=](const boxed& b) -> boxed {
                            return [=](const boxed& a) -> boxed {
                                boxed b_Prime_ = f(i)(a)(b);
                                return dict_t{
                                    { "accum", b_Prime_ },
                                    { "value", b_Prime_ }
                                };
                            };
                        };
                    })(b0)(xs)["value"];
                };
            };
        };
    };
    return _;
};
auto mapAccumLWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversableWithIndex) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& s0) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Traversable_Accum_Internal::stateL()(Data_TraversableWithIndex::traverseWithIndex()(dictTraversableWithIndex)(Data_Traversable_Accum_Internal::applicativeStateL())([=](const boxed& i) -> boxed {
                        return [=](const boxed& a) -> boxed {
                            return [=](const boxed& s) -> boxed {
                                return f(i)(s)(a);
                            };
                        };
                    })(xs))(s0);
                };
            };
        };
    };
    return _;
};
auto scanlWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversableWithIndex) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& b0) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_TraversableWithIndex::mapAccumLWithIndex()(dictTraversableWithIndex)([=](const boxed& i) -> boxed {
                        return [=](const boxed& b) -> boxed {
                            return [=](const boxed& a) -> boxed {
                                boxed b_Prime_ = f(i)(b)(a);
                                return dict_t{
                                    { "accum", b_Prime_ },
                                    { "value", b_Prime_ }
                                };
                            };
                        };
                    })(b0)(xs)["value"];
                };
            };
        };
    };
    return _;
};
auto forWithIndex() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& dictTraversableWithIndex) -> boxed {
            return Data_Function::flip()(Data_TraversableWithIndex::traverseWithIndex()(dictTraversableWithIndex)(dictApplicative));
        };
    };
    return _;
};


} // end namespace Data_TraversableWithIndex


