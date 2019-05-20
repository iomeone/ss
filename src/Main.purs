module Main where


import Effect.Console (log)
import Prelude hiding (between,when)

import Control.Alt ((<|>))
import Control.Lazy (fix)
import Data.Array (some, fromFoldable, many, toUnfoldable)
import Data.Char.Unicode (digitToInt, isAscii, isLetter)
import Data.Either (Either(..))
-- import Data.List (List(..), fromFoldable, many)
import Data.List (List(..), fromFoldable) 
import Data.List as L
import Data.Maybe (Maybe(..))
import Data.String.CodeUnits (fromCharArray, singleton)
import Data.Tuple (Tuple(..))
import Effect (Effect)
import Effect.Console (logShow)

import Text.Parsing.Parser (ParseError, Parser, fail, ParserT, runParser, parseErrorPosition)
import Text.Parsing.Parser.Combinators (sepEndBy, notFollowedBy, endBy1, sepBy1, optionMaybe, try, chainl, between)
import Text.Parsing.Parser.Expr (Assoc(..), Operator(..), buildExprParser)
import Text.Parsing.Parser.Language (javaStyle, haskellStyle, haskellDef)
import Text.Parsing.Parser.Pos (Position(..), initialPos)
import Text.Parsing.Parser.String (eof, string, char, satisfy, anyChar, noneOf, skipSpaces)
import Text.Parsing.Parser.Token (TokenParser, match, when, token, makeTokenParser, digit, alphaNum)


data Attribute = Attribute String String

instance eqAttribute :: Eq Attribute where
  eq (Attribute k1 v1) (Attribute k2 v2) = k1 == k2 && v1 == v2

instance showAttribute :: Show Attribute where
  show (Attribute k v) = "Attribute " <> show k <> " " <> show v


data HTML
  = Element String (List Attribute) (List HTML)
  | VoidElement String (List Attribute)
  | TextNode String
  | CommentNode String

instance showHTML :: Show HTML where
  show (Element name attrs children) =
    "Element " <> show name <> " (" <> show attrs <> ") (" <> show children <> ")"
  show (VoidElement name attrs) =
    "VoidElement " <> show name <> " (" <> show attrs <> ")"
  show (TextNode text) = "TextNode " <> show text
  show (CommentNode text) = "CommentNode " <> show text

parseTagName :: Parser String String
parseTagName = fromCharArray <$> some  alphaNum


parseTextNode :: Parser String HTML
parseTextNode = TextNode <<< fromCharArray <$> some (noneOf ['<', '>'])


parseAttributeName :: Parser String String
parseAttributeName = fromCharArray <$> some (noneOf [' ', '"', '\'', '>', '/', '='])


parseAttributeValue :: Parser String String
parseAttributeValue = do
  maybeOpenChar <- optionMaybe (char '"' <|> char '\'')
  case maybeOpenChar of
    Nothing -> fromCharArray <$> some (noneOf [' ', '\t', '\n', '\r', '"', '\'', '=', '<', '>', '`', '/'])
    Just openChar -> do
      value <- fromCharArray <$> many (noneOf [openChar])
      _ <- char openChar
      pure value



parseAttribute :: Parser String Attribute
parseAttribute = do
  name <- parseAttributeName
  skipSpaces
  maybeEquals <- optionMaybe $ char '='
  value <- case maybeEquals of
    Nothing -> pure ""
    Just _ -> do
        skipSpaces
        parseAttributeValue
  pure $ Attribute name value



parseAttributes :: Parser String (List Attribute)
parseAttributes = sepEndBy parseAttribute skipSpaces

notClosedTag :: Parser String Unit
notClosedTag = notFollowedBy $ string "</"

parseCloseTag :: String -> Parser String Char
parseCloseTag name = do
  _ <- string "</"
  _ <- string name
  char '>'


parseOpenTag :: Parser String (Tuple String (List Attribute))
parseOpenTag = do
  notClosedTag
  _ <- char '<'
  name <- parseTagName
  skipSpaces
  attrs <- parseAttributes
  skipSpaces
  _ <- char '>'
  pure $ Tuple name attrs


parseElement :: Parser String HTML
parseElement = do
  Tuple name attrs <- parseOpenTag
  children <- L.many parseNode
  _ <- parseCloseTag name
  pure $ Element name attrs  children


parseHTML ::  String  -> Either ParseError (List HTML) 
parseHTML s =  runParser s $ L.many parseNode <* eof

parseNode :: Parser String HTML
parseNode = fix \_ ->
  try parseElement <|>
  try parseVoidElement <|>
  parseTextNode


parseVoidElement :: Parser String HTML
parseVoidElement = do
  notClosedTag
  _ <- char '<'
  name <- parseTagName
  skipSpaces
  attrs <- parseAttributes
  skipSpaces
  _ <- string "/>"
  pure $ VoidElement name attrs


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

getParseResultString :: String -> String
getParseResultString strToParser = 
	 show $ parseHTML strToParser

main :: Effect Unit
main = do
--  log $ show $ fromFoldable (Just 1)
--  log  "Parser In Cpp:"
-- parseTest "zhuzhao)1212438" parseTagName
	log $ getParseResultString "<html></html>"



--  parseTest "a+b+c" opTest 


factorial :: Int->Int
factorial 0 = 1
factorial n = n * factorial (n-1)