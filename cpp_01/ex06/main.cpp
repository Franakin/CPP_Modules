/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 12:52:15 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 16:59:39 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return EXIT_FAILURE;
	}
	Harl MrHarl;
	MrHarl.complain(argv[1]);
	return EXIT_SUCCESS;
}