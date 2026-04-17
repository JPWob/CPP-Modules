#include "DiamondTrap.hpp"


void DiamondTrap::whoAmI(){
	std::cout << "I am a pure Diamond! My Name is \"" << _name << "\"." 
	<< " But my Parents name is \"" << FragTrap::_name << "\"" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{	
	std::cout 	<< "DiamondTrap assignment operator on \"" << _name << "\" called." << std::endl;
	if(this != &src)
	{
		ClapTrap::operator=(src);
		this->_name = src._name; 
	}
	return *this;
}


//Def Constructor
DiamondTrap::DiamondTrap() :
	ClapTrap("default_clap_name"),
	ScavTrap("default"),			//Call to Claptrap(name) ignored, rest of instructions in Scav Constructor executed
	FragTrap("default"),			//Call to Claptrap(name) ignored, rest of instructions in Frag Constructor executed
	_name("default")
{
	//Parent constructors are finished, now we set our values
	this->_hit = 100;   
    this->_ep = 50;
    this->_attack = 30;
	std::cout << "DiamondTrap " << _name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) :
	ClapTrap(src), 
    ScavTrap(src),	//good practice
    FragTrap(src)	//good practice
{
	std::cout << "DiamondTrap Copy Constructor called. Taking values from \"" << src._name <<  "\"." << std::endl;
	this->_name = src._name;
	*this = src;
}

DiamondTrap::DiamondTrap(std::string name) :
    ClapTrap(name + "_clap_name"), 		//only Diamond is allowed to Construct ClapTrap
    ScavTrap(name), 					//this would call Claptrap(name)-> ignored!
    FragTrap(name), 					//this would call Claptrap(name)-> ignored!
    _name(name) 						//ok
{
	this->_hit = 100;   
    this->_ep = 50;
    this->_attack = 30;
    std::cout << "DiamondTrap \"" << _name << "\" constructed." << std::endl;
}


DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap \"" << _name << "\" destructed." << std::endl;
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

The "" Bypass
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


/*Inheritance

Since ScavTrap and FragTrap are sharing the same ClapTrap, C++ doesn't want them fighting over how to initialize it.
>>> The Rule: DiamondTrap is the only one allowed to call the ClapTrap constructor directly.
>>> Calls to ClapTrap Constructor from Scav/Frag are ignored, so the ClapTrap::_name variable remains unchanged


*/

/* What is stored in memory, when the Default Diamond Constructor is finished?
>>>
When the DiamondTrap constructor is finished, all three classes (ClapTrap, ScavTrap, FragTrap) 
are actually looking at the exact same memory addresses for their attributes.

*/

/*
/----------The Conflict (The Overwriting)-------\
>>>
Because you declared ScavTrap and FragTrap as virtual public ClapTrap, 
the computer creates only one ClapTrap sub-object in memory for your DiamondTrap!
>>>
When you call DiamondTrap(), C++ follows the construction order. 
Here is what happens to that shared "whiteboard" (the HP, EP, and AD variables):

Step 1: ClapTrap Constructor runs.
	It writes on the whiteboard: HP: 10, EP: 10, AD: 0.

Step 2: ScavTrap Constructor runs.
	It looks at the whiteboard and says "I need to change these!"
	It erases the old numbers and writes: HP: 100, EP: 50, AD: 20.

Step 3: FragTrap Constructor runs.
	It looks at the same whiteboard and says "No, I need to change these!"
	It erases the ScavTrap numbers and writes: HP: 100, EP: 100, AD: 30.

By the time it gets to your DiamondTrap body, the "whiteboard" says:
HP: 100, EP: 100, AD: 30 (The FragTrap values).
*/

/*

If the variables had unique names (like _diamondName and _clapName), 
you would not need the ClapTrap:: prefix. You could simply use the variable names directly.
*/