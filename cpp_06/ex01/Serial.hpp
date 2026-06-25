#include <iostream>

class Serializer{
    public:
    static uintptr_t serializer(Data* ptr);
    static Data* deserialize(uintptr_t raw);



}

/*
uintptr_t: An unsigned integer type guaranteed to be large enough to hold a pointer without losing data. On a 32-bit system, it is 32 bits; on a 64-bit system, it is 64 bits.

*/