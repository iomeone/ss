#include "Data_Char_Unicode/Data_Char_Unicode.h"
#include "Data_Show/Data_Show.h"
#include "Effect/Effect.h"
#include "Effect_Console/Effect_Console.h"
#include "Prelude/Prelude.h"

#include "Main/Main.h"

#pragma execution_character_set("UTF-8")
//#define JUCE_NATIVE_WCHAR_IS_UTF8 1
//#undef JUCE_NATIVE_WCHAR_IS_UTF16

#include "../JuceLibraryCode/JuceHeader.h"

#include <iostream>
using namespace std;


namespace Main {

auto main() -> boxed {
    return Effect_Console::logShow()(Data_Show::showBoolean())(Data_Char_Unicode::isDigit()("2"));
};


} // end namespace Main

int main(int argc, const char * argv[]) {
    Main::main()();
	//juce::String s = CharPointer_UTF8("\xe4\xbd\xa0\xe6\x98\xaf\xe8\xb0\x81\xf0\x9d\x85\xa2");

	juce::String s = CharPointer_UTF8("中文可以一个一个输出啦 繁體字也一個個輸出");
	wcout.imbue(locale("", LC_CTYPE));

	for(int i = 0 ; i < s.length(); i++)
	{
		wcout << wchar_t(s[i]);
		cout << " int value is: " << hex << s[i] << endl;
	}
	
	//printf("%x\n", (int)ni);


	//std::cout << s.length() << endl;

    return 0;
}

