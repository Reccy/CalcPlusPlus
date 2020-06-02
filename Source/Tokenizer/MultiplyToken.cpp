#include "MultiplyToken.h"

std::string MultiplyToken::token_type_string() const {
	return "Multiply";
}

int MultiplyToken::precedence() const {
	return 1;
}