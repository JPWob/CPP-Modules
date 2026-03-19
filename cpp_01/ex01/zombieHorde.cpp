#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	int i = 0;
	if (N <= 0)
		return nullptr;

	Zombie *horde = new Zombie[N];
	while(i < N)
	{
		horde[i].name = name;  //access member variable name through real object instances (horde[i])
		i++;
	}
	return horde;
}