module Main where

import Prelude
import Effect.Console (log)





main = do
  log $ show (factorial 3)
  log  "this is awsome!"



factorial :: Int->Int
factorial 0 = 1
factorial n = n * factorial (n-1)