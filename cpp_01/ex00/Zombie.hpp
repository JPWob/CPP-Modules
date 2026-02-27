#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public :

	Zombie(std::string name);

	void	announce();
	//static means these functions belong to the class itself, not the individual object instance
	static Zombie* newZombie( std::string name );
	static void	randomChump( std::string name );

	private :
	
	std::string name;
};


#endif