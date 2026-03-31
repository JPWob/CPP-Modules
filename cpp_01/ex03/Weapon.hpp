#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>

class Weapon {

    public:
        Weapon(std::string type);
        const std::string& getType() const; //does not change the object → should be const.
        void setType(std::string newtype); //changes the object → cannot be const.

    private:

    std::string _type;
};

#endif


/*
Vergleiche
1️⃣ const std::string& getType();
2️⃣ const std::string& getType() const;

1️⃣ const before return type
    - the value that will be returned to the caller (in this case a string reference)
      can not be modified
    - ! But the function itself is still allowed to modify the object

2️⃣ () const after parentheses == Const function
    - the function cannot change the instance
    - all members of this instance are treated as read-only inside a () const function
    - therefore only const member functions are allowed on members inside this function
    - function can only be called on a constant object

    
    
    ✅ Summary
    
    std::string& Weapon::getType() const {}
    
    Inside a const member function:
    - All members of the instance are read-only.
    - You can only call other const functions on members.
    
    Calling const functions:
    ✅ Can be called on non-const instances ✅
    ✅ Can be called on const instances ✅
    
        Weapon club("club");
        const Weapon sword("sword");
        
        club.getType();  // ✅ OK, non-const instance
        sword.getType(); // ✅ OK, const instance

Calling non-const functions:
    ✅ Can only be called on non-const instances 
    ❌ cannot call on const instances


*/