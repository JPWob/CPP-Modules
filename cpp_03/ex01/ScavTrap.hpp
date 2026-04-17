#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& src);
    ScavTrap(std::string name);
    ~ScavTrap();
	ScavTrap& operator=(const ScavTrap& src);

    // Overriding the attack function
    void attack(const std::string& target);
    void guardGate();
};
