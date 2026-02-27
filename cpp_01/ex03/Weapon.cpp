#include "Weapon.hpp"

const std::string& Weapon::getType()
{
    return type; //no copy is made, cannot be nullptr, no ptr syntax
}


void Weapon::setType(std::string settype)
{
    type = settype;
    return;
}


/*

Returning a pointer:
const std::string* getType() const
{
    return &type; //address of type, no copy is made
                //must use Must use -> or * to acces value
}

*/