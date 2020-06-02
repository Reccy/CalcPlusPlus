#include "BracketCloseToken.h"

std::string BracketCloseToken::token_type_string() const {
	return "BracketClose";
}

int BracketCloseToken::precedence() const {
	return -1;
}
