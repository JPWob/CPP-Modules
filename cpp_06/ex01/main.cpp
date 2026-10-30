#include "Serial.hpp"

int main(){

	Data data;
	uintptr_t raw;

	(data).str = "Hello";
	(data).n = 42;

	raw = Serializer::serialize(&data); 								//returns the unsigned integer type uintptr_t
	std::cout << "Original pointer (&data):\t" << &data << std::endl;
    std::cout << "Serialized pointer(&data):\t" << raw << std::endl;

	
	//treat the bits (raw) as a memory address again
	Data *ptr = Serializer::deserialize(raw); //returns a Data*

	//test if the ptr created from uintptr_t raw is working
    std::cout << "String inside:  " << ptr->str << std::endl;
	//std::cout << "String inside:     " << raw.str << std::endl; not possible
	std::cout << "Int inside: " << ptr->n << std::endl;
}


/*
In computer memory, everything is ultimately stored as raw 1s and 0s (bits). 
The only thing that makes them "different things" is how the compiler chooses to interpret those bits.
The exact same 64 bits of data are viewed by the compiler depending on the variable type:


Data* data =  0x7ffee6cb7850 	//"This is a memory address. "This is a memory address. If the user uses ->, I should go to this destination and look for a std::string and an int
uintptr_t raw = 0x7ffee6cb7850	//"This is just a plain math number. The user can add to it, subtract from it, or multiply it


*/