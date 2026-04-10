#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    // Overriding the attack function
    void attack(const std::string& target);
    void guardGate();
};

#endif
