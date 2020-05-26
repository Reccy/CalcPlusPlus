#pragma once
#include <string>
#include <iomanip>
#include <sstream>
#include <memory>
#include <algorithm>
#include <stdexcept>

enum class TokenType { BracketOpen, BracketClose, Power, Multiply, Divide, Add, Subtract, Number, Invalid };

class Token
{
public:
	Token(const Token& token);
	Token(std::string raw_token);
	std::string to_string() const;
	bool is_valid();
private:
	virtual std::string token_type_string() const = 0;

	TokenType token_type;
	std::unique_ptr<std::string> raw_token;
};
