#include "RobotomyRequestForm.hpp"


void RobotomyRequestForm::form_action() const{

    std::cout << "* LOUD DRILLING NOISES: BZZZZZZZ! * ... ";

    static bool seed = false; //ensure the seed is only generated once per program
    if(!seed){
        std::srand(std::time(NULL));
        seed = true;
    }
    if (std::rand() % 2 == 0) {
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy on " << this->getTarget() << " failed." << std::endl;
    }
}

const std::string& RobotomyRequestForm::getTarget() const {
    return this->_target;
}

//CC Form
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
    AForm(src), _target(src._target) {
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
    std::cout << "RobotomyRequestForm Copy Assignment Operator called" << std::endl;
    if (this != &src) {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}