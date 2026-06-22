#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
    // Orthodox Canonical Form
    Intern();
    ~Intern();
    Intern(const Intern& src);
    Intern& operator=(const Intern& src);

    // Core functionality
    AForm* makeForm(std::string formName, std::string target);

};

#endif