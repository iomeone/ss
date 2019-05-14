#include "Data_Char_Unicode/Data_Char_Unicode.h"
#include "Data_Show/Data_Show.h"
#include "Effect/Effect.h"
#include "Effect_Console/Effect_Console.h"
#include "Prelude/Prelude.h"

#include "Main/Main.h"


namespace Main {

auto main() -> boxed {
    return Effect_Console::logShow()(Data_Show::showBoolean())(Data_Char_Unicode::isDigit()("2"));
};


} // end namespace Main

int main(int argc, const char * argv[]) {
    Main::main()();
    return 0;
}

