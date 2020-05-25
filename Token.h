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
	void set_token_type();
	bool compare_raw_token(std::string) const;
	bool raw_token_is_numeric() const;
	std::string token_type_string() const;

	TokenType token_type;
	std::unique_ptr<std::string> raw_token;
};
