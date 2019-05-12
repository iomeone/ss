#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Traversable_Accum/Data_Traversable_Accum.h"
#include "Prelude/Prelude.h"

#include "Data_Traversable_Accum_Internal/Data_Traversable_Accum_Internal.h"


namespace Data_Traversable_Accum_Internal {

auto StateR() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto StateL() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto stateR() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto stateL() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto functorStateR() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& k) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed v = Data_Traversable_Accum_Internal::stateR()(k)(s);
                return dict_t{
                    { "accum", v["accum"] },
                    { "value", f(v["value"]) }
                };
            };
        };
    });
};
auto functorStateL() -> boxed {
    return Data_Functor::Functor()([=](const boxed& f) -> boxed {
        return [=](const boxed& k) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed v = Data_Traversable_Accum_Internal::stateL()(k)(s);
                return dict_t{
                    { "accum", v["accum"] },
                    { "value", f(v["value"]) }
                };
            };
        };
    });
};
auto applyStateR() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Traversable_Accum_Internal::functorStateR();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed v = Data_Traversable_Accum_Internal::stateR()(x)(s);
                boxed v1 = Data_Traversable_Accum_Internal::stateR()(f)(v["accum"]);
                return dict_t{
                    { "accum", v1["accum"] },
                    { "value", v1["value"](v["value"]) }
                };
            };
        };
    });
};
auto applyStateL() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Data_Traversable_Accum_Internal::functorStateL();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& s) -> boxed {
                boxed v = Data_Traversable_Accum_Internal::stateL()(f)(s);
                boxed v1 = Data_Traversable_Accum_Internal::stateL()(x)(v["accum"]);
                return dict_t{
                    { "accum", v1["accum"] },
                    { "value", v["value"](v1["value"]) }
                };
            };
        };
    });
};
auto applicativeStateR() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Traversable_Accum_Internal::applyStateR();
    })([=](const boxed& a) -> boxed {
        return [=](const boxed& s) -> boxed {
            return dict_t{
                { "accum", s },
                { "value", a }
            };
        };
    });
};
auto applicativeStateL() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Data_Traversable_Accum_Internal::applyStateL();
    })([=](const boxed& a) -> boxed {
        return [=](const boxed& s) -> boxed {
            return dict_t{
                { "accum", s },
                { "value", a }
            };
        };
    });
};


} // end namespace Data_Traversable_Accum_Internal


