#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB {

	public:

	HumanB(std::string n = "HumanB", Weapon* w = NULL);
	void set_weapon(std::string name);
	void attack();

	private:

	Weapon* _weapon;
	std::string _name;

};

#endif