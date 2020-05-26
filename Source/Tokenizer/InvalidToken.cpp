#include "InvalidToken.h"

std::string InvalidToken::token_type_string() const {
	return "Invalid";
}

bool InvalidToken::is_valid() {
	return false;
}