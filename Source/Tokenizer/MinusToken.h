#pragma once
#include "Token.h"
class MinusToken : public Token
{
	using Token::Token;
	std::string token_type_string() const override;
};

