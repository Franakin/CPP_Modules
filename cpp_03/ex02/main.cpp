/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 16:02:43 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/06 19:43:51 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

void	f(void)
{
	std::cout << std::endl;
	system("leaks -q test");
}

int main(void)
{
	FragTrap	bob1("Bob"), dylan("Dylan"), mrpoopiebutthole("Mr Poopie Butthole");
	FragTrap	empty;
	FragTrap	bob2(bob1);
	FragTrap	bob3("you sure this is bob?");

	bob3 = bob1;
	std::cout << std::endl;
	
	//Dylan kills bob2
	dylan.attack("bob");
	bob2.takeDamage(111);
	//bob2 tries to heal himself
	bob2.beRepaired(2);
	
	std::cout << std::endl;
	
	//Dylan tries to repair himself 51 times
	for (int i = 0; i < 51; i++)
		dylan.beRepaired(5);
	std::cout << std::endl;

	//Mr Poopie Butthole attempts to attack Dylan until he runs out of energy
	for (int i = 0; i < 51; i++)
		mrpoopiebutthole.attack("Dylan");
	std::cout << std::endl;

	//Bob1 gets beaten up to a pulp
	for (int i = 0; i < 11; i++)
		bob1.takeDamage(10);

	std::cout << std::endl;

	mrpoopiebutthole.highFivesGuys();

	std::cout << std::endl;

	atexit(f);
	return 0;
}

