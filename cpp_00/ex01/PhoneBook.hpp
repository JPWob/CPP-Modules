#ifndef EX01_HPP
#define EX01_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook(); // custom constructor would be PhoneBook(int idx = 0, int cnt = 0) : index(idx), count(cnt) {}
	~PhoneBook(); //not necesary (implicitly-declared destructor from the C++ Standard Library rules of object lifetime)

	void add();
	void search();

	private:

	static const int max_contacts = 3;
	Contact contacts[max_contacts];
	int index;
	int count;
};

#endif