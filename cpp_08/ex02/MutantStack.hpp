#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
public:
    // 1Define your own custom type names using typedef //Tell the compiler what the name 'iterator' actually means
    // your code automatically stays compatible even if someone creates a MutantStack<int, std::vector<int>>. 
    // It looks up whatever the underlying container is and grabs its specific iterator.
    // typedef is creating a shortcut nickname for a type.
    // typename is reassuring the compiler that a nested template match is a type and not a variable.
    // A const_iterator allows you to read the data, but prevents you from accidentally modifying it
    // A const_iterator acts like a pointer-to-const data: the iterator itself is free to move around and point to different positions in memory, but you cannot use it to modify the values it points to
    
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    //
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    //this  Points to your MutantStack instance.
    //this->c Looks inside that MutantStack to find its inherited member variable named c (which is the actual std::deque object).
    iterator begin() {
        return this->c.begin(); 
    }

    iterator end() {
        return this->c.end(); 
    }


    cost_iterator begin() const{    //compiler automatically changes the type of the this pointer from MutantStack* to const MutantStack*.
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

    //Orthodox canonical Form missing!

};





