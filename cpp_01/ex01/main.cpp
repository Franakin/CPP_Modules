/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 17:15:50 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 17:07:15 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	f(void)
{
	system("leaks -q zombieHorde");
}

int	main(void)
{
	Zombie		*horde;
	const int	N = 10;

	atexit(f);
	horde = zombieHorde((int)N, "Fred");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	std::cout << std::endl;
	return 0;
}