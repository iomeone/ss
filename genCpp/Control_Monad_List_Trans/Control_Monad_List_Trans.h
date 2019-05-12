// Generated by pscpp compiler

#ifndef Control_Monad_List_Trans_H
#define Control_Monad_List_Trans_H

#include "purescript.h"

namespace Control_Monad_List_Trans {

using namespace purescript;

auto Yield() -> const boxed&;
auto Skip() -> const boxed&;
auto Done() -> const boxed&;
auto ListT() -> const boxed&;
auto wrapLazy() -> const boxed&;
auto wrapEffect() -> const boxed&;
auto unfold() -> const boxed&;
auto uncons() -> const boxed&;
auto tail() -> const boxed&;
auto stepMap() -> const boxed&;
auto takeWhile() -> const boxed&;
auto scanl() -> const boxed&;
auto prepend_Prime_() -> const boxed&;
auto prepend() -> const boxed&;
auto nil() -> const boxed&;
auto singleton() -> const boxed&;
auto take() -> const boxed&;
auto zipWith_Prime_() -> const boxed&;
auto zipWith() -> const boxed&;
auto newtypeListT() -> boxed;
auto mapMaybe() -> const boxed&;
auto iterate() -> const boxed&;
auto repeat() -> const boxed&;
auto head() -> const boxed&;
auto functorListT() -> const boxed&;
auto fromEffect() -> const boxed&;
auto monadTransListT() -> boxed;
auto foldlRec_Prime_() -> const boxed&;
auto runListTRec() -> const boxed&;
auto foldlRec() -> const boxed&;
auto foldl_Prime_() -> const boxed&;
auto runListT() -> const boxed&;
auto foldl() -> const boxed&;
auto filter() -> const boxed&;
auto dropWhile() -> const boxed&;
auto drop() -> const boxed&;
auto cons() -> const boxed&;
auto unfoldable1ListT() -> const boxed&;
auto unfoldableListT() -> const boxed&;
auto semigroupListT() -> const boxed&;
auto concat() -> const boxed&;
auto monoidListT() -> const boxed&;
auto catMaybes() -> const boxed&;
auto monadListT() -> const boxed&;
auto bindListT() -> const boxed&;
auto applyListT() -> const boxed&;
auto applicativeListT() -> const boxed&;
auto monadEffectListT() -> const boxed&;
auto altListT() -> const boxed&;
auto plusListT() -> const boxed&;
auto alternativeListT() -> const boxed&;
auto monadZeroListT() -> const boxed&;
auto monadPlusListT() -> const boxed&;

} // end namespace Control_Monad_List_Trans

#endif // Control_Monad_List_Trans_H
