/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 18:05:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 19:49:28 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy constructor called for Brain" << std::endl;
	*this = copy;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return;
	this->ideas[i] = idea;
}

std::string	Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return "";
	return this->ideas[i];
}