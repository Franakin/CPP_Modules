/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 15:10:52 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/02 19:52:06 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cmath>

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
Span::Span(void) : N(0){}

Span::Span(const unsigned int newN) : N(newN){}

Span::Span(const Span &copy) : N(copy.N), elements(copy.elements){}

Span::~Span(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
Span	&Span::operator=(const Span &copy)
{
	this->N = copy.N;
	this->elements = copy.elements;
	return (*this);
}

//member functions--------------------------------------------------------------------------------------------------------------------------------------------
void	Span::addNumber(const int newElement)
{
	if (elements.size() == N || elements.size() == elements.max_size())
		throw maxStorageReachedException();
	elements.push_back(newElement);
	elements.sort();
}

void	Span::addNumbers(std::list<int>::const_iterator start, std::list<int>::const_iterator end)
{
	unsigned long	totalSize = std::distance(start, end) + elements.size();

	if (totalSize > N)
		throw maxStorageReachedException();
	elements.insert(elements.end(), start, end);
	elements.sort();
}

unsigned int	Span::shortestSpan(void) const
{
	if (elements.size() < 2)
		throw noSpanException();
	unsigned int	minSpan, currentSpan;
	std::list<int>::const_iterator it1 = elements.begin();
	std::list<int>::const_iterator it2 = it1;
	minSpan = longestSpan();
	while (it2 != elements.end())
	{
		it2++;
		currentSpan = std::abs(*it1 - *it2);
		if (currentSpan == 0)
			return 0;
		if (currentSpan < minSpan)
			minSpan = currentSpan;
		it1++;
	}
	return minSpan;
}

unsigned int	Span::longestSpan(void) const
{
	if (elements.size() < 2)
		throw noSpanException();
	return std::abs(elements.back() - elements.front());
}

//exceptions--------------------------------------------------------------------------------------------------------------------------------------------
const char	*Span::maxStorageReachedException::what() const throw()
{
	return "Maximum number of stored integers reached";
}

const char	*Span::noSpanException::what() const throw()
{
	return "Not enough integers stored to determine span";
}