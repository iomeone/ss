#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Monoid_Additive/Data_Monoid_Additive.h"
#include "Data_Monoid_Conj/Data_Monoid_Conj.h"
#include "Data_Monoid_Disj/Data_Monoid_Disj.h"
#include "Data_Monoid_Dual/Data_Monoid_Dual.h"
#include "Data_Monoid_Endo/Data_Monoid_Endo.h"
#include "Data_Monoid_Multiplicative/Data_Monoid_Multiplicative.h"
#include "Data_Semigroup_First/Data_Semigroup_First.h"
#include "Data_Semigroup_Last/Data_Semigroup_Last.h"
#include "Prelude/Prelude.h"

#include "Data_Newtype/Data_Newtype.h"


namespace Data_Newtype {

auto Newtype() -> const boxed& {
    static const boxed _ = [](const boxed& unwrap) -> boxed {
        return [=](const boxed& wrap) -> boxed {
            return dict_t{
                { "unwrap", unwrap },
                { "wrap", wrap }
            };
        };
    };
    return _;
};
auto wrap() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["wrap"];
    };
    return _;
};
auto unwrap() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["unwrap"];
    };
    return _;
};
auto underF2() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& dictFunctor1) -> boxed {
            return [=](const boxed& dictNewtype) -> boxed {
                return [=](const boxed& dictNewtype1) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictFunctor1)(Data_Newtype::unwrap()(dictNewtype1))))(Data_Function::on()(f)(Data_Functor::map()(dictFunctor)(Data_Newtype::wrap()(dictNewtype))));
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto underF() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& dictFunctor1) -> boxed {
            return [=](const boxed& dictNewtype) -> boxed {
                return [=](const boxed& dictNewtype1) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictFunctor1)(Data_Newtype::unwrap()(dictNewtype1)))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Functor::map()(dictFunctor)(Data_Newtype::wrap()(dictNewtype))));
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto under2() -> const boxed& {
    static const boxed _ = [](const boxed& dictNewtype) -> boxed {
        return [=](const boxed& dictNewtype1) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(dictNewtype1)))(Data_Function::on()(f)(Data_Newtype::wrap()(dictNewtype)));
                };
            };
        };
    };
    return _;
};
auto under() -> const boxed& {
    static const boxed _ = [](const boxed& dictNewtype) -> boxed {
        return [=](const boxed& dictNewtype1) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(dictNewtype1))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Newtype::wrap()(dictNewtype)));
                };
            };
        };
    };
    return _;
};
auto un() -> const boxed& {
    static const boxed _ = [](const boxed& dictNewtype) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Data_Newtype::unwrap()(dictNewtype);
        };
    };
    return _;
};
auto traverse() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& dictNewtype) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictFunctor)(Data_Newtype::wrap()(dictNewtype)))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Newtype::unwrap()(dictNewtype)));
                };
            };
        };
    };
    return _;
};
auto overF2() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& dictFunctor1) -> boxed {
            return [=](const boxed& dictNewtype) -> boxed {
                return [=](const boxed& dictNewtype1) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictFunctor1)(Data_Newtype::wrap()(dictNewtype1))))(Data_Function::on()(f)(Data_Functor::map()(dictFunctor)(Data_Newtype::unwrap()(dictNewtype))));
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto overF() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& dictFunctor1) -> boxed {
            return [=](const boxed& dictNewtype) -> boxed {
                return [=](const boxed& dictNewtype1) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictFunctor1)(Data_Newtype::wrap()(dictNewtype1)))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Functor::map()(dictFunctor)(Data_Newtype::unwrap()(dictNewtype))));
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto over2() -> const boxed& {
    static const boxed _ = [](const boxed& dictNewtype) -> boxed {
        return [=](const boxed& dictNewtype1) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::wrap()(dictNewtype1)))(Data_Function::on()(f)(Data_Newtype::unwrap()(dictNewtype)));
                };
            };
        };
    };
    return _;
};
auto over() -> const boxed& {
    static const boxed _ = [](const boxed& dictNewtype) -> boxed {
        return [=](const boxed& dictNewtype1) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::wrap()(dictNewtype1))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Newtype::unwrap()(dictNewtype)));
                };
            };
        };
    };
    return _;
};
auto op() -> const boxed& {
    static const boxed _ = [](const boxed& dictNewtype) -> boxed {
        return Data_Newtype::un()(dictNewtype);
    };
    return _;
};
auto newtypeMultiplicative() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& v) -> boxed {
        return v;
    })(Data_Monoid_Multiplicative::Multiplicative());
};
auto newtypeLast() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& v) -> boxed {
        return v;
    })(Data_Semigroup_Last::Last());
};
auto newtypeFirst() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& v) -> boxed {
        return v;
    })(Data_Semigroup_First::First());
};
auto newtypeEndo() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& v) -> boxed {
        return v;
    })(Data_Monoid_Endo::Endo());
};
auto newtypeDual() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& v) -> boxed {
        return v;
    })(Data_Monoid_Dual::Dual());
};
auto newtypeDisj() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& v) -> boxed {
        return v;
    })(Data_Monoid_Disj::Disj());
};
auto newtypeConj() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& v) -> boxed {
        return v;
    })(Data_Monoid_Conj::Conj());
};
auto newtypeAdditive() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& v) -> boxed {
        return v;
    })(Data_Monoid_Additive::Additive());
};
auto collect() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& dictNewtype) -> boxed {
            return [=](const boxed& v) -> boxed {
                return [=](const boxed& f) -> boxed {
                    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::wrap()(dictNewtype))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Functor::map()(dictFunctor)(Data_Newtype::unwrap()(dictNewtype))));
                };
            };
        };
    };
    return _;
};
auto alaF() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& dictFunctor1) -> boxed {
            return [=](const boxed& dictNewtype) -> boxed {
                return [=](const boxed& dictNewtype1) -> boxed {
                    return [=](const boxed& v) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(dictFunctor1)(Data_Newtype::unwrap()(dictNewtype1)))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(f)(Data_Functor::map()(dictFunctor)(Data_Newtype::wrap()(dictNewtype))));
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto ala() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return [=](const boxed& dictNewtype) -> boxed {
            return [=](const boxed& dictNewtype1) -> boxed {
                return [=](const boxed& v) -> boxed {
                    return [=](const boxed& f) -> boxed {
                        return Data_Functor::map()(dictFunctor)(Data_Newtype::unwrap()(dictNewtype))(f(Data_Newtype::wrap()(dictNewtype1)));
                    };
                };
            };
        };
    };
    return _;
};


} // end namespace Data_Newtype


