#include "WrongAnimal.hpp"

std::string& WrongAnimal::getType(){
    return (_type);
}

void WrongAnimal::makeSound(){
    std::cout << "\"generic noise\"" << std::endl;
}

WrongAnimal::WrongAnimal() : _type("Not specified Animal"){
    std::cout << "Default Animal constructed." << std::endl;
};

WrongAnimal::~WrongAnimal(){
    std::cout << _type << " destructed" << std::endl;
}