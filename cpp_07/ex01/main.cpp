#include "iter.hpp"

int main(){

	int int_arr[] = {1, 2, 3};
    float float_arr[] = {1.1f, 2.2f, 3.3f};
    const std::string array[] = {"Hello", "from", "CPP", "Module", "07"};

    int 	int_length 		= 	static_cast<int>(sizeof(int_arr) / sizeof(int_arr[0]));
    float 	float_length 	= 	static_cast<int>(sizeof(float_arr) / sizeof(float_arr[0]));
    int 	length			= 	static_cast<int>(sizeof(array) / sizeof(array[0]));

    // Test with int
	iter(int_arr, 3, print<int>);
    iter(int_arr, 3, increment<int>);  //Error because array is const
	std::cout << "Incremented" << std::endl;
    iter(int_arr, int_length, print<int>);
	std::cout << std::endl;

    // Test with floats
    iter(float_arr, float_length, print<float>);
    iter(float_arr, float_length, increment<float>);
	std::cout << "Incremented" << std::endl;
	iter(float_arr, float_length, print<float>);
	std::cout << std::endl;

    //test with strings
    //iter(array, length, increment<std::string>);
    iter(array, length, print<std::string>);
}

// sizeof(array) tells the computer the total size of the array in bytes, which means sizeof(array) returns 20 (5 elements × 4 bytes).


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

