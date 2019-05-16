
#include <cassert>
#include <purescript.h>

FOREIGN_BEGIN( Data_Enum )

// foreign import toCharCode :: Char -> Int
exports["toCharCode"] = [](const boxed& c_) -> boxed {

	const juce::String& s = unbox<juce::String> (c_);
	int charcode =s[0];
	//assert(s.length() == 1);
	return charcode;
	//const int   i = unbox<int>(c_);
	//if (i > 0x0010ffff || i < 0)
	//{
	//
	//	const juce::String  s = unbox<juce::String>(c_);
	//}
	//
 //
 // return i;
};

FOREIGN_END
