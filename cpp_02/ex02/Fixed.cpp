/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 17:59:58 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/05 19:08:27 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//---------------- Default constructors and destructor

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int i)
{
	this->number = i << this->frac;
}

Fixed::Fixed(const float f)
{
	this->number = (int)roundf((f * (1 << this->frac)));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

//---------------- Member functions

float	Fixed::toFloat(void) const
{
	return ((float)this->number / (float)(1 << this->frac));
}

int	Fixed::toInt(void) const
{
	return (this->number >> this->frac);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void	Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

//---------------- Min Max member functions

Fixed	&Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1.getRawBits() <= n2.getRawBits())
		return n1;
	return n2;
}

const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() <= n2.getRawBits())
		return n1;
	return n2;
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1.getRawBits() >= n2.getRawBits())
		return n1;
	return n2;
}

const Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() >= n2.getRawBits())
		return n1;
	return n2;
}

//---------------- << and = operators

std::ostream	&operator<<(std::ostream &out, const Fixed &n)
{
	out << n.toFloat();
	return out;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->number = copy.getRawBits();
	return (*this);
}

//---------------- Increment / decrement operators

//prefix
Fixed	&Fixed::operator++(void)
{
	this->number++;
	return *this;
}

//postfix
Fixed	Fixed::operator++(int i)
{
	(void)i;
	Fixed	old(*this);
	
	this->number++;
	return old;
}

//prefix
Fixed	&Fixed::operator--(void)
{
	this->number--;
	return *this;
}

//postfix
Fixed	Fixed::operator--(int i)
{
	(void)i;
	Fixed	old(*this);

	this->number--;
	return old;
}

//---------------- Comparison operators

bool	Fixed::operator>(const Fixed &n) const
{
	return (this->number > n.getRawBits());
}

bool	Fixed::operator<(const Fixed &n) const
{
	return (this->number < n.getRawBits());
}

bool	Fixed::operator>=(const Fixed &n) const
{
	return (this->number >= n.getRawBits());
}

bool	Fixed::operator<=(const Fixed &n) const
{
	return (this->number <= n.getRawBits());
}

bool	Fixed::operator==(const Fixed &n) const
{
	return (this->number == n.getRawBits());
}

bool	Fixed::operator!=(const Fixed &n) const
{
	return (this->number != n.getRawBits());
}

//---------------- Arithmetic operators

Fixed	Fixed::operator+(const Fixed &n) const
{
	Fixed	newN;

	newN.setRawBits(this->number + n.getRawBits());
	return (newN);
}

Fixed	Fixed::operator-(const Fixed &n) const
{
	Fixed	newN;

	newN.setRawBits(this->number - n.getRawBits());
	return (newN);
}

Fixed	Fixed::operator*(const Fixed &n) const
{
	Fixed	newN;

	newN.setRawBits((this->number * n.getRawBits()) >> this->frac);
	return (newN);
}

Fixed	Fixed::operator/(const Fixed &n) const
{
	return Fixed(this->toFloat() / n.toFloat());
}
