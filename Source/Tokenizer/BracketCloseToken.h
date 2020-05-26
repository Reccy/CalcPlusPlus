#pragma once
#include "Token.h"
class BracketCloseToken : public Token
{
	using Token::Token;
	std::string token_type_string() const override;
};

