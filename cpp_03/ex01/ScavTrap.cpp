#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit = 100;
    this->_ep = 50;
    this->_attack = 20;
    std::cout << "ScavTrap " << _name << " constructed" << std::endl; 
}


ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << _name << " deconstructed." << std::endl; 
}

// Overriding the attack function
void ScavTrap::attack(const std::string& target) {
    if(_ep <= 0 || _hit <= 0)
        std::cout   << "ScavTrap " << _name << " is too weak to attack" << std::endl;
    else{
        std::cout   << "ScavTrap " << _name 
                    << " attacks with great force, causing " 
                    << target << " to take "
                    << _attack << " points of damage." << std::endl;
    }
}

void ScavTrap::guardGate(){
    std::cout   << "ScavTrap " << _name << " is now in gate keeper mode" << std::endl;
}