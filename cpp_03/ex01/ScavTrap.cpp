#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src){
	std::cout << "Scav Trap \"" << _name << "\" Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src){
	std::cout << "ScavTrap \"" << _name << "\" Copy assignment operator called" << std::endl;
	if (this != &src) {
		ClapTrap::operator=(src); 
    }
	return(*this);
}

ScavTrap::ScavTrap() : ClapTrap(){			// : ClapTrap is good practice
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->_hit = 100; 		//overwrite the ClapTrap defaults
    this->_ep = 50;
    this->_attack = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit = 100;
    this->_ep = 50;
    this->_attack = 20;
    std::cout << "ScavTrap \"" << _name << "\" constructed" << std::endl; 
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap \"" << _name << "\" deconstructed." << std::endl; 
}

// Overriding the attack function
void ScavTrap::attack(const std::string& target) {
    if(_ep <= 0 || _hit <= 0)
        std::cout   << "ScavTrap " << _name << " is too weak to attack" << std::endl;
    else{
		_ep--;
        std::cout   << "ScavTrap \"" << _name 
                    << "\" attacks with great force, causing \"" 
                    << target << "\" to take "
                    << _attack << " points of damage." << std::endl;
    }
}

void ScavTrap::guardGate(){
    std::cout   << "ScavTrap \"" << _name << "\" is now in gate keeper mode" << std::endl;
}