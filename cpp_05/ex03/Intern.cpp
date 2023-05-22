/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 13:36:36 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/22 14:21:57 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
Intern::Intern(void){}

Intern::Intern(const Intern &copy){(void)copy;}

Intern::~Intern(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

//member functions
AForm	*Intern::makeForm(std::string formName, std::string target)
{
	std::string	allForms[] = {"shrubbery creation", "robotomy request", "presidencial pardon", "NULL"};
	int	i;

	for (i = 0; i <= 3; i++)
	{
		if (formName == allForms[i])
		{
			std::cout << "Intern creates " << allForms[i] << " form" << std::endl;
			break;
		}
	}
	switch (i)
	{
	case 0:
		return new ShrubberyCreationForm(target);
	case 1:
		return new RobotomyRequestForm(target);
	case 2:
		return new PresidencialPardonForm(target);
	default:
	{
		std::cout << "I don't know what a " << formName << " is :(" << std::endl;
		return NULL;
	}
	}
}