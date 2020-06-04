#pragma once
#include "OperatorToken.h"

class UnaryMinusToken : public OperatorToken
{
	using OperatorToken::OperatorToken;
	std::string token_type_string() const override;
	int precedence() const override;
};

