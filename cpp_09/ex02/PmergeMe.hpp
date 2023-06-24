/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:03:17 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/24 14:53:09 by fpurdom       ########   odam.nl         */
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
		void			sortWithinPairsDeque(void);
		void			sortByPairDeque(void);
		void			insertionSortByJacob(std::deque<int> &pend, std::deque<int> &S, std::deque<int> pairInfo, std::deque<int> jacobOrder);
		std::string		isDequeSorted(void) const;
		std::deque<int>	getDeque(void) const;
		std::deque<int>	getJacobsthalOrderDeque(unsigned int pendSize) const;
		std::deque<int>	getPairInfoDeque(unsigned int sSize) const;

		void				sortVector(void);
		void				sortWithinPairsVector(void);
		void				sortByPairVector(void);
		void				insertionSortByJacob(std::vector<int> &pend, std::vector<int> &S, std::vector<int> pairInfo, std::vector<int> jacobOrder);
		std::string			isVectorSorted(void) const;
		std::vector<int>	getVector(void) const;
		std::vector<int>	getJacobsthalOrderVector(unsigned int pendSize) const;
		std::vector<int>	getPairInfoVector(unsigned int sSize) const;
};

std::ostream& operator<<(std::ostream& os, const PmergeMe& list);

#endif
