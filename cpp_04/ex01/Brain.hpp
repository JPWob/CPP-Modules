#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
protected:
    std::string ideas[100];

public:
    Brain();
    ~Brain();
	Brain(const Brain& src);
	Brain& operator=(const Brain& src);

    void setIdea(int i, const std::string& idea);
    const std::string& getIdea(int i) const; //returns a const referemnce
};

#endif

//const std::string& getIdea(int i) const;
//The const at the end of a function signature tells the compiler: "This function will not modify any member variables of the object it belongs to."