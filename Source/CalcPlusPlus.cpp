#include <iostream>
#include <sstream>
#include "Tokenizer/Tokenizer.h"

#define PROG_NAME "CalcPlusPlus"
#define PROG_VERSION "0.1"
#define PROG_AUTHOR "Aaron Meaney"
#define PROG_COMPILE_TIMESTAMP __TIMESTAMP__

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
        << std::endl;
};

std::string read_input() {
    std::cout
        << "\n"
        << "Enter a Maths equation to solve\n"
        << "> ";

    std::string line;
    std::getline(std::cin, line);
    return line;
};

int main_loop() {
    std::string input = read_input();

    if (input == EXIT_STRING) {
        std::cout << "Thanks for using " << PROG_NAME << std::endl;
        return false;
    }

    std::cout << "Tokenizing " << input << "\n";

    Tokenizer t(input);

    TokenSet token_set = t.tokenize();

    std::cout << token_set.str() << "\n";

    if (!token_set.is_valid()) {
        std::cout << "Invalid tokens detected." << std::endl;
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
