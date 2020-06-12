#pragma once
#include "../Tokenizer/Tokenizer.h"
#include "../Parser/Parser.h"
#include "../Solver/Solver.h"

class Calculator
{
public:
	static std::string calculate(std::string input, bool debug_mode);
};
