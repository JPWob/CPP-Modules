#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(std::string n) : _name(n) {}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..."<< std::endl; // (this->name)
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}
