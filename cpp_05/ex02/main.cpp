/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:05:00 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/19 18:36:14 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidencialPardonForm.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	//--------------------------------------SHRUBBERY----------------------------------------------
	std::cout << "\n\033[1;46m--SHRUBBERY CREATION--\033[0m\n" << std::endl;
	std::cout << "\033[0;32mOn success:\033[0m" << std::endl;
	try
	{
		Bureaucrat 				tod("Tod", 50);
		ShrubberyCreationForm	shrub("Codam");
		
		std::cout << shrub << std::endl;
		tod.signForm(shrub);
		std::cout << shrub << std::endl;
		tod.executeForm(shrub);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[0;32mOn not signed exception:\033[0m" << std::endl;
	try
	{
		Bureaucrat 				tod("Tod", 50);
		ShrubberyCreationForm	shrub("Amazon");
		
		std::cout << shrub << std::endl;
		tod.executeForm(shrub);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[0;32mOn grade too low:\033[0m" << std::endl;
	try
	{
		Bureaucrat 				tod("Tod", 150);
		Bureaucrat				me("Dev", 1);
		ShrubberyCreationForm	shrub("Desert");
		
		std::cout << shrub << std::endl;
		me.signForm(shrub);
		std::cout << shrub << std::endl;
		tod.executeForm(shrub);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[0;32mOn grade too low even when not signed:\033[0m" << std::endl;
	try
	{
		Bureaucrat 				tod("Tod", 150);
		ShrubberyCreationForm	request("Desert");
		
		std::cout << request << std::endl;
		tod.executeForm(request);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	//------------------------------------------ROBOTOMY------------------------------------------
	std::cout << "\n\033[1;46m--REQUESTING ROBOTOMY--\033[0m\n" << std::endl;
	std::cout << "\033[0;32mOn success (maybe):\033[0m" << std::endl;
	try
	{
		Bureaucrat 			tod("Tod", 45);
		RobotomyRequestForm	request("Codam");
		
		std::cout << request << std::endl;
		tod.signForm(request);
		std::cout << request << std::endl;
		tod.executeForm(request);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[0;32mOn not signed exception:\033[0m" << std::endl;
	try
	{
		Bureaucrat 			tod("Tod", 45);
		RobotomyRequestForm	request("Amazon");
		
		std::cout << request << std::endl;
		tod.executeForm(request);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[0;32mOn grade too low:\033[0m" << std::endl;
	try
	{
		Bureaucrat 			tod("Tod", 150);
		Bureaucrat			me("Dev", 1);
		RobotomyRequestForm	request("Desert");
		
		std::cout << request << std::endl;
		me.signForm(request);
		std::cout << request << std::endl;
		tod.executeForm(request);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[0;32mOn grade too low even when not signed:\033[0m" << std::endl;
	try
	{
		Bureaucrat 			tod("Tod", 150);
		RobotomyRequestForm	request("Desert");
		
		std::cout << request << std::endl;
		tod.executeForm(request);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	//------------------------------------------PARDON------------------------------------------
	std::cout << "\n\033[1;46m--PRESIDENTIAL PARDON--\033[0m\n" << std::endl;
	std::cout << "\033[0;32mOn success:\033[0m" << std::endl;
	try
	{
		Bureaucrat 				tod("Tod", 5);
		PresidencialPardonForm	request("Codam");
		
		std::cout << request << std::endl;
		tod.signForm(request);
		std::cout << request << std::endl;
		tod.executeForm(request);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[0;32mOn not signed exception:\033[0m" << std::endl;
	try
	{
		Bureaucrat 			tod("Tod", 5);
		PresidencialPardonForm	request("Amazon");
		
		std::cout << request << std::endl;
		tod.executeForm(request);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[0;32mOn grade too low:\033[0m" << std::endl;
	try
	{
		Bureaucrat 				tod("Tod", 150);
		Bureaucrat				me("Dev", 25);
		PresidencialPardonForm	request("Desert");
		
		std::cout << request << std::endl;
		me.signForm(request);
		std::cout << request << std::endl;
		tod.executeForm(request);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[0;32mOn grade too low even when not signed:\033[0m" << std::endl;
	try
	{
		Bureaucrat 				tod("Tod", 150);
		PresidencialPardonForm	request("Desert");
		
		std::cout << request << std::endl;
		tod.executeForm(request);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	atexit(f);
	return 0;
}

