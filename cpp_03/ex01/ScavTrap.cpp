/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 18:52:24 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/06 19:33:54 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string newName): ClapTrap(newName)
{
	std::cout << "Constructor called for ScavTrap " << newName << std::endl;
	this->name = newName;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(void)
{
	std::cout << "Constructor called for ScavTrap [unnamed]" << std::endl;
	this->name = "[unnamed]";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "Copy constructor called for new Scavtrap " << copy.name << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "Copy assignment operator called for ScavTrap " << copy.name << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (!this->hitPoints)
	{
		std::cout << "ScavTrap " << this->name << " cannot attack " << target << " because they are dead." << std::endl;
		return;
	}
	if (!this->energyPoints)
	
	{
		std::cout << "ScavTrap " << this->name << " cannot attack " << target << " because they're out of energy!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}