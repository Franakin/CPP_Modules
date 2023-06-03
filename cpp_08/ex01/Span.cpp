/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 15:10:52 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/03 13:22:40 by fpurdom       ########   odam.nl         */
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

std::ostream	&operator<<(std::ostream &out, const Span &sp)
{
	const std::list<int>			elements = sp.getElements();
	std::list<int>::const_iterator	it = elements.begin();
	int								i = 10;

	while (i > 0 && it != elements.end())
	{
		out << '[' << *it << ']';
		it++;
		i--;
	}
	if (!i)
		out << "...(" << elements.size() << " total numbers)";
	return out;
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

long	Span::shortestSpan(void) const
{
	if (elements.size() < 2)
		throw noSpanException();
	long	minSpan, currentSpan;
	std::list<int>::const_iterator it1 = elements.begin();
	std::list<int>::const_iterator it2 = it1;
	std::list<int>::const_iterator it3 = it1;
	it3++;
	minSpan = longestSpan();
	while (it3 != elements.end())
	{
		it2++;
		currentSpan = std::abs((long)*it2 - (long)*it1);
		if (currentSpan == 0)
			return 0;
		if (currentSpan < minSpan)
			minSpan = currentSpan;
		it1++;
		it3++;
	}
	return minSpan;
}

long	Span::longestSpan(void) const
{
	if (elements.size() < 2)
		throw noSpanException();
	return std::abs((long)elements.back() - (long)elements.front());
}

std::list<int>	Span::getElements(void) const
{
	return elements;
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