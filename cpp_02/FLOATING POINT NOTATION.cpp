


Floating Point is Scientific Notation in base 2
IEEE 754 Standard Single Precision (32 bits)


So all it can do is:	-Store 23 Significant Digits (Mantissa)
			-decide where the decimal Point in those is
			-multiply the Mantissa with 2^x (Exponent Box)
			 (x range from decimal -126 to +127)

This means: Large and Small Numbes can be stored because of the Exponent Box
But Precision is lost because:
	- only 23 Significant Binary Digits
	- Scientific Notation can not Represent Recurring Numbers like 1/3
Also:
       -> Two Exponents are reserved for special cases
	Represent 0 
	- is impossible if the mantissa is always betwenn 1 and almost 2. 
	- If the Exponent is 0 (127 in b2), the number is now 
	  interpreted as subnormal with a leading 0 in the Mantissa
	  instead of 1. This allows representation of very small
	  values and zero.
	-
	Representing Infinity or Overflow
	- Is done with Exponent 127 (255 in b2)

Exponent Box (0-255) so with 127 bias; Range should be from -127 to 128.
But it is actually from -126 to 127 because two Exponents are Reserved


Actual Exponent Range for Normalized Numbers 
				Binary  |  Decimal (-127)		
Minimum Exponent (00000001):  	   1    |   -126 
Maximum Exponent (11111110):      254	|    127
Special Exponent (00000000): 	   0	|   -127
Infinity/NaN     (11111111): 	   255  |    128
