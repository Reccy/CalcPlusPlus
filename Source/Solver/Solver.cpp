#include "Solver.h"

Solver::Solver(TokenSet tokens) {
	this->token_set = tokens;
}

std::string Solver::solve() {
	std::stack<NumericToken*> token_stack;

	for (Token* token : this->token_set) {
		if (dynamic_cast<NumericToken*>(token)) {
			token_stack.push(dynamic_cast<NumericToken*>(token));
		}
		else if (dynamic_cast<OperatorToken*>(token)) {
			OperatorToken* operator_token = dynamic_cast<OperatorToken*>(token);

			if (token_stack.empty()) {
				throw SolveException();
			}

			NumericToken* num1 = token_stack.top();
			token_stack.pop();

			if (token_stack.empty()) {
				throw SolveException();
			}

			NumericToken* num2 = token_stack.top();
			token_stack.pop();

			NumericToken* result = perform_operation(operator_token, num1, num2);

			token_stack.push(result);
		}
	}

	std::ostringstream ss;
	ss << token_stack.top()->to_float();
	return std::string(ss.str());
}

NumericToken* Solver::perform_operation(OperatorToken* operator_token, NumericToken* numeric_token_1, NumericToken* numeric_token_2) {
	float num1 = numeric_token_1->to_float();
	float num2 = numeric_token_2->to_float();
	float result;

	if (dynamic_cast<AddToken*>(operator_token)) {
		result = num2 + num1;
	}
	else if (dynamic_cast<MinusToken*>(operator_token)) {
		result = num2 - num1;
	}
	else if (dynamic_cast<MultiplyToken*>(operator_token)) {
		result = num2 * num1;
	}
	else if (dynamic_cast<DivideToken*>(operator_token)) {
		result = num2 / num1;
	}
	else if (dynamic_cast<ExponentToken*>(operator_token)) {
		result = pow(num2, num1);
	}
	else {
		throw std::runtime_error("Unknown operator token");
	}

	return new NumericToken(std::to_string(result));
}
