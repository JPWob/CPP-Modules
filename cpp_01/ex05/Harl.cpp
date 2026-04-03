#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "ENOUGH"};
	
	void (Harl::*functionpointers[5])(void) = 
	{
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error,
		&Harl::_enough
    };

	int i;
	for(i = 0; i < 6; i++)
		if(level == levels[i])
			return((this->*functionpointers[i])());
	
	std::cout << "You had one job\n..." << std::endl;
	return;

}


/*
	Step 1 — Start with a normal member function
		void Harl::debug(void){...}; 
			//inside the Harl class

	Step 2 — Declare a function pointer *f
		void (*fptr)(void); 
		void (Harl::*fptr)(void); 
			// Harl:: → this function belongs to the class
			// *fptr → function pointer named fptr
			// “fptr is a pointer to a function inside Harl that takes no arguments and returns void”
	
	Step 3 — Assign a function to it
		ptr = &Harl::debug;
			//adress of function

	Step 4 — Call it
		(this->*func)();
			// this → current object
			// *func → dereference the function pointer
			// () → call it

	Step 5 — Now scale it to an array
		void (*farray[])(void);
		void (Harl::*farray[4])(void);
			//farray is an array of 4 pointers
			//each pointer points to a Harl member function
	
	Step 7 — Calling function from farray
		(this->*farray[i])();
			//this → current object
	
	// Step 1: define a type
	typedef void (Harl::*FuncPtr)(void);

	// Step 2: create array
	FuncPtr functions[4];

	// Step 3: assign values
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;

*/	


void Harl::_debug( void )
{	
	std::cout 	<< "I love having extra bacon for my" 
	<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" 
	<< std::endl;
}
void Harl::_info( void )
{
	std::cout 	<< "I cannot believe adding extra bacon costs more money. You didn’t put" 
	<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!" 
	<< std::endl;
}

void Harl::_warning( void )
{
	std::cout 	<< "I think I deserve to have some extra bacon for free. I’ve been coming for"
	<< "years, whereas you started working here just last month." 
	<< std::endl;
}

void Harl::_error( void )
{
	std::cout 	<< "This is unacceptable! I want to speak to the manager now." 
				<< std::endl;
}

void Harl::_enough( void )
{
	std::cout 	<< "BOOOOORING!" 
				<< std::endl;
	exit(EXIT_SUCCESS);
}