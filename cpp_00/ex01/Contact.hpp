#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "utils.hpp"


class Contact
{
	public:

	Contact(); //automatically generated default constructor by c++ standard when compiling
	~Contact(); //automatically generated default deconstructor by c++ standard when compiling
	
	
	void fill();
	void preview(int i);
	void show_full();

	private:

	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string secret;

};

#endif
