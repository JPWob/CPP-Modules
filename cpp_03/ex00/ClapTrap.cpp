#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target){
    if(_ep <= 0 || _hit <= 0)
        std::cout   << "ClapTrap " << _name << " is too weak to attack" << std::endl;
    else{
        std::cout   << "ClapTrap " << _name 
                    << " attacks " << target
                    << ", causing " << _attack << " points of damage." << std::endl;
    }
}


void ClapTrap::takeDamage(unsigned int amount){
    _hit -= amount;
    std::cout   << "ClapTrap " << _name 
                << " has taken " << amount
                << " damage: " << _hit << " hitpoints left." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
    _ep--;
    _hit += amount;
    std::cout   << "ClapTrap " << _name 
                << " uses 1 EP to repair itself by " << amount
                << " points: " << _hit << " hitpoints left." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _ep(10), _attack(0){
    std::cout << "ClapTrap Constructor called" << std::endl;
};

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
}