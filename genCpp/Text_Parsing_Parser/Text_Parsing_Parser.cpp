#include "Control_Alt/Control_Alt.h"
#include "Control_Alternative/Control_Alternative.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Monad_Error_Class/Control_Monad_Error_Class.h"
#include "Control_Monad_Except/Control_Monad_Except.h"
#include "Control_Monad_Except_Trans/Control_Monad_Except_Trans.h"
#include "Control_Monad_Rec_Class/Control_Monad_Rec_Class.h"
#include "Control_Monad_State/Control_Monad_State.h"
#include "Control_Monad_State_Class/Control_Monad_State_Class.h"
#include "Control_Monad_State_Trans/Control_Monad_State_Trans.h"
#include "Control_Monad_Trans_Class/Control_Monad_Trans_Class.h"
#include "Control_MonadPlus/Control_MonadPlus.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Control_Plus/Control_Plus.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Either/Data_Either.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Monoid/Data_Monoid.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Prelude/Prelude.h"
#include "Text_Parsing_Parser_Pos/Text_Parsing_Parser_Pos.h"

#include "Text_Parsing_Parser/Text_Parsing_Parser.h"


namespace Text_Parsing_Parser {

auto ParseState() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return [=](const boxed& value2) -> boxed {
                return dict_t{
                    { "ParseState", true },
                    { "value0", value0 },
                    { "value1", value1 },
                    { "value2", value2 }
                };
            };
        };
    };
    return _;
};
auto ParseError() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "ParseError", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto ParserT() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto showParseError() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(ParseError ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showString())(v["value0"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Text_Parsing_Parser_Pos::showPosition())(v["value1"]))(")"))));
    });
};
auto parseErrorPosition() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value1"];
    };
    return _;
};
auto parseErrorMessage() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["value0"];
    };
    return _;
};
auto newtypeParserT() -> boxed {
    return Data_Newtype::Newtype()([=](const boxed& n) -> boxed {
        return n;
    })(Text_Parsing_Parser::ParserT());
};
auto runParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& s) -> boxed {
            return [=](const boxed& p) -> boxed {
                boxed initialState = Text_Parsing_Parser::ParseState()(s)(Text_Parsing_Parser_Pos::initialPos())(false);
                return Control_Monad_State_Trans::evalStateT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined))(Control_Monad_Except_Trans::runExceptT()(Data_Newtype::unwrap()(Text_Parsing_Parser::newtypeParserT())(p)))(initialState);
            };
        };
    };
    return _;
};
auto runParser() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Data_Identity::newtypeIdentity()))(Text_Parsing_Parser::runParserT()(Data_Identity::monadIdentity())(s));
    };
    return _;
};
auto monadTransParserT() -> boxed {
    return Control_Monad_Trans_Class::MonadTrans()([=](const boxed& dictMonad) -> boxed {
        return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Text_Parsing_Parser::ParserT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Trans_Class::lift()(Control_Monad_Except_Trans::monadTransExceptT())(Control_Monad_State_Trans::monadStateT()(dictMonad)))(Control_Monad_Trans_Class::lift()(Control_Monad_State_Trans::monadTransStateT())(dictMonad)));
    });
};
auto monadThrowParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Except_Trans::monadThrowExceptT()(Control_Monad_State_Trans::monadStateT()(dictMonad));
    };
    return _;
};
auto monadStateParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Except_Trans::monadStateExceptT()(Control_Monad_State_Trans::monadStateStateT()(dictMonad));
    };
    return _;
};
auto position() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_State_Class::gets()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v) -> boxed {
            return v["value1"];
        });
    };
    return _;
};
auto monadRecParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonadRec) -> boxed {
        return Control_Monad_Except_Trans::monadRecExceptT()(Control_Monad_State_Trans::monadRecStateT()(dictMonadRec));
    };
    return _;
};
auto monadParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Except_Trans::monadExceptT()(Control_Monad_State_Trans::monadStateT()(dictMonad));
    };
    return _;
};
auto monadErrorParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Except_Trans::monadErrorExceptT()(Control_Monad_State_Trans::monadStateT()(dictMonad));
    };
    return _;
};
auto mapParserT() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::over()(Text_Parsing_Parser::newtypeParserT())(Text_Parsing_Parser::newtypeParserT())(Text_Parsing_Parser::ParserT()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::mapExceptT())(Control_Monad_State_Trans::mapStateT()));
};
auto lazyParserT() -> boxed {
    return Control_Lazy::Lazy()([=](const boxed& f) -> boxed {
        return Control_Lazy::defer()(Control_Monad_State_Trans::lazyStateT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::runExceptT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Data_Newtype::unwrap()(Text_Parsing_Parser::newtypeParserT()))(f)));
    });
};
auto hoistParserT() -> boxed {
    return Text_Parsing_Parser::mapParserT();
};
auto functorParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictFunctor) -> boxed {
        return Control_Monad_Except_Trans::functorExceptT()(Control_Monad_State_Trans::functorStateT()(dictFunctor));
    };
    return _;
};
auto failWithPosition() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& message) -> boxed {
            return [=](const boxed& pos) -> boxed {
                return Control_Monad_Error_Class::throwError()(Text_Parsing_Parser::monadThrowParserT()(dictMonad))(Text_Parsing_Parser::ParseError()(message)(pos));
            };
        };
    };
    return _;
};
auto eqParseError() -> boxed {
    return Data_Eq::Eq()([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            return unbox<bool>(Data_Eq::eq()(Data_Eq::eqString())(x["value0"])(y["value0"])) && unbox<bool>(Data_Eq::eq()(Text_Parsing_Parser_Pos::eqPosition())(x["value1"])(y["value1"]));
        };
    });
};
auto ordParseError() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Text_Parsing_Parser::eqParseError();
    })([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            boxed v = Data_Ord::compare()(Data_Ord::ordString())(x["value0"])(y["value0"]);
            if (unbox<dict_t>(v).contains("LT")) {
                return Data_Ordering::LT();
            };
            if (unbox<dict_t>(v).contains("GT")) {
                return Data_Ordering::GT();
            };
            return Data_Ord::compare()(Text_Parsing_Parser_Pos::ordPosition())(x["value1"])(y["value1"]);
        };
    });
};
auto consume() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_State_Class::modify_()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v) -> boxed {
            return Text_Parsing_Parser::ParseState()(v["value0"])(v["value1"])(true);
        });
    };
    return _;
};
auto bindParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Except_Trans::bindExceptT()(Control_Monad_State_Trans::monadStateT()(dictMonad));
    };
    return _;
};
auto fail() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& message) -> boxed {
            return Control_Bind::bindFlipped()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser::failWithPosition()(dictMonad)(message))(Text_Parsing_Parser::position()(dictMonad));
        };
    };
    return _;
};
auto applyParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Except_Trans::applyExceptT()(Control_Monad_State_Trans::monadStateT()(dictMonad));
    };
    return _;
};
auto semigroupParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictSemigroup) -> boxed {
            return Data_Semigroup::Semigroup()(Control_Apply::lift2()(Text_Parsing_Parser::applyParserT()(dictMonad))(Data_Semigroup::append()(dictSemigroup)));
        };
    };
    return _;
};
auto applicativeParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_Except_Trans::applicativeExceptT()(Control_Monad_State_Trans::monadStateT()(dictMonad));
    };
    return _;
};
auto monoidParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictMonoid) -> boxed {
            return Data_Monoid::Monoid()([=](const boxed&) -> boxed {
                return Text_Parsing_Parser::semigroupParserT()(dictMonad)(dictMonoid["Semigroup0"](undefined));
            })(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_Monoid::mempty()(dictMonoid)));
        };
    };
    return _;
};
auto altParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Alt::Alt()([=](const boxed&) -> boxed {
            return Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined));
        })([=](const boxed& p1) -> boxed {
            return [=](const boxed& p2) -> boxed {
                return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Text_Parsing_Parser::ParserT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::ExceptT())(Control_Monad_State_Trans::StateT()))([=](const boxed& v) -> boxed {
                    return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Control_Monad_State_Trans::runStateT()(Control_Monad_Except_Trans::runExceptT()(Data_Newtype::unwrap()(Text_Parsing_Parser::newtypeParserT())(p1)))(Text_Parsing_Parser::ParseState()(v["value0"])(v["value1"])(false)))([=](const boxed& v1) -> boxed {
                        if (unbox<dict_t>(v1["value0"]).contains("Left")) {
                            if (unbox<bool>(!unbox<bool>(v1["value1"]["value2"]))) {
                                return Control_Monad_State_Trans::runStateT()(Control_Monad_Except_Trans::runExceptT()(Data_Newtype::unwrap()(Text_Parsing_Parser::newtypeParserT())(p2)))(v);
                            };
                        };
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v1["value0"])(v1["value1"]));
                    });
                });
            };
        });
    };
    return _;
};
auto plusParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Plus::Plus()([=](const boxed&) -> boxed {
            return Text_Parsing_Parser::altParserT()(dictMonad);
        })(Text_Parsing_Parser::fail()(dictMonad)("No alternative"));
    };
    return _;
};
auto alternativeParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Alternative::Alternative()([=](const boxed&) -> boxed {
            return Text_Parsing_Parser::applicativeParserT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Text_Parsing_Parser::plusParserT()(dictMonad);
        });
    };
    return _;
};
auto monadZeroParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_MonadZero::MonadZero()([=](const boxed&) -> boxed {
            return Text_Parsing_Parser::alternativeParserT()(dictMonad);
        })([=](const boxed&) -> boxed {
            return Text_Parsing_Parser::monadParserT()(dictMonad);
        });
    };
    return _;
};
auto monadPlusParserT() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_MonadPlus::MonadPlus()([=](const boxed&) -> boxed {
            return Text_Parsing_Parser::monadZeroParserT()(dictMonad);
        });
    };
    return _;
};


} // end namespace Text_Parsing_Parser


