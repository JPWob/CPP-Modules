#include "AForm.hpp"
#include "PresedentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){

    
    Bureaucrat Bu("Bu", 140);
    ShrubberyCreationForm Shrubb("SCHRUBB");

    try{
    Shrubb.beSigned(Bu);
    Shrubb.execute(Bu);
    }
    catch (const std::exception& e) {// Catch your custom exception
        std::cerr << e.what() << std::endl;
    }


    return(0);

}

