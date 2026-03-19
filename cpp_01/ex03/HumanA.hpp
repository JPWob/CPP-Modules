#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA {

    public:

    HumanA(Weapon& w, const std::string& n = "HumanA");
    void attack();

    private:

    Weapon& _weaponA; //HumanA does not own the weapon //It references an existing Weapon
    std::string _name;
};

#endif



/*

HumanA(Weapon& weapon, std::string name );
    ➜ Pass name by value
    - copy of string is made when calling constructor
    - Inside the constructor, name is a local copy.

HumanA(Weapon& weapon, const std::string name);
    ➜ Pass by value + const
    - copy of string is made when calling constructor
    - You cannot modify the local name copy inside the constructor.
    - marking a by-value parameter const is usually pointless.
      Since it's already a copy, modifying it would not affect the caller anyway.

HumanA(Weapon& weapon, const std::string& name);
    ➜ Const reference
    - no copy is made
    - Cannot modify caller’s string.
    - Can bind to temporaries / Accepts literals

HumanA(Weapon& weapon, std::string& name);
    ➜ Non-const reference
    - No copy is made.
    - You are allowed to modify the caller’s string.
    - Problem: HumanA a(club, "Bob");  // ❌ compiler ERROR
    - Because: "Bob" becomes a temporary std::string
    - Non-const references like std::string& cannot bind to temporaries!!!

HumanA(Weapon& weapon, std::string& name);
HumanA::HumanA(Weapon& weapon, std::string& name) 
    : _weaponA(weapon), _name(name) {} 
HumanA a(club, "Bob"); 
would give compiling error? does "Bob" not live long enough to be copied to _name?



🔍 HumanA a(club, "Bob"); 
Why is a temporary std::string created when I pass "Bob"?
What is "Bob" in C++ really?

    - Parameter type for name is:   std::string& name
    - But "Bob" real type is:       const char[4]       (string literal, no string object)
    ❕ C++ must perform a conversion. The Types Must Match!
    
    The class std::string has a constructor like this:  std::string(const char* s);
    So the compiler does this automatically:            HumanA a(club, std::string("Bob"));
    ❗️ That expression: std::string("Bob") creates a temporary object while compiling
    That temporary exists only for the duration of the full expression.

❌ std::string& ref = std::string("Bob");  // ❌ illegal
- Temporary would be destroyed at ;
- ref would point to destroyed memory ==  Undefined behavior❗️
✅ const std::string& ref = std::string("Bob");
✅ If a temporary object is bound to a const reference, 
its lifetime is extended to match the lifetime of the reference.

Why C++ forbids binding non-const references to temporaries
    std::string& ref = std::string("Bob");  // ❌
    const std::string& ref = std::string("Bob");  // ✅



You cannot create a HumanA without passing a Weapon.
    == A HumanA will always have a weapon.

//Notice the parameter order must change because default arguments must come last.
*/