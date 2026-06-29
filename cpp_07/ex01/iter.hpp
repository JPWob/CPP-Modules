#include <iostream>

template <typename T>
void print(const T& x) {
    std::cout << x << std::endl; // Works for any type that supports <<
}

template <typename T>
void increment(T& x) {
    x++; // Works for any type that supports ++
}

template <typename T, typename F>
void iter(T* array, const int length, F func){
    for(int i = 0; i < length; i++){
        func(array[i]);
    }
}




