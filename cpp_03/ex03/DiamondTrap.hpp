#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap{
private:
    std::string _name;

public:
    DiamondTrap(std::string name);
    ~DiamondTrap();

    using ScavTrap::attack;
    void whoAmI();

};

/*
When you create a DiamondTrap, you pass in one string (e.g., "robot").
You then use that string to fill both "name" slots,
but you modify one for ClapTrap.
*/