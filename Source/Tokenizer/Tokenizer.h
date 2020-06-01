#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Token.h"
#include "TokenFactory.h"
#include "TokenSet.h"

class Tokenizer
{
public:
	Tokenizer(std::string);
	TokenSet tokenize();
private:
	std::string build_full_raw_token();
	bool is_raw_numeric_token(std::string::iterator);
	void ff_to_non_whitespace();

	std::unique_ptr<std::string> raw_tokens;
	std::string::iterator raw_token_it;
};
