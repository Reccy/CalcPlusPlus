#pragma once
#include "Token.h"
class NumericToken : public Token
{
public:
	using Token::Token;
	std::string token_type_string() const override;
	float to_float() const;
private:
	float value;
};
