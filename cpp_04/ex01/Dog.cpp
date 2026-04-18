#include "Dog.hpp"

Brain* Dog::getBrain() const{
    return _Brain;
}

Dog& Dog::operator=(const Dog& src){
	if(this != &src){
		this->_type = src._type;
		if (this->_Brain)
			delete this->_Brain; 	//good practice
		this->_Brain = new Brain;	//Deep Copy 
		*_Brain = *src._Brain; 		//_Brain is a Pointer, no Brain Object. Need to dereference!
	}
	std::cout << "Dog Assignment Operator called" << std::endl;
    return *this;
}


//CONSTRUCTORS (Dog always has a brain! Brain is never NULL)

//If i dont put : Animal(src), a default Animal is constructed first that immediatly gets overriden
Dog::Dog(const Dog& src) : Animal(src), _Brain(new Brain(*src._Brain)){
	std::cout << "Dog DeepCopy constructed" << std::endl;
}

Dog::Dog() : Animal(), _Brain(new Brain){
	std::cout << _type << " in Dogclass constructed (3/3)."<< std::endl;
}

Dog::Dog(std::string type) : Animal(type), _Brain(new Brain){
	std::cout << _type << " in Dogclass constructed (2/2)."<< std::endl;
}


//Destructor
Dog::~Dog(){
	delete _Brain;
	std::cout << _type << " has been destructed. (2/3)"<< std::endl;
}

// Make Sound
void Dog::makeSound(){
	std::cout << "\"WUFF!\" " <<std::endl;
}