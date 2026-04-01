#include <iostream>

int main(int argc, char *argv[])
{	

    if (argc < 2)
	{
		std::cout << "Program expects string arguments\n";
			return(1);
	}

	for (int j = 1; argv[j]; ++j)
	{
		std::string str = argv[j];
		for (size_t i = 0; i < str.size(); ++i)
		{
			str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
		}
		std::cout << str << " ";
		
	}
	std::cout << std::endl;
	return(0);
}

// std::cout << "As char: " << line[i]  << std::endl;					//print char
// std::cout << "As int: " << static_cast<int>(line[i]) << std::endl;	//print int
/*

💡int std::toupper(char c)
	- It returns an int representing:
		a) Either the uppercase version of the character, or
		b) The original value if no conversion is possible (eg '!')
	- Expects an int that is either EOF or in the range 0–255 = unsigned
	❌ has undefined behavior if char > 255 (signed) or negative.
		👉 Solution: Good practice:  cast c to unsigned char:
		-> <unsigned char> Converts the (signed) char to its correct positive value (0–255).

💡Explanation why casting is good for portability
-Normally c is unsigned with a range 0 - 255.
-Casting c to unsigned is good for portability for system with char = signed (range: -128 to 127)
-Example for a system with signed char
	- Imagine you read a byte with value 200 (e.g., from a file or UTF-8 text)
	- char c = 200
	- Because char is signed: 200 → wraps to → -56 automatically
	- So std::cout << (int)c;   // prints: -56
	- std::toupper(c) = std::toupper(-56) ❌ Invalid! undefined behavior
	- ✅ std::toupper(static_cast<unsigned char>(c)); 
		- c (-56) → cast → unsigned char (200)
		- toupper receives a valid value (0–255)

💡C++ style cast: STATIC_CAST is most common for variables. it tells you:
	-> This is a value conversion
	-> Its safe: No tricks (no const removal, no pointer hacking)

⚠️ Avoid C style casting!

	❌(unsigned char)c				// C-style cast (works, but dangerous, less explicit)
	👉static_cast<unsigned char>c	 // C++ cast (safe, preferred)

	const int *p = w;

(int*)w;


	.

*/



