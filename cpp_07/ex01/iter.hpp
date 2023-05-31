/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 16:29:02 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/31 16:43:07 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void	iter(T *arr, size_t len, void (*func)(const T &val))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif
