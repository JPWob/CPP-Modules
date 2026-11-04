

// { Under the hood std::stack implementation

// template <typename T, typename Container = std::deque<T>>
// class stack{
// private:
//     container_type c;   //-> Composition: MyStack "has-a" std::vector

// public:

//     typedef Container container_type; // container_type gets stored
    
//     // We explicitly write wrapper functions to expose ONLY what we want
//     void push(const T& val) {
//         c.push_back(val); // Uses vector's push_back
//     }

//     void pop(){
//        c.pop_back;
//     }

//     //  There are NO definitions for begin(), end(), operator[], or insert().
// }


// }


#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include "MutantStack.hpp"

void printSeparator(const std::string& title) {
    std::cout << "\n--- " << title << " ---\n";
}

int main() {
    
    // ==========================================
    // TEST 1: Default Constructor & Basic Ops
    // ==========================================
    printSeparator("TEST 1: Default Constructor & Basic Operations");
    
    MutantStack<int> mstack;
    std::stack<int> realStack; // For behavior comparison

    mstack.push(5);
    mstack.push(17);
    realStack.push(5);
    realStack.push(17);

    std::cout << "MutantStack top: " << mstack.top() << " (Expected: 17)\n";
    std::cout << "RealStack top:   " << realStack.top() << " (Expected: 17)\n";

    mstack.pop();
    realStack.pop();

    std::cout << "After pop - MutantStack size: " << mstack.size() << " (Expected: 1)\n";
    std::cout << "After pop - RealStack size:   " << realStack.size() << " (Expected: 1)\n";


    // ==========================================
    // TEST 2: Container Constructor
    // ==========================================
    printSeparator("TEST 2: Container Constructor (Deque & Vector)");

    // 2a. Deque container constructor (Default underlying container for stack)
    std::deque<int> my_deque;
    my_deque.push_back(10);
    my_deque.push_back(20);
    my_deque.push_back(30);

    MutantStack<int> mstackFromDeque(my_deque);
    std::cout << "MutantStack from Deque top: " << mstackFromDeque.top() << " (Expected: 30)\n";
    std::cout << "MutantStack from Deque size: " << mstackFromDeque.size() << " (Expected: 3)\n";

    // 2b. Vector container constructor (Explicitly overriding container type)
    // Note: C++98 requires space between brackets: > >
    std::vector<int> my_vector;
    my_vector.push_back(100);
    my_vector.push_back(200);

    MutantStack<int, std::vector<int> > mstackFromVector(my_vector);
    std::cout << "MutantStack from Vector top: " << mstackFromVector.top() << " (Expected: 200)\n";
    std::cout << "MutantStack from Vector size: " << mstackFromVector.size() << " (Expected: 2)\n";


    // ==========================================
    // TEST 3: Copy Constructor
    // ==========================================
    printSeparator("TEST 3: Copy Constructor");

    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);

    // Copy constructing copyStack from original
    MutantStack<int> copyStack(original);

    // Modify original to prove copyStack is independent (deep/independent copy)
    original.pop(); 
    original.push(99);

    std::cout << "Original top (after mod): " << original.top() << " (Expected: 99)\n";
    std::cout << "CopyStack top (unaffected): " << copyStack.top() << " (Expected: 3)\n";
    std::cout << "CopyStack size: " << copyStack.size() << " (Expected: 3)\n";


    // ==========================================
    // TEST 4: Copy Assignment Operator
    // ==========================================
    printSeparator("TEST 4: Copy Assignment Operator & Self-Assignment");

    MutantStack<int> stackA;
    stackA.push(42);
    stackA.push(84);

    MutantStack<int> stackB;
    stackB.push(1); // Will be overwritten

    // Assignment
    stackB = stackA;
    std::cout << "StackB top after assignment: " << stackB.top() << " (Expected: 84)\n";
    std::cout << "StackB size after assignment: " << stackB.size() << " (Expected: 2)\n";

    // Self-assignment test (should not crash or corrupt memory)
    stackB = stackB;
    std::cout << "StackB top after self-assignment: " << stackB.top() << " (Expected: 84)\n";


    // ==========================================
    // TEST 5: Iterator Functionality vs Deque
    // ==========================================
    printSeparator("TEST 5: Iterator Functionality & Validation");

    MutantStack<int> iterableStack;
    std::deque<int> comparisonDeque;

    // Fill both with the same sequence
    for (int i = 1; i <= 5; ++i) {
        iterableStack.push(i * 10);
        comparisonDeque.push_back(i * 10); // Note: push_back fills deque in insertion order (bottom to top)
    }

    // Forward iteration test (C++98 compatible loop syntax)
    std::cout << "MutantStack forward elements: ";
    for (MutantStack<int>::iterator it = iterableStack.begin(); it != iterableStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n(Expected: 10 20 30 40 50)\n";

    // Reverse iteration test
    std::cout << "MutantStack reverse elements: ";
    for (MutantStack<int>::reverse_iterator rit = iterableStack.rbegin(); rit != iterableStack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << "\n(Expected: 50 40 30 20 10)\n";

    // Const correctness check
    std::cout << "Const MutantStack forward elements: ";
    const MutantStack<int>& constRef = iterableStack;
    for (MutantStack<int>::const_iterator cit = constRef.begin(); cit != constRef.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << "\n(Expected: 10 20 30 40 50)\n";

    std::cout << "\nAll tests completed successfully!\n";
    return 0;
}