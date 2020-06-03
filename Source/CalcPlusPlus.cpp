#include <iostream>
#include <sstream>
#include "Tokenizer/Tokenizer.h"
#include "Parser/Parser.h"
#include "Solver/Solver.h"

#define PROG_NAME "CalcPlusPlus"
#define PROG_VERSION "0.3"
#define PROG_AUTHOR "Aaron Meaney"
#define PROG_COMPILE_TIMESTAMP __TIMESTAMP__

#define DEBUG_MODE true

#define EXIT_STRING "exit"

void print_program_intro() {
    std::cout
        << PROG_NAME
        << " v"
        << PROG_VERSION
        << "\n"
        << "By "
        << PROG_AUTHOR
        << "\n"
        << "Compiled at: "
        << PROG_COMPILE_TIMESTAMP
        << "\n"
        << "\n"
        << "Type '" << EXIT_STRING << "' to end program"
        << "\n";
};

std::string read_input() {
    std::cout
        << "\n"
        << "> ";

    std::string line;
    std::getline(std::cin, line);
    return line;
};

int main_loop() {
    std::string input = read_input();

    if (input == EXIT_STRING) {
        std::cout << "Thanks for using " << PROG_NAME << "\n";
        return false;
    }

    Tokenizer t(input);
    TokenSet token_set = t.tokenize();

    if (!token_set.is_valid()) {
        std::cout << "Syntax Error" << "\n";
        return true;
    }

    Parser parser(token_set);

    TokenSet parsed_token_set;
    try {
        parsed_token_set = parser.to_reverse_polish();
    }
    catch (ParseException e) {
        std::cout << "Syntax Error" << "\n";
        return true;
    }
    
    if (DEBUG_MODE) {
        std::cout << "Tokenizing " << input << "\n";
        std::cout << token_set.str() << "\n";
        std::cout << "Parsing" << "\n";
        std::cout << parsed_token_set.str() << "\n";
        std::cout << "Solving" << "\n";
    }

    Solver solver(parsed_token_set);

    try {
        std::cout << "= " << solver.solve() << "\n";
    }
    catch (SolveException e) {
        std::cout << "Syntax Error" << "\n";
        return true;
    }
    

    return true;
}

int main()
{
    print_program_intro();
    
    bool run_program = true;
    do {
        run_program = main_loop();
    } while (run_program);
};
