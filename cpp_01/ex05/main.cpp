#include "Harl.hpp"

int main(){

	std::string line;
	Harl harl;
	
	std::cout 	<< "\U000026A0 Harls needs to complain."
				<<	" Choose between DEBUG, INFO, WARNING or ERROR!\n>>";
	while(1)
	{
		if(!std::getline(std::cin, line))
			return(0);
		harl.complain(line);


		std::cout 	<< "\U000026A0 Make Harl complain or type ENOUGH"
					<< " if you think you spread enough negativity :)\n>>";
	}

}

/*

in C:
char *s = NULL;

in C++
std::string s; //is never NULL!
	The equivalent of “no content” is: s.empty()

*/