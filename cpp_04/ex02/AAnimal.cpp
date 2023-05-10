/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 14:35:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 18:17:04 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "Default AAnimal constructor called" << std::endl;
	this->type = "Unknown 4 legged creature";
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = copy.type;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &copy)
{
	this->type = copy.type;
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Bruh I have no idea what noise I'm supposed to make REEEEEEE" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return this->type;
}
