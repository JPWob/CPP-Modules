#include "Dog.hpp"

Dog::Dog(){
    _type = "Dog";
    std::cout << _type << " in Dogclass constructed (2/2)."<< std::endl;
}

Dog::~Dog(){
    std::cout << _type << " has been destructed. (1/2)"<< std::endl;
}

void Dog::makeSound(){
    std::cout << "\"WUFF!\" " <<std::endl;
}
