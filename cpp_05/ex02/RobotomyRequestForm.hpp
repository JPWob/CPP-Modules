#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

protected:
	virtual void form_action() const;

public:

	//OCF
    RobotomyRequestForm(std::string target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

    const std::string& getTarget() const;
};
  
#endif


/*
Random numbers in C
Computers cannot generate truly random numbers on their own; 
they use mathematical formulas to generate a sequence of numbers that look random. 
This sequence relies on a starting number called a seed.

1)
You seed once (=generate a sequence) with std::srand() or std::srand(std::time(nullptr));
Then call std::rand() as many times as you need.

3) Why only once?
Because calling std::srand() resets the generator.
For example:
    std::srand(123);
    std::cout << std::rand() << '\n';  // 52 (example)
    std::srand(123);
    std::cout << std::rand() << '\n';  // 52 again

4)
Same goes for std::srand(std::time(nullptr)); 
because multiple functioncalls in a row can have the same time stamp,
therfore the same seed.
int getRandom()
{
    std::srand(std::time(nullptr));
    return std::rand();
}

*/