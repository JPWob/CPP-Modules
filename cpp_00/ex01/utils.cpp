#include "utils.hpp"

std::string getNonEmptyLine(const std::string &prompt)
{
	std::string line;

	while(1)
	{
		std::cout << prompt,
		std::getline(std::cin, line);
		if(!line.empty())
			break;
		std::cout << "Input can not be empty. Try again:" << std::endl;
	}
	return (line);
}

std::string format(std::string str)
{
	if( str.length() > 10)
		return (str.substr(0, 9) + '.' );
	else
		return (str.substr(0, 10));
}
