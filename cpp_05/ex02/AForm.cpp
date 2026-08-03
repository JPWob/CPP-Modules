#include "AForm.hpp"
#include "Bureaucrat.hpp"


//new
void AForm::execute(const Bureaucrat& executor) const{
	
    if (!this->_isSigned){
        throw AForm::FormNotSignedException();
	}
    if (executor.getGrade() > this->getExecGrade()){
		std::cerr << executor.getName() << " could not execute " << this->getName() << " because: ";
        throw AForm::GradeTooLowException();
	}

    this->form_action(); //This function must be virtual and individual for each Child Form
}


//from ex01
void AForm::beSigned(const Bureaucrat& b){
	if(_gradeToSign < b.getGrade()){
		std::cout << b.getName() << " could not sign " << this->getName() << " because: ";
		throw AForm::GradeTooLowException();
	}
	_isSigned = true;
	std::cout<< b.getName() << " sucessfully signed " << this->getName() << std::endl;
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

//Exeptions
const char* AForm::FormNotSignedException::what() const throw(){
	return("AForm Error: Form is not signed!");
}

const char* AForm::GradeTooHighException::what() const throw(){
	return("AForm Error: Grade is too high!");
};

const char* AForm::GradeTooLowException::what() const throw(){
	return("AForm Error: Grade is too Low!");
};

//print form
std::ostream& operator<<(std::ostream& o, const AForm& f){
	o << f.getName() << " has sign status (1 is signed): " << f.getIsSigned() << std::endl;
	o << "Grade to Sign: " << f.getGradeToSign() << ". Grade to execute: " << f.getExecGrade() << "." << std::endl;
	return o;
}

//OCF
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

AForm& AForm::operator=(const AForm& src){
	std::cout << "AForm Copy Assignment Operator called" << std::endl;
	if(this != &src){
		this->_isSigned = src._isSigned;
	}
	return *this;
}

AForm::~AForm(){
	std::cout << "AForm Destructor called" << std::endl;
};

AForm::AForm(const AForm& src) : _name(src._name), _gradeToSign(src._gradeToSign), _execGrade(src._execGrade), _isSigned(src._isSigned){
	std::cout << "AForm CopyConstructor called" << std::endl;
};