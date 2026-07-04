
/*
1. Adding Elements

push_back(value): Adds an element to the very end of the vector.
emplace_back(args...): Similar to push_back, but constructs the element in-place at the end of the vector using the provided arguments. This is often more efficient because it avoids temporary object copies.
insert(iterator, value): Inserts an element at a specific position (defined by an iterator). Note that inserting in the middle of a vector can be slow ($O(n)$) because it has to shift all subsequent elements.
						:Inserting a Range from Another Container
2. Removing Elements
pop_back(): Removes the very last element. It doesnt return the value, it just deletes it.
erase(iterator) or erase(start_iterator, end_iterator): Removes an element at a specific position, or a range of elements. Like insert, erasing from the middle requires shifting elements.
clear(): Removes all elements from the vector, leaving it with a size of 0.

3. Accessing Elements
operator[] (e.g., vec[i]): Quick, direct access to the element at index i. Warning: It does not check if the index is out of bounds, which can cause crashes if you aren't careful.
at(i): Accesses the element at index i, but does include bounds checking. If i is out of bounds, it throws an std::out_of_range exception. Its safer but slightly slower than []
front(): Returns a reference to the very first element.
back(): Returns a reference to the very last element.

4. Size and Capacity
size(): Returns the number of elements currently inside the vector.
empty(): Returns true if the vector has no elements (size() == 0). It is generally preferred over vec.size() == 0 for readability.
capacity(): Returns the total number of elements the vector can hold before it needs to allocate more memory.
reserve(n): Tells the vector to pre-allocate enough memory to hold at least n elements. Use this if you know youre about to add a lot of items, as it prevents the vector from constantly reallocating memory behind the scenes.

5. Iterators
begin(): Returns an iterator pointing to the first element.
end(): Returns an iterator pointing to the element past the last element.

Iterator
The definition of an iterator changes depending on the container. This is where the beauty of the C++ Standard Library shines: iterators provide a uniform interface regardless of how the data is stored.
Container    				What the Iterator Actually Is
std::vector / std::array	Essentially a raw pointer (direct memory address).
std::list (Linked List)		A wrapper around a pointer to a Node (which contains the data and a pointer to the next node).
std::map (Binary Tree)		A wrapper around a pointer to a Tree Node (with links to parent/child nodes).
*/

