#include "Token.h"

// PUBLIC

Token::Token(const Token& token) {
	this->token_type = token.token_type;
	this->raw_token = std::make_unique<std::string>(*token.raw_token);
};

Token::Token(std::string str) {
	this->raw_token = std::make_unique<std::string>(str);
	set_token_type();
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
	return this->token_type != TokenType::Invalid;
};

// PRIVATE

inline void Token::set_token_type() {
	if (compare_raw_token("(")) {
		this->token_type = TokenType::BracketOpen;
	}
	else if (compare_raw_token(")")) {
		this->token_type = TokenType::BracketClose;
	}
	else if (compare_raw_token("^")) {
		this->token_type = TokenType::Power;
	}
	else if (compare_raw_token("*")) {
		this->token_type = TokenType::Multiply;
	}
	else if (compare_raw_token("/")) {
		this->token_type = TokenType::Divide;
	}
	else if (compare_raw_token("+")) {
		this->token_type = TokenType::Add;
	}
	else if (compare_raw_token("-")) {
		this->token_type = TokenType::Subtract;
	}
	else if (raw_token_is_numeric()) {
		this->token_type = TokenType::Number;
	}
	else {
		this->token_type = TokenType::Invalid;
	}
};

bool inline Token::compare_raw_token(std::string token) const {
	return *this->raw_token == std::string(token);
};

bool Token::raw_token_is_numeric() const {
	int decimal_point_count = 0;

	for (char const& token_char : *this->raw_token) {
		if (!std::isdigit(token_char) && token_char != '.')
			return false;

		if (token_char == '.') {
			decimal_point_count++;
		}

		if (decimal_point_count > 1) {
			return false;
		}
	}
	
	return true;
};

std::string Token::token_type_string() const {
	switch (this->token_type) {
	case TokenType::BracketOpen:
		return "BracketOpen";
		break;
	case TokenType::BracketClose:
		return "BracketClose";
		break;
	case TokenType::Power:
		return "Power";
		break;
	case TokenType::Multiply:
		return "Multiply";
		break;
	case TokenType::Divide:
		return "Divide";
		break;
	case TokenType::Add:
		return "Add";
		break;
	case TokenType::Subtract:
		return "Subtract";
		break;
	case TokenType::Number:
		return "Number";
		break;
	case TokenType::Invalid:
		return "Invalid";
		break;
	}

	throw std::invalid_argument(std::to_string(static_cast<int>(this->token_type)));
};
