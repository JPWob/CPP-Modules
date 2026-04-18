#include "Brain.hpp"

Brain& Brain::operator=(const Brain& src) {
	if (this != &src) { 
        for (int i = 0; i < 100; i++) {
			this->ideas[i] = src.ideas[i];
        }
    }
	std::cout << "Brain assignment operator called." << std::endl;
    return *this;
}

Brain::Brain(const Brain& src) {
    std::cout << "Brain Copy Constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = src.ideas[i];
    }
}

Brain::Brain(){
    std::cout << "Brain constructed" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain destructed" << std::endl;
}

void Brain::setIdea(int i, const std::string& idea){
    this->ideas[i] = idea;
}

const std::string& Brain::getIdea(int i) const{
    
    return(this->ideas[i]);
}