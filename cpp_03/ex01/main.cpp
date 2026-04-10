#include "ScavTrap.hpp"

int main(){
    ClapTrap one("Conti");
    ScavTrap scavi("Skyler");

    one.attack("Skyler");
    one.takeDamage(1);
    one.beRepaired(10);
    scavi.attack("Conti");
    one.attack("Skyler");


    return (0);
}