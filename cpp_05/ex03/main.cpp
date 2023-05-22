/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:05:00 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/22 14:22:51 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	Intern		randomDude;
	Bureaucrat	Dev("Dev", 1);
	AForm		*ptrForm;

	//--------------------------------------SHRUBBERY----------------------------------------------
	std::cout << "\n\033[1;46m--SHRUBBERY CREATION--\033[0m\n" << std::endl;
	ptrForm = randomDude.makeForm("shrubbery creation", "rainforest");
	std::cout << *ptrForm << std::endl;
	Dev.signForm(*ptrForm);
	Dev.executeForm(*ptrForm);
	delete ptrForm;

	//------------------------------------------ROBOTOMY------------------------------------------
	std::cout << "\n\033[1;46m--REQUESTING ROBOTOMY--\033[0m\n" << std::endl;
	ptrForm = randomDude.makeForm("robotomy request", "Bender");
	std::cout << *ptrForm << std::endl;
	Dev.signForm(*ptrForm);
	Dev.executeForm(*ptrForm);
	delete ptrForm;

	//------------------------------------------PARDON------------------------------------------
	std::cout << "\n\033[1;46m--PRESIDENTIAL PARDON--\033[0m\n" << std::endl;
	ptrForm = randomDude.makeForm("presidencial pardon", "Donald Trump");
	std::cout << *ptrForm << std::endl;
	Dev.signForm(*ptrForm);
	Dev.executeForm(*ptrForm);
	delete ptrForm;

	//------------------------------------------ERROR------------------------------------------
	std::cout << "\n\033[1;46m--TREN FOR MIKE O'HEARN--\033[0m\n" << std::endl;
	ptrForm = randomDude.makeForm("tren prescription", "Mike O'Hearn");
	if (ptrForm)
	{
		std::cout << *ptrForm << std::endl;
		Dev.signForm(*ptrForm);
		Dev.executeForm(*ptrForm);
		delete ptrForm;
	}
	std::cout << std::endl;
	atexit(f);
	return 0;
}

