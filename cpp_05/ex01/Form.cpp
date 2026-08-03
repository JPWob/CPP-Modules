#include "Form.hpp"
#include "Bureaucrat.hpp"


void Form::beSigned(const Bureaucrat& b){
	if(_gradeToSign < b.getGrade()){
		std::cout << b.getName() << " couldnt sign " << this->getName() << " because: ";
		throw Form::GradeTooLowException();
	}
	_isSigned = true;
	std::cout<< b.getName() << " sucessfully signed " << this->getName() << std::endl;
}

std::string Form::getName() const{
	return(_name);
}

bool Form::getIsSigned() const{
	return(_isSigned);
}

int Form::getGradeToSign() const{
	return(_gradeToSign);
}

int Form::getExecGrade() const{
	return(_execGrade);
}

//Exeptions
const char* Form::GradeTooHighException::what() const throw(){
	return("Form Error: Grade is too high!");
};

const char* Form::GradeTooLowException::what() const throw(){
	return("Form Error: Grade is too Low!");
};

//Print operator
std::ostream&operator<<(std::ostream& o, const Form& f){
	o << f.getName() << " has sign status (1 is signed): " << f.getIsSigned() << std::endl;
	o << "Grade to Sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getExecGrade() << "." << std::endl;
	return o;
}

//OCF
Form::Form(const std::string& name, const int gradeToSign, const int execGrade) 
	: _name(name), _gradeToSign(gradeToSign), _execGrade(execGrade), _isSigned(false)
{
	std::cout << "Form Constructor called" << std::endl;
	if(gradeToSign < 1 || execGrade < 1){
		throw Form::GradeTooHighException();
	}
	if(gradeToSign > 150 || execGrade > 150){
		throw Form::GradeTooLowException();
	}
}

/*
Copy Assignment operator
Standard copy assignment operator usually overwrite all member variables 
of the target (this) object, so that it becomes an exact replica of src.
For your Form class, you can only do a partial assignment because almost all
of Form variables are const !
You are only copying the one variable that is actually allowed to change: _signature.
Rest of src stays the same.
*/
Form& Form::operator=(const Form& src){
	std::cout << "Form Copy Assignment Operator called" << std::endl;
	if(this != &src){
		this->_isSigned = src._isSigned;
	}
	return *this;
}
								


Form::~Form(){
	std::cout << "Form Destructor called" << std::endl;
};

Form::Form(const Form& src) : _name(src._name), _gradeToSign(src._gradeToSign), _execGrade(src._execGrade), _isSigned(src._isSigned){
	std::cout << "Form CopyConstructor called" << std::endl;
};