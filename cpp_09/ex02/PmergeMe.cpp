/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:03:11 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/23 16:47:16 by fpurdom       ########   odam.nl         */
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
	std::deque<int>	list = sorter.getDeque();
	unsigned int	size = list.size(), i;
	
	for (i = 0; i < 5; i++)
		os << list[i] << ' ';
	for (; i < size && i < 5; i++)
		os << list[i] << ' ';
	if (i != size)
		os << "[...]";
	return os;
}

//static functions---------------------------------------------------------------------------------------------------------------------------------------------
template <typename T> static void	printContainer(T &cont)
{
	std::cout << "Contains: ";
	for (typename T::iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

//member functions---------------------------------------------------------------------------------------------------------------------------------------------

void	PmergeMe::checkStraggler(void)
{
	if (size % 2)
	{
		hasStraggler = true;
		straggler = asDeque[size - 1];
		size--;
	}
	hasStraggler = false;
}

//DEQUE SORTER//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void	PmergeMe::sortDeque(void)
{
	//CHECK FOR STRAGGLER
	checkStraggler();
	if (hasStraggler)
		asDeque.pop_back();

	//SORT THE NUMBERS WITHIN EACH PAIR
	//sortWithinPairs();
	for (unsigned int i = 1; i < size; i += 2)
	{
		if (asDeque[i] < asDeque[i - 1])
		{
			const int	save = asDeque[i];
			asDeque[i] = asDeque[i - 1];
			asDeque[i - 1] = save;
		}
	}
	
	//SORT THE PAIRS BASED ON THEIR LARGEST NUMBER
	//asDeque = sortByPair();
	std::deque<int>	newDeque ;
	newDeque.push_back(asDeque[1]);
	newDeque.push_front(asDeque[0]);

	for (unsigned int i = 3; i < size; i += 2)
	{
		for (unsigned int k = 1; k < size; k += 2)
		{
			if (asDeque[i] < newDeque[k])
			{
				newDeque.insert(newDeque.begin() + k - 1, asDeque[i]);
				newDeque.insert(newDeque.begin() + k - 1, asDeque[i - 1]);
				break;
			}
			else if (newDeque.begin() + k + 1 == newDeque.end())
			{
				newDeque.insert(newDeque.end(), asDeque[i - 1]);
				newDeque.insert(newDeque.end(), asDeque[i]);
				break;
			}
		}
	}

	//MAKE 2 DEQUES, 1 WITH THE SMALLEST NUMBERS OF THE PAIRS (pend) AND THE OTHER WITH THE BIGEST ONES (S),THEN ADD FIRST pend MEMBER TO S
	std::deque<int>	S, pend;
	
	for (unsigned int i = 1; i < size; i += 2)
	{
		S.push_back(newDeque[i]);
		pend.push_back(newDeque[i - 1]);
	}
	S.push_front(newDeque[0]);
	pend.pop_front();
	
	//CHANGE ORDER OF pen TO MAKE IT FORD-JONHSON, assigning groups of different sizes to pen, then inverting the order of said groups, new group size is (prev group size) + (prev prev group size)^2, starts at group size 2
	unsigned int	pendSize = pend.size(), sSize = S.size();
	std::deque<int> jacobOrder = getJacobsthalOrder(pendSize), pairInfo = getPairInfo(sSize);

	//INSERTION SORT of the elements of pend into S up until but not including the originally number it was paired with, in order dictated by a Jacobsthal sequence
	for (unsigned int i = 0; i < pendSize; i++)
	{
		unsigned int k;
		for (k = 0; pairInfo[k] < jacobOrder[i]; k++)
		{
			if (pend[jacobOrder[i]] < S[k] || pairInfo[k] == jacobOrder[i])
			{
				S.insert(S.begin() + k, pend[jacobOrder[i]]);
				pairInfo.insert(pairInfo.begin() + k, -1);
				break;
			}
			else if (S.begin() + k + 1 == S.end())
			{
				S.insert(S.end(), pend[jacobOrder[i]]);
				pairInfo.insert(pairInfo.end(), -1);
				break;
			}
		}
	}

	//HANDLE STRAGGLER
	if (hasStraggler)
	{
		unsigned int i;
		for (i = S.size() - 1; i > 0; i--)
		{
			if (straggler > S[i])
			{
				S.insert(S.begin() + i + 1, straggler);
				break;
			}
		}
		if (!i)
			S.push_front(straggler);
	}
	asDeque = S;
}

void	PmergeMe::sortVector(void)
{
	
}