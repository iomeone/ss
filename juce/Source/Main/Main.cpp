#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Data_Array/Data_Array.h"
#include "Data_Char_Unicode/Data_Char_Unicode.h"
#include "Data_Either/Data_Either.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_List/Data_List.h"
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
auto s1() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Text_Parsing_Parser_String::_string_()(dictStringLike)(dictMonad)("1");
        };
    };
    return _;
};
auto parseTest() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return [=](const boxed& dictEq) -> boxed {
            return [=](const boxed& input) -> boxed {
                return [=](const boxed& p) -> boxed {
                    boxed v = Text_Parsing_Parser::runParser()(input)(p);
                    if (unbox<dict_t>(v).contains("Right")) {
                        return Effect_Console::logShow()(Data_Show::showString())(Data_Semigroup::append()(Data_Semigroup::semigroupString())("parser result is")(Data_Show::show()(dictShow)(v["value0"])));
                    };
                    if (unbox<dict_t>(v).contains("Left")) {
                        return Effect_Console::logShow()(Data_Show::showString())(Data_Semigroup::append()(Data_Semigroup::semigroupString())("error: ")(Data_Show::show()(Text_Parsing_Parser::showParseError())(v["value0"])));
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Main (line 50, column 21 - line 53, column 46): ");
                };
            };
        };
    };
    return _;
};
auto parseSingleDigitInt() -> boxed {
    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(Data_Identity::monadIdentity()))(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_Token::digit()(Data_Identity::monadIdentity())))([=](const boxed& v) -> boxed {
        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(Data_Identity::monadIdentity()))(v);
    });
};
auto parens() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_Combinators::between()(dictMonad)(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("("))(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(")"));
    };
    return _;
};
auto opTest() -> boxed {
    return Text_Parsing_Parser_Combinators::chainl()(Data_Identity::monadIdentity())(Data_Functor::map()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Data_String_CodeUnits::singleton())(Text_Parsing_Parser_String::anyChar()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())))(Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(Data_Identity::functorIdentity()))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("+"))(Data_Semigroup::append()(Data_Semigroup::semigroupString())))("");
};
auto main() -> const boxed& {
    static const boxed _ = []() -> boxed {
        Effect_Console::log()("parser test:")();
        return Main::parseTest()(Data_Show::showArray()(Data_Show::showChar()))(Data_Eq::eqArray()(Data_Eq::eqChar()))("12ab")(Main::parseSingleDigitInt())();
    };
    return _;
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


} // end namespace Main

int main(int argc, const char * argv[]) {
    Main::main()();
    return 0;
}

