#include <iostream>
#include <cmath>

class Fixed {
	
private:
	int _fixp; 					
	static const int _bits = 8; 

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& src); 		
	Fixed(const int n); 			
	Fixed(const float f);			
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int 	toInt(void) const;

	Fixed& operator=(const Fixed& src);

	//Comparison operator
	bool operator<(const Fixed& right)const;
	bool operator>(const Fixed& right)const;
	bool operator<=(const Fixed& right)const;
	bool operator>=(const Fixed& right)const;
	bool operator!=(const Fixed& right)const;
	bool operator==(const Fixed& right)const;

	//arithmetic operator
	Fixed operator+(const Fixed& right)const;
	Fixed operator-(const Fixed& right)const;
	Fixed operator*(const Fixed& right)const;
	Fixed operator/(const Fixed& right)const;

	
	Fixed& operator++();	//Pre-Increment ++i (Increment first, then use)
	Fixed& operator--();	//Pre-Decrement --i
	Fixed operator++(int);	//Post-Increment (a = i++ : a is 5;  i is 6;)
	Fixed operator--(int);	//Post increment
	
	//Difference: Who can call them and what the caller is allowed to do with the result.
	//Non const: result and obects can be modified!
	//Fixed::max(a, b) = 100;	In this case the result (which will be changed to 100) is one of the objects!!!
	static Fixed& 		min(Fixed& first, Fixed& scnd);
	static Fixed& 		max(Fixed& first, Fixed& scnd);
	//Read only
	static const Fixed& min(const Fixed& first, const Fixed& scnd);
	static const Fixed& max(const Fixed& first,const Fixed& scnd);

};

std::ostream& operator<<(std::ostream &out,const Fixed &fixed); //overload of insertion operator


/*

>> If I want to: 
	// Find the larger of a and b, and set it to 100 == Modifiy Object
	// Non const Function is needed!
	Fixed::max(a, b) = 100;		-> Used: static Fixed& min(Fixed& first, Fixed& scnd);

>> If you do:

	const Fixed a(10);
	const Fixed b(20);

	Fixed& result = Fixed::max(a, b);	// You need a const Version of max
										// because Const objects are calling it
									
	-> 	Needed:
		static const Fixed& max(const Fixed& first,const Fixed& scnd);
	-> 	Ilegal:
		static Fixed& max(const Fixed& first,const Fixed& scnd);
		-> In case of 
				Fixed::max(x, y) = 42; 	// This would allow us to change a CONST variable!
										// ERROR: x and y were supposed to be read-only!


*/