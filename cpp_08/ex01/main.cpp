#include "Span.hpp"


int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)) ^ static_cast<unsigned int>(std::clock()) );

	Span sp(20005);
	
	std::cout << "Add numbers manually to my span" << std::endl;
	try{
		sp.addNumber(-1);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(8888);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception& e){
		std::cout << "Caught Exception: " << e.what() << std::endl;
		return 0;
	}

	std::cout << "Add Numbers Randomly " <<  std::endl;
	try{
		sp.addRandomNumbers(20000);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception&e ){
		std::cout << "Caught Exception: " << e.what() << std::endl;
		return 0;
	}

	//Create a vector filled with numbers
    std::vector<int> sourceVector;
    for (int i = 0; i < 1000; ++i) {
        sourceVector.push_back(std::rand());
    }
	
	Span empty(500);
	
	std::cout << "Add elements of a vector to my Span" <<  std::endl;
	try{
		empty.addItRange(sourceVector.begin(), sourceVector.end());
		std::cout << empty.shortestSpan() << std::endl;
		std::cout << empty.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception& e){
		std::cout << "Caught an exception: " << e.what() << std::endl;
		return 0;
	}

	return 0;
}