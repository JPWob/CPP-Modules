#include "Dog.hpp"

Dog::Dog() : _Brain(new Brain){
    _type = "Dog";
    std::cout << _type << " in Dogclass constructed (3/3)."<< std::endl;
}

Dog::~Dog(){
    delete _Brain;
    std::cout << _type << " has been destructed. (2/3)"<< std::endl;
}

void Dog::makeSound(){
    std::cout << "\"WUFF!\" " <<std::endl;
}
