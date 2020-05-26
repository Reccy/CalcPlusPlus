#pragma once
#include "Token.h"
class DivideToken : public Token
{
public:
	using Token::Token;
	std::string token_type_string() const override;
};

