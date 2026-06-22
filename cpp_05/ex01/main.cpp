#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){

	Bureaucrat b("b", 50);

	Form f("f", 50, 80);
	try{
		b.signForm(f);
	}
	catch(const Form::GradeTooLowException& e){
        std::cerr << e.what() << std::endl;
	}
}