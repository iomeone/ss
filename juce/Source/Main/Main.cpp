#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Array/Data_Array.h"
#include "Data_Char_Unicode/Data_Char_Unicode.h"
#include "Data_Either/Data_Either.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_List/Data_List.h"
#include "Data_List_Types/Data_List_Types.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Data_String_CodeUnits/Data_String_CodeUnits.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Effect/Effect.h"
#include "Effect_Console/Effect_Console.h"
#include "Prelude/Prelude.h"
#include "Text_Parsing_Parser/Text_Parsing_Parser.h"
#include "Text_Parsing_Parser_Combinators/Text_Parsing_Parser_Combinators.h"
#include "Text_Parsing_Parser_Expr/Text_Parsing_Parser_Expr.h"
#include "Text_Parsing_Parser_Language/Text_Parsing_Parser_Language.h"
#include "Text_Parsing_Parser_Pos/Text_Parsing_Parser_Pos.h"
#include "Text_Parsing_Parser_String/Text_Parsing_Parser_String.h"
#include "Text_Parsing_Parser_Token/Text_Parsing_Parser_Token.h"

#include "Main/Main.h"


namespace Main {

auto Kill() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "Kill", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto Attribute() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "Attribute", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto Element() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return [=](const boxed& value2) -> boxed {
                return dict_t{
                    { "Element", true },
                    { "value0", value0 },
                    { "value1", value1 },
                    { "value2", value2 }
                };
            };
        };
    };
    return _;
};
auto VoidElement() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "VoidElement", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto TextNode() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "TextNode", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto CommentNode() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "CommentNode", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto showKill() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("name : ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(v["value0"])(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" uid : ")(v["value1"])));
    });
};
auto showAttribute() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("Attribute ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showString())(v["value0"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" ")(Data_Show::show()(Data_Show::showString())(v["value1"]))));
    });
};
auto showHTML() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Element")) {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("Element ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showString())(v["value0"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" (")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_List_Types::showList()(Main::showAttribute()))(v["value1"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(") (")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_List_Types::showList()(Main::showHTML()))(v["value2"]))(")"))))));
        };
        if (unbox<dict_t>(v).contains("VoidElement")) {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("VoidElement ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showString())(v["value0"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(" (")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_List_Types::showList()(Main::showAttribute()))(v["value1"]))(")"))));
        };
        if (unbox<dict_t>(v).contains("TextNode")) {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("TextNode ")(Data_Show::show()(Data_Show::showString())(v["value0"]));
        };
        if (unbox<dict_t>(v).contains("CommentNode")) {
            return Data_Semigroup::append()(Data_Semigroup::semigroupString())("CommentNode ")(Data_Show::show()(Data_Show::showString())(v["value0"]));
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Main (line 45, column 1 - line 45, column 31): ");
    });
};
auto s1() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Text_Parsing_Parser_String::_string_()(dictStringLike)(dictMonad)("1");
        };
    };
    return _;
};
auto parseTextNode() -> boxed {
    return Data_Functor::map()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Main::TextNode())(Data_String_CodeUnits::fromCharArray()))(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_String::noneOf()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(array_t{ "<", ">" })));
};
auto parseTest() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& input) -> boxed {
            return [=](const boxed& p) -> boxed {
                boxed v = Text_Parsing_Parser::runParser()(input)(p);
                if (unbox<dict_t>(v).contains("Right")) {
                    return Effect_Console::log()(Data_Semigroup::append()(Data_Semigroup::semigroupString())("Parser result is: ")(Data_Show::show()(dictShow)(v["value0"])));
                };
                if (unbox<dict_t>(v).contains("Left")) {
                    return Effect_Console::logShow()(Data_Show::showString())(Data_Semigroup::append()(Data_Semigroup::semigroupString())("error: ")(Data_Show::show()(Text_Parsing_Parser::showParseError())(v["value0"])));
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Main (line 177, column 21 - line 180, column 46): ");
            };
        };
    };
    return _;
};
auto parseTagName() -> boxed {
    return Data_Functor::map()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Data_String_CodeUnits::fromCharArray())(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_Token::alphaNum()(Data_Identity::monadIdentity())));
};
auto parseCloseTag() -> const boxed& {
    static const boxed _ = [](const boxed& name) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("</"))([=](const boxed& v) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(name))([=](const boxed& v1) -> boxed {
                return Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(">");
            });
        });
    };
    return _;
};
auto parseAttributeValue() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_Combinators::optionMaybe()(Data_Identity::monadIdentity())(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("\""))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("'"))))([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("Nothing")) {
            return Data_Functor::map()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Data_String_CodeUnits::fromCharArray())(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_String::noneOf()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(array_t{ " ", "\t", "\n", "\r", "\"", "'", "=", "<", ">", "`", "/" })));
        };
        if (unbox<dict_t>(v).contains("Just")) {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Data_Functor::map()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Data_String_CodeUnits::fromCharArray())(Data_Array::many()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_String::noneOf()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(array_t{ v["value0"] }))))([=](const boxed& v1) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(v["value0"]))([=](const boxed& v2) -> boxed {
                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Data_Identity::monadIdentity()))(v1);
                });
            });
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Main (line 68, column 3 - line 73, column 17): ");
    });
};
auto parseAttributeName() -> boxed {
    return Data_Functor::map()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Data_String_CodeUnits::fromCharArray())(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_String::noneOf()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(array_t{ " ", "\"", "'", ">", "/", "=" })));
};
auto parseAttribute() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::parseAttributeName())([=](const boxed& v) -> boxed {
        return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::skipSpaces()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity()))([=](const boxed&) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_Combinators::optionMaybe()(Data_Identity::monadIdentity())(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("=")))([=](const boxed& v1) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))([=]() -> boxed {
                    if (unbox<dict_t>(v1).contains("Nothing")) {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Data_Identity::monadIdentity()))("");
                    };
                    if (unbox<dict_t>(v1).contains("Just")) {
                        return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::skipSpaces()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity()))([=](const boxed&) -> boxed {
                            return Main::parseAttributeValue();
                        });
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Main (line 82, column 12 - line 86, column 28): ");
                }())([=](const boxed& v2) -> boxed {
                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Data_Identity::monadIdentity()))(Main::Attribute()(v)(v2));
                });
            });
        });
    });
};
auto parseAttributes() -> boxed {
    return Text_Parsing_Parser_Combinators::sepEndBy()(Data_Identity::monadIdentity())(Main::parseAttribute())(Text_Parsing_Parser_String::skipSpaces()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity()));
};
auto parens() -> boxed {
    return Text_Parsing_Parser_Combinators::between()(Data_Identity::monadIdentity())(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("("))(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(")"));
};
auto parseNameNum() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::parens()(Data_Functor::map()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Data_String_CodeUnits::fromCharArray())(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(Data_Char_Unicode::isLetter())))))([=](const boxed& v) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Data_Functor::map()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Data_String_CodeUnits::fromCharArray())(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_Token::digit()(Data_Identity::monadIdentity()))))([=](const boxed& v1) -> boxed {
            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Data_Identity::monadIdentity()))(Main::Kill()(v)(v1));
        });
    });
};
auto opTest() -> boxed {
    return Text_Parsing_Parser_Combinators::chainl()(Data_Identity::monadIdentity())(Data_Functor::map()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Data_String_CodeUnits::singleton())(Text_Parsing_Parser_String::anyChar()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())))(Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("+"))(Data_Semigroup::append()(Data_Semigroup::semigroupString())))("");
};
auto notClosedTag() -> boxed {
    return Text_Parsing_Parser_Combinators::notFollowedBy()(Data_Identity::monadIdentity())(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("</"));
};
auto parseOpenTag() -> boxed {
    return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::notClosedTag())([=](const boxed&) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("<"))([=](const boxed& v) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::parseTagName())([=](const boxed& v1) -> boxed {
                return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::skipSpaces()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity()))([=](const boxed&) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::parseAttributes())([=](const boxed& v2) -> boxed {
                        return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::skipSpaces()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity()))([=](const boxed&) -> boxed {
                            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(">"))([=](const boxed& v3) -> boxed {
                                return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Data_Identity::monadIdentity()))(Data_Tuple::Tuple()(v1)(v2));
                            });
                        });
                    });
                });
            });
        });
    });
};
auto parseVoidElement() -> boxed {
    return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::notClosedTag())([=](const boxed&) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("<"))([=](const boxed& v) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::parseTagName())([=](const boxed& v1) -> boxed {
                return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::skipSpaces()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity()))([=](const boxed&) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::parseAttributes())([=](const boxed& v2) -> boxed {
                        return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::skipSpaces()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity()))([=](const boxed&) -> boxed {
                            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("/>"))([=](const boxed& v3) -> boxed {
                                return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Data_Identity::monadIdentity()))(Main::VoidElement()(v1)(v2));
                            });
                        });
                    });
                });
            });
        });
    });
};
auto parseNode() -> boxed {
    return Control_Lazy::fix()(Text_Parsing_Parser::lazyParserT())([=](const boxed& v) -> boxed {
        return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(Data_Identity::monadIdentity()))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_Combinators::_try_()(Data_Identity::monadIdentity())(Main::parseElement()))(Text_Parsing_Parser_Combinators::_try_()(Data_Identity::monadIdentity())(Main::parseVoidElement())))(Main::parseTextNode());
    });
};
auto parseElement() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::parseOpenTag())([=](const boxed& v) -> boxed {
        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Data_List::many()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Main::parseNode()))([=](const boxed& v1) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Main::parseCloseTag()(v["value0"]))([=](const boxed& v2) -> boxed {
                return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Data_Identity::monadIdentity()))(Main::Element()(v["value0"])(v["value1"])(v1));
            });
        });
    });
};
auto parseHTML() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        return Text_Parsing_Parser::runParser()(s)(Control_Apply::applyFirst()(Text_Parsing_Parser::applyParserT()(Data_Identity::monadIdentity()))(Data_List::many()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Main::parseNode()))(Text_Parsing_Parser_String::eof()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())));
    };
    return _;
};
auto main() -> boxed {
    return Effect_Console::log()(Data_Show::show()(Data_Either::showEither()(Text_Parsing_Parser::showParseError())(Data_List_Types::showList()(Main::showHTML())))(Main::parseHTML()("<html></html>")));
};
auto factorial() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<int>(v) == 0) {
            return 1;
        };
        return unbox<int>(v) * unbox<int>(Main::factorial()(unbox<int>(v) - 1));
    };
    return _;
};
auto eqAttribute() -> boxed {
    return Data_Eq::Eq()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return unbox<bool>(Data_Eq::eq()(Data_Eq::eqString())(v["value0"])(v1["value0"])) && unbox<bool>(Data_Eq::eq()(Data_Eq::eqString())(v["value1"])(v1["value1"]));
        };
    });
};


} // end namespace Main

int main(int argc, const char * argv[]) {
    Main::main()();
    return 0;
}

