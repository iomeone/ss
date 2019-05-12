#include "Control_Applicative/Control_Applicative.h"
#include "Control_Bind/Control_Bind.h"
#include "Control_Monad_ST/Control_Monad_ST.h"
#include "Control_Monad_ST_Internal/Control_Monad_ST_Internal.h"
#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Data_Maybe/Data_Maybe.h"
#include "Data_Ord/Data_Ord.h"
#include "Data_Ordering/Data_Ordering.h"
#include "Data_Ring/Data_Ring.h"
#include "Prelude/Prelude.h"
#include "Unsafe_Coerce/Unsafe_Coerce.h"

#include "Data_Array_ST/Data_Array_ST.h"


namespace Data_Array_ST {

auto unsafeThaw() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(Control_Monad_ST_Internal::applicativeST()))(Unsafe_Coerce::unsafeCoerce());
};
auto unsafeFreeze() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Control_Applicative::pure()(Control_Monad_ST_Internal::applicativeST()))(Unsafe_Coerce::unsafeCoerce());
};
auto thaw() -> boxed {
    return Data_Array_ST::copyImpl();
};
auto withArray() -> const boxed& {
    static const boxed _ = [](const boxed& f) -> boxed {
        return [=](const boxed& xs) -> boxed {
            return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::thaw()(xs))([=](const boxed& v) -> boxed {
                return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(f(v))([=](const boxed& v1) -> boxed {
                    return Data_Array_ST::unsafeFreeze()(v);
                });
            });
        };
    };
    return _;
};
auto sortBy() -> const boxed& {
    static const boxed _ = [](const boxed& comp) -> boxed {
        boxed comp_Prime_ = [=](const boxed& x) -> boxed {
            return [=](const boxed& y) -> boxed {
                boxed v = comp(x)(y);
                if (unbox<dict_t>(v).contains("GT")) {
                    return 1;
                };
                if (unbox<dict_t>(v).contains("EQ")) {
                    return 0;
                };
                if (unbox<dict_t>(v).contains("LT")) {
                    return -1;
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.Array.ST (line 94, column 15 - line 99, column 1): ");
            };
        };
        return Data_Array_ST::sortByImpl()(comp_Prime_);
    };
    return _;
};
auto sortWith() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Array_ST::sortBy()(Data_Ord::comparing()(dictOrd)(f));
        };
    };
    return _;
};
auto sort() -> const boxed& {
    static const boxed _ = [](const boxed& dictOrd) -> boxed {
        return Data_Array_ST::sortBy()(Data_Ord::compare()(dictOrd));
    };
    return _;
};
auto run() -> const boxed& {
    static const boxed _ = [](const boxed& st) -> boxed {
        return Control_Monad_ST_Internal::run()(Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(st)(Data_Array_ST::unsafeFreeze()));
    };
    return _;
};
auto push() -> const boxed& {
    static const boxed _ = [](const boxed& a) -> boxed {
        return Data_Array_ST::pushAll()(array_t{ a });
    };
    return _;
};
auto _peek_() -> boxed {
    return Data_Array_ST::peekImpl()(Data_Maybe::Just())(Data_Maybe::Nothing());
};
auto modify() -> const boxed& {
    static const boxed _ = [](const boxed& i) -> boxed {
        return [=](const boxed& f) -> boxed {
            return [=](const boxed& xs) -> boxed {
                return Control_Bind::bind()(Control_Monad_ST_Internal::bindST())(Data_Array_ST::_peek_()(i)(xs))([=](const boxed& v) -> boxed {
                    if (unbox<dict_t>(v).contains("Just")) {
                        return Data_Array_ST::poke()(i)(f(v["value0"]))(xs);
                    };
                    if (unbox<dict_t>(v).contains("Nothing")) {
                        return Control_Applicative::pure()(Control_Monad_ST_Internal::applicativeST())(false);
                    };
                    THROW_("PatternMatchFailure: ""Failed pattern match at Data.Array.ST (line 156, column 3 - line 158, column 26): ");
                });
            };
        };
    };
    return _;
};
auto freeze() -> boxed {
    return Data_Array_ST::copyImpl();
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto empty() -> const boxed& { static const boxed _ = foreign().at("empty"); return _; };
auto sortByImpl() -> const boxed& { static const boxed _ = foreign().at("sortByImpl"); return _; };
auto copyImpl() -> const boxed& { static const boxed _ = foreign().at("copyImpl"); return _; };
auto peekImpl() -> const boxed& { static const boxed _ = foreign().at("peekImpl"); return _; };
auto poke() -> const boxed& { static const boxed _ = foreign().at("poke"); return _; };
auto pushAll() -> const boxed& { static const boxed _ = foreign().at("pushAll"); return _; };
auto splice() -> const boxed& { static const boxed _ = foreign().at("splice"); return _; };
auto toAssocArray() -> const boxed& { static const boxed _ = foreign().at("toAssocArray"); return _; };

} // end namespace Data_Array_ST


