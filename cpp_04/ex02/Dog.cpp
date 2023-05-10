/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:43:47 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 19:52:54 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
	*this->brain = *copy.brain;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog	&Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	*this->brain = *copy.brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "OMG WOOF WOOF WOOF!" << std::endl;
}

void	Dog::printBrainPtr(void) const
{
	std::cout << "Address of " << this->getType() << " Brain pointer: " << this->brain << std::endl;
}

void	Dog::setIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}

std::string	Dog::getIdea(int i) const
{
	return this->brain->getIdea(i);
}