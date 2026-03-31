#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB {

public:

	HumanB(std::string n = "HumanB");
	void setWeapon(Weapon &w);
	void attack();

private:

	std::string _name;
	Weapon *_weapon;

};

#endif