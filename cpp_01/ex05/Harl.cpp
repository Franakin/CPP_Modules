/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 15:23:12 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 16:01:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << "DEBUGGING" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFORMING" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "UH OH IT'S KAPOT" << std::endl;	
}

void	Harl::complain(std::string level)
{
	const Harl::funcPtr	func[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	const std::string	lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i <= 3; i++)
		if (lvls[i] == level)
			(this->*func[i])();
}