#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int n){
    typename T::iterator it;
    for(it = container.begin(); it != container.end(); ++it){
        if(*it == n){
            return it;
        }
    }
    return container.end();
}


/*
std::find
In the STL, searching for an element is decoupled from the containers themselves 
and is instead handled by generic algorithms (like std::find) that operate via iterators.

Standard containers do not typically throw exceptions when a search fails. 
Instead, they return a special iterator that represents the past-the-end element.
    - If the element is found, it returns an iterator pointing to that element.
    - If the element is not found, it returns the end() iterator of the container.

1. The Explicit Iterator Loop (Under the Hood)

    std::vector<int> numbers = {10, 20, 30, 40};

    // 1. Initialization: Start at the beginning
    // 2. Condition: Loop until we hit the end
    // 3. Increment: Move the bookmark forward (++it)
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        
    // 4. Dereferencing: Use '*' to look at the value inside the bookmark
    std::cout << *it << " ";


How an Iterator Works (The Core Mechanics)

    - it is an abstract type
    - data type can change completely depending on the container
    - To the compiler, an iterator is almost always a class template object that has been written to mimic a pointer.
    - Because std::vector's iterator might be a raw pointer, while std::list's iterator is a heavy class object,
      C++ uses the template system to hide this complexity from you.


Iterators mimic the behavior of raw pointers by overloading a few standard operators. 
No matter what kind of complex container you are using, you navigate it the exact same way:

    ++it (Increment): Moves the iterator to the next element.
    *it (Dereference): Accesses the actual value at the current position (just like a pointer).
    == or != (Comparison): Checks if two iterators are pointing to the same place (crucial for stopping a loop).

container.end() is an iterator object
    - it is not the last element
    - it is not the size of the container
    - it is an iterator that points to the imaginary slot just after the last element.


Associative containers
- specialized data structures that store elements in a sorted order
- std::set/ std::map
- maps store data as key-value pairs (std::pair<Key, Value>)
- sets store unique keys.
- *it evaluates to a std::pair<const int, std::string>, not just a plain int -> more coplex
*/