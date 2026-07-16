#include "RPN.hpp"

bool isValidInput(const std::string& input){

    int operandCount = 0;
    int operatorCount = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];

        if (c == ' ') {
            continue;
        }

        bool isDigit = std::isdigit(c);
        bool isOperator = (c == '+' || c == '-' || c == '*' || c == '/');

        if (!isDigit && !isOperator) {
            std::cerr << "Error: Forbidden character '" << c << "'" << std::endl;
            return false;
        }
        if(i < (input.length() - 1) && input[i + 1] != ' '){
            std::cerr << "Error: Numbers must be single digits separated by spaces." << std::endl;
            return false;
        }
        if (isDigit) {
            operandCount++;
        } else {
            operatorCount++;
        }

    }
    // A valid RPN expression must have at least one operand, and one more operand (number) than operators.
    if (operandCount == 0 || operandCount != operatorCount + 1) {
        std::cerr << "Error: Unbalanced expression (operators vs operands)." << std::endl;
        return false;
    }
    return true;
}

bool calculate(const std::string& input, std::stack<int>& rpn){

    int result = 0;
    for(size_t i = 0; i < input.length(); ++i){
        char c = input[i];
        
        if (c == ' ') continue;
        if(std::isdigit(c))
            rpn.push(c - '0');
        else{
            if(rpn.size() < 2){
                std::cerr << "Error: Invalid operation order." << std::endl;
                return false;
            }
            int b = rpn.top();
            rpn.pop();
            int a = rpn.top();
            rpn.pop();
            if(c == '+'){
                result = a + b;
            }
            else if(c == '-'){
                result = a - b;
            }
            else if(c == '*'){
                result = a * b;
            }
            else if (c == '/') {
                if (b == 0) {
                    std::cerr << "Error: Division by zero." << std::endl;
                    return false;
                }
                result = a / b;
            }
            rpn.push(result);
        }
    }
    return true;
}


