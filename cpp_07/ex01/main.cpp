#include "iter.hpp"

int main(){

    int int_arr[] = {1, 2, 3};
    float float_arr[] = {1.1f, 2.2f, 3.3f};
    std::string array[] = {"Hello", "from", "CPP", "Module", "07"};

    int int_length = static_cast<int>(sizeof(int_arr) / sizeof(int_arr[0]));
    float float_length = static_cast<int>(sizeof(float_arr) / sizeof(float_arr[0]));
    int length = static_cast<int>(sizeof(array) / sizeof(array[0]));

    // Test with ints
    iter(int_arr, int_length, increment<int>);
    iter(int_arr, int_length, print<int>);

    // Test with floats
    iter(float_arr, float_length, increment<float>);
    iter(float_arr, float_length, print<float>);

    //test with strings
    //iter(array, length, increment<std::string>);
    iter(array, length, print<std::string>);
}

//sizeof(array) tells the computer the total size of the array in bytes, which means sizeof(array) returns 20 (5 elements × 4 bytes).