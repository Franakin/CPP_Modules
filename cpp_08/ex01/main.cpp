/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 15:10:59 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/02 19:51:16 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Span.hpp"

// void	f(void)
// {
// 	system("leaks -q test");
// }

int main(void)
{
	Span sp = Span(12);
	std::list<int>	lmao;
	int	arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -999};
	lmao.assign(arr, arr + 11);

	try
	{
		sp.addNumber(6);
		sp.addNumbers(lmao.begin(), lmao.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// atexit(f);
	return 0;
}
