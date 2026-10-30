#include "Scalar.hpp"


bool isInf(double d) {
    return (d == std::numeric_limits<double>::infinity() ||
            d == -std::numeric_limits<double>::infinity());
}

bool isInf(float f) {
    return (f == std::numeric_limits<float>::infinity() ||
            f == -std::numeric_limits<float>::infinity());
}

bool isNan(double d) {
    return (d != d); // true ONLY if d is NaN, false for every other number (including +/- infinity)
}


enum LiteralType{
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

void printAllConversions(char c, int i, const float& f, const double& d, bool isImpossible){

	bool intOverflow = (d > std::numeric_limits<int>::max() || 
                        d < std::numeric_limits<int>::min() || 
                        d != d); // nan check

    bool charOverflow = (intOverflow || d < 0 || d > 127);

	std::cout << "char: ";
    if (isImpossible || charOverflow) {
        std::cout << "impossible\n";
    } else if (!std::isprint(static_cast<unsigned char>(c))) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << c << "'\n";
    }

    std::cout << "int: ";
    if (isImpossible || intOverflow){
        std::cout << "impossible\n";
    } else {
        std::cout << i << "\n";
    }

    std::cout << "float: ";
    if (isImpossible) {
        std::cout << "impossible\n";
    } else {
        std::cout << f << "f\n";
    }

    std::cout << "double: ";
    if (isImpossible) {
        std::cout << "impossible\n";
    } else {
        std::cout << d << "\n";
    }

}


void printPseudo(const std::string& str){


    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

	double d = std::strtod(str.c_str(), NULL);

	float f = static_cast<float>(d);
  	std::cout << "float: ";
	if (isNan(f)) {
       	std::cout << "nanf\n";
    } 
	else if (isInf(f)) {
        std::cout << (f < 0 ? "-inff\n" : "+inff\n");
	}
  
    std::cout << "double: ";
	if (isNan(d)) {
        std::cout << "nan\n";
    }
	else if (isInf(d)) {
        std::cout << (d < 0 ? "-inf\n" : "+inf\n");
	}
}

bool isPseudo(const std::string& str) {
    if (str == "-inff" || str == "+inff" || str == "nanf" ||
            str == "-inf" || str == "+inf" || str == "nan"){
        return true;
    }
    return false;
}


bool charliteral(const std::string& str){

    char c;

	if(str.length() == 1 && !std::isdigit(str[0])){
        c = str[0];
	}
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\''){
		c = str[1];
    }
	else
		return false;
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	printAllConversions(c, i, f, d, false);
	return true;

}


LiteralType detectNumericType(const std::string& str) {

	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;

	if (i == str.length())
		return INVALID;

	bool hasDot = false;
    bool hasDigits = false;

	while (i < str.length()) {
		if (str[i] == '.'){
			if (hasDot)
				return INVALID;
			hasDot = true;
		}
		else if (str[i] == 'f' && i == str.length() - 1) {
            return (hasDigits && hasDot) ? FLOAT : INVALID;
		}
		else if(!isdigit(static_cast<unsigned char>(str[i]))){
			return INVALID;
		}
		else
			hasDigits = true;
    	++i;
	}
	if (!hasDigits || str[str.length() - 1] == '.')
        return INVALID;

	return ((hasDot) ? DOUBLE : INT);
	

}


void ScalarConverter::convert(const std::string& string){
	
	size_t start = 0;
	while (start < string.length() && (string[start] == ' ' || string[start] == '\t'))
    start++;
		
	std::string str = string.substr(start);
	
	if (isPseudo(str)) {
		printPseudo(str);
		return;
	}
	if(charliteral(str)){
		return;
	}
		
	LiteralType type = detectNumericType(str);
	
	std::cout << std::fixed << std::setprecision(1); 
		
	if (type == INT) {
	    double val = std::strtod(str.c_str(), NULL);

	    // Check if it fits within standard int bounds
	    if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) {
	        // Int overflows: char and int are impossible
	        float f = static_cast<float>(val);
	        printAllConversions(f, f, f, val, false);
	        return;
	    }

	    int		i = static_cast<int>(val);
	    char   	c = static_cast<char>(i);
	    float  	f = static_cast<float>(i);
	    double 	d = static_cast<double>(i);

	    printAllConversions(c, i, f, d, false);
	    return;
    }

	std::cout.unsetf(std::ios::fixed);
	std::cout << std::setprecision(6);
		
    if (type == FLOAT){
		std::cout.unsetf(std::ios::fixed);
		std::cout << std::setprecision(6);
        std::string trim = str.substr(0, str.length() - 1);
        double temp = std::strtod(trim.c_str(), NULL);

        float  f = static_cast<float>(temp);
        char   c = static_cast<char>(f);
        int    i = static_cast<int>(f);
        double d = static_cast<double>(f);

        printAllConversions(c, i, f, d, false);
  
    }
	else if(type == DOUBLE){
		double d = std::strtod(str.c_str(), NULL);
		char  c = static_cast<char>(d);
		int   i = static_cast<int>(d);
		float f = static_cast<float>(d);

		printAllConversions(c, i, f, d, false);

	}
    else
        printAllConversions('\0', 0, 0.0f, 0.0, true);
}




ScalarConverter::ScalarConverter(){};
ScalarConverter::~ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter& other){
	(void)other;
};
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
	(void)other;
	return *this;
}

