#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad_ST/Control_Monad_ST.h"
#include "Control_Monad_ST_Internal/Control_Monad_ST_Internal.h"
#include "Control_Monad_ST_Ref/Control_Monad_ST_Ref.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Array_ST/Data_Array_ST.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Prelude/Prelude.h"

#include "Data_Array_ST_Iterator/Data_Array_ST_Iterator.h"


namespace Data_Array_ST_Iterator {

auto Iterator() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "Iterator", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto _peek_() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Control_Monad_ST_Internal::read()(v["value1"]))([=](const boxed& v1) -> boxed {
            return Control_Applicative::pure()(Control_Monad_ST_Internal::applicativeST())(v["value0"](v1));
        });
    };
    return _;
};
auto next() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Control_Monad_ST_Internal::read()(v["value1"]))([=](const boxed& v1) -> boxed {
            return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Control_Monad_ST_Internal::modify()([=](const boxed& v2) -> boxed {
                return unbox<int>(v2) + 1;
            })(v["value1"]))([=](const boxed& v2) -> boxed {
                return Control_Applicative::pure()(Control_Monad_ST_Internal::applicativeST())(v["value0"](v1));
            });
        });
    };
    return _;
};
auto pushWhile() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return [=](const boxed& iter) -> boxed {
            return [=](const boxed& array) -> boxed {
                return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Control_Monad_ST_Internal::_new_()(false))([=](const boxed& v) -> boxed {
                    return Control_Monad_ST_Internal::_while_()(Data_Functor::map()(Control_Monad_ST_Internal::functorST())(Data_HeytingAlgebra::_not_()(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Control_Monad_ST_Internal::read()(v)))(Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST_Iterator::_peek_()(iter))([=](const boxed& v1) -> boxed {
                        if (unbox<dict_t>(v1).contains("Just")) {
                            if (unbox<bool>(p(v1["value0"]))) {
                                return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::push()(v1["value0"])(array))([=](const boxed& v2) -> boxed {
                                    return Data_Functor::_void_()(Control_Monad_ST_Internal::functorST())(Data_Array_ST_Iterator::next()(iter));
                                });
                            };
                        };
                        return Data_Functor::_void_()(Control_Monad_ST_Internal::functorST())(Control_Monad_ST_Internal::write()(true)(v));
                    }));
                });
            };
        };
    };
    return _;
};
auto pushAll() -> boxed {
    return Data_Array_ST_Iterator::pushWhile()(Data_Function::_const_()(true));
};
auto iterator() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Data_Functor::map()(Control_Monad_ST_Internal::functorST())(Data_Array_ST_Iterator::Iterator()(f))(Control_Monad_ST_Internal::_new_()(0));
    };
    return _;
};
auto iterate() -> const boxed& {
    static const boxed _ = [](const boxed& iter) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Control_Monad_ST_Internal::_new_()(false))([=](const boxed& v) -> boxed {
                return Control_Monad_ST_Internal::_while_()(Data_Functor::map()(Control_Monad_ST_Internal::functorST())(Data_HeytingAlgebra::_not_()(Data_HeytingAlgebra::heytingAlgebraBoolean()))(Control_Monad_ST_Internal::read()(v)))(Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST_Iterator::next()(iter))([=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1).contains("Just")) {
                        return f(v1["value0"]);
                    };
                    if (unbox<dict_t>(v1).contains("Nothing")) {
                        return Data_Functor::_void_()(Control_Monad_ST_Internal::functorST())(Control_Monad_ST_Internal::write()(true)(v));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Array.ST.Iterator (line 42, column 5 - line 44, column 47): ");
                }));
            });
        };
    };
    return _;
};
auto exhausted() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Functor::map()(Control_Monad_ST_Internal::functorST())(Data_Maybe::isNothing()))(Data_Array_ST_Iterator::_peek_());
};


} // end namespace Data_Array_ST_Iterator


