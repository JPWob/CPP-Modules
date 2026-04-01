#include "PhoneBook.hpp"


PhoneBook::PhoneBook(): _index(0), _count(0) {} // // custom constructor would be PhoneBook(int idx = 0, int cnt = 0) : _index(idx), _count(cnt) {}
PhoneBook::~PhoneBook() {} //Decons defiened automatically, only for learning purpose

void PhoneBook::add()
{
	if (_index >= _max_contacts)  //overwrite from beginning if Book is full
		_index = 0;
	contacts[_index].fill();
	_index++;					 //move index for next add() functinon call
	if (_count < _max_contacts)  //
		_count++;
}

void PhoneBook::search()
{
	int i = 0;
	std::string line;

	if (_count == 0)
	{
		std::cout << "PhoneBook has no entries" << std::endl;
		return;
	}

	while(i < _count)
	{
		contacts[i].preview(i);
		i++;
	}

	std::cout << "Enter contact index for more detail\n>> ";
	while(1) // run until user gives valid index; show corresponding contact in full
	{
		if (!std::getline(std::cin, line))
            return; // handle EOF safely,ends program
		if (line.length() == 1 && std::isdigit(static_cast<unsigned char>(line[0]))) //line has to be 1 character (0-8), has to be digit,
		{
			i = line[0] - '0'; //convert char to int
			if(i < _count)//needs to be within count
			{
				contacts[i].show_full();
				return;
			}
		}
		std::cout << "Enter valid index (0 to " << _count - 1 << ")\n>>";
	}
}
