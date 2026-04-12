#include "Zombie.hpp"
#include <limits>

void StackZombie()
{
	std::string name;

	std::cout << "Good. One Zombie at a time\n";
	while(1)
	{
		std::cout << "Name your Zombie (or \"DONE\" if you are done): \n>>";
		if (!std::getline(std::cin, name) || name == "DONE")
        	break;
		if (name.empty())
        	continue;
		randomChump(name);
	}
	std::cout << "All done!\n";
}

void HeapZombie()
{
	std::string name;
	Zombie** 	horde = new Zombie*[10]; //allocating array of 10 pointers, no zombies exist yet
	
	std::cout << "Nice. Name up to 10 Zombies as you like.\nEnter DONE to announce all Zombies\n";
	int i = 0;
	while (i < 10)
	{
	    std::cout << "Name your Zombie:\n>>";
	    if (!std::getline(std::cin, name) || name == "DONE")
	        break;

	    if (name.empty())
	        continue; // Jumps to the top. 'i' is NOT incremented.

	    horde[i] = newZombie(name); 
	    i++; // This only happens if we didn't 'continue' or 'break'
	}
	int count = i;
	int j;
	for(j = 0; j < count; j++)
		horde[j]->announce();
	for(j = 0; j < count; j++)
		delete horde[j];
	delete[] horde;
	std::cout << std::endl;
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
		if (!(std::cin >> choice)) return 0; // Handle Ctrl+D
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer
	if(choice == '1')
		StackZombie();
	else	
		HeapZombie();

	return 0;
}



/*
Looping: for vs. while (Horde)

	for(i = 0; i < 10; i++)
In your for loop version, if I press Enter10 times (empty name):
- the loop ends
- i is 10, but zero zombies were actually created. 
Your cleanup loop at the bottom would then try to delete 10 garbage pointers and cause a Segmention Fault.

	int i = 0;
	while (i < 10)
In the while loop version, if I press Enter 10 times:
- I'm still at i = 0, 
- and the program is still waiting for me to provide a valid name for the very first slot!

Pro-tip: When the logic of "when to move to the next item" depends on user input, 
a while loop is almost always cleaner than a for loop.

*/


//Info ++++Heap Zombie Mode++++ 
//Object vs Pointer Array

/*
With an Object Array (Zombie*):

	Zombie horde[10] 				(Stack) (Creating Class Objects on Stack can be memory Problem!)
	Zombie* horde = new Zombie[x]   (Heap)

All 10 zombies are "born" in that the moment because the Default Constructor Called is called.
== If User just names 2 Zombies, You have 8 "ghost" zombies sitting in memory 
   taking up space and running their constructors for no reason.


With a Pointer Array (Zombie**): 

	Zombie* horde[10];					(Stack)
	Zombie** horde = new Zombie*[x]; 	(Heap)

You only created 10 "parking spots" (pointers). 
If the user types "DONE" after 2 zombies, you only ever call 2x new Zombie . 
The other 8 spots stay as NULL. You save the overhead of 8 full Zombie objects.

Zombie** horde = new Zombie*[10]; 
-> Is a heap allocated Array of Pointer

-> Better Practice:  The "Hybrid" Approach (Stack Array of Heap Pointers)
	- In Professional C++, we usually try to keep the "container" (the array of pointers) 
	  on the stack and only put the "heavy" data (the actual Zombies) on the heap.
	- Instead of 
		X 		Zombie** horde = new Zombie*[10] 
		Y 		Zombie* horde[10]   				//or even Zombie* horde[10]{nullptr} in C11

		-->stack array of 10 zombie size Pointers
		-->no Zombies created yet
		-->Zombie creation: horde[i] = new Zombie(name(optional));
*/

