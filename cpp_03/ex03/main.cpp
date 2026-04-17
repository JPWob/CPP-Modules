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
    dt.attack("a training dummy");

    // We take damage and repair to verify Hit Points and Energy Points
    // If EP is 50, this should work. If it was 0 or 10, we'd run out fast.
    dt.beRepaired(10); 
    dt.takeDamage(105); // Should just barely 'kill' it if HP is 100
    dt.beRepaired(10);  // Should fail if dead

    std::cout << std::endl;
    std::cout << "--- SPECIAL ABILITIES ---" << std::endl;
    dt.guardGate();     // From ScavTrap
    dt.highFivesGuys(); // From FragTrap

    std::cout << "\n--- DESTRUCTION ORDER ---" << std::endl;
    // Watch the terminal here: 
    // It should go Diamond -> Scav/Frag -> Clap
    return 0;
}