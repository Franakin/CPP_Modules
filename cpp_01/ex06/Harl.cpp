/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 15:23:12 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 17:00:56 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << "DEBUGGING" << std::endl;
	this->info();
}

void	Harl::info(void)
{
	std::cout << "INFORMING" << std::endl;
	this->warning();
}

void	Harl::warning(void)
{
	std::cout << "WARNING" << std::endl;
	this->error();
}

void	Harl::error(void)
{
	std::cout << "UH OH IT'S KAPOT" << std::endl;	
}

void	Harl::complain(std::string level)
{
	const std::string	lvls[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "default"};
	int	i = 0;

	while (i <= 4 && !(lvls[i] == level))
		i++;
	switch (i)
	{
	case 0:
		this->debug();
		break;
	case 1:
		this->info();
		break;
	case 2:
		this->warning();
		break;
	case 3:
		this->error();
		break;
	default:
		std::cout << "Why is Harl so annoying" << std::endl;
		break;
	}
}