/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:05:00 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/19 16:04:31 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	RobotomyRequestForm	test("home");
	Bureaucrat			bob("bob", 75);
	bob.signForm(test);
	bob.executeForm(test);
	atexit(f);
	return 0;
}

