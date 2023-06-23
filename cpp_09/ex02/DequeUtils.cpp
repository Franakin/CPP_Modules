/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DequeUtils.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 16:43:11 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/23 16:44:33 by fpurdom       ########   odam.nl         */
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

std::deque<int>	PmergeMe::getPairInfo(unsigned int sSize) const
{
	std::deque<int>	ret(sSize);

	for (unsigned int i = 0; i < sSize; i++)
		ret[i] = (int)i - 2;
	return ret;
}

std::deque<int>	PmergeMe::getJacobsthalOrder(unsigned int pendSize) const
{
	int	prevGroupSize = 0, currentGroupSize = 2;
	unsigned int	i = 0;
	std::deque<int>	ret(pendSize);

	while (i < pendSize)
	{
		int	groupOriginIndex = i;
		for (int groupIterator = currentGroupSize - 1; groupIterator >= 0; groupIterator--)
		{
			ret[i] = groupOriginIndex + groupIterator;
			if (ret[i] > (int)pendSize)
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
