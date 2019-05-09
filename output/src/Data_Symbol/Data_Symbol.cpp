
#include "Data_Symbol/Data_Symbol.h"


namespace Data_Symbol {

auto SProxy() -> const boxed& {
    static const boxed _ = dict_t{
        { "SProxy", true }
    };
    return _;
};
auto IsSymbol() -> const boxed& {
    static const boxed _ = [](const boxed& reflectSymbol) -> boxed {
        return dict_t{
            { "reflectSymbol", reflectSymbol }
        };
    };
    return _;
};
auto reifySymbol() -> const boxed& {
    static const boxed _ = [](const boxed& s) -> boxed {
        return [=](const boxed& f) -> boxed {
            return Data_Symbol::unsafeCoerce()([=](const boxed& dictIsSymbol) -> boxed {
                return f(dictIsSymbol);
            })(dict_t{
                { "reflectSymbol", [=](const boxed& v) -> boxed {
                    return s;
                } }
            })(Data_Symbol::SProxy());
        };
    };
    return _;
};
auto reflectSymbol() -> const boxed& {
    static const boxed _ = [](const boxed& dict) -> boxed {
        return dict["reflectSymbol"];
    };
    return _;
};


// Foreign values

DEFINE_FOREIGN_DICTIONARY_AND_ACCESSOR()

auto unsafeCoerce() -> const boxed& { static const boxed _ = foreign().at("unsafeCoerce"); return _; };

} // end namespace Data_Symbol


