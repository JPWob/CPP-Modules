#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
    if (!this->getIsSigned()){
    std::cout << "Error executing PresidentialPardonForm \"" << this->getTarget() << "\": ";
    throw AForm::IsNotSignedException();
    }
    if (executor.getGrade() > this->getExecGrade()) {
        std::cout << "Error executing PresidentialPardonForm \"" << this->getTarget() << "\": ";
        throw AForm::GradeTooLowException();
    }
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox the Great" << std::endl;

}

const std::string& PresidentialPardonForm::getTarget() const {
    return this->_target;
}

//std CC Form
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
    AForm(src), _target(src._target) {
    std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    std::cout << "PresidentialPardonForm Copy Assignment Operator called" << std::endl;
    if (this != &src) {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}