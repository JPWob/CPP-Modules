#include "Animal.hpp"

std::string& Animal::getType(){
    return (_type);
}
void Animal::makeSound(){
    std::cout << "\"generic noise\"" << std::endl;
}

Animal::Animal() : _type("Not specified Animal"){
    std::cout << "Default Animal constructed." << std::endl;
};

Animal::~Animal(){
    std::cout << _type << " from AnimalClass destructed" << std::endl;
}

