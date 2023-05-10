/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 17:36:55 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 18:42:36 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their weapon " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}

HumanA::HumanA(const std::string newName, Weapon &newWeapon): name(newName), weapon(newWeapon){}

HumanA::~HumanA(){}