#include "Zombie.hpp"
#include <vector>
#include <limits>

void ZombieMode1()
{
	std::string name;

	std::cout << "Good. One Zombie at a time\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while(1)
	{
		std::cout << "Name your Zombie:\n>>";
		if (!std::getline(std::cin, name) || name == "DONE")
        	break;
		if (name.empty())
        	continue;
		Zombie::randomChump(name);
	}
	std::cout << "All done!\n";
}

void ZombieMode2()
{
	std::string name;
	size_t		i = 0;
	Zombie 		**HeapZombie = new Zombie* [10]; //allocating array of 10 pointers, no zombies exist yet
	
	std::cout << "Nice. Name up to 10 Zombies as you like.\nEnter DONE to announce all Zombies\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while(i < 10)
	{
		std::cout << "Name your Zombie:\n>>";
		if (!std::getline(std::cin, name) || name == "DONE")
        	break;
		if (name.empty())
        	continue;
		HeapZombie[i] = Zombie::newZombie(name); //returns pointer to Zombie
		i++;
	}
	i = 0;
	while(HeapZombie[i])
	{
		HeapZombie[i]->announce();
		delete HeapZombie[i];
		i++;
	}
	delete[] HeapZombie;
	std::cout << "All done!\n";
}

int main ()
{
	char choice = 0;

	std::cout << "Choose zombie creation mode:\n"
	<< "[1] Create one zombie at a time and let it announce immediately (Stack allocation).\n"
	<< "[2] Create multiple zombies first, then let them all announce (Heap allocation).\n";
	while(choice != '1' && choice != '2')
	{
		std::cout << "Enter choice (1/2): \n>>";
		std::cin >> choice;
	}
	if (!choice)
        return(0); //EOF
	if(choice == '1')
		ZombieMode1();
	else	
		ZombieMode2();

	return 0;
}



/*
std::vector
	-It’s a dynamic array, that can grow or shrink at runtime.
*/