#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
protected:

public:
    WrongCat();
	~WrongCat();

    void makeSound();
};