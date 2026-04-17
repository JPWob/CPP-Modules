#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){

    std::cout << "--- 1. BASIC INSTANTIATION ---" << std::endl;
    {
        FragTrap frag("Fraggy");
        frag.attack("Target");
        frag.takeDamage(30);
        frag.beRepaired(20);
        frag.highFivesGuys();
    } // Check destruction order here
	std::cout << std::endl;

    std::cout << "\n--- 2. VIRTUAL POINTER TEST ---" << std::endl;
    {
        // Pointing to a FragTrap using a ClapTrap pointer
        ClapTrap* poly = new FragTrap("PtrFrag");

        // Should use ClapTrap's attack (since FragTrap doesn't override it)
        // but with FragTrap's 30 attack damage.
        poly->attack("The World");
        
        poly->takeDamage(50);
        
       //poly->highFivesGuys(); // THIS WOULD FAIL TO COMPILE (ClapTrap doesn't know highFives)
        
        delete poly; // Checks virtual destructor
    }
	std::cout << std::endl;

    std::cout << "\n--- 3. COPY AND ASSIGNMENT ---" << std::endl;
    {
        FragTrap a("Original");
		std::cout << std::endl;

        FragTrap b(a);        // Copy Constructor
		b.attack("target");
		std::cout << std::endl;

        FragTrap c("Temp");
        c = b;               // Assignment Operator

        c.highFivesGuys();
		std::cout << std::endl;
    }

    return 0;
}