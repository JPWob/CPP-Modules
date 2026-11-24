
/*
Merge Sort (Split by Halves)
    In Merge Sort, you blindly cut the array down the middle. 
    You don't compare any elements until you reach the very bottom.
    Splits the indices structurally (N/2).

Merge-Insertion-Sort (Split by Pairs)
    also knwon as the Ford-Johnson Algorythm. 
    In Ford-Johnson, you do not split the container down the middle. 
    You pair up numbers right next to each other, compare them immediately, 
    and split them into Winners and Losers.
    It is optimized and designed purely to minimize the absolute number of element comparisons
    Splits the elements by value (Winners vs. Losers) after comparing pairs.

Summary
    At each level, the algorithm strips away the losers and sends only the winners deeper.
    The sequences get smaller, but the individual elements get bigger.
    Until it hits the base case (a sequence of size 1, which for this example is [ 89 ]).

*** Example ***    

Using your exact sequence [ 42, 13, 10, 89, 7, 24 ]:

1. The Recursive Descent (Going Down)
Every Level consists of 2 Steps:

    Step 1: Pair adjacent elements and compare them:

        (42, 13) -> 42 is larger
        (10, 89) -> 89 is larger
        (7, 24)  -> 24 is larger

    Step 2: Split them into two separate chains of equal size:

        Winner Chain: [ 42, 89, 24 ]
        Loser Chain:  [ 13, 10,  7 ]

 
What happens next -> Recursion
You don't touch the Loser Chain yet. 
You take the Winner Chain [ 42, 89, 24 ] and pass it recursively into the same function (Executing Step1 and Step2 from above).

Inside the recursive call, that Winner Chain gets paired up again:
Sequence entering Recursion Level 2: [ 42, 89, 24 ]

    Step 1: Pair adjacent elements and compare them:
        (42, 89)    -> 89 is larger (Winner)
        24          -> Straggler (Leftover because the sequence size is odd!)
    
    Step 2: Split them into two separate chains of equal size:

        Winner Chain (sorted):  [ 89 ]  << This is the Base case, a Winner chain of size 1. Now Recursion unwinds!
        Loser (Pend) Chain:     [ 42 ]
        Straggler:              [ 24 ]


2. The Recursive Ascent (Rewinding & Inserting)
    As the recursion unwinds, you start using BINARY SEARCH to insert the Losers back into main chain.

    Pend: [b1, b2, b3, b4, ....]

    Ford Johnson Rules:
    Insertion limit index:
        Every loser (pend element) [b1, b2, b3, ...] is strictly tied to the specific winner [a1, b2, b3] it was paired with during the descent.
        The pend (loser) chain is always stored in the sequence b_1, b_2, b_3.
        However, their actual numerical values can be in any order!
        Each loser has a designated insertion limit in the main chain (based on the index of its original winner).
        What this means: The Looser element cannot be bigger than the Winner Element it lost the inital Comparison to.
        The index of the Winner element in the main chain is the Insertion Limit.

    Jacobsthal Insertion Order:
        The Jacobsthal sequence dictates grouping pend elements into blocks and inserting them in reverse order.
        The algorithm looks at the Jacobsthal jump sizes to pick which losers to insert first.
        Why?: Inserting pend elements sequentially, leads to waist comparisons.

*** Ford-Johnson uses the Jacobsthal numbers to keep the number of comparisons at the absolute theoretical minimum **

    How?
    The Jacobsthal number minimizes comparison operations by "batching" the Loser elements into groups and inserting them in reverse order.
    By this way any element that gets inserted back using Binary Search, maximizes — without exceeding the Binary Search Constraint.

*** The Binary Search Constraint (2^k - 1)
    Defines the maximum number of elements binary search can handle within a given number of comparisons.

    2 comparisons can search up to 2^2 - 1 = 3  elemets
    3 comparisons can search up to 2^3 - 1 = 7  elements
    4 comparisons can search up to 2^4 - 1 = 15 elements
    = Every additional comparison doubles the number of elements binary search can handle (plus one pivot)

    So the Jacbobsthal number makes sure, that the Pend Chain element can be inserted back into main 
        - without exceeding the Binary Search Constraint
        - while taking full advantage of the Binary Search Constraint allowed by each comparison.


*** Example Pend element b11 will never need to search more than 15 elements
        
        When Inserting b11 first with the 3. Batch , you can be sure it will only need up to 4 comparisons!
        Possible Elements b11 needs comparison to:

        10 elements of main: a_1, a_2, a_3, a_4, a_5, a_6, a_7, a_8, a_9, a_10,
            5 elements of previos batches: b1   b2, b3,  b4, 5
        = 15 elements.

        For b10 (inserted when b11 is inside main) the calulation will equal 15 Elements as well!

*** Overexplaining:
    Every batch size is a strict balancing act between two opposing penalties:
    
    A.   Too small (e.g. only 2 at a time forever): 
        Later element (b_11) insertion with a bound of b11 < a11 get bloated by earlier insertions (b_6 \ b_9) and spill over their 2^k - 1 ceiling.

    B.  Too big (e.g., b_11 to b_2 all at once)
        b2 or b4 would lose their cheap comparison window of only 2 or 3 comparison if they get inserted back
        when b11 to b5 already sit in main chain.


*** How Jacobsthal Numbers Dictates the Batch Size:

    J = [0, 1, 1, 3, 5, 11, 21, ...]
    n = [0, 1, 2, 3, 4,  5,  6, ...]

    Batches are defined 
        [start J_k-1, end J_k]

        - We start with k = 2 as it is the first non trivial Jacobsthal number.
        -(J_0 = 0 and J_1 = 1 are trivial, meaning J_n = J_(n-1) + 2J_(n-2) does not apply to them)
        
  * Batch 0 (k = 2)
    
    Start: J_2-1 = J_1 = 1
    End:   J_2   = J_2 = 1

    => [1 to 1] which means insert b1 at the beginning of main without any comparison as it is guaranteed to be 
                smaller than anything in main.

  * Batch 1 (k = 3) (real start)

    Start: J_3-1 = J_2 = 1
    End:   J_3   = J_3 = 3

    1 to 3 means chunks size 2 and starting with the biggest index! Because of the reverse order Rule of Jacobsthal.
    => Insert b3 first into main using BinarySearch, then insert b2 using binary Search.

    J = [0, 1, 1, 3, 5, 11, 21, ...]
    n = [0, 1, 2, 3, 4,  5,  6, ...]

    This logic results in the following Batch/Chunk Size and Insertion Order
    |----++-------------------+------------+----------------------------------------+------------------------+-----------------+
    | Jn || Jacobsthal Bounds | Chunk Size | Exact Order to Binary-Insert into main | Max Search Space (main)| Max Comparisons |
    |----++-------------------+------------+----------------------------------------+------------------------+-----------------+
    | 3  || 1 -> 3            |     2      | b3 -> b2                               | 3  (2^2 - 1)           |        2        |
    | 4  || 3 -> 5            |     2      | b5 -> b4                               | 7  (2^3 - 1)           |        3        |
    | 5  || 5 -> 11           |     6      | b11 -> b10 -> b9 -> b8 -> b7 -> b6     | 15 (2^4 - 1)           |        4        |
    | 6  || 11 -> 17 (clamped)|     6      | b17 -> b16 -> b15 -> b14 -> b13 -> b12 | 31 (2^5 - 1)           |        5        |
    |+----+-------------------+------------+----------------------------------------+------------------------+-----------------+
    
    (Level 0): Unwinding the Top Level 

        Main Chain (sorted) 
            [ 89 ]
            [ b1 ] 
        
        Loser Chain
            42 lost to b1, so it gets indexed a1
            [ 42 ]
            [ a1 ]

    Step 1. Start with the looser of the smallest winner 
                b1 is the smallest winner so start with a1 and do [a1, b1]

        Main Chain becomes: [ 42, 89 ] (sorted)
        Straggler:          [ 24 ]

        No Elements left in Loser Chain.

    Step 2: If we have a straggler [24], Use Binary Search to insert the straggler 

        Main Chain is now sorted: [ 24, 42, 89 ] (sorted)

    Level 1 (Top Level for this example)

    Status quo: 

        Main Chain (sorted)
            [ 24, 42, 89 ]
            [ a1, a2, a3 ] (new order)
        
        Loser Chain         >> !Problem, this Loser Chain, stored in memory is outdated!
            [ 13, 10, 7 ]  
            [ b2, b3, b1]

            At the time of creation,  Winner chain was
            [ 42, 89, 24 ] so Loser mapped [ 13, 10,  7 ]

        Fix: If Every Winner knows the index of their Loser, we know how to map the Losers

            Now Main chain is [ 24, 42, 89 ] so Loser needs to get mapped

            This order does not match the main chain.
            Map all looser back to their original pairs.
            (13 lost to a2, 10 lost to a3, 7 lost to a1)


        1. Start with the looser of the smallest winner 
           b1 is the smallest winner so start with a1

           main chain [ 7, 24, 42, 89 ]
                      [a1, b1, b2, b3 ]

        2. Identify the Pend (amount of remaining Losers to inser)

            Pend [13, 10]   = 2 Elements left
                 [a2, a3] 
            
            For Pend == 2, Jaconsthal Number dictates the following

            0,  1,  1,  3,  5, 11, 21, 43, ...
            j0, j1, j2, j3, j4, j5, ...

            Calculation for n = 2 Elements:
                Look at jn+1  so j3 and compare the previous one jn to it
                        j3 = 3 
                        j2 = 2
                This tells us, our current batch spans from index 3 down to index 2: 
                    [a2, a3]
            
            *** The Walk-Back Rule ***
            > You must walk backward from the highest index down to the lowest index <
            >> Therefore start inserting a3 first, then a2.
    



    
     


*/


