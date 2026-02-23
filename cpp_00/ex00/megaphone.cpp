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

/*

C++ introduces references to allow safe aliasing of memory.
    char &c = s[i];

Use references (&) when:
    -You want a safe alias to an existing object
    -No need for pointer syntax (*)
    -Guaranteed to never be null
    -Cannot be rebound to another object
    int x = 42;
    int &r = x;  // r is a reference to x
    r = 99;      // modifies x directly, note how it is automatically dereferenced
    r is not a new variable — it’s just another name for x.
    int &r2;     // ❌ ERROR: cannot declare a reference without binding

In C, aliasing is manual and requires pointers. Mistakes are easy: 
dangling pointers, accidental modification, or undefined behavior from misused memory.

Pointers still exist in c++.
| Feature                           | Pointer (`int* p`) | Reference (`int &r`)            |
| --------------------------------- | ------------------ | ------------------------------- |
| Syntax to access value            | `*p`               | `r`                             |
| Can be null?                      | Yes                | No                              |
| Can be rebound to another object? | Yes                | No (fixed after initialization) |
| Aliases memory?                   | Yes                | Yes                             |
| Safer / less error-prone?         | Less               | More                            |

User Input 
Numbers / tokens → std::cin >>
Full lines → std::getline

Multiple values
int a, b;
std::cin >> a >> b;
input like: 10 20

Reading a string (single word)
std::string name;
std::cin >> name;
std::cout << "Hello " << name << std::endl;

Reading a full line (with spaces)
std::string line;
std::getline(std::cin, line);
std::cout << line << std::endl;

Common pitfall: cin before getline

*/