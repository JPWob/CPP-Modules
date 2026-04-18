#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
protected:

public:
    WrongCat();
	WrongCat(std::string type);
	~WrongCat();

    void makeSound();
};