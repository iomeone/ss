#include "Data_List/Data_List.h"
#include "Data_List_Types/Data_List_Types.h"

#include "Data_List_Partial/Data_List_Partial.h"


namespace Data_List_Partial {

auto tail() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Cons")) {
                return v["value1"];
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Partial (line 15, column 1 - line 15, column 46): ");
        };
    };
    return _;
};
auto last() -> const boxed& {
    static const boxed _ = [](const boxed& _TCO_Copy_dictPartial_) -> boxed {
        return [=](const boxed& _TCO_Copy_v_) -> boxed {
            boxed _TCO_dictPartial_;
            _TCO_dictPartial_ = _TCO_Copy_dictPartial_;
            boxed _TCO_v_;
            _TCO_v_ = _TCO_Copy_v_;
            bool _TCO_Done_ = false;
            boxed _TCO_Result_;
            const auto _TCO_Loop_ = [&](const boxed dictPartial, const boxed v) -> boxed {
                if (unbox<dict_t>(v).contains("Cons")) {
                    if (unbox<dict_t>(v["value1"]).contains("Nil")) {
                        _TCO_Done_ = true;
                        return v["value0"];
                    };
                };
                if (unbox<dict_t>(v).contains("Cons")) {
                    _TCO_dictPartial_ = dictPartial;
                    _TCO_v_ = v["value1"];
                    return undefined;
                };
                THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Partial (line 21, column 1 - line 21, column 41): ");
            };
            while (!(_TCO_Done_)) {
                _TCO_Result_ = _TCO_Loop_(_TCO_dictPartial_, _TCO_v_);
            };
            return _TCO_Result_;
        };
    };
    return _;
};
auto init() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Cons")) {
                if (unbox<dict_t>(v["value1"]).contains("Nil")) {
                    return Data_List_Types::Nil();
                };
            };
            if (unbox<dict_t>(v).contains("Cons")) {
                return Data_List_Types::Cons()(v["value0"])(Data_List_Partial::init()(dictPartial)(v["value1"]));
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Partial (line 28, column 1 - line 28, column 46): ");
        };
    };
    return _;
};
auto head() -> const boxed& {
    static const boxed _ = [](const boxed& dictPartial) -> boxed {
        return [=](const boxed& v) -> boxed {
            if (unbox<dict_t>(v).contains("Cons")) {
                return v["value0"];
            };
            THROW_("PatternMatchFailure: ""Failed pattern match at Data.List.Partial (line 9, column 1 - line 9, column 41): ");
        };
    };
    return _;
};


} // end namespace Data_List_Partial


