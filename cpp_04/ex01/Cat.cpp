/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:05:43 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 19:53:17 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
	*this->brain = *copy.brain;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat	&Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	*this->brain = *copy.brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "let me out MEOW!" << std::endl;
}

void	Cat::printBrainPtr(void) const
{
	std::cout << "Address of " << this->getType() << " Brain pointer: " << this->brain << std::endl;
}

void	Cat::setIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}

std::string	Cat::getIdea(int i) const
{
	return this->brain->getIdea(i);
}