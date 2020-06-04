#include "UnaryMinusToken.h"

std::string UnaryMinusToken::token_type_string() const {
	return "Unary Minus";
}

int UnaryMinusToken::precedence() const {
	return 2;
}