
1. Shallow Copy (The Default)
A shallow copy copies the values of the member variables exactly as they are.

If the member is an int, it copies the number. (Safe)

If the member is a pointer (like Brain*), it copies the memory address. (Dangerous)


//////////////////////////////////////////////////////

1. The Containers: int vs. float
    
In most modern systems (like the C++ code you are writing), 
both an int and a float take up 32 bits (4 bytes) of memory.

____________________________
int (Integer):  
All 32 bits are used to represent a whole number. 
here is no concept of a decimal point. Bit 0 is worth 1, bit 1 is worth 2, and so on.
Int MAX:  2,147,483,647 (2^-31)
Int MIN: -2,147,483,648 (2^31)  (31 because 1 bit is for the sign)

_____________________________
float (Floating Point): 
The 32 bits are divided into three "departments": 
1 bit: Sign (+/-)
8 bits: Exponent (e) determines how large the number can get (the power of ten).
23 bits: Mantissa (M) = precision bits (the digits before and after the decimal point)
        float = M * 2^e
In a Float, the decimal point "floats" left and right to accommodate huge or tiny numbers,
representing massive numbers (10^38) or tiny ones (10^-38).

_____________________________
How are floats printed?
When you print a very large 32-bit float in a terminal,
the system typically switches to Scientific Notation.
Because a 32-bit float only has about 7 decimal digits of precision.
Instead of 340,282,346,638,528,860,000,000,000,000,000,000,000
Printed out : 3.4028235e+38



float my_big_float = 1e20; // 1 followed by 20 zeros
my_big_float = my_big_float + 1.0;
-> The + 1.0 is completely lost because, at that scale, the "gap" between representable numbers is much larger than 1

____________________________
Why is the float Max Value so much higher than INT MAX?
Because of the 8 bits dedicated to the exponent, a float can represent powers up to 2^127 or 2^128 in theory
2^128 is aproximately 3.4*10^38

____________________________
Why is float Max 2^127 and not 2^254?
->The "Bias" Trick (Negative Exponents)
To represent very small numbers (like $0.000001$), we need negative exponents. 
Instead of using a sign bit inside the exponent (which would make math slower for the CPU), 
engineers use a Bias of 127. (Subtract 127 from whatever number you see in e)

By using this "offset," the 256 possible values are split roughly in half: 
half for very small numbers and half for very large numbers.

You dont get to use all 256 values for the exponent because the two "ends" of the range (0 and 255)
are reserved for special cases like N/A  and infinity.

____________________________
Why Q8.8?
If you have a 32-bit "bucket," why only use 16 bits (Q8.8) and let the rest sit empty?
-> Preventing Overflow (The "Buffer" Strategy)
        This is the most common reason modern programmers use Q8.8 inside a 32-bit variable.
        You can add thousands of Q8.8 numbers together inside that 32-bit bucket without ever worrying about the sum hitting the ceiling
-> Hardware Constraints (The 16-bit Era)
        Many digital signal processors (DSPs) and older microcontrollers are natively 16-bit. 
-> Standardized Communication
->SIMD: fit two Q8.8 numbers (16 bits each) into a single 32-bit memory slot.