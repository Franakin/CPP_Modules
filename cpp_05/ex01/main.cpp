/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:05:00 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/22 14:27:14 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	std::cout << "\033[1;46m--------------------EX00--------------------\033[0m" << std::endl;

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

	std::cout << std::endl << "\033[1;46m--------------------EX01--------------------\033[0m" << std::endl;

	//create good bureaucrat, signable form, and make him sign it
	std::cout << "\033[0;32m[create good bureaucrat, signable form, and make him sign it]\033[0m" << std::endl;
	try
	{
		Bureaucrat	josh("Joshua", 5);
		Form		form1("form1", 10, 1);

		std::cout << josh << std::endl;
		std::cout << form1 << std::endl;
		
		josh.signForm(form1);

		std::cout << form1 << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//create forms out of bounds
	std::cout << std::endl << "\033[0;32m[create forms out of bounds]\033[0m" << std::endl;
	try
	{
		Form	form1("form1", 1, 151);
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	form1("form1", -666, 15);
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//low grade bureaucrat tries to sign high grade form
	std::cout << std::endl << "\033[0;32m[low grade bureaucrat tries to sign high grade form]\033[0m" << std::endl;
	try
	{
		Bureaucrat	josh("Joshua", 150);
		Form		form1("form1", 10, 1);
		
		josh.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//bureaucrat tries to sign form twice
	std::cout << std::endl << "\033[0;32m[bureaucrat tries to sign form twice]\033[0m" << std::endl;
	try
	{
		Bureaucrat	josh("Joshua", 1);
		Form		form1("form1", 10, 1);
		
		josh.signForm(form1);
		josh.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	atexit(f);
	return 0;
}

