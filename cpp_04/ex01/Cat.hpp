#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
protected:
    Brain *_Brain;

public:
    Cat();
	~Cat();
    Cat(const Cat& src);
    Cat& operator=(const Cat& src);

    void makeSound();
    Brain* getBrain() const;
};