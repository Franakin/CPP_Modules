/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 15:52:25 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/10 18:55:34 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
Form::Form() : name("N/A"), isSigned(false), minSignGrade(1), minExecGrade(1)
{
	return;
}

Form::Form(const std::string &newName, const int &signGrade, const int &execGrade) : name(newName), isSigned(false), minSignGrade(signGrade), minExecGrade(execGrade)
{
	if (this->minSignGrade < 1 || this->minExecGrade < 1)
		throw GradeTooHighException();
	if (this->minSignGrade > 150 || this->minExecGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned), minSignGrade(copy.minSignGrade), minExecGrade(copy.minExecGrade)
{
	return;
}

Form::~Form(void)
{
	return;
}

Form	&Form::operator=(const Form &copy)
{
	this->isSigned = copy.getSignStatus();
	return (*this);
}

//<< operator--------------------------------------------------------------------------------------------------------------------------------------------
std::ostream	&operator<<(std::ostream &out, const Form &b)
{
	out << "_____________________________" << std::endl;
	out << "| Form name: " << b.getName() << std::endl << '|' << std::endl;
	out << "| Min grade for signing: " << b.getMinSignGrade() << std::endl;
	out << "| Min grade for executing: " << b.getMinExecGrade() << std::endl << '|' << std::endl;
	out << "| Signed? ";
	if (b.getSignStatus())
		out << "true";
	else
		out << "false";
	out << std::endl;
	out << "_____________________________";
	return out;
}

//member functions--------------------------------------------------------------------------------------------------------------------------------------------
std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getSignStatus() const
{
	return this->isSigned;
}

int	Form::getMinSignGrade() const
{
	return this->minSignGrade;
}

int Form::getMinExecGrade() const
{
	return this->minExecGrade;
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->minSignGrade)
		throw GradeTooLowException();
	if (this->getSignStatus())
		throw FormAlreadySignedException();
	this->isSigned = true;
}

//Exceptions--------------------------------------------------------------------------------------------------------------------------------------------
const char	*Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char	*Form::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}