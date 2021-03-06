// Generated by pscpp compiler

#ifndef Data_List_Lazy_NonEmpty_H
#define Data_List_Lazy_NonEmpty_H

#include "purescript.h"

namespace Data_List_Lazy_NonEmpty {

using namespace purescript;

auto uncons() -> const boxed&;
auto toList() -> const boxed&;
auto toUnfoldable() -> const boxed&;
auto tail() -> const boxed&;
auto singleton() -> boxed;
auto repeat() -> const boxed&;
auto length() -> const boxed&;
auto last() -> const boxed&;
auto iterate() -> const boxed&;
auto init() -> const boxed&;
auto head() -> const boxed&;
auto fromList() -> const boxed&;
auto fromFoldable() -> const boxed&;
auto concatMap() -> boxed;
auto appendFoldable() -> const boxed&;

} // end namespace Data_List_Lazy_NonEmpty

#endif // Data_List_Lazy_NonEmpty_H

