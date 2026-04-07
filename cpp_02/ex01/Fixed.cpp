#include "Fixed.hpp"

Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	(*this)._fixp = n << _bits; // n << 8 is the same (but much faster) as: n * 2^_bits || n * _bits * _bits
};

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
	std::cout << "getRawBits member function called" << std::endl;
	return _fixp;
}


void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	_fixp = raw;
}

