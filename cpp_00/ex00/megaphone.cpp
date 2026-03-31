#include <iostream>

int main(int argc, char *argv[])
{	

	// !!!! $>./megaphone "shhhhh... I think the students are asleep..."

    if (argc < 2)
	{
		std::cout << "Program expects string arguments\n";
		return;
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
}

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


// std::cout << "As char: " << line[i]  << std::endl;
// std::cout << "As int: " << static_cast<int>(line[i]) << std::endl;

