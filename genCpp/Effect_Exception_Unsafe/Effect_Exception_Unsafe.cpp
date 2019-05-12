#include "Control_Semigroupoid/Control_Semigroupoid.h"
#include "Effect_Exception/Effect_Exception.h"
#include "Effect_Unsafe/Effect_Unsafe.h"

#include "Effect_Exception_Unsafe/Effect_Exception_Unsafe.h"


namespace Effect_Exception_Unsafe {

auto unsafeThrowException() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Unsafe::unsafePerformEffect())(Effect_Exception::throwException());
};
auto unsafeThrow() -> boxed {
    return Control_Semigroupoid::compose()(Control_Semigroupoid::semigroupoidFn())(Effect_Exception_Unsafe::unsafeThrowException())(Effect_Exception::error());
};


} // end namespace Effect_Exception_Unsafe


