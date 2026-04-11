#include "WrongCat.hpp"

WrongCat::WrongCat(){
    _type = "WrongCat";
    std::cout << _type << " in WrongCatClass constructed"<<std::endl;
}

WrongCat::~WrongCat(){
    std::cout << _type << " of WrongCatClass destructed"<<std::endl;
}

void WrongCat::makeSound(){
    std::cout << "\"MEOWWWW!\"" <<std::endl;
}
