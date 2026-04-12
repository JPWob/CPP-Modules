#include "Zombie.hpp"

int main ()
{
	int N = 10;
	std::string name = "Oger";
	Zombie *horde;

	horde = zombieHorde(N, name);
	int i = 0;
	while( i < N )
	{
		std::cout << "Zombie " << i + 1 << std::endl;
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return 0;
}



// while( i < N )
// {
// std::cout << "Testing for continuos allocation:\n";
// 	std::cout << "horde[" << i + 1 << "] : ";
// 	std::cout << &horde[i] << std::endl;
// 	i++;
// }
/*
std::vector
	-It’s a dynamic array, that can grow or shrink at runtime.
*/