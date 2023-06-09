/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 14:40:23 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/13 15:28:01 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

// void	f(void)
// {
// 	system("leaks -q btc");
// }

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <input_file>";
		return 1;
	}
	(void)argv, (void)argc;
	BitcoinExchange	exchanger;
	try
	{
		exchanger.readPriceFile("data.csv");
		exchanger.exec(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	// atexit(f);
	return 0;
}

