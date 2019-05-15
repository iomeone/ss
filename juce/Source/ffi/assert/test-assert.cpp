#include "purescript.h"

// Tested with package v4.0.0

FOREIGN_BEGIN( Test_Assert )

exports["assert'"] = [](const boxed& message) -> boxed {
    return [=](const boxed& success_) -> boxed {
        const auto success = unbox<bool>(success_);
        return [=]() -> boxed {
			juce::String str = unbox<juce::String>(message);
            if (!success) throw std::runtime_error(str.toStdString());
            return boxed();
        };
    };
};

FOREIGN_END
