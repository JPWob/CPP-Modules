#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{

protected:
    std::string _type;
public:
	Animal();
	Animal(const Animal& src);
	Animal& operator=(const Animal& src);
	Animal(std::string type);
	virtual ~Animal();
	
	virtual void makeSound(); //look at the most derived version of this function
	const std::string& getType() const;
};

#endif

/*
Only Animal::~Animal() runs
Cat::~Cat() and Dog::~Dog() will NOT run
_Brain will NOT be deleted → REAL leak
*/