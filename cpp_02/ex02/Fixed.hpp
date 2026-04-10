#include <iostream>
#include <cmath>

class Fixed {
	
private:
	int _fixp; 					//fixpoint = the Raw bits = the raw integer value (not 5 but 1280)
	static const int _bits = 8; 

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& src); 		// Copy constructor
	Fixed(const int n); 			//Const Integer Constructor, converts n to _fixp
	Fixed(const float f);			//Const float Constructor, converts f to _fixp
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int 	toInt( void ) const;

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
	Fixed operator++(int);	//Post-Increment a = i++; a is 5 | i is 6;
	Fixed operator--(int);	//Post increment
	
	static Fixed& min(Fixed& first, Fixed& scnd);
	static const Fixed& min(const Fixed& first, const Fixed& scnd);
	static Fixed& max(Fixed& first, Fixed& scnd);
	static const Fixed& max(const Fixed& first,const Fixed& scnd);

};

std::ostream& operator<<(std::ostream &out,const Fixed &fixed); //overload of insertion operator


/*
Why "Static"?
Since these are static, they don't belong to a specific instance of the class (like a or b). You call them using the class name itself:
*/