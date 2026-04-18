#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
protected:
    Brain *_Brain;
	
public:
    Dog();
	Dog(std::string name);
	Dog(const Dog& src);
	Dog& operator=(const Dog& src);
	~Dog();

    void makeSound();
	Brain* getBrain() const;

};