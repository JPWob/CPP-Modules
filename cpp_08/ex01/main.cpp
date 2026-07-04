#include "Span.hpp"
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Span sp = Span(10005);
	sp.addNumber(-1);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(8888);
	 
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	sp.addRandomNumbers(10000);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}