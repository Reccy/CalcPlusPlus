#pragma once
#include "OperatorToken.h"
class AddToken : public OperatorToken
{
public:
	using OperatorToken::OperatorToken;
	std::string token_type_string() const override;
	int precedence() const override;
};

