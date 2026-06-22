#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string _target;

public:
    PresidentialPardonForm(std::string target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

    const std::string& getTarget() const;
    void execute(const Bureaucrat& executor) const;
};

#endif