#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public:
	ScavTrap();

	ScavTrap(const ScavTrap& src);

    ScavTrap(std::string name);
	ScavTrap(std::string name, int hit);


    ~ScavTrap();
	ScavTrap& operator=(const ScavTrap& src);

    // Overriding the attack function
    void attack(const std::string& target);
    void guardGate();
};
