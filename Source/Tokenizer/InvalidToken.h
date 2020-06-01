#pragma once
#include "Token.h"
class InvalidToken : public Token
{
public:
	using Token::Token;
	std::string token_type_string() const override;
	bool is_valid() override;
};
