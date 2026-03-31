#include "HumanA.hpp"

HumanA::HumanA(const std::string& n, Weapon& w) 
    : _name(n), _weaponA(w)  {} //private_member(parameter)

void HumanA::attack()
{
    std::cout   << _name << " attacks with their " 
                << _weaponA.getType() 
                << std::endl;
}


/*

You cannot create a HumanA without passing a Weapon.
        == A HumanA will always have a weapon.
*/