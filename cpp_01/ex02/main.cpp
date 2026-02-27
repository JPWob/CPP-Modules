#include "Zombie.hpp"

int main ()
{
	std::string name = "Hi THIS BRAIN";
	
	std::string *stringPTR = &name; //stores address of name
	std::string &stringREF = name; //alias of name; another name bound to the same storage location
	
	
	
	
	
	return 0;
}



/*

Both lines print the same memory address.:

int x = 42;
int& ref = x;

std::cout << &x << std::endl;
std::cout << &ref << std::endl;

------

int x = 5;
int* p = &x;   // pointer p has its own address
int& r = x;    // reference r does not


Why references?
- large objects are expensive to copy (Performance, storage)
	
	void foo(std::string s);   // copies
	void foo(const std::string& s);  // no copy
- const & avoids copying while preventing modification.
- standard practice in modern C++ APIs.
- in C, to modify a callers variable, you needed to pass a pointer
	increment(&a); 
	void increment(int* x)
	{
		(*x)++; //dereferencing operator
	}
- in C++ : increment(a); 
	void increment(int& x)
	{
		x++;
	}

Use references when:

✔ You want to avoid copying
✔ You want to modify caller’s object
✔ The parameter must not be null
✔ You want cleaner syntax than pointers

Use pointers when:

✔ Null is a valid state
✔ You need reseating
✔ You model optional relationships
✔ You manage dynamic memory

Reseating:

With Pointers: ALLOWED
	int a = 10;
	int b = 20;

	int* p = &a;  // p points to a
	p = &b;       // reseating → now p points to b

With References (Not Allowed)
	int a = 10;
	int b = 20;

	int& r = a;  // r refers to a
	r = b;       // NOT reseating, This does not make r refer to b.
				 // instead, it  assigns b's VALUE to a

C++ introduces references to allow safe aliasing of memory.
    char &c = s[i];

Use references (&) when:
    -You want a safe alias to an existing object
    -No need for pointer syntax (*)
    -Guaranteed to never be null
    -Cannot be rebound to another object (reseated)
    int x = 42;
    int &r = x;  // r is a reference to x
    r = 99;      // modifies x directly, note how it is automatically dereferenced
    r is not a new variable — it’s just another name for x.
    int &r2;     // ❌ ERROR: cannot declare a reference without binding

In C, aliasing is manual and requires pointers. Mistakes are easy: 
dangling pointers, accidental modification, or undefined behavior from misused memory.

Pointers still exist in c++.
| Feature                           | Pointer (`int* p`) | Reference (`int &r`)            |
| --------------------------------- | ------------------ | ------------------------------- |
| Syntax to access value            | `*p`               | `r`                             |
| Can be null?                      | Yes                | No                              |
| Can be rebound to another object? | Yes                | No (fixed after initialization) |
| Aliases memory?                   | Yes                | Yes                             |
| Safer / less error-prone?         | Less               | More                            |

User Input 
Numbers / tokens → std::cin >>
Full lines → std::getline

Multiple values
int a, b;
std::cin >> a >> b;
input like: 10 20

Reading a string (single word)
std::string name;
std::cin >> name;
std::cout << "Hello " << name << std::endl;

Reading a full line (with spaces)
std::string line;
std::getline(std::cin, line);
std::cout << line << std::endl;

Common pitfall: cin before getline

*/