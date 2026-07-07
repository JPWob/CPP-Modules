/*
STL (Standard Template Library) Containers 
- are pre-written, highly optimized data structures 
- used to store and manage collections of objects in memory.
- use instead of manually building arrays, linked, lists or trees

You will learn how to write code that treats different underlying data structures identically, 
as long as they contain integers.


1. std::array<T, N> (Fixed Size)
    This is the standard library container that represents a fixed-size, 
    stack-allocated array. Its size must be known at compile time. 
    The size is stored with the variable type, takes up no memory.
    std::array<int, 5> takes up exactly... 20 bytes.
  ! You can go out of bounds without getting a compiler error or an immediate runtime crash.
        std::array<int,5> arr;
        arr[6] = 42;
  It looks like this:

    template <typename T, size_t N>
    class array {
        T _M_elems[N]; // A raw, stack-allocated C-style array
        
        // No _size variable needed! It just returns the template parameter N, which takes up no memory.
        constexpr size_t size() const { return N; } 
    };

2. A Custom Array<T> or std::vector<T> (Dynamic Size)

    A container where the size is passed at runtime (e.g., when a user passes a size to a constructor).
    
    template <typename T>
    class Array {
    private:
        T* _data; // Points to memory allocated on the heap
        size_t    _size; // MUST track the size here because the heap doesn't keep score!
    };

*/