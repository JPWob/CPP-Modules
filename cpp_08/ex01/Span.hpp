#include <iostream>
#include <vector>

class Span {
private:
    std::vector<int> _container;
    unsigned int _N;
public:
    Span(unsigned int N);


    void addNumber(int value){
        if (_container.size() + 1 > _N) {
            throw std::runtime_error("Cannot add random numbers: would exceed maximum capacity N.");
        }
        _container.push_back(value);
    };

    void addRandomNumbers(unsigned int quantity) {
    if (_container.size() + quantity > _N) {
        throw std::runtime_error("Exceeds maximum capacity N.");
    }
    for (unsigned int i = 0; i < quantity; ++i) {
        _container.push_back(std::rand()); 
    }
    }

    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        //typename std::iterator_traits<Iterator>::difference_type quantity = std::distance(begin, end); //portable
        // for (Iterator it = begin; it != end; ++it) {     //Wrong!!! segfault if some passes begin and end in reverse
        //     ++distance;
        // }
        long long distance = std::distance(begin, end); // subtracts the two memory addresses: end - begin. (if its a continuous container type like vector)
        if(distance < 0)
            throw std::runtime_error("Invalid iterator range: begin comes after end.");
        
        if (_container.size() + (distance) > _N) {
            throw std::runtime_error("Cannot add random numbers: would exceed maximum capacity N.");
        }
        _container.insert(_container.end(), begin, end);
    }

    // int shortestSpan();
    // int longestSpan();
};


/*

_container.insert(_container.end(), begin, end);
    _container.insert(where to put them inside _container, where the src data starts , where the src data ends.)


Breaking down the syntax:
This is the heavy type name for the iterator variable.
    std::vector<int>::const_iterator it

In your template function, because the container is generic and const, this becomes 
    typename T::const_iterator).


*/