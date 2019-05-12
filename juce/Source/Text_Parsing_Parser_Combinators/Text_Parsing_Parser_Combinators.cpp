#include "Control_Alt/Control_Alt.h"
#include "Control_Applicative/Control_Applicative.h"
#include "Control_Apply/Control_Apply.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad_Except/Control_Monad_Except.h"
#include "Control_Monad_Except_Trans/Control_Monad_Except_Trans.h"
#include "Control_Monad_State/Control_Monad_State.h"
#include "Control_Monad_State_Trans/Control_Monad_State_Trans.h"
#include "Control_Plus/Control_Plus.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Either/Data_Either.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_Function/Data_Function.h"
#include "Data_Functor/Data_Functor.h"
#include "Data_List/Data_List.h"
#include "Data_List_Types/Data_List_Types.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Tuple/Data_Tuple.h"
#include "Data_Unit/Data_Unit.h"
#include "Prelude/Prelude.h"
#include "Text_Parsing_Parser/Text_Parsing_Parser.h"

#include "Text_Parsing_Parser_Combinators/Text_Parsing_Parser_Combinators.h"


namespace Text_Parsing_Parser_Combinators {

auto withErrorMessage() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& msg) -> boxed {
                return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(p)(Text_Parsing_Parser::fail()(dictMonad)(Data_Semigroup::append()(Data_Semigroup::semigroupString())("Expected ")(msg)));
            };
        };
    };
    return _;
};
auto tryRethrow() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Text_Parsing_Parser::ParserT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::ExceptT())(Control_Monad_State_Trans::StateT()))([=](const boxed& v) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Control_Monad_State_Trans::runStateT()(Control_Monad_Except_Trans::runExceptT()(Data_Newtype::unwrap()(Text_Parsing_Parser::newtypeParserT())(p)))(v))([=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1["value0"]).contains("Left")) {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(Data_Either::Left()(Text_Parsing_Parser::ParseError()(v1["value0"]["value0"]["value0"])(v["value1"])))(Text_Parsing_Parser::ParseState()(v1["value1"]["value0"])(v1["value1"]["value1"])(v["value2"])));
                    };
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v1["value0"])(v1["value1"]));
                });
            });
        };
    };
    return _;
};
auto _try_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Text_Parsing_Parser::ParserT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::ExceptT())(Control_Monad_State_Trans::StateT()))([=](const boxed& v) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Control_Monad_State_Trans::runStateT()(Control_Monad_Except_Trans::runExceptT()(Data_Newtype::unwrap()(Text_Parsing_Parser::newtypeParserT())(p)))(v))([=](const boxed& v1) -> boxed {
                    if (unbox<dict_t>(v1["value0"]).contains("Left")) {
                        return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v1["value0"])(Text_Parsing_Parser::ParseState()(v1["value1"]["value0"])(v1["value1"]["value1"])(v["value2"])));
                    };
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v1["value0"])(v1["value1"]));
                });
            });
        };
    };
    return _;
};
auto skipMany1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(p)([=](const boxed& v) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Combinators::skipMany()(dictMonad)(p))([=](const boxed& v1) -> boxed {
                    return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_Unit::unit());
                });
            });
        };
    };
    return _;
};
auto skipMany() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Combinators::skipMany1()(dictMonad)(p))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_Unit::unit()));
        };
    };
    return _;
};
auto sepEndBy1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& sep) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(p)([=](const boxed& v) -> boxed {
                    return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(sep)([=](const boxed& v1) -> boxed {
                        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Combinators::sepEndBy()(dictMonad)(p)(sep))([=](const boxed& v2) -> boxed {
                            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_List_Types::Cons()(v)(v2));
                        });
                    }))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_List::singleton()(v)));
                });
            };
        };
    };
    return _;
};
auto sepEndBy() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& sep) -> boxed {
                return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Combinators::sepEndBy1()(dictMonad)(p)(sep))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_List_Types::Nil()));
            };
        };
    };
    return _;
};
auto sepBy1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& sep) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(p)([=](const boxed& v) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Data_List::many()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(sep)(p)))([=](const boxed& v1) -> boxed {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_List_Types::Cons()(v)(v1));
                    });
                });
            };
        };
    };
    return _;
};
auto sepBy() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& sep) -> boxed {
                return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Combinators::sepBy1()(dictMonad)(p)(sep))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_List_Types::Nil()));
            };
        };
    };
    return _;
};
auto optional() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Data_Functor::_void_()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(p))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_Unit::unit()));
        };
    };
    return _;
};
auto option() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& a) -> boxed {
            return [=](const boxed& p) -> boxed {
                return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(p)(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(a));
            };
        };
    };
    return _;
};
auto optionMaybe() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Text_Parsing_Parser_Combinators::option()(dictMonad)(Data_Maybe::Nothing())(Data_Functor::map()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(Data_Maybe::Just())(p));
        };
    };
    return _;
};
auto notFollowedBy() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Text_Parsing_Parser_Combinators::_try_()(dictMonad)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(Text_Parsing_Parser_Combinators::_try_()(dictMonad)(p))(Text_Parsing_Parser::fail()(dictMonad)("Negated parser succeeded")))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_Unit::unit())));
        };
    };
    return _;
};
auto manyTill() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& end) -> boxed {
                boxed::recur scan;
                boxed::recur::weak scan_Weak_(scan);
                scan = [=]() -> boxed {
                    auto& scan = scan_Weak_;
                    return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Data_Functor::voidLeft()(Text_Parsing_Parser::functorParserT()(dictMonad["Bind1"](undefined)["Apply0"](undefined)["Functor0"](undefined)))(end)(Data_List_Types::Nil()))(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(p)([=](const boxed& v) -> boxed {
                        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(scan)([=](const boxed& v1) -> boxed {
                            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_List_Types::Cons()(v)(v1));
                        });
                    }));
                }();
                return scan;
            };
        };
    };
    return _;
};
auto many1Till() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& end) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(p)([=](const boxed& v) -> boxed {
                    return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Combinators::manyTill()(dictMonad)(p)(end))([=](const boxed& v1) -> boxed {
                        return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(Data_List_Types::Cons()(v)(v1));
                    });
                });
            };
        };
    };
    return _;
};
auto lookAhead() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Text_Parsing_Parser::ParserT())(Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Monad_Except_Trans::ExceptT())(Control_Monad_State_Trans::StateT()))([=](const boxed& s) -> boxed {
                return Control_Bind::bind()(dictMonad["Bind1"](undefined))(Control_Monad_State_Trans::runStateT()(Control_Monad_Except_Trans::runExceptT()(Data_Newtype::unwrap()(Text_Parsing_Parser::newtypeParserT())(p)))(s))([=](const boxed& v) -> boxed {
                    return Control_Applicative::pure()(dictMonad["Applicative0"](undefined))(Data_Tuple::Tuple()(v["value0"])(s));
                });
            });
        };
    };
    return _;
};
auto endBy1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& sep) -> boxed {
                return Data_List::some()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(Control_Apply::applyFirst()(Text_Parsing_Parser::applyParserT()(dictMonad))(p)(sep));
            };
        };
    };
    return _;
};
auto endBy() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& sep) -> boxed {
                return Data_List::many()(Text_Parsing_Parser::alternativeParserT()(dictMonad))(Text_Parsing_Parser::lazyParserT())(Control_Apply::applyFirst()(Text_Parsing_Parser::applyParserT()(dictMonad))(p)(sep));
            };
        };
    };
    return _;
};
auto choice() -> const boxed& {
    static const boxed _ = [](const boxed& dictFoldable) -> boxed {
        return [=](const boxed& dictMonad) -> boxed {
            return Data_Foldable::foldl()(dictFoldable)(Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad)))(Control_Plus::empty()(Text_Parsing_Parser::plusParserT()(dictMonad)));
        };
    };
    return _;
};
auto chainr1_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(f)([=](const boxed& v) -> boxed {
                        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(Text_Parsing_Parser_Combinators::chainr1()(dictMonad)(p)(f))([=](const boxed& v1) -> boxed {
                            return Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(v(a)(v1));
                        });
                    }))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(a));
                };
            };
        };
    };
    return _;
};
auto chainr1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(p)([=](const boxed& v) -> boxed {
                    return Text_Parsing_Parser_Combinators::chainr1_Prime_()(dictMonad)(p)(f)(v);
                });
            };
        };
    };
    return _;
};
auto chainr() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Combinators::chainr1()(dictMonad)(p)(f))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(a));
                };
            };
        };
    };
    return _;
};
auto chainl1_Prime_() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(f)([=](const boxed& v) -> boxed {
                        return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(p)([=](const boxed& v1) -> boxed {
                            return Text_Parsing_Parser_Combinators::chainl1_Prime_()(dictMonad)(p)(f)(v(a)(v1));
                        });
                    }))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(a));
                };
            };
        };
    };
    return _;
};
auto chainl1() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& f) -> boxed {
                return Control_Bind::bind()(Text_Parsing_Parser::bindParserT()(dictMonad))(p)([=](const boxed& v) -> boxed {
                    return Text_Parsing_Parser_Combinators::chainl1_Prime_()(dictMonad)(p)(f)(v);
                });
            };
        };
    };
    return _;
};
auto chainl() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& p) -> boxed {
            return [=](const boxed& f) -> boxed {
                return [=](const boxed& a) -> boxed {
                    return Control_Alt::alt()(Text_Parsing_Parser::altParserT()(dictMonad))(Text_Parsing_Parser_Combinators::chainl1()(dictMonad)(p)(f))(Control_Applicative::pure()(Text_Parsing_Parser::applicativeParserT()(dictMonad))(a));
                };
            };
        };
    };
    return _;
};
auto between() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return [=](const boxed& open) -> boxed {
            return [=](const boxed& close) -> boxed {
                return [=](const boxed& p) -> boxed {
                    return Control_Apply::applyFirst()(Text_Parsing_Parser::applyParserT()(dictMonad))(Control_Apply::applySecond()(Text_Parsing_Parser::applyParserT()(dictMonad))(open)(p))(close);
                };
            };
        };
    };
    return _;
};
auto asErrorMessage() -> const boxed& {
    static const boxed _ = [](const boxed& dictMonad) -> boxed {
        return Data_Function::flip()(Text_Parsing_Parser_Combinators::withErrorMessage()(dictMonad));
    };
    return _;
};


} // end namespace Text_Parsing_Parser_Combinators


