#include <iostream>

class Base{
	public:
	virtual ~Base();

};

class A : public Base{
	public:
	int alpha;
	A(int a);
	~A();
};

class B : public Base{

	public:
	std::string string;
	B(std::string str);
	~B();

};

class C : public Base{
	public:
	char tschar;
	C(char c);
	~C();
};

/* Dynamik Casting

dynamic_cast is used exclusively for handling polymorphism at runtime. 
It is used to safely navigate down or across an inheritance hierarchy (downcasting).
	-helps to check the true Identity of an object (Base or derived?)
	-Upcasting: can convert a base class pointer/reference to a derived class pointer/reference (if object was created as a derived object!)
	-CrossCasting: If object inherits from more than one base class, you can
	 cast a pointer from one base parent directly to a sibling base parent.


!!! To do dynamik casting:
	Compiler needs information from the objects vtable at compile time.
	If Object has no virtual function, it has no vtable!

When you add virtual ~Base(), 
the compiler secretly alters the layout of your class in memory. 
It injects a hidden pointer called the vptr (virtual pointer) into the object.
	-The vtable contains pointers to all the virtual functions.
	-Crucially, the vtable also contains a pointer to a type_info object (RTTI (Runtime Type Information)) 
	  which stores the actual string name and type of the class at runtime.
If your object is not virtual, it is just raw data. There is no vptr, no vtable, and absolutely zero metadata stored in memory to identify what the object is.
*/