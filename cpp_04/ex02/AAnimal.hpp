#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal{

protected:
    std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal& src);
	AAnimal& operator=(const AAnimal& src);
	AAnimal(std::string type);
	virtual ~AAnimal();
	
	virtual void makeSound() = 0; //one pure virtual function makes the whole Class abstract
	const std::string& getType() const;
};

#endif

/*
Only AAnimal::~AAnimal() runs
Cat::~Cat() and Dog::~Dog() will NOT run
_Brain will NOT be deleted → REAL leak
*/