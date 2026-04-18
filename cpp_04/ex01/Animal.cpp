#include "Animal.hpp"

const std::string& Animal::getType() const{
    return (_type);
}


void Animal::makeSound(){
    std::cout << "\"generic noise\"" << std::endl;
}

Animal::Animal(const Animal& src) : _type(src._type){
	std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& src){
	if(this != &src){
		this->_type = src._type;
		std::cout << "Animal Assignment Operator called" << std::endl;
	}
	return *this;
}

Animal::Animal(std::string type) : _type(type){
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal() : _type("Not specified Animal"){
    std::cout << "Default Animal constructed." << std::endl;
};

Animal::~Animal(){
    std::cout << _type << " from AnimalClass destructed" << std::endl;
}
