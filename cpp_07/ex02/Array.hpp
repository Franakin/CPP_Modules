/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 17:54:11 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/31 18:34:02 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
	private:
		T			*array;
		unsigned int len;

	public:
		//--------------------------------------------------------------------Defaults
		Array() : array(new T[0]()), len(0){}
		Array(unsigned int n) : array(new T[n]()), len(n){}
		Array(const Array &copy) : array(new T[copy.len]()), len(copy.len)
		{
			for (unsigned long i = 0; i < len; i++)
				array[i] = copy.array[i];
		}
		~Array()
		{
			delete[] array;
		}

		//--------------------------------------------------------------------Member Function
		unsigned int	size(void) const
		{
			return len;
		}

		//--------------------------------------------------------------------Operators
		Array<T>	&operator=(const Array &copy)
		{
			if (this == &copy)
				return *this;
			if (array)
				delete[] array;
			array = new T[copy.len];
			len = copy.len;
			for (unsigned long i = 0; i < len; i++)
				array[i] = copy.array[i];
			return *this;
		}

		T	&operator[](const int i) const
		{
			if ((unsigned int)i >= len)
				throw std::exception();
			return array[i];
		}
};

template <typename T> std::ostream	&operator<<(std::ostream &out, const Array<T> &array)
{
	for (unsigned int i = 0; i < array.size(); i++)
		out << '[' << array[i] << ']';
	return out;
}

#endif
