#include "utils.hpp"

std::string getNonEmptyLine(const std::string &prompt)
{
	std::string line;

	while(1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, line)) //Handle EOF
    		exit(EXIT_FAILURE);
		if(line.empty()) //Handle if user just presses enter
			std::cout << "Input can not be empty. Try again:" << std::endl;
		else
			return (line);
	}
}

std::string format(std::string str)
{
	if( str.length() > 10)		//If string is longer than 10
		return (str.substr(0, 9) + '.' );
	else
		return (str);
}


/*

⚠️ Empty line ≠ EOF

	if (!line.empty())	-> only checks if the user pressed ENTER without typing anything.

	When EOF happens (Ctrl+D / Ctrl+Z) = getline: FAILS!. To handle false return value
	👉 if (!std::getline(std::cin, line))
    	return;

*/