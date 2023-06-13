/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 15:13:58 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/13 17:27:09 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

// void	f(void)
// {
// 	system("leaks -q test");
// }

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN \"<expression>\"" << std::endl;
		return 1;
	}
	RPN	calc(argv[1]);
	try
	{
		calc.exec();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	// atexit(f);
	return 0;
}
