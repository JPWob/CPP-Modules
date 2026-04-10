#include "Fixed.hpp"

Fixed& Fixed::min(Fixed& first, Fixed& scnd){
	if (first < scnd)
		return first;
	else
		return scnd;
}
const Fixed& Fixed::min(const Fixed& first, const Fixed& scnd){
	if (first < scnd)
		return first;
	else
		return scnd;
}
Fixed& Fixed::max(Fixed& first, Fixed& scnd){
	if (first > scnd)
		return first;
	else
		return scnd;
}
const Fixed& Fixed::max(const Fixed& first,const Fixed& scnd){
	if (first > scnd)
		return first;
	else
		return scnd;
}


//In Fixed Point, the increment is always the same because we are operating on the underlying storage, not the human-readable value.
//If you want to add a "whole integer 1" (making 5.0 become 6.0), you would use your + operator: a + Fixed(1).

//Pre-Increment ++i (Increment first, then use)
Fixed& Fixed::operator++(){
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}
//Pre-Decrement --i
Fixed& Fixed::operator--(){
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}
//Post-Increment a = i++; a is 5 | i is 6;
Fixed Fixed::operator++(int){
	Fixed temp(*this); 
	++(*this); // C++, the  ++ has a higher priority than the * (dereference) operator
	return temp;
}
//Post increment
Fixed Fixed::operator--(int){
	Fixed temp(*this);
	--(*this);
	return temp;
}



//arithmetic operator
Fixed Fixed::operator+(const Fixed& right)const{
	Fixed result;
	result.setRawBits(this->getRawBits() + right.getRawBits());
	return result;
}
Fixed Fixed::operator-(const Fixed& right)const{
	Fixed result;
	result.setRawBits(this->getRawBits() - right.getRawBits());
	return result;
}
//Multiply, then shift right ((A * B) >> 8)
Fixed Fixed::operator*(const Fixed& right)const{
	Fixed result;
	long temp = (long)this->getRawBits() * right.getRawBits();
	result.setRawBits((int)temp >> _bits);
	return result;
}
//Shift left, then divide (A << 8) / B
Fixed Fixed::operator/(const Fixed& right)const{
	Fixed result;
	long temp = ((long)this->getRawBits() << _bits) / right.getRawBits(); //!use parentheses to force the compiler to do the shift before the division.
	result.setRawBits((int)temp);
	return result;
}


bool Fixed::operator<(const Fixed& right)const{
	return(this->getRawBits() < right.getRawBits());
}
bool Fixed::operator>(const Fixed& right)const{
	return(this->getRawBits() > right.getRawBits());
}
bool Fixed::operator<=(const Fixed& right)const{
	return(this->getRawBits() <= right.getRawBits());
}
bool Fixed::operator>=(const Fixed& right)const{
	return(this->getRawBits() >= right.getRawBits());
}
bool Fixed::operator!=(const Fixed& right)const{
	return(this->getRawBits() != right.getRawBits());
}
bool Fixed::operator==(const Fixed& right)const{
	return(this->getRawBits() == right.getRawBits());
}

//Int constructor [n * 2^_bits]
Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	(*this)._fixp = n << _bits; 
};

//Float Constructor
Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->_fixp = (int)roundf(f * (1 << _bits)); 
}

float Fixed::toFloat( void ) const{
	return ( (float)this->getRawBits() / (1 << _bits) );
}

int Fixed::toInt( void ) const{
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

