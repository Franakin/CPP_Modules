/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidencialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 16:21:42 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/18 16:04:45 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidencialPardonForm.hpp"

//defaults
PresidencialPardonForm::PresidencialPardonForm(void)
{
	std::cout << "Default PresidencialPardonForm constructor" << std::endl;
}

PresidencialPardonForm::PresidencialPardonForm(const PresidencialPardonForm &copy)
{
	std::cout << "Copy PresidencialPardonForm constructor" << std::endl;
}

PresidencialPardonForm::~PresidencialPardonForm(void)
{
	std::cout << "PresidencialPardonForm deconstructor" << std::endl;
}

PresidencialPardonForm	&PresidencialPardonForm::operator=(const PresidencialPardonForm &copy)
{
	//do the copy
	return (*this);
}

//member functions
