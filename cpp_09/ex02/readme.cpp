
/*
Merge Sort (Split by Halves)
In Merge Sort, you blindly cut the array down the middle. 
You don't compare any elements until you reach the very bottom.

Merge-Insertion-Sort
Ford-Johnson (Split by Pairs) -> PmergeMe
In Ford-Johnson, you do not split the container down the middle. 
You pair up numbers right next to each other, compare them immediately, 
and split them into Winners and Losers.
It is optimized and designed purely to minimize the absolute number of element comparisons

Using your exact sequence [ 42, 13, 10, 89, 7, 24 ]:

Step 1: Pair adjacent elements and compare them:
(42, 13) -> 42 is larger
(10, 89) -> 89 is larger
(7, 24)  -> 24 is larger

Step 2: Split them into two separate chains of equal size:
At each level, the algorithm strips away the losers and sends only the winners deeper.
The sequences get smaller, but the individual elements get bigger.
Winner Chain: [ 42, 89, 24 ]
Loser Chain:  [ 13, 10,  7 ]

What happens next? (The Recursion)
This is where the trickiest part happens. You don't touch the Loser Chain yet. 
You take the Winner Chain [ 42, 89, 24 ] and pass it recursively into the same function.
until it hits the base case (a sequence of size 1, which is [ 89 ]).

Inside the recursive call, that Winner Chain gets paired up again:
Sequence entering Recursion Level 2: [ 42, 89, 24 ]

Pair 1: (42, 89) -> 89 is larger (Winner)
Straggler: 24    -> (Leftover because the sequence size is odd!)

Setup:
New Winner Chain (sorted): [ 89 ]
Loser (Pend) Chain: [ 42 ]
Straggler: [ 24 ]

Then, as the recursion unwinds, you start using binary search to insert the losers back into the winners 
using those Jacobsthal numbers we talked about.

Summary: Merge Sort: Splits the indices structurally (N/2).
Ford-Johnson (PmergeMe): Splits the elements by value (Winners vs. Losers) after comparing pairs.


What happens to the loser chains:
The loser chains from the upper levels are temporarily "shelved" or frozen in memory. They do absolutely nothing until the recursion starts unwinding.


Going Down (Deepening Recursion)
At each level, the algorithm strips away the losers and sends only the winners deeper. 
As a result, the sequences get smaller, but the individual elements get heavier (they become blocks).


*/