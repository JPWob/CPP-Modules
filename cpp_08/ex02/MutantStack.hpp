#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>{
public:
	




}









/*
STD::STACK
The interface for std::stack is deliberately minimal. 
It only supports a handful of core operations, all of which run in O(1) constant time:

-LIFO Management: Elements are inserted (pushed) and extracted (popped) from the same end, known as the top of the stack.
-Container Adaptor: It isn't a standalone data structure built from scratch. 
 Instead, it "wraps" around an existing standard container (like std::deque | std::vector | std::list) 
 and restricts its interface to mimic a stack.
-Default Underlay: By default, if you don't specify a container type, std::stack uses std::deque behind the scenes.
-

push(value) / emplace(...) 	Adds an element to the top of the stack.
pop()						Removes the element at the very top. (Note: This returns void, it does not return the value!)
top()						Returns a reference to the element at the top without removing it.
size()						Returns the number of elements currently in the stack.
empty()						Returns true if the stack has no elements, false otherwise.


STD::DEQUE
- Double-Ended Queue,
- std::deque gives you the best of both worlds between a std::vector and a std::list
- While a std::vector is like a straight line that only grows efficiently at the very end, 
  a std::deque is designed to grow dynamically at both the front and the back with equal efficiency.
- It allocates memory in multiple small, fixed-size chunks. 
  It then maintains a central pointer array (a "map") that keeps track of where all these chunks are located in RAM.
  = no reallocations
  = fast insertion in 0(1) time at both ends
- Frequent Shrunk/Grow Safety: Stacks constantly grow and shrink. 
  ->std::deque handles freeing up individual memory chunks when they are no longer needed 
    much more gracefully than a vector, which holds onto its allocated capacity 
	unless explicitly told to shrink.


*/