#include "Control_Alt/Control_Alt.h"
#include "Data_Identity/Data_Identity.h"
#include "Data_Semigroup/Data_Semigroup.h"
#include "Prelude/Prelude.h"
#include "Text_Parsing_Parser/Text_Parsing_Parser.h"
#include "Text_Parsing_Parser_String/Text_Parsing_Parser_String.h"
#include "Text_Parsing_Parser_Token/Text_Parsing_Parser_Token.h"

#include "Text_Parsing_Parser_Language/Text_Parsing_Parser_Language.h"


namespace Text_Parsing_Parser_Language {

auto emptyDef() -> boxed {
    boxed op_Prime_ = [=](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(array_t{ ":", "!", "#", "$", "%", "&", "*", "+", ".", "/", "<", "=", ">", "?", "@", "\\", "^", "|", "-", "~" });
    };
    return dict_t{
        { "commentStart", "" },
        { "commentEnd", "" },
        { "commentLine", "" },
        { "nestedComments", true },
        { "identStart", Control_Alt::alt()(Text_Parsing_Parser::altParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_Token::letter()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("_")) },
        { "identLetter", Control_Alt::alt()(Text_Parsing_Parser::altParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_Token::alphaNum()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(array_t{ "_", "'" })) },
        { "opStart", op_Prime_(Data_Identity::monadIdentity()) },
        { "opLetter", op_Prime_(Data_Identity::monadIdentity()) },
        { "reservedOpNames", array_t{  } },
        { "reservedNames", array_t{  } },
        { "caseSensitive", true }
    };
};
auto haskellStyle() -> boxed {
    boxed op_Prime_ = [=](const boxed& dictMonad) -> boxed {
        return Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(dictMonad)(array_t{ ":", "!", "#", "$", "%", "&", "*", "+", ".", "/", "<", "=", ">", "?", "@", "\\", "^", "|", "-", "~" });
    };
    boxed v = Text_Parsing_Parser_Token::unGenLanguageDef()(Text_Parsing_Parser_Language::emptyDef());
    return dict_t{
        { "commentStart", "{-" },
        { "commentEnd", "-}" },
        { "commentLine", "--" },
        { "nestedComments", true },
        { "identStart", Text_Parsing_Parser_Token::letter()(Data_Identity::monadIdentity()) },
        { "identLetter", Control_Alt::alt()(Text_Parsing_Parser::altParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_Token::alphaNum()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(array_t{ "_", "'" })) },
        { "opStart", op_Prime_(Data_Identity::monadIdentity()) },
        { "opLetter", op_Prime_(Data_Identity::monadIdentity()) },
        { "reservedNames", array_t{  } },
        { "reservedOpNames", array_t{  } },
        { "caseSensitive", true }
    };
};
auto haskell98Def() -> boxed {
    boxed v = Text_Parsing_Parser_Token::unGenLanguageDef()(Text_Parsing_Parser_Language::haskellStyle());
    return dict_t{
        { "commentStart", v["commentStart"] },
        { "commentEnd", v["commentEnd"] },
        { "commentLine", v["commentLine"] },
        { "nestedComments", v["nestedComments"] },
        { "identStart", v["identStart"] },
        { "identLetter", v["identLetter"] },
        { "opStart", v["opStart"] },
        { "opLetter", v["opLetter"] },
        { "reservedNames", array_t{ "let", "in", "case", "of", "if", "then", "else", "data", "type", "class", "default", "deriving", "do", "import", "infix", "infixl", "infixr", "instance", "module", "newtype", "where", "primitive" } },
        { "reservedOpNames", array_t{ "::", "..", "=", "\\", "|", "<-", "->", "@", "~", "=>" } },
        { "caseSensitive", v["caseSensitive"] }
    };
};
auto haskellDef() -> const boxed& {
    static const boxed _ = dict_t{
        { "commentStart", Text_Parsing_Parser_Language::haskell98Def()["commentStart"] },
        { "commentEnd", Text_Parsing_Parser_Language::haskell98Def()["commentEnd"] },
        { "commentLine", Text_Parsing_Parser_Language::haskell98Def()["commentLine"] },
        { "nestedComments", Text_Parsing_Parser_Language::haskell98Def()["nestedComments"] },
        { "identStart", Text_Parsing_Parser_Language::haskell98Def()["identStart"] },
        { "identLetter", Control_Alt::alt()(Text_Parsing_Parser::altParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_Language::haskell98Def()["identLetter"])(Text_Parsing_Parser_String::_char_()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())("#")) },
        { "opStart", Text_Parsing_Parser_Language::haskell98Def()["opStart"] },
        { "opLetter", Text_Parsing_Parser_Language::haskell98Def()["opLetter"] },
        { "reservedNames", Data_Semigroup::append()(Data_Semigroup::semigroupArray())(Text_Parsing_Parser_Language::haskell98Def()["reservedNames"])(array_t{ "foreign", "import", "export", "primitive", "_ccall_", "_casm_", "forall" }) },
        { "reservedOpNames", Text_Parsing_Parser_Language::haskell98Def()["reservedOpNames"] },
        { "caseSensitive", Text_Parsing_Parser_Language::haskell98Def()["caseSensitive"] }
    };
    return _;
};
auto haskell() -> boxed {
    return Text_Parsing_Parser_Token::makeTokenParser()(Data_Identity::monadIdentity())(Text_Parsing_Parser_Language::haskellDef());
};
auto javaStyle() -> boxed {
    boxed v = Text_Parsing_Parser_Token::unGenLanguageDef()(Text_Parsing_Parser_Language::emptyDef());
    return dict_t{
        { "commentStart", "/*" },
        { "commentEnd", "*/" },
        { "commentLine", "//" },
        { "nestedComments", true },
        { "identStart", Text_Parsing_Parser_Token::letter()(Data_Identity::monadIdentity()) },
        { "identLetter", Control_Alt::alt()(Text_Parsing_Parser::altParserT()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_Token::alphaNum()(Data_Identity::monadIdentity()))(Text_Parsing_Parser_String::oneOf()(Text_Parsing_Parser_String::stringLikeString())(Data_Identity::monadIdentity())(array_t{ "_", "'" })) },
        { "opStart", v["opStart"] },
        { "opLetter", v["opLetter"] },
        { "reservedNames", array_t{  } },
        { "reservedOpNames", array_t{  } },
        { "caseSensitive", false }
    };
};


} // end namespace Text_Parsing_Parser_Language


