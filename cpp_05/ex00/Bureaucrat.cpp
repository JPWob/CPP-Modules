#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){

};

Bureaucrat::~Bureaucrat(){};

Bureaucrat::Bureaucrat(const Bureaucrat& other){};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){};

std::string Bureaucrat::getName(){};
int	Bureaucrat::getGrade(){};