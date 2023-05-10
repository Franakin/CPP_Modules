/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:05:00 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/10 18:20:41 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	//init with grade too high
	try
	{
		Bureaucrat josh("Joshua", 0);
		std::cout << josh << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//init with grade too low
	try
	{
		Bureaucrat josh("Joshua", 151);
		std::cout << josh << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//increment grade too high
	try
	{
		Bureaucrat josh("Joshua", 1);
		std::cout << josh << std::endl;
		josh.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//increment grade too low
	try
	{
		Bureaucrat josh("Joshua", 150);
		std::cout << josh << std::endl;
		josh.decrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	atexit(f);
	return 0;
}

