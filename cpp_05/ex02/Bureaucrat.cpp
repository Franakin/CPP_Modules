/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:04:55 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/19 18:15:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
Bureaucrat::Bureaucrat(void){}

Bureaucrat::Bureaucrat(const std::string &newName, int newGrade) : name(newName), grade(newGrade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade){}

Bureaucrat::~Bureaucrat(void){}

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

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
		return;
	}
	catch(AForm::FormAlreadySignedException &e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
		return;
	}
	std::cout << this->name << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
		return;
	}
	catch(AForm::FormNotSignedForExecException &e)
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
		return;
	}
	std::cout << this->name << " executed " << form.getName() << std::endl;
}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade: " << b.getGrade();
	return out;
}

//exceptions--------------------------------------------------------------------------------------------------------------------------------------------
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}