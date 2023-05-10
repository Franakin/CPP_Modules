/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 19:33:07 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/06 19:49:19 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string newName): ClapTrap(newName)
{
	std::cout << "Constructor called for FragTrap " << newName << std::endl;
	this->name = newName;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(void)
{
	std::cout << "Constructor called for FragTrap [unnamed]" << std::endl;
	this->name = "[unnamed]";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "Copy constructor called for new Fragtrap " << copy.name << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " destroyed" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "Copy assignment operator called for FragTrap " << copy.name << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->name << " --> (*･∀･)／＼(･∀･*) <-- You" << std::endl;
}