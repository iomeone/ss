#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Control_Lazy/Control_Lazy.h"
#include "Control_Monad_State/Control_Monad_State.h"
#include "Control_Monad_State_Class/Control_Monad_State_Class.h"
#include "Control_MonadPlus/Control_MonadPlus.h"
#include "Control_MonadZero/Control_MonadZero.h"
#include "Data_Array/Data_Array.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Char/Data_Char.h"
#include "Data_Char_Unicode/Data_Char_Unicode.h"
#include "Data_Either/Data_Either.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Int/Data_Int.h"
#include "Data_List/Data_List.h"
#include "Data_List_Types/Data_List_Types.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Data_String/Data_String.h"
#include "Data_String_CodeUnits/Data_String_CodeUnits.h"
#include "Data_String_Common/Data_String_Common.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unfoldable/Data_Unfoldable.h"
#include "Data_Unit/Data_Unit.h"
#include "Math/Math.h"
#include "Prelude/Prelude.h"
#include "Text_Parsing_Parser/Text_Parsing_Parser.h"
#include "Text_Parsing_Parser_Combinators/Text_Parsing_Parser_Combinators.h"
#include "Text_Parsing_Parser_Pos/Text_Parsing_Parser_Pos.h"
#include "Text_Parsing_Parser_String/Text_Parsing_Parser_String.h"

#include "Text_Parsing_Parser_Token/Text_Parsing_Parser_Token.h"


