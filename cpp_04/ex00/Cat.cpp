#include "Cat.hpp"

Cat::Cat()//equivalent to Cat::Cat() : Animal() 
{ 
    _type = "Cat";  //In C++, the member initializer list (: ..., ...,) is for "direct" members. Since _type is inherited from Animal, it technically "belongs" to the Animal part of the object, not the Cat part.
    std::cout << _type << " in cat class constructed. (Default Animal should be constructed first)."<<std::endl;
}


Cat::~Cat(){
    std::cout << _type << " (Catclass) destructed. destructed. (Default Animal needs to be destructed afterwards)."<<std::endl;
}

void Cat::makeSound(){
    std::cout << "\"MEOWWWW!\"" <<std::endl;
}
