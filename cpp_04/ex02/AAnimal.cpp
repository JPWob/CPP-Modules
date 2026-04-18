#include "AAnimal.hpp"

const std::string& AAnimal::getType() const{
    return (_type);
}

void AAnimal::makeSound(){
    std::cout << "\"generic noise\"" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) : _type(src._type){
	std::cout << "AAnimal Copy Constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& src){
	if(this != &src){
		this->_type = src._type;
		std::cout << "AAnimal Assignment Operator called" << std::endl;
	}
	return *this;
}

AAnimal::AAnimal(std::string type) : _type(type){
	std::cout << "AAnimal Constructor called" << std::endl;
}

AAnimal::AAnimal() : _type("Not specified AAnimal"){
    std::cout << "Default AAnimal constructed." << std::endl;
};

AAnimal::~AAnimal(){
    std::cout << _type << " from AAnimalClass destructed" << std::endl;
}
