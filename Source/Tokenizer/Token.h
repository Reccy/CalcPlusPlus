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
	virtual bool is_valid();
protected:
	std::unique_ptr<std::string> raw_token;
private:
	virtual std::string token_type_string() const = 0;
};
