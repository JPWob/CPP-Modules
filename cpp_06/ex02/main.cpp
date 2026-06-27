#include <iostream>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For std::time()
#include <exception> // For std::bad_cast
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);



int main(){

	
    std::srand(static_cast<unsigned int>(std::time(NULL))); // Seed the random number generator once at program startup, otherwise every program will have same output

	std::cout << "--- Generating Random Object ---" << std::endl;
	Base* randObject = generate();
	
    std::cout << "--- Identify Random Object via ptr ---" << std::endl;
    identify(randObject);

    std::cout << "--- Identify Random Object via reference ---" << std::endl;
    identify(*randObject);

    delete randObject;
}



Base* generate(void) {
    switch (std::rand() % 3) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A(42);
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B("Hello There");
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C('f');
    }
    return NULL;
}

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
    else { // If dynamic_cast fails with a pointer, it returns NULL.
        std::cout << "Unknown type" << std::endl;
    }
}


// References cannot be NULL. If dynamic_cast fails with a reference, 
// it throws a std::bad_cast exception. We MUST catch it.
void identify(Base& p) {
    try {
		(void)dynamic_cast<A&>(p);					//in case dynamic_cast<reference>(ptr) fails, it throws an exemption std::bad_cast(); (happens behind the scenes)
        std::cout << "Actual type: A" << std::endl;
        return; // Found it, stop checking
    } catch (const std::bad_cast&) {} //just for catching,do nothing, test further

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Actual type: B" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Actual type: C" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    std::cout << "Unknown type" << std::endl;
}

/*
"Catching exceptions by const & is a C++ best practice. 
The reference (&) avoids the overhead of copying the exception object 
and prevents object slicing if a derived exception is thrown. 
The const ensures the exception object is read-only and
 allows the compiler to optimize the catch block."
*/

/* Why catch an exeption by Reference and not by value? : const std::bad_cast&
std::bad_cast inherits from std::exception
C++ copies the thrown exception into a new variable. If a compiler or runtime throws a specialized, custom version of bad_cast that has extra debugging information or attributes, catching it by value forces it into a base std::bad_cast variable.
Any extra data or specialized behavior from the derived exception is violently chopped off. This is called object slicing. Catching by reference (&) ensures you point directly to the original exception object in memory, preserving its exact type and polymorphic behavior.

Catching by Value (The Problem: Object Slicing)
If you omit the & and catch by value like this:		catch (std::bad_cast ex) // By value!
You are allocating a brand-new variable named ex on the stack that is exactly the size of a standard std::bad_cast object.
If the runtime actually throws the specialized __verbose_bad_cast, C++ tries to fit this larger, specialized object into the smaller space allocated for ex

Additionally, catching by reference is faster because it avoids copying the exception object entirely.
*/



/*
This exercise is designed to teach you the difference between 
	pointer dynamic casting
	reference dynamic casting

	void identify(Base* p)
		When you use dynamic_cast with pointers, a failed cast returns NULL (nullptr).

	void identify(Base& p)
	References cannot be NULL. Therefore, when dynamic_cast fails with a reference, 
	it throws a std::bad_cast exception. You must use try-catch blocks to identify the type
*/