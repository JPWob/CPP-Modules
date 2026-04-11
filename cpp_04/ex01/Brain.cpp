#include "Brain.hpp"

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