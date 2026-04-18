#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{ //tells the compiler: "Share this parent."
public:
	FragTrap();
    ~FragTrap();
	FragTrap(const FragTrap& src);
	FragTrap& operator=(const FragTrap &src);
    FragTrap(std::string name);

    void highFivesGuys(void);
};

#endif




/* Virtual in Frag and Scav Trap:

>>> Use virtual when you want to prevent a future child from this class having duplicate grandparents.

>> Virtual tells compiler that the Parent of this Class can be shared with someone else (who is willing to share)

>> Compiler: I will allocate exactly one memory space for the ClapTrap variables (_name, _hit, _ep, _attack) 

*/