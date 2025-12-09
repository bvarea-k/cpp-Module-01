/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:47:24 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/09 16:48:39 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _numberValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*It transfoms a int to fixed-point*/

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_numberValue = value << _fractionalBits;			// = value * 256
}

/*It transforms a float into a fixed-point*/
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_numberValue = roundf(value * (1 << _fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl; //Shown when assigning
	if (this != &other)								//You don't need to copy it if they are the same
		this->_numberValue = other.getRawBits();

	return (*this);
}

int		Fixed::getRawBits( void ) const {
	return (this->_numberValue);
}

void	Fixed::setRawBits ( int const raw ) {
	this->_numberValue = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)_numberValue / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const {
	return (_numberValue >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

				/***Arithmetic operators***/

Fixed Fixed::operator+(const Fixed &other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}

				/***Comparison operators ***/

bool Fixed::operator>(const Fixed &other) const {
	return (this->toFloat() > other.toFloat());
}

/*bool Fixed::operator>(const Fixed &other) const {
	if (this->toFloat() > other.toFloat()) {
		return (true);
	}
	else
		return (false);
}*/

bool Fixed::operator<(const Fixed &other) const {
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->toFloat() != other.toFloat());
}

				/***Increment / Decrement operators***/

Fixed &Fixed::operator++(void) {
	_numberValue++;
	return (*this);
	
}

Fixed Fixed::operator++(int) {
	 Fixed tmp(*this);			//Copy before incrementing
	_numberValue++;
	return (tmp); 
}

Fixed &Fixed::operator--(void) {
	_numberValue--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);			//Copy before decrementing
	_numberValue--;
	return (tmp); 
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1 < f2)
		return f1;
	else
 		return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}
