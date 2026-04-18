#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
protected:
    Brain *_Brain;

public:
    Cat();
	Cat(std::string name);
	Cat(const Cat& src);
	Cat& operator=(const Cat& src);
	~Cat();

    void makeSound();
    Brain* getBrain() const;
};