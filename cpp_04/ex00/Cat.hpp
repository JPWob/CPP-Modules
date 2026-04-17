#include "Animal.hpp"

class Cat : public Animal{
protected:

public:
    Cat();
	Cat(std::string name);
	Cat(const Cat& src);
	Cat& operator=(const Cat& src);
	~Cat();

    void makeSound();
};