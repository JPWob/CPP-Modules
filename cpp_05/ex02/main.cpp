#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){

    
    Bureaucrat Bu("Bu", 5);
    ShrubberyCreationForm Shrubb("SCHRUBB");
    RobotomyRequestForm Robo("Robo");
    PresidentialPardonForm Traitor("Traitor");

    try{
    std::cout << std::endl << "---" << "ShrubberyCreationForm" << "---"<< std::endl;
    Shrubb.beSigned(Bu);
    Shrubb.execute(Bu);
    std::cout << std::endl << "---" << "RobotomyRequestForm" << "---"<< std::endl;
    Robo.beSigned(Bu);
    Robo.execute(Bu);
    std::cout << std::endl << "---" << "PresidentialPardonForm" << "---"<< std::endl;
    Traitor.beSigned(Bu);
    Traitor.execute(Bu);
    std::cout << std::endl;
    }
    catch (const std::exception& e) {// Catch your custom exception
        std::cerr << e.what() << std::endl;
    }


    return(0);

}

