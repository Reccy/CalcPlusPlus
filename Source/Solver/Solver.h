#pragma once
#include <stack>
#include "../Tokenizer/TokenSet.h"
#include "../Tokenizer/Token.h"
#include "../Tokenizer/NumericToken.h"
#include "../Tokenizer/OperatorToken.h"
#include "../Tokenizer/AddToken.h"
#include "../Tokenizer/MinusToken.h"
#include "../Tokenizer/MultiplyToken.h"
#include "../Tokenizer/DivideToken.h"

class Solver
{
public:
	Solver(TokenSet);
	std::string solve();
private:
	TokenSet token_set;
	NumericToken* perform_operation(OperatorToken*, NumericToken*, NumericToken*);
};

