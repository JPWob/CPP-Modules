#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap{
protected:
    std::string _name;
    int _hit;
    int _ep;
    int _attack;

public:
    ClapTrap(std::string name);
    virtual ~ClapTrap(); // Adding 'virtual' here ensures the most derived destructor is called first
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif

/*
When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it regains <amount> hit points. 
Attacking and repairingeach cost 1 energy point. 
Of course, ClapTrap can’t do anything if it has no hit points or energy points left. 

However, since these exercises serve as an introduction, 
the ClapTrap instances should not interact directly with one another, 
and the parameters will not refer to another instance of ClapTrap.
*/