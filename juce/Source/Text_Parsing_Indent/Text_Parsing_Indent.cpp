#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Monad/Control_Monad.h"
#include "Control_Monad_State/Control_Monad_State.h"
#include "Control_Monad_State_Class/Control_Monad_State_Class.h"
#include "Control_Monad_State_Trans/Control_Monad_State_Trans.h"
#include "Control_Monad_Trans_Class/Control_Monad_Trans_Class.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Function/Data_Function.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_List/Data_List.h"
#include "Data_List_Types/Data_List_Types.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"
#include "Text_Parsing_Parser/Text_Parsing_Parser.h"
#include "Text_Parsing_Parser_Combinators/Text_Parsing_Parser_Combinators.h"
#include "Text_Parsing_Parser_Pos/Text_Parsing_Parser_Pos.h"
#include "Text_Parsing_Parser_String/Text_Parsing_Parser_String.h"

#include "Text_Parsing_Indent/Text_Parsing_Indent.h"


namespace Text_Parsing_Indent {

auto Opt() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "Opt", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto symbol() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& name) -> boxed {
            return Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Data_List::many()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(array_t{ " ", "\t" })))(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(name));
        };
    };
    return _;
};
auto sourceLine() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["line"];
    };
    return _;
};
auto sourceColumn() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v["column"];
    };
    return _;
};
auto setSourceLine() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& l) -> boxed {
            return dict_t{
                { "line", l },
                { "column", v["column"] }
            };
        };
    };
    return _;
};
auto runIndent() -> boxed {
    return Data_Function::flip()(Control_Monad_State::evalState())(Text_Parsing_Parser_Pos::initialPos());
};
auto put_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return Control_Monad_Trans_Class::lift()(Text_Parsing_Parser::monadTransParserT())(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))(Control_Monad_State_Class::put()(Control_Monad_State_Trans::monadStateStateT()(Data_Identity::monadIdentity()))(p));
    };
    return _;
};
auto many1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Control_Apply::lift2()(Text_Parsing_Parser::applyParserT()(dictMonad))(Data_List_Types::Cons())(p)(Data_List::many()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(p));
        };
    };
    return _;
};
auto getPosition() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Control_Monad_State_Class::gets()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v) -> boxed {
            return v["value1"];
        });
    };
    return _;
};
auto get_Prime_() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Control_Monad_Trans_Class::lift()(Text_Parsing_Parser::monadTransParserT())(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))(Control_Monad_State_Class::get()(Control_Monad_State_Trans::monadStateStateT()(Data_Identity::monadIdentity()))))([=](const boxed& v) -> boxed {
        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(v);
    });
};
auto withPos() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::get_Prime_())([=](const boxed& v) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::getPosition()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))([=](const boxed& v1) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::put_Prime_()(v1))(x))([=](const boxed& v2) -> boxed {
                    return Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::put_Prime_()(v))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(v2));
                });
            });
        });
    };
    return _;
};
auto biAp() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& c) -> boxed {
            return [=](const boxed& v1) -> boxed {
                return [=](const boxed& v2) -> boxed {
                    return c(f(v1))(f(v2));
                };
            };
        };
    };
    return _;
};
auto checkIndent() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::get_Prime_())([=](const boxed& v) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::getPosition()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))([=](const boxed& v1) -> boxed {
            boxed _Local_25 = Text_Parsing_Indent::biAp()(Text_Parsing_Indent::sourceColumn())(Data_Eq::eq()(Data_Eq::eqInt()))(v1)(v);
            if (unbox<bool>(_Local_25)) {
                return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Data_Unit::unit());
            };
            return Text_Parsing_Parser::fail()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("indentation doesn't match");
        });
    });
};
auto block() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return Text_Parsing_Indent::withPos()(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Data_List::many()(Text_Parsing_Parser::alternativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Parser::lazyParserT())(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::checkIndent())(p)))([=](const boxed& v) -> boxed {
            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(v);
        }));
    };
    return _;
};
auto block1() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return Text_Parsing_Indent::withPos()(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::many1()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::checkIndent())(p)))([=](const boxed& v) -> boxed {
            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(v);
        }));
    };
    return _;
};
auto indented() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::getPosition()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))([=](const boxed& v) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::get_Prime_())([=](const boxed& v1) -> boxed {
            boxed _Local_30 = Text_Parsing_Indent::biAp()(Text_Parsing_Indent::sourceColumn())(Data_Ord::lessThanOrEq()(Data_Ord::ordInt()))(v)(v1);
            if (unbox<bool>(_Local_30)) {
                return Text_Parsing_Parser::fail()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("not indented");
            };
            return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::put_Prime_()(Text_Parsing_Indent::setSourceLine()(v1)(Text_Parsing_Indent::sourceLine()(v))))([=](const boxed&) -> boxed {
                return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Data_Unit::unit());
            });
        });
    });
};
auto withBlock() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& p) -> boxed {
                return Text_Parsing_Indent::withPos()(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(a)([=](const boxed& v) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Parser_Combinators::optionMaybe()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::indented())(Text_Parsing_Indent::block()(p))))([=](const boxed& v1) -> boxed {
                        if (unbox<dict_t>(v1).contains("Nothing")) {
                            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(f(v)(Data_List_Types::Nil()));
                        };
                        if (unbox<dict_t>(v1).contains("Just")) {
                            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(f(v)(v1["value0"]));
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Indent (line 112, column 5 - line 114, column 32): ");
                    });
                }));
            };
        };
    };
    return _;
};
auto withBlock_Prime_() -> boxed {
    return Text_Parsing_Indent::withBlock()(Data_Function::flip()(Data_Function::_const_()));
};
auto indented_Prime_() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::getPosition()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))([=](const boxed& v) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::get_Prime_())([=](const boxed& v1) -> boxed {
            boxed _Local_37 = Text_Parsing_Indent::biAp()(Text_Parsing_Indent::sourceColumn())(Data_Ord::lessThanOrEq()(Data_Ord::ordInt()))(v)(v1);
            if (unbox<bool>(_Local_37)) {
                return Text_Parsing_Parser::fail()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("not indented");
            };
            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Data_Unit::unit());
        });
    });
};
auto sameLine() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::getPosition()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))([=](const boxed& v) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::get_Prime_())([=](const boxed& v1) -> boxed {
            boxed _Local_40 = Text_Parsing_Indent::biAp()(Text_Parsing_Indent::sourceLine())(Data_Eq::eq()(Data_Eq::eqInt()))(v)(v1);
            if (unbox<bool>(_Local_40)) {
                return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Data_Unit::unit());
            };
            return Text_Parsing_Parser::fail()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("over one line");
        });
    });
};
auto sameOrIndented() -> boxed {
    return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::sameLine())(Text_Parsing_Indent::indented());
};
auto indentAp() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return Control_Monad::ap()(Text_Parsing_Parser::monadParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(a)(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::sameOrIndented())(b));
        };
    };
    return _;
};
auto indentMany() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return Control_Monad::ap()(Text_Parsing_Parser::monadParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(a)(Data_List::many()(Text_Parsing_Parser::alternativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Parser::lazyParserT())(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::sameOrIndented())(b)));
        };
    };
    return _;
};
auto indentNoAp() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return Control_Apply::lift2()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Data_Function::_const_())(a)(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::sameOrIndented())(b));
        };
    };
    return _;
};
auto indentAngles() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return Text_Parsing_Indent::withPos()(Text_Parsing_Indent::indentAp()(Text_Parsing_Indent::indentNoAp()(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Control_Category::identity()(Control_Category::categoryFn())))(Text_Parsing_Indent::symbol()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("<")))(Text_Parsing_Indent::indentNoAp()(p)(Text_Parsing_Indent::symbol()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))(">"))));
    };
    return _;
};
auto indentBraces() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return Text_Parsing_Indent::withPos()(Text_Parsing_Indent::indentAp()(Text_Parsing_Indent::indentNoAp()(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Control_Category::identity()(Control_Category::categoryFn())))(Text_Parsing_Indent::symbol()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("{")))(Text_Parsing_Indent::indentNoAp()(p)(Text_Parsing_Indent::symbol()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("}"))));
    };
    return _;
};
auto indentBrackets() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return Text_Parsing_Indent::withPos()(Text_Parsing_Indent::indentAp()(Text_Parsing_Indent::indentNoAp()(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Control_Category::identity()(Control_Category::categoryFn())))(Text_Parsing_Indent::symbol()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("[")))(Text_Parsing_Indent::indentNoAp()(p)(Text_Parsing_Indent::symbol()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("]"))));
    };
    return _;
};
auto indentParens() -> const boxed& {
    static const boxed _ = [](const boxed& p) -> boxed {
        return Text_Parsing_Indent::withPos()(Text_Parsing_Indent::indentAp()(Text_Parsing_Indent::indentNoAp()(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Control_Category::identity()(Control_Category::categoryFn())))(Text_Parsing_Indent::symbol()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))("(")))(Text_Parsing_Indent::indentNoAp()(p)(Text_Parsing_Indent::symbol()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))(")"))));
    };
    return _;
};
auto indentOp() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Monad::ap()(Text_Parsing_Parser::monadParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(a)(Text_Parsing_Parser_Combinators::option()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity()))(v["value0"])(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(Control_Monad_State_Trans::monadStateT()(Data_Identity::monadIdentity())))(Text_Parsing_Indent::sameOrIndented())(v["value1"])));
        };
    };
    return _;
};


} // end namespace Text_Parsing_Indent


