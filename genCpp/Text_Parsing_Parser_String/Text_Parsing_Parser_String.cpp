#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad_State/Control_Monad_State.h"
#include "Control_Monad_State_Class/Control_Monad_State_Class.h"
#include "Data_Array/Data_Array.h"
#include "Data_Eq/Data_Eq.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"
#include "Data_String/Data_String.h"
#include "Data_String_CodePoints/Data_String_CodePoints.h"
#include "Data_String_CodeUnits/Data_String_CodeUnits.h"
#include "Data_String_Common/Data_String_Common.h"
#include "Data_String_Pattern/Data_String_Pattern.h"
#include "Prelude/Prelude.h"
#include "Text_Parsing_Parser/Text_Parsing_Parser.h"
#include "Text_Parsing_Parser_Combinators/Text_Parsing_Parser_Combinators.h"
#include "Text_Parsing_Parser_Pos/Text_Parsing_Parser_Pos.h"

#include "Text_Parsing_Parser_String/Text_Parsing_Parser_String.h"


namespace Text_Parsing_Parser_String {

auto StringLike() -> const boxed& {
    static const boxed _ = [](const boxed& drop) -> boxed {
        return [=](const boxed& indexOf) -> boxed {
            return [=](const boxed& null) -> boxed {
                return [=](const boxed& uncons) -> boxed {
                    return dict_t{
                        { "drop", drop },
                        { "indexOf", indexOf },
                        { "null", null },
                        { "uncons", uncons }
                    };
                };
            };
        };
    };
    return _;
};
auto uncons() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["uncons"];
    };
    return _;
};
auto stringLikeString() -> boxed {
    return Text_Parsing_Parser_String::StringLike()(Data_String_CodePoints::drop())(Data_String_CodePoints::indexOf())(Data_String_Common::null())(Data_String_CodeUnits::uncons());
};
auto null() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["null"];
    };
    return _;
};
auto indexOf() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["indexOf"];
    };
    return _;
};
auto eof() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_Monad_State_Class::gets()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v) -> boxed {
                return v["value0"];
            }))([=](const boxed& v) -> boxed {
                return Control_Applicative::unless()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Text_Parsing_Parser_String::null()(dictStringLike)(v))(Text_Parsing_Parser::fail()(dictMonad)("Expected EOF"));
            });
        };
    };
    return _;
};
auto drop() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["drop"];
    };
    return _;
};
auto _string_() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return [=](const boxed& str) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_Monad_State_Class::gets()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v) -> boxed {
                    return v["value0"];
                }))([=](const boxed& v) -> boxed {
                    boxed v1 = Text_Parsing_Parser_String::indexOf()(dictStringLike)(Data_Newtype::wrap()(Data_String_Pattern::newtypePattern())(str))(v);
                    if (unbox<dict_t>(v1).contains("Just")) {
                        if (unbox<int>(v1["value0"]) == 0) {
                            return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_Monad_State_Class::modify_()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v2) -> boxed {
                                return Text_Parsing_Parser::ParseState()(Text_Parsing_Parser_String::drop()(dictStringLike)(Data_String_CodePoints::length()(str))(v))(Text_Parsing_Parser_Pos::updatePosString()(v2["value1"])(str))(true);
                            }))([=](const boxed&) -> boxed {
                                return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(str);
                            });
                        };
                    };
                    return Text_Parsing_Parser::fail()(dictMonad)(Data_Semigroup::append()(Data_Semigroup::semigroupString())("Expected ")(Data_Show::show()(Data_Show::showString())(str)));
                });
            };
        };
    };
    return _;
};
auto anyChar() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_Monad_State_Class::gets()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v) -> boxed {
                return v["value0"];
            }))([=](const boxed& v) -> boxed {
                boxed v1 = Text_Parsing_Parser_String::uncons()(dictStringLike)(v);
                if (unbox<dict_t>(v1).contains("Nothing")) {
                    return Text_Parsing_Parser::fail()(dictMonad)("Unexpected EOF");
                };
                if (unbox<dict_t>(v1).contains("Just")) {
                    return Control_Bind::discard()(Control_Bind::discardUnit())(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_Monad_State_Class::modify_()(Text_Parsing_Parser::monadStateParserT()(dictMonad))([=](const boxed& v2) -> boxed {
                        return Text_Parsing_Parser::ParseState()(v1["value0"]["tail"])(Text_Parsing_Parser_Pos::updatePosString()(v2["value1"])(Data_String_CodeUnits::singleton()(v1["value0"]["head"])))(true);
                    }))([=](const boxed&) -> boxed {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v1["value0"]["head"]);
                    });
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.String (line 56, column 3 - line 63, column 16): ");
            });
        };
    };
    return _;
};
auto satisfy() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Text_Parsing_Parser_Combinators::tryRethrow()(dictMonad)(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_String::anyChar()(dictStringLike)(dictMonad))([=](const boxed& v) -> boxed {
                    boxed _Local_35 = f(v);
                    if (unbox<bool>(_Local_35)) {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v);
                    };
                    return Text_Parsing_Parser::fail()(dictMonad)(Data_Semigroup::append()(Data_Semigroup::semigroupString())("Character '")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_String_CodeUnits::singleton()(v))("' did not satisfy predicate")));
                }));
            };
        };
    };
    return _;
};
auto _char_() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return [=](const boxed& c) -> boxed {
                return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(dictStringLike)(dictMonad)([=](const boxed& v) -> boxed {
                    return Data_Eq::eq()(Data_Eq::eqChar())(v)(c);
                }))(Data_Show::show()(Data_Show::showChar())(c));
            };
        };
    };
    return _;
};
auto noneOf() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return [=](const boxed& ss) -> boxed {
                return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(dictStringLike)(dictMonad)(Data_Function::flip()(Data_Foldable::notElem()(Data_Foldable::foldableArray())(Data_Eq::eqChar()))(ss)))(Data_Semigroup::append()(Data_Semigroup::semigroupString())("none of ")(Data_Show::show()(Data_Show::showArray()(Data_Show::showChar()))(ss)));
            };
        };
    };
    return _;
};
auto oneOf() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return [=](const boxed& ss) -> boxed {
                return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_String::satisfy()(dictStringLike)(dictMonad)(Data_Function::flip()(Data_Foldable::elem()(Data_Foldable::foldableArray())(Data_Eq::eqChar()))(ss)))(Data_Semigroup::append()(Data_Semigroup::semigroupString())("one of ")(Data_Show::show()(Data_Show::showArray()(Data_Show::showChar()))(ss)));
            };
        };
    };
    return _;
};
auto whiteSpace() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Data_Array::many()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(Text_Parsing_Parser_String::satisfy()(dictStringLike)(dictMonad)([=](const boxed& c) -> boxed {
                return unbox<bool>(Data_Eq::eq()(Data_Eq::eqChar())(c)("\n"))|| unbox<bool>(unbox<bool>(Data_Eq::eq()(Data_Eq::eqChar())(c)("\r"))|| unbox<bool>(unbox<bool>(Data_Eq::eq()(Data_Eq::eqChar())(c)(" "))|| unbox<bool>(Data_Eq::eq()(Data_Eq::eqChar())(c)("\t"))));
            })))([=](const boxed& v) -> boxed {
                return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_String_CodeUnits::fromCharArray()(v));
            });
        };
    };
    return _;
};
auto skipSpaces() -> const boxed& {
    static const boxed _ = [](const boxed& dictStringLike) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Data_Functor::_void_()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Text_Parsing_Parser_String::whiteSpace()(dictStringLike)(dictMonad));
        };
    };
    return _;
};


} // end namespace Text_Parsing_Parser_String


