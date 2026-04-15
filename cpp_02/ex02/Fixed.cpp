#include "Fixed.hpp"


//Min Max, const, non const
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

//Pre/Post crements
//In Fixed Point, the increment is always the same because we are operating on the underlying storage, not the human-readable value.
//If you want to add a "whole integer 1" (making 5.0 become 6.0), you would use your + operator like this: a + Fixed(1).

//Pre-Increment ++i (Increment first, then use)
Fixed& Fixed::operator++(){
	this->setRawBits(this->_fixp + 1);
	return *this;
}
//Pre-Decrement --i
Fixed& Fixed::operator--(){
	this->setRawBits(this->_fixp - 1);
	return *this;
}
//Post-Increment (a = i++; a is 5 | i is 6;)
Fixed Fixed::operator++(int){
	Fixed temp(*this); 
	++(*this); 				// In C++, the  ++ has a higher priority than the *(dereference) operator. So () needed, otherwise pointer++ and not value++
	return temp;
}
//Post increment i++
Fixed Fixed::operator--(int){
	Fixed temp(*this);
	--(*this);
	return temp;
}

//arithmetic operator
Fixed Fixed::operator+(const Fixed& right)const{
	Fixed result;
	result.setRawBits(this->_fixp + right._fixp);
	return result;
}
Fixed Fixed::operator-(const Fixed& right)const{
	Fixed result;
	result.setRawBits(this->_fixp - right._fixp);
	return result;
}
//Multiply, then shift right ((A * B) >> 8)
Fixed Fixed::operator*(const Fixed& right)const{
	Fixed result;
	long temp = (long)this->_fixp * right._fixp;
	result.setRawBits((int)temp >> _bits);
	return result;
}
//Shift left, then divide (A << 8) / B
Fixed Fixed::operator/(const Fixed& right)const{
	Fixed result;
	long temp = ((long)this->_fixp << _bits) / right._fixp; //!use parentheses to force the compiler to do the shift before the division.
	result.setRawBits((int)temp);
	return result;
}


bool Fixed::operator<(const Fixed& right)const{
	return(this->_fixp < right._fixp);
}
bool Fixed::operator>(const Fixed& right)const{
	return(this->_fixp > right._fixp);
}
bool Fixed::operator<=(const Fixed& right)const{
	return(this->_fixp <= right._fixp);
}
bool Fixed::operator>=(const Fixed& right)const{
	return(this->_fixp >= right._fixp);
}
bool Fixed::operator!=(const Fixed& right)const{
	return(this->_fixp != right._fixp);
}
bool Fixed::operator==(const Fixed& right)const{
	return(this->_fixp == right._fixp);
}

//----From ex01----\\
//Int constructor
//Float constructor
//tofloat()
//toint()
//ostream

Fixed::Fixed(const int n){
	//std::cout << "Int constructor called" << std::endl;
	(*this)._fixp = n << _bits;
}

Fixed::Fixed(const float f){
	//std::cout << "Float constructor called" << std::endl;
	this->_fixp = static_cast<int>(roundf(f * (1 << _bits))); 
}

float Fixed::toFloat( void ) const{
	//std::cout << "tofloat memberfunction called" << std::endl;
	return (static_cast<float>(this->_fixp) / (1 << _bits) );
}

int Fixed::toInt( void ) const{
	//std::cout << "toInt memberfunction called" << std::endl;
	return(this->_fixp >> _bits);
}

std::ostream& operator<<(std::ostream& out,const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}

//----From ex00----\\
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
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src){
        this->_fixp = src._fixp;
    }
	return *this;
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


