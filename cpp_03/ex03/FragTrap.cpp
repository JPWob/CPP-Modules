#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hit = 100;
    this->_ep = 100;
    this->_attack = 30;
    std::cout << "FragTrap " << _name << " constructed" << std::endl; 

}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << _name << " destructed" << std::endl; 
}

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << _name << " asks for a friendly HighFive" << std::endl; 

}

