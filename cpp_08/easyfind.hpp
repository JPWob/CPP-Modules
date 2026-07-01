#include <iostream>
#include <vector>

template <typename T>
int easyfind(const T& container, int n){

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


*/