#include "iter.hpp"

int main(){

	int int_arr[] = {1, 2, 3};
    float float_arr[] = {1.1f, 2.2f, 3.3f};
    const std::string array[] = {"Hello", "from", "CPP", "Module", "07"};

    int 	int_length 		= 	static_cast<int>(sizeof(int_arr) / sizeof(int_arr[0]));
    float 	float_length 	= 	static_cast<int>(sizeof(float_arr) / sizeof(float_arr[0]));
    int 	length			= 	static_cast<int>(sizeof(array) / sizeof(array[0]));

    // Test with int
	std::cout << "Print Integer" << std::endl;
	iter(int_arr, 3, print<int>);
    iter(int_arr, 3, increment<int>);  //Error because array is const
	std::cout << "Incremented" << std::endl;
    iter(int_arr, int_length, print<int>);
	std::cout << std::endl;

    // Test with floats
	std::cout << "Print Floats" << std::endl;
    iter(float_arr, float_length, print<float>);
    iter(float_arr, float_length, increment<float>);
	std::cout << "Incremented" << std::endl;
	iter(float_arr, float_length, print<float>);
	std::cout << std::endl;

    //test with strings
	std::cout << "Print String" << std::endl;
    iter(array, length, print<std::string>);
    //iter(array, length, increment<std::string>);
}

// sizeof(array) tells the computer the total size of the array in bytes, which means sizeof(array) returns 20 (5 elements × 4 bytes).



