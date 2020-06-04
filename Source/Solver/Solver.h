#pragma once
#include <stack>
#include <math.h>
#include "SolveException.h"
#include "DivideByZeroException.h"
#include "../Tokenizer/TokenSet.h"
#include "../Tokenizer/Token.h"
#include "../Tokenizer/NumericToken.h"
#include "../Tokenizer/OperatorToken.h"
#include "../Tokenizer/AddToken.h"
#include "../Tokenizer/MinusToken.h"
#include "../Tokenizer/UnaryMinusToken.h"
#include "../Tokenizer/MultiplyToken.h"
#include "../Tokenizer/DivideToken.h"
#include "../Tokenizer/ExponentToken.h"

class Solver
{
public:
	Solver(TokenSet);
	std::string solve();
private:
	TokenSet token_set;
	NumericToken* perform_unary_operation(OperatorToken*, NumericToken*);
	NumericToken* perform_binary_operation(OperatorToken*, NumericToken*, NumericToken*);
};

