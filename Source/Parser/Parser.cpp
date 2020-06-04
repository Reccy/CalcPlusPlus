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

	int bracket_close_count = 0;
	int bracket_open_count = 0;

	for (Token* token : this->token_set) {
		if (dynamic_cast<NumericToken*>(token)) {
			output_queue.push(token);
		}
		else if (dynamic_cast<BracketOpenToken*>(token)) {
			bracket_open_count++;

			OperatorToken* operator_token = dynamic_cast<BracketOpenToken*>(token);
			operator_stack.push(operator_token);
		}
		else if (dynamic_cast<BracketCloseToken*>(token)) {
			bracket_close_count++;

			OperatorToken* operator_token = dynamic_cast<BracketCloseToken*>(token);

			if (!operator_stack.empty() && dynamic_cast<BracketOpenToken*>(operator_stack.top())) {
				// Empty brackets
				throw ParseException();
			}

			while (!operator_stack.empty() && !dynamic_cast<BracketOpenToken*>(operator_stack.top())) {
				output_queue.push(operator_stack.top());
				operator_stack.pop();

				if (operator_stack.empty()) {
					// No Opening Bracket Found
					throw ParseException();
				}
			}

			if (!operator_stack.empty() && dynamic_cast<BracketOpenToken*>(operator_stack.top())) {
				operator_stack.pop();
			}
		}
		else if (dynamic_cast<OperatorToken*>(token)) {
			OperatorToken* operator_token = dynamic_cast<OperatorToken*>(token);

			while (!operator_stack.empty() && operator_stack.top()->precedence() >= operator_token->precedence()) {
				Token* token_to_push = dynamic_cast<Token*>(operator_stack.top());

				output_queue.push(token_to_push);
				operator_stack.pop();
			}
			operator_stack.push(operator_token);
		}
	}

	if (bracket_open_count != bracket_close_count) {
		// Mismatched brackets
		throw ParseException();
	}

	while (!operator_stack.empty()) {
		if (dynamic_cast<BracketOpenToken*>(operator_stack.top()) || dynamic_cast<BracketCloseToken*>(operator_stack.top())) {
			throw ParseException();
		}

		output_queue.push(operator_stack.top());
		operator_stack.pop();
	}

	if (output_queue.empty()) {
		throw ParseException();
	}

	return TokenSet(output_queue);
};
