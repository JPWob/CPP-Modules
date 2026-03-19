#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

const std::string& Weapon::getType() const
{
    return _type; //no copy is made, cannot be nullptr, no ptr syntax
}

void Weapon::setType(std::string newtype)
{
    _type = newtype;
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