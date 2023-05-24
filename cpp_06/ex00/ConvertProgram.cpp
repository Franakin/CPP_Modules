/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ConvertProgram.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:34:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/24 15:14:09 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

// void	f(void)
// {
// 	system("leaks -q convert");
// }

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "convert usage: ./convert \"arg1\"" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	// atexit(f);
	return 0;
}
