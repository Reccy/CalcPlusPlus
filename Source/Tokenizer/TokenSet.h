#pragma once
#include <vector>
#include "Token.h"

class TokenSet
{
public:
	TokenSet(std::vector<Token*>);
	bool is_valid();
	std::string str();
private:
	std::vector<Token*> tokens;
};

