#include "WrongCat.hpp"

WrongCat::WrongCat(std::string type) : WrongAnimal(type){
    std::cout << _type << " in WrongCatClass constructed"<<std::endl;
}

WrongCat::WrongCat() : WrongAnimal(){
    std::cout << _type << " in WrongCatClass constructed"<<std::endl;
}

WrongCat::~WrongCat(){
    std::cout << _type << " of WrongCatClass destructed"<<std::endl;
}

void WrongCat::makeSound(){
    std::cout << "\"MEOWWWW!\"" <<std::endl;
}
