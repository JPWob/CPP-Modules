#include "Bureaucrat.hpp"
#include "AForm.hpp"

//new
void Bureaucrat::executeForm(AForm const& f) const{
	f.execute(*this);
}

//from ex01
void Bureaucrat::signAForm(AForm& f){
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


/*
Because _name is const, C++ will try to initialize it before 
it even enters the {} of your constructor. Since you didn't tell it 
what name to use, it defaults to an empty string ("").
Then, *this = other; runs. As we established earlier, 
your = operator safely ignores the const _name variable. 
The result? Your newly copied Bureaucrat gets the correct grade, 
but their name is permanently stuck as an empty string.
*/


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other){
        this->_grade = other._grade;
    }
    std::cout << "Bureaucrat Copy assignment called" << std::endl;
    return *this;
};
/*Print operator
When main.cpp executes the line 	std::cout << intern;, 
the compiler translates it mathematically 
into a function call: 				operator<<(std::cout, intern);.
*/

std::ostream& operator<<(std::ostream& o, const Bureaucrat& src){
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return o;
};

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructed" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){
    std::cout << "Bureaucrat Copy Constructor called" << std::endl;
};

