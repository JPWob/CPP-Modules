#include "Zombie.hpp"

int main ()
{
	int N = 10;
	std::string name = "Oger";
	Zombie *horde;

	horde = Zombie::zombieHorde(N, name);
	int i = 0;
	while( i < N )
	{
		std::cout << "Zombie " << i + 1 << std::endl;
		horde[i].announce();
		i++;
	}
	i = 0;
	std::cout << "Testing for continuos allocation:\n";
	while( i < N )
	{
		std::cout << "horde[" << i + 1 << "] : ";
		std::cout << &horde[i] << std::endl;
		i++;
	}
	delete[] horde;
	

	return 0;
}



/*
std::vector
	-It’s a dynamic array, that can grow or shrink at runtime.
*/