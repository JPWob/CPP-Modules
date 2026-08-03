#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){

    
    Bureaucrat Bu("Bu", 5);
    ShrubberyCreationForm Shrubb("SCHRUBB");
    RobotomyRequestForm Robo("Robo");
    PresidentialPardonForm Traitor("Traitor");
    Intern Random;
    AForm* fpointer;

    
    try{
    	std::cout << std::endl << "---" << "Attention Intern at work" << "---"<< std::endl;
    	fpointer = Random.makeForm("robotom request", "Robo1");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try{
    	std::cout << std::endl << "---" << "ShrubberyCreationForm" << "---"<< std::endl;
    	Shrubb.beSigned(Bu);
    	Shrubb.execute(Bu);
    
		std::cout << std::endl << "---" << "RobotomyRequestForm" << "---"<< std::endl;
    	fpointer->beSigned(Bu);
    	fpointer->execute(Bu);
    	
		std::cout << std::endl << "---" << "PresidentialPardonForm" << "---"<< std::endl;
	    Traitor.beSigned(Bu);
	    Traitor.execute(Bu);
		
	    std::cout << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    delete fpointer;
    return(0);

}

