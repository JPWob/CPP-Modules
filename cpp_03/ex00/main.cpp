#include "ClapTrap.hpp"

//HP are like healt
//EP needed to attack or heal HP


int main(){
	
	std::cout << std::endl;
	std::cout << "Test Zero (Default)" << std::endl;
	ClapTrap zero;
	zero.attack("Gert");
	
	
	std::cout << std::endl;
	std::cout << "Test One" << std::endl;
	ClapTrap one("One");
    one.attack("Ghost");
    one.takeDamage(1);
    one.beRepaired(10);
	
	std::cout << std::endl;
	std::cout << "Test Two (Copy of One)" << std::endl;
	ClapTrap two(one);
	two.attack("Bernd");
	std::cout << std::endl;



    return (0);
}