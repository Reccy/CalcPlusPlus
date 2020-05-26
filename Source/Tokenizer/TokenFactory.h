#pragma once
#include "Token.h"
#include "BracketOpenToken.h"
#include "BracketCloseToken.h"
#include "ExponentToken.h"
#include "MultiplyToken.h"
#include "DivideToken.h"
#include "AddToken.h"
#include "MinusToken.h"
#include "NumericToken.h"
#include "InvalidToken.h"

class TokenFactory
{
public:
	Token* build(std::string);
protected:
	bool raw_token_is_numeric(std::string) const;
};

