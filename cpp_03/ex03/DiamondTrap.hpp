#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name;

public:
	DiamondTrap();
    ~DiamondTrap();
	DiamondTrap(const DiamondTrap& src);
	DiamondTrap& operator=(const DiamondTrap& src);
    DiamondTrap(std::string name);

    using ScavTrap::attack;
    void whoAmI();

};

/*The Core Hierarchy

Usually, ScavTrap and FragTrap would be the ones to build the ClapTrap part, because they are directly derived from it
 
1. The Grandparent (Base Class): ClapTrap
	This is the root. It knows nothing about the others.

2. The Parents (Derived from ClapTrap): ScavTrap and FragTrap
	They are children of ClapTrap.
	They are parents of DiamondTrap.

3. The Child: DiamondTrap
	This is the most derived class. It is the child of both ScavTrap and FragTrap.
	Can see everything in its parents and grandparent
*/