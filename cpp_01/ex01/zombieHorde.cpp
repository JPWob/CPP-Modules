#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i = 0;
	if (N <= 0)
		return NULL;

	Zombie *horde = new Zombie[N]; // C++ runs the Zombie() constructor N times. //Heap Objet Array
	while(i < N)
	{
		horde[i].set_name(name); //access member variable name through real object instances (horde[i])
		i++;
	}
	return horde;
}

/*
__________The Object Array (Zombie*) vs. The Pointer Array (Zombie**) ______

1.____________
The Object Array (Zombie*)

In many other languages, an "array of objects" is actually an array of references (pointers) to objects,
scattered all over the place. In C++, when you create an object array, the objects are laid out contiguously in memory.

On the Stack
	- Zombie horde[10]; // Fixed size, deleted automatically when function ends. Needs specific number


On the Heap
	- Zombie* horde = new Zombie[N];
	-> Dynamic size, You can decide how many "slots" you need at runtime
	-> lives until you delete[] it.
	-> new Zombie[N] = Creates N "bodies" instantly. Needs default Construtcor (Zombie()). (In standard C++, it is impossible to use the new[] syntax without a default constructor)

2.____________
The Pointer Array (Zombie**)

In this structure, you aren't creating a row of "bodies" (objects); 
you are creating a row of parking spots (pointers). Each spot holds 
a memory address that points to a Zombie living somewhere else on the Heap.

On the Stack
	- Zombie* horde[10]; 
	-> A fixed-size array of 10 pointers.
	-> Each pointer starts with "garbage" memory unless you set them to NULL.
	-> Cleanup: The array of pointers is deleted automatically, 
	   but any Zombies you new-ed into those spots must be deleteed manually before the function ends.

On the Heap
	-Zombie** horde = new Zombie*[N];
	-> Dynamic Size: You can decide how many "slots" you need at runtime.
	-> lives until you delete[] it.
	-> Two-Step Creation:
		1. new Zombie*[N] creates N empty pointers (parking spots).
		2. You must then loop through and use horde[i] = new Zombie("Name") to actually put a Zombie in each spot.
	-> Complex Cleanup:
		1. Loop through and delete each individual Zombie: delete horde[i];
		2. Then delete[] the array of pointers: delete[] horde;
*/



