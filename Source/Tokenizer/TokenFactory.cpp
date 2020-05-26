#include "TokenFactory.h"

bool TokenFactory::raw_token_is_numeric(std::string raw_token) const {
	int decimal_point_count = 0;

	for (char const& token_char :raw_token) {
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

Token* TokenFactory::build(std::string raw_token) {
	if (raw_token == "(") {
		return new BracketOpenToken(raw_token);
	}
	else if (raw_token == ")") {
		return new BracketCloseToken(raw_token);
	}
	else if (raw_token == "^") {
		return new ExponentToken(raw_token);
	}
	else if (raw_token == "*") {
		return new MultiplyToken(raw_token);
	}
	else if (raw_token == "/") {
		return new DivideToken(raw_token);
	}
	else if (raw_token == "+") {
		return new AddToken(raw_token);
	}
	else if (raw_token == "-") {
		return new MinusToken(raw_token);
	}
	else if (raw_token_is_numeric(raw_token)) {
		return new NumericToken(raw_token);
	}
	else {
		return new InvalidToken(raw_token);
	}
};
