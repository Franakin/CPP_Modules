/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:03:08 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/23 16:32:12 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

// void	f(void)
// {
// 	system("leaks -q test");
// }

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "No input :(" << std::endl;
		return 1;
	}
	if (argc == 2)
	{
		std::cerr << "The purpose of this exercise is to compare the different efficiencies of two different types of containers when it comes to sorting a list of numbers using a specific sorting algorithm, this becomes impossible if you only input a single argument" << std::endl;
		return 2;
	}
	try
	{
		PmergeMe	sorter(argv + 1, argc - 1);
		
		std::cout << "Before: " << sorter << std::endl;
		sorter.sortDeque();
		std::cout << "After: " << sorter << sorter.isDequeSorted() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// atexit(f);
	return 0;
}
