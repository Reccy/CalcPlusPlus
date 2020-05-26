#pragma once
#include <string>
#include <iomanip>
#include <sstream>
#include <memory>
#include <algorithm>
#include <stdexcept>

class Token
{
public:
	Token(const Token& token);
	Token(std::string raw_token);
	std::string to_string() const;
	bool is_valid();
private:
	virtual std::string token_type_string() const = 0;

	std::unique_ptr<std::string> raw_token;
};
