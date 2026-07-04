#include "Span.hpp"



long long Span::longestSpan(){
	if(_vector.size() <= 1)
		throw std::logic_error("Not enough elements to find a span.");
	
	long long max_value = *std::max_element(_vector.begin(), _vector.end()); //returns an iterator, so *iterator to get the value
	long long min_value = *std::min_element(_vector.begin(),_vector.end());

	return static_cast<int>(max_value - min_value);
}

//Once the vector is sorted, the two closest numbers are guaranteed to be right next to each other.
long long Span::shortestSpan(){
	if(_vector.size() <= 1)
		throw std::logic_error("Not enough elements to find a span.");
	
	std::vector<int> cpy = _vector;
	std::sort(cpy.begin(), cpy.end());

	long long min_span = LLONG_MAX;

	for(size_t i = 0; i < cpy.size() -1; ++i)
	{
		long long span = cpy[i + 1] - cpy[i];
		if(span < min_span){
			min_span = span;
		}
	}
	return static_cast<int>(min_span);
}


void Span::addNumber(int value){
    if (_vector.size() + 1 > _N) {
        throw std::runtime_error("Cannot add random numbers: would exceed maximum capacity N.");
    }
    _vector.push_back(value);
}


void Span::addRandomNumbers(unsigned int quantity) {
    if (_vector.size() + quantity > _N) {
        throw std::runtime_error("Exceeds maximum capacity N.");
    }
    for (unsigned int i = 0; i < quantity; ++i) {
        _vector.push_back(std::rand());
	}
}


Span::Span(unsigned int N) : _N(N){

  _vector.reserve(N);
  //std::cout << "Span vector constructed" << std::endl;
}