#include "MinusToken.h"

std::string MinusToken::token_type_string() const {
	return "Minus";
}

int MinusToken::precedence() const {
	return 0;
}
