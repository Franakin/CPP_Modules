/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 15:12:39 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/27 15:27:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> void	swap(T &val1,  T &val2)
{
	T temp = val1;
	
	val1 = val2;
	val2 = temp;
}

template <typename T> T	min(T &val1, T &val2)
{
	return (val1 < val2) ? val1 : val2;
}

template <typename T> T max(T &val1, T &val2)
{
	return (val1 > val2) ? val1 : val2;
}

#endif
