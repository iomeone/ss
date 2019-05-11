#include "Control_Bind/Control_Bind.h"
#include "Data_Function/Data_Function.h"
#include "Data_Ring/Data_Ring.h"
#include "Data_Semiring/Data_Semiring.h"
#include "Data_Show/Data_Show.h"
#include "Effect/Effect.h"
#include "Effect_Console/Effect_Console.h"
#include "Prelude/Prelude.h"

#include "Main/Main.h"


namespace Main {

auto factorial() -> const boxed& {
    static const boxed _ = [](const boxed& v) -> boxed {
        if (unbox<int>(v) == 0) {
            return 1;
        };
        return unbox<int>(v) * unbox<int>(Main::factorial()(unbox<int>(v) - 1));
    };
    return _;
};
auto main() -> const boxed& {
    static const boxed _ = []() -> boxed {
        Effect_Console::log()(Data_Show::show()(Data_Show::showInt())(Main::factorial()(3)))();
        return Effect_Console::log()("this is awsome!")();
    };
    return _;
};


} // end namespace Main

int main(int argc, const char * argv[]) {
    Main::main()();
    return 0;
}

