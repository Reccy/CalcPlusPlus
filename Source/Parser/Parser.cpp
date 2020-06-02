#include "Parser.h"

Parser::Parser(TokenSet token_set) {
	if (!token_set.is_valid()) {
		throw std::runtime_error("Cannot parse an invalid token set");
	}

	this->token_set = token_set;
};

TokenSet Parser::to_reverse_polish() {
	std::queue<Token*> output_queue;
	std::stack<OperatorToken*> operator_stack;

	for (Token* token : this->token_set) {
		if (dynamic_cast<NumericToken*>(token)) {
			output_queue.push(token);
		}
		else if (dynamic_cast<BracketOpenToken*>(token)) {
			OperatorToken* operator_token = dynamic_cast<BracketOpenToken*>(token);
			operator_stack.push(operator_token);
		}
		else if (dynamic_cast<BracketCloseToken*>(token)) {
			OperatorToken* operator_token = dynamic_cast<BracketCloseToken*>(token);

			while (!operator_stack.empty() && !dynamic_cast<BracketOpenToken*>(operator_stack.top())) {
				output_queue.push(operator_stack.top());
				operator_stack.pop();
			}

			if (!operator_stack.empty() && dynamic_cast<BracketOpenToken*>(operator_stack.top())) {
				operator_stack.pop();
			}
		}
		else if (dynamic_cast<OperatorToken*>(token)) {
			OperatorToken* operator_token = dynamic_cast<OperatorToken*>(token);

			while (!operator_stack.empty() && operator_stack.top()->precedence() > operator_token->precedence()) {
				Token* token_to_push = dynamic_cast<Token*>(operator_stack.top());

				output_queue.push(token_to_push);
				operator_stack.pop();
			}
			operator_stack.push(operator_token);
		}
	}

	while (!operator_stack.empty()) {
		output_queue.push(operator_stack.top());
		operator_stack.pop();
	}

	return TokenSet(output_queue);
};
