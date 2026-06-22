#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm{
private:
    std::string _target;

public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

    const std::string& getTarget() const;
    void execute(const Bureaucrat& executor) const; //"I will not change any member variables of this form while executing it."


};