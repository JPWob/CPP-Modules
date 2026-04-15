1. The Containers: int vs. float
    
In most modern systems (like the C++ code you are writing), 
both an int and a float take up 32 bits (4 bytes) of memory.


_________________________
int (Integer):  
All 32 bits are used to represent a whole number. 
here is no concept of a decimal point. Bit 0 is worth 1, bit 1 is worth 2, and so on.
Int MAX:  2147483647 (2^-31)
Int MIN: -2147483648 (2^31)  (31 because 1 bit is for the sign)

_________________________
float (Floating Point): 
The 32 bits are divided into three "departments": 
1 bit: Sign (+/-)
8 bits: Exponent (e) determines how large the number can get (the power of ten).
23 bits: Mantissa (M) = precision bits (the digits before and after the decimal point)
        float = M * 2^e
In a Float, the decimal point "floats" left and right to accommodate huge or tiny numbers,
representing massive numbers (10^38) or tiny ones (10^-38).






How are Floats  stored in Memory?
-> They are stored in Scientific Notation, and in binary of course.

Number 5 in Float Point Notation
	- in binary: 00000101.0
	- now, get a single 1 in front of the decimal point
	- 1.01 <<- we slided the point 2 places to the left. 
	- therefore Exponent needs to be ^2
       -> Result: 1.01(base2) x 2^2
   How 1.01(base2) x 2^2 is stored in a 32 bit float
	1 bit :  0
		 Sign is positive, so first bit is 0
	8 bits:	 10000001
		 Exponent is 2(decimal), so (because of 127 bias) it gets stored as 2+127 = 129 
		 in binary Exponent Box (10000001) The FPU Unit is wired to 
		 substract 127 from whatever number it sees in the Exponent box
		 So The Computer will know and read it as we wantetd it: 2!
	23 bits: 01000000000000000000000
		 Mantissa is what  comes after the decimal point in the normalized number. 
		 So take the 01 and fill the rest of the 23 slots with zeros.
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		
