/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:05:43 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 18:17:19 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = copy.type;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "let me out MEOW!" << std::endl;
}
