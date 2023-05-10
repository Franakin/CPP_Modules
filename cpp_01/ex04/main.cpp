/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 12:52:15 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 15:57:06 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./sed <filename> <string to find> <string to replace>" <<std::endl;
		return EXIT_FAILURE;
	}
	Sed	prog(argv[1]);
	prog.replace(argv[2], argv[3]);
	return EXIT_SUCCESS;
}