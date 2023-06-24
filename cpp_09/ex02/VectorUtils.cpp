/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   VectorUtils.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 18:06:54 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/24 13:55:04 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::getVector(void) const
{
	return asVector;
}

std::string	PmergeMe::isVectorSorted(void) const
{
	return ((std::is_sorted(asVector.begin(), asVector.end())) ? "Sorted!" : "Not sorted :(");
}

void	PmergeMe::sortWithinPairsVector(void)
{
	for (unsigned int i = 1; i < size; i += 2)
	{
		if (asVector[i] < asVector[i - 1])
		{
			const int	save = asVector[i];
			asVector[i] = asVector[i - 1];
			asVector[i - 1] = save;
		}
	}
}

void	PmergeMe::sortByPairVector(void)
{
	std::vector<int>	newVector;
	newVector.push_back(asVector[1]);
	newVector.insert(newVector.begin(), asVector[0]);

	for (unsigned int i = 3; i < size; i += 2)
	{
		for (unsigned int k = 1; k < size; k += 2)
		{
			if (asVector[i] < newVector[k])
			{
				newVector.insert(newVector.begin() + k - 1, asVector[i]);
				newVector.insert(newVector.begin() + k - 1, asVector[i - 1]);
				break;
			}
			else if (newVector.begin() + k + 1 == newVector.end())
			{
				newVector.insert(newVector.end(), asVector[i - 1]);
				newVector.insert(newVector.end(), asVector[i]);
				break;
			}
		}
	}
	asVector = newVector;
}

std::vector<int>	PmergeMe::getPairInfoVector(unsigned int sSize) const
{
	std::vector<int>	ret(sSize);

	for (unsigned int i = 0; i < sSize; i++)
		ret[i] = (int)i - 2;
	return ret;
}

std::vector<int>	PmergeMe::getJacobsthalOrderVector(unsigned int pendSize) const
{
	int	prevGroupSize = 0, currentGroupSize = 2;
	unsigned int	i = 0;
	std::vector<int>	ret(pendSize);

	if (pendSize < 2)
		return ret;
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

void	PmergeMe::insertionSortByJacob(std::vector<int> pend, std::vector<int> S, std::vector<int> pairInfo, std::vector<int> jacobOrder)
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
			S.insert(S.begin(), straggler);
	}
	asVector = S;
}