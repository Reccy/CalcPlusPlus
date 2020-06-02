#pragma once
#include "Token.h"
#include <iostream>

class OperatorToken : public Token
{
public:
	using Token::Token;
	virtual int precedence() const = 0;
};
