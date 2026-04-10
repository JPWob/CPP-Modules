#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
    ClapTrap clap("Clap");
    ScavTrap scav("Scav");
    FragTrap frag("Frag");
    DiamondTrap dia("Diamond");
    std::cout << std::endl;

    clap.attack("Scav");
    clap.takeDamage(1);
    clap.beRepaired(10);
    scav.attack("Clap");
    clap.attack("Scav");
    frag.highFivesGuys();
    frag.attack("Clap");
    std::cout << std::endl;
    dia.attack("clap");
    dia.guardGate();
    dia.whoAmI();
    std::cout << std::endl;


    return (0);
}