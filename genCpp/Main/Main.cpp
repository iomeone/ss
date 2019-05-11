#include "Effect_Console/Effect_Console.h"
#include "Prelude/Prelude.h"

#include "Main/Main.h"


namespace Main {

auto main() -> boxed {
    return Effect_Console::log()("World");
};


} // end namespace Main

int main(int argc, const char * argv[]) {
    Main::main()();
    return 0;
}

