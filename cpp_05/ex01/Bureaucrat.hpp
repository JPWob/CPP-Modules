#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception> // Required for std::exception

class Form;

class Bureaucrat{
private:
	const std::string 	_name;
	int 				_grade;

public:
	//new:
	void signForm(Form& f);

	// Constructors & Destructor (Orthodox Canonical Form)
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	
	const std::string& 	getName() const;
	int getGrade() const;
	void incrementGrade();
    void decrementGrade();
	
	class	GradeTooHighException : public std::exception{
		public:
		virtual const char* what() const throw();	//just a declaration, not a function body
	};
	
	class GradeTooLowException : public std::exception{
		public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& src);

#endif