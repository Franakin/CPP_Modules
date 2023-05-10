/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 16:02:43 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/06 17:20:25 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

void	f(void)
{
	std::cout << std::endl;
	system("leaks -q test");
}

int main(void)
{
	ClapTrap	bob1("Bob"), dylan("Dylan"), mrpoopiebutthole("Mr Poopie Butthole");
	ClapTrap	empty;
	ClapTrap	bob2(bob1);
	ClapTrap	bob3("you sure this is bob?");

	bob3 = bob1;
	std::cout << std::endl;
	
	//Dylan kills bob2
	dylan.attack("bob");
	bob2.takeDamage(100);
	//bob2 tries to heal himself
	bob2.beRepaired(2);
	
	std::cout << std::endl;
	
	//Dylan tries to repair himself 11 times
	for (int i = 0; i < 11; i++)
		dylan.beRepaired(5);
	std::cout << std::endl;

	//Mr Poopie Butthole attempts to attack Dylan until he runs out of energy
	for (int i = 0; i < 11; i++)
		mrpoopiebutthole.attack("Dylan");
	std::cout << std::endl;

	//Bob1 gets beaten up to a pulp
	for (int i = 0; i < 11; i++)
		bob1.takeDamage(1);
	std::cout << std::endl;
	atexit(f);
	return 0;
}

