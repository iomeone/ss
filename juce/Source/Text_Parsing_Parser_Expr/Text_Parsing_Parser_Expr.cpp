#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Category/Control_Category.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_List/Data_List.h"
#include "Data_List_Types/Data_List_Types.h"
#include "Prelude/Prelude.h"
#include "Text_Parsing_Parser/Text_Parsing_Parser.h"
#include "Text_Parsing_Parser_Combinators/Text_Parsing_Parser_Combinators.h"

#include "Text_Parsing_Parser_Expr/Text_Parsing_Parser_Expr.h"


namespace Text_Parsing_Parser_Expr {

auto AssocNone() -> const boxed& {
    static const boxed _ = dict_t{
        { "AssocNone", true }
    };
    return _;
};
auto AssocLeft() -> const boxed& {
    static const boxed _ = dict_t{
        { "AssocLeft", true }
    };
    return _;
};
auto AssocRight() -> const boxed& {
    static const boxed _ = dict_t{
        { "AssocRight", true }
    };
    return _;
};
auto Infix() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return [=](const boxed& value1) -> boxed {
            return dict_t{
                { "Infix", true },
                { "value0", value0 },
                { "value1", value1 }
            };
        };
    };
    return _;
};
auto Prefix() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "Prefix", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto Postfix() -> const boxed& {
    static const boxed _ = [](const boxed& value0) -> boxed {
        return dict_t{
            { "Postfix", true },
            { "value0", value0 }
        };
    };
    return _;
};
auto termP() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& prefixP) -> boxed {
            return [=](const boxed& term) -> boxed {
                return [=](const boxed& postfixP) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(prefixP)([=](const boxed& v) -> boxed {
                        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(term)([=](const boxed& v1) -> boxed {
                            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(postfixP)([=](const boxed& v2) -> boxed {
                                return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v2(v(v1)));
                            });
                        });
                    });
                };
            };
        };
    };
    return _;
};
auto splitOp() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return [=](const boxed& accum) -> boxed {
            if (unbox<dict_t>(v).contains("Infix")) {
                if (unbox<dict_t>(v["value1"]).contains("AssocNone")) {
                    return dict_t{
                        { "rassoc", accum["rassoc"] },
                        { "lassoc", accum["lassoc"] },
                        { "nassoc", Data_List_Types::Cons()(v["value0"])(accum["nassoc"]) },
                        { "prefix", accum["prefix"] },
                        { "postfix", accum["postfix"] }
                    };
                };
            };
            if (unbox<dict_t>(v).contains("Infix")) {
                if (unbox<dict_t>(v["value1"]).contains("AssocLeft")) {
                    return dict_t{
                        { "rassoc", accum["rassoc"] },
                        { "lassoc", Data_List_Types::Cons()(v["value0"])(accum["lassoc"]) },
                        { "nassoc", accum["nassoc"] },
                        { "prefix", accum["prefix"] },
                        { "postfix", accum["postfix"] }
                    };
                };
            };
            if (unbox<dict_t>(v).contains("Infix")) {
                if (unbox<dict_t>(v["value1"]).contains("AssocRight")) {
                    return dict_t{
                        { "rassoc", Data_List_Types::Cons()(v["value0"])(accum["rassoc"]) },
                        { "lassoc", accum["lassoc"] },
                        { "nassoc", accum["nassoc"] },
                        { "prefix", accum["prefix"] },
                        { "postfix", accum["postfix"] }
                    };
                };
            };
            if (unbox<dict_t>(v).contains("Prefix")) {
                return dict_t{
                    { "rassoc", accum["rassoc"] },
                    { "lassoc", accum["lassoc"] },
                    { "nassoc", accum["nassoc"] },
                    { "prefix", Data_List_Types::Cons()(v["value0"])(accum["prefix"]) },
                    { "postfix", accum["postfix"] }
                };
            };
            if (unbox<dict_t>(v).contains("Postfix")) {
                return dict_t{
                    { "rassoc", accum["rassoc"] },
                    { "lassoc", accum["lassoc"] },
                    { "nassoc", accum["nassoc"] },
                    { "prefix", accum["prefix"] },
                    { "postfix", Data_List_Types::Cons()(v["value0"])(accum["postfix"]) }
                };
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Text.Parsing.Parser.Expr (line 69, column 1 - line 69, column 80): ");
        };
    };
    return _;
};
auto rassocP1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& rassocOp) -> boxed {
                return [=](const boxed& prefixP) -> boxed {
                    return [=](const boxed& term) -> boxed {
                        return [=](const boxed& postfixP) -> boxed {
                            return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Expr::rassocP()(dictMonad)(x)(rassocOp)(prefixP)(term)(postfixP))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(x));
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto rassocP() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& rassocOp) -> boxed {
                return [=](const boxed& prefixP) -> boxed {
                    return [=](const boxed& term) -> boxed {
                        return [=](const boxed& postfixP) -> boxed {
                            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(rassocOp)([=](const boxed& v) -> boxed {
                                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Expr::termP()(dictMonad)(prefixP)(term)(postfixP))([=](const boxed& v1) -> boxed {
                                    return Text_Parsing_Parser_Expr::rassocP1()(dictMonad)(v1)(rassocOp)(prefixP)(term)(postfixP);
                                }))([=](const boxed& v1) -> boxed {
                                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v(x)(v1));
                                });
                            });
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto nassocP() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& nassocOp) -> boxed {
                return [=](const boxed& prefixP) -> boxed {
                    return [=](const boxed& term) -> boxed {
                        return [=](const boxed& postfixP) -> boxed {
                            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(nassocOp)([=](const boxed& v) -> boxed {
                                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Expr::termP()(dictMonad)(prefixP)(term)(postfixP))([=](const boxed& v1) -> boxed {
                                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v(x)(v1));
                                });
                            });
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto lassocP1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& lassocOp) -> boxed {
                return [=](const boxed& prefixP) -> boxed {
                    return [=](const boxed& term) -> boxed {
                        return [=](const boxed& postfixP) -> boxed {
                            return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Expr::lassocP()(dictMonad)(x)(lassocOp)(prefixP)(term)(postfixP))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(x));
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto lassocP() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& x) -> boxed {
            return [=](const boxed& lassocOp) -> boxed {
                return [=](const boxed& prefixP) -> boxed {
                    return [=](const boxed& term) -> boxed {
                        return [=](const boxed& postfixP) -> boxed {
                            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(lassocOp)([=](const boxed& v) -> boxed {
                                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Expr::termP()(dictMonad)(prefixP)(term)(postfixP))([=](const boxed& v1) -> boxed {
                                    return Text_Parsing_Parser_Expr::lassocP1()(dictMonad)(v(x)(v1))(lassocOp)(prefixP)(term)(postfixP);
                                });
                            });
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto makeParser() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& term) -> boxed {
            return [=](const boxed& ops) -> boxed {
                boxed accum = Data_Foldable::foldr()(Data_Foldable::foldableArray())(Text_Parsing_Parser_Expr::splitOp())(dict_t{
                    { "rassoc", Data_List_Types::Nil() },
                    { "lassoc", Data_List_Types::Nil() },
                    { "nassoc", Data_List_Types::Nil() },
                    { "prefix", Data_List_Types::Nil() },
                    { "postfix", Data_List_Types::Nil() }
                })(ops);
                boxed lassocOp = Text_Parsing_Parser_Combinators::choice()(Data_List_Types::foldableList())(dictMonad)(accum["lassoc"]);
                boxed nassocOp = Text_Parsing_Parser_Combinators::choice()(Data_List_Types::foldableList())(dictMonad)(accum["nassoc"]);
                boxed postfixOp = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_Combinators::choice()(Data_List_Types::foldableList())(dictMonad)(accum["postfix"]))("");
                boxed postfixP = Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(postfixOp)(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Control_Category::identity()(Control_Category::categoryFn())));
                boxed prefixOp = Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Text_Parsing_Parser_Combinators::choice()(Data_List_Types::foldableList())(dictMonad)(accum["prefix"]))("");
                boxed prefixP = Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(prefixOp)(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Control_Category::identity()(Control_Category::categoryFn())));
                boxed rassocOp = Text_Parsing_Parser_Combinators::choice()(Data_List_Types::foldableList())(dictMonad)(accum["rassoc"]);
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Expr::termP()(dictMonad)(prefixP)(term)(postfixP))([=](const boxed& v) -> boxed {
                    return Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Expr::rassocP()(dictMonad)(v)(rassocOp)(prefixP)(term)(postfixP))(Text_Parsing_Parser_Expr::lassocP()(dictMonad)(v)(lassocOp)(prefixP)(term)(postfixP)))(Text_Parsing_Parser_Expr::nassocP()(dictMonad)(v)(nassocOp)(prefixP)(term)(postfixP)))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v)))("operator");
                });
            };
        };
    };
    return _;
};
auto buildExprParser() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& operators) -> boxed {
            return [=](const boxed& simpleExpr) -> boxed {
                return Data_Foldable::foldl()(Data_Foldable::foldableArray())(Text_Parsing_Parser_Expr::makeParser()(dictMonad))(simpleExpr)(operators);
            };
        };
    };
    return _;
};


} // end namespace Text_Parsing_Parser_Expr


