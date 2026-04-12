#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie random(name);
	random.announce();
	return;
}

//This object only exists within the scope of the function