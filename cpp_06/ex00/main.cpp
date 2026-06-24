#include "Scalar.hpp"
#include <limits>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
        return 1; // Return an error code
    }
    ScalarConverter::convert(argv[1]);
    // ScalarConverter::convert("42.1234567890123");
    // ScalarConverter::convert("3.33f");
    // ScalarConverter::convert("5.7f864f");
    // ScalarConverter::convert("   2147483647");
    // ScalarConverter::convert("   2147483648");

    // float f = -std::numeric_limits<float>::infinity();
    // std::cout << f << std::endl;
    // std::cout << static_cast<double>(f) << std::endl;
    //float ff = +std::numeric_limits<float>::infinity();
   // double d = -std::numeric_limits<double>::infinity();
   // float dd = +std::numeric_limits<double>::infinity();
   
}


/*
A float has 32 bits of precision (about 7 decimal digits)
A double has 64 bits (about 15–17 decimal digits).

e.g. str = 42.1234567890123;

If you force std::setprecision(1);
both your float and double outputs will display 42.1


*/