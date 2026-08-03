#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


// PresidentialPardonForm: Informs that <target> has been pardoned by Zaphod Beeblebrox. 
// Required grades: sign 25, exec 5

void PresidentialPardonForm::form_action() const{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox the Great" << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const {
    return this->_target;
}

//OCFForm

//Child Constructor, calling the Base Constructor first. then setting target
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