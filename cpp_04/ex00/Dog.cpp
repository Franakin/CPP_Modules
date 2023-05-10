/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:43:47 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 18:17:25 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.type;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "OMG WOOF WOOF WOOF!" << std::endl;
}
