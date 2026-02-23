#include "Contact.hpp"

//Decon and Con would happen automatically, only for learning purpose
Contact::~Contact() {} 
Contact::Contact() {}

void Contact::fill()
{
	firstname = getNonEmptyLine("First name: ");
	lastname = getNonEmptyLine("Last name: ");
	nickname = getNonEmptyLine("Nickname: ");
	phonenumber = getNonEmptyLine("Phone number: ");
	secret = getNonEmptyLine("Darkest secret: ");
}
	
void Contact::preview(int i)
{
	std::cout 
	<< "|"
	<< std::setw(10) << i
	<< "|" 
	<< std::setw(10) << format(firstname) 
	<< "|" 
	<< std::setw(10) << format(lastname)
	<< "|" 
	<< std::setw(10) << format(nickname)
	<< "|" << std::endl;
}

void Contact::show_full()
{
	std::cout <<
	firstname 	<< std::endl <<
	lastname 	<< std::endl <<
	nickname 	<< std::endl <<
	phonenumber << std::endl <<
	secret 		<< 
	std::endl;
}

