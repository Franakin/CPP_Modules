/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 14:29:18 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 17:06:44 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	f(void)
{
	system("leaks -q zombieHorde");
}

int	main(void)
{
	Zombie	*evaluator;
	std::string const name = "Person evaling this rn";

	atexit(f);
	std::cout << "Zombie created and announced through newZombie:" << std::endl;
	evaluator = newZombie(name);
	evaluator->announce();
	delete evaluator;

	std::cout << std::endl;

	std::cout << "Zombie created and announced through randomChump:" << std::endl;
	randomChump(name);
	return 0;
}