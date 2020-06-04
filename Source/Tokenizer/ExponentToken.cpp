#include "ExponentToken.h"

std::string ExponentToken::token_type_string() const {
	return "Exponent";
}

int ExponentToken::precedence() const {
	return 3;
}
