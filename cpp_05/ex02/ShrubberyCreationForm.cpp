#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{

    if(!this->getIsSigned())
    {
        std::cout << "Error executing ShrubberyCreationForm \"" << this->getTarget() << "\": ";
        throw IsNotSignedException();
    }
    if(executor.getGrade() > this->getExecGrade())
    {
        std::cout << "Error executing ShrubberyCreationForm \"" << this->getTarget() << "\": ";
        throw GradeTooLowException();
    }    
    // 1. Create and open the file. If "example.txt" doesn't exist, this will create it.
    std::ofstream outFile(this->getTarget() + "_shrubbery");
    
    // 2. Always check if the file opened successfully
    if (!outFile) {
        throw std::runtime_error("Failed to create or open the file for Shrubbery");
    }
    // 3. Write data if successful
   outFile << "               ,@@@@@@@,\n"
                << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/88\n"
                << "   %&%%&*%%&*@@@@@@@@/@@@88888\\88888'\n"
                << "   %&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                << "   `&&%\\ `&&%&  \\ | /       `88\\88'\n"
                << "       `Y&\\    ` | /        /88'\n"
                << "           `\\   | |        / /\n"
                << "             \\_ | |       / /\n"
                << "             _\\_|_|_  _  /_/_\n"
                << "            [___________]\n"
                << "             |         |\n"
                << "             |_________|\n";
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
AForm(src),  _target(src._target)
{
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