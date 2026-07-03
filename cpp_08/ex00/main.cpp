#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40};

    // 1. Initialization: Start at the beginning
    // 2. Condition: Loop until we hit the end
    // 3. Increment: Move the bookmark forward (++it)
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        
        // 4. Dereferencing: Use '*' to look at the value inside the bookmark
        std::cout << *it << " "; 
    }
}

/*
Breaking down the syntax:
This is the heavy type name for the iterator variable.
    std::vector<int>::const_iterator it

In your template function, because the container is generic and const, this becomes 
    typename T::const_iterator).

*it
The asterisk is the dereference operator. It means: "Don't print the bookmark itself; print the actual integer the bookmark is pointing to right now."
    
*/