/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/08 17:03:55 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/14 12:26:20 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	char to_print;

	if (argc < 2)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	argv++;
	while (*argv)
	{
		while (**argv)
		{
			to_print = toupper(**argv);
			std::cout << to_print;
			(*argv)++;
		}
		argv++;
	}
	std::cout << std::endl;
	return (0);
}
