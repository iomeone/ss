psc-package init

psc-package updates

psc-package install

purs compile --codegen corefn --output output 

pscpp --makefile

mingw32-make debug




-- List all (active) source paths for dependencies
psc-package sources

PS D:\dev\pcc\src> psc-package sources
.psc-package\psc-0.12.3\prelude\v4.1.0\src\**\*.purs


https://pursuit.purescript.org/


gen corefun and c++ source command is:
purs compile --codegen corefn --output output .psc-package/psc-0.12.3/console/v4.2.0/src/Effect/Console.purs .psc-package/psc-0.12.3/console/v4.2.0/src/Effect/Class/Console.purs .psc-package/psc-0.12.3/effect/v2.0.1/src/Effect.purs .psc-package/psc-0.12.3/effect/v2.0.1/src/Effect/Unsafe.purs .psc-package/psc-0.12.3/effect/v2.0.1/src/Effect/Uncurried.purs .psc-package/psc-0.12.3/effect/v2.0.1/src/Effect/Class.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Prelude.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Control/Apply.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Control/Applicative.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Control/Category.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Control/Bind.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Control/Semigroupoid.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Control/Monad.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Record/Unsafe.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Type/Data/Row.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Type/Data/RowList.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/CommutativeRing.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Ring.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Void.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Semiring.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/BooleanAlgebra.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Eq.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Bounded.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Show.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Functor.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Function.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/NaturalTransformation.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Symbol.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/HeytingAlgebra.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/DivisionRing.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Unit.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Monoid.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Boolean.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Semigroup.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/EuclideanRing.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Ord.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Field.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Ordering.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Ord/Unsafe.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Semigroup/Last.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Semigroup/First.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Monoid/Conj.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Monoid/Endo.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Monoid/Disj.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Monoid/Additive.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Monoid/Multiplicative.purs .psc-package/psc-0.12.3/prelude/v4.1.0/src/Data/Monoid/Dual.purs src/Main.purs


pscpp --ucns output/Control.Monad/corefn.json output/Data.EuclideanRing/corefn.json output/Data.Semigroup.Last/corefn.json output/Data.Unit/corefn.json output/Data.DivisionRing/corefn.json output/Main/corefn.json output/Data.Functor/corefn.json output/Data.Symbol/corefn.json output/Data.Ordering/corefn.json output/Data.Semiring/corefn.json output/Data.Semigroup.First/corefn.json output/Data.Void/corefn.json output/Data.Monoid.Endo/corefn.json output/Effect.Console/corefn.json output/Data.BooleanAlgebra/corefn.json output/Data.Monoid.Disj/corefn.json output/Effect.Class.Console/corefn.json output/Control.Bind/corefn.json output/Data.Monoid.Additive/corefn.json output/Effect.Class/corefn.json output/Prelude/corefn.json output/Control.Apply/corefn.json output/Type.Data.Row/corefn.json output/Data.Eq/corefn.json output/Data.HeytingAlgebra/corefn.json output/Record.Unsafe/corefn.json output/Control.Applicative/corefn.json output/Data.Ord/corefn.json output/Data.Field/corefn.json output/Data.Monoid.Dual/corefn.json output/Effect/corefn.json output/Data.Function/corefn.json output/Data.CommutativeRing/corefn.json output/Data.Ord.Unsafe/corefn.json output/Effect.Uncurried/corefn.json output/Data.Bounded/corefn.json output/Data.NaturalTransformation/corefn.json output/Data.Monoid.Multiplicative/corefn.json output/Data.Ring/corefn.json output/Control.Semigroupoid/corefn.json output/Effect.Unsafe/corefn.json output/Data.Show/corefn.json output/Data.Monoid.Conj/corefn.json output/Control.Category/corefn.json output/Data.Boolean/corefn.json output/Data.Semigroup/corefn.json output/Data.Monoid/corefn.json output/Type.Data.RowList/corefn.json
pause


output file ->$(IntDir)/%(RelativeDir)/


juce 's projucer  compiler flags
1,vs include 
/I"./../../glm" /wd"4201"
2,mac os include 
-I../../glm

juce's projucer link flags 
1,vs
/subsystem:console /entry:mainCRTStartup
