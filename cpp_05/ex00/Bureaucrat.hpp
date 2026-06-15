#include <iostream>
#include <string>
#include <exception> // Required for std::exception


class Bureaucrat{
private:
	const std::string 	_name;
	int 				_grade;
	Bureaucrat(); 		//forcefully forbid anyone from ever using it

public:
	// Constructors & Destructor (Orthodox Canonical Form)
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);  

	const std::string& 	getName() const;
	int getGrade() const;
	void incrementGrade();
    void decrementGrade();

	class	GradeTooHighException : public std::exception{
	public:
		virtual const char* what() const throw();	//just a declaration, not a function body
	};

	class GradeTooLowException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
};

/*

Throwing an excpetion
- the whole point of throwing an exception is to avoid crashing or exiting the program
- Handle: Runtime Errors or Functions that cannot return a null/error value
	e.g.
	- Constrcutors (no return value)
	- Overload Operators (require an object reference as returntype, refernce cannot be null)
- Also: If an exception is thrown in a constructor, the object is never created!
	- A Constructor has no return value, so once called, you cannot stop creation with "return(-1);"
	- Throwing an exception is the only way to instantly self-destruct the constructor, abort object creation entirely, and guarantee that a corrupted object never exists.
- You can catch regular runtime errors, that would normally crash a program
	- ZeroDivisionError
	- IndexOutOfBoundsException / IndexError
	- FileNotFoundException / IOError
- You can also write your own expections: The Big Difference: if/else vs. Exceptions
	- An if/else statement is local. 
	  It forces you to deal with the problem right then and there, in that specific line of code.
	- The Pass The Potato Problem:
	  Imagine if using if/else, you have 5 layers of functions leading up to the check. Then you
	  have to return the error(eg return(-1)). Every single layer has to include an if/else block 
	  to pass that error code up to the user interface.
	- Using a Custom Exception (The "Express Elevator")
	  The moment it is thrown (throw), it shoots straight past all the middle functions until it 
	  finds a try/catch block—usually right at the user interface laye

int getGrade() const;
	- this function will never modify any member variables of the Bureaucrat class
	- good practise

const int getGrade();
	- Protects the returned copy
	- making the returned copy const is completely useless.

Ultimate best practice for std::string
	- const std::string& getName() const;
*/