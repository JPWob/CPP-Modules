#include "Animal.hpp"

class Dog : public Animal{
protected:
    
public:
    Dog();
	Dog(std::string name);
	Dog(const Dog& src);
	Dog& operator=(const Dog& src);
	~Dog();

    void makeSound();

};