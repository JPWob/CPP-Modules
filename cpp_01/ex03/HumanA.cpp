#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << name << "attacks with their" << WeaponA.getType() << endl;
}