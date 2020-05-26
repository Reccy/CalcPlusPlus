#pragma once
#include "Token.h"
class ExponentToken : public Token
{
	using Token::Token;
	std::string token_type_string() const override;
};

