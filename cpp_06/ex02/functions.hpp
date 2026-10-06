#include <iostream>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For std::time()
#include <exception> 

class Base;

Base* generate(void);
void identify(Base& p);
void identify(Base* p);