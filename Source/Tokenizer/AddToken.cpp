#include "AddToken.h"

std::string AddToken::token_type_string() const {
	return "Add";
}

int AddToken::precedence() const {
	return 0;
}
