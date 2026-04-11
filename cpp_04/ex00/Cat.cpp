#include "Cat.hpp"

Cat::Cat(){
    _type = "Cat";
    std::cout << _type << " in cat class constructed. (Default Animal should be constructed first)."<<std::endl;
}

Cat::~Cat(){
    std::cout << _type << " of cat class destructed. (Default Animal needs to be destructed afterwards)."<<std::endl;
}

void Cat::makeSound(){
    std::cout << "\"MEOWWWW!\"" <<std::endl;
}
