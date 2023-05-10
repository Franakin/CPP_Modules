/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:04:55 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/10 18:54:41 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
Bureaucrat::Bureaucrat(void)
{
	return;
}

Bureaucrat::Bureaucrat(const std::string &newName, int newGrade) : name(newName), grade(newGrade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.getGrade();
	return (*this);
}

//member functions--------------------------------------------------------------------------------------------------------------------------------------------
std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade < 2)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade > 149)
		throw GradeTooLowException();
	this->grade++;
}

//<< operator--------------------------------------------------------------------------------------------------------------------------------------------
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade: " << b.getGrade();
	return out;
}

//Exceptions--------------------------------------------------------------------------------------------------------------------------------------------
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}