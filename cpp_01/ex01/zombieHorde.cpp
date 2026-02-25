#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	int i = 0;
	if (N <= 0)
		return nullptr;

	Zombie *horde = new Zombie[10];
	while(i < N)
	{
		horde[i].name = name;
		i++;
	}
	return horde;
}