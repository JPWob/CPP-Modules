#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap \"" << _name << "\" asks for a friendly HighFive" << std::endl; 
}

FragTrap::FragTrap() : ClapTrap() {
	this->_hit = 100;
	this->_ep = 100;
	this->_attack = 30;
	std::cout << "FragTrap \"" << _name << "\" constructed" << std::endl; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hit = 100;
	this->_ep = 100;
	this->_attack = 30;
	std::cout << "FragTrap \"" << _name << "\" constructed" << std::endl; 

}
FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src){
	std::cout << "FragTrap \"" << _name << "\" Copy Constructor called" << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap& src){
	std::cout << "FragTrap \"" << _name << "\" Copy Assignment Operator called" << std::endl;
	if (this != &src) {
		ClapTrap::operator=(src);
	}
	return *this;
}


FragTrap::~FragTrap(){
    std::cout << "FragTrap \"" << _name << "\" destructed" << std::endl; 
}



