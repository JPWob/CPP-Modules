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
	std::cout << "Printing b: " << b << std::endl;
	std::cout << "Printing f: " << f << std::endl;



	Bureaucrat C("C", 50);
	Form Z("Z", 20, 50);
	try{
	Z.beSigned(C);
	}
	catch(const Form::GradeTooLowException& e){
        std::cerr << e.what() << std::endl;
	}
	std::cout << "Printing C: " << C << std::endl;
	std::cout << "Printing Z: " << Z << std::endl;

}