#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>



struct ItemVector {
    unsigned int id;
    unsigned int value;

    static size_t comparisons; // Shared counter across all ItemVector comparisons

    ItemVector(unsigned int n = 0, unsigned int id = 0) :  id(id), value(n){};

    bool operator>(const ItemVector& b) const{
        comparisons++;
        return(this->value > b.value);

    }

    bool operator<(const ItemVector& b) const{
        comparisons++;  
        return(this->value < b.value);
    }

    bool operator==(const ItemVector& b) const{
        comparisons++;
        return(this->id == b.id);
    }
};



struct ItemDeque {
    unsigned int id;
    unsigned int value;

    static size_t comparisons; // Shared counter across all ItemVector comparisons

    ItemDeque(unsigned int n = 0, unsigned int id = 0) :  id(id), value(n){};

    bool operator>(const ItemDeque& b) const{
        comparisons++;
        return(this->value > b.value);

    }

    bool operator<(const ItemDeque& b) const{
        comparisons++;  
        return(this->value < b.value);
    }

    bool operator==(const ItemDeque& b) const{
        comparisons++;
        return(this->id == b.id);
    }
};

std::vector<ItemVector> sort_vector(std::vector<ItemVector>& vec, int argc);
std::deque<ItemDeque>   sort_deque(std::deque<ItemDeque>& deq, int argc);
double                  get_time_us();
bool                    parse_positive_int(const char* str, unsigned int& out) ;

//std::vector<Item>&  sort_vector(std::vector<Item>& vec);

    /* 
    When unwinding recursion, winners[] comes back as a sorted main[]. 
    The Order of Winner elements has changed!
    To do Jacobsthal insertion correctly, the losers in pend[] need to be in the same Order as their Winners in main.
    
    How do I keep track of which loser belongs to which Winner?

    0. Use IDs instead of values, because values can be duplicate as subject requirement
    
    1. Going Down
        - Store every level a vector<Item> lookup of loser elements!
        - It keeps track of which loser Item belongs to which Winner.id
        - lookup is Winner ID indexed -> Its elements are loser Items
        - this means: The loser of main[i] is the Item at lookup[main[i].id]
        
    2. Going Up
       A: Create NEW every level a 0 indexed vector<Item> pend
        - loser Items in pend[] need to be in the order of their Winners in main[]
        - Create sorted pend[] using the lookup table
        - pend[i] must later correctly correspond to Jacbosthal Insertion indexes, thats why its 0 indexed
        - Loop through main and fill pend with help of lookup tabele
            -> pend[i] =  lookup[main[i].id]
        
        😀 Now a loser in pend[i] has its winner sitting at main[i]
        😀 Start inserting elements of pend[] into main[] in the Order that Jacbotshal dictates.
        😀 Key element is that pend[i] cannot be bigger than its original winner main[i]. 
        😀 So the Winner at main[i] is the BOUND for inserting pend[i]!
        
        !!! Pitfall !!!
        😰 When you start inserting pend Items into main[] -> main[] might shift and pend[i] - main[i] could be off
        😰 Now you cannot be sure that main[i] is the upper bound for pend[i]
        
        B: Keep track of the winner indexes in main[]!
            Examples inserting b3 
            Insertion shifts a2 [b1, a1, b3, a2, a3, ...]
                ❗If pend[i] gets inserted before main[i-1].
                ❗The insertion shifts all winners by i + 1 for coming insertions.
            Insertion does NOT shift a2: [b1, a1, a2, b3, a3,...]
                If pend[i] gets inserted after main[i-1], 
                The insertion has no impact on pend[i-1]
            Keep track of how many shifts have happend with a index vext

        As long as we keep track of indexes from now on, we can rely on them and do not need
        to manually identify the winner of a loser to find the upper bound for insertion.
    */

#endif



/*
Jacobsthal numbers (batch boundaries in pend, 1-indexed):
    k = [0, 1, 2, 3, 4,  5,  6,  7,  8,   9, ...]
    J = [0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...]

Max comparisons F(N) by total input size N:
    N   = [0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11, ...]
    max = [0, 0, 1, 3, 5, 7, 10, 13, 16, 19, 22, 26, ...]

n means the index of the Jacobsthal number
N meaning the total number of elements to sort

N = 5 (Max comparisons: 7)
./PmergeMe 42 7 91 13 58

N = 8 (Max comparisons: 16)
./PmergeMe 34 89 12 65 3 77 41 20

N = 11 (Max comparisons: 26)
./PmergeMe 84 19 53 7 96 31 62 4 75 48 11

N = 15 (Max comparisons: 42)
./PmergeMe 67 23 99 5 44 81 14 72 38 90 1 56 29 85 18

N = 21 (Max comparisons: 66)
./PmergeMe 73 16 94 28 61 3 87 45 12 98 33 59 8 79 24 68 40 92 15 51 37


*/