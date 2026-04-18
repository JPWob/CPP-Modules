#include "ClapTrap.hpp"

/*General:
Attacking and repairingeach cost 1 energy point. 
Of course, ClapTrap can’t do anything if it has no hit points or energy points left. 

However, since these exercises serve as an introduction, 
the ClapTrap instances should not interact directly with one another, 
and the parameters will not refer to another instance of ClapTrap.
*/

//When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
//Cost: 1 ep
void ClapTrap::attack(const std::string& target){
    if(_ep <= 0 || _hit <= 0)
        std::cout   << "ClapTrap \"" << _name << "\" is too weak to attack" << std::endl;
    else{
		_ep--;
        std::cout   << "ClapTrap \"" << _name 
                    << "\" attacks \"" << target
                    << "\", causing " << _attack << " points of damage." << std::endl;
    }
}

//When ClapTrap repairs itself, it regains <amount> hit points. 
//Cost: 1 ep
void ClapTrap::beRepaired(unsigned int amount){
	if (_ep > 0 && _hit > 0) {
		_ep--;
	    _hit += amount;
	    std::cout   << "ClapTrap \"" << _name 
		<< "\" uses 1 EP to repair itself by " << amount
		<< " HP. Now " << _hit << " HP left." << std::endl;
	}
	else{
		std::cout   << "ClapTrap \"" << _name 
		<< "\" cannot repair itself (No EP or HP left)" << std::endl;
	}
	
}

void ClapTrap::takeDamage(unsigned int amount){
	_hit -= amount;
	if(_hit < 0)
		_hit = 0;
	std::cout   << "ClapTrap \"" << _name 
				<< "\" has taken " << amount
				<< " damage: " << _hit << " HP left." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	std::cout << "ClapTrap Copy Constructor from src \"" << src._name << "\" called" << std::endl;
	this->_name = src._name;
	this->_ep = src._ep;
	this->_hit = src._hit;
	this->_attack = src._attack;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src){
	std::cout << "ClapTrap Copy Assignment operator for \"" << _name << "\" called."
	<< " Making Copy from src \"" << src._name << "\""  << std::endl;
	if(this != &src){
		_name = src._name;
		_ep = src._ep;
		_hit = src._hit;
		_attack = src._attack;
	}
	return(*this);
}

ClapTrap::ClapTrap() : _name("Default"), _hit(10), _ep(10), _attack(0){
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _ep(10), _attack(0){
    std::cout << "ClapTrap Constructor for \"" << _name << "\" called" << std::endl;
};


ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor for \"" << _name << "\" called" << std::endl;
}