#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/*
FIXED POINT NUMBERS

Fixed-Point Value: 5
Raw Fixed Point Value: 1280 // 


Converting a constant integer to fixed-point is just re-scaling the value,
so that it sits to the left of an imaginary binary point. 
It allows you to perform "decimal" math using only integer logic, 
which is a lifesaver in embedded systems or high-performance graphics.
	- Hardware Limitations: Many small microcontrollers (microwave, car sensors, or simple calculators) 
	   don't have a Floating Point Unit (FPU).
	- Pure Speed: Integer math is the "native language" of a CPU
	- Determinism: Floating-point numbers can sometimes have tiny rounding errors that vary between different processors. 
	  Fixed-point is exact: If you add 1280 + 1280, you will always get 2560 (which you interpret as 10.0).

HOW TO?
The computer doesn't actually know what a decimal point is; 
it just sees a sequence of bits. 
The "fixed-point" part is a contract between you and the computer.
You can decide that the decimal point always lives at a specific spot!
E.g., after the 8th bit == Q8.8 format (8 bits for the integer, 8 bits for the fraction).

The Core Concept: Scaling 
	- You Decide: Fractional Bits n = 8 (Q8.8 Format )

	- FixedValue = Integer * 2^n

Example (Q8.8):

Standard Integer 5 (00000101 ) 

FixedPoint Value = 5 * 2^8 = 1280  (00000101 00000000) 
	== You shift those bits 8 bits to the left.
	To the CPU, that new binary string is the number 1280:  00000101 00000000
	! But because you know the last 8 bits are reserved for fractions, you read it as 5.00000000
*/