#include "whatever.hpp"

int main(){

}

/*
What types support all the comparison
operators? (<,>,,==, !=, <=, >=)

✅ Built-in (Primitive) Types
Integers:               int, short, long, long long, unsigned int, char, etc.
Floating-point numbers: float, double, long double.
Booleans:               bool (where false < true).

✅ Standard Library Types (The STL)
Strings:             std::string
Standard Containers: std::vector, std::list, std::deque, std::set. (Two vectors are compared element-by-element).
Utility types:       std::pair and std::tuple (compared element-by-element).

❌Pointers (Partial Failure / Dangerous)
    ✅ While pointers support comparison operators (comparing memory addresses)
    ❌void* (generic pointers) do not support relative comparisons like < or >.
        ->Because void* strips away all type information, 
          C++98 forbids using relative comparison operators (<, >, <=, >=) on them.
❌Built-in Raw Arrays
    int arr1[5];
    int arr2[5];
    (void)(arr1 < arr2); // ❌ Compiler Error!
❌Custom structs or classes (By Default)

*/