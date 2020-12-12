#include "../header/token.hpp"

std::unordered_map<std::string, TokenType> keywords({
    {"let", LET},
    {"func", FUNCTION},
    {"True", TRUE},
    {"False", FALSE},
    {"if", IF},
    {"else", ELSE},
    {"return", RETURN},
});

TokenType LookupIdent(std::string ident)
{
  if (keywords.find(ident) == keywords.end())
    return IDENT;
  return keywords[ident];
}
