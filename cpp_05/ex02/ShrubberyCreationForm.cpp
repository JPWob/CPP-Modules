#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::form_action() const {
    // Create and open the file. If "example.txt" doesn't exist, this will create it.
    std::ofstream outFile( (this->getTarget()+ "_shrubbery").c_str() );
    
    if (!outFile) {
        throw std::runtime_error("Failed to create or open the file for Shrubbery");
    }

	outFile << "      /\\      \n"
            << "     /  \\     \n"
            << "    /    \\    \n"
            << "   /______\\   \n"
            << "      ||      \n"
            << "      ||      \n";
    outFile.close();
}

const std::string& ShrubberyCreationForm::getTarget() const{
    return(this->_target);
 }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("ShrubberyCreationForm", 145, 137), _target(target){
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
AForm(src),  _target(src._target){
    std::cout << "ShrubberyCreationForm CopyConstructor called" << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src){
    std::cout << "ShrubberyCreationForm CopyAssignment Operator called" << std::endl;
    if(this != &src){
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
};