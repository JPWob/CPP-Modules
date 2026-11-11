#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>
#include "MutantStack.hpp"

void printSeparator(const std::string& title) {
    std::cout << "\n--- " << title << " ---\n";
}

// push_back belongs to Sequence Containers (std::vector, std::list, std::deque)
// push belongs to Container Adaptors (std::stack, std::queue

int main() {

	{
		//Test main() from subject

		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite){
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

		std::cout << "Test with std::list to compare behavior " << std::endl;
	    std::list<int> lst;

	    lst.push_back(5);
	    lst.push_back(17);
	    std::cout << lst.back() << std::endl; // .top() becomes .back()
	    lst.pop_back();                       // .pop() becomes .pop_back()
	    std::cout << lst.size() << std::endl;
	    lst.push_back(3);
	    lst.push_back(5);
	    lst.push_back(737);
	    lst.push_back(0);

	    std::list<int>::iterator it1 = lst.begin();
	    std::list<int>::iterator ite2 = lst.end();
	    ++it1;
	    --it1;
	    while (it1 != ite2){
	        std::cout << *it1 << std::endl;
	        ++it1;
	    }

	}

    
    // ==========================================
    // TEST 1: Default Constructor & Basic Ops
    // ==========================================
    {
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
    }

    {
        // ==========================================
        // TEST 2: Container Constructor
        // ==========================================

        printSeparator("TEST 2: Container Constructor (Deque)");
    
        // 2a. Deque container constructor (Default underlying container for stack)
        std::deque<int> my_deque;

        my_deque.push_back(10);
        my_deque.push_back(20);
        my_deque.push_back(30);
    
        MutantStack<int> mstackDeque(my_deque);
        std::stack<int> realStackDeque(my_deque); // For comparison

        std::cout << "MutantStack from Deque top: " << mstackDeque.top() << " (Expected: 30)\n";
        std::cout << "MutantStack from Deque size: " << mstackDeque.size() << " (Expected: 3)\n";
        std::cout << "RealStack from Deque top: " << realStackDeque.top() << " (Expected: 30)\n";
        std::cout << "RealStack from Deque size: " << realStackDeque.size() << " (Expected: 3)\n";

    }

    {
        // ==========================================
        // TEST 2b: Vector Container Constructor  (Explicitly overriding container type)
        // ==========================================
        printSeparator("TEST 2b: Vector Container Constructor");
        
        
        std::vector<int> my_vector;
        my_vector.push_back(100);
        my_vector.push_back(200);
        
        MutantStack<int, std::vector<int> > mstackVector(my_vector);


        std::stack<int, std::vector<int> > realStackFromVector(my_vector); // For comparison
        std::cout << "MutantStack from Vector top: " << mstackVector.top() << " (Expected: 200)\n";
        std::cout << "MutantStack from Vector size: " << mstackVector.size() << " (Expected: 2)\n";
    }

    {
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
        copyStack.pop();
        copyStack.push(99);
    
        std::cout << "Original top: " << original.top() << " (Expected: 3)\n";
        std::cout << "CopyStack top modified: " << copyStack.top() << " (Expected: 99)\n";

    }

    {
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
        // stackB = stackB;
        // std::cout << "StackB top after self-assignment: " << stackB.top() << " (Expected: 84)\n";

    }
    
    {

        // ==========================================
        // TEST 5: Iterator Functionality vs Deque
        // ==========================================
        printSeparator("TEST 5: Iterator Functionality & Validation");
    
        MutantStack<int> iterStack;
        std::deque<int> comparisonDeque;
    
        // Fill both with the same sequence
        for (int i = 1; i <= 5; ++i) {
            iterStack.push(i * 10);
            comparisonDeque.push_back(i * 10); // Note: push_back fills deque in insertion order (bottom to top)
        }
    
        // Forward iteration test (C++98 compatible loop syntax)
        std::cout << "MutantStack forward elements: ";
        for (MutantStack<int>::iterator it = iterStack.begin(); it != iterStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n(Expected: 10 20 30 40 50)\n";
    
        // Reverse iteration test
        std::cout << "MutantStack reverse elements: ";
        for (MutantStack<int>::reverse_iterator rit = iterStack.rbegin(); rit != iterStack.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << "\n(Expected: 50 40 30 20 10)\n";
    
        // Const correctness check
        std::cout << "Const MutantStack forward elements: ";
        const MutantStack<int>& constRef = iterStack;
        for (MutantStack<int>::const_iterator cit = constRef.begin(); cit != constRef.end(); ++cit) {
            std::cout << *cit << " ";
        }
        std::cout << "\n(Expected: 10 20 30 40 50)\n";
    
    }

    std::cout << "\nAll tests completed successfully!\n";
    return 0;

}