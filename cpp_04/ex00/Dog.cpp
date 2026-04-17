#include "Dog.hpp"

Dog::Dog(const Dog& src) : Animal(src){
	std::cout << "Dog Copy constructed (2/2)."<< std::endl;
}

Dog& Dog::operator=(const Dog& src){
	if(this != &src){
		this->_type = src._type;
		std::cout << "Dog Assignment Operator called" << std::endl;
	}
	return *this;
}

Dog::Dog(std::string type) : Animal(type){
	std::cout << _type << " in Dogclass constructed (2/2)."<< std::endl;
}

Dog::Dog() : Animal("Dog"){
    std::cout << _type << " in Dogclass constructed (2/2)."<< std::endl;
}

Dog::~Dog(){
    std::cout << _type << " has been destructed. (1/2)"<< std::endl;
}

void Dog::makeSound(){
    std::cout << "\"WUFF!\" " <<std::endl;
}
