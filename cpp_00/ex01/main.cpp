#include "PhoneBook.hpp"

int main()
{
	PhoneBook PhoneBook1;

	std::string line;

	while(1)
	{
		std::cout << ">> Enter: ADD, SEARCH or EXIT \n>>";
		std::getline(std::cin, line);
		if (!std::getline(std::cin, line))
        	break; //EOF
		if(line == "EXIT")
			break;
		else if(line == "ADD")
		{
			PhoneBook1.add();
		}
		else if(line == "SEARCH")
		{
			PhoneBook1.search();
		}
	}
	return (0);
}