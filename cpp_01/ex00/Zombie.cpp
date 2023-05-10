/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 14:06:23 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/28 17:43:08 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": I've been decapitated and therefore destroyed!" << std::endl;
	return;
}

Zombie::Zombie(std::string const newName): name(newName)
{
	std::cout << this->name << ": OMG I've been constructed" << std::endl;
	return;
}
