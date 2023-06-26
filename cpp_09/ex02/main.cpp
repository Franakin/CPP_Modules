/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:03:08 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/26 18:46:58 by fpurdom       ########   odam.nl         */
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
	try
	{
		PmergeMe	sorter(argv + 1, argc);
		clock_t		dequeTime, vectorTime;
		
		std::cout << "\nBefore: " << sorter << std::endl;
		dequeTime = clock();
		if (!dequeTime)
			throw std::runtime_error("Clock() error");
		sorter.sortDeque();
		dequeTime = clock() - dequeTime;
		if (!dequeTime)
			throw std::runtime_error("Clock() error");
		vectorTime = clock();
		if (!vectorTime)
			throw std::runtime_error("Clock() error");
		sorter.sortVector();
		vectorTime = clock() - vectorTime;
		if (!vectorTime)
			throw std::runtime_error("Clock() error");
		std::cout << "After:  " << sorter << std::endl << std::endl;
		std::cout << "Is deque sorted?  " << sorter.isDequeSorted() << std::endl;
		std::cout << "Is vector sorted? " << sorter.isVectorSorted() << std::endl << std::endl;
		std::cout << "Time to process range of " << argc << " elements with std::deque:  " << dequeTime << " ticks" << std::endl;
		std::cout << "Time to process range of " << argc << " elements with std::vector: " << vectorTime << " ticks" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// atexit(f);
	return 0;
}
