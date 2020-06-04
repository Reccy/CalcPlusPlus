#pragma once
#include <queue>
#include <stack>
#include "ParseException.h"
#include "../Tokenizer/TokenSet.h"
#include "../Tokenizer/Token.h"
#include "../Tokenizer/NumericToken.h"
#include "../Tokenizer/AddToken.h"
#include "../Tokenizer/MinusToken.h"
#include "../Tokenizer/UnaryMinusToken.h"
#include "../Tokenizer/MultiplyToken.h"
#include "../Tokenizer/DivideToken.h"
#include "../Tokenizer/ExponentToken.h"
#include "../Tokenizer/BracketOpenToken.h"
#include "../Tokenizer/BracketCloseToken.h"


class Parser
{
public:
	Parser(TokenSet);
	TokenSet to_reverse_polish();
private:
	bool is_token_unary_minus(Token*, Token*);
	TokenSet token_set;
};
