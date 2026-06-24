#include <iostream>

//g++ test.cpp -o test

int main(){
    int* p = new int(128);
    
    //unsigned char* ch = reinterpret_cast<unsigned char*>(p); //to avoid signed overflow
    char* ch = reinterpret_cast<char*>(p);
    //ch now stores the memory address of the very last byte of p
    //*ch is of size 1 byte
    //*ch holds the value of that last byte

                                  //dereference ch
    std::cout << "static_cast<int>(*ch): " << static_cast<int>(*ch) << std::endl;
    //: ch[0]
    std::cout << "ch[0]: " << static_cast<int>(ch[0]) << std::endl; //-128
    // Take the address of ch[0], cast it to an unsigned char pointer, then grab the value
    std::cout << "ch[0]: " << static_cast<int>(*reinterpret_cast<unsigned char*>(&ch[0])) << std::endl;
    std::cout << "static_cast<char>(*ch): " << static_cast<char>(*ch) << std::endl; 

    //*p is of size 4 bytes
    std::cout << "static_cast<int>(*p): " << static_cast<int>(*p) << std::endl; //Already an Int
    //reads 4 bytes, but static_cast<char> truncates it to the last one
    //(10000000 == 128), which is signed bit overflow so == -128 which has no Symbol (�)
    std::cout << "static_cast<char>(*p): " << static_cast<char>(*p) << std::endl; 

    std::cout << std::endl << "Reading an int byte by byte " << std::endl; 
    int x = 300;
    int* p1 = &x;
    char* ch1 = reinterpret_cast<char*>(p1);

    // ch points to Byte 0 (44)
    // ch + 1 points to Byte 1 (1)

    std::cout << "Byte 0 value: " << static_cast<int>(*ch1) << std::endl;       // Prints 44
    std::cout << "Byte 1 value: " << static_cast<int>(*(ch1 + 1)) << std::endl; // Prints 1

}

/*
eg with 128

The number 128 is simply too big to fit into a signed char's positive range, 
so it wraps around to the absolute lowest negative number possible.

eg with 42
static_cast<int>(*ch): 42
static_cast<char>(*ch): * //ASCII decimal 42 is '*' 

*/
