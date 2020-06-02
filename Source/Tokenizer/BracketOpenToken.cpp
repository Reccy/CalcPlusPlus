#include "BracketOpenToken.h"

std::string BracketOpenToken::token_type_string() const {
	return "BracketOpen";
}

int BracketOpenToken::precedence() const {
	return -1;
}
