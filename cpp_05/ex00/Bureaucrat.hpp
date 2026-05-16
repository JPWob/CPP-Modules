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

	std::string getName();
	int getGrade();
};

