/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 14:35:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 18:17:14 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default animal constructor called" << std::endl;
	this->type = "Unknown 4 legged creature";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = copy.type;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &copy)
{
	this->type = copy.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Bruh I have no idea what noise I'm supposed to make REEEEEEE" << std::endl;
}

std::string	Animal::getType(void) const
{
	return this->type;
}
