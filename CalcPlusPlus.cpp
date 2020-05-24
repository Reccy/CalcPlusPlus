#include <iostream>
#include "Tokenizer.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    std::string input = "256+84+39.84+384/342^34+34*34(34+79)";
    Tokenizer t(input);
    std::vector<Token> result = t.tokenize();
}
