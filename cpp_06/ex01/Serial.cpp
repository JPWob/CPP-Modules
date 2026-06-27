#include "Serial.hpp"

uintptr_t Serializer::serialize(Data* data) { //take ptr,return int
    return reinterpret_cast<uintptr_t>(data);
}

Data* Serializer::deserialize(uintptr_t raw) { //take int, return pointer
    return reinterpret_cast<Data*>(raw);
}

//OC Form 
Serializer::Serializer(){}
Serializer::Serializer(const Serializer& src) {
    (void)src;
}
Serializer& Serializer::operator=(const Serializer& src) {
	(void)src;
	return *this;
}
Serializer::~Serializer(){}
