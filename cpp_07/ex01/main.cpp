/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 16:29:07 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/31 16:46:43 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <typeinfo>


// void	f(void)
// {
// 	system("leaks -q test");
// }

template <typename T> void	func(const T &val)
{
	std::cout << '[' << val << ']';
}

int main(void)
{
	{
		std::cout << "\n\033[1;46m--INT ARRAY--\033[0m\n" << std::endl;
		int	arr[5] = {10, 20, 30, 40, 50};
		iter(arr, 5, func);
		std::cout << std::endl;
	}
	{
		std::cout << "\n\033[1;46m--CHAR ARRAY--\033[0m\n" << std::endl;
		char	arr[5] = {'A', 'B', 'C', 'D', 'E'};
		iter(arr, 5, func);
		std::cout << std::endl;
	}
	{
		std::cout << "\n\033[1;46m--FLOAT ARRAY--\033[0m\n" << std::endl;
		float	arr[5] = {99.9, 69, -0.001, 999.9, 0};
		iter(arr, 5, func);
		std::cout << std::endl;
	}
	// atexit(f);
	return 0;
}

