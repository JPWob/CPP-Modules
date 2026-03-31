#include "HumanB.hpp"

HumanB::HumanB(std::string n) 
	: _name(n), _weapon(NULL){};

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

void HumanB::setWeapon(Weapon &w)
{
	_weapon = &w;
}