#include "Fixed.hpp"

//----NEW IN ex01----\\
//Int constructor
//Float constructor
//tofloat()
//toint()
//overload of insertion operator


/*Precedence:
0. Function Call (...) and whats happening in the (...)
1. Type Cast
2. Multi/Divi 		* /
4. Sum/Subs			+ -
3. Shift Operators	<< >>
*/

Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	(*this)._fixp = n << _bits; 
};// n = 1 -> 1*256 -> fixp = 256 (00000001 00000000) // but done with bit shifting: 1 << 8 = 1 * 256



Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->_fixp = static_cast<int>(roundf(f * (1 << _bits))); 
}//42.42f -> 42.42 * 256 = 10859.52 -> roundf(10859.52) becomes (int)10860


float Fixed::toFloat( void ) const{
	std::cout << "tofloat memberfunction called" << std::endl;
	return (static_cast<float>(this->_fixp) / (1 << _bits) ); //First Cast to Float, then divide! == Force Float Division
}

int Fixed::toInt( void ) const{
	std::cout << "toInt memberfunction called" << std::endl;
	return(this->_fixp >> _bits); 
}//fixp >> 8 and _fixp / 256 are the same, but >> much faster

std::ostream& operator<<(std::ostream& out,const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}

///////// From previous ex00

//Def Cons
//Cpy Cons
//Des
//Copy assignment operator
//getter & setter

Fixed::Fixed(): _fixp(0){
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src){
	std::cout << "Copy Constructor called" << std::endl;
	this->_fixp = src._fixp;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src){
        this->_fixp = src._fixp;
    }
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixp;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	_fixp = raw;
}


/* Float Constructor
When converting a float to fixed-point, you can't use bit-shifting (<<) directly,
because the CPU handles float bits differently than integer bits. 
Instead, you multiply by your scaling factor ($2^8 = 256$) and round the result.

trading infinte preciosion for perfect speed and predictability
bit-shift operator (<<) is not defined for floats 
So to: f * 2^_bits you have to f * (1 << _bits) //(1 << _bits) = 256
If casting directly as int, wihout rounding zou losse accuracy immediatly
first use roundf so 0.999... becomes 1.0 and not 0
--> (int)0.9 becomes 0. --> roundf(0.9) becomes 1.*/



// Int constructor [n * 2^_bits] 
// n << 8 is the same (but much faster) than: n * pow(2, _bits) 
// Dont write n*256, because its Hardcoded 