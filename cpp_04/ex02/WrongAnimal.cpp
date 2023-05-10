/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:03:00 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 16:03:34 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = "Unknown 4 legged creature";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = copy.type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Bruh I have no idea what noise I'm supposed to make REEEEEEE" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return this->type;
}
