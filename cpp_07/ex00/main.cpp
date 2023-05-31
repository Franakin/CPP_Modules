/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 15:22:45 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/27 16:00:25 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	{
		std::cout << "\n\033[1;46m--TESTING INTS--\033[0m\n" << std::endl;
		int x = 100;
		int y = -6;
		std::cout << "Before Swap, x = " << x << "; y = " << y << std::endl;
		swap(x, y);
		std::cout << "After Swap, x = " << x << "; y = " << y << std::endl;
		std::cout << "Min = " << min(x, y) << std::endl;
		std::cout << "Max = " << max(x, y) << std::endl;
	}
	{
		std::cout << "\n\033[1;46m--TESTING CHARS--\033[0m\n" << std::endl;
		char x = 'k';
		char y = '1';
		std::cout << "Before Swap, x = " << x << "; y = " << y << std::endl;
		swap(x, y);
		std::cout << "After Swap, x = " << x << "; y = " << y << std::endl;
		std::cout << "Min = " << min(x, y) << std::endl;
		std::cout << "Max = " << max(x, y) << std::endl;
	}
	{
		std::cout << "\n\033[1;46m--TESTING FLOATS--\033[0m\n" << std::endl;
		float x = 5.1f;
		float y = 5.12f;
		std::cout << "Before Swap, x = " << x << "; y = " << y << std::endl;
		swap(x, y);
		std::cout << "After Swap, x = " << x << "; y = " << y << std::endl;
		std::cout << "Min = " << min(x, y) << std::endl;
		std::cout << "Max = " << max(x, y) << std::endl;
	}
	{
		std::cout << "\n\033[1;46m--TESTING DOUBLES--\033[0m\n" << std::endl;
		double x = 9999999999999999.9;
		double y = 9999999999999999999999999.9;
		std::cout << "Before Swap, x = " << x << "; y = " << y << std::endl;
		swap(x, y);
		std::cout << "After Swap, x = " << x << "; y = " << y << std::endl;
		std::cout << "Min = " << min(x, y) << std::endl;
		std::cout << "Max = " << max(x, y) << std::endl;
	}
	{
		std::cout << "\n\033[1;46m--TESTING STRINGS--\033[0m\n" << std::endl;
		std::string x = "lmao idk";
		std::string y = "how do you know what's bigger";
		std::cout << "Before Swap, x = " << x << "; y = " << y << std::endl;
		swap(x, y);
		std::cout << "After Swap, x = " << x << "; y = " << y << std::endl;
		std::cout << "Min = " << min(x, y) << std::endl;
		std::cout << "Max = " << max(x, y) << std::endl;
	}
	{
		std::cout << "\n\033[1;46m--TESTING BOOLS--\033[0m\n" << std::endl;
		bool x = true;
		bool y = false;
		std::cout << "Before Swap, x = " << x << "; y = " << y << std::endl;
		swap(x, y);
		std::cout << "After Swap, x = " << x << "; y = " << y << std::endl;
		std::cout << "Min = " << min(x, y) << std::endl;
		std::cout << "Max = " << max(x, y) << std::endl << std::endl;
	}
	atexit(f);
	return 0;
}

