#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	const int _gradeToSign;
	const int _execGrade;
	bool _isSigned;

public:
	AForm(const std::string& name, const int gradeToSign, const int execGrade);
	virtual ~AForm();
	AForm(const AForm& src);
	AForm& operator=(const AForm& src);

	void beSigned(const Bureaucrat& b);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getExecGrade() const;

    virtual void execute(const Bureaucrat& executor) const = 0;

    //classes are inherited privatly by default
	class GradeTooHighException : public std::exception{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
	
	class IsNotSignedException : public std::exception{
	public:
		virtual const char* what() const throw();
	};

	class NoSuchForm : public std::exception {
       virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& o, AForm& AForm);

#endif