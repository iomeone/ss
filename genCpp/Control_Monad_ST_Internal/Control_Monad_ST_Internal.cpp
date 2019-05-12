#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Unit/Data_Unit.h"
#include "Partial_Unsafe/Partial_Unsafe.h"
#include "Prelude/Prelude.h"

#include "Control_Monad_ST_Internal/Control_Monad_ST_Internal.h"


namespace Control_Monad_ST_Internal {

auto modify() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return Control_Monad_ST_Internal::modify_Prime_()([=](const boxed& s) -> boxed {
            boxed s_Prime_ = f(s);
            return dict_t{
                { "state", s_Prime_ },
                { "value", s_Prime_ }
            };
        });
    };
    return _;
};
auto functorST() -> boxed {
    return Data_Functor::Functor()(Control_Monad_ST_Internal::map_());
};
auto monadST() -> boxed {
    return Control_Monad::Monad()([=](const boxed&) -> boxed {
        return Control_Monad_ST_Internal::applicativeST();
    })([=](const boxed&) -> boxed {
        return Control_Monad_ST_Internal::bindST();
    });
};
auto bindST() -> boxed {
    return Control_Bind::Bind()([=](const boxed&) -> boxed {
        return Control_Monad_ST_Internal::applyST();
    })(Control_Monad_ST_Internal::bind_());
};
auto applyST() -> boxed {
    return Control_Apply::Apply()([=](const boxed&) -> boxed {
        return Control_Monad_ST_Internal::functorST();
    })(Control_Monad::ap()(Control_Monad_ST_Internal::monadST()));
};
auto applicativeST() -> boxed {
    return Control_Applicative::Applicative()([=](const boxed&) -> boxed {
        return Control_Monad_ST_Internal::applyST();
    })(Control_Monad_ST_Internal::pure_());
};
auto monadRecST() -> boxed {
    return Control_Monad_Rec_Class::MonadRec()([=](const boxed&) -> boxed {
        return Control_Monad_ST_Internal::monadST();
    })([=](const boxed& f) -> boxed {
        return [=](const boxed& a) -> boxed {
            boxed isLooping = [=](const boxed& v) -> boxed {
                if (unbox<dict_t>(v).contains("Loop")) {
                    return true;
                };
                return false;
            };
            boxed fromDone = [=](const boxed& dictPartial) -> boxed {
                return [=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Done")) {
                        return v["value0"];
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.ST.Internal (line 54, column 32 - line 54, column 46): ");
                };
            }(undefined);
            return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Control_Bind::bindFlipped()(Control_Monad_ST_Internal::bindST())(Control_Monad_ST_Internal::_new_())(f(a)))([=](const boxed& v) -> boxed {
                return Control_Bind::discard()(Control_Bind::discardUnit())(Control_Monad_ST_Internal::bindST())(Control_Monad_ST_Internal::_while_()(Data_Functor::map()(Control_Monad_ST_Internal::functorST())(isLooping)(Control_Monad_ST_Internal::read()(v)))(Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Control_Monad_ST_Internal::read()(v))([=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1).contains("Loop")) {
                        return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(f(v1["value0"]))([=](const boxed& v2) -> boxed {
                            return Data_Functor::_void_()(Control_Monad_ST_Internal::functorST())(Control_Monad_ST_Internal::write()(v2)(v));
                        });
                    };
                    if (unbox<dict_t>(v1).contains("Done")) {
                        return Control_Applicative::pure()(Control_Monad_ST_Internal::applicativeST())(Data_Unit::unit());
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Control.Monad.ST.Internal (line 46, column 18 - line 50, column 28): ");
                })))([=](const boxed&) -> boxed {
                    return Data_Functor::map()(Control_Monad_ST_Internal::functorST())(fromDone)(Control_Monad_ST_Internal::read()(v));
                });
            });
        };
    });
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto map_() -> const boxed& { static const boxed _ = foreign().at("map_"); return _; };
auto pure_() -> const boxed& { static const boxed _ = foreign().at("pure_"); return _; };
auto bind_() -> const boxed& { static const boxed _ = foreign().at("bind_"); return _; };
auto run() -> const boxed& { static const boxed _ = foreign().at("run"); return _; };
auto _while_() -> const boxed& { static const boxed _ = foreign().at("while"); return _; };
auto _for_() -> const boxed& { static const boxed _ = foreign().at("for"); return _; };
auto foreach() -> const boxed& { static const boxed _ = foreign().at("foreach"); return _; };
auto _new_() -> const boxed& { static const boxed _ = foreign().at("new"); return _; };
auto read() -> const boxed& { static const boxed _ = foreign().at("read"); return _; };
auto modify_Prime_() -> const boxed& { static const boxed _ = foreign().at("modify'"); return _; };
auto write() -> const boxed& { static const boxed _ = foreign().at("write"); return _; };

} // end namespace Control_Monad_ST_Internal


