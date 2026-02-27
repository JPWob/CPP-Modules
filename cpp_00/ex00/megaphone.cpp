#include <iostream>

int main()
{
    std::string line;
    std::getline(std::cin, line);

    for (size_t i = 0; i < line.size(); ++i)
    {
        line[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(line[i])));
        /*
        std::toupper
            - expects an int that is either EOF or in the range 0–255 = unsigned
            = is undefined behavior if char is signed and negative.
                -> unsigned: Converts the signed char to its correct positive value (0–255).
            - returns an int (usually 4 bytes).
        static_cast<char>
            -Casting back to char is good for poratbility.
            -static_cast is a C++ type cast operator, completely different than "static char"
        */
    }
    std::cout << line << std::endl;
}

// std::cout << "As char: " << line[i];
// std::cout << " As int: " << static_cast<int>(line[i]) << std::endl;

