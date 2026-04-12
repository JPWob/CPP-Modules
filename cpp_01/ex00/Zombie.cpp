#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::Zombie(std::string n) : _name(n) {}

Zombie::~Zombie(){
	std::cout << _name << " Zombie destructed" << std::endl; 
}

void Zombie::announce(){
	std::cout << _name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}
