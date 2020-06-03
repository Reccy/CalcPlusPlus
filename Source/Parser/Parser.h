#pragma once
#include <queue>
#include <stack>
#include "ParseException.h"
#include "../Tokenizer/TokenSet.h"
#include "../Tokenizer/Token.h"
#include "../Tokenizer/NumericToken.h"
#include "../Tokenizer/AddToken.h"
#include "../Tokenizer/MinusToken.h"
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
	TokenSet token_set;
};
