#include "ScavTrap.hpp"

int main(){

	std::cout << std::endl;
	std::cout << "Test Zero (Default)" << std::endl;
	ScavTrap zero;
	zero.attack("Gert");


	std::cout << std::endl;
	std::cout << "Test One (ScavTrap (Name) constructor)" << std::endl;
	ScavTrap one("One");
    one.attack("Ghost");
    one.takeDamage(1);
    one.beRepaired(10);

	std::cout << std::endl;
	std::cout << "Test Three (Cpy Assignemnt Operator)" << std::endl;
	ScavTrap three;
	three = one;
    three.attack("Tres");
    three.takeDamage(50);
    three.beRepaired(10);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Test Two (ScavTrap Copy Constructor with Original One as src)" << std::endl;
	ScavTrap two(one);
	two.attack("Bernd");
	two.takeDamage(9);
	two.beRepaired(5);
	two.guardGate();
	std::cout << std::endl;

	
	std::cout << "Test virtual attack function" << std::endl;
	ClapTrap* ptr = new ScavTrap("Pointer");
	ptr->attack("Gollum");				//Compiler checks ClapTrap.hpp. It finds Scav attack via vtable. Passes.
	//ptr->guardGate(); 				//Compiler checks ClapTrap.hpp. It cannot find guardGate. Fails.
	delete ptr; //otherwise destructor will not be called

	std::cout << std::endl;


    return (0);
}