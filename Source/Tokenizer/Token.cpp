#include "Token.h"

// PUBLIC

Token::Token(const Token& token) {
	this->raw_token = std::make_unique<std::string>(*token.raw_token);
};

Token::Token(std::string str) {
	this->raw_token = std::make_unique<std::string>(str);
};

std::string Token::to_string() const {
	std::stringstream ss;
	ss	<< std::left
		<< std::setw(20)
		<< this->token_type_string()
		<< " => "
		<< std::setw(15)
		<< *this->raw_token;

	return ss.str();
}

bool Token::is_valid() {
	return true;
};
