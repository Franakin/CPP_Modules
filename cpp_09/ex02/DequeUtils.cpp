/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DequeUtils.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 16:43:11 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/24 15:44:27 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::deque<int>	PmergeMe::getDeque(void) const
{
	return asDeque;
}

std::string	PmergeMe::isDequeSorted(void) const
{
	return ((std::is_sorted(asDeque.begin(), asDeque.end())) ? "Sorted!" : "Not sorted :(");
}

void	PmergeMe::sortWithinPairsDeque(void)
{
	for (unsigned int i = 1; i < size; i += 2)
	{
		if (asDeque[i] < asDeque[i - 1])
		{
			const int	save = asDeque[i];
			asDeque[i] = asDeque[i - 1];
			asDeque[i - 1] = save;
		}
	}
}

void	PmergeMe::sortByPairDeque(void)
{
	std::deque<int>	newDeque;
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
	asDeque = newDeque;
}

std::deque<int>	PmergeMe::getPairInfoDeque(unsigned int sSize) const
{
	std::deque<int>	ret(sSize);

	for (unsigned int i = 0; i < sSize; i++)
		ret[i] = (int)i - 2;
	return ret;
}

std::deque<int>	PmergeMe::getJacobsthalOrderDeque(unsigned int pendSize) const
{
	int	prevGroupSize = 0, currentGroupSize = 2;
	unsigned int	i = 0;
	std::deque<int>	ret(pendSize);

	if (pendSize < 2)
		return ret;
	while (i < pendSize)
	{
		int	groupOriginIndex = i;
		for (int groupIterator = currentGroupSize - 1; groupIterator >= 0; groupIterator--)
		{
			ret[i] = groupOriginIndex + groupIterator;
			if (ret[i] >= (int)pendSize)
			{
				groupIterator = pendSize - i - 1;
				ret[i] = groupOriginIndex + groupIterator;
			}
			i++;
		}
		const int	save = currentGroupSize;
		currentGroupSize = currentGroupSize + prevGroupSize * 2;
		prevGroupSize = save;
	}
	return ret;
}

void	PmergeMe::insertionSortByJacob(std::deque<int> &pend, std::deque<int> &S, std::deque<int> pairInfo, std::deque<int> jacobOrder)
{
	for (unsigned int i = 0; i < pend.size(); i++)
	{
		unsigned int k;
		for (k = 0; pairInfo[k] < jacobOrder[i]; k++)
		{
			if (pend[jacobOrder[i]] < S[k])
			{
				S.insert(S.begin() + k, pend[jacobOrder[i]]);
				pairInfo.insert(pairInfo.begin() + k, -1);
				break;
			}
		}
		if (pairInfo[k] == jacobOrder[i])
		{
			S.insert(S.begin() + k, pend[jacobOrder[i]]);
			pairInfo.insert(pairInfo.begin() + k, -1);
		}
	}
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