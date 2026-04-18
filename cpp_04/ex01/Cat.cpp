#include "Cat.hpp"

Brain* Cat::getBrain() const{
    return _Brain;
}

Cat& Cat::operator=(const Cat& src)
{
    if (this != &src){				// 1. Don't assign a cat to itself
		this->_type = src._type; 
		if (this->_Brain)			// 2. Prevent Memory Leak if the cpy has an initialized Brain already (in this ex always init)
			delete this->_Brain;
		this->_Brain = new Brain;	//3. Deep Copy 
		*_Brain = *src._Brain;		//!!! the operator= is NOT called in the case of _Brain = src. Because _Brain is a Pointer_Brain; Just copies Pointer == Shallow
									// Need to dereference to say Brain = Brain and not Pointer = Pointer. 
	}
	std::cout << "Operator= on Cat called" <<std::endl;
    return *this; 
}

//CONSTRUCTORS (Cat always has a brain! Brain is never NULL)
//calling cpy constructor for brain
Cat::Cat(const Cat& src) : Animal(src), _Brain(new Brain(*src._Brain)){
	std::cout << "Cat DeepCopy constructed" << std::endl;
}

//calling default constructor fro brain
Cat::Cat() : Animal(), _Brain(new Brain){ 
	std::cout << _type << " in Catclass constructed. (Default Animal and then Brain should be constructed first)."<<std::endl;
}

Cat::Cat(std::string type) : Animal(type), _Brain(new Brain){
	std::cout << _type << " in CatClass constructed. (Animal should be constructed first)."<<std::endl;
}

//Destructor
Cat::~Cat(){
    delete _Brain;
    std::cout << _type << " (Catclass) destructed. (Brain should go first)."<<std::endl;
}

// Make Sound
void Cat::makeSound(){
    std::cout << "\"MEOWWWW!\"" <<std::endl;
}
