#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <ctime>
#include <exception>

class Span {
private:
    std::vector<int> _vector;
    unsigned int _N;
public:
    Span(unsigned int N);

	long long shortestSpan();
	long long longestSpan();

    void addNumber(int value);
    void addRandomNumbers(unsigned int quantity);

    template <typename Iterator>
    void addItRange(Iterator begin, Iterator end) {
        
        // subtracts the two memory addresses: end - begin. (if its a continuous vector type like vector)
        long long distance = std::distance(begin, end);

        // most robust way to write it in C++, gets the correct distance type dynamically
		//typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end); 
        
        if(distance < 0)
            throw std::runtime_error("Invalid iterator range: begin comes after end.");

        if ((_N - _vector.size()) < static_cast<unsigned int>(distance)) {
            throw std::runtime_error("Cannot add as much numbers: would exceed maximum capacity N.");
        }
        _vector.insert(_vector.end(), begin, end); //Insert the range in a single call
    }

};


/*

_vector.insert(_vector.end(), begin, end);
    _vector.insert(where to put them inside _vector, where the src data starts , where the src data ends.)


Breaking down the syntax:
This is the heavy type name for the iterator variable.
    std::vector<int>::const_iterator it

In your template function, because the vector is generic and const, this becomes 
    typename T::const_iterator).


*/