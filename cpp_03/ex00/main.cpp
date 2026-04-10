#include "ClapTrap.hpp"

int main(){
    ClapTrap one("Conti");

    one.attack("Ghost");
    one.takeDamage(1);
    one.beRepaired(10);
    return (0);
}