namespace Text_Parsing_Parser_Token {

auto LanguageDef() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto upper() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::isUpper()))("uppercase letter");
    };
    return _;
};
auto unGenLanguageDef() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return v;
    };
    return _;
};
auto token() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& tokpos) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_Monad_State_Class::gets()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v) -> boxed {
                return v["value0"];
            }))([=](const boxed& v) -> boxed {
                boxed v1 = Data_List::uncons()(v);
                if (unbox<dict_t>(v1).contains("Nothing")) {
                    return Text_Parsing_Parser::fail()(dictMonad)("Unexpected EOF");
                };
                if (unbox<dict_t>(v1).contains("Just")) {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_Monad_State_Class::modify_()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v2) -> boxed {
                        return Text_Parsing_Parser::ParseState()(v1["value0"]["tail"])(tokpos(v1["value0"]["head"]))(true);
                    }))([=](const boxed&) -> boxed {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v1["value0"]["head"]);
                    });
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 53, column 3 - line 58, column 16): ");
            });
        };
    };
    return _;
};
auto when() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& tokpos) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Text_Parsing_Parser_Combinators::tryRethrow()(dictMonad)(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Token::token()(dictMonad)(tokpos))([=](const boxed& v) -> boxed {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_MonadZero::guard()(Text_Parsing_Parser::monadZeroParserT()(dictMonad))(f(v)))([=](const boxed&) -> boxed {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v);
                    });
                }));
            };
        };
    };
    return _;
};
auto theReservedNames() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<bool>(v["caseSensitive"])) {
                return Data_Array::sort()(Data_Ord::ordString())(v["reservedNames"]);
            };
            return Data_Array::sort()(Data_Ord::ordString())(Data_Functor::map()(Data_Functor::functorArray())(Data_String_Common::toLower())(v["reservedNames"]));
        };
    };
    return _;
};
auto space() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::isSpace()))("space");
    };
    return _;
};
auto simpleSpace() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_Combinators::skipMany1()(dictMonad)(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::isSpace()));
    };
    return _;
};
auto oneLineComment() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_Combinators::_try_()(dictMonad)(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(v["commentLine"])))(Text_Parsing_Parser_Combinators::skipMany()(dictMonad)(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)([=](const boxed& v1) -> boxed {
                return Data_Eq::notEq()(Data_Eq::eqChar())(v1)("\n");
            })));
        };
    };
    return _;
};
auto octDigit() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::isOctDigit()))("oct digit");
    };
    return _;
};
auto match() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& dictEq) -> boxed {
            return [=](const boxed& tokpos) -> boxed {
                return [=](const boxed& tok) -> boxed {
                    return Text_Parsing_Parser_Token::when()(dictMonad)(tokpos)([=](const boxed& v) -> boxed {
                        return Data_Eq::eq()(dictEq)(v)(tok);
                    });
                };
            };
        };
    };
    return _;
};
auto letter() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::isAlpha()))("letter");
    };
    return _;
};
auto isReserved() -> const boxed& {
    static const boxed _ = [](const boxed& _TCO_Copy_names_) -> boxed {
        return [=](const boxed& _TCO_Copy_name_) -> boxed {
            boxed _TCO_names_;
            _TCO_names_ = _TCO_Copy_names_;
            boxed _TCO_name_;
            _TCO_name_ = _TCO_Copy_name_;
            bool _TCO_Done_ = false;
            boxed _TCO_Result_;
            const auto _TCO_Loop_ = [&](const boxed names, const boxed name) -> boxed {
                boxed v = Data_Array::uncons()(names);
                if (unbox<dict_t>(v).contains("Nothing")) {
                    _TCO_Done_ = true;
                    return false;
                };
                if (unbox<dict_t>(v).contains("Just")) {
                    boxed v1 = Data_Ord::compare()(Data_Ord::ordString())(v["value0"]["head"])(name);
                    if (unbox<dict_t>(v1).contains("LT")) {
                        _TCO_names_ = v["value0"]["tail"];
                        _TCO_name_ = name;
                        return undefined;
                    };
                    if (unbox<dict_t>(v1).contains("EQ")) {
                        _TCO_Done_ = true;
                        return true;
                    };
                    if (unbox<dict_t>(v1).contains("GT")) {
                        _TCO_Done_ = true;
                        return false;
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 717, column 39 - line 720, column 53): ");
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 715, column 5 - line 720, column 53): ");
            };
            while (!(_TCO_Done_)) {
                _TCO_Result_ = _TCO_Loop_(_TCO_names_, _TCO_name_);
            };
            return _TCO_Result_;
        };
    };
    return _;
};
auto isReservedName() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            return [=](const boxed& name) -> boxed {
                boxed caseName = [=]() -> boxed {
                    if (unbox<bool>(v["caseSensitive"])) {
                        return name;
                    };
                    return Data_String_Common::toLower()(name);
                }();
                return Text_Parsing_Parser_Token::isReserved()(Text_Parsing_Parser_Token::theReservedNames()(dictMonad)(v))(caseName);
            };
        };
    };
    return _;
};
auto inCommentSingle() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            boxed startEnd = Data_Semigroup::append()(Data_Semigroup::semigroupArray())(Data_String_CodeUnits::toCharArray()(v["commentEnd"]))(Data_String_CodeUnits::toCharArray()(v["commentStart"]));
            return Control_Lazy::fix()(Text_Parsing_Parser::lazyParserT())([=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Data_Functor::_void_()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Text_Parsing_Parser_Combinators::_try_()(dictMonad)(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(v["commentEnd"]))))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_Combinators::skipMany1()(dictMonad)(Text_Parsing_Parser_String::noneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(startEnd)))(p)))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(startEnd))(p)))("end of comment");
            });
        };
    };
    return _;
};
auto multiLineComment() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            return Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_Combinators::_try_()(dictMonad)(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(v["commentStart"])))(Text_Parsing_Parser_Token::inComment()(dictMonad)(v));
        };
    };
    return _;
};
auto inCommentMulti() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            boxed startEnd = Data_Semigroup::append()(Data_Semigroup::semigroupArray())(Data_String_CodeUnits::toCharArray()(v["commentEnd"]))(Data_String_CodeUnits::toCharArray()(v["commentStart"]));
            return Control_Lazy::fix()(Text_Parsing_Parser::lazyParserT())([=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Data_Functor::_void_()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Text_Parsing_Parser_Combinators::_try_()(dictMonad)(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(v["commentEnd"]))))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_Token::multiLineComment()(dictMonad)(v))(p)))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_Combinators::skipMany1()(dictMonad)(Text_Parsing_Parser_String::noneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(startEnd)))(p)))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(startEnd))(p)))("end of comment");
            });
        };
    };
    return _;
};
auto inComment() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<bool>(v["nestedComments"])) {
                return Text_Parsing_Parser_Token::inCommentMulti()(dictMonad)(v);
            };
            return Text_Parsing_Parser_Token::inCommentSingle()(dictMonad)(v);
        };
    };
    return _;
};
auto whiteSpace_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<bool>(unbox<bool>(Data_String_Common::null()(v["commentLine"])) && unbox<bool>(Data_String_Common::null()(v["commentStart"])))) {
                return Text_Parsing_Parser_Combinators::skipMany()(dictMonad)(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_Token::simpleSpace()(dictMonad))(""));
            };
            if (unbox<bool>(Data_String_Common::null()(v["commentLine"]))) {
                return Text_Parsing_Parser_Combinators::skipMany()(dictMonad)(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Token::simpleSpace()(dictMonad))(Text_Parsing_Parser_Token::multiLineComment()(dictMonad)(v)))(""));
            };
            if (unbox<bool>(Data_String_Common::null()(v["commentStart"]))) {
                return Text_Parsing_Parser_Combinators::skipMany()(dictMonad)(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Token::simpleSpace()(dictMonad))(Text_Parsing_Parser_Token::oneLineComment()(dictMonad)(v)))(""));
            };
            return Text_Parsing_Parser_Combinators::skipMany()(dictMonad)(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Token::simpleSpace()(dictMonad))(Text_Parsing_Parser_Token::oneLineComment()(dictMonad)(v)))(Text_Parsing_Parser_Token::multiLineComment()(dictMonad)(v)))(""));
        };
    };
    return _;
};
auto hexDigit() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::isHexDigit()))("hex digit");
    };
    return _;
};
auto digit() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::isDigit()))("digit");
    };
    return _;
};
auto makeTokenParser() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& v) -> boxed {
            boxed stringLetter = Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)([=](const boxed& c) -> boxed {
                return unbox<bool>(Data_Eq::notEq()(Data_Eq::eqChar())(c)("\"")) && unbox<bool>(unbox<bool>(Data_Eq::notEq()(Data_Eq::eqChar())(c)("\\")) && unbox<bool>(Data_Ord::greaterThan()(Data_Ord::ordChar())(c)("")));
            });
            boxed sign = [=](const boxed& dictRing) -> boxed {
                return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("-"))(Data_Ring::negate()(dictRing)))(Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("+"))(Control_Category::identity()(Control_Category::categoryFn()))))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Control_Category::identity()(Control_Category::categoryFn())));
            };
            boxed oper = [=]() -> boxed {
                boxed go = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(v["opStart"])([=](const boxed& v1) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Data_Array::many()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(v["opLetter"]))([=](const boxed& v2) -> boxed {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_String_CodeUnits::singleton()(v1))(Data_String_CodeUnits::fromCharArray()(v2)));
                    });
                });
                return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(go)("operator");
            }();
            boxed number = [=](const boxed& base) -> boxed {
                return [=](const boxed& baseDigit) -> boxed {
                    boxed folder = [=](const boxed& v1) -> boxed {
                        return [=](const boxed& v2) -> boxed {
                            if (unbox<dict_t>(v1).contains("Nothing")) {
                                return Data_Maybe::Nothing();
                            };
                            if (unbox<dict_t>(v1).contains("Just")) {
                                return Data_Functor::map()(Data_Maybe::functorMaybe())([=](const boxed& v3) -> boxed {
                                    return unbox<int>(unbox<int>(base) * unbox<int>(v1["value0"])) + unbox<int>(v3);
                                })(Data_Char_Unicode::digitToInt()(v2));
                            };
                            THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 600, column 9 - line 600, column 49): ");
                        };
                    };
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(baseDigit))([=](const boxed& v1) -> boxed {
                        return Data_Maybe::maybe()(Text_Parsing_Parser::fail()(dictMonad)("not digits"))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad)))(Data_Foldable::foldl()(Data_Foldable::foldableArray())(folder)(Data_Maybe::Just()(0))(v1));
                    });
                };
            };
            boxed octal = Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(array_t{ "o", "O" }))(number(8)(Text_Parsing_Parser_Token::octDigit()(dictMonad)));
            boxed lexeme = [=](const boxed& p) -> boxed {
                return Control_Apply::applyFirst()(Text_Parsing_Parser::applyParserT()(dictMonad))(p)(Text_Parsing_Parser_Token::whiteSpace_Prime_()(dictMonad)(v));
            };
            boxed reservedOp = [=](const boxed& name) -> boxed {
                boxed go = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(name))([=](const boxed& v1) -> boxed {
                    return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_Combinators::notFollowedBy()(dictMonad)(v["opLetter"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())("end of ")(name));
                });
                return lexeme(Text_Parsing_Parser_Combinators::_try_()(dictMonad)(go));
            };
            boxed symbol = [=](const boxed& name) -> boxed {
                return Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(lexeme(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(name)))(name);
            };
            boxed parens = [=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::between()(dictMonad)(symbol("("))(symbol(")"))(p);
            };
            boxed semi = symbol(";");
            boxed semiSep = [=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::sepBy()(dictMonad)(p)(semi);
            };
            boxed semiSep1 = [=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::sepBy1()(dictMonad)(p)(semi);
            };
            boxed isReservedOp = [=](const boxed& name) -> boxed {
                return Text_Parsing_Parser_Token::isReserved()(Data_Array::sort()(Data_Ord::ordString())(v["reservedOpNames"]))(name);
            };
            boxed _operator_ = [=]() -> boxed {
                boxed go = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(oper)([=](const boxed& v1) -> boxed {
                    boxed _Local_43 = isReservedOp(v1);
                    if (unbox<bool>(_Local_43)) {
                        return Text_Parsing_Parser::fail()(dictMonad)(Data_Semigroup::append()(Data_Semigroup::semigroupString())("reserved operator ")(v1));
                    };
                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v1);
                });
                return lexeme(Text_Parsing_Parser_Combinators::_try_()(dictMonad)(go));
            }();
            boxed ident = [=]() -> boxed {
                boxed go = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(v["identStart"])([=](const boxed& v1) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Data_Array::many()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(v["identLetter"]))([=](const boxed& v2) -> boxed {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_String_CodeUnits::singleton()(v1))(Data_String_CodeUnits::fromCharArray()(v2)));
                    });
                });
                return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(go)("identifier");
            }();
            boxed identifier = [=]() -> boxed {
                boxed go = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(ident)([=](const boxed& v1) -> boxed {
                    boxed _Local_47 = Text_Parsing_Parser_Token::isReservedName()(dictMonad)(v)(v1);
                    if (unbox<bool>(_Local_47)) {
                        return Text_Parsing_Parser::fail()(dictMonad)(Data_Semigroup::append()(Data_Semigroup::semigroupString())("reserved word ")(Data_Show::show()(Data_Show::showString())(v1)));
                    };
                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v1);
                });
                return lexeme(Text_Parsing_Parser_Combinators::_try_()(dictMonad)(go));
            }();
            boxed hexadecimal = Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(array_t{ "x", "X" }))(number(16)(Text_Parsing_Parser_Token::hexDigit()(dictMonad)));
            boxed fraction = [=]() -> boxed {
                boxed op = [=](const boxed& v1) -> boxed {
                    return [=](const boxed& v2) -> boxed {
                        if (unbox<dict_t>(v2).contains("Nothing")) {
                            return Data_Maybe::Nothing();
                        };
                        if (unbox<dict_t>(v2).contains("Just")) {
                            return Control_Bind::bind()(Data_Maybe::bindMaybe())(Data_Char_Unicode::digitToInt()(v1))([=](const boxed& v3) -> boxed {
                                return Control_Applicative::pure()(Data_Maybe::applicativeMaybe())(unbox<double>(unbox<double>(v2["value0"]) + unbox<double>(Data_Int::toNumber()(v3))) / 10.0);
                            });
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 550, column 9 - line 550, column 51): ");
                    };
                };
                return Text_Parsing_Parser_Combinators::asErrorMessage()(dictMonad)("fraction")(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("."))([=](const boxed& v1) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_Token::digit()(dictMonad)))("fraction"))([=](const boxed& v2) -> boxed {
                        return Data_Maybe::maybe()(Text_Parsing_Parser::fail()(dictMonad)("not digit"))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad)))(Data_Foldable::foldr()(Data_Foldable::foldableArray())(op)(Data_Maybe::Just()(0.0))(v2));
                    });
                }));
            }();
            boxed escapeGap = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Data_Array::some()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_Token::space()(dictMonad)))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("\\")))("end of string gap");
            boxed escapeEmpty = Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("&");
            boxed escMap = Data_Array::zip()(array_t{ "a", "b", "f", "n", "r", "t", "v", "\\", "\"", "'" })(array_t{ "", "\b", "\f", "\n", "\r", "\t", "\v", "\\", "\"", "'" });
            boxed dot = symbol(".");
            boxed decimal = number(10)(Text_Parsing_Parser_Token::digit()(dictMonad));
            boxed exponent_Prime_ = [=]() -> boxed {
                boxed::recur power;
                boxed::recur::weak power_Weak_(power);
                power = [=](const boxed& e) -> boxed {
                    boxed power = power_Weak_;
                    if (unbox<bool>(Data_Ord::lessThan()(Data_Ord::ordInt())(e)(0))) {
                        return 1.0 / unbox<double>(power(-unbox<int>(e)));
                    };
                    return Math::pow()(10.0)(Data_Int::toNumber()(e));
                };
                return Text_Parsing_Parser_Combinators::asErrorMessage()(dictMonad)("exponent")(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(array_t{ "e", "E" }))([=](const boxed& v1) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(sign(Data_Ring::ringInt()))([=](const boxed& v2) -> boxed {
                        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(decimal)("exponent"))([=](const boxed& v3) -> boxed {
                            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(power(v2(v3)));
                        });
                    });
                }));
            }();
            boxed fractExponent = [=](const boxed& n) -> boxed {
                boxed justExponent = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(exponent_Prime_)([=](const boxed& v1) -> boxed {
                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(unbox<double>(Data_Int::toNumber()(n)) * unbox<double>(v1));
                });
                boxed fractExponent_Prime_ = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(fraction)([=](const boxed& v1) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Combinators::option()(dictMonad)(1.0)(exponent_Prime_))([=](const boxed& v2) -> boxed {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(unbox<double>(unbox<double>(Data_Int::toNumber()(n)) + unbox<double>(v1)) * unbox<double>(v2));
                    });
                });
                return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(fractExponent_Prime_)(justExponent);
            };
            boxed fractFloat = [=](const boxed& n) -> boxed {
                return Data_Functor::map()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Data_Either::Right())(fractExponent(n));
            };
            boxed decimalFloat = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(decimal)([=](const boxed& v1) -> boxed {
                return Text_Parsing_Parser_Combinators::option()(dictMonad)(Data_Either::Left()(v1))(fractFloat(v1));
            });
            boxed zeroNumFloat = Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Data_Functor::map()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Data_Either::Left())(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(hexadecimal)(octal)))(decimalFloat))(fractFloat(0)))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_Either::Left()(0)));
            boxed natFloat = Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("0"))(zeroNumFloat))(decimalFloat);
            boxed naturalOrFloat = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(lexeme(natFloat))("number");
            boxed floating = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(decimal)(fractExponent);
            boxed _float_ = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(lexeme(floating))("float");
            boxed zeroNumber = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("0"))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(hexadecimal)(octal))(decimal))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(0))))("");
            boxed nat = Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(zeroNumber)(decimal);
            boxed _int_ = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(lexeme(sign(Data_Ring::ringInt())))([=](const boxed& v1) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(nat)([=](const boxed& v2) -> boxed {
                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v1(v2));
                });
            });
            boxed integer = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(lexeme(_int_))("integer");
            boxed natural = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(lexeme(nat))("natural");
            boxed comma = symbol(",");
            boxed commaSep = [=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::sepBy()(dictMonad)(p)(comma);
            };
            boxed commaSep1 = [=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::sepBy1()(dictMonad)(p)(comma);
            };
            boxed colon = symbol(":");
            boxed charNum = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(decimal)(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("o"))(number(8)(Text_Parsing_Parser_Token::octDigit()(dictMonad)))))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("x"))(number(16)(Text_Parsing_Parser_Token::hexDigit()(dictMonad)))))([=](const boxed& v1) -> boxed {
                boxed _Local_63 = Data_Ord::greaterThan()(Data_Ord::ordInt())(v1)(1114111);
                if (unbox<bool>(_Local_63)) {
                    return Text_Parsing_Parser::fail()(dictMonad)("invalid escape sequence");
                };
                boxed v2 = Data_Char::fromCharCode()(v1);
                if (unbox<dict_t>(v2).contains("Just")) {
                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v2["value0"]);
                };
                if (unbox<dict_t>(v2).contains("Nothing")) {
                    return Text_Parsing_Parser::fail()(dictMonad)("invalid character code (should not happen)");
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 448, column 17 - line 452, column 5): ");
            });
            boxed charLetter = Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)([=](const boxed& c) -> boxed {
                return unbox<bool>(Data_Eq::notEq()(Data_Eq::eqChar())(c)("'")) && unbox<bool>(unbox<bool>(Data_Eq::notEq()(Data_Eq::eqChar())(c)("\\")) && unbox<bool>(Data_Ord::greaterThan()(Data_Ord::ordChar())(c)("")));
            });
            boxed charEsc = [=]() -> boxed {
                boxed parseEsc = [=](const boxed& v1) -> boxed {
                    return Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(v1["value0"]))(v1["value1"]);
                };
                return Text_Parsing_Parser_Combinators::choice()(Data_Foldable::foldableArray())(dictMonad)(Data_Functor::map()(Data_Functor::functorArray())(parseEsc)(escMap));
            }();
            boxed charControl = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("^"))([=](const boxed& v1) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Token::upper()(dictMonad))([=](const boxed& v2) -> boxed {
                    boxed v3 = Data_Char::fromCharCode()(unbox<int>(unbox<int>(Data_Char::toCharCode()(v2)) - unbox<int>(Data_Char::toCharCode()("A"))) + 1);
                    if (unbox<dict_t>(v3).contains("Just")) {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v3["value0"]);
                    };
                    if (unbox<dict_t>(v3).contains("Nothing")) {
                        return Text_Parsing_Parser::fail()(dictMonad)("invalid character code (should not happen)");
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 437, column 9 - line 441, column 5): ");
                });
            });
            boxed caseString = [=](const boxed& name) -> boxed {
                if (unbox<bool>(v["caseSensitive"])) {
                    return Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(name))(name);
                };
                if (unbox<bool>(Data_Boolean::otherwise())) {
                    boxed::recur walk;
                    boxed::recur::weak walk_Weak_(walk);
                    boxed msg = Data_Show::show()(Data_Show::showString())(name);
                    boxed caseChar = [=](const boxed& c) -> boxed {
                        if (unbox<bool>(Data_Char_Unicode::isAlpha()(c))) {
                            return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::toLower()(c)))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::toUpper()(c)));
                        };
                        return Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(c);
                    };
                    walk = [=](const boxed& name_Prime_) -> boxed {
                        boxed walk = walk_Weak_;
                        boxed v1 = Data_String_CodeUnits::uncons()(name_Prime_);
                        if (unbox<dict_t>(v1).contains("Nothing")) {
                            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_Unit::unit());
                        };
                        if (unbox<dict_t>(v1).contains("Just")) {
                            return Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(caseChar(v1["value0"]["head"]))(msg))(walk(v1["value0"]["tail"]));
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 654, column 22 - line 656, column 86): ");
                    };
                    return Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(walk(name))(name);
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 649, column 5 - line 649, column 52): ");
            };
            boxed reserved = [=](const boxed& name) -> boxed {
                boxed go = Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(caseString(name))(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_Combinators::notFollowedBy()(dictMonad)(v["identLetter"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())("end of ")(name)));
                return lexeme(Text_Parsing_Parser_Combinators::_try_()(dictMonad)(go));
            };
            boxed brackets = [=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::between()(dictMonad)(symbol("["))(symbol("]"))(p);
            };
            boxed braces = [=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::between()(dictMonad)(symbol("{"))(symbol("}"))(p);
            };
            boxed ascii3codes = array_t{ "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "SUB", "ESC", "DEL" };
            boxed ascii3 = array_t{ "\0", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
            boxed ascii2codes = array_t{ "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI", "EM", "FS", "GS", "RS", "US", "SP" };
            boxed ascii2 = array_t{ "\b", "\t", "\n", "\v", "\f", "\r", "", "", "", "", "", "", "", " " };
            boxed asciiMap = Data_Array::zip()(Data_Semigroup::append()(Data_Semigroup::semigroupArray())(ascii3codes)(ascii2codes))(Data_Semigroup::append()(Data_Semigroup::semigroupArray())(ascii3)(ascii2));
            boxed charAscii = [=]() -> boxed {
                boxed parseAscii = [=](const boxed& v1) -> boxed {
                    return Text_Parsing_Parser_Combinators::_try_()(dictMonad)(Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Text_Parsing_Parser_String::_string_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(v1["value0"]))(v1["value1"]));
                };
                return Text_Parsing_Parser_Combinators::choice()(Data_Foldable::foldableArray())(dictMonad)(Data_Functor::map()(Data_Functor::functorArray())(parseAscii)(asciiMap));
            }();
            boxed escapeCode = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(charEsc)(charNum))(charAscii))(charControl))("escape code");
            boxed charEscape = Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("\\"))(escapeCode);
            boxed characterChar = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(charLetter)(charEscape))("literal character");
            boxed charLiteral = [=]() -> boxed {
                boxed go = Text_Parsing_Parser_Combinators::between()(dictMonad)(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("'"))(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("'"))("end of character"))(characterChar);
                return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(lexeme(go))("character");
            }();
            boxed stringEscape = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("\\"))([=](const boxed& v1) -> boxed {
                return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(escapeGap)(Data_Maybe::Nothing()))(Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(escapeEmpty)(Data_Maybe::Nothing())))(Data_Functor::map()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Data_Maybe::Just())(escapeCode));
            });
            boxed stringChar = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Data_Functor::map()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Data_Maybe::Just())(stringLetter))(stringEscape))("string character");
            boxed stringLiteral = [=]() -> boxed {
                boxed folder = [=](const boxed& v1) -> boxed {
                    return [=](const boxed& chars) -> boxed {
                        if (unbox<dict_t>(v1).contains("Nothing")) {
                            return chars;
                        };
                        if (unbox<dict_t>(v1).contains("Just")) {
                            return Data_List_Types::Cons()(v1["value0"])(chars);
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Token (line 404, column 9 - line 404, column 55): ");
                    };
                };
                boxed go = Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Combinators::between()(dictMonad)(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("\""))(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)("\""))("end of string"))(Data_List::many()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(stringChar)))([=](const boxed& v1) -> boxed {
                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_String_CodeUnits::fromCharArray()(Data_List::toUnfoldable()(Data_Unfoldable::unfoldableArray())(Data_Foldable::foldr()(Data_List_Types::foldableList())(folder)(Data_List_Types::Nil())(v1))));
                });
                return lexeme(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(go)("literal string"));
            }();
            boxed angles = [=](const boxed& p) -> boxed {
                return Text_Parsing_Parser_Combinators::between()(dictMonad)(symbol("<"))(symbol(">"))(p);
            };
            return dict_t{
                { "identifier", identifier },
                { "reserved", reserved },
                { "operator", _operator_ },
                { "reservedOp", reservedOp },
                { "charLiteral", charLiteral },
                { "stringLiteral", stringLiteral },
                { "natural", natural },
                { "integer", integer },
                { "float", _float_ },
                { "naturalOrFloat", naturalOrFloat },
                { "decimal", decimal },
                { "hexadecimal", hexadecimal },
                { "octal", octal },
                { "symbol", symbol },
                { "lexeme", lexeme },
                { "whiteSpace", Text_Parsing_Parser_Token::whiteSpace_Prime_()(dictMonad)(v) },
                { "parens", parens },
                { "braces", braces },
                { "angles", angles },
                { "brackets", brackets },
                { "semi", semi },
                { "comma", comma },
                { "colon", colon },
                { "dot", dot },
                { "semiSep", semiSep },
                { "semiSep1", semiSep1 },
                { "commaSep", commaSep },
                { "commaSep1", commaSep1 }
            };
        };
    };
    return _;
};
auto alphaNum() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(Data_Char_Unicode::isAlphaNum()))("letter or digit");
    };
    return _;
};


} // end namespace Text_Parsing_Parser_Token


