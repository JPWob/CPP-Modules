#include "Bureaucrat.hpp"
#include "Form.hpp"

//new
void Bureaucrat::signForm(Form& f){
	f.beSigned(*this);
}

//from ex00
const std::string& Bureaucrat::getName() const{
    return(this->_name);
};

int	Bureaucrat::getGrade() const{
    return(this->_grade);
};

void Bureaucrat::incrementGrade(){
    std::cout << "Increment Grade" << std::endl;
    this->_grade--;
};
void Bureaucrat::decrementGrade(){
    std::cout << "Decrement Grade" << std::endl;
    this->_grade++;
};

//define the what method
const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return("Bureaucrat Error: Grade is too high! Must be >= 1");

};

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Bureaucrat Error: Grade is too low! (Must be <= 150)");
};


//Print operator
std::ostream& operator<<(std::ostream& o, const Bureaucrat& src){
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return o;
};

// OCF
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
    std::cout << "Bureaucrat Constructor called" << std::endl;
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade = grade;
};

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructed" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){
    std::cout << "Bureaucrat Copy Constructor called" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other){
        this->_grade = other._grade;
    }
    std::cout << "Bureaucrat Copy assignment called" << std::endl;
    return *this;
};

