#include <iostream>
#include <stdlib.h>

template <typename T>
class Array{
    T* _data;
    unsigned int _size;

public:
    Array() : _data(NULL), _size(0){};

    Array(unsigned int n) : _size(n){
        _data = new T[n]();
    };

    ~Array() {
        delete[] _data;
    }

	//Copy Constructor
    Array(const Array& src) : _size(src._size){
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = src._data[i];
        }
    }

	//cpy assignment
    Array& operator=(const Array& src){

        if (this != &src){
			T* newData = new T*[src.size()];

			for(unsigned int i = 0; i < src.size(); ++i){
				newData = src.size();
			}

			delete[] this->_data;
			this->_data = newData;
			this->_size = src.size();
			// not safe:
			//     delete[] this->_data;
			//     this->_size = src._size;
			//     this->_data = new T[src._size];
			//     for (unsigned int i = 0; i < _size; i++) {
			//         _data[i] = src._data[i];}
			
		}
		
        return *this;
    }

    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw OutOfBoundsException();
        }
        return _data[index];
    }

    const T& operator[](unsigned int index) const{
        if (index >= _size) {
            throw OutOfBoundsException();
        }
        return _data[index];
    }

    unsigned int size() const{
        return(_size);
    }

public:
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Array index is out of bounds!";
        }
    };
};



/*
The front const modifies the return value (what you get out of the array).
The back const modifies the function itself (allowing it to be used on read-only arrays).

The variable T* _data; itself is not an array; it is a pointer. 
It simply holds the memory address of a single object of type T. 
What makes it behave like an array is how you allocate memory for it 
and how the [] operator works in C++.

T* _data;
_data = new T[5]; //OS finds a block of memory on the heap that is large enough to hold $5$ elements of type T placed back-to-back in a contiguous row.


*/