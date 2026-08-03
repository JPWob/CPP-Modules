#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){

    
    Bureaucrat Bu("Bu", 50);
    ShrubberyCreationForm Shrubb("SCHRUBB");
    RobotomyRequestForm Robo("Robo");
    PresidentialPardonForm Traitor("Traitor");
	std::cout << std::endl;

	//Not allowed: AForm A();

    try{
    std::cout << std::endl << "---" << "ShrubberyCreationForm" << "---"<< std::endl;
    Shrubb.beSigned(Bu);
    Shrubb.execute(Bu);
	}
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	try{
    std::cout << std::endl << "---" << "RobotomyRequestForm" << "---"<< std::endl;
    Robo.beSigned(Bu);
    Robo.execute(Bu);
	}
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	try{
    std::cout << std::endl << "---" << "PresidentialPardonForm" << "---"<< std::endl;
    Traitor.beSigned(Bu);
    Traitor.execute(Bu);
    std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;

    return(0);

}

