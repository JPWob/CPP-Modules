#include "Zombie.hpp"
#include <vector>

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
	std::vector<Zombie*> allZombies;
	std::cout << "Nice, Give me all the names, then enter DONE to announce all Zombies\n";
	size_t i = 0;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while(1)
	{
		std::cout << "Name your Zombie:\n>>";
		if (!std::getline(std::cin, name) || name == "DONE")
        	break;
		if (name.empty())
        	continue;
		allZombies.push_back(Zombie::newZombie(name)); 
	}
	while(i < allZombies.size())
	{
		allZombies[i]->announce();
		delete allZombies[i];
		i++;
	}
	allZombies.clear();
	std::cout << "All done!\n";
}

int main ()
{
	char choice = 0;

	std::cout << "Choose zombie creation mode:\n"
	<< "[1] Create one zombie at a time and let it announce immediately.\n"
	<< "[2] Create multiple zombies first, then let them all announce.\n";
	while(choice != '1' && choice != '2')
	{
		std::cout << "Enter choice (1/2): \n>>";
		std::cin >> choice;
	}
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