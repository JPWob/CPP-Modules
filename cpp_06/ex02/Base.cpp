#include "Base.hpp"

Base::~Base(){
	std::cout << "Base Destructor called" << std::endl;
}

A::A(int a) : alpha(a){
	std::cout << "A Constructor called" << std::endl;
}

A::~A(){
	std::cout << "A Destructor called" << std::endl;
}

B::B(std::string str) : string(str){
	std::cout << "B Constructor called" << std::endl;
}

B::~B(){
	std::cout << "B Destructor called" << std::endl;
}

C::C(char c) : letter(c){
	std::cout << "C Constructor called" << std::endl;
}

C::~C(){
	std::cout << "C Destructor called" << std::endl;
}
