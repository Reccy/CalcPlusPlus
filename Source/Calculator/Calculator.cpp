#include "Calculator.h"

std::string Calculator::calculate(std::string input, bool debug_mode) {
    std::stringstream ss;

    Tokenizer t(input);
    TokenSet token_set = t.tokenize();

    if (!token_set.is_valid()) {
        ss << "Syntax Error" << "\n";
        return ss.str();
    }

    Parser parser(token_set);

    TokenSet parsed_token_set;
    try {
        parsed_token_set = parser.to_reverse_polish();
    }
    catch (ParseException e) {
        ss << "Syntax Error" << "\n";
        return ss.str();
    }

    if (debug_mode) {
        std::cout << "Tokenizing " << input << "\n";
        std::cout << token_set.str() << "\n";
        std::cout << "Parsing" << "\n";
        std::cout << parsed_token_set.str() << "\n";
        std::cout << "Solving" << "\n";
    }

    Solver solver(parsed_token_set);

    try {
        ss << solver.solve();
        return ss.str();
    }
    catch (SolveException e) {
        ss << "Syntax Error" << "\n";
        return ss.str();
    }
    catch (DivideByZeroException e) {
        ss << "Divide by Zero Error" << "\n";
        return ss.str();
    }
}
