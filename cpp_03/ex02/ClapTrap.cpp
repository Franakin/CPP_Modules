/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 16:02:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/06 19:10:13 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string newName)
{
	std::cout << "Constructor called for ClapTrap " << newName << std::endl;
	this->name = newName;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(void)
{
	std::cout << "Constructor called for ClapTrap [unnamed]" << std::endl;
	this->name = "[unnamed]";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called for new Claptrap " << copy.name << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called for ClapTrap " << copy.name << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " cannot attack " << target << " because they are dead." << std::endl;
		return;
	}
	if (!this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " cannot attack " << target << " because they're out of energy!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << "Stop beating up dead bodies you psycho, " << this->name << " is already dead." << std::endl;
		return;
	}
	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has been killed!" << std::endl;
		this->hitPoints = 0;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage! Now has " << this->hitPoints << "HP" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " cannot be repaired for " << amount << " points because they are dead." << std::endl;
		return;
	}
	if (!this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " cannot be repaired for " << amount << " points because they're out of energy!" << std::endl;
		return;
	}
	this->hitPoints += amount;
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " has been repaired for " << amount << " points! Now has " << this->hitPoints << "HP" << std::endl;
}
