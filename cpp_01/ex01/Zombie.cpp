/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 17:15:58 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/28 17:42:55 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void Zombie::setName(std::string name)
{
	this->name = name;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": I've been decapitated and therefore destroyed!" << std::endl;
	return;
}

Zombie::Zombie(void)
{
	std::cout << "Zombie constructed" << std::endl;
	return;
}
