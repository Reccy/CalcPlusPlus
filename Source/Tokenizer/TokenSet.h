#pragma once
#include <vector>
#include <queue>
#include "Token.h"

class TokenSet
{
public:
	TokenSet() = default;
	TokenSet(std::queue<Token*>);
	TokenSet(std::vector<Token*>);
	bool is_valid();
	std::string str();
	std::string raw_str();
	std::vector<Token*>::iterator begin();
	std::vector<Token*>::iterator end();
private:
	std::vector<Token*> tokens;
};

