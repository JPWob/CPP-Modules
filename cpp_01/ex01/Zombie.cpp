#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed"){};

Zombie::Zombie(std::string n) : _name(n) {}

Zombie::~Zombie(){
	std::cout << _name << " Zombie destructed" << std::endl; 
}

void Zombie::announce(){
	std::cout << _name << ": BraiiiiiiinnnzzzZ..."<< std::endl; // (this->name)
}

void	Zombie::set_name(std::string name){
	this->_name = name;
}
