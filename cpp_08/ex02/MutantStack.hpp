#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>{
public:
	/*
	To make MutantStack Iterable, define template iterators to use
		- use typedef
		- Normally
			$ typedef std::vector<int>::iterator iterator;
		
		- For a default std::stack<int> defining it look like
			$ typedef std::stack<int>::container_type::iterator iterator; //You define iterator, but you have no way to get an iterator from a standard stack
			>> defaults to typedef  std::deque<int>::iterator iterator)
		
		- In case of template, where T (data type) and container_type are unknown
			$ typedef typename std::stack<T>::container_type::iterator iterator;
	*/
	// Container stands for std::stack<T, Container>::container_type
    // typedef is creating a shortcut nickname for a type.
    // typename is reassuring the compiler that a nested template match is a type and not a variable.
    // A const_iterator allows you to read the data, but prevents you from accidentally modifying it
    // A const_iterator acts like a pointer-to-const data: the iterator itself is free to move around and point to different positions in memory, but you cannot use it to modify the values it points to

	
	// Default Constructor | Usag: MutantStack<int> default;
    MutantStack() : std::stack<T, Container>(){};

	// Container Constructor
	// Usage: std::deque<int> d = {1, 2, 3}; MutantStack<int> myStack(d);
    MutantStack(const typename std::stack<T, Container>::container_type& container) 
		: std::stack<T, Container>(container){};

	// Copy Constructor
	// use std::stack copy constructor because variables live in there anyway
    MutantStack(const MutantStack& src)
		: std::stack<T, Container>(src) {}

	// Copy Assignment
	// use std::stack because variables live in there anyway
    MutantStack& operator=(const MutantStack& src){
        if(this != &src){
            std::stack<T, Container>::operator=(src);
        }
        return *this;
    };

    ~MutantStack(){};


    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    /* 
		Because MutantStack is a template class, the compiler cannot immediately see 
		the members of the base class during the first phase of parsing.
		By tying c to this->, you turn c into a dependent name and enforce the Two-Phase Lookup: waiting until instantiation time to look up those dependent names
    */
	iterator begin() {
        return this->c.begin(); 
    }

    iterator end() {
        return std::stack<T, Container>::c.end();  //other way to write it
    }


    const_iterator begin() const{    //compiler automatically changes the type of the this pointer from MutantStack* to const MutantStack*.
        return this->c.begin();     //You don't need to type const inside the body because the compiler used the constness of this to figure it all out for you before it even reached the .rbegin() call!
    }

    const_iterator end() const{
        return this->c.end();
    }

    reverse_iterator rbegin(){
        return this->c.rbegin();
    }

    reverse_iterator rend(){
        return this->c.rend();
    }

    const_reverse_iterator rbegin() const{  
        return this->c.rbegin();         //gets std::deque::rbegin() const
    }


    const_reverse_iterator rend() const{
        return this->c.rend();
    }

};





