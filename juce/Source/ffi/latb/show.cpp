#include "purescript.h"
#include <string>         // std::string, std::u32string
#include <locale>         // std::wstring_convert
#include <codecvt>        // std::codecvt_utf8
#include <cstdint>        // std::uint_least32_t
#include <sstream>

FOREIGN_BEGIN( Data_Show )

exports["showCharImpl"] = [](const boxed& c_) -> boxed {
	juce::String jc = unbox<juce::String> (c_);
    std::string c =  "\'";
    c += unbox<char>(c_);
    c += "\'";
    /* if (c < 128) { */
    /*   s.push_back(c); */
    /* } else { */
    /*   static std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf32conv; */
    /*   s += utf32conv.to_bytes(c); */
    /* } */
    /* s.push_back('\''); */
    return jc;
};
 //foreign import cons :: forall a. a -> Array a -> Array a
 //duplicate to Data.Array.cons
exports["cons"] = [](const boxed& e_) -> boxed {
  return [=](const boxed& xs_) -> boxed {
    array_t xs = unbox<array_t>(xs_);
    array_t result(xs);
    result.emplace(result.begin(), e_ );
    return result;
  };
};

/* FOREIGN_END */
/* FOREIGN_BEGIN( Test_Main ) */

exports["join"] = [](const boxed& separator_) -> boxed {
  const juce::String& separator = unbox<juce::String>(separator_);
  return [=](const boxed& xs_) -> boxed {
    array_t xs = unbox<array_t>(xs_);
    const auto length = xs.size();
	juce::String result;
    auto it = xs.cbegin();
    result += unbox<juce::String>(*it++);
    for (; it != xs.cend(); it++) {
      result += separator;
      result += unbox<juce::String>(*it);
    }
    return result;
  };
};

FOREIGN_END
