#include "Scalar.hpp"
#include <limits>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
        return 1; // Return an error code
    }
    ScalarConverter::convert(argv[1]);
	std::cout << std::endl << "3.33f" << std::endl;
    ScalarConverter::convert("3.33f");
	std::cout << std::endl <<"5.7f864f" << std::endl ;
    ScalarConverter::convert("5.7f864f");
	std::cout << std::endl << "   2147483647" << std::endl;
    ScalarConverter::convert("   2147483647");
	std::cout << std::endl << "   2147483648" << std::endl;
    ScalarConverter::convert("   2147483648");
	std::cout << std::endl << "42" << std::endl;
    ScalarConverter::convert("42");
	std::cout << std::endl << "42.1234567890123" << std::endl;
    ScalarConverter::convert("42.1234567890123");
	
}


/*
A float has 32 bits of precision (about 7 decimal digits)
A double has 64 bits (about 15–17 decimal digits).

e.g. str = 42.1234567890123;

If you force std::setprecision(1);
both your float and double outputs will display 42.1


*/