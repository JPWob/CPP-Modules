/*

💡💡💡STD::STACK💡💡💡💡
The interface for std::stack is deliberately minimal. 
It only supports a handful of core operations, all of which run in O(1) constant time:

- LIFO Management: 
    Elements are inserted (pushed) and extracted (popped) from the same end, known as the top of the stack.
- Container Adaptor c: 
    It isn't a standalone data structure built from scratch. 
    Instead, it "wraps" around an existing standard container (like std::deque | std::vector | std::list) 
    and restricts its interface to mimic a stack.
    By default, if you don't specify a container type, std::stack uses std::deque behind the scenes.
    The underlying container is stored in a protected member variable named c.

push(value) / emplace(...) 	Adds an element to the top of the stack.
pop()						Removes the element at the very top. (Note: This returns void, it does not return the value!)
top()						Returns a reference to the element at the top without removing it.
size()						Returns the number of elements currently in the stack.
empty()						Returns true if the stack has no elements, false otherwise.

💡💡💡Declaring a std::stack in main()💡💡💡
  
  std::stack<int> defaultStack   
  //Parameter 1 (int): The data type (T) that the stack will hold.
  //Because you omitted the second parameter, the compiler automatically defaults to using a std::deque<int> to hold the data under the hood.


  //Parameter 1 (int): The data type (T) that the stack will hold.
  //Parameter 2: The explicit container type used for underlying storage If you do not want to use a std::deque, you can explicitly tell the stack to use a different standard container, such as a std::vector or a std::list.
  std::stack<int, std::vector<int> > myVectorStack;

  other eg
  std::stack<std::string, std::list<std::string> > listStack; // Custom Container: List of strings
  

💡💡💡The Structure Under the Hood💡💡💡
Inside the C++ Standard Library source code, std::stack is defined roughly like this:

    template <typename T, typename Container = std::deque<T>>
    class stack {
    public:
        // 1. The Magic Shortcut (Publicly visible to everyone)
        typedef Container container_type; 

        // Standard public functions that everyone uses
        void push(const T& value) { c.push_back(value); }
        void pop()                { c.pop_back(); }
        T& top()                  { return c.back(); }

    protected:
        // 2. The Inner Data Storage (Only visible to stack and its children)
        Container c; 
    };

-> typename Container = std::deque<T>>   ||| Could also swap for vector or list
Swappable Interiors: As long as the inner container has functions named push_back(), pop_back(), and back(), std::stack can wrap around it. 
This is why you can easily swap out std::deque for std::vector or std::list. 
If it used inheritance, swapping the base class dynamically like this wouldn't be possible.

Finding the name of Container?
If you dont know, what type of stack the user created and wantto find out, you can use container_type
You use the public container_type shortcut to tell your code eg. what type of iterator to create. 
Because it is public, you can access it by writing std::stack<T>::container_type.
    typedef typename std::stack<T>::container_type::iterator iterator;

Once your function knows what type of iterator it is returning, it goes inside the protected member variable c to pull out the live, actual memory markers (begin() and end()).
    iterator begin() { 
        return this->c.begin(); 
    }


💡💡💡STD::DEQUE💡💡💡
- Double-Ended Queue,
- std::deque gives you the best of both worlds between a std::vector and a std::list
- While a std::vector is like a straight line that only grows efficiently at the very end, 
  a std::deque is designed to grow dynamically at both the front and the back with equal efficiency.
- It allocates memory in multiple small, fixed-size chunks. 
  It then maintains a central pointer array (a "map") that keeps track of where all these chunks are located in RAM.
  = no reallocations
  = fast insertion in 0(1) time at both ends
- Frequent Shrunk/Grow Safety: Stacks constantly grow and shrink. 
  ->std::deque handles freeing up individual memory chunks when they are no longer needed 
    much more gracefully than a vector, which holds onto its allocated capacity 
	unless explicitly told to shrink.


Using Deques Member Functions 

The Syntactical Rule: You must use this->
Because MutantStack is a template class inheriting from another template class (std::stack<T>), 
the compiler cannot immediately see the members of the base class during the first phase of parsing.

If you just type c.begin(), the compiler will throw an error saying "c was not declared in this scope". 
To fix this, you must explicitly tell the compiler to look inside the base class by using this->c.


The std::stack Object in main()
When you are in main.cpp, you are in the global scope. You are an "outsider" to the class.
  int main() {
    std::stack<int> s;
    s.c.begin(); // ❌ ERROR: 'c' is protected!
  }
Because c is marked protected inside std::stack, the compiler enforces a strict security wall. 
It tells the global scope: "You do not have clearance to touch c. 
Only the stack itself and its children are allowed."

The MutantStack Object in main()
When you use your MutantStack object in main(), you are still an outsider. You still cannot access c directly.
  int main() {
      MutantStack<int> ms;
      ms.c.begin(); // ❌ STILL AN ERROR: 'c' is still protected!
  }

SOLUTION: Dont call c.begin() => Call ms.begin(). And where is begin() defined? Inside the MutantStack class scope!
Inside the MutantStack class declaration, you are a child class (a derived class). You have family clearance!
  template <typename T>
  class MutantStack : public std::stack<T> {
  public:
    iterator begin() {
        return this->c.begin(); //  SUCCESS! You are inside the child class.
    }
  };



If you inherit from std::stack (like Mutant Stack), you can bypass the restrictions 
and talk directly to the inner std::deque using push_front() == Adding to bottom of the stack. 
However, this is generally frowned upon in clean software engineering 
because it defeats the whole purpose of using a stack wrapper.

std::stack does not inherit from std::deque ("is-a" relationship).
Instead, std::stack uses composition ("has-a" relationship).


Iterators Deque
Because std::deque is a fully featured, standalone sequential container (unlike std::stack), 
it provides a rich set of iterators to let you traverse its elements in any direction. 
Specifically, std::deque provides Random Access Iterators. This means its iterators act very much like raw pointers; 
you can use them to move forward, backward, or jump directly to any element in $O(1)$ constant time using math (like it + 5).

Inside the C++ Standard Library, the creators of std::stack didn't just hardcode it to use a std::deque. They gave it a public nickname—a type alias—called container_type.



*/