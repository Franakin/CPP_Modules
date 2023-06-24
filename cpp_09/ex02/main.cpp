/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:03:08 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/24 13:53:38 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include "PmergeMe.hpp"

// void	f(void)
// {
// 	system("leaks -q test");
// }

int main(int argc, char **argv)
{
	argc--;
	if (argc < 1)
		return std::cerr << "No input :(" << std::endl, 1;
	if (argc == 1)
		return std::cerr << "The purpose of this exercise is to compare the different efficiencies of two different types of containers when it comes to sorting a list of numbers using a specific sorting algorithm, this becomes impossible if you only input a single argument" << std::endl, 1;
	try
	{
		PmergeMe	sorter(argv + 1, argc);
		clock_t		dequeTime, vectorTime;
		
		std::cout << "\nBefore: " << sorter << std::endl;
		dequeTime = clock();
		sorter.sortDeque();
		dequeTime = clock() - dequeTime;
		vectorTime = clock();
		sorter.sortVector();
		vectorTime = clock() - dequeTime;
		std::cout << "After: " << sorter << std::endl;
		std::cout << "Is deque sorted? " << sorter.isDequeSorted() << std::endl;
		std::cout << "Is vector sorted? " << sorter.isVectorSorted() << std::endl;
		std::cout << "Time to process range of " << argc << " elements with std::deque: " << dequeTime * 1000 << " us" << std::endl;
		std::cout << "Time to process range of " << argc << " elements with std::vector: " << vectorTime * 1000 << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// atexit(f);
	return 0;
}
