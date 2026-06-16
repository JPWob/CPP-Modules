#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
private:
	const std::string _name;
	const int _gradeToSign;
	const int _execGrade;
	bool _isSigned;

public:
	Form(const std::string& name, const int gradeToSign, const int execGrade);
	~Form();
	Form(const Form& src);
	Form& operator=(const Form& src);

	void beSigned(const Bureaucrat& b);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getExecGrade() const;

	class GradeTooHighException : std::exception{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : std::exception{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, Form& Form);