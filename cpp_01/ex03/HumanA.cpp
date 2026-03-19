#include "HumanA.hpp"

HumanA::HumanA(Weapon& w, const std::string& n) 
    : _weaponA(w), _name(n) {} //private_member(parameter)

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