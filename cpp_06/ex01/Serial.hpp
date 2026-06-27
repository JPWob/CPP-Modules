#include <iostream>
#include <stdint.h>
#include "data.hpp"

class Serializer{
    private:
    // Orthodox Canonical Form (Private to prevent instantiation)
    Serializer();
    Serializer(const Serializer& src);
    Serializer& operator=(const Serializer& src);
    ~Serializer();

    public:
    static uintptr_t serialize(Data* data);
    static Data* deserialize(uintptr_t raw);
};

/*
1. struct vs class in C++
    In C++, the only technical difference between a struct and a class is the default visibility:
    - struct: Members are public by default.
    - class: Members are private by default.

uintptr_t: An unsigned integer type guaranteed to be large enough to hold a pointer without losing data. On a 32-bit system, it is 32 bits; on a 64-bit system, it is 64 bits.

uintptr_t serialize(Data* ptr);
It takes a pointer and converts it to the unsigned integer type uintptr_t.

*/