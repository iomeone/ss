#include "Control_Apply/Control_Apply.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Unit/Data_Unit.h"

#include "Control_Applicative/Control_Applicative.h"


namespace Control_Applicative {

auto Applicative() -> const boxed& {
    static const boxed _ = [](const boxed& Apply0) -> boxed {
        return [=](const boxed& pure) -> boxed {
            return dict_t{
                { "Apply0", Apply0 },
                { "pure", pure }
            };
        };
    };
    return _;
};
auto pure() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["pure"];
    };
    return _;
};
auto unless() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (!(unbox<bool>(v))) {
                    return v1;
                };
                if (unbox<bool>(v)) {
                    return Control_Applicative::pure()(dictApplicative)(Data_Unit::unit());
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Applicative (line 62, column 1 - line 62, column 65): ");
            };
        };
    };
    return _;
};
auto when() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& v1) -> boxed {
                if (unbox<bool>(v)) {
                    return v1;
                };
                if (!(unbox<bool>(v))) {
                    return Control_Applicative::pure()(dictApplicative)(Data_Unit::unit());
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Control.Applicative (line 57, column 1 - line 57, column 63): ");
            };
        };
    };
    return _;
};
auto liftA1() -> const boxed& {
    static const boxed _ = [](const boxed& dictApplicative) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& a) -> boxed {
                return Control_Apply::apply()(dictApplicative["Apply0"](undefined))(Control_Applicative::pure()(dictApplicative)(f))(a);
            };
        };
    };
    return _;
};
auto applicativeFn() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Control_Apply::applyFn();
    })([=](const boxed& x) -> boxed {
        return [=](const boxed& v) -> boxed {
            return x;
        };
    });
};
auto applicativeArray() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Control_Apply::applyArray();
    })([=](const boxed& x) -> boxed {
        return array_t{ x };
    });
};


} // end namespace Control_Applicative


