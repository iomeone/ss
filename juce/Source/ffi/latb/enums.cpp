
#include <cassert>
#include <purescript.h>

FOREIGN_BEGIN( Data_Enum )

// foreign import toCharCode :: Char -> Int
exports["toCharCode"] = [](const boxed& c_) -> boxed {

	const juce::String& s = unbox<juce::String> (c_);
	int charcode =s[0];
	assert(s.length() == 1);
	return charcode;
};

FOREIGN_END
