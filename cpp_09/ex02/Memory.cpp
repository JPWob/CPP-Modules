/*

When you are inserting elements into the main chain:

std::vector::insert() CONTNINOUS MEMORY
- Forces the container to physically shift every single element 
  after the insertion point over by one slot in memory. This is highly expensive (O(n) time).
- if using std::find(...):
  Iterator is a Random-Access Iterator. 
  Doing binary search (std::lower_bound) on a vector is lightning fast (O(logn)) 
  because the computer can jump directly to the middle index in memory.



std::deque::insert() or std::list::insert() 
- Handle memory blocks or node pointers differently, making insertions at certain positions much faster.
- std::find(...)
  Has Bidirectional Iterators. A list cannot jump to the middle of memory. 
  If you use a generic template with std::lower_bound on a std::list, C++ will secretly only simulate 
  the binary search but really is incrementing the pointer one-by-one under the hood.

*/