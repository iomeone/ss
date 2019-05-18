module Main where


import Effect.Console (log)
import Prelude hiding (between,when)

import Control.Alt ((<|>))
import Control.Lazy (fix)
import Data.Array (some, fromFoldable)
import Data.Char.Unicode (digitToInt, isAscii, isLetter)
import Data.Either (Either(..))
-- import Data.List (List(..), fromFoldable, many)
import Data.List (List(..), many)
import Data.Maybe (Maybe(..))
import Data.String.CodeUnits (fromCharArray, singleton)
import Data.Tuple (Tuple(..))
import Effect (Effect)
import Effect.Console (logShow)

import Text.Parsing.Parser (Parser, fail, ParserT, runParser, parseErrorPosition)
import Text.Parsing.Parser.Combinators (endBy1, sepBy1, optionMaybe, try, chainl, between)
import Text.Parsing.Parser.Expr (Assoc(..), Operator(..), buildExprParser)
import Text.Parsing.Parser.Language (javaStyle, haskellStyle, haskellDef)
import Text.Parsing.Parser.Pos (Position(..), initialPos)
import Text.Parsing.Parser.String (eof, string, char, satisfy, anyChar)
import Text.Parsing.Parser.Token (TokenParser, match, when, token, makeTokenParser, digit)



notFollowedBy :: forall a. Parser String a -> Parser String Unit
notFollowedBy p = try $ (try p *> fail "Negated parser succeeded") <|> pure unit








data Kill
  = Kill String String 

instance showKill :: Show Kill where
  show (Kill a b) = "name : " <> a <> " uid : " <> b 

-- parens :: forall m a. Monad m => ParserT String m a -> ParserT String m a
-- parens = between (string "(") (string ")")

-- we could also write as this.
parens :: forall a. Parser String  a -> Parser String  a
parens = between (string "(") (string ")")


parseNameNum :: Parser String  Kill
parseNameNum = do

  name <- parens (fromCharArray <$> (some $ satisfy (isLetter)))                --    name <- parens (fromCharArray <$> (some $anyChar))
  
  d <- fromCharArray <$> some digit

  pure ( Kill name d )







s1 = string "1"

opTest :: Parser String String
opTest = chainl (singleton <$> anyChar) (char '+' $> append) ""


parseTest :: forall s a. Show a =>  s  -> Parser s a -> Effect Unit
parseTest input p = case runParser input p of
  Right actual -> do
    log $ "Parser result is: " <> show actual
  Left err -> logShow ("error: " <> show err) 



main :: Effect Unit
main = do
  log $ show $ fromFoldable (Just 1)
--  log  "Parser In Cpp:"
--  parseTest "(zhuzhao)1212438" parseNameNum




--  parseTest "a+b+c" opTest 


factorial :: Int->Int
factorial 0 = 1
factorial n = n * factorial (n-1)