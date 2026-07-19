
/*

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
