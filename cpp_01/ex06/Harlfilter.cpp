#include "Harlfilter.hpp"

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	void (Harl::*functionarray[4])(void) = 
	{
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

	int i;
	for(i = 0; i < 4; i++)
		if(level == levels[i])
			break;
	switch(i)
	{
		case 0:(this->*functionarray[0])();
		case 1:(this->*functionarray[1])();
        case 2:(this->*functionarray[2])();
        case 3:(this->*functionarray[3])(); break;
        default:
            std::cout << "You had one job\n..." << std::endl;
        break;
	}
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
	std::cout 	
	<< "[DEBUG]" << std::endl
	<< "I love having extra bacon for my" 
	<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" 
	<< std::endl;
}
void Harl::_info( void )
{
	std::cout 	
	<< "[INFO]" << std::endl
	<< "I cannot believe adding extra bacon costs more money. You didn’t put" 
	<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!" 
	<< std::endl;
}

void Harl::_warning( void )
{
	std::cout 	
	<< "[WARNING]" << std::endl
	<< "I think I deserve to have some extra bacon for free. I’ve been coming for"
	<< "years, whereas you started working here just last month." 
	<< std::endl;
}

void Harl::_error( void )
{
	std::cout 	
	<< "[ERROR]" << std::endl
	<< "This is unacceptable! I want to speak to the manager now." 
	<< std::endl;
}