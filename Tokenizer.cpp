#include "Tokenizer.h"

Tokenizer::Tokenizer(std::string raw_tokens) {
	this->raw_tokens = std::make_unique<std::string>(raw_tokens);
	this->raw_token_it = this->raw_tokens->begin();
};

std::vector<Token> Tokenizer::tokenize() {
	std::vector<Token> tokens;

	this->raw_token_it = this->raw_tokens->begin();

	while (this->raw_token_it != this->raw_tokens->end()) {
		tokens.push_back(build_token());
	}

	return tokens;
};

Token Tokenizer::build_token() {
	return Token(build_full_raw_token());
};

std::string Tokenizer::build_full_raw_token() {
	std::string::iterator forward_it = this->raw_token_it;

	while (forward_it != this->raw_tokens->end() && is_raw_numeric_token(forward_it)) {
		forward_it++;
	}

	if (this->raw_token_it == forward_it) {
		forward_it++;
	}

	std::string full_raw_token = std::string(this->raw_token_it, forward_it);

	this->raw_token_it = forward_it;

	return full_raw_token;
}

bool Tokenizer::is_raw_numeric_token(std::string::iterator forward_it) {
	return std::isdigit(*forward_it) || *forward_it == '.';
}