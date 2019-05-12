module Main where


import Effect.Console (log)
import Prelude hiding (between,when)

import Control.Alt ((<|>))
import Control.Lazy (fix)
import Data.Array (some)
import Data.Either (Either(..))
import Data.List (List(..), fromFoldable, many)
import Data.Maybe (Maybe(..))
import Data.String.CodeUnits (fromCharArray, singleton)
import Data.Tuple (Tuple(..))
import Effect (Effect)
import Effect.Console (logShow)

import Text.Parsing.Parser (Parser, ParserT, runParser, parseErrorPosition)
import Text.Parsing.Parser.Combinators (endBy1, sepBy1, optionMaybe, try, chainl, between)
import Text.Parsing.Parser.Expr (Assoc(..), Operator(..), buildExprParser)
import Text.Parsing.Parser.Language (javaStyle, haskellStyle, haskellDef)
import Text.Parsing.Parser.Pos (Position(..), initialPos)
import Text.Parsing.Parser.String (eof, string, char, satisfy, anyChar)
import Text.Parsing.Parser.Token (TokenParser, match, when, token, makeTokenParser)



parens :: forall m a. Monad m => ParserT String m a -> ParserT String m a
parens = between (string "(") (string ")")


s1 = string "1"

parseTest :: forall s a. Show a => Eq a => s  -> Parser s a -> Effect Unit
parseTest input p = case runParser input p of
  Right actual -> do
    logShow $ "parser result is" <> show actual
  Left err -> logShow ("error: " <> show err) 



main = do
--  log $ show (factorial 3)
  log  "parser parens:"


  parseTest "1(haha)" s1 



factorial :: Int->Int
factorial 0 = 1
factorial n = n * factorial (n-1)