#include <iostream>
#include <string>

class Bureaucrat{
private:
	const std::string 	_name;
	int 				_grade;

public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);  

	const std::string& 	getName() const;
	int 				getGrade() const;
	void 				incrementGrade();
    void 				decrementGrade();
	int 				GradeTooHighException();
	int 				GradeTooLowException();
};

/*
int getGrade() const;
	- this function will never modify any member variables of the Bureaucrat class
	- good practise

const int getGrade();
	- Protects the returned copy
	- making the returned copy const is completely useless.

Ultimate best practice for std::string
	- const std::string& getName() const;
*/