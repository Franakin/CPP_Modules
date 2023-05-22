/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 13:36:32 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/22 13:59:02 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidencialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();

	Intern	&operator=(const Intern &copy);

	AForm	*makeForm(std::string formName, std::string target);
};

#endif
