#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{

protected:
    std::string _type;
public:
	Animal();
	virtual ~Animal();
    virtual void makeSound();
    std::string& getType(); 
};

#endif