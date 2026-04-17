#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

// int main(){
//     ClapTrap clap("Clap");
//     ScavTrap scav("Scav");
//     FragTrap frag("Frag");
//     DiamondTrap dia("Diamond");
//     std::cout << std::endl;

//     clap.attack("Scav");
//     clap.takeDamage(1);
//     clap.beRepaired(10);
//     scav.attack("Clap");
//     clap.attack("Scav");
//     frag.highFivesGuys();
//     frag.attack("Clap");
//     std::cout << std::endl;
    
// 	dia.attack("clap");
//     dia.guardGate();
//     dia.whoAmI();
//     std::cout << std::endl;


//     return (0);
// }

//HP 100
//attack 30
//EP 50
//

int main() {
    std::cout << "--- DIAMONDTRAP CREATION ---" << std::endl;
    DiamondTrap dt("DIAMOND");
    std::cout << std::endl;

    std::cout << "--- IDENTITY CHECK ---" << std::endl;
    dt.whoAmI();
    std::cout << std::endl;

    std::cout << "--- STATS CHECK ---" << std::endl;
    // We call attack to see the Attack Damage (should be 30)
    // Note: This should use ScavTrap's attack style!
	std::cout << ">>> Should have 30 attackpoint like a FragTrap <<<" << std::endl;
    dt.attack("a training dummy");
	std::cout << std::endl;

    // We take damage and repair to verify Hit Points and Energy Points
    // If EP is 50, this should work. If it was 0 or 10, we'd run out fast.
	std::cout << ">>> Should start with 100 HP and 50 EP <<<" << std::endl;
    dt.beRepaired(10); 
	std::cout << std::endl;

    std::cout << "--- SPECIAL ABILITIES ---" << std::endl;
    dt.guardGate();     // From ScavTrap
    dt.highFivesGuys(); // From FragTrap
	std::cout << std::endl;

	std::cout << "--- ENERGY DEPLETION TEST ---" << std::endl;
	DiamondTrap burner("Burner");
	for (int i = 0; i < 50; i++) {
	    burner.attack("the air");
	}
	std::cout << ">>> The next attack should fail (0 EP) <<<" << std::endl;
	burner.attack("the air");
	std::cout << ">>> Healing should not be possible (0 EP) <<<" << std::endl;
	burner.beRepaired(1);
	std::cout << std::endl;

	std::cout << "--- POLYMORPHISM TEST ---" << std::endl;
	{
		ClapTrap* meta = new DiamondTrap("MetaRobot");
	
		// This should call ScavTrap::attack because it's virtual!
		meta->attack("the ceiling");
	
		// This will call ClapTrap's takeDamage/beRepaired
		meta->takeDamage(50);
		meta->beRepaired(20);
	
		// CRITICAL: This requires a virtual destructor in ClapTrap
		// to avoid memory leaks and ensure the whole Diamond chain is destroyed.
		delete meta;
	}
	std::cout << std::endl;

	std::cout << "--- COPY AND ASSIGNMENT TEST ---" << std::endl;
	{
	    DiamondTrap original("Original");
	    original.takeDamage(30); // HP should now be 70

	    std::cout << "\n--- Creating copy..." << std::endl;
	    DiamondTrap copy(original);
	    copy.whoAmI();
	    // Test if the copy also has 70 HP and the same names
	    copy.beRepaired(10); 

	    std::cout << "\n--- Testing Assignment Operator..." << std::endl;
	    DiamondTrap assignee("Temp");
		std::cout << std::endl;
	    assignee = original;
		std::cout << std::endl;
	    assignee.whoAmI();
		std::cout << std::endl;
	} // Objects destroyed here - check the logs!

    std::cout << "\n--- DESTRUCTION ORDER ---" << std::endl;
    return 0;
}