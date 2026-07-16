#include <iostream>
#include <stack>
#include <string>

int main(int argc, char *argv[]){
    if(argc < 2){
        std::cerr << "Error: not enough arguments" << std::endl;
        return 1;
    }

    std::stack<int> rpn;
    if(!isValidInput(argv[1]))
        return -1;


}

bool isValidInput(const std::string& input){

    int operandCount = 0;
    int operatorCount = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];

        // Skip spaces
        if (c == ' ') {
            continue;
        }

        // 1. Check if the character itself is allowed
        bool isDigit = std::isdigit(c);
        bool isOperator = (c == '+' || c == '-' || c == '*' || c == '/');

        if (!isDigit && !isOperator) {
            std::cerr << "Error: Forbidden character '" << c << "'" << std::endl;
            return false;
        }
        else{ 
            if(i < (input.length()) && input[i + 1] != ' '){
            std::cerr << "Error: Numbers must be single digits separated by spaces." << std::endl;
            return
        }

        }
        01234
        3 4 +
        lenght 4

        


        // 2. Strict 42 Rule: Ensure the character is a single-digit token.
        // It must be isolated by spaces on both sides (or be at the start/end of the string).
        if (i > 0 && input[i - 1] != ' ') {
            std::cerr << "Error: Numbers must be single digits separated by spaces." << std::endl;
            return false;
        }
        if (i < input.length() - 1 && input[i + 1] != ' ') {
            std::cerr << "Error: Numbers must be single digits separated by spaces." << std::endl;
            return false;
        }

        // 3. Keep track of our counts to check mathematical balance later
        if (isDigit) {
            operandCount++;
        } else {
            operatorCount++;
        }
    }

    // A valid RPN expression must have at least one operand,
    // and exactly one more operand than operators (e.g., "3 4 +" -> 2 numbers, 1 operator).
    if (operandCount == 0 || operandCount != operatorCount + 1) {
        std::cerr << "Error: Unbalanced expression (operators vs operands)." << std::endl;
        return false;
    }

    return true;
}
}

