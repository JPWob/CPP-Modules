#include "Scalar.hpp"

int main(){
    std::string str = "t";

    ScalarConverter::convert(str);
    ScalarConverter::convert("42.1234567890123");
    ScalarConverter::convert("3.33f");
    ScalarConverter::convert("5.7f864f");
    ScalarConverter::convert("   2147483647");
    ScalarConverter::convert("   2147483648");
}


/*
A float has 32 bits of precision (about 7 decimal digits)
A double has 64 bits (about 15–17 decimal digits).

e.g. str = 42.1234567890123;

If you force std::setprecision(1);
both your float and double outputs will display 42.1


*/