#include "Base.hpp"

Base::~Base(){
	std::cout << "Base Destructor called" << std::endl;
}

A::A(int a) : alpha(a){}

A::~A(){
	std::cout << "A Destructor called" << std::endl;
}

B::B(std::string str) : string(str){
	std::cout << "B Constructor called" << std::endl;
}

B::~B(){
	std::cout << "B Destructor called" << std::endl;
}