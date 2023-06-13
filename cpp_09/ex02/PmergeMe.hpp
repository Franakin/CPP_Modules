/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:03:17 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/13 19:03:35 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe
{
	private:
		

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &copy);
};

#endif
