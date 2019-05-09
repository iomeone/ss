#include "Data_Eq/Data_Eq.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Data_Show/Data_Show.h"

#include "Data_Ordering/Data_Ordering.h"


namespace Data_Ordering {

auto LT() -> const boxed& {
    static const boxed _ = dict_t{
        { "LT", true }
    };
    return _;
};
auto GT() -> const boxed& {
    static const boxed _ = dict_t{
        { "GT", true }
    };
    return _;
};
auto EQ() -> const boxed& {
    static const boxed _ = dict_t{
        { "EQ", true }
    };
    return _;
};
auto showOrdering() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("LT")) {
            return "LT";
        };
        if (unbox<dict_t>(v).contains("GT")) {
            return "GT";
        };
        if (unbox<dict_t>(v).contains("EQ")) {
            return "EQ";
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Ordering (line 26, column 1 - line 26, column 39): ");
    });
};
auto semigroupOrdering() -> boxed {
    return Data_Semigroup::Semigroup()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("LT")) {
                return Data_Ordering::LT();
            };
            if (unbox<dict_t>(v).contains("GT")) {
                return Data_Ordering::GT();
            };
            if (unbox<dict_t>(v).contains("EQ")) {
                return v1;
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.Ordering (line 21, column 1 - line 21, column 49): ");
        };
    });
};
auto invert() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<dict_t>(v).contains("GT")) {
            return Data_Ordering::LT();
        };
        if (unbox<dict_t>(v).contains("EQ")) {
            return Data_Ordering::EQ();
        };
        if (unbox<dict_t>(v).contains("LT")) {
            return Data_Ordering::GT();
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Ordering (line 33, column 1 - line 33, column 31): ");
    };
    return _;
};
auto eqOrdering() -> boxed {
    return Data_Eq::Eq()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            if (unbox<dict_t>(v).contains("LT")) {
                if (unbox<dict_t>(v1).contains("LT")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("GT")) {
                if (unbox<dict_t>(v1).contains("GT")) {
                    return true;
                };
            };
            if (unbox<dict_t>(v).contains("EQ")) {
                if (unbox<dict_t>(v1).contains("EQ")) {
                    return true;
                };
            };
            return false;
        };
    });
};


} // end namespace Data_Ordering


