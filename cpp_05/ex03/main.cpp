#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){


    Intern Random;
    AForm* fpointer = NULL;

    
    try{
    	std::cout << std::endl << "---" << "Attention Intern at work" << "---"<< std::endl;
    	fpointer = Random.makeForm("robotomy request", "Robo1");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	try{
    	std::cout << std::endl << "---" << "Attention Intern at work" << "---"<< std::endl;
    	fpointer = Random.makeForm("Blubber", "Blubb");
		std::cout << "This Line should not print" << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    delete fpointer;
    return(0);

}

