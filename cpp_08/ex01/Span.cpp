#include <limits>
#include "Span.hpp"

// int -2,147,483,647 to +2,147,483,647
// possible int range 4,294,967,295
// long long is guaranteed to be at least 64 bits on every modern compiler and platform. 
// long on Windows 64-bit is only 32 bits, like int

long long Span::longestSpan(){
	if(_vector.size() <= 1)
		throw std::logic_error("Not enough elements to find a span.");
	
	long long max_value = *std::max_element(_vector.begin(), _vector.end()); //returns an iterator, so *iterator to get the value
	long long min_value = *std::min_element(_vector.begin(),_vector.end());

	return (max_value - min_value);
}

long long Span::shortestSpan(){

	if(_vector.size() <= 1)
		throw std::logic_error("Not enough elements to find a span.");
	
	std::vector<int> cpy = _vector;

	//Once the vector is sorted, the two closest numbers are guaranteed to be right next to each other.
	std::sort(cpy.begin(), cpy.end());

	long long min_span = std::numeric_limits<long long>::max();

	for(size_t i = 0; i < cpy.size() - 1; ++i)
	{
		long long span = cpy[i + 1] - cpy[i];
		if(span < min_span){
			min_span = span;
		}
	}
	return (min_span);
}


void Span::addNumber(int value){
    if (_vector.size() + 1 > _N) {
        throw std::runtime_error("Cannot add random numbers: would exceed maximum capacity N.");
    }
    _vector.push_back(value);
}


void Span::addRandomNumbers(unsigned int quantity) {
	// eg. 70 already inside + 40 quantity > _N(100)
    if (_vector.size() + quantity > _N) {
        throw std::runtime_error("Exceeds maximum capacity N.");
    }
    for (unsigned int i = 0; i < quantity; ++i) {
        _vector.push_back(std::rand());
	}
}


Span::Span(unsigned int N) : _N(N){
	_vector.reserve(N);
}

Span::Span(const Span& src) : _vector(src._vector), _N(src._N){
}

Span& Span::operator=(const Span& other){
	if(this != &other){
		this->_vector = other._vector;
		this->_N = other._N;
	}
	return *this;
}

Span::~Span(){};