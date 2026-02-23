#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public :

	Zombie(std::string name);

	void	announce();
	static Zombie* newZombie( std::string name );
	static void	randomChump( std::string name );

	private :
	
	std::string name;
};


#endif