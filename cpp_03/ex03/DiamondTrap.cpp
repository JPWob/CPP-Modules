#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI(){
    std::cout << "I am a pure Diamond!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) :
    ClapTrap(name + "_clap_name"),
    FragTrap(name), 
    ScavTrap(name),
    _name(name)
{
    this->_hit = FragTrap::_hit;
    this->_ep = ScavTrap::_ep;
    this->_attack = FragTrap::_attack;
    std::cout << "DiamondTrap " << _name << " constructed." << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << _name << " destructed." << std::endl;
}

/*
Since FragTrap and ScavTrap both inherit from ClapTrap, 
your DiamondTrap currently has two copies of ClapTrap inside it. 
This causes total chaos when you try to access _hit or _name 
because the compiler doesn't know which "grandparent" to talk to.

To fix this, you must go back to your ScavTrap.hpp and FragTrap.hpp and 
add the virtual keyword to their inheritance. This tells C++:
"If someone inherits from both of us, only give them one shared copy of ClapTrap."

When you defined FragTrap and ScavTrap, you didn't give them
 a "default" constructor (one with no parameters). 
You told the compiler: "Every time a FragTrap is born, it must have a name."

The "Virtual" Bypass
Here is the weird part of the Diamond Problem:
In a normal inheritance chain, ScavTrap would call ClapTrap. 
But in a Virtual Inheritance chain, the "most derived" class 
(the one at the very bottom, DiamondTrap) is the only one allowed 
to initialize the grandparent (ClapTrap).
    -Even though you pass name to FragTrap(name), 
     FragTrap's attempt to talk to ClapTrap is ignored.
    -Even though you pass name to ScavTrap(name), 
     its attempt is also ignored.
    -Only the line ClapTrap(name + "_clap_name") actually 
     sets the name in the shared grandparent.

3. Why pass the name at all then?
If their calls to the grandparent are ignored, why not just pass nothing?
Syntax: As mentioned, the compiler won't let you call 
a constructor that requires a string without giving it a string.
Stat Logic: Even though the "naming" part of the parent constructors
is ignored, the other logic inside their constructors 
(like setting the HP or Energy points) still runs. 
You need them to initialize so your DiamondTrap gets 
its base stats before you overwrite them with the 
specific Diamond requirements.
*/