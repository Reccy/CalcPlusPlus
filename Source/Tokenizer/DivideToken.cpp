#include "DivideToken.h"

std::string DivideToken::token_type_string() const {
	return "DivideToken";
}

int DivideToken::precedence() const {
	return 1;
}
