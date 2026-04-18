#include "Cat.hpp"

Cat& Cat::operator=(const Cat& src){
	if(this != &src){
		this->_type = src._type;
		std::cout << "Cat Assignment Operator called" << std::endl;
	}
	return *this;
}

Cat::Cat(const Cat& src) : Animal(src){
	std::cout << "Cat Copy Constructor for \"" << _type << "\"called. "
	<< "(Animal CpyC should be first)."<<std::endl;

}

Cat::Cat(std::string type) : Animal(type){
	std::cout << _type << " in CatClass constructed. (Animal should be constructed first)."<<std::endl;
}

Cat::Cat() : Animal(){
    std::cout << _type << " in CatClass constructed. (Animal should be constructed first)."<<std::endl;
}

Cat::~Cat(){
    std::cout << _type << " (Catclass) destructed. (Animal needs to be destructed afterwards)."<<std::endl;
}

void Cat::makeSound(){
    std::cout << "\"MEOWWWW!\"" <<std::endl;
}
