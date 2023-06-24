/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:03:11 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/24 15:44:13 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>
#include <algorithm>

//defaults-----------------------------------------------------------------------------------------------------------------------------------------------------
PmergeMe::PmergeMe(char **nbrs, int argc)
{
	long		n;
	std::string	s;

	size = argc;
	for (unsigned int i = 0; i < size; i++)
	{
		s = nbrs[i];
		if (s.find_first_not_of("-0123456789") != std::string::npos ||
		(s.find_last_of('-') != 0 && s.find_last_of('-') != std::string::npos))
			throw std::runtime_error("Invalid input");
		n = std::atol(nbrs[i]);
		if (n > INT_MAX || n < INT_MIN)
			throw std::runtime_error("Int overflow");
		asDeque.push_back((int)n);
		asVector.push_back((int)n);
	}
}

PmergeMe::PmergeMe(void){}

PmergeMe::PmergeMe(const PmergeMe &copy){(void)copy;}

PmergeMe::~PmergeMe(void){}

//operators----------------------------------------------------------------------------------------------------------------------------------------------------
PmergeMe	&PmergeMe::operator=(const PmergeMe &copy){(void)copy; return (*this);}

std::ostream& operator<<(std::ostream& os, const PmergeMe& sorter)
{
	std::deque<int>		dequeList = sorter.getDeque();
	std::vector<int>	vectorList = sorter.getVector();
	unsigned int		size = dequeList.size(), i = 0;
	std::deque<int>::iterator it = dequeList.begin();

	for (; it != dequeList.end() && i < 10; i++, ++it)
		os << *it << ' ';
	it++;
	if (i < size)
		os << "[...]";
	// for (i = 0; i < size; i++)
	// 	if (dequeList[i] != vectorList[i])
	// 		throw std::runtime_error("Deque and vector are not the same");
	return os;
}

//member functions---------------------------------------------------------------------------------------------------------------------------------------------
void	PmergeMe::checkStraggler(void)
{
	if (size % 2)
	{
		hasStraggler = true;
		straggler = asDeque[size - 1];
		size--;
		return;
	}
	hasStraggler = false;
}

//DEQUE SORTER//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void	PmergeMe::sortDeque(void)
{
	if (size == 1)
		return;
	//CHECK FOR STRAGGLER
	checkStraggler();
	if (hasStraggler)
		asDeque.pop_back();
	//DIVIDE BY PAIRS AND SORT THE NUMBERS WITHIN EACH PAIR
	sortWithinPairsDeque();

	//SORT THE PAIRS BASED ON THEIR LARGEST NUMBER
	sortByPairDeque();

	//MAKE 2 DEQUES, 1 WITH THE SMALLEST NUMBERS WITHIN THE PAIRS (pend) AND THE OTHER WITH THE BIGEST ONES (S),THEN ADD FIRST pend MEMBER TO S
	std::deque<int>	S, pend;
	
	for (unsigned int i = 1; i < size; i += 2)
	{
		S.push_back(asDeque[i]);
		pend.push_back(asDeque[i - 1]);
	}
	S.push_front(asDeque[0]);
	pend.pop_front();
	
	//INSERTION SORT of the elements of pend into S up until but not including the original number it was paired with, in order dictated by a Jacobsthal sequence.

	//JACOBSTHAL SEQUENCE APPLICATION: divide the elements in pend into groups then invert the order of those elements, insert based on this new order
	//The group sizes begin as 2, so the first two elements in pend are swapped. The size of every proceeding group is [groupSize of group before] + ([groupSize of group before that one] * 2), so group sizes are 2, 2, 6, 10, 22, 42...
	
	//If the total N in the sequence is an impaired number, insert the straggler as the last step.
	insertionSortByJacob(pend, S, getPairInfoDeque(S.size()), getJacobsthalOrderDeque(pend.size()));
}

//VECTOR SORTER/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void	PmergeMe::sortVector(void)
{
	if (size == 1)
		return;
	checkStraggler();
	if (hasStraggler)
		asVector.pop_back();
	sortWithinPairsVector();
	sortByPairVector();

	std::vector<int>	S, pend;
	for (unsigned int i = 1; i < size; i += 2)
	{
		S.push_back(asVector[i]);
		pend.push_back(asVector[i - 1]);
	}
	S.insert(S.begin(), asVector[0]);
	pend.erase(pend.begin());

	insertionSortByJacob(pend, S, getPairInfoVector(S.size()), getJacobsthalOrderVector(pend.size()));
}