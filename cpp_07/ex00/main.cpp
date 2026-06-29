#include "whatever.hpp"

#define PRINT(var) std::cout << #var << " = " << var << std::endl;

int main( void ) { 
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0; 
}

// int main(){
//     int a = 100;
//     int b = 150;

//     swap(a, b);
//     PRINT(a);
//     PRINT(b);
//     std::cout << "Min: " << min(a, b) << std::endl;
//     std::cout << "Max: " << max(a, b) << std::endl;
// }

/*
What types support all the comparison
operators? (<,>,,==, !=, <=, >=)

✅ Built-in (Primitive) Types
Integers:               int, short, long, long long, unsigned int, char, etc.
Floating-point numbers: float, double, long double.
Booleans:               bool (false is < true).

✅ Standard Library Types (The STL)
Strings:             std::string
Standard Containers: std::vector, std::list, std::deque, std::set. (Two vectors are compared element-by-element).
Utility types:       std::pair and std::tuple (compared element-by-element).

❌ Pointers (Partial Failure / Dangerous)
    ✅ While pointers support comparison operators (comparing memory addresses)
    ❌ void* (generic pointers) do not support relative comparisons like < or >.
        ->Because void* strips away all type information, 
          C++98 forbids using relative comparison operators (<, >, <=, >=) on them.
❌ Built-in Raw Arrays
    int arr1[5];
    int arr2[5];
    (void)(arr1 < arr2); // ❌ Compiler Error!
❌ Custom structs or classes (By Default)

*/