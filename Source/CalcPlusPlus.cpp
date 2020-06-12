#include <iostream>
#include <sstream>
#include "Calculator/Calculator.h"

#define PROG_NAME "CalcPlusPlus"
#define PROG_VERSION "0.4"
#define PROG_AUTHOR "Aaron Meaney"
#define PROG_COMPILE_TIMESTAMP __TIMESTAMP__

#define DEBUG_MODE false

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

    std::cout << "= " << Calculator::calculate(input, DEBUG_MODE) << "\n";

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
