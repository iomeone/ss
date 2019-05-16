#include <limits>
#include "purescript.h"

// Tested with package v4.0.0

void a()
{

}


FOREIGN_BEGIN( Data_Bounded )

exports["topInt"] = std::numeric_limits<int>::max();
exports["bottomInt"] = std::numeric_limits<int>::min();


exports["topChar"] = juce::String(CharPointer_UTF8("\xF4\x8F\xBF\xBF")); 
// unicode limit utf8 \xF4\x8F\xBF\xBF is the same as 0x10FFFF with unicode encoding. (Unicode use 4 bytes to encoding).

exports["bottomChar"] = juce::String(CharPointer_UTF8("\x00"));

//std::string tc()
//{
//	char t = ;
//	std::string s;
//	s.push_back(char(0x10FFFF));
//	return s;
//}
//
//exports["topChar"] = boxed{
//
//	
//};



exports["bottomChar"] = juce::String(wchar_t(0));

exports["topNumber"] = std::numeric_limits<double>::max();
exports["bottomNumber"] = std::numeric_limits<double>::min();

FOREIGN_END
