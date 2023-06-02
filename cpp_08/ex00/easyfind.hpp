/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/01 14:57:48 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/02 14:48:23 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename T>

bool	easyfind(T &container, const int needle)
{
	return std::find(container.begin(), container.end(), needle) != container.end();
}