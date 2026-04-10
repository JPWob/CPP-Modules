#include "Fixed.hpp"

//Int constructor [n * 2^_bits]
// n = 1 -> 1*256 -> fixp = 256 (00000001 00000000)
// 1 << 8 = 1 * 256
Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	(*this)._fixp = n << _bits; 
};

//Float Constructor
//42.42f -> 42.42 * 256 = 10859.52 -> roundf(10859.52) becomes (int)10860
Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->_fixp = (int)roundf(f * (1 << _bits)); 
}

float Fixed::toFloat( void ) const{
	//std::cout << "tofloat memberfunction called" << std::endl;
	return ( (float)this->getRawBits() / (1 << _bits) );
}

int Fixed::toInt( void ) const{
	//std::cout << "toInt memberfunction called" << std::endl;
	return(int(this->getRawBits() >> _bits)); //fixp >> 8 and _fixp / 256 are the same, but >> much faster
}


//Def Cons
Fixed::Fixed(): _fixp(0){
	std::cout << "Default Constructor called" << std::endl;
}

//Des
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
};

//Cpy Cons
Fixed::Fixed(const Fixed& src){
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

//=operator overloader: this = src
Fixed& Fixed::operator=(const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) { // Check addresses
        this->setRawBits(src.getRawBits());
    }
	return *this; //returns a reference, not a copy
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _fixp;
}


void Fixed::setRawBits( int const raw ){
	//std::cout << "setRawBits member function called" << std::endl;
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



//Int constructor [n * 2^_bits] 
// n << 8 is the same (but much faster) than: n * pow(2, _bits) 
// Dont write n*256, because its Hardcoded 