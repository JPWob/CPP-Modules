#include "HumanB.hpp"

HumanB::HumanB(std::string n, Weapon* w) 
	: _weapon(w), _name(n) {};

void HumanB::attack()
{
	if(!_weapon)
	{
		std::cout 	<< _name 
					<< " attacks with their bare hands"
					<< std::endl;
	}
	else
	{
		std::cout 	<< _name 
					<< " attacks with their "
					<< _weapon->getType() 
					<< std::endl;
	}
}

void HumanB::set_weapon(std::string name)
{
	Weapon w(name);

	_weapon = &w;
}