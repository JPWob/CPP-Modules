#ifndef EX01_HPP
#define EX01_HPP

#include "Contact.hpp"

class PhoneBook
{

private:

	static const int _max_contacts = 3;
	Contact contacts[_max_contacts];
	int _index;
	int _count;  //count necesary, because of overwriting mechanism with index

public:

	PhoneBook(); //initialize index and count
	~PhoneBook(); //not necesary (implicitly-declared destructor from the C++ Standard Library rules of object lifetime)

	void add();
	void search();

};

#endif