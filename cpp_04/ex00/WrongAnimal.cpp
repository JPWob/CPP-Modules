#include "WrongAnimal.hpp"



std::string& WrongAnimal::getType(){
	return (_type);
}

void WrongAnimal::makeSound(){
	std::cout << "\"generic noise\"" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "\"" << type << "\" as Instance of WrongAnimal Class constructed." << std::endl;
}

WrongAnimal::WrongAnimal() : _type("default"){
    std::cout << "Default WrongAnimal constructed." << std::endl;
};

WrongAnimal::~WrongAnimal(){
    std::cout << _type << " of WrongAnimal Class destructed" << std::endl;
}