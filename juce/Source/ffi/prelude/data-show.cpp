#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Data_Show )

exports["showIntImpl"] = [](const boxed& n) -> boxed {
    return std::to_string(unbox<int>(n));
};

exports["showNumberImpl"] = [](const boxed& n) -> boxed {
    return std::to_string(unbox<double>(n));
};

exports["showStringImpl"] = [](const boxed& s) -> boxed {
    return "\"" + unbox<juce::String>(s) + "\"";
};

exports["showArrayImpl"] = [](const boxed& f) -> boxed {
    return [=](const boxed& xs_) -> boxed {
    const auto& xs = unbox<array_t>(xs_);
	juce::String s("[");
    auto count = xs.size();
    for (auto it = xs.cbegin(), end = xs.cend(); it != end; it++) {
        s += unbox<juce::String>(f(*it));
        if (--count > 0) {
          s += ',';
        }
    }
    s += ']';
    return s;
    };
};

FOREIGN_END
