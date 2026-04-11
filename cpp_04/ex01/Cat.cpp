#include "Cat.hpp"

Brain* Cat::getBrain() const{
    return _Brain;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "Operator = on Cat called" <<std::endl;
    // 1. Don't assign a cat to itself
    if (this != &src) 
        this->_type = src._type; //just default stuff
    // 2. Prevent Memory Leak if the cpy has an initialized Brain already
    if (this->_Brain)
            delete this->_Brain;
    //3. Deep Copy 
    this->_Brain = new Brain;
    for(int i = 0; i < 100; i++)
    {
        this->_Brain->setIdea(i, src._Brain->getIdea(i));
    }
    return *this;
}

Cat::Cat(const Cat& src){
    std::cout << "Cats Copy is being constructed " <<std::endl;
    this->_Brain = NULL; // important for assigment operator (delete Brain)
    *this = src;
    
}

Cat::Cat() : _Brain(new Brain){ 
    std::cout << _type << " in cat class constructed. (Default Animal and then Brain should be constructed first)."<<std::endl;
    _type = "Cat";
}

Cat::~Cat(){
    delete _Brain;
    std::cout << _type << " (Catclass) destructed. (Brain should go first)."<<std::endl;
}

void Cat::makeSound(){
    std::cout << "\"MEOWWWW!\"" <<std::endl;
}