/* MENORY

When you are inserting elements into the main chain:

std::vector::insert() CONTNINOUS MEMORY
- Forces the container to physically shift every single element 
  after the insertion point over by one slot in memory. This is highly expensive (O(n) time).
- if using std::find(...):
  Iterator is a Random-Access Iterator. 
  Doing binary search (std::lower_bound) on a vector is lightning fast (O(logn)) 
  because the computer can jump directly to the middle index in memory.



std::deque::insert() or std::list::insert() 
- Handle memory blocks or node pointers differently, making insertions at certain positions much faster.
- std::find(...)
  Has Bidirectional Iterators. A list cannot jump to the middle of memory. 
  If you use a generic template with std::lower_bound on a std::list, C++ will secretly only simulate 
  the binary search but really is incrementing the pointer one-by-one under the hood.

*/

/* JACOBSTHAL

The first Jacobsthal numbers are: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525

The Power of 2 (Binary Search Mechanics)
When you perform a binary search, you cut the search space in half with every single comparison.
With 2 comparisons, you can uniquely identify an item in a list of up to $3$ elements. 
(2^2 - 1 = 3)
With 3 comparisons, you can uniquely identify an item in a list of up to $7$ elements. 
(2^3 - 1 = 7)
With 4 comparisons, you can uniquely identify an item in a list of up to $15$ elements. 
(2^4 - 1 = 15)

Notice the jumps in maximum list size: 3, 7, 15.
If you are binary searching an array that has 4 elements, it will cost you 3 comparisons. 
If the array grows to 7 elements, it still only costs you 3 comparisons.
Therefore, elements 5, 6, and 7 are essentially "free real estate" for your binary search.


Because of your earlier comparisons, you already know that $y_3 < x_3$. 
If you insert $y_3$ first, the Main Chain is still small enough that finding a spot 
for $y_3$ takes exactly 2 comparisons. If you had inserted $y_2$ first, 
the chain would grow, and inserting $y_3$ might suddenly cost 3 comparisons. 
The target sequence preserves the perfect binary search window.

By grabbing the higher element (y_3) first, we exploit the fact that its search window 
is bounded by x_3, allowing us to slide it into a perfect size 3 window (max 2 comparisons) 
before the elements below it expand and bloat the list. Going backward ensures the 
list size never spills over into that extra, costly comparison step.
*/

/* RECURSION

The Base Case (The Exit Strategy): 
A conditional statement that checks if the problem has been broken down to its absolute smallest unit.
 If true, it returns a hardcoded or simple value without calling the function again. Without this, 
 your program will loop infinitely until it crashes with a Stack Overflow.

The Recursive Step (The Progression): The section where the function calls itself, 
but crucially, passes a modified, smaller version of the original input. 
This ensures the function is constantly marching toward the Base Case.

Pseudo:

# 1. BASE CASE
if inputData is small enough or meets the stopping condition:
    return a simple, known result

# 2. LOGIC & PREPARATION
# (Do some work here if needed, like pairing elements or splitting data)
processedData = doSomethingWith(inputData)

# 3. RECURSIVE STEP
# Call the function again with smaller/modified data
result = recursiveFunction(processedData)

# 4. UNWINDING / COMBINING
# (Optional: Modify or combine the result as it travels back up the stack)
finalResult = combine(result, inputData)
return finalResult


*/