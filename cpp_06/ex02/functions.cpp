#include "Base.hpp"
#include "functions.hpp"

//in case dynamic_cast<reference>(reference) fails, it throws an exemption std::bad_cast();
void identify(Base& p) {
    try {
		(void)dynamic_cast<A&>(p);					
        std::cout << "Actual type: A" << std::endl;
        return; // Found it, stop checking
    } catch (const std::exception&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Actual type: B" << std::endl;
        return;
    } catch (const std::exception&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Actual type: C" << std::endl;
        return;
    } catch (const std::exception&) {}

    std::cout << "Unknown type" << std::endl;
}

// If dynamic_cast fails with a pointer, it returns NULL.
void identify(Base* p) {
    
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "Actual type: A" << std::endl;
    } 
    else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "Actual type: B" << std::endl;
    } 
    else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "Actual type: C" << std::endl;
    } 
    else {
        std::cout << "Unknown type" << std::endl;
    }
}

Base* generate(void) {
    switch (std::rand() % 3) {
        case 0:
            return new A(26);
        case 1:
            return new B("Class B");
        case 2:
            return new C('c');
    }
    return NULL;
}
