#include <iostream>
/*

The template function must be written entirely inside .hppfile, not split into a .cpp file.
Because the compiler needs the full template definition available when it instantiates the types in main.cpp).

In C++, template <typename T> applies only to the single function or class definition 
that immediately follows it. It does not act as a global setting for the rest of the file.
T is a placeholder variable for a type.
*/

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T& a, const T& b){
    return((a < b) ? a : b);
}

template <typename T>
const T& max(const T& a, const T& b){
    return((a > b) ? a : b);
}
