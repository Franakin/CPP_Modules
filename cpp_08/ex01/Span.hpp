/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 15:10:50 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/03 13:05:29 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>

class Span
{
	private:
		unsigned int	N;
		std::list<int>	elements;
		Span();

	public:
		Span(const unsigned int newN);
		Span(const Span &copy);
		~Span();

		Span	&operator=(const Span &copy);

		void			addNumber(const int newElement);
		void			addNumbers(std::list<int>::const_iterator it1, std::list<int>::const_iterator it2);
		long			shortestSpan(void) const;
		long			longestSpan(void) const;
		std::list<int>	getElements(void) const;

		class maxStorageReachedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class noSpanException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Span &sp);

#endif
