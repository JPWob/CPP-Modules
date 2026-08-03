#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string _target;

protected:
	virtual void form_action() const;

public:
	//OCF
    PresidentialPardonForm(std::string target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

    const std::string& getTarget() const;
};

#endif


/*
When you create a child object like PresidentialPardonForm form("Target");:

1. Memory is allocated for the whole object (base members + child members).
2. The PresidentialPardonForm constructor calls the AForm::AForm(...) constructor.
3. After execution, the rest of PresidentialPardonForm's constructor executes.
*/