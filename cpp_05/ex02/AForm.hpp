#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
//Only the parent (code inside AForm.cpp) can read or write to it.
	const std::string _name;
	const int _gradeToSign;
	const int _execGrade;
	bool _isSigned;

protected:
//Parent and Children (code inside the .cpp files) can access/override it
	virtual void form_action() const = 0;

public:
	AForm(const std::string& name, const int gradeToSign, const int execGrade);
	virtual ~AForm();
	AForm(const AForm& src);
	AForm& operator=(const AForm& src);

	//new function:
    void execute(const Bureaucrat& executor) const; //same logic for every Form.

	void beSigned(const Bureaucrat& b);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getExecGrade() const;


    //classes are inherited privatly by default
	class GradeTooHighException : public std::exception{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
	
	class FormNotSignedException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, AForm& AForm);

#endif