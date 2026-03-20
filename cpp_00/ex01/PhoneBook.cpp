#include "PhoneBook.hpp"

//Decon would happen automatically, only for learning purpose
PhoneBook::PhoneBook(): index(0), count(0) {}
PhoneBook::~PhoneBook() {} 

void PhoneBook::add()
{
	if (index >= max_contacts)
		index = 0;
	contacts[index].fill();
	index++;
	if (count < max_contacts)
		count++;
}

void PhoneBook::search()
{
	int index = 0;
	if (count == 0)
	{
		std::cout << "PhoneBook has no entries" << std::endl;
		return;
	}
	while(index < count)
	{
		contacts[index].preview(index);
		index++;
	}
	std::cout << "Enter contact index for more detail " << std::endl;
	std::string line;
	while(1)
	{
		std::getline(std::cin, line);
		index = line[0] - '0';
		if(line.length() == 1 && std::isdigit(line[0]) && index < count)
		{
			contacts[index].show_full();
			break;
		}
		else
			std::cout << "Enter valid index (0 to " << count - 1 << ')' << std::endl;
	}
}
