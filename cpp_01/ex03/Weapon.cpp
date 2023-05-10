/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 16:27:55 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 18:56:13 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void Weapon::setType(const std::string newType)
{
	this->type = newType;
	return;
}

const std::string Weapon::getType(void)
{
	return (this->type);
}

Weapon::Weapon(std::string newType)
{
	this->setType(newType);
}

Weapon::~Weapon(){}