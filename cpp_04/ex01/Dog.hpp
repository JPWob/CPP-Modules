#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
protected:
    Brain *_Brain;
public:
    Dog();
	~Dog();

    void makeSound();

};