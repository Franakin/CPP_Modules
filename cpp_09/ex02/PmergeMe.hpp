/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:03:17 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/23 16:30:39 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <iostream>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);

		std::deque<int>		asDeque;
		std::vector<int>	asVector;
		unsigned int		size;
		int					straggler;
		bool				hasStraggler;

	public:
		PmergeMe(char **argv, int size);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe &copy);

		void			checkStraggler(void);

		void			sortDeque(void);
		std::string		isDequeSorted(void) const;
		std::deque<int>	getDeque(void) const;
		std::deque<int>	getJacobsthalOrder(unsigned int pendSize) const;
		std::deque<int>	getPairInfo(unsigned int sSize) const;

		void			sortVector(void);
};

std::ostream& operator<<(std::ostream& os, const PmergeMe& list);

#endif
