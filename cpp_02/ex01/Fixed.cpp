/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 17:59:58 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/05 14:04:10 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Destructor called" << std::endl;
}

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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void	Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->number = copy.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &n)
{
	out << n.toFloat();
	return out;
}