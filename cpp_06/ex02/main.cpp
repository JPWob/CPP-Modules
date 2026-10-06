#include "Base.hpp"
#include "functions.hpp"

int main(){

	
    std::srand(static_cast<unsigned int>(std::time(NULL)));			// Seed the random number generator once at program startup, otherwise every program will have same output

	std::cout << "--- Generating Random Object: ";
	Base* randObject = generate();
	
	std::cout << std::endl << "Identify Random Object via ptr: ";
    identify(randObject);		// passing Base*
    
    std::cout << std::endl << "Identify Random Object via reference: ";
    if (randObject != NULL) {
    	identify(*randObject);	// passing B
	}
	

	std::cout << std::endl << "--- END ---" << std::endl;
    delete randObject;
}



/*
This exercise is designed to teach the difference between 
	pointer dynamic casting
	reference dynamic casting

	void identify(Base* p)
		When you use dynamic_cast with pointers, a failed cast returns NULL (nullptr).

	void identify(Base& p)
	References cannot be NULL. Therefore, when dynamic_cast fails with a reference, 
	it throws a std::bad_cast exception. You must use try-catch blocks to identify the type
*/

/*
 * ============================================================================
 * EXCEPTION HANDLING: Catch by Reference vs. Catch by Value
 * ============================================================================
 *
 * Why use `const std::bad_cast&` instead of `std::bad_cast`?
 *
 * 1. PREVENTS OBJECT SLICING:
 *    - Catching by value (`catch (std::bad_cast ex)`) allocates a new object
 *      on the stack with only the base class layout.
 *    - If the runtime throws a derived/specialized exception (e.g., a custom
 *      or vendor subclass containing extra debug fields), copying it into
 *      the base type chops off the derived members ("slicing").
 *    - Catching by reference (`&`) binds directly to the original thrown
 *      instance, preserving the full dynamic type and all member data.
 *
 * 2. PRESERVES POLYMORPHISM:
 *    - Slicing resets the virtual table pointer (vptr) to the base class.
 *    - A reference ensures virtual dispatch works properly, so overridden
 *      methods like `ex.what()` invoke the derived version.
 *
 * 3. ZERO COPY OVERHEAD:
 *    - Catching by value invokes the copy constructor. If memory allocation
 *      fails during that copy, `std::terminate` can be triggered.
 *    - Catching by `const &` involves zero copies and protects the original
 *      exception object from being modified.
 * ============================================================================
 */