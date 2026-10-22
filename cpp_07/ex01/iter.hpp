#include <iostream>


// function template "iter" that takes 3 parameters and returns nothing.
template <typename T, typename F>
void iter(T* array, const int length, F func){
	if (!array)
        return;
	for(int i = 0; i < length; ++i){
		func(array[i]);
	}
}

template <typename T>
void print(const T& x) {
    std::cout << x << std::endl; // Works for any type that supports <<
}

template <typename T>
void increment(T& x) {
    x++; // Works for any type that supports ++
}


/*

Not good examples:

template <typename T>
void iter(T* array, size_t length, void (*func)(T&));

void (*func)(T&)

	- (*func)	pointer to a function
	- (T&)		The function it points to must take exactly one argument: a non-const reference to T

	Downside
	1. Because the argument is fixed as T&: You cannot pass a function taking const T&
	- You cannot use it on a const array
	- To support const, you would have to write a second overload:
		template <typename T>
		void iter(const T* array, size_t length, void (*func)(const T&));
	
	2. It Rejects Anything That Isn't a Plain Function
		- like Functors (Function Objects): A struct/class overloading operator(


*/ 



