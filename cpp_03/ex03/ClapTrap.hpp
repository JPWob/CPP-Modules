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
    virtual ~ClapTrap(); 		//Adding 'virtual' here ensures the most derived destructor is called first
	ClapTrap(const ClapTrap& src);
	ClapTrap& operator=(const ClapTrap& src);
    ClapTrap(std::string name);

    virtual void attack(const std::string& target);		//Adding 'virtual' here ensures the most derived attack() is called first
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif