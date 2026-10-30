#include "whatever.hpp"


int main( void ) { 
    int a = 2;
    int b = 3;

    swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::cout << std::endl;
	
	std::string s1 = "chaine1";
    std::string s2 = "chaine2";
    swap(s1, s2);
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "min( s1, s2 ) = " << ::min( s1, s2 ) << std::endl;
    std::cout << "max( s1, s2 ) = " << ::max( s1, s2 ) << std::endl;
	std::cout << std::endl;

	double d1 = 1.33;
	double d2 = 2.33;
	swap(d1, d2);
    std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
    std::cout << "min( d1, d2 ) = " << ::min( d1, d2 ) << std::endl;
    std::cout << "max( d1, d2 ) = " << ::max( d1, d2 ) << std::endl;
	std::cout << std::endl;
    return 0; 
}


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



// Force the compiler to validate all 6 comparison operators.
    // The (void) cast prevents "unused expression" compiler warnings.
    (void)(a < b);
    (void)(a > b);
    (void)(a <= b);
    (void)(a >= b);
    (void)(a == b);
    (void)(a != b);
*/