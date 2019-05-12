#include "Data_Eq/Data_Eq.h"
#include "Data_EuclideanRing/Data_EuclideanRing.h"
#include "Data_Foldable/Data_Foldable.h"
#include "Data_HeytingAlgebra/Data_HeytingAlgebra.h"
#include "Data_Newtype/Data_Newtype.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Data_String/Data_String.h"
#include "Data_String_Common/Data_String_Common.h"
#include "Data_String_Pattern/Data_String_Pattern.h"
#include "Prelude/Prelude.h"

#include "Text_Parsing_Parser_Pos/Text_Parsing_Parser_Pos.h"


namespace Text_Parsing_Parser_Pos {

auto Position() -> const boxed& {
    static const boxed _ = [](const boxed& x) -> boxed {
        return x;
    };
    return _;
};
auto updatePosString() -> const boxed& {
    static const boxed _ = [](const boxed& pos_Prime_) -> boxed {
        return [=](const boxed& str) -> boxed {
            boxed updatePosChar = [=](const boxed& v) -> boxed {
                return [=](const boxed& c) -> boxed {
                    if (unbox<string>(c) == "\n") {
                        return dict_t{
                            { "line", unbox<int>(v["line"]) + 1 },
                            { "column", 1 }
                        };
                    };
                    if (unbox<string>(c) == "\r") {
                        return dict_t{
                            { "line", unbox<int>(v["line"]) + 1 },
                            { "column", 1 }
                        };
                    };
                    if (unbox<string>(c) == "\t") {
                        return dict_t{
                            { "line", v["line"] },
                            { "column", unbox<int>(unbox<int>(v["column"]) + 8) - unbox<int>(Data_EuclideanRing::mod()(Data_EuclideanRing::euclideanRingInt())(unbox<int>(v["column"]) - 1)(8)) }
                        };
                    };
                    return dict_t{
                        { "line", v["line"] },
                        { "column", unbox<int>(v["column"]) + 1 }
                    };
                };
            };
            return Data_Foldable::foldl()(Data_Foldable::foldableArray())(updatePosChar)(pos_Prime_)(Data_String_Common::split()(Data_Newtype::wrap()(Data_String_Pattern::newtypePattern())(""))(str));
        };
    };
    return _;
};
auto showPosition() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        return Data_Semigroup::append()(Data_Semigroup::semigroupString())("(Position { line: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v["line"]))(Data_Semigroup::append()(Data_Semigroup::semigroupString())(", column: ")(Data_Semigroup::append()(Data_Semigroup::semigroupString())(Data_Show::show()(Data_Show::showInt())(v["column"]))(" })"))));
    });
};
auto initialPos() -> const boxed& {
    static const boxed _ = dict_t{
        { "line", 1 },
        { "column", 1 }
    };
    return _;
};
auto eqPosition() -> boxed {
    return Data_Eq::Eq()([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            return unbox<bool>(unbox<int>(x["column"]) == unbox<int>(y["column"])) && unbox<bool>(unbox<int>(x["line"]) == unbox<int>(y["line"]));
        };
    });
};
auto ordPosition() -> boxed {
    return Data_Ord::Ord()([=](const boxed&) -> boxed {
        return Text_Parsing_Parser_Pos::eqPosition();
    })([=](const boxed& x) -> boxed {
        return [=](const boxed& y) -> boxed {
            boxed v = Data_Ord::compare()(Data_Ord::ordInt())(x["column"])(y["column"]);
            if (unbox<dict_t>(v).contains("LT")) {
                return Data_Ordering::LT();
            };
            if (unbox<dict_t>(v).contains("GT")) {
                return Data_Ordering::GT();
            };
            return Data_Ord::compare()(Data_Ord::ordInt())(x["line"])(y["line"]);
        };
    });
};


} // end namespace Text_Parsing_Parser_Pos


