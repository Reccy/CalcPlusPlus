#include "NumericToken.h"

std::string NumericToken::token_type_string() const {
	return "Numeric";
}

float NumericToken::to_float() const {
	return ::atof(this->raw_token->c_str());
}
