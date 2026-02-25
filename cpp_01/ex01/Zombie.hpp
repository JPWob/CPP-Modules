#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public :

	Zombie();
	Zombie(std::string name);

	void	announce();
	static Zombie* zombieHorde( int N, std::string name );

	private :
	
	std::string name;
};


#endif