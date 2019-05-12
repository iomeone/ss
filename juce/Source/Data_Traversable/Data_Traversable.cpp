#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Category/Control_Category.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Maybe_First/Data_Maybe_First.h"
#include "Data_Maybe_Last/Data_Maybe_Last.h"
#include "Data_Monoid_Additive/Data_Monoid_Additive.h"
#include "Data_Monoid_Conj/Data_Monoid_Conj.h"
#include "Data_Monoid_Disj/Data_Monoid_Disj.h"
#include "Data_Monoid_Dual/Data_Monoid_Dual.h"
#include "Data_Monoid_Multiplicative/Data_Monoid_Multiplicative.h"
#include "Data_Traversable_Accum/Data_Traversable_Accum.h"
#include "Data_Traversable_Accum_Internal/Data_Traversable_Accum_Internal.h"
#include "Prelude/Prelude.h"

#include "Data_Traversable/Data_Traversable.h"


namespace Data_Traversable {

auto Traversable() -> const boxed& {
    static const boxed _ = [](const boxed& Foldable1) -> boxed {
        return [=](const boxed& Functor0) -> boxed {
            return [=](const boxed& sequence) -> boxed {
                return [=](const boxed& traverse) -> boxed {
                    return dict_t{
                        { "Foldable1", Foldable1 },
                        { "Functor0", Functor0 },
                        { "sequence", sequence },
                        { "traverse", traverse }
                    };
                };
            };
        };
    };
    return _;
};
auto traverse() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["traverse"];
    };
    return _;
};
auto traversableMultiplicative() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableMultiplicative();
    })([=](const boxed&) -> boxed {
        return Data_Monoid_Multiplicative::functorMultiplicative();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Multiplicative::Multiplicative())(v);
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Multiplicative::Multiplicative())(f(v));
            };
        };
    });
};
auto traversableMaybe() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableMaybe();
    })([=](const boxed&) -> boxed {
        return Data_Maybe::functorMaybe();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Nothing")) {
                return Control_Applicative::pure()(dictApplicative)(Data_Maybe::Nothing());
            };
            if (unbox<dict_t>(v).contains("Just")) {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Maybe::Just())(v["value0"]);
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Traversable (line 86, column 1 - line 86, column 47): ");
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<dict_t>(v1).contains("Nothing")) {
                    return Control_Applicative::pure()(dictApplicative)(Data_Maybe::Nothing());
                };
                if (unbox<dict_t>(v1).contains("Just")) {
                    return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Maybe::Just())(v(v1["value0"]));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Traversable (line 86, column 1 - line 86, column 47): ");
            };
        };
    });
};
auto traversableDual() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableDual();
    })([=](const boxed&) -> boxed {
        return Data_Monoid_Dual::functorDual();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Dual::Dual())(v);
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Dual::Dual())(f(v));
            };
        };
    });
};
auto traversableDisj() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableDisj();
    })([=](const boxed&) -> boxed {
        return Data_Monoid_Disj::functorDisj();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Disj::Disj())(v);
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Disj::Disj())(f(v));
            };
        };
    });
};
auto traversableConj() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableConj();
    })([=](const boxed&) -> boxed {
        return Data_Monoid_Conj::functorConj();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Conj::Conj())(v);
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Conj::Conj())(f(v));
            };
        };
    });
};
auto traversableAdditive() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableAdditive();
    })([=](const boxed&) -> boxed {
        return Data_Monoid_Additive::functorAdditive();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Additive::Additive())(v);
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Monoid_Additive::Additive())(f(v));
            };
        };
    });
};
auto sequenceDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return Data_Traversable::traverse()(dictTraversable)(dictApplicative)(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto traversableArray() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableArray();
    })([=](const boxed&) -> boxed {
        return Data_Functor::functorArray();
    })([=](const boxed& dictApplicative) -> boxed {
        return Data_Traversable::sequenceDefault()(Data_Traversable::traversableArray())(dictApplicative);
    })([=](const boxed& dictApplicative) -> boxed {
        return Data_Traversable::traverseArrayImpl()(Control_Apply::apply()(dictApplicative["Apply0"](undefined)))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined)))(Control_Applicative::pure()(dictApplicative));
    });
};
auto sequence() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["sequence"];
    };
    return _;
};
auto traversableFirst() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableFirst();
    })([=](const boxed&) -> boxed {
        return Data_Maybe_First::functorFirst();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Maybe_First::First())(Data_Traversable::sequence()(Data_Traversable::traversableMaybe())(dictApplicative)(v));
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Maybe_First::First())(Data_Traversable::traverse()(Data_Traversable::traversableMaybe())(dictApplicative)(f)(v));
            };
        };
    });
};
auto traversableLast() -> boxed {
    return Data_Traversable::Traversable()([=](const boxed&) -> boxed {
        return Data_Foldable::foldableLast();
    })([=](const boxed&) -> boxed {
        return Data_Maybe_Last::functorLast();
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Maybe_Last::Last())(Data_Traversable::sequence()(Data_Traversable::traversableMaybe())(dictApplicative)(v));
        };
    })([=](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Maybe_Last::Last())(Data_Traversable::traverse()(Data_Traversable::traversableMaybe())(dictApplicative)(f)(v));
            };
        };
    });
};
auto traverseDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& ta) -> boxed {
                    return Data_Traversable::sequence()(dictTraversable)(dictApplicative)(Data_Functor::map()(dictTraversable["Functor0"](undefined))(f)(ta));
                };
            };
        };
    };
    return _;
};
auto mapAccumR() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& s0) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Traversable_Accum_Internal::stateR()(Data_Traversable::traverse()(dictTraversable)(Data_Traversable_Accum_Internal::applicativeStateR())([=](const boxed& a) -> boxed {
                        return [=](const boxed& s) -> boxed {
                            return f(s)(a);
                        };
                    })(xs))(s0);
                };
            };
        };
    };
    return _;
};
auto scanr() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& b0) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Traversable::mapAccumR()(dictTraversable)([=](const boxed& b) -> boxed {
                        return [=](const boxed& a) -> boxed {
                            boxed b_Prime_ = f(a)(b);
                            return dict_t{
                                { "accum", b_Prime_ },
                                { "value", b_Prime_ }
                            };
                        };
                    })(b0)(xs)["value"];
                };
            };
        };
    };
    return _;
};
auto mapAccumL() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& s0) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Traversable_Accum_Internal::stateL()(Data_Traversable::traverse()(dictTraversable)(Data_Traversable_Accum_Internal::applicativeStateL())([=](const boxed& a) -> boxed {
                        return [=](const boxed& s) -> boxed {
                            return f(s)(a);
                        };
                    })(xs))(s0);
                };
            };
        };
    };
    return _;
};
auto scanl() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& b0) -> boxed {
                return [=](const boxed& xs) -> boxed {
                    return Data_Traversable::mapAccumL()(dictTraversable)([=](const boxed& b) -> boxed {
                        return [=](const boxed& a) -> boxed {
                            boxed b_Prime_ = f(b)(a);
                            return dict_t{
                                { "accum", b_Prime_ },
                                { "value", b_Prime_ }
                            };
                        };
                    })(b0)(xs)["value"];
                };
            };
        };
    };
    return _;
};
auto _for_() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& dictTraversable) -> boxed {
            return [=](const boxed& x) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Data_Traversable::traverse()(dictTraversable)(dictApplicative)(f)(x);
                };
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto traverseArrayImpl() -> const boxed& { static const boxed _ = foreign().at("traverseArrayImpl"); return _; };

} // end namespace Data_Traversable


