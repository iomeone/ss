module Main where


import Prelude hiding (between,when)
import Data.Char.Unicode (digitToInt, isDigit)
import Effect (Effect)
import Effect.Console (logShow)

main :: Effect Unit
main = do
  logShow (isDigit '4')
