#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
public:
	FragTrap();
    ~FragTrap();
	FragTrap(const FragTrap& src);
    FragTrap(std::string name);
	FragTrap& operator=(const FragTrap &src);

    void highFivesGuys(void);
};

#endif