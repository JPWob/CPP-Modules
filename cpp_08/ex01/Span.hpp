#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <climits>

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
    void addNumbers(Iterator begin, Iterator end) {
        
		//typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end); //more portable
        // for (Iterator it = begin; it != end; ++it) {     //Wrong!!! segfault if some passes begin and end in reverse
        //     ++distance;
        // }

        long long distance = std::distance(begin, end); // subtracts the two memory addresses: end - begin. (if its a continuous vector type like vector)
        if(distance < 0)
            throw std::runtime_error("Invalid iterator range: begin comes after end.");
        
        if (_vector.size() + (distance) > _N) {
            throw std::runtime_error("Cannot add as much numbers: would exceed maximum capacity N.");
        }
        _vector.insert(_vector.end(), begin, end);
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