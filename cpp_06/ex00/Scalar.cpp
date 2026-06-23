#include "Scalar.hpp"

bool PseudoLiterals(const std::string& str) {
    if (str == "-inff" || str == "+inff" || str == "nanf") {
        std::cout << "It's a float pseudo-literal.\n";
        return true;
    }
    if (str == "-inf" || str == "+inf" || str == "nan") {
        std::cout << "It's a double pseudo-literal.\n";
        return true;
    }
    return false;
}

bool charliteral(const std::string& str){

    if(str.length() == 1 && !std::isdigit(str[0])){
        char c = str[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
    // By default, C++ streams will drop the trailing zeros entirely: 
    // e.g. static_cast<float>('a') evaluates to 97 not 97.0
    // so do:
        std::cout << std::fixed << std::setprecision(1); 

        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return (true);
    }
    return false;
}

std::string trimmedStr(const std::string& str){
    //std::string trimStr = str;

    if((str.length() > 1)
        && (str[str.length() - 1] == 'f')){
        std::string trimStr = str.substr(0, str.length() - 1) ;
        return trimStr;
    }
    return str;
}

bool checkCleanInput(std::stringstream& ss,  double doubleVal){
    double doubleVal;
    char leftover;
    
    bool clean;

    if (!(ss >> doubleVal) || (ss >> leftover)) {
    std::cout << "char: impossible\n"
                << "int: impossible\n"
                << "float: impossible\n"
                << "double: impossible\n";
    return false;
    }

}

void printAllConversions(double doubleVal){

    // 1. Handle Char safely
    std::cout << "char: ";
    if (doubleVal < 0 || doubleVal > 127) {
        std::cout << "impossible\n";
    } else if (!std::isprint(static_cast<int>(doubleVal))) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(doubleVal) << "'\n";
    }

    std::cout << "int: "    << static_cast<int>(doubleVal)  << "\n";
    std::cout << "float: "  << static_cast<float>(doubleVal) << "f\n";
    std::cout << "double: " << static_cast<double>(doubleVal) << "\n";
}

void ScalarConverter::convert(const std::string& str){

    if (PseudoLiterals(str)) {
        return; 
    }
    if(charliteral(str)){
        return;
    }
    std::string trimStr = trimmedStr(str);

    std::stringstream ss(trimStr);
    double doubleVal
    if(!checkCleanInput(ss, doubleVal);
    // If the stream fails to read a number, OR finds leftover garbage text after reading number
    
    printAllConversions(doubleVal);
}

// void convert(const std::string& str) {
//     // Phase 1: Handle Pseudo-literals immediately (Early Exit)
//     if (handlePseudoLiterals(str)) {
//         return; 
//     }

//     // Phase 2: Check for a single Character literal (e.g., 'a')
//     // If the string length is 1 and it's not a digit, it's a char literal!
//     if (str.length() == 1 && !std::isdigit(str[0])) {
//         processAsChar(str[0]);
//         return;
//     }

//     // Phase 3: Clean up float suffixes and identify the core numeric type
//     std::string cleanStr = str;
//     bool isFloatType = false;

//     if (cleanStr.length() > 1 && cleanStr[cleanStr.length() - 1] == 'f') {
//         isFloatType = true;
//         cleanStr = cleanStr.substr(0, cleanStr.length() - 1); // Strip the 'f'
//     }

//     // Phase 4: Stream Conversion & Validation
//     std::stringstream ss(cleanStr);
//     double doubleVal;
//     char leftover;

//     // If the stream fails to read a number, OR finds leftover garbage text
//     if (!(ss >> doubleVal) || (ss >> leftover)) {
//         std::cout << "char: impossible\n"
//                   << "int: impossible\n"
//                   << "float: impossible\n"
//                   << "double: impossible\n";
//         return;
//     }

//     // Phase 5: Success! Cast and Print everything
//     // Since we parsed it into a double, we can safely dispatch the prints
//     printAllConversions(doubleVal, isFloatType);
// }



/*
//42.3f.3f
stripping only the last 'f' leaves you with "42.3f.3".

0)  ss >> doubleVal reads "42.3" successfully into your double variable.
1)  The stream stops reading at the second 'f' because it's not a valid part of a number.
2)  Crucially, the remaining string inside the stream is now "f.3".
    This is where the leftover check (ss >> leftover) saves the day. Because there is still "f.3" sitting in the stream, attempting to read into leftover will succeed (it will grab the 'f')

//a42.1f
stripping only the last 'f' leaves you with "a42.1"

0) ss >> doubleVal;
   -The very first character it encounters is 'a'
   -'a' cannot form any part of a valid floating-point number, the extraction fails immediately.
   -The stream internally sets its failbit flag to true.
*/
