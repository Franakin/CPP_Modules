/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/03 15:10:24 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/04 12:42:59 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack<T>(const MutantStack &copy){*this = copy;}
		MutantStack<T>(){}
		~MutantStack<T>(){}

		MutantStack<T>	&operator=(const MutantStack &copy){(void)copy; return this;}

		//iterators
		iterator	begin(void)
		{
			return this->c.begin();
		}
		iterator	end(void)
		{
			return this->c.end();
		}
		
		//reverse iterators
		reverse_iterator	rbegin()
		{
			return this->c.rbegin();
		}
		reverse_iterator	rend()
		{
			return this->c.rend();
		}
		
		//const iterators
		const_iterator	begin(void) const
		{
			return this->c.begin();
		}
		const_iterator	end(void) const
		{
			return this->c.end();
		}
		const_iterator	cbegin(void) const
		{
			return this->c.cbegin();
		}
		const_iterator	cend(void) const
		{
			return this->c.cend();
		}
		
		//const reverse iterators
		const_reverse_iterator	rbegin(void) const
		{
			return this->c.rbegin();
		}
		const_reverse_iterator	rend() const
		{
			return this->c.rend();
		}
		const_reverse_iterator	crbegin(void) const
		{
			return this->crbegin();
		}
		const_reverse_iterator	crend(void) const
		{
			return this->crend();
		}
};

#endif
