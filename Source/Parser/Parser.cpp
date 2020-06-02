#include "Parser.h"

Parser::Parser(TokenSet token_set) {
	if (!token_set.is_valid()) {
		throw std::runtime_error("Cannot parse an invalid token set");
	}

	this->token_set = token_set;
};

bool token_is_number(Token* token) {
	return typeid(*token) == typeid(NumericToken);
};

bool token_is_operator(Token* token) {
	return	typeid(*token) == typeid(AddToken) ||
		typeid(*token) == typeid(MinusToken) ||
		typeid(*token) == typeid(MultiplyToken) ||
		typeid(*token) == typeid(DivideToken);
};

bool token_is_open_bracket(Token* token) {
	return (typeid(*token) == typeid(BracketOpenToken));
};

bool token_is_close_bracket(Token* token) {
	return (typeid(*token) == typeid(BracketCloseToken));
};

int get_operator_precedence(Token* token) {
	if (typeid(*token) == typeid(AddToken) || typeid(*token) == typeid(MinusToken)) {
		return 0;
	}
	else if (typeid(*token) == typeid(MultiplyToken) || typeid(*token) == typeid(DivideToken)) {
		return 1;
	}
	else if (typeid(*token) == typeid(ExponentToken)) {
		return 3;
	}
	else if (typeid(*token) == typeid(BracketCloseToken) || typeid(*token) == typeid(BracketOpenToken)) {
		return 3;
	}

	throw std::runtime_error("Undefined precedence for token");
}

bool operator_has_greater_precedence(Token* lhs, Token* rhs) {
	int lhs_precedence = get_operator_precedence(lhs);
	int rhs_precedence = get_operator_precedence(rhs);

	return lhs_precedence > rhs_precedence;
};

TokenSet Parser::to_reverse_polish() {
	std::queue<Token*> output_queue;
	std::stack<Token*> operator_stack;

	for (Token* token : this->token_set) {
		if (token_is_number(token)) {
			output_queue.push(token);
		}
		else if (token_is_operator(token)) {
			while (!operator_stack.empty() && operator_has_greater_precedence(operator_stack.top(), token)) {
				output_queue.push(operator_stack.top());
				operator_stack.pop();
			}
			operator_stack.push(token);
		}
		else if (token_is_open_bracket(token)) {
			operator_stack.push(token);
		}
		else if (token_is_close_bracket(token)) {
			while (!operator_stack.empty() && !token_is_open_bracket(operator_stack.top())) {
				output_queue.push(operator_stack.top());
				operator_stack.pop();
			}

			if (!operator_stack.empty() && token_is_open_bracket(operator_stack.top())) {
				operator_stack.pop();
			}
		}
	}

	while (!operator_stack.empty()) {
		output_queue.push(operator_stack.top());
		operator_stack.pop();
	}

	return TokenSet(output_queue);
};
