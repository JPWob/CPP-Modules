#include <iostream>
#include <stack>


/* Under the hood std::stack implementation

	template <typename T, typename Container = std::deque<T>>
	class stack{
	protected:
	    container_type c;  					 //-> Composition: MyStack "has-a" std::vector

	public:

	    typedef Container container_type;	// container_type is Container, this is just cpp standardization
	    
		// Stack Operations. These functions use c member functions
		push(value) / emplace(...) 	Adds an element to the top of the stack.
		pop()						Removes the element at the very top. (Note: This returns void, it does not return the value!)
		top()                       Returns a reference to the element at the top without removing it.
		size()						Returns the number of elements currently in the stack.
		empty()	
	}

 */

// std::stack<T, Container>
// T                is a type parameter for the type of elements stored in the stack (eg. int, std::string, etc.)
// Container        is a type parameter for the underlying container type that expands to eg. std::vector<int>
// container_type   is a public type alias for "Container". public: typedef Container container_type;. It gets inherited by MutantStack. It allows external code to reference the exact underlying container type.
// c                is a member variabel of std::stack<T, Container>. It is protected: container_type c;. It holds the actual container data.
// MutantStack      is an object of type std::stack (through public inheritance). That object has all the capabilities of a std::stack, plus the extra iterator functions you wrote.
//                  Because it IS a std::stack, you can pass a MutantStack into any function that expects a regular std::stack by reference or value.

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>{
public:
	
    // First define Canonic Form

    // (C++11 and later): Inherit all constructors from std::stack, No need to write out
    // using std::stack<T, Container>::stack;
	
	// Default Constructor
    // Use: MutantStack<int> default;
    // This is a derived class constructor that calls the default constructor of the base. this line ensures that the underlying std::stack is properly built before your custom stack object comes to life.
    // Actually MutantStack(){}; will work fine, but good practice is:
    MutantStack() : std::stack<T, Container>(){};

	// Copy Constructor
	// Use: MutantStack<int> stack1; MutantStack<int> stack2(stack1);
	// using std::stack copy constructor because variables live in there anyway
    MutantStack(const MutantStack& src)
    : std::stack<T, Container>(src) {};
    
	// Copy Assignment
	// using std::stack because variables live in there anyway
    MutantStack& operator=(const MutantStack& src){
        if(this != &src){
            std::stack<T, Container>::operator=(src);
        }
        return *this;
    };
    
    //Destructor
    ~MutantStack(){};

    // Optional
    // Container Parameter Constructor
    // Use: std::deque<int> d = {1, 2, 3}; MutantStack<int> myStack(d);
    // Using std::stack constructor to initialize the base class portion of my MutantStack object with the provided container. This ensures that the underlying container of the stack is properly initialized with the elements from the provided container.
    MutantStack(const Container& some_container_object) 
        : std::stack<T, Container>(some_container_object){};

    // Use typedef to create type aliases for iterators

    typedef typename Container::iterator iterator;
    typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator; //other way to write the above "Container::iterator"

    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    /* 
		Because MutantStack is a template class, the compiler cannot immediately see 
		the members of the Base class during the first phase of parsing.
        So container_type c;  of the base class std::stack is not visible!
		By tying c to this->, you turn c into a dependent name and enforce the Two-Phase Lookup: waiting until instantiation time to look up those dependent names
        Otheriwise compiler will throw an error saying "c was not declared in this scope".
    */
	iterator begin() {
        return this->c.begin(); 
    }

    /*
    Why all the sudden can I access member functions of container_type c like this->c.begin()?
    -> c is a protected member of std::stack and is inherited by MutantStack
    -> protected means the class itself and any child classescan touch it.
    -> std::stack could access begin()/end() but the whole point of a stack is to hide these functions by making c protected, So the global scope cannot access c.begin()/c.end() directly.
    -> So for this exercise, MutantStack uses member functions of c, and is allowed to do so
    */

    iterator end() {
        return std::stack<T, Container>::c.end();  //other way to write it
    }

    const_iterator begin() const{    
        return this->c.begin();     // No need type const inside the body because the compiler used the constness of this to figure it all out for you before it even reached the .begin() call! //compiler automatically changes the type of the this returned iterator from to const 
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




