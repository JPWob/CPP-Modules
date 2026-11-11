#include <algorithm>  
#include "easyfind.hpp"

//std::find Returns an iterator to the first element in the range [first,last) that compares equal to val. If no such element is found, the function returns last.

int main() {
    std::vector<int> numbers; //= {10, 20, 30, 40}; Initilazier list does not exist in +98

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        
        std::cout << *it << " "; 
    }

    std::cout << std::endl;
    std::cout << "std::find 20: " << *(std::find(numbers.begin(), numbers.end(), 20)) << std::endl;
    std::cout << "easyfind  20: " << *(easyfind(numbers, 20)) << std::endl;
    
    //testing return value of my easyfind
    int test = -1;
    std::vector<int>::iterator it_ori;
    std::vector<int>::iterator it_mine;

    it_ori = std::find(numbers.begin(), numbers.end(), test);
    it_mine = easyfind(numbers, test);

    // std:: function:
    if(it_ori == numbers.end()){
        std::cout << "No occurence of " << test << " in T." << std::endl;
    }
    else
        std::cout << "std::find " << test << ": " << *(it_ori) << std::endl;

    // my function:
    if(it_mine == numbers.end()){
        std::cout << "No occurence of " << test << " in T." << std::endl;
    }
    else
        std::cout << "easyfind  " << test << ": " << *(it_mine) << std::endl;
}

/*
Breaking down the syntax:
This is the heavy type name for the iterator variable.
    std::vector<int>::const_iterator it

In your template function, because the container is generic and const, this becomes 
    typename T::const_iterator it

*it
The asterisk is the dereference operator. It means: "Don't print the bookmark itself; print the actual integer the bookmark is pointing to right now."
    
*/