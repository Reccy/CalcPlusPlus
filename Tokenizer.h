#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Token.h"

class Tokenizer
{
public:
	Tokenizer(std::string);
	std::vector<Token> tokenize();
private:
	Token build_token();
	std::string build_full_raw_token();

	std::unique_ptr<std::string> raw_tokens;
	std::string::iterator raw_token_it;
};
