#include "Data_Symbol/Data_Symbol.h"
#include "Record_Unsafe/Record_Unsafe.h"
#include "Type_Data_RowList/Type_Data_RowList.h"

#include "Data_Show/Data_Show.h"


namespace Data_Show {

auto ShowRecordFields() -> const boxed& {
    static const boxed _ = [](const boxed& showRecordFields) -> boxed {
        return dict_t{
            { "showRecordFields", showRecordFields }
        };
    };
    return _;
};
auto Show() -> const boxed& {
    static const boxed _ = [](const boxed& show) -> boxed {
        return dict_t{
            { "show", show }
        };
    };
    return _;
};
auto showString() -> boxed {
    return Data_Show::Show()(Data_Show::showStringImpl());
};
auto showRecordFieldsNil() -> boxed {
    return Data_Show::ShowRecordFields()([=](const boxed& v) -> boxed {
        return [=](const boxed& v1) -> boxed {
            return array_t{  };
        };
    });
};
auto showRecordFields() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["showRecordFields"];
    };
    return _;
};
auto showRecord() -> const boxed& {
    static const boxed _ = [](const boxed& dictRowToList) -> boxed {
        return [=](const boxed& dictShowRecordFields) -> boxed {
            return Data_Show::Show()([=](const boxed& record) -> boxed {
                boxed v = Data_Show::showRecordFields()(dictShowRecordFields)(Type_Data_RowList::RLProxy())(record);
                if (unbox<int>(array_length(v)) == 0) {
                    return "{}";
                };
                return Data_Show::join()(" ")(array_t{ "{", Data_Show::join()(", ")(v), "}" });
            });
        };
    };
    return _;
};
auto showNumber() -> boxed {
    return Data_Show::Show()(Data_Show::showNumberImpl());
};
auto showInt() -> boxed {
    return Data_Show::Show()(Data_Show::showIntImpl());
};
auto showChar() -> boxed {
    return Data_Show::Show()(Data_Show::showCharImpl());
};
auto showBoolean() -> boxed {
    return Data_Show::Show()([=](const boxed& v) -> boxed {
        if (unbox<bool>(v)) {
            return "true";
        };
        if (!(unbox<bool>(v))) {
            return "false";
        };
        THROW_("PatternMatchFailure: ""Failed pattern match at Data.Show (line 20, column 1 - line 20, column 37): ");
    });
};
auto show() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["show"];
    };
    return _;
};
auto showArray() -> const boxed& {
    static const boxed _ = [](const boxed& dictShow) -> boxed {
        return Data_Show::Show()(Data_Show::showArrayImpl()(Data_Show::show()(dictShow)));
    };
    return _;
};
auto showRecordFieldsCons() -> const boxed& {
    static const boxed _ = [](const boxed& dictIsSymbol) -> boxed {
        return [=](const boxed& dictShowRecordFields) -> boxed {
            return [=](const boxed& dictShow) -> boxed {
                return Data_Show::ShowRecordFields()([=](const boxed& v) -> boxed {
                    return [=](const boxed& record) -> boxed {
                        boxed tail = Data_Show::showRecordFields()(dictShowRecordFields)(Type_Data_RowList::RLProxy())(record);
                        boxed key = Data_Symbol::reflectSymbol()(dictIsSymbol)(Data_Symbol::SProxy());
                        boxed focus = Record_Unsafe::unsafeGet()(key)(record);
                        return Data_Show::cons()(Data_Show::join()(": ")(array_t{ key, Data_Show::show()(dictShow)(focus) }))(tail);
                    };
                });
            };
        };
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto showIntImpl() -> const boxed& { static const boxed _ = foreign().at("showIntImpl"); return _; };
auto showNumberImpl() -> const boxed& { static const boxed _ = foreign().at("showNumberImpl"); return _; };
auto showCharImpl() -> const boxed& { static const boxed _ = foreign().at("showCharImpl"); return _; };
auto showStringImpl() -> const boxed& { static const boxed _ = foreign().at("showStringImpl"); return _; };
auto showArrayImpl() -> const boxed& { static const boxed _ = foreign().at("showArrayImpl"); return _; };
auto cons() -> const boxed& { static const boxed _ = foreign().at("cons"); return _; };
auto join() -> const boxed& { static const boxed _ = foreign().at("join"); return _; };

} // end namespace Data_Show


