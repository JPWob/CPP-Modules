#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private :
	std::string _name; //non static member object

	public :
	Zombie();
	Zombie(std::string name);

	void	announce();
	void	set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name ); //zombieHorde() does not depend on an existing zombie.

#endif


/*

A static function has no this pointer, so it cannot access name.
Therefore, announce() must be non-static.


Final Answer

announce() is not static because:

	-It uses the member variable name
	-It requires a this pointer
	-It represents behavior of a specific object
	-Static functions cannot access non-static members

*/