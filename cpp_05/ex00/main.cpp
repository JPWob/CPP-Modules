#include "Bureaucrat.hpp"

//grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).

int main (){

    try{
        std::cout << "Try to create too god to be true Bureau" << std::endl;
        Bureaucrat TooGood("TooGood", 0);
        std::cout << "This line should not print" << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e){
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Try to create the worst Bureau" << std::endl;
        Bureaucrat TooLazy("TooLazy", 151);
        std::cout << "This line should not print" << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e){
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat Friedrich("Friedrich", 60);
    std::cout << Friedrich.getName() << std::endl;
    std::cout << Friedrich.getGrade() << std::endl;
    Friedrich.incrementGrade();
    Friedrich.decrementGrade();
    std::cout << Friedrich.getGrade() << std::endl;
}