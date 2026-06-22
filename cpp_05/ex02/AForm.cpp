#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
When you write the assignment operator for your AForm class, 
you are only perAForming a partial assignment. 
You are only copying the one variable that is actually allowed to change: _signature.
Rest of src stays the same.
*/

AForm& AForm::operator=(const AForm& src){
	std::cout << "AForm Copy Assignment Operator called" << std::endl;
	if(this != &src){
		this->_isSigned = src._isSigned;
	}
	return *this;
}
								
void AForm::beSigned(const Bureaucrat& b){
	if(_gradeToSign < b.getGrade()){
		std::cout << b.getName() << " couldnt sign " << this->getName() << " because: ";
		throw AForm::GradeTooLowException();
	}
	_isSigned = true;
	std::cout<< b.getName() << " sucessfully signed " << this->getName() << std::endl;
}

const char* AForm::IsNotSignedException::what() const throw(){
	return("AForm Error: Form is not signed!");
}

const char* AForm::GradeTooHighException::what() const throw(){
	return("AForm Error: Grade is too high!");
};

const char* AForm::GradeTooLowException::what() const throw(){
	return("AForm Error: Grade is too Low!");
};



std::ostream& operator<<(std::ostream& o, const AForm& f){
	o << f.getName() << " has sign status (1 is signed): " << f.getIsSigned() << std::endl;
    o << "Grade to Sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getExecGrade() << "." << std::endl;
	return o;
}

std::string AForm::getName() const{
	return(_name);
}

bool AForm::getIsSigned() const{
	return(_isSigned);
}

int AForm::getGradeToSign() const{
	return(_gradeToSign);
}

int AForm::getExecGrade() const{
	return(_execGrade);
}



AForm::AForm(const std::string& name, const int gradeToSign, const int execGrade) 
	: _name(name), _gradeToSign(gradeToSign), _execGrade(execGrade), _isSigned(false)
{
	std::cout << "AForm Constructor called" << std::endl;
	if(gradeToSign < 1 || execGrade < 1){
		throw AForm::GradeTooHighException();
	}
	if(gradeToSign > 150 || execGrade > 150){
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm(){
	std::cout << "AForm Destructor called" << std::endl;
};

AForm::AForm(const AForm& src) : _name(src._name), _gradeToSign(src._gradeToSign), _execGrade(src._execGrade), _isSigned(src._isSigned){
	std::cout << "AForm CopyConstructor called" << std::endl;
};