#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


AForm* Intern::makeForm(std::string formName, std::string target) {
    // 1. Array of known form names
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int i;
	for(i = 0; i < 3; i++){
        if(formName == formTypes[i])
            break;
    }

    AForm* newForm = NULL;
    switch (i)
    {
        case 0: newForm = new ShrubberyCreationForm(target);break;
        case 1: newForm = new RobotomyRequestForm(target);break;
        case 2: newForm = new PresidentialPardonForm(target);break;
        default:{
            std::cerr << "Error: Intern cannot create: \"" << formName << "\". ";
			throw AForm::NoSuchForm();
		}
    }
    std::cout << "Intern created " << formName << std::endl;
    return newForm;
}

//OC Form
Intern::Intern() {
    std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern& src) { 
    (void)src; //Intern has no member variables
    std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& src) {
    (void)src;
    std::cout << "Intern Copy Assignment Operator called" << std::endl;
    return *this;
}