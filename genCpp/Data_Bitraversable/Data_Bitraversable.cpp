#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Category/Control_Category.h"
#include "Data_Bifoldable/Data_Bifoldable.h"
#include "Data_Bifunctor/Data_Bifunctor.h"
#include "Data_Bifunctor_Clown/Data_Bifunctor_Clown.h"
#include "Data_Bifunctor_Flip/Data_Bifunctor_Flip.h"
#include "Data_Bifunctor_Joker/Data_Bifunctor_Joker.h"
#include "Data_Bifunctor_Product/Data_Bifunctor_Product.h"
#include "Data_Bifunctor_Wrap/Data_Bifunctor_Wrap.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Traversable/Data_Traversable.h"
#include "Prelude/Prelude.h"

#include "Data_Bitraversable/Data_Bitraversable.h"


namespace Data_Bitraversable {

auto Bitraversable() -> const boxed& {
    static const boxed _ = [](const boxed& Bifoldable1) -> boxed {
        return [=](const boxed& Bifunctor0) -> boxed {
            return [=](const boxed& bisequence) -> boxed {
                return [=](const boxed& bitraverse) -> boxed {
                    return dict_t{
                        { "Bifoldable1", Bifoldable1 },
                        { "Bifunctor0", Bifunctor0 },
                        { "bisequence", bisequence },
                        { "bitraverse", bitraverse }
                    };
                };
            };
        };
    };
    return _;
};
auto bitraverse() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["bitraverse"];
    };
    return _;
};
auto lfor() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& t) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Data_Bitraversable::bitraverse()(dictBitraversable)(dictApplicative)(f)(Control_Applicative::pure()(dictApplicative))(t);
                };
            };
        };
    };
    return _;
};
auto ltraverse() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Data_Bitraversable::bitraverse()(dictBitraversable)(dictApplicative)(f)(Control_Applicative::pure()(dictApplicative));
            };
        };
    };
    return _;
};
auto rfor() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& t) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Data_Bitraversable::bitraverse()(dictBitraversable)(dictApplicative)(Control_Applicative::pure()(dictApplicative))(f)(t);
                };
            };
        };
    };
    return _;
};
auto rtraverse() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return Data_Bitraversable::bitraverse()(dictBitraversable)(dictApplicative)(Control_Applicative::pure()(dictApplicative));
        };
    };
    return _;
};
auto bitraversableJoker() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return Data_Bitraversable::Bitraversable()([=](const boxed&) -> boxed {
            return Data_Bifoldable::bifoldableJoker()(dictTraversable["Foldable1"](undefined));
        })([=](const boxed&) -> boxed {
            return Data_Bifunctor_Joker::bifunctorJoker()(dictTraversable["Functor0"](undefined));
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Joker::Joker())(Data_Traversable::sequence()(dictTraversable)(dictApplicative)(v));
            };
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Joker::Joker())(Data_Traversable::traverse()(dictTraversable)(dictApplicative)(r)(v1));
                    };
                };
            };
        });
    };
    return _;
};
auto bitraversableClown() -> const boxed& {
    static const boxed _ = [](const boxed& dictTraversable) -> boxed {
        return Data_Bitraversable::Bitraversable()([=](const boxed&) -> boxed {
            return Data_Bifoldable::bifoldableClown()(dictTraversable["Foldable1"](undefined));
        })([=](const boxed&) -> boxed {
            return Data_Bifunctor_Clown::bifunctorClown()(dictTraversable["Functor0"](undefined));
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Clown::Clown())(Data_Traversable::sequence()(dictTraversable)(dictApplicative)(v));
            };
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& l) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return [=](const boxed& v1) -> boxed {
                        return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Clown::Clown())(Data_Traversable::traverse()(dictTraversable)(dictApplicative)(l)(v1));
                    };
                };
            };
        });
    };
    return _;
};
auto bisequenceDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return Data_Bitraversable::bitraverse()(dictBitraversable)(dictApplicative)(Control_Category::identity()(Control_Category::categoryFn()))(Control_Category::identity()(Control_Category::categoryFn()));
        };
    };
    return _;
};
auto bisequence() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["bisequence"];
    };
    return _;
};
auto bitraversableFlip() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return Data_Bitraversable::Bitraversable()([=](const boxed&) -> boxed {
            return Data_Bifoldable::bifoldableFlip()(dictBitraversable["Bifoldable1"](undefined));
        })([=](const boxed&) -> boxed {
            return Data_Bifunctor_Flip::bifunctorFlip()(dictBitraversable["Bifunctor0"](undefined));
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Flip::Flip())(Data_Bitraversable::bisequence()(dictBitraversable)(dictApplicative)(v));
            };
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& r) -> boxed {
                return [=](const boxed& l) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Flip::Flip())(Data_Bitraversable::bitraverse()(dictBitraversable)(dictApplicative)(l)(r)(v));
                    };
                };
            };
        });
    };
    return _;
};
auto bitraversableProduct() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return [=](const boxed& dictBitraversable1) -> boxed {
            return Data_Bitraversable::Bitraversable()([=](const boxed&) -> boxed {
                return Data_Bifoldable::bifoldableProduct()(dictBitraversable["Bifoldable1"](undefined))(dictBitraversable1["Bifoldable1"](undefined));
            })([=](const boxed&) -> boxed {
                return Data_Bifunctor_Product::bifunctorProduct()(dictBitraversable["Bifunctor0"](undefined))(dictBitraversable1["Bifunctor0"](undefined));
            })([=](const boxed& dictApplicative) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Product::Product())(Data_Bitraversable::bisequence()(dictBitraversable)(dictApplicative)(v["value0"])))(Data_Bitraversable::bisequence()(dictBitraversable1)(dictApplicative)(v["value1"]));
                };
            })([=](const boxed& dictApplicative) -> boxed {
                return [=](const boxed& l) -> boxed {
                    return [=](const boxed& r) -> boxed {
                        return [=](const boxed& v) -> boxed {
                            return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Product::Product())(Data_Bitraversable::bitraverse()(dictBitraversable)(dictApplicative)(l)(r)(v["value0"])))(Data_Bitraversable::bitraverse()(dictBitraversable1)(dictApplicative)(l)(r)(v["value1"]));
                        };
                    };
                };
            });
        };
    };
    return _;
};
auto bitraversableWrap() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return Data_Bitraversable::Bitraversable()([=](const boxed&) -> boxed {
            return Data_Bifoldable::bifoldableWrap()(dictBitraversable["Bifoldable1"](undefined));
        })([=](const boxed&) -> boxed {
            return Data_Bifunctor_Wrap::bifunctorWrap()(dictBitraversable["Bifunctor0"](undefined));
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& v) -> boxed {
                return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Wrap::Wrap())(Data_Bitraversable::bisequence()(dictBitraversable)(dictApplicative)(v));
            };
        })([=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& l) -> boxed {
                return [=](const boxed& r) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return Data_Functor::map()(dictApplicative["Apply0"](undefined)["Functor0"](undefined))(Data_Bifunctor_Wrap::Wrap())(Data_Bitraversable::bitraverse()(dictBitraversable)(dictApplicative)(l)(r)(v));
                    };
                };
            };
        });
    };
    return _;
};
auto bitraverseDefault() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& g) -> boxed {
                    return [=](const boxed& t) -> boxed {
                        return Data_Bitraversable::bisequence()(dictBitraversable)(dictApplicative)(Data_Bifunctor::bimap()(dictBitraversable["Bifunctor0"](undefined))(f)(g)(t));
                    };
                };
            };
        };
    };
    return _;
};
auto bifor() -> const boxed& {
    static const boxed _ = [](const boxed& dictBitraversable) -> boxed {
        return [=](const boxed& dictApplicative) -> boxed {
            return [=](const boxed& t) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return [=](const boxed& g) -> boxed {
                        return Data_Bitraversable::bitraverse()(dictBitraversable)(dictApplicative)(f)(g)(t);
                    };
                };
            };
        };
    };
    return _;
};


} // end namespace Data_Bitraversable


