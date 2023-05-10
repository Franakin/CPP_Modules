/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 17:42:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 12:35:46 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their weapon ";
	if (this->weapon)
		std::cout << this->weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

HumanB::HumanB(const std::string name): name(name), weapon(NULL){}

HumanB::~HumanB(){};