#include "Scalar.hpp"

void printAllConversions(char c, int i, const float& f, const double& d, bool isImpossible){

    // Check if the value has a fractional component:
	if (d != static_cast<long long>(d)) {// Has decimals: reset to default/suitable precision so digits aren't chopped off
    
    	std::cout.unsetf(std::ios::fixed);
    	std::cout << std::setprecision(std::numeric_limits<double>::digits10);
	}

    std::cout << "char: ";
    if (isImpossible || std::isnan(d) || std::isinf(d) || i < 0 || i > 127) {
        std::cout << "impossible\n";
    } else if (!std::isprint(c)) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << c << "'\n";
    }

    std::cout << "int: ";
    if (isImpossible || std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN){
        std::cout << "impossible\n";
    } else {
        std::cout << i << "\n";
    }

    std::cout << "float: ";
    if (isImpossible) {
        std::cout << "impossible\n";
    } else if (std::isnan(f)) {
        std::cout << "nanf\n";
    } else if (std::isinf(f)) {
        std::cout << (f < 0 ? "-inff\n" : "+inff\n");
    } else {
        std::cout << f << "f\n";
    }

    std::cout << "double: ";
    if (isImpossible) {
        std::cout << "impossible\n";
    } else if (std::isnan(d)) {
        std::cout << "nan\n";
    } else if (std::isinf(d)) {
        std::cout << (d < 0 ? "-inf\n" : "+inf\n");
    } else {
        std::cout << d << "\n";
    }

}


void printPseudo(const std::string& str){

    bool isFloatPseudo = (str == "nanf" || str == "+inff" || str == "-inff");
    
    if (isFloatPseudo) {
        float  	f = std::strtof(str.c_str(), NULL);
        char	c = static_cast<char>(f);
        int 	i = static_cast<int>(f);
        double 	d = static_cast<double>(f);
        printAllConversions(c, i, f, d, false);
    } 
    else {
        double 	d = std::strtod(str.c_str(), NULL);
        char 	c = static_cast<char>(d);
        int 	i = static_cast<int>(d);
        float 	f = static_cast<double>(d);
        printAllConversions(c, i, f, d, false);
	}
}

bool isPseudo(const std::string& str) {
    if (str == "-inff" || str == "+inff" || str == "nanf" ||
            str == "-inf" || str == "+inf" || str == "nan"){
        printPseudo(str);
        return true;
    }
    return false;
}


bool charliteral(const std::string& str){

    if(str.length() == 1 && !std::isdigit(str[0])){
        char c = str[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);
        printAllConversions(c, i, f, d, false);
        return (true);
    }
    return false;
}

std::string trimmedStr(const std::string& str){

    if((str.length() > 1)
        && (str[str.length() - 1] == 'f')){
        std::string trimStr = str.substr(0, str.length() - 1) ;
        return trimStr;
    }
    return str;
}
                                                
bool isCleanInput(std::stringstream& ss,  double& doubleVal){ //pass double as reference!
    char leftover;

    if ((ss >> doubleVal) && !(ss >> leftover)) {
        return true; // clean string
    }
    return false; // Found garbage text or extraction failed
}



void ScalarConverter::convert(const std::string& str){

    std::cout << std::fixed << std::setprecision(1); 
    if (isPseudo(str)) {
        return;
    }
    if(charliteral(str)){
        return;
    }
    std::string trimStr = trimmedStr(str); //Get rid of 1 'f' max before working with ss. While std::stod and std::stof are great at finding a number inside a string, they suffer from a major flaw: they ignore trailing garbage text. So manual check is necesary
    std::stringstream ss(trimStr);
    double doubleVal = 0.0;					// reserve biggest space possible

    if(!isCleanInput(ss, doubleVal)){
		printAllConversions('\0',0 ,0.0f,0.0, true);
    }
	else
    	printAllConversions(doubleVal, doubleVal, doubleVal, doubleVal, false);
}


ScalarConverter::ScalarConverter(){};

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
