#include <iostream>

template <typename T>
class Array{
    T* _data;
    unsigned int _size;

public:
    Array() : _data(nullptr), _size(0){};

    Array(unsigned int n) : _size(n){
        _data = new T[n]();
    };

    ~Array() {
        delete[] _data;
    }

    Array(const Array& src) : _size(src._size){
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = src._data[i];
        }
    }

    Array& operator=(const Array& src){
        if (this != &src){
            delete[] this->_data;
            this->_size = src._size;
            this->_data = new T[src._size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = src._data[i];}
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
*/
