#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:
	ScavTrap();
    ~ScavTrap();
	ScavTrap(const ScavTrap& src);
	ScavTrap& operator=(const ScavTrap& src);
    ScavTrap(std::string name);

    // Overriding the attack function
    void attack(const std::string& target);
    void guardGate();
};

/*
-----------------------------------------------------------

Virtual Inheritance
->Virtual public ClapTrapin for Frag and Scav Trap:

>>> Use virtual when you want to prevent a future child from this class having duplicate grandparents.

>> Virtual tells compiler that the Parent of this Class can be shared with someone else (who is willing to share)

>> Compiler: I will allocate exactly one memory space for the ClapTrap variables (_name, _hit, _ep, _attack)

-----------------------------------------------------------

Virtual in Functions 
->virtual void attack() or Destructors

>>This tells the compiler: Use the most derived Version of this function:
"If a child class has its own version of this function, use the child's 
version—even if I'm looking at the object through a parent's pointer."

What it fixes: 
>>> It ensures that if you have a 
	ClapTrap* ptr = new ScavTrap(); 
	calling ptr->attack() runs the ScavTrap version, not the base ClapTrap version.
>>> It ensures the most derived Destructor is called first

-----------------------------------------------------------
*/


#endif
