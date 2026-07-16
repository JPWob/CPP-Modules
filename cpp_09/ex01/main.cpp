#include "RPN.hpp"

int main(int argc, char *argv[]){
    if(argc < 2){
        std::cerr << "Error: not enough arguments" << std::endl;
        return -1;
    }

    if(!isValidInput(argv[1]))
        return -1;
    std::stack<int> rpn;
    if(!calculate(argv[1], rpn))
        return -1;
    std::cout << rpn.top() << std::endl;
    return 1;
}
