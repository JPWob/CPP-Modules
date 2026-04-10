#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    ClapTrap clap("Clap");
    ScavTrap scav("Scav");
    FragTrap frag("Frag");

    clap.attack("Scav");
    clap.takeDamage(1);
    clap.beRepaired(10);
    scav.attack("Clap");
    clap.attack("Scav");
    frag.highFivesGuys();
    frag.attack("Clap");

    return (0);
}