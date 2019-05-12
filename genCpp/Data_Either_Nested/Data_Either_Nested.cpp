#include "Data_Either/Data_Either.h"
#include "Data_Void/Data_Void.h"

#include "Data_Either_Nested/Data_Either_Nested.h"


namespace Data_Either_Nested {

auto in9() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Left()(v)))))))));
    };
    return _;
};
auto in8() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Left()(v))))))));
    };
    return _;
};
auto in7() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Left()(v)))))));
    };
    return _;
};
auto in6() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Left()(v))))));
    };
    return _;
};
auto in5() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Left()(v)))));
    };
    return _;
};
auto in4() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Left()(v))));
    };
    return _;
};
auto in3() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Either::Right()(Data_Either::Right()(Data_Either::Left()(v)));
    };
    return _;
};
auto in2() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Either::Right()(Data_Either::Left()(v));
    };
    return _;
};
auto in10() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        return Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Right()(Data_Either::Left()(v))))))))));
    };
    return _;
};
auto in1() -> boxed {
    return Data_Either::Left();
};
auto either9() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return [=](const boxed& i) -> boxed {
                                        return [=](const boxed& y) -> boxed {
                                            if (unbox<dict_t>(y).contains("Left")) {
                                                return a(y["value0"]);
                                            };
                                            if (unbox<dict_t>(y).contains("Right")) {
                                                if (unbox<dict_t>(y["value0"]).contains("Left")) {
                                                    return b(y["value0"]["value0"]);
                                                };
                                                if (unbox<dict_t>(y["value0"]).contains("Right")) {
                                                    if (unbox<dict_t>(y["value0"]["value0"]).contains("Left")) {
                                                        return c(y["value0"]["value0"]["value0"]);
                                                    };
                                                    if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Left")) {
                                                            return d(y["value0"]["value0"]["value0"]["value0"]);
                                                        };
                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                return e(y["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                            };
                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                    return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                };
                                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                        return g(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                    };
                                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                            return h(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                        };
                                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                                return i(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                            };
                                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                                return Data_Void::absurd()(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                            };
                                                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 236, column 29 - line 238, column 40): ");
                                                                        };
                                                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 234, column 27 - line 238, column 40): ");
                                                                    };
                                                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 232, column 25 - line 238, column 40): ");
                                                                };
                                                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 230, column 23 - line 238, column 40): ");
                                                            };
                                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 228, column 21 - line 238, column 40): ");
                                                        };
                                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 226, column 19 - line 238, column 40): ");
                                                    };
                                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 224, column 17 - line 238, column 40): ");
                                                };
                                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 222, column 15 - line 238, column 40): ");
                                            };
                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 220, column 31 - line 238, column 40): ");
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto either8() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return [=](const boxed& y) -> boxed {
                                        if (unbox<dict_t>(y).contains("Left")) {
                                            return a(y["value0"]);
                                        };
                                        if (unbox<dict_t>(y).contains("Right")) {
                                            if (unbox<dict_t>(y["value0"]).contains("Left")) {
                                                return b(y["value0"]["value0"]);
                                            };
                                            if (unbox<dict_t>(y["value0"]).contains("Right")) {
                                                if (unbox<dict_t>(y["value0"]["value0"]).contains("Left")) {
                                                    return c(y["value0"]["value0"]["value0"]);
                                                };
                                                if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Left")) {
                                                        return d(y["value0"]["value0"]["value0"]["value0"]);
                                                    };
                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                            return e(y["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                        };
                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                            };
                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                    return g(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                };
                                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                        return h(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                    };
                                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                        return Data_Void::absurd()(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                    };
                                                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 215, column 27 - line 217, column 38): ");
                                                                };
                                                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 213, column 25 - line 217, column 38): ");
                                                            };
                                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 211, column 23 - line 217, column 38): ");
                                                        };
                                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 209, column 21 - line 217, column 38): ");
                                                    };
                                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 207, column 19 - line 217, column 38): ");
                                                };
                                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 205, column 17 - line 217, column 38): ");
                                            };
                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 203, column 15 - line 217, column 38): ");
                                        };
                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 201, column 29 - line 217, column 38): ");
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto either7() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& y) -> boxed {
                                    if (unbox<dict_t>(y).contains("Left")) {
                                        return a(y["value0"]);
                                    };
                                    if (unbox<dict_t>(y).contains("Right")) {
                                        if (unbox<dict_t>(y["value0"]).contains("Left")) {
                                            return b(y["value0"]["value0"]);
                                        };
                                        if (unbox<dict_t>(y["value0"]).contains("Right")) {
                                            if (unbox<dict_t>(y["value0"]["value0"]).contains("Left")) {
                                                return c(y["value0"]["value0"]["value0"]);
                                            };
                                            if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Left")) {
                                                    return d(y["value0"]["value0"]["value0"]["value0"]);
                                                };
                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                        return e(y["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                    };
                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                            return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                        };
                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                return g(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                            };
                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                return Data_Void::absurd()(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                            };
                                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 196, column 25 - line 198, column 36): ");
                                                        };
                                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 194, column 23 - line 198, column 36): ");
                                                    };
                                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 192, column 21 - line 198, column 36): ");
                                                };
                                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 190, column 19 - line 198, column 36): ");
                                            };
                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 188, column 17 - line 198, column 36): ");
                                        };
                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 186, column 15 - line 198, column 36): ");
                                    };
                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 184, column 27 - line 198, column 36): ");
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto either6() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& y) -> boxed {
                                if (unbox<dict_t>(y).contains("Left")) {
                                    return a(y["value0"]);
                                };
                                if (unbox<dict_t>(y).contains("Right")) {
                                    if (unbox<dict_t>(y["value0"]).contains("Left")) {
                                        return b(y["value0"]["value0"]);
                                    };
                                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Left")) {
                                            return c(y["value0"]["value0"]["value0"]);
                                        };
                                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Left")) {
                                                return d(y["value0"]["value0"]["value0"]["value0"]);
                                            };
                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                    return e(y["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                };
                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                        return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                    };
                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                        return Data_Void::absurd()(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                    };
                                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 179, column 23 - line 181, column 34): ");
                                                };
                                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 177, column 21 - line 181, column 34): ");
                                            };
                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 175, column 19 - line 181, column 34): ");
                                        };
                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 173, column 17 - line 181, column 34): ");
                                    };
                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 171, column 15 - line 181, column 34): ");
                                };
                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 169, column 25 - line 181, column 34): ");
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto either5() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& y) -> boxed {
                            if (unbox<dict_t>(y).contains("Left")) {
                                return a(y["value0"]);
                            };
                            if (unbox<dict_t>(y).contains("Right")) {
                                if (unbox<dict_t>(y["value0"]).contains("Left")) {
                                    return b(y["value0"]["value0"]);
                                };
                                if (unbox<dict_t>(y["value0"]).contains("Right")) {
                                    if (unbox<dict_t>(y["value0"]["value0"]).contains("Left")) {
                                        return c(y["value0"]["value0"]["value0"]);
                                    };
                                    if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Left")) {
                                            return d(y["value0"]["value0"]["value0"]["value0"]);
                                        };
                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                return e(y["value0"]["value0"]["value0"]["value0"]["value0"]);
                                            };
                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                return Data_Void::absurd()(y["value0"]["value0"]["value0"]["value0"]["value0"]);
                                            };
                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 164, column 21 - line 166, column 32): ");
                                        };
                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 162, column 19 - line 166, column 32): ");
                                    };
                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 160, column 17 - line 166, column 32): ");
                                };
                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 158, column 15 - line 166, column 32): ");
                            };
                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 156, column 23 - line 166, column 32): ");
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto either4() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& y) -> boxed {
                        if (unbox<dict_t>(y).contains("Left")) {
                            return a(y["value0"]);
                        };
                        if (unbox<dict_t>(y).contains("Right")) {
                            if (unbox<dict_t>(y["value0"]).contains("Left")) {
                                return b(y["value0"]["value0"]);
                            };
                            if (unbox<dict_t>(y["value0"]).contains("Right")) {
                                if (unbox<dict_t>(y["value0"]["value0"]).contains("Left")) {
                                    return c(y["value0"]["value0"]["value0"]);
                                };
                                if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Left")) {
                                        return d(y["value0"]["value0"]["value0"]["value0"]);
                                    };
                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                        return Data_Void::absurd()(y["value0"]["value0"]["value0"]["value0"]);
                                    };
                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 151, column 19 - line 153, column 30): ");
                                };
                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 149, column 17 - line 153, column 30): ");
                            };
                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 147, column 15 - line 153, column 30): ");
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 145, column 21 - line 153, column 30): ");
                    };
                };
            };
        };
    };
    return _;
};
auto either3() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& y) -> boxed {
                    if (unbox<dict_t>(y).contains("Left")) {
                        return a(y["value0"]);
                    };
                    if (unbox<dict_t>(y).contains("Right")) {
                        if (unbox<dict_t>(y["value0"]).contains("Left")) {
                            return b(y["value0"]["value0"]);
                        };
                        if (unbox<dict_t>(y["value0"]).contains("Right")) {
                            if (unbox<dict_t>(y["value0"]["value0"]).contains("Left")) {
                                return c(y["value0"]["value0"]["value0"]);
                            };
                            if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                                return Data_Void::absurd()(y["value0"]["value0"]["value0"]);
                            };
                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 140, column 17 - line 142, column 28): ");
                        };
                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 138, column 15 - line 142, column 28): ");
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 136, column 19 - line 142, column 28): ");
                };
            };
        };
    };
    return _;
};
auto either2() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Left")) {
                    return a(y["value0"]);
                };
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Left")) {
                        return b(y["value0"]["value0"]);
                    };
                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                        return Data_Void::absurd()(y["value0"]["value0"]);
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 131, column 15 - line 133, column 26): ");
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 129, column 17 - line 133, column 26): ");
            };
        };
    };
    return _;
};
auto either10() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return [=](const boxed& b) -> boxed {
            return [=](const boxed& c) -> boxed {
                return [=](const boxed& d) -> boxed {
                    return [=](const boxed& e) -> boxed {
                        return [=](const boxed& f) -> boxed {
                            return [=](const boxed& g) -> boxed {
                                return [=](const boxed& h) -> boxed {
                                    return [=](const boxed& i) -> boxed {
                                        return [=](const boxed& j) -> boxed {
                                            return [=](const boxed& y) -> boxed {
                                                if (unbox<dict_t>(y).contains("Left")) {
                                                    return a(y["value0"]);
                                                };
                                                if (unbox<dict_t>(y).contains("Right")) {
                                                    if (unbox<dict_t>(y["value0"]).contains("Left")) {
                                                        return b(y["value0"]["value0"]);
                                                    };
                                                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                                                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Left")) {
                                                            return c(y["value0"]["value0"]["value0"]);
                                                        };
                                                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Left")) {
                                                                return d(y["value0"]["value0"]["value0"]["value0"]);
                                                            };
                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                    return e(y["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                };
                                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                        return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                    };
                                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                            return g(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                        };
                                                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                                return h(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                            };
                                                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                                    return i(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                                };
                                                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                                                        return j(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                                    };
                                                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                                                        return Data_Void::absurd()(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                                                    };
                                                                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 259, column 31 - line 261, column 41): ");
                                                                                };
                                                                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 257, column 29 - line 261, column 41): ");
                                                                            };
                                                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 255, column 27 - line 261, column 41): ");
                                                                        };
                                                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 253, column 25 - line 261, column 41): ");
                                                                    };
                                                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 251, column 23 - line 261, column 41): ");
                                                                };
                                                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 249, column 21 - line 261, column 41): ");
                                                            };
                                                            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 247, column 19 - line 261, column 41): ");
                                                        };
                                                        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 245, column 17 - line 261, column 41): ");
                                                    };
                                                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 243, column 15 - line 261, column 41): ");
                                                };
                                                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 241, column 34 - line 261, column 41): ");
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return _;
};
auto either1() -> const boxed& {
    static const boxed _ = [](const boxed& y) -> boxed {
        if (unbox<dict_t>(y).contains("Left")) {
            return y["value0"];
        };
        if (unbox<dict_t>(y).contains("Right")) {
            return Data_Void::absurd()(y["value0"]);
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Either.Nested (line 124, column 13 - line 126, column 24): ");
    };
    return _;
};
auto at9() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                    return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                };
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
                return b;
            };
        };
    };
    return _;
};
auto at8() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
                return b;
            };
        };
    };
    return _;
};
auto at7() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                            return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
                return b;
            };
        };
    };
    return _;
};
auto at6() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                        return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                    };
                                };
                            };
                        };
                    };
                };
                return b;
            };
        };
    };
    return _;
};
auto at5() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                    return f(y["value0"]["value0"]["value0"]["value0"]["value0"]);
                                };
                            };
                        };
                    };
                };
                return b;
            };
        };
    };
    return _;
};
auto at4() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Left")) {
                                return f(y["value0"]["value0"]["value0"]["value0"]);
                            };
                        };
                    };
                };
                return b;
            };
        };
    };
    return _;
};
auto at3() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Left")) {
                            return f(y["value0"]["value0"]["value0"]);
                        };
                    };
                };
                return b;
            };
        };
    };
    return _;
};
auto at2() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Left")) {
                        return f(y["value0"]["value0"]);
                    };
                };
                return b;
            };
        };
    };
    return _;
};
auto at10() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Right")) {
                    if (unbox<dict_t>(y["value0"]).contains("Right")) {
                        if (unbox<dict_t>(y["value0"]["value0"]).contains("Right")) {
                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]).contains("Right")) {
                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                        if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                            if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Right")) {
                                                    if (unbox<dict_t>(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]).contains("Left")) {
                                                        return f(y["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]["value0"]);
                                                    };
                                                };
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
                return b;
            };
        };
    };
    return _;
};
auto at1() -> const boxed& {
    static const boxed _ = [](const boxed& b) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& y) -> boxed {
                if (unbox<dict_t>(y).contains("Left")) {
                    return f(y["value0"]);
                };
                return b;
            };
        };
    };
    return _;
};


} // end namespace Data_Either_Nested


