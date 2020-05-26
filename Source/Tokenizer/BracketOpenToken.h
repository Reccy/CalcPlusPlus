#pragma once
#include "Token.h"
class BracketOpenToken : public Token
{
	using Token::Token;
	std::string token_type_string() const override;
};

