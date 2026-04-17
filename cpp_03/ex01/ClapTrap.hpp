#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap{
protected:						//protected, so derived classes can access attributes
    std::string _name;
    int _hit;
    int _ep;
    int _attack;

public:
	ClapTrap();
    ClapTrap(std::string name);
	ClapTrap(const ClapTrap& src);
	ClapTrap& operator=(const ClapTrap& src);
    virtual ~ClapTrap(); 		//Adding 'virtual' here ensures the most derived destructor is called first

    virtual void attack(const std::string& target);		//Adding 'virtual' here ensures the most derived attack() is called first
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif

/* Virtual in Functions 
// virtual void attack() or Destructors
>>
This tells the compiler: Use the most derived Version of this function:
"If a child class has its own version of this function, use the child's 
version—even if I'm looking at the object through a parent's pointer."

What it fixes: 
>>>It ensures that if you have a 
	ClapTrap* ptr = new ScavTrap(); 
	calling ptr->attack() runs the ScavTrap version, not the base ClapTrap version.
>>>It ensures the most derived Destructor is called first

*/